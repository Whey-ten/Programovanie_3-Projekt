#include <iostream>
#include <map>
#include "Klass.h"

/*
 * functions create premade klasses for tests
 */
void Klass::createKlass() {
    int class_exp = 100;
    int class_hp = 20;
    int class_mana = 20;
    int class_power = 10;
    int class_defense = 5;
    int class_magic = 2;
    name = "PreSetWarrior";

    for(int i = 1; i < 10; i++){
        lvl_exp.insert(std::pair<int, int>(i, i * class_exp));
        lvl_hp.insert(std::pair<int, int>(i, (i * class_hp) + base_hp));
        lvl_mana.insert(std::pair<int, int>(i, (i * base_mana_val) + class_mana));
        lvl_power.insert(std::pair<int, int>(i, i + class_power));
        lvl_defense.insert(std::pair<int, int>(i, i + class_defense));
        lvl_magic.insert(std::pair<int, int>(i, i * class_magic));
    }
}

void Klass::createKlassTwo() {
    int class_exp = 100;
    int class_hp = 10;
    int class_mana = 50;
    int class_power = 6;
    int class_defense = 4;
    int class_magic = 6;
    name = "PreSetMage";

    for(int i = 1; i < 10; i++){
        lvl_exp.insert(std::pair<int, int>(i, i * class_exp));
        lvl_hp.insert(std::pair<int, int>(i, (i * class_hp) + base_hp));
        lvl_mana.insert(std::pair<int, int>(i, (i * base_mana_val) + class_mana));
        lvl_power.insert(std::pair<int, int>(i, i + class_power));
        lvl_defense.insert(std::pair<int, int>(i, i + class_defense));
        lvl_magic.insert(std::pair<int, int>(i, i * class_magic));
    }
}

/*
 *functions return value of stat for level from maps
 */

int Klass::getExp(int lvl) const{
    return lvl_exp.at(lvl);
}
int Klass::getHp(int lvl) const{
    return lvl_hp.at(lvl);
}
int Klass::getMana(int lvl) const{
    return  lvl_mana.at(lvl);
}
int Klass::getPower(int lvl) const{
    return lvl_power.at(lvl);
}
int Klass::getDefense(int lvl) const{
    return lvl_defense.at(lvl);
}
int Klass::getMagic(int lvl) const{
    return lvl_magic.at(lvl);
}

/*
 * function loads klass from string
 */

bool Klass::loadFromString(const std::string& str) {
    int c = numberOfDels(str, ':');
    if(c != 6){
        return false;
    }
    std::string name_of = subString(str,1,':');
    name = name_of;
    int exp = std::stoi(subString(str,2,':'));
    for(int i = 0; i < 10; i++){
        lvl_exp.insert(std::pair<int, int>(i, i * exp));
    }
    int hp = std::stoi(subString(str,3,':'));
    for(int i = 0; i < 10; i++){
        lvl_hp.insert(std::pair<int, int>(i, (i * hp) + base_hp));
    }
    int mana = std::stoi(subString(str,4,':'));
    for(int i = 0; i < 10; i++){
        lvl_mana.insert(std::pair<int, int>(i, (i * base_mana_val) + mana));
    }
    int power = std::stoi(subString(str,5,':'));
    for(int i = 0; i < 10; i++){
        lvl_power.insert(std::pair<int, int>(i, i + power));
    }
    int defense = std::stoi(subString(str,6,':'));
    for(int i = 0; i < 10; i++){
        lvl_defense.insert(std::pair<int, int>(i, i + defense));
    }
    int magic = std::stoi(subString(str,7,':'));
    for(int i = 0; i < 10; i++){
        lvl_magic.insert(std::pair<int, int>(i, i * magic));
    }
    return true;
}

/*
 * function returns string value of class
 */

std::string Klass::getFileString() const {
    int lvl = 1;
    std::string str = "";
    str += getName() + ":";
    //
    int i = getExp(lvl);
    std::string s_num = std::to_string(i);
    str += s_num + ":";
    //
    i = getHp(lvl) - base_hp;
    s_num = std::to_string(i);
    str += s_num + ":";
    //
    i = getMana(lvl) - base_mana_val;
    s_num = std::to_string(i);
    str += s_num + ":";
    //
    i = getPower(lvl) - lvl;
    s_num = std::to_string(i);
    str += s_num + ":";
    //
    i = getDefense(lvl) - lvl;
    s_num = std::to_string(i);
    str += s_num + ":";
    //
    i = getMagic(lvl);
    s_num = std::to_string(i);
    str += s_num;

    return str;
}