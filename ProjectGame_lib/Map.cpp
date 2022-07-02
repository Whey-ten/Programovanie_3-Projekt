#include "Map.h"
#include <iostream>
#include <fstream>

/*
 * Premade function to create testing map
 */
void Map::createMap() {
    map_name = "AutoCreatedMap1";
    Room r1, r2, r3;
    r1.createRoomOne();
    r2.createRoomTwo();
    r3.createRoomTree();
    rooms.push_back(r1);
    rooms.push_back(r2);
    rooms.push_back(r3);
    rooms_map.insert(std::make_pair(r1.getName(), r2.getName()));
    rooms_map.insert(std::make_pair(r2.getName(), r1.getName()));
    rooms_map.insert(std::make_pair(r2.getName(), r3.getName()));
    rooms_map.insert(std::make_pair(r3.getName(), r2.getName()));
}
/*
 * function return room from string name
 */
Room Map::getRoom(const std::string& room_name) const {
    Room r;
    for(auto it = rooms.begin(); it != rooms.end(); it++){
        if(it->getName() == room_name){
            return *it;
        }
    }
    return r;
}
/*
 * function copies from new room to existing one
 */
bool Map::updateRoom(const std::string& room_name, const Room& r) {
    for(auto it = rooms.begin(); it != rooms.end(); it++){
        if(it->getName() == room_name){
            it->operator=(r);
        }
    }
    return true;
}
/*
 * function returns name of rooms that are neighbor to selected one
 */
std::string Map::getNeighborRooms(const std::string& room_name) const {
    std::string return_value = "";
    for(auto it = rooms_map.begin(); it != rooms_map.end(); it++){
        if(it->first == room_name){
            return_value += it->second;
            return_value += ", ";
        }
    }
    if(return_value.size() != 0){
        return_value = return_value.substr(0, return_value.length()-2);
    }
    return return_value;
}
/*
 * function checks of 2 rooms are neighbor
 */
bool Map::isNeighbor(const std::string& room_name1, const std::string& room_name2) {
    for(auto it = rooms_map.begin(); it != rooms_map.end(); it++){
        if(it->first == room_name1 && it->second == room_name2){
            return true;
        }
    }
    return false;
}
/*
 * functions add to map way of travel
 */
void Map::addWay(const std::string& r1, const std::string& r2) {
    rooms_map.insert(std::make_pair(r1, r2));
}
/*
 * functions save map to file
 */
bool Map::saveToFile() {
    return saveToFile(getName());
}

bool Map::saveToFile(const std::string &file_name) {
    std::string f_name = file_name + ".txt";
    std::ofstream outfile (f_name);
    outfile << getName() << std::endl;
    outfile << rooms.size() << std::endl;
    for(auto it = rooms.begin(); it != rooms.end(); it++){
        std::string room_string = it->getFileString();
        outfile << room_string << std::endl;
    }
    outfile << rooms_map.size() << std::endl;
    for(auto it = rooms_map.begin(); it != rooms_map.end(); it++){
        std::string map_string = it->first + "," + it->second;
        outfile << map_string << std::endl;
    }
    outfile.close();
    return true;
}