#include <iostream>
using namespace std;

class Vector {
private:
    size_t sz;
    int* elem;
public:
    Vector(initializer_list<int> lst):elem {new int[lst.size()]}, sz(lst.size()) {
        copy(lst.begin(), lst.end(), elem);
    }

    void printALL() {
        for(int i = 0; i < sz; i ++) { cout << elem[i] << " "; }
        cout << endl;
    }

    ~Vector(){
        delete [] elem;
    }

};

int main(int argc, char *argv[]){
    /*
     * () 认为是构造函数
     * {} 认为是列表初始化
     */
    Vector v{1, 2, 3};
    v.printALL();
}