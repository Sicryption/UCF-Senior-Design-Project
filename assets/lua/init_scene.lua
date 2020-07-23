name_table = {}
current_object = -1
_lock = false
_EXEC_STATE = 0
select_object = function(name)
    --println("name table:", name,name_table[name] )
    if(name_table[name] == nil) then 
        current_object = -1
    else 
        current_object = name_table[name] 
    end
end
function IsRunning()
    ::HALT_LOOP::
    if(_EXEC_STATE < 0) then
        return false
    elseif(_EXEC_STATE == 1) then
        goto HALT_LOOP
    elseif(_EXEC_STATE == 2) then
        return false
    elseif(_EXEC_STATE == 3) then
        return false
    end
    return true
end
