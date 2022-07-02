project(ProjectGame_lib)

set(HEADER_FILES
        Character.h
        Klass.h
        Stats.h
        Game.h
        Spell.h
        Map.h
        Room.h
        Item.h
        Load.h
        )

set(SOURCE_FILES
        Character.cpp
        Klass.cpp
        Stats.cpp
        Game.cpp
        Spell.cpp
        Map.cpp
        Room.cpp
        Item.cpp
        Load.cpp
        )

add_library(ProjectGame_lib STATIC ${SOURCE_FILES} ${HEADER_FILES})