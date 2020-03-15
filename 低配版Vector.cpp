/*
 * @Author: your name
 * @Date: 2020-02-23 10:38:13
 * @LastEditTime: 2020-02-23 10:48:44
 * @LastEditors: Please set LastEditors
 * @Description: In User Settings Edit
 * @FilePath: /wanmen2/Vector.cpp
 */
#include <iostream>
using namespace std;

class Vector {
private:
    size_t sz;
    double* elem;

    Vector(initializer_list<double> lst)
        :elem {new double[lst.size()]}, 
        sz(lst.size())
    {
        copy(lst.begin(), lst.end(), elem);
    }

    

    ~Vector(){
        cout << "~exec" << endl; 
    }

};

int main(int args, char *argv[]){


}