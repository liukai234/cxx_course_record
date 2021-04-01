#include <iostream>

using namespace std;

/*
 * 限制class能产生的对象数量
 */

class Printer {
public:
    static Printer& thePrinter() {
        /*
         * 当类使用无参构造函数时，定义时可以为A a; 或 A a();
         * 当类只要定义了有参构造函数，就不会自动产生午餐构造函数，此时定义时必须为 A a(1, 2);
         */
        // 最好不要以inline连接static数据
        static Printer p;
        return p;
    }

    void submitJob(string &str){ cout << "submitJob\n"; };
    void reset(){ cout << "reset\n"; };
    void performSelfTest(){ cout << "performSelfTest\n"; };

    /*
     * 为了避免友元函数像一个全局变量，并且不在类的内部
     * 使用类内的 static方法
     * 或使用 namespace 命名空间
     */
    // friend Printer& thePrinter();

private:
    /*
     * 如果一个方法不是纯虚函数，则必须有方法体
     * 构造函数必须有方法体
     */
    Printer(){}
    Printer(const Printer& rhs);
};
/*
Printer& thePrinter() {
    static Printer p;
    return p;
}
*/
int main(){
    string str("123");

    Printer::thePrinter().reset();
    Printer::thePrinter().submitJob(str);
    return 0;
}