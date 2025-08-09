#include "Pokemon.h"
#include <iostream>
#include <map>
#include <string>
#include <vector>

using namespace std;

// Map type to pair<weakness, resistance>
const map<string, pair<string, string>> typeChart = {
    {"Fire",     {"Water", "Grass"}},
    {"Water",    {"Electric", "Fire"}},
    {"Grass",    {"Fire", "Water"}},
    {"Electric", {"Ground", "Water"}},
    {"Ground",   {"Water", "Electric"}},
    {"Psychic",  {"Dark", "Fighting"}},
    {"Dark",     {"Fighting", "Psychic"}},
    {"Fighting", {"Psychic", "Dark"}},
    {"Ice",      {"Fire", "Water"}},
    {"Dragon",   {"Ice", "Dragon"}},
    {"Fairy",    {"Steel", "Dragon"}},
    {"Steel",    {"Fire", "Fairy"}},
    {"Normal",   {"Fighting", "Ghost"}},
    {"Ghost",    {"Dark", "Normal"}},
    {"Rock",     {"Water", "Flying"}},
    {"Flying",   {"Electric", "Rock"}},
    {"Bug",      {"Fire", "Grass"}},
    {"Poison",   {"Psychic", "Fairy"}}
};

int main() {
    cout << "Welcome to the Pokemon Manager!\n";
    cout << "What would you like to do?\n";
    cout << "1. Create a new Pokemon\n";
    cout << "2. Add a move to a Pokemon\n";
    cout << "3. Add an ability to a Pokemon\n";
    cout << "4. Add a weakness to a Pokemon\n";
    cout << "5. Add a resistance to a Pokemon\n";
    cout << "6. Display Pokemon details\n";
    cout << "7. Exit\n";

    cout << "Enter your choice (1-7): ";
    vector<Pokemon> Mypokemons;

    int choice;
    cin >> choice;

    switch (choice) {
        case 1: {
            cout << "Enter Pokemon name, type, and level: ";
            string name, type;
            int level;
            cin >> name >> type >> level;
            Pokemon newPokemon(name, type, level);

            //automatically weaknesses, and resistances based off entered type
            auto it = typeChart.find(type);
            if (it != typeChart.end()) {
                newPokemon.addWeakness(it->second.first);
                newPokemon.addResistance(it->second.second);
            } else {
                cout << "Unknown type. No weaknesses or resistances added.\n";
            }

            cout << "Enter abilities (separated by spaces and end with DONE): ";
            string ability;
            while (cin >> ability && ability != "DONE") {
                newPokemon.addAbility(ability);
            }

            cout<< "Enter Moves for your new Pokemon: ";
            string move;
            cin >> move;

            while(newPokemon.getMoves().size() < 4){
                newPokemon.addMove(move);
                cout << "Enter another move (or type DONE to finish): ";
                cin >> move;
                if (move == "DONE") {
                    break;
                }
            }
            
            cout << "Pokemon " << newPokemon.getName() << " created!\n";
            Mypokemons.push_back(newPokemon);
            break;
        }
        case 2: {
            if (Mypokemons.empty()) {
                cout << "No Pokemon available. Please create a Pokemon first.\n";
                break;
            }
            cout << "Enter the name of the Pokemon to add a move: ";
            string pokemonName, moveName;
            cin >> pokemonName;
            cout << "Enter move name: ";
            cin >> moveName;
            for (auto& pokemon : Mypokemons) {
                if (pokemon.getName() == pokemonName) {
                    pokemon.addMove(moveName);
                    cout << "Move " << moveName << " added to " << pokemon.getName() << "\n";
                    break;
                }
            }
            break;
        }
        case 3: {
            if (Mypokemons.empty()) {
                cout << "No Pokemon available. Please create a Pokemon first.\n";
                break;
            }
            cout << "Enter the name of the Pokemon to add an ability: ";
            string pokemonName, abilityName;
            cin >> pokemonName;
            cout << "Enter ability name: ";
            cin >> abilityName;
            for (auto& pokemon : Mypokemons) {
                if (pokemon.getName() == pokemonName) {
                    pokemon.addAbility(abilityName);
                    cout << "Ability " << abilityName << " added to " << pokemon.getName() << "\n";
                    break;
                }
            }
            break;
        }
};
}