#include <iostream>
#include <string>
#include <vector>

using std::endl;
using std::cin;
using std::cout;
using std::string;
using std::vector;

// Base Character Class
class Character {
protected:
    int level = 1;
private:
    double health = 100;

public:
    string name;

    Character(string n, bool showMessage = true) : name(n) {
        if (showMessage) {
            cout << "Character " << name << " has entered the game..." << endl;
        }
    }

    virtual ~Character() {
        cout << "Character " << name << " has left the game.." << endl;
    }

    void takeDamage(double damageAmount) {
        cout << name << " takes " << damageAmount << " Damage" << endl;
        health -= damageAmount;
        if (health <= 0) health = 0;
    }

    void heal(double healAmount) {
        cout << name << " heals " << healAmount << " HP." << endl;
        health += healAmount;
        if (health >= 100) health = 100;
    }

    void printStatus() const {
        cout << "[Status] Name: " << name << ", Health: " << health << ", Level: " << level << endl;
    }

    bool isAlive() const {
        return (health > 0);
    }
};

// Item Class
class Item {
    string name;
    string type;
    int value;
public:
    Item(string name, string type, int value)
        : name(name), type(type), value(value) {}

    string getName() const { return name; }
    string getType() const { return type; }
    int getEffectValue() const { return value; }

    void printInfo() const {
        cout << "Item: " << name << " (Type: " << type << ", Effect: " << value << ")" << endl;
    }
};

// Enemy Class
class Enemy : public Character {
public:
    Enemy(string n) : Character(n, false) {
        cout << "Enemy " << name << " has entered the game.." << endl;
    }

    void attack(Character& target) {
        double damage = 8;
        cout << name << " strikes back at " << target.name << " for " << damage << " damage!" << endl;
        target.takeDamage(damage);
    }
};

// Player Class
class Player : public Character {
private:
    vector<Item> inventory;
public:
    Player(string n) : Character(n, false) {
        cout << "Player " << name << " has entered the game.." << endl;
    }

    void addItem(const Item& newItem) {
        inventory.push_back(newItem);
        cout << name << " picked up: " << newItem.getName() << endl;
    }

    void showInventory() const {
        cout << "--- Inventory ---" << endl;
        if (inventory.empty()) {
            cout << "Inventory is empty." << endl;
            return;
        }
        for (size_t i = 0; i < inventory.size(); ++i) {
            cout << i + 1 << ". ";
            inventory[i].printInfo();
        }
    }

    void useItem(int index) {
        if (index < 0 || index >= static_cast<int>(inventory.size())) {
            cout << "Invalid item index!" << endl;
            return;
        }

        Item item = inventory[index];
        if (item.getType() == "potion") {
            cout << name << " uses " << item.getName() << " and heals for " << item.getEffectValue() << " HP." << endl;
            heal(item.getEffectValue());
        } else {
            cout << name << " uses " << item.getName() << ", but nothing happens (not implemented yet)." << endl;
        }

        inventory.erase(inventory.begin() + index);
    }

    void attack(Character& target) {
        double damage = 10;
        cout << name << " attacks " << target.name << " for " << damage << " damage!" << endl;
        target.takeDamage(damage);
    }
};

// Battle Function
void battle(Player& p, Enemy& e) {
    cout << "\n🔥 Battle Starts between " << p.name << " and " << e.name << "!\n";

    while (p.isAlive() && e.isAlive()) {
        p.attack(e);

        if (!e.isAlive()) {
            cout << e.name << " is defeated!\n";
            break;
        }

        e.attack(p);

        if (!p.isAlive()) {
            cout << p.name << " is defeated!\n";
            break;
        }

        cout << "---------------------------\n";
    }

    cout << "\n🏆 Battle Over!\n";
    if (p.isAlive())
        cout << p.name << " wins the battle!\n";
    else
        cout << e.name << " wins the battle!\n";
}

// Main Function
int main() {
    Player p1("Hero");
    Enemy e1("Goblin");

    // Add a potion to the player's inventory
    Item potion("Small Health Potion", "potion", 25);
    p1.addItem(potion);

    cout << "\n";
    p1.printStatus();
    p1.showInventory();

    cout << "\nUsing potion before battle...\n";
    p1.useItem(0);  // Use the first item in inventory

    cout << "\n";
    p1.printStatus();

    battle(p1, e1);

    return 0;
}
