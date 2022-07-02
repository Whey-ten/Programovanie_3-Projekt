#ifndef PROJECTGAME_STATS_H
#define PROJECTGAME_STATS_H

/**
 * Header file of class Stats.
 * Stats class includes stats of character.
 */

class Stats {
    int max_hp;
    int current_hp;
    int max_mana;
    int current_mana;
    //
    int power;
    int defense;
    int magic;

public:
    //getters
    int getMaxHP() const{return max_hp;};
    int getCurrentHP() const{return current_hp;};
    int getMaxMana() const{return max_mana;};
    int getCurrentMana() const{return current_mana;};
    int getPower() const{return power;};
    int getDefense() const{return defense;};
    int getMagic() const{return magic;};
    //setters
    void setMaxHP(int value){max_hp = value;};
    void setCurrentHP(int value){current_hp = value;};
    void setMaxMana(int value){max_mana = value;};
    void setCurrentMana(int value){current_mana = value;};
    void setPower(int value){power = value;};
    void setDefense(int value){defense = value;};
    void setMagic(int value){magic = value;};

};


#endif //PROJECTGAME_STATS_H
