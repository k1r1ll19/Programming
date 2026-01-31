#include <iostream>
#include <string>
using namespace std;

//3 вариант

class Player {
private:
    string name;
    int hp;
    void checkHp() {
        if (hp <= 0) {
            hp = 0;
            actionStatus = "Dead";
        } 
        else if (hp > 100) {
            hp = 100;
        }
    }
    float x;
    float y;
    string actionStatus;
public:
    Player() {
        name = "Unknown";
        x = 0.0;
        y = 0.0;
        hp = 100;
        actionStatus = "Stand";
    }

    Player(string n, double posX, double posY, int health, string status) {
        name = n;
        x = posX;
        y = posY;
        hp = health;
        checkHp();
        actionStatus = status;
    }

    Player(const Player &other) {         
        name = other.name;
        x = other.x;
        y = other.y;
        hp = other.hp;
        actionStatus = other.actionStatus;
    }

    ~Player() {
        cout << "Run_Destructor" << endl;
    }


    //геттеры
    string getName() {
        return name;
    }
    float getX() {
        return x; 
    }
    float getY() { 
        return y; 
    }
    int getHp() {
        return hp; 
    }
    string getStatus() { 
        return actionStatus; 
    }

    //сеттеры
    void setPositionX(float posX) {
        x = posX;
        cout << "Moving to X: " << posX << endl;
    }
    void setPositionY(float posY) {
        y = posY;
        cout << "Moving to Y: " << posY << endl;
    }


    void damage(int dmg) {
        if (dmg > 0) {
            hp -= dmg;
            checkHp();
            cout << name << " Took " << dmg << " damage." << endl;
            cout << "HP: " << hp << endl;
        }
    }

    void heal(int cnt) {
        if (cnt > 0) {
            if (hp > 0) {
                hp += cnt;
                checkHp();
                cout << name << " cured by " << cnt << ". Current hp: " << hp << endl;
                cout << "HP: " << hp << endl;
            } 
            else {
                cout << "The player is dead and cannot be treated." << endl;
            }
        }
    }
    void info() {
        cout << "----------------------------" << endl;
        cout << "Information" << endl;
        cout << "Name: " << name << endl;
        cout << "Position: (" << x << "; " << y << ")" << endl;
        cout << "HP: " << hp << endl;
        cout << "Status: " << actionStatus << endl;
        cout << "----------------------------" << endl;
    }
};
int main() {

    Player player1;
    player1.info();

    Player player2("Hero", 10.5, 20.0, 100, "Attack");
    player2.info();

    Player player3 = player2;
    player3.info();


    player1.setPositionX(50.0);
    player1.setPositionY(50.0);
    player2.damage(30);
    player2.heal(10);
    player3.damage(150);

    return 0;
    }