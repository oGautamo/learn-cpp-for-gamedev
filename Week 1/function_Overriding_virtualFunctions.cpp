#include<iostream>

using namespace std;

class Base{
    public:
        virtual void show(){
            cout<< "Base class show( ) "<<endl;
        }
};

class Derived: public Base{
    public:
        void show() override {
            cout<< "Derived class show( )"<<endl;
        }
};

int main() {
    Base b1;
    b1.show(); // Base class show

    Base* ptr;
    Derived d;
    ptr = &d;
    ptr->show();  //Output: Derived Show

    return 0;
    
}