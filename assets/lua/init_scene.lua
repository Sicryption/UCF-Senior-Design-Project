name_table = {}
current_object = nil

function tick()
    
end

function select_gameobject(name)
      current_object = name_table[name]
end

function delete(name)
    name_table[name] = nil
end
