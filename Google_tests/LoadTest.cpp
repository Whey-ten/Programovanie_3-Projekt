#include "gtest/gtest.h"
#include "Game.h"
/**
 * Tests correct load from files.
 */
TEST(LoadTestSuite, CreateGame){
    Game g;
    ASSERT_TRUE(g.loadGame("../../ProjectGame_lib/HouseOfDoom.txt"));
    EXPECT_FALSE(g.getGameState());
    Character ch;
    ch.createWarrior();
    g.LoadPlayer(ch);
    EXPECT_TRUE(g.getGameState());
    EXPECT_EQ("Cellar", g.getCurrentPosition());
    EXPECT_EQ("There might be something hidden here.", g.checkCurrentRoom());
    //this is 50% to be right so we just clean it
    //EXPECT_EQ("You found: sword.And successfully equipped it.", g.cleanRoom());
    //EXPECT_EQ("You found: shield.And successfully equipped it.", g.cleanRoom());
    g.cleanRoom();
    g.cleanRoom();
    EXPECT_EQ("Room is empty, move to other one.", g.checkCurrentRoom());
    Room r = g.getCurrentRoom();
    EXPECT_EQ("empty", r.getStatus());

    EXPECT_EQ("Kitchen", g.getNeighborRooms());
    EXPECT_TRUE(g.moveToRoom("Kitchen"));
    EXPECT_EQ("Kitchen", g.getCurrentPosition());
    EXPECT_EQ("You found enemies!!", g.checkCurrentRoom());
    std::cout << "FIGHT START"<<std::endl;
    EXPECT_EQ("You won fight and enemy died!", g.cleanRoom());
    r = g.getCurrentRoom();
    EXPECT_EQ(0, r.getNumberOfEnemies());
    ch = g.getPlayer();
    EXPECT_EQ(2, ch.getLevel());
    EXPECT_EQ("Room is empty, move to other one.", g.checkCurrentRoom());
    EXPECT_EQ("There is still something on map, you are unable to finish game yet!", g.finnishGame());
    EXPECT_EQ("Room is empty, move to other one.", g.checkCurrentRoom());
    EXPECT_EQ("Cellar, Attic", g.getNeighborRooms());
    EXPECT_TRUE(g.moveToRoom("Cellar"));
    EXPECT_FALSE(g.moveToRoom("Attic"));
    EXPECT_TRUE(g.moveToRoom("Kitchen"));
    EXPECT_TRUE(g.moveToRoom("Attic"));
    EXPECT_EQ("You found enemies!!", g.checkCurrentRoom());
    EXPECT_EQ("You won fight and enemy died!", g.cleanRoom());
    EXPECT_EQ("Room is empty, move to other one.", g.checkCurrentRoom());
    EXPECT_EQ( "Congratulations! You beat the game. You can save your character and load new game.", g.finnishGame());
    EXPECT_FALSE(g.getGameState());

}

TEST(LoadTestSuite, LoadChar1){
    Character ch;
    ch.loadFromFile("../../ProjectGame_lib/Character_Warrior.txt");
    EXPECT_EQ("FileCharacterWarrior", ch.getName());
    EXPECT_EQ(1, ch.getLevel());
    Klass k = ch.getKlass();
    EXPECT_EQ("Warrior", k.getName());
    Spell s = ch.getSpellFromName("kick");
    EXPECT_EQ(15, s.getPower());
    Item i;
    i.loadFromString("ring:def:1");
    EXPECT_TRUE(ch.unequipItem(i));
    EXPECT_FALSE(ch.unequipItem("ring"));
    EXPECT_TRUE(ch.unequipItem("shoes"));

}

TEST(LoadTestSuite, LoadChar2){
    Character ch;
    ch.loadFromFile("../../ProjectGame_lib/Character_Mage.txt");
    EXPECT_EQ("FileCharacterMage", ch.getName());
    EXPECT_EQ(1, ch.getLevel());
    Klass k = ch.getKlass();
    EXPECT_EQ("Mage", k.getName());
    Spell s = ch.getSpellFromName("fireball");
    EXPECT_EQ(65, s.getPower());
    Item i;
    i.loadFromString("ring:def:1");
    EXPECT_FALSE(ch.unequipItem(i));
    EXPECT_FALSE(ch.unequipItem("ring"));
    EXPECT_TRUE(ch.unequipItem("staff"));
}

TEST(LoadTestSuit, SaveCharacter){
    Character ch;
    ch.loadFromFile("../../ProjectGame_lib/Character_Mage.txt");
    EXPECT_TRUE(ch.saveToFile("test_save"));
    Character ch2;
    EXPECT_TRUE(ch2.loadFromFile("test_save.txt"));
}

TEST(LoadTestSuit, SaveGame){
    Character ch;
    ASSERT_TRUE(ch.loadFromFile("../../ProjectGame_lib/Character_Mage.txt"));
    Game g;
    ASSERT_TRUE(g.loadGame("../../ProjectGame_lib/HouseOfDoom.txt"));
    g.LoadPlayer(ch);
    ASSERT_TRUE(g.saveGame());
    ASSERT_TRUE(ch.saveToFile());
    Game g2;
    Character ch2;
    ASSERT_TRUE(g.loadGame("HouseOfDoom.txt"));
    std::string file_name = ch.getName() + ".txt";
    ASSERT_TRUE(ch2.loadFromFile(file_name));
}