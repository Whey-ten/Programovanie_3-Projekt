#include <iostream>
#include <map>
#include <vector>
#include "Spell.h"
#include "Load.h"
#ifndef PROJECTGAME_KLASS_H
#define PROJECTGAME_KLASS_H

/**
 * Class Klass of project includes its name and stats character will get on his current level.
 * Public functions are simple setters and getters.
 *
 */

const int base_hp = 100;
const int base_mana_val = 2;

class Klass {
    std::string name;
    std::map<int, int> lvl_exp;
    std::map<int, int> lvl_hp;
    std::map<int, int> lvl_mana;
    std::map<int, int> lvl_power;
    std::map<int, int> lvl_defense;
    std::map<int, int> lvl_magic;
public:
    void createKlass();
    void createKlassTwo();
    std::string getName() const{return name;};
    int getExp(int lvl)const;
    int getHp(int lvl)const;
    int getMana(int lvl)const;
    int getPower(int lvl)const;
    int getDefense(int lvl)const;
    int getMagic(int lvl)const;
    //
    bool loadFromString(const std::string& str);
    std::string getFileString() const;
};


#endif //PROJECTGAME_KLASS_H
