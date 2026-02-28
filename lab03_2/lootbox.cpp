#include "lootbox.h"
#include <iostream>
#include <cstdlib>
using namespace std;

Lootbox::Lootbox() {
    name = "Обычный лутбокс";
}

Lootbox::Lootbox(string n, vector<Player::Item> items) {
    name = n;
    possibleItems = items;
}

Lootbox::Lootbox(Lootbox& other) {
    name = other.name;
    possibleItems = other.possibleItems;
}

Lootbox::~Lootbox() {
    possibleItems.clear();
    cout << "Лутбокс \"" << name << "\" удалён из памяти" << endl;
}

Player::Item Lootbox::open() {
    int randomIndex = rand() % possibleItems.size();
    Player::Item droppedItem = possibleItems[randomIndex];
    cout << "Из лутбокса \"" << name << "\" выпал предмет: " << droppedItem.itemName << endl;
    return droppedItem;
}

void Lootbox::show() {
    cout << "----------------" << name << "----------------" << endl;
    cout << "Возможные предметы:" << endl;
    for (int i = 0; i < possibleItems.size(); i++) {
        cout << "  " << i + 1 << ") ";
        possibleItems[i].show();
    }
    cout << "--------------------------------------" << endl;
}