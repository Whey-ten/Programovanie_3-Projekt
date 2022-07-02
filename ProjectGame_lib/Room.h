#ifndef PROJECTGAME_ROOM_H
#define PROJECTGAME_ROOM_H
#include <iostream>
#include <map>
#include <vector>
#include "Character.h"
#include "Load.h"

/**
 * Header file for class Room
 * Class considers of room name, status of room, enemies located in this room, items hidden in room.
 */

class Room {
    std::string room_name = "";
    std::string status = "";
    std::vector<Character> enemies;
    std::vector<Item> items;
public:
    std::string getName() const{return room_name;}
    std::string getStatus() const{return status;}
    int getNumberOfEnemies() const{return enemies.size();}
    std::string getNamesOfEnemies();
    void createRoomOne();
    void createRoomTwo();
    void createRoomTree();
    void setStatus(std::string value){status = value;}
    std::vector<Character> getEnemies()const{return enemies;};
    std::string checkRoom();
    bool operator==(const Room& r) const;
    bool operator=(const Room& r);
    Item findItem();
    std::vector<Item> getItems()const{return items;}
    void eraseItem(const Item& i);
    void eraseEnemy(const Character& c);
    int getNumberOfItems(){return items.size();}
    //
    bool loadFromString(const std::string& str);
    void addEnemy(const Character& ch){enemies.push_back(ch);};
    void addItem(const Item& i){items.push_back(i);};
    //
    std::string getFileString();
};


#endif //PROJECTGAME_ROOM_H
