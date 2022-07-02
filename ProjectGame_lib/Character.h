#include <iostream>
#include "Klass.h"
#include "Stats.h"
#include "Item.h"
#include "Load.h"

#ifndef PROJECTGAME_CHARACTER_H
#define PROJECTGAME_CHARACTER_H
/**
 * Header file for Character class.
 * This class defines player's character as well as other enemies he might meet during the game
 * Class includes private values like: name of character, level of character, current experience, class/klass of character,
 * stats of character, his current available spells with cooldown and if character is alive or not.
 * Public functions of class include simple getters and setter for private values of character and simple functions to
 * change stats of character, use it's spells.
 */

class Character {
    std::string name = "";
    int level = 1;
    int experience = 0;
    Klass klassa;
    Stats stats;
    //
    std::vector<Spell> spells;
    std::map<std::string, int> spells_cooldown;
    std::vector<Item> equipment;
    bool alive = true;
public:
    void setName();
    void setName(std::string name);
    void setKlass(Klass klass);
    void setStats(int &lvl);
    std::string getName() const{return name;};
    int getLevel() const{return level;};
    int getExp() const{return experience;};
    int getHP() const{return stats.getCurrentHP();};
    int getPower() const{return stats.getPower();};
    int getDefense() const{return stats.getDefense();};
    int getMagic() const{return stats.getMagic();};
    bool isAlive() const{return alive;};

    Klass getKlass() const{return klassa;};
    //
    bool checkLevelUp();
    void levelUp(int cap);
    void addExp(int exp);
    void setMaxHP(int new_value);
    void changeHP(bool plus, int value);
    void changeMana(bool plus, int value);
    void changePower(bool plus, int value);
    void changeDefense(bool plus, int value);
    void changeMagic(bool plus, int value);
    //

    bool learnSpell(Spell s);
    int castRandomSpell();
    Spell getSpellFromName(const std::string& name_of_spell)const;
    //
    bool equipItem(const Item& i);
    bool unequipItem(const Item& i);
    bool unequipItem(const std::string& item_name);
    // Premade Characters for tests
    void createMage();
    void createWarrior();
    void createGoonOne();
    void createGoonTwo();
    void createBoss();
    //
    void printStatus();
    bool operator==(const Character& c) const;
    //
    bool loadFromString(const std::string& str);
    bool loadFromFile(const std::string& file_name);
    bool saveToFile(const std::string& file_name);
    bool saveToFile();
    std::string getFileString();
};


#endif //PROJECTGAME_CHARACTER_H
