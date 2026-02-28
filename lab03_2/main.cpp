#include "player.h"
#include "lootbox.h"
#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
using namespace std;

void myLabRating() {
    cout << "-------Оценка лабораторной работы 3:--------" << endl;
    cout << "Интерес:       8/10" << endl;
    cout << "Наполненность: 10/10" << endl;
    cout << "Сложность:     7/10" << endl;
    cout << "--------------------------------------------" << endl;
}

int main() {
    srand(time(0));
    Player::Item sword("Меч", "Редкий", "Острый меч");
    Player::Item shield("Щит", "Обычный", "Деревянный щит");
    Player::Item potion("Зелье", "Обычный", "Восстанавливает HP");
    Player::Item bow("Лук", "Легендарный", "Меткий лук");
    Player::Item helmet("Шлем", "Редкий", "Железный шлем");

    cout << "------------Создание игроков----------------" << endl;
    Player player1("P1", 10, 20, 100, "Бежит");
    player1.backpack.push_back(sword);
    player1.backpack.push_back(shield);

    Player player2("P2", 5, 15, 80, "Стоит");
    player2.backpack.push_back(potion);
    player2.backpack.push_back(bow);


    Player player3(player1); 

    cout << "Игрок 1:" << endl;
    player1.show();

    cout << "Игрок 2:" << endl;
    player2.show();

    cout << "Копия игрока 1:" << endl;
    player3.show();

    // геттеры
    cout << "Имя игрока 1: " << player1.getName() << endl;
    cout << "HP игрока 2: " << player2.getHp() << endl;
    cout << "Позиция игрока 1: X=" << player1.getPosX() << " Y=" << player1.getPosY() << endl;

    // сеттеры
    player1.setActionStatus("Атакует");
    cout << "Новый статус игрока 1: " << player1.getActionStatus() << endl;

    cout << "-------------Урон и лечение-------------" << endl;
    player1.takeDamage(30);
    player1.heal(10);
    player2.takeDamage(200);

    vector<Player::Item> lootItems;
    lootItems.push_back(helmet);
    lootItems.push_back(bow);
    lootItems.push_back(potion);

    Lootbox lootbox1("Лутбокс", lootItems);
    lootbox1.show();

    Player::Item dropped = lootbox1.open();
    player1.backpack.push_back(dropped);

    cout << "Инвентарь игрока 1 после лутбокса:" << endl;
    player1.show();

    Lootbox lootbox2(lootbox1);
    cout << "Копия лутбокса:" << endl;
    lootbox2.show();

    cout << "--------------Оператор + -----------" << endl;
    Player player4 = player1 + player2;
    player4.show();

    cout << "--------------Оператор - ---------" << endl;
    Player player5 = player1 - player2;
    player5.show();


    cout << "-----------Оператор / -------------" << endl;
    Player player6 = player1 / player2;
    player6.show();

    myLabRating();

    return 0;
}