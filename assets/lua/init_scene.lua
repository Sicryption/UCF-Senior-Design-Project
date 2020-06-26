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
        current_object = value["id"] or 0
    end

    return current_object
end

function delete(name)
    name_table[name] = nil;
end
