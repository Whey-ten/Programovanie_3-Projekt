#include <iostream>
#include "Spell.h"
/*
 * functions create premade spells for tests
 */
void Spell::createOne() {
    int pow = 15;
    int mana_cost = 1;
    //
    name = "SolidKick";
    power = pow;
    mana = mana_cost;
    type = "attack";
}

void Spell::createTwo() {
    int pow = 25;
    int mana_cost = 10;
    name = "FireBall";
    power = pow;
    mana = mana_cost;
    type = "attack";
}

void Spell::createTree() {
    int pow = 50;
    int mana_cost = 10;
    name = "HolyHeal";
    power = pow;
    mana = mana_cost;
    type = "support";
}
/*
 * operator checks if 2 spells are same
 */
bool Spell::operator==(Spell s) const{
    if(s.getName() != name){
        return false;
    }
    return true;
}
/*
 * function loads spell from string
 */
bool Spell::loadFromString(const std::string& str) {
    int c = numberOfDels(str, ':');
    if(c != 3){
        return false;
    }
    name = subString(str,1,':');
    power = std::stoi(subString(str,2,':'));
    mana = std::stoi(subString(str,3,':'));
    type = subString(str,4,':');
    return true;
}
/*
 * function returns string value of spell
 */
std::string Spell::getFileString() {
    std::string str = "";
    str += getName() + ":";
    str += std::to_string(power) + ":";
    str += std::to_string(mana) + ":";
    str += getType();
    return str;
}