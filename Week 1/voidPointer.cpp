#include <iostream>

int main() {
    int a{5};
    void* ptr = &a;
    std::cout<<"&a = "<< ptr <<std::endl ;
    // std:: cout << a << *ptr; --> this wrong 
    std::cout << "a = *ptr = "<<*static_cast<int*>(ptr) << std::endl;

    return 0;
}