#include <iostream>    // iostream ostream istream 
#include <sstream>     // sstream istringstream ostringstream
#include <fstream>     // fstream ifstream ofstream 
// fstream 和 sstream 都继承自 iostream

using namespace std;

int main() {
    stringstream ss("12306");
    int a;
    istream is(ss.rdbuf());
    // or ss >> a;
    is >> a;
    cout << a;

}
