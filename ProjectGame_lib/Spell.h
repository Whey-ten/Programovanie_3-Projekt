#include <iostream>
#include "Load.h"
#ifndef PROJECTGAME_SPELL_H
#define PROJECTGAME_SPELL_H

/**
 * Header file for Spell class of project.
 * Class includes name of spell, its power, mana cost and type of spell.
 */


class Spell {
    std::string name;
    int power;
    int mana;
    std::string type;
public:
    //funkcie pre testy
    void createOne();
    void createTwo();
    void createTree();

    std::string getName(){return name;};
    int getPower() const{return power;};
    int getMana() const{return mana;};
    std::string getType(){return type;};
    bool operator==(Spell s) const;
    //
    bool loadFromString(const std::string& str);
    std::string getFileString();

};


#endif //PROJECTGAME_SPELL_H
