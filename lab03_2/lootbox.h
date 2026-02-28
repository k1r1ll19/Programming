#ifndef LOOTBOX_H
#define LOOTBOX_H

#include "player.h"
#include <vector>
#include <iostream>
using namespace std;

class Lootbox {
public:
    string name;
    vector<Player::Item> possibleItems;

    Lootbox();
    Lootbox(string n, vector<Player::Item> items);
    Lootbox(Lootbox& other);

    ~Lootbox();

    Player::Item open();

    void show();
};

#endif