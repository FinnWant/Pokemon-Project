#include "Pokemon.h"
#include <iostream>
#include <string> 

using namespace std;

void Pokemon::addMove(const string& move) {
    Move newMove;
    newMove.name = move;
    cout << "Enter type, power, and accuracy for move " << move << ": ";
    cin >> newMove.type >> newMove.power >> newMove.accuracy;
    moves.push_back(newMove);
    cout << "Move " << move << " added successfully \n";
};

void Pokemon::addAbility(const string& ability) {
    abilities.push_back(ability);
}

void Pokemon::addWeakness(const string& weakness) {
    weaknesses.push_back(weakness);
}

void Pokemon::addResistance(const string& resistance) {
    resistances.push_back(resistance);
}