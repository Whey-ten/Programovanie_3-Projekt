#include "gtest/gtest.h"
#include "Character.h"
/**
 * Tests for creation of Character, his class, stats and spells
 * Tests simple funcions used in Character,Klass and spells
 */
TEST(CharacterTestSuite, CreateCharacter){
    Character ch;
    EXPECT_EQ("", ch.getName());
}

TEST(CharacterTestSuite, SetCharacterName){
    Character ch;
    std::string name = "Super";
    ch.setName(name);
    EXPECT_EQ("Super", ch.getName());
}

TEST(CharacterTestSuite, CreatePreSetKlass){
    Klass k;
    k.createKlass();
    EXPECT_EQ("PreSetWarrior", k.getName());
}

TEST(CharacterTestSuite, CreatePreSetSecondKlass){
    Klass k;
    k.createKlassTwo();
    EXPECT_EQ("PreSetMage", k.getName());
}

TEST(CharacterTestSuite, CheckStatsLoaded){
    Character ch;
    Klass k;
    k.createKlass();
    ch.setKlass(k);
    EXPECT_EQ(100, k.getExp(1));
    EXPECT_EQ(140, k.getHp(2));
    ch.setName("Erik");
    EXPECT_EQ(1, ch.getLevel());
    ch.addExp(105);
    EXPECT_EQ(2, ch.getLevel());
    EXPECT_EQ(5, ch.getExp());
    EXPECT_EQ(140, ch.getHP());
}

TEST(CharacterTestSuite, CheckSpellsLoaded){
    Character ch;
    ch.createWarrior();
    Spell s1,s2;
    s1.createOne();
    s2.createTwo();
    EXPECT_FALSE(ch.learnSpell(s1));
    EXPECT_TRUE(ch.learnSpell(s2));
}

TEST(CharacterTestSuite, EquipAndUnequipOfItem){
    Character ch;
    ch.createMage();
    Item i1,i2;
    i1.createItemOne();
    i2.createItemTwo();
    std::string i_name = i2.getName();
    EXPECT_EQ(7, ch.getPower());
    ch.equipItem(i1);
    EXPECT_EQ(17, ch.getPower());
    EXPECT_EQ(5, ch.getDefense());
    ch.equipItem(i2);
    EXPECT_EQ(10,ch.getDefense());
    ch.unequipItem(i1);
    EXPECT_EQ(7, ch.getPower());
    ch.unequipItem(i_name);
    EXPECT_EQ(5, ch.getDefense());
}

TEST(CharacterTestSuite, CastSpell){
    Character ch;
    ch.createMage();
    EXPECT_EQ(25, ch.castRandomSpell());
    EXPECT_EQ(0, ch.castRandomSpell());
    EXPECT_EQ(0, ch.castRandomSpell());
    EXPECT_EQ(0, ch.castRandomSpell());
    EXPECT_EQ(25, ch.castRandomSpell());
}

TEST(CharacterTestSuite, CreateCharacter2){
    Character ch;
    ch.createWarrior();
    ch.printStatus();
    EXPECT_EQ("PremadeWarrior", ch.getName());
}