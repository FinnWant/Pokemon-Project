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
    cout << "7. Battle with a Pokemon\n";
    cout << "8. Exit\n";

    cout << "Enter your choice (1-7): ";
    vector<Pokemon> Mypokemons;

    int choice;
    cin >> choice;

    switch (choice) {
        case 1: 
        {
            string name, type;
            int level;
            int health;
            int attack;
            int defense;
            int speed;
            int specialAttack;
            int specialDefense;
            
            cout << "Enter Pokemon name: ";
            cin >> name;
            cout << "Enter Pokemon type: ";
            cin >> type;
            cout << "Enter level, health, attack, defense, speed, special attack, and special defense: ";
            cin >> level >> health >> attack >> defense >> speed >> specialAttack >> specialDefense;
            Pokemon newPokemon(name, type, level, health, attack, defense, speed, specialAttack, specialDefense);

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
        case 2: 
        {
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
        case 3: 
        {
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
        case 4: 
        {
            if (Mypokemons.empty()) {
                cout << "No Pokemon available. Please create a Pokemon first.\n";
                break;
            }
            cout << "Enter the name of the Pokemon to add a weakness: ";
            string pokemonName, weaknessName;
            cin >> pokemonName;
            cout << "Enter weakness name: ";
            cin >> weaknessName;
            for (auto& pokemon : Mypokemons) {
                if (pokemon.getName() == pokemonName) {
                    pokemon.addWeakness(weaknessName);
                    cout << "Weakness " << weaknessName << " added to " << pokemon.getName() << "\n";
                    break;
                }
            }
            break;
        }
        case 5: 
        {
            if (Mypokemons.empty()) {
                cout << "No Pokemon available. Please create a Pokemon first.\n";
                break;
            }
            cout << "Enter the name of the Pokemon to add a resistance: ";
            string pokemonName, resistanceName;
            cin >> pokemonName;
            cout << "Enter resistance name: ";
            cin >> resistanceName;  
            for (auto& pokemon : Mypokemons) {
                if (pokemon.getName() == pokemonName) {
                    pokemon.addResistance(resistanceName);
                    cout << "Resistance " << resistanceName << " added to " << pokemon.getName() << "\n";
                    break;
                }
            }
            break;
        }
        case 6: 
        {
            if (Mypokemons.empty()) {
                cout << "No Pokemon available. Please create a Pokemon first.\n";
                break;
            }
            cout << "Enter the name of the Pokemon to display details: ";
            string pokemonName;
            cin >> pokemonName;
            for (const auto& pokemon : Mypokemons) {
                if (pokemon.getName() == pokemonName) {
                    cout << "Name: " << pokemon.getName() << "\n";
                    cout << "Type: " << pokemon.getType() << "\n";
                    cout << "Level: " << pokemon.getLevel() << "\n";
                    cout << "Moves: " << (pokemon.getMoves().empty() ? "None" : "") << "\n";
                    for (const auto& move : pokemon.getMoves()) {
                        cout << "- " << move.name << "\n";
                    }
                    cout << "Abilities: " << (pokemon.getAbilities().empty() ? "None" : "") << "\n";
                    for (const auto& ability : pokemon.getAbilities()) {
                        cout << "- " << ability << "\n";
                    }
                    cout << "Weaknesses: " << (pokemon.getWeaknesses().empty() ? "None" : "") << "\n";
                    for (const auto& weakness : pokemon.getWeaknesses()) {
                        cout << "- " << weakness << "\n";
                    }
                    cout << "Resistances: " << (pokemon.getResistances().empty() ? "None" : "") << "\n";
                    for (const auto& resistance : pokemon.getResistances()) {
                        cout << "- " << resistance << "\n";
                    }
                    break;
                }
            }
            break;
        }
        case 7: 
        {
            if (Mypokemons.empty()) {
                cout << "No Pokemon available. Please create a Pokemon first.\n";
                break;
            }
            cout << "Enter the name of the Pokemon to battle: ";
            string pokemonName;
            cin >> pokemonName;
            bool found = false;
            for (const auto& pokemon : Mypokemons) {
                if (pokemon.getName() == pokemonName) {
                    found = true;
                    cout << "Battling with " << pokemon.getName() << "!\n";
                    // create simple opponent Pokemon or choose from existing ones
                    cout << "Choose an opponent Pokemon (or create a new one):\n";
                    cout << "1. Create a new opponent Pokemon\n";
                    cout << "2. Use an existing Pokemon\n";
                    int opponentChoice;
                    cin >> opponentChoice;
                    if (opponentChoice == 1) {
                        string opponentName, opponentType;
                        int opponentLevel, opponentHealth, opponentAttack, opponentDefense, opponentSpeed, 
                        opponentSpecialAttack, opponentSpecialDefense;

                        cout << "Enter opponent Pokemon name, type, level, health, attack, defense, speed, special attack, and special defense: ";
                        cin >> opponentName >> opponentType >> opponentLevel >> opponentHealth >> opponentAttack >> 
                        opponentDefense >> opponentSpeed >> opponentSpecialAttack >> opponentSpecialDefense;
                        // Create opponent Pokemon
                        Pokemon opponentPokemon(opponentName, opponentType, opponentLevel, opponentHealth,
                         opponentAttack, opponentDefense, opponentSpeed, opponentSpecialAttack, opponentSpecialDefense);
                        // Automatically add weaknesses and resistances based on type
                        auto it = typeChart.find(opponentType);
                        if (it != typeChart.end()) {
                            opponentPokemon.addWeakness(it->second.first);
                            opponentPokemon.addResistance(it->second.second);
                        }
                        cout << "Opponent Pokemon " << opponentPokemon.getName() << " created!\n";
                    } else if (opponentChoice == 2) {
                        cout << "Enter the name of the existing opponent Pokemon: ";
                        string opponentName;
                        cin >> opponentName;
                        bool opponentFound = false;
                        for (auto& opponent : Mypokemons) {
                            if (opponent.getName() == opponentName) {
                                opponentFound = true;
                                cout << "Battling with opponent " << opponent.getName() << "!\n";
                                while(pokemon.getHealth() > 0 && opponent.getHealth() > 0){
                                    bool playerTurn = pokemon.getSpeed() >= opponent.getSpeed();
                                    if (playerTurn) {
                                        cout << pokemon.getName() << "'s turn. Choose a move:\n";
                                        vector<Move> moves = pokemon.getMoves();
                                        for (size_t i = 0; i < moves.size(); ++i) {
                                            cout << i + 1 << ". " << moves[i].name << "\n";
                                        }
                                        int moveChoice;
                                        cin >> moveChoice;
                                        if (moveChoice < 1 || moveChoice > moves.size()) {
                                            cout << "Invalid move choice. Try again.\n";
                                            continue;
                                        }
                                        string chosenMove = moves[moveChoice - 1].name;
                                        cout << pokemon.getName() << " used " << chosenMove << "!\n";
                                        // damage calculation
                                        if(moves[moveChoice - 1].specialAttackMove) {
                                            int damage = (((2 * pokemon.getLevel()) / 5) + 2) * 
                                            (pokemon.getSpecialAttack() / opponent.getSpecialDefense()) * 
                                            moves[moveChoice - 1].power / 50;
                                            opponent.setHealth(opponent.getHealth() - damage);
                                            cout << "It dealt " << damage << " damage to " << opponent.getName() << "!\n";
                                        } else {
                                            int damage = (((2 * pokemon.getLevel()) / 5) + 2) * 
                                            (pokemon.getAttack() / opponent.getDefense()) * 
                                            moves[moveChoice - 1].power / 50;
                                            opponent.setHealth(opponent.getHealth() - damage);
                                            cout << "It dealt " << damage << " damage to " << opponent.getName() << "!\n";
                                        }
                                        //continue battle implementation...
                                    }
                                }
                            }
                        }
                        if (!opponentFound) {
                            cout << "Opponent Pokemon not found. Please create or choose an existing Pokemon.\n";
                            break;
                        }
                    } 
                    else {
                        cout << "Invalid choice. Please choose 1 or 2.\n";
                        break;
                    }
                    break;
                }
            }
            break;
        }
        case 8: 
        {
            cout << "Exiting the Pokemon Manager. Goodbye!\n";
            return 0;
        }
    }
}
