#include "Pokemon.h"
#include <iostream>
#include <string> 

using namespace std;

void Pokemon::addMove(const string& move) {
    Move newMove;
    newMove.name = move;
    cout << "Enter type, power, and accuracy for move " << move << ": ";
    cin >> newMove.type >> newMove.power >> newMove.accuracy;
    // Determine if the move is a special attack move
    cout << "Is this a special attack move? (1 for yes, 0 for no): ";
    int special;
    cin >> special;
    newMove.specialAttackMove = (special == 1);
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