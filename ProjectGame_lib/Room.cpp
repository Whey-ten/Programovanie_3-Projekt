#include "Room.h"
/*
 * function returns names of enemies currently occupying room
 */
std::string Room::getNamesOfEnemies() {
    std::string return_value= "";
    for(auto it = enemies.begin(); it != enemies.end(); it++){
        return_value += it->getName();
        return_value += " & ";
    }
    if(return_value.size() != 0){
        return_value = return_value.substr(0, return_value.length()-3);
    }
    return return_value;
}
/*
 * functions create premade rooms for tests
 */
void Room::createRoomOne() {
    room_name = "Entry";
    status = "hidden";
    Item i1, i2;
    i1.createItemOne();
    i2.createItemTwo();
    items.push_back(i1);
}

void Room::createRoomTwo() {
    room_name = "room1";
    status = "full";
    Character ch1, ch2;
    ch1.createGoonOne();
    ch2.createGoonTwo();
    enemies.push_back(ch1);
    enemies.push_back(ch2);
}

void Room::createRoomTree() {
    room_name = "BossRoom";
    status = "full";
    Character ch;
    ch.createBoss();
    enemies.push_back(ch);
}
/*
 * functions erases enemy from room
 */
void Room::eraseEnemy(const Character& c) {
    auto itr = enemies.begin();
    for(auto it = enemies.begin(); it != enemies.end(); it++){
        Character c2 = *it;
        if(c2 == c){
            itr = it;
        }
    }
    enemies.erase(itr);
}
/*
 * function erases iteam from room
 */
void Room::eraseItem(const Item& i){
    auto itr = items.begin();
    for(auto it = items.begin(); it != items.end(); it++){
        Item i2 = *it;
        if(i2 == i){
            itr = it;
        }
    }
    items.erase(itr);
}
/*
 * function simualates search of room and returns random item existing in room
 */
Item Room::findItem() {
    int randomIndex = rand() % items.size();
    Item i = items.at(randomIndex);
    eraseItem(i);
    return i;
}
/*
 * operator checks if 2 rooms are same
 */
bool Room::operator==(const Room& r) const {
    if(room_name == r.getName()){
        return true;
    }
    return false;
}
/*
 * operator copies one room to another
 */
bool Room::operator=(const Room& r) {
    room_name = r.getName();
    status = r.getStatus();
    enemies = r.getEnemies();
    items = r.getItems();
    return true;
}
/*
 * function loads room from string
 */
bool Room::loadFromString(const std::string& str) {
    int c = numberOfDels(str, ',');
    if(c != 3){
        return false;
    }
    std::string subs;
    std::string name = subString(str,1,',');
    std::string state = subString(str,2,',');
    std::string enemy = subString(str,3,',');
    std::string item = subString(str,4,',');
    room_name = name;
    status = state;
    char ch = enemy[0];
    c = ch - '0';
    for(int i = 0; i < c; i++){
        Character character;
        subs = subString(enemy,i+2,'@');
        if(!character.loadFromString(subs)){
            return false;
        }
        addEnemy(character);
    }
    ch = item[0];
    c = ch - '0';
    for(int i = 0; i < c; i++){
        Item new_item;
        subs = subString(item, i+2,'@');
        if(!new_item.loadFromString(subs)){
            return false;
        }
        addItem(new_item);
    }
    return true;
}
/*
 * function returns string value of room
 */
std::string Room::getFileString() {
    std::string str = "";
    str += getName() + ",";
    str += getStatus() + ",";
    //enemies
    str += std::to_string(enemies.size());
    for(auto it = enemies.begin(); it != enemies.end(); it++){
        str += "@";
        std::string enemy_string = it->getFileString();
        str += enemy_string;
    }
    str += ",";
    //items
    str += std::to_string(items.size());
    for(auto it = items.begin(); it != items.end(); it++){
        str += "@";
        std::string item_string = it->getFileString();
        str += item_string;
    }

    return str;
}