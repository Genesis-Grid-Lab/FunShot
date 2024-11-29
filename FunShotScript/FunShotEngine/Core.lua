-- core script class
local FunShotScript = {}
local FunShotScript_mt = { __index = FunShotScript }

-- inits script base clasee
function FunShotScript.Constructor(entity)
    local self = setmetatable({}, FunShotScript_mt)
    self.Entity = entity
    return self
end

-- destroy entity with id
function FunShotScript.Destroy(entity)
    ApiDestroy(entity)
end

-- inits script class
function Initializer()
    -- script class 
    local ScriptKlass = {}
    local ScriptKlass_mt = { __index = ScriptKlass }
    setmetatable(ScriptKlass, { __index = FunShotScript })
    
    -- constructor
    function ScriptKlass.Constructor(entity)
        local obj = FunShotScript.Constructor(entity)
        self = setmetatable(obj, ScriptKlass_mt)    
        return self
    end
    
    -- apply force to rigidbody
    function ScriptKlass:ApplyForce(force)
        ApiApplyForce(self.Entity, force)
    end
    
    -- destroy self
    function ScriptKlass:Destroy()
        ApiDestroy(self.Entity)
    end

     -- get data
    function ScriptKlass:Get(type)
        if type == TRANSFORM then
            return ApiGetTransform(self.Entity)
        end        
        print("invalid type:", type);
        return {}
    end
    
    -- export class
    return ScriptKlass
end

-- export module
return FunShotScript
