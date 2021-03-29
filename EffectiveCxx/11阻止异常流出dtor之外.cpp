#include <iostream>

using namespace std;

class Session {
public:
    Session(){}
    ~Session();

// private:
    static void logCreate(Session* object);
    static void logDestruction(Session* object);
};

void Session::logCreate(Session *object) { cout << "logCreate\n"; }
void Session::logDestruction(Session *object) { cout << "logDestruction\n"; }
Session::~Session() {
    /*
     * do nothing
     * 这里的catch块看起来什么都没有做，但是他阻止了logDestruction()抛出的exception传出Session destructor之外
     */
    try { logDestruction(this); }
    catch (exception e) { /* cout << e.what(); 如果这个operator << 导致了异常，那这回到了阻止异常流出dtor的起点 */ }
}


int main() {
    Session session;
    Session subsession;
    session.logCreate(&subsession);
}