#include <iostream>
#include <vector>

using namespace std;

int main() {
    /* cout << "size: " << vecInt.size() << endl;
     *cout << "capacity: " << vecInt.capacity() << endl;
     */

    /* {}列表初始化 */         vector<int> v1{0, 1};
    /* ()构造vector对象 */    vector<int> v2(10, 1);
    
    /*
     * vector<int>::iterator it           it可读写 vector<int> 元素
     * vector<int>::const_iterator it     it可读不可写 vector<int> 元素
     */

    swap(v1[0], v1[1]);
    for(/* int& */ auto &i : v1) {cout << ++i /* 不加引用不能将改变应用到容器中 */ << " ";}

    return 0;
}