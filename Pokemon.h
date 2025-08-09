#ifndef POKEMON_H
#define POKEMON_H

#include <string>
#include <vector>

using namespace std;

struct Move{
    string name;
    string type;
    int power;
    int accuracy;
};

class Pokemon {
    private:
        string name;
        string type;
        int level;
        vector<Move> moves;
        vector <string> abilities;
        vector<string> weaknesses;
        vector<string> resistances;
    public:
        Pokemon(const string& name, const string& type, int level){
            this->name = name;
            this->type = type;
            this->level = level;
        };
        void addMove(const string& move);
        void addAbility(const string& ability);
        void addWeakness(const string& weakness);
        void addResistance(const string& resistance);
        string getName() const { return name; }
        string getType() const { return type; } 
        int getLevel() const { return level; }
        vector<string> getMoves() const{
            vector<string> moveNames;
            for (const auto& move : moves) {
                moveNames.push_back(move.name);
            }
            return moveNames;
        };
        vector<string> getAbilities() const { return abilities; }
        vector<string> getWeaknesses() const { return weaknesses; }
        vector<string> getResistances() const { return resistances; }
};

#endif // POKEMON_H