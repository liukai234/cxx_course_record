//
// Created by lk234 on 2020/10/22 022.
//

#include <iostream>
#include <list>
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

class MemoryManager {
public:
    void* operator new(size_t size);
    void operator delete(void *pointer) noexcept;

    static void init();
    static MemoryManager* getInstance();

    static void getAllObjPointer();

    ~MemoryManager() = default;
private:
//    static MemoryManager manageAllocate;
//    size_t size;
    static MemoryManager *memoryManager;
    static std::list<void *> objectCount; // 存储object对象，object对象内含有refCount_
    static size_t memorySize_;
    static void * Memory_;
    static size_t startPointer;
    static size_t lastPointer; // 偏移量
    static unsigned char * list[MAX_OBJECT];
    static size_t listPreSize[MAX_OBJECT];
    static size_t listIndex;
    static int list_len;
};


#endif // GARBAGE_COLLECTION_MEMORY_MANAGER_H
