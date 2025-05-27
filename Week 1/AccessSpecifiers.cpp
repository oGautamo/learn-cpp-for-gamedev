/* 
public: Open to All
private: Secret/Internal
protected: Internal + Inherited
*/

#include<iostream>
#include<string>

class Player {
public:
    std::string name;  // Public - anyone can access

    void greet() {
        std::cout << "Hello, " << name << std::endl;
    }

};

int main( ) {

Player p;
p.name = "Sandip";   // ✅ Allowed
p.greet();           // ✅ Allowed

    return 0;
}




