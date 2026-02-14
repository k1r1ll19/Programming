#ifndef PLAYER_H
#define PLAYER_H

#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Player {
private:
    string name;
    int posX, posY;
    int hp;
    vector<char> backpack;
    
public:
    Player();
    Player(string n, int x, int y, int h, vector<char> items);
    
    Player(const Player& other);
    Player& operator=(const Player& other);
    ~Player();
    
    Player operator+(const Player& other);
    Player operator-(const Player& other);
    Player operator/(const Player& other);
    
    void show();
};

#endif