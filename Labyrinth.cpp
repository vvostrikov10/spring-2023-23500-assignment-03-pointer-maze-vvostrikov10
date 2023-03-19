#include "Labyrinth.h"

bool isPathToFreedom(MazeCell* start, const std::string& moves) {
    bool wandFound, bookFound, potionFound = false;
    bool validPath = true;
    MazeCell* current = start;
    if (current->whatsHere == Item::POTION) potionFound = true;
    if (current->whatsHere == Item::SPELLBOOK) bookFound = true;
    if (current->whatsHere == Item::WAND) wandFound = true;
    for (int i = 0; i < moves.size(); i++){
        switch (moves[i]){
            case 'N':
                current = current->north;
                break;
            case 'S':
                current = current->south;
                break;
            case 'W':
                current = current->west;
                break;
            case 'E':
                current = current->east;
                break;
        }
        if (current == nullptr){
            validPath = false;
            break;
        }
        if (current->whatsHere == Item::POTION) potionFound = true;
        if (current->whatsHere == Item::SPELLBOOK) bookFound = true;
        if (current->whatsHere == Item::WAND) wandFound = true;
    }
    if (validPath && potionFound && wandFound && bookFound) return true;
    return false;
}
