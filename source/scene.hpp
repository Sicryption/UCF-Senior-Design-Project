#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <map>
#include <memory>


#include "gameObject.hpp"

class Scene : public Updateable
{
private:
    std::map<unsigned int,GameObject*> hashmap;
    unsigned int idCounter;

public:

    Scene()
    {
        hashmap.empty();
        idCounter = 0;
    }

    ~Scene()
    {
        auto it =  hashmap.cbegin();
        for(;it != hashmap.cend(); it++)
        {
            it->second->destroy();
        }
    }

    unsigned int addObject(GameObject* obj)
    {
        hashmap[idCounter] = obj;
        return ++idCounter;
    }


};