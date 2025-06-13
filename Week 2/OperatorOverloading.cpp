#include <iostream>
#include <string>
using namespace std;

class Character {
private:
    double health;
public:
    string name;

    // Constructor
    Character(string n, double h) : name(n), health(h) {}

    // Overload + operator to combine health
    Character operator+(const Character& other) {
        string newName = this->name + "-" + other.name;
        double newHealth = this->health + other.health;
        return Character(newName, newHealth);
    }

    void showStatus() const {
        cout << "Character: " << name << ", Health: " << health << endl;
    }
};

int main() {
    Character hero("Hero", 80);
    Character sidekick("Sidekick", 60);

    cout << "Before combining:" << endl;
    hero.showStatus();
    sidekick.showStatus();

    Character fusion = hero + sidekick;  // operator+ is called here

    cout << "\nAfter fusion:" << endl;
    fusion.showStatus();

    return 0;
}
