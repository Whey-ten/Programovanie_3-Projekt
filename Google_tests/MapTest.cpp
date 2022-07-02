#include "gtest/gtest.h"
#include "Map.h"
/**
 * Tests map creation, rooms and functions there
 */

TEST(MapTestSuite, CreateMap){
    Map m;
    EXPECT_EQ("", m.getName());
}

TEST(MapTestSuite, CreateRoom){
    Room r;
    EXPECT_EQ("", r.getName());
}

TEST(MapTestSuite, PremadeRooms){
    Room r1, r2, r3;
    r1.createRoomOne();
    EXPECT_EQ("Entry", r1.getName());
    EXPECT_EQ("hidden", r1.getStatus());
    EXPECT_EQ(0, r1.getNumberOfEnemies());
    EXPECT_EQ("", r1.getNamesOfEnemies());
    r2.createRoomTwo();
    EXPECT_EQ("room1", r2.getName());
    EXPECT_EQ("full", r2.getStatus());
    EXPECT_EQ(2, r2.getNumberOfEnemies());
    EXPECT_EQ("GoonONE & GoonTWO", r2.getNamesOfEnemies());
    r3.createRoomTree();
    EXPECT_EQ("BossRoom", r3.getName());
    EXPECT_EQ("full", r3.getStatus());
    EXPECT_EQ(1, r3.getNumberOfEnemies());
    EXPECT_EQ("BigBOSS", r3.getNamesOfEnemies());

}

TEST(MapTestSuite, PremadeMap){
    Map m;
    m.createMap();
    EXPECT_EQ("AutoCreatedMap1", m.getName());
    EXPECT_TRUE(m.isNeighbor("Entry", "room1"));
    EXPECT_TRUE(m.isNeighbor("room1", "Entry"));
    EXPECT_FALSE(m.isNeighbor("Entry", "BossRoom"));
    Room r1 = m.getEntryRoom();
    Room r2 = m.getRoom("Entry");
    EXPECT_TRUE(r1 == r2);
    Item i1, i2;
    i1 = r1.findItem();
    i2.createItemOne();
    EXPECT_TRUE(i1 == i2);

}