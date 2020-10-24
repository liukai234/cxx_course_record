//
// Created by lk234 on 2020/10/22 022.
//
#include <iostream>
#ifndef GARBAGECOLLECTION_OBJECT_H
#define GARBAGECOLLECTION_OBJECT_H
#include "ManageAllocation.h"
#ifdef DEBUG
#include "dbg.h"
#endif
class Object {
public:
    void* operator new(size_t size); // 重写operator new
    void operator delete(void *pointer) noexcept;
    Object& operator=(Object &obj);
    int refCount() const;
//    ~Object();
private:
//    static ManageAllocation* manageAllocation;
    int refCount_ = 0;
};

#endif //GARBAGECOLLECTION_OBJECT_H
