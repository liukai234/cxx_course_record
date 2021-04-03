#include <iostream>
#include <vector>

using namespace std;

int main(int argc, char **argv) {
    /* char*与string风格互相转换时使用c_str和用string新建对象 */
    vector<string> v1;
    for(int i = 1; i < argc; i++) {
        v1.push_back(string(argv[i]));
    }

    for(auto i : v1) { cout << i << " "; }
}
