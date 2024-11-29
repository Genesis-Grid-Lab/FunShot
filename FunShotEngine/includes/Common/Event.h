#pragma once
#include "Core.h"

namespace Gen
{    
    template <typename Event> 
    struct EventListener
    {
        using CallbackFn = std::function<void(const Event&)>;

        GEN_INLINE EventListener(CallbackFn&& callback, uint32_t listnrid): 
            Callback(std::move(callback)), ID(listnrid) 
        {}
        
        CallbackFn Callback;
        uint32_t ID;
    };

    // Event Registry

    template <typename Event> 
    struct EventRegistry
    {
        using Listener = std::unique_ptr<EventListener<Event>>;
        std::queue<std::unique_ptr<Event>> Queue;
        std::vector<Listener> Listeners;
    };

    // Event Dispatcher

    struct EventDispatcher
    { 
        GEN_INLINE ~EventDispatcher() 
        {
            for(auto& [_, ptr] : m_Registry) 
            {
                auto registry = CastRegistry<char>(ptr);
                GEN_DELETE(registry);
            }
        }     

        template <typename Event, typename Callback>
        GEN_INLINE void AttachCallback(Callback&& callback, uint32_t listnrid) 
        { 
            auto listener = std::make_unique<EventListener<Event>>(std::move(callback), listnrid);
            GetRegistry<Event>()->Listeners.push_back(std::move(listener));
        }
       
        template <typename Event>
        GEN_INLINE void DetachCallback(uint32_t listnrid) 
        { 
            auto& listeners = GetRegistry<Event>()->Listeners;
            listeners.erase(std::remove_if(listeners.begin(), 
            listeners.end(), [&] (auto& listener) 
            { 
                return (listener->ID == listnrid);
            }), 
            listeners.end());
        } 

        GEN_INLINE void EraseListener(uint32_t listnrid) 
        { 
            for(auto& [_, registry] : m_Registry) 
            {
                auto& listeners = CastRegistry<int8_t>(registry)->Listeners;
                listeners.erase(std::remove_if(listeners.begin(), 
                listeners.end(), [&] (auto& listener) 
                { 
                    return (listener->ID == listnrid); 
                }), 
                listeners.end());
            }
        } 
        
        template <typename Event, typename... Args>
        GEN_INLINE void PostEvent(Args&&...args) 
        {
            auto registry = GetRegistry<Event>();
            if(registry->Listeners.empty()) { return; }
            registry->Queue.push(std::make_unique<Event>(std::forward<Args>(args)...));
        }

        template <typename Task>
        GEN_INLINE void PostTask(Task&& task) 
        {
            m_Tasks.push(std::move(task));
        }

        GEN_INLINE void PollEvents() 
        {
            // persistent callbacks
            for(auto& [_, pointer] : m_Registry) 
            {   
                auto registry = CastRegistry<char>(pointer);

                while(!registry->Queue.empty())
                {
                    for(auto& listener : registry->Listeners)
                    {
                        listener->Callback(*registry->Queue.front());
                    }
                    registry->Queue.pop();
                }
            }
            
            // frame callbacks
            while(!m_Tasks.empty()) 
            { 
                m_Tasks.front()();
                m_Tasks.pop();
            }
        } 
                
    private:
        template <typename Event>
        GEN_INLINE EventRegistry<Event>* CastRegistry(void* p)
        {
            return static_cast<EventRegistry<Event>*>(p); 
        }

        template <typename Event>
        GEN_INLINE EventRegistry<Event>* GetRegistry() 
        {
            auto it = m_Registry.find(TypeID<Event>());
            if(it != m_Registry.end()) 
            {
                return CastRegistry<Event>(it->second); 
            }
            auto registry = new EventRegistry<Event>();
            m_Registry[TypeID<Event>()] = registry;
            return registry;
        }
      
    private:    
        std::unordered_map<uint32_t, void*> m_Registry;
        std::queue<std::function<void()>> m_Tasks;
    };
}