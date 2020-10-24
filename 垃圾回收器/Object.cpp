//
// Created by lk234 on 2020/10/22 022.
//

#include "Object.h"
void * Object::operator new(size_t size) {
#ifdef DEBUG
    dbg("operator new called");
#endif
    return ManageAllocation::getInstance()->operator new(size); // 调用ManageAllocate::operator new
}

void Object::operator delete(void *pointer) noexcept {
#ifdef DEBUG
    dbg("operator delete called");
#endif
    ManageAllocation::getInstance()->operator delete(pointer);
}

// TODO: [PROBLEM] deep copy
Object& Object::operator=(Object &obj) {
#ifdef DEBUG
    dbg("operator= &obj");
#endif
    // TODO: 赋值时增减计数
    obj.refCount_ += 1;
    return *this;
}

int Object::refCount() const {
    return refCount_;
}

