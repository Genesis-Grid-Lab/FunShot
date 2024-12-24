#include <memory>
#include <random>
#include <entt/entt.hpp>

#define SUPPORT_FILEFORMAT_HDR

namespace FS {
     // entity identifier
    using EntityID = entt::entity;
    // null entity
    constexpr EntityID NENTT = entt::null;  
    // entity registry
    using EntityRegistry = entt::registry;

     // runtime type
    template <typename T>
    inline constexpr uint32_t TypeID()
    {
        return static_cast<uint32_t>(reinterpret_cast<std::uintptr_t>(&typeid(T)));
    }

    // generate random 64 bit
    inline uint64_t RandomU64() 
    {
        static std::random_device device;
        static std::mt19937_64 generator(device());
        static std::uniform_int_distribution<uint64_t> distribution;
        return distribution(generator);
    }

    template<typename T>
    using Scope = std::unique_ptr<T>;
    template<typename T, typename ... Args>
    constexpr Scope<T> CreateScope(Args&& ... args){
        return std::make_unique<T>(std::forward<Args>(args)...);
    }

    template<typename T>
    using Ref = std::shared_ptr<T>;
    template<typename T, typename ... Args>
    constexpr Ref<T> CreateRef(Args&& ... args){
        return std::make_shared<T>(std::forward<Args>(args)...);
    }
}

#include "Core/Assert.h"