#include<iostream>
#include<string>

using namespace std;

class Character{
    private:
        string name;
        int hp;
        int attackPower;
    
    public:
        Character(string n, int h, int a) : name(n), hp(h), attackPower(a) {}

        // Declearing friend function
        friend void battle(Character& a, Character& b);

        void showStatus( ) const {
            cout<<"[Status] " << name << " HP: "<< hp << " Attack Power: "<< attackPower << endl;
        }

};

// Friend function: Not a member of Character, but has access to its private data
void battle(Character& a, Character& b) { 
    cout<< endl << "Battle between "<< a.name << " and " << b.name << " begains." << endl;

    a.hp -= b.attackPower;
    b.hp -= a.attackPower;

    cout << a.name << " hits " << b.name << " for " << a.attackPower <<" damage. " << endl;
    cout << b.name << " hits back for " << b.attackPower << " damage." << endl;

    if(a.hp <= 0 && b.hp <= 0 )  cout<<"💀 It's a double K.O." << endl;
    else if(a.hp <= 0) cout << a.name << " is defited!" << endl;
    else if (b.hp <= 0) cout << b.name << " is defited! " << endl;
    else cout<<"Both fighters survive the round." << endl;

}

int main () {
    Character hero("Knight", 100, 30);
    Character enemy("Goblin", 80, 20);

    hero.showStatus();
    enemy.showStatus();

    battle(hero, enemy);

    cout << "After battle: " << endl;
    hero.showStatus();
    enemy.showStatus();

    return 0;
}

