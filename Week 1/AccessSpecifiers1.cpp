#include<iostream>

class Player {
private:
    int health;  // Private - not accessible outside directly

public:
    void setHealth(int h) {
        health = h;
    }

    int getHealth() {
        return health;
    }
};

int main( ) {
    Player p;
    p.setHealth(100);     // ✅ Allowed
    std::cout << p.getHealth(); // ✅ Allowed
    // p.health = 50;     ❌ Error - private access
    return 0;

}
