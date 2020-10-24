//
// Created by lk234 on 2020/10/22 022.
//

#include <iostream>
#include <list>
#ifndef GARBAGECOLLECTION_MANAGEALLOCATION_H
#define GARBAGECOLLECTION_MANAGEALLOCATION_H
//#include "Object.h"
#ifdef DEBUG
#include "dbg.h"
#endif

class ManageAllocation {
public:
    ~ManageAllocation() = default;
    void* operator new(size_t size); // 重写operator new , Object &obj
    void operator delete(void *pointer) noexcept;
    static ManageAllocation* getInstance();
    static void getAllObjPointer();
private:
//    static ManageAllocation manageAllocate;
    size_t size;
    ManageAllocation() = default;
    static ManageAllocation *manageAllocation;
    static std::list<void *> objectCount; // 存储object对象，object对象内含有refCount_
};


#endif //GARBAGECOLLECTION_MANAGEALLOCATION_H
