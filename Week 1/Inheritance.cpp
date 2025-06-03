
#include<iostream>

// Base Class
class Creature{
    public:
       static double HP;
       std::string name;

       Creature(std::string n) {
        name = n;
        std::cout<<"Creature: "<< name << std::endl;
       }

      
};

// Derived Class 
class Monster : public Creature{
    public:
        Monster(std:: string n) : Creature(n) {
            std::cout<<"Monster: "<< n << std::endl;
        
        }


};

// derived class from another Derived class 
class Dragon : public Monster{
    public: 
        Dragon(std::string n) : Monster(n){
            std::cout<<"Dragon: " << n << std::endl;
        }
        void getHP( ){
            double hp;
            std::cout<<"Enter the HP for "<<name<<" Dragon "<<std::endl;
            std::cin>>hp;
             HP = hp;
        }

        void printInfo( ){
            std::cout<<"[Info] Dragon: "<< name << " HP: "<<HP;
        }

        
};

double Creature :: HP(100);


int main ( ) {
    // Creature c1("Unique");
    // Monster m1("Unique");
    Dragon d1("Unique");
    d1.getHP();
    d1.printInfo();


    return 0;
}