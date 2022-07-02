#ifndef PROJECTGAME_MAP_H
#define PROJECTGAME_MAP_H

#include <iostream>
#include <map>
#include "Room.h"

/**
 * Header file for Class map.
 * Class represents map on which is game played.
 * Class considers of: name of map, vector of rooms that map includes, multimap of possible ways to travel on map
 */

class Map {
    std::string map_name = "";
    std::vector<Room> rooms;
    std::multimap<std::string, std::string> rooms_map;

public:
    std::string getName() const{return map_name;}
    std::string getNeighborRooms(const std::string& room_name) const;
    Room getRoom(const std::string& room_name) const;
    bool updateRoom(const std::string& room_name, const Room& r);
    std::vector<Room> getAllRooms()const{return rooms;};
    bool isNeighbor(const std::string& room_name1, const std::string& room_name2);
    void createMap();
    Room getEntryRoom(){return rooms.front();}
    //
    void setName(std::string n){map_name = n;};
    void addRoom(Room r){rooms.push_back(r);};
    void addWay(const std::string& r1, const std::string& r2);
    //
    //bool loadFromString(std::string str);
    bool saveToFile(const std::string& file_name);
    bool saveToFile();

};


#endif //PROJECTGAME_MAP_H
