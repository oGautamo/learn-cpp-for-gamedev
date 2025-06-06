#include<iostream>

using namespace std;

class Base{
    public:
        void show() {
            cout<< "Base class show() "<<endl;
        }
};

class Derived: public Base {
    public:
        void show(){  //Overrides Base :: show()
            cout<< "Derived class show()"<<endl;
        }
};

int main( ) {
    Base b1;
    Derived d1;

    b1.show();
    d1.show();
}