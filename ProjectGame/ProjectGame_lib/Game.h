#include <iostream>
#include "Character.h"
#include "Map.h"
#include "Load.h"

#ifndef PROJECTGAME_HRA_H
#define PROJECTGAME_HRA_H

/**
 * Header file from Game Class
 * Class is game that is played and simulated.
 *
 */

const int fight_experience = 50;

class Game {
    bool game_state = false;
    Character player;
    Map map;
    Room current_room;
public:
    void PreLoadGame();
    Room getCurrentRoom()const{return current_room;}
    Character getPlayer()const{return player;}
    bool getGameState() const {return game_state;};
    void LoadPlayer(Character new_player);
    bool moveToRoom(const std::string& new_room_name);
    std::string battleSimulation(Character enemy);
    std::string cleanRoom();
    std::string checkCurrentRoom(){return current_room.checkRoom();}
    std::string getCurrentPosition(){return current_room.getName();}
    std::string getNeighborRooms(){return map.getNeighborRooms(current_room.getName());}

    std::string finnishGame();
    //
    bool saveGame();
    bool saveGame(const std::string& file_name);
    bool loadGame(const std::string &file_name);
    bool saveCharacter();
    bool saveCharacter(std::string file_name);



};


#endif //PROJECTGAME_HRA_H
