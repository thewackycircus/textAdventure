// textAdventure.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

using namespace std;
string isFight;

class Player {
    public:
        int health = 50;
        bool isDefending = false;
};

class Enemy {
    public:
        int health = 15;
        bool isCharging = false;
};

Player player;
Enemy enemy;

void Fight();
void Decision();

int main()
{
    cout << "a divine angel looks down upon you menacingly!" << endl << "will you fight, defend or run?" << endl;

    while (isFight != "run" && isFight != "fight") {
        Decision();
    }
}

void Decision() {
    cin >> isFight;
    player.isDefending = false;

    if (isFight == "run") {
        cout << "You safely ran away!" << endl;
    }
    else if (isFight == "fight") {
        cout << "You stand your ground and fight!" << endl;
        Fight();
    }
    else if (isFight == "defend") {
        cout << "You defend your position!" << endl;
        player.isDefending = true;
        Fight();
    }
    else {
        cout << "You must fight, defend or run!" << endl;
    }
}

void EnemyAttack() {
    int decision = rand() % 3;
    
    if (!enemy.isCharging) {
        if (decision == 0) {
            cout << "Angel swung and missed you!" << endl;
        }
        else if (decision == 1) {
            if (!player.isDefending) {
                int damage = (rand() % 5) + 1;
                cout << "Angel hit you for " << damage << " damage!" << endl;
                player.health -= damage;
            }
            else {
                cout << "Angel hit you but you defended against all damage" << endl;
            }
        }
        else if (decision == 2) {
            enemy.isCharging = true;
            cout << "Angel charges an attack!" << endl;
        }
    }
    else {
        if (!player.isDefending) {
            int damage = ((rand() % 5) + 1) * 5;
            cout << "Angel hit you really hard for " << damage << " damage!" << endl;
            player.health -= damage;
        }
        else if (player.isDefending) {
            int damage = ((rand() % 5) + 1);
            cout << "Angel hit you really hard for " << damage << " damage! But you defended most of the damage!" << endl;
            player.health -= damage;
        }
        enemy.isCharging = false;
        
    }
}

void Fight() {

    if (!player.isDefending) {
        enemy.health -= 1;
        cout << "You hit enemy for 1 damage! Enemy now has " << enemy.health << " health!" << endl;
    }

    //p_health -= 1;
    //cout << "Enemy hit you for 1 damage! You now have " << p_health << " health!" << endl;

    EnemyAttack();

    if (player.health <= 0) {
        cout << "You died!";
    }
    else if (enemy.health <= 0) {
        cout << "goblin died!";
    }
    else {
        cout << "_______________________________________" << endl;
        cout << "Would you like to fight, defend or run?" << endl;
        Decision();
    }
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
