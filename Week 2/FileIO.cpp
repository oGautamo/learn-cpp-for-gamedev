#include<iostream>
#include<fstream>
#include<string>


class Player {
    public:
        std::string name;
        double hp;
        int level;

        Player(std::string n = "Unknown", double h = 100, int l = 1) : name(n), hp(h), level(l) {}

        void saveToFile(const std::string& fileName) {
            std::ofstream outFile(fileName);  // std::ofstream --> Write to a file
            if(outFile.is_open()){
                outFile << name << std::endl;
                outFile << hp << std::endl;
                outFile << level << std::endl;
                outFile.close();
                std::cout << "Game Saved! " << std::endl;
            } else {
                std::cout << "Fail to open file for writing." << std::endl;
            }
        }

        void LoadFromFile(const std::string& fileName) {
            std::ifstream inFile(fileName);  // std::ifstream --> Read from a file
            if(inFile.is_open()){
                std::getline(inFile, name);
                inFile >> hp;
                inFile >> level;
                inFile.close();
                std::cout << "Game Loaded! " << std::endl;   
            } else {
                std::cout << "Failed to open file for reading." << std::endl;
            }
        }

};


int main() {
    Player p1("Shikha");

    Player p2("Sandeep", 125, 6);

    p2.saveToFile("saveGame.txt");
    p2.LoadFromFile("saveGame.txt");
}