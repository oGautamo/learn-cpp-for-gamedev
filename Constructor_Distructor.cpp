#include<iostream>
#include<string>

using namespace std;

class player {
    public:
        string name;
        float health;
    
    // Constructor
    player(string n, float h) {
        name = n;
        health = h;

        cout<<"Player Created:"<<n<<endl;
    }

    // Distructor
    ~player(){
        cout<<"Player  Destroid: "<<name;
    }
};


int main() {
    player p1("Sandip", 100);

    return 0;
}