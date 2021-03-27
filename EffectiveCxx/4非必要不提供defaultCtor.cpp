#include <new.h> // for placement new

class EquipmentPiece {
public:
    // non default ctor
    EquipmentPiece(int IDNumber);
    ~EquipmentPiece() = default;
};

int main() {
    EquipmentPiece equipmentPiece(1); // ok
    // EquipmentPiece equipmentPiece1[10]; // error not ctor
    // EquipmentPiece *equipmentPiece1 = new EquipmentPiece[10];

    // 对象数组
    EquipmentPiece bestPieces0[2] = { EquipmentPiece(1), EquipmentPiece(2) }; // 非指针数组

    // 指针数组
    EquipmentPiece *bestPieces1[2] = {new EquipmentPiece(1), new EquipmentPiece(2) };

    // 指针数组
    using PEP = EquipmentPiece *;
    PEP *bestPieces2 = new PEP[2];

    /*
     * EquipmentPiece *bestPieces1[2]
     * EquipmentPiece ** bestPieces1 = new EquipmentPiece*[2] 效果相同，但是使用new方法需要手动释放资源
     */

    for(int i = 0; i < 2; i ++) {
        bestPieces2[i] = new EquipmentPiece(i);
    }

    // 过度使用内存使用operator new and placement new
    void* rawMemory = operator new[](2 * sizeof(EquipmentPiece));
    EquipmentPiece *bestPieces3 = static_cast<EquipmentPiece *>(rawMemory);
    new (&bestPieces3[0]) EquipmentPiece(1);

    // 释放rawMemory
    // 以构造顺序的相反顺序析构
    bestPieces3[0].~EquipmentPiece();
    // 不可以直接释放rawMemory，删除一个不以new operator获得的指针，会造成不可定义
    operator delete[](rawMemory);
}

