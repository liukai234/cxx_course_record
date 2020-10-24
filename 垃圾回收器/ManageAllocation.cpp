//
// Created by lk234 on 2020/10/22 022.
//

#include "ManageAllocation.h"
#include "Object.h"

ManageAllocation * ManageAllocation::manageAllocation = nullptr;
std::list<void *> ManageAllocation::objectCount;

// 重写全局operator new
void* operator new(size_t size){
#ifdef DEBUG
    dbg("global new");
#endif
    return malloc(size);
}

void operator delete(void *pointer) noexcept {
#ifdef DEBUG
    dbg("global delete");
#endif
    free(pointer);
}

void* ManageAllocation::operator new(size_t size) // 重写operator new , Object &obj
{
#ifdef DEBUG
    dbg("ManageAllocation operator new called");
#endif
    void * objPointer = ::operator new(size);
    objectCount.push_back(objPointer);
    return objPointer; // 调用全局operator new
}

void ManageAllocation::operator delete(void *pointer) noexcept {
#ifdef DEBUG
    dbg("ManageAllocation operator delete called");
#endif
    ::operator delete(pointer);
}

ManageAllocation* ManageAllocation::getInstance()
{
    if(manageAllocation == nullptr) {
        manageAllocation = new ManageAllocation;
    }
    return manageAllocation;
}

// TODO: clearALL、move整理
// TODO: 线程暂停，处理全部 使用一个临时链表来倒换 objectCount 内容有序弹出并判断是否被delete正在占用资源给temp链表，然后再从temp表给回objectCount
// TODO: 寻找空闲地址，标记 size
void ManageAllocation::getAllObjPointer() {
    // 逆序遍历
    // using listIterType = decltype(objectCount.rbegin());
    std::list<void *> objectListTemp;

    for(auto iter = objectCount.rbegin(); iter != objectCount.rend(); ++ iter) {
        auto *objTemp = (Object*)*iter; // Object *
        int refCount = objTemp->refCount();
        std::cout << refCount << std::endl;
        if(0 == refCount) {
            std::cout << "Above has be deleted" << std::endl;
            delete objTemp;
            objTemp = nullptr;
        } else {
            objectListTemp.push_front(*iter);
        }
    }

    objectCount.clear();

    std::cout << "---" << std::endl;
    for(auto &x : objectListTemp) {
        std::cout << ((Object*)x)->refCount() << std::endl;
        objectCount.push_back(x);
    }

    objectListTemp.clear();
}

//ManageAllocation::~ManageAllocation() {
//
//    std::cout << "~ManageAllocation" << std::endl;
//    if(manageAllocation) {
//        delete ManageAllocation::manageAllocation;
//        ManageAllocation::manageAllocation = nullptr;
//    }
//}
