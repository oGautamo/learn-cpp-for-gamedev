#include<iostream>
class Base {
protected:
    int level;
};

class Derived : public Base {
public:
    void setLevel(int l) {
        level = l;  // ✅ Allowed (protected can be accessed in child)
    }
};

int main( ) {
    Derived d;
    // d.level = 2;      ❌ Error - still hidden outside

    return 0;
}