name_table = {}
current_object = nil

function tick()
    
end

function select_gameobject(name)
    local value = name_table[name]

    if (type(value) != "table") then 
        error("cannot select non-gameobject '"..value.."'") 
        return nil 
    end

    if(type(value["id"])= "number" ) then
        current_object = value["id"] or nil
    end

    return current_object
end

function get_gameobject_properties(id)
    if(name_table[id] != nil) then
        obj = {x=0,y=0,xscale=0,yscale=0,angle=0}
        -- TODO: API function which converts a game object into a table
        return obj
    end
    return nil
end

function create_gameobject(id)
    obj = {} 
    
end