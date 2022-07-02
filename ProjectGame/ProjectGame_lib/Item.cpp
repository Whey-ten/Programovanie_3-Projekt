#include "Item.h"
/*
 * functions to create premade items for tests
 */
void Item::createItemOne() {
    name = "Sword";
    type = "off";
    value = 10;
}

void Item::createItemTwo() {
    name = "Shield";
    type = "def";
    value = 5;
}
/*
 * operator checks if 2 spells are same
 */
bool Item::operator==(const Item& i) const {
    if(name == i.getName() && type == i.getType() && value == i.getValue()){
        return true;
    }
    return false;
}
/*
 * function loads spell from string
 */
bool Item::loadFromString(const std::string& str) {
    int c = numberOfDels(str, ':');
    if(c != 2){
        return false;
    }
    name = subString(str,1,':');
    type = subString(str,2,':');
    value = std::stoi(subString(str,3,':'));
    return true;
}
/*
 * function returns string value of spell
 */
std::string Item::getFileString() const {
    std::string str = "";
    str += getName() + ":";
    str += getType() + ":";
    str += std::to_string(value);
    return str;
}
