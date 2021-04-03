#include <iostream>
#include <vector>

using namespace std;

int main(int argc, char **argv) {
    vector<string> v1;
    for(int i = 1; i < argc; i++) {
        v1.push_back(string(argv[i]));
    }

    for(auto i : v1) { cout << i << " "; }
}
