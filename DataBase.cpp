#include "DataBase.h"


DataBase* DataBase::instance = nullptr;

DataBase* DataBase::get_instance()
{
    if (!instance)
        instance = new DataBase();
    return instance;
}


