#ifndef PLAYER_H
#define PLAYER_H

#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Player {
public:
    string name;
    int posX;
    int posY;
    int hp;
    string actionStatus;

    struct Item {
        string itemName;
        string rarity;
        string description;

        Item() {
            itemName = "Неизвестный предмет";
            rarity = "Обычный";
            description = "Нет описания";
        }

        Item(string n, string r, string d) {
            itemName = n;
            rarity = r;
            description = d;
        }

        void show() {
            cout << "Предмет: " << itemName << " | Редкость: " << rarity << " | " << description << endl;
        }
    };

    vector<Item> backpack;


    Player();
    Player(string n, int x, int y, int h, string status);
    Player(Player& other);


    ~Player();


    string getName();
    int getPosX();
    int getPosY();
    int getHp();
    string getActionStatus();
    vector<Item> getBackpack();

    void setName(string n);
    void setPosX(int x);
    void setPosY(int y);
    void setHp(int h);
    void setActionStatus(string status);
    void setBackpack(vector<Item> items);

    void takeDamage(int x);
    void heal(int x);
    void openLootbox(string lootboxName, vector<Item> possibleItems);
    void show();

    Player operator+(Player other);
    Player operator-(Player other);
    Player operator/(Player other);
};

#endif