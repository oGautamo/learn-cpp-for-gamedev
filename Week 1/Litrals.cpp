// Lecture : Introduction to C++ - Constants and Literals


#include <iostream>
#include <string> // Required for std::string
#include <bitset> //for binary conversion

int main() {
    int pog = +1;
    int nog = -1;
    double micro = 1e-6;
    double unit = 1.0;
    int myHex = 0x100; // 256 in decimal
    int myOct = 0400;
    int myBinary = 00001;
    std::string name = "SANDIP";

    int myNum = 30;

    // Print values with different base formats
    std::cout << std::showbase; // show base prefix like 0x or 0
    std::cout << "Decimal: " << std::dec <<myNum << std::endl;
    std::cout << "Octal: " << std::oct <<myNum << std::endl;
    std::cout << "Hexadecimal: " << std::hex <<myNum << std::endl;
     std::cout << "Binary : " << std::bitset<8>(myNum) << std::endl; // 8 bits
     // bisect<16>. bisect<32> ---> for 16, 32 bits

    return 0;
}

