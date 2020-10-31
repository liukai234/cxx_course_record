//
// Created by lk234 on 2020/10/22 022.
//

#include <iostream>
#include <list> // unused
#ifndef GARBAGE_COLLECTION_MEMORY_MANAGER_H
#define GARBAGE_COLLECTION_MEMORY_MANAGER_H
//#include "Object.h"
#ifdef DEBUG
#include "dbg.h"
#endif

/*
 * Memory Manage可以使用的内存
 */
#define MEMORY_SIZE 256

/*
 * 内存中存有的最大对象数量
 */
#define MAX_OBJECT 256

/*
 * 匿名结构体MemoryStruct
 * 维护对象大小及指针列表
 */
typedef struct {
    void * list[MAX_OBJECT]; // 对象指针
    size_t listPreSize[MAX_OBJECT]; // 对象大小

    size_t listIndex; // 下标
}MemoryStruct;

class MemoryManager {
public:
    void* operator new(size_t size);
    void operator delete(void *pointer) noexcept;

    static void init();
    static MemoryManager* getInstance();

    // TODO: static void toMark() {}
    static void markClear() {

    }

//    static void getAllObjPointer();

    ~MemoryManager() = default;
private:
    static MemoryManager *memoryManager;

    static size_t memorySize_;
    static void * Memory_;
    /*
     * 偏移量：已利用内存累积（在memory_下的一个 "表明占用情况" 的指针）
     * Stack pointer rsp
     */
    static size_t lastPointer_;


    static MemoryStruct memoryStruct_;



    //    static std::list<void *> objectCount; // 存储object对象，object对象内含有refCount_

};


#endif // GARBAGE_COLLECTION_MEMORY_MANAGER_H
