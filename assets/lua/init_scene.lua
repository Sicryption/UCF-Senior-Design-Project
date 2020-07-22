name_table = {}
current_object = nil
_lock = false
_EXEC_STATE = 0
function select_object(name)
    current_object = name_table[name]
end
function delete(name)
    name_table[name] = nil
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
