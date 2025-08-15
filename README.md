# Pokémon Creator & Battle Simulator

## A simple C++ console application that allows you to create custom Pokémon, manage their stats, abilities, moves, and engage them in basic battles.

## Features

- Create Custom Pokémon

- Define name, type, level, and battle stats (HP, Attack, Defense, Speed, Special Attack, Special Defense).

- Automatically assign weaknesses and resistances based on type.

- Move Management

- Add up to 4 moves per Pokémon with type, power, and accuracy.

- Ability Management

- Add any number of abilities to a Pokémon.

- Type System

- Built-in type chart with predefined weaknesses and resistances.

- Display Pokémon Details

- View stats, moves, abilities, weaknesses, and resistances.

# Battle System (Basic)

Choose an existing Pokémon or create a new opponent to battle.

## How It Works

The application runs as an interactive console menu:

Create a new Pokémon

Add a move

Add an ability

Add a weakness

Add a resistance

Display Pokémon details

Battle with a Pokémon

Exit

File Structure
📂 src  
 ├── Pokemon.h         # Pokémon class definition & Move struct  
 ├── PokemonImp.cpp    # Pokémon class method implementations  
 ├── PokemonMain.cpp   # Main menu & application logic  

## Compilation & Running
Using g++ (Linux/Mac)
g++ PokemonMain.cpp PokemonImp.cpp -o pokemon
./pokemon

Using MinGW (Windows)
g++ PokemonMain.cpp PokemonImp.cpp -o pokemon.exe
pokemon.exe

Example Usage
Welcome to the Pokemon Manager!
1. Create a new Pokemon
2. Add a move to a Pokemon
...
Enter your choice (1-8): 1
Enter Pokemon name: Pikachu
Enter Pokemon type: Electric
Enter level, health, attack, defense, speed, special attack, and special defense: 50 120 85 60 90 75 70
Enter abilities (separated by spaces and end with DONE): Static LightningRod DONE
Enter Moves for your new Pokemon: Thunderbolt
Enter type, power, and accuracy for move Thunderbolt: Electric 90 100
Enter another move (or type DONE to finish): QuickAttack
Enter type, power, and accuracy for move QuickAttack: Normal 40 100
...
Pokemon Pikachu created!

## Planned Improvements

-Implement full battle mechanics (damage calculation, turn order, type effectiveness).

-Save/Load Pokémon data from files.

-Add multi-Pokémon battles.

## License

This project is open-source and free to modify.
