#include <iostream>

using namespace std;

int main() {
    /*
     * gdb调试中使用print/x ucharMax来打印ucharMax中的内容，格式f为：x (16进制)
     */
    unsigned char ucharMax = UCHAR_MAX; // 0x7F << 1 + 1
    /*
     * 对0x7F求负：结果为所有二进制位取反加1
     * 正数：原码 = 反码 = 补码
     * 负数：原码 = 反码 原码求反 = 补码 原码取反加一
     * 知道负数的补码求原码也取反加一即可
     *
     * 负数的补码是原码取反加一的原因 -> 也就是说 一个数的正数和负数在补码形式中的相互转换时取反加一
     * 0 - 正数 = 负数（该正数的相反数）-> （1111 + 0001） - 正数 = 该正数的相反数
     * 而 1111 - 正数 = 该正数按位取反
     * 所以1111 - 正数 + 0001 = 负数（该正数的相反数）  即取反加1
     *
     * 计算机中存储数据使用的是补码形式
     * 从补码读取一个负数：符号位1当作-号，其余位取反加一
     * 从补码读取一个正数：符号位0当作+号，其余位直接读取
     */

    /*
     * 一直自增可以按照这个顺序去循环，并且相反数相加和为0
     * 负数不带符号取反加一为原码，把符号位去了就是其相反数（那个正数）
     *
     * 补码          数值
     * 0111 1111 --- 127
     * ...
     * 0000 0001 ---   1
     * 0000 0000 ---   0
     * 1111 1111 ---  -1
     * 1111 1110 ---  -2
     * ...
     * 1000 0001 --- -127
     * 1000 0000 --- -128
     */
    char charMax = CHAR_MAX; // 0x7F
    char charMin = CHAR_MIN; // -0x7F - 1
    printf("ucharMax: %x charMax: %x charMin: %x\n", ucharMax, charMax, charMin);
    printf("ucharMax: %d charMax: %d charMin: %d\n", ucharMax, charMax, charMin);

    /*
     * (gdb) print/x &charMax
     * $4 = 0x61fe1e
     * (gdb) x/bx 0x61fe1e
     * 0x61fe1e:	0x7f
     *
     * (gdb) x/bx 0x61fe1f
     * 0x61fe1f:	0xff
     *
     * (gdb) x/hx 0x61fe1e
     * 0x61fe1e:	0xff7f [!!] 小端模式，高字节地址内容在高位，低字节地址内容在低位
     *
     * (gdb) x/2bx 0x61fe1e
     * 0x61fe1e:	0x7f	0xff [!!] 这样输出的是无视大小端模式的
     */
}