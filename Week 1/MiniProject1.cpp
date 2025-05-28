 /*
    Mini Project -> 01 
    Simple RPG Character System
*/

#include<iostream>
#include<string>

class Character
{
protected:
    int level = 1;
private:
    double health = 100;
public:
    std::string name;


//Constructor
Character(std::string n, bool showMessage = true) {
    name = n;
    if (showMessage) {
        std::cout << "Character " << name << " has entered the game..." << std::endl;
    }
}

//distructor
~Character(){
    std::cout<<"Character "<<name<<" has left the game.."<<std::endl;
}

// Methodes

void takeDamage(double damage) {
    std::cout<<name<<" take "<<damage<<" damage."<<std::endl;
    health -= damage; 
    if (health < 0)    
        health = 0;
}

void heal(double healAmount) {
    std::cout<<name<<" heal by "<<healAmount<<" HP."<<std::endl;
    health += healAmount;
    if (health > 100) 
        health = 100;
}

void printStatus( ) {
    std::cout<<"[Status] Name: "<<name<<", Health: "<<health<<", level: "<<level<<std::endl;

}

 bool isAlive() {
        return health > 0;
    }

};

// derived class
class Mage : public Character {
    private: 
        double mana = 50;

    public:

       Mage(std::string n) : Character(n, false) {
            std::cout << "Mage " << name << " has entered the game..." << std::endl;
        }

    void castSpell(double manaCost) {
        if (mana >= manaCost) {
            mana -= manaCost;
            std::cout << name << " casts a spell! Mana left: " << mana << std::endl;
        } else {
            std::cout << name << " does not have enough mana to cast a spell!" << std::endl;
        }
    }


    void  printStauts(){
        Character:: printStatus(); //call base function
        std::cout<<" Mana: "<<mana<<std::endl;
    }

};

int main( ) {
    Character c1("Unique");
    Mage m1("Shikha");
    std::cout<<std::endl;
    
    c1.takeDamage(20);
    c1.heal(10);
    c1.printStatus();
    std::cout<<std::endl;

    m1.castSpell(10);
    m1.castSpell(45); // Should fail due to low mana
    m1.printStauts();

    std::cout<<std::endl;

    
    return 0;
}