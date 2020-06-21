name_table = {}
current_object = nil
on_update = {}



-- tick function
function tick()
    local t_id = make_rectangle()
    println("(".. t_id .. ") rectangle");
end

function add_named_item(name,value)
    name_table[name] = value
end

function create_gameobject(_id)
    return {
        id = _id or 0,
        type= 'rectangle'
    }
end

function create_rectangle(name)
    local id = rectangle()
    add_named_item(name, create_gameobject(id))
end







