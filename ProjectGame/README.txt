Vypracoval: Sebastian Jankovic
Tema: Jednoducha hra
Projekt Schvalil: Gyarfas Frantisek

Info:
Projekt bol povodne mysleny aj povoleny ako hra, ktora bude cela prebiehat v konzole. Pri prvej vezrii projektu mi bolo povedane, ze to tak nie je mozne tak mat, preto je hra prerobena.
Z dovodu, ze hra bola povodne myslena ako "konzolova", niektore jej funkcie maju divnu simulaciu ale nevedel som si to inak predstavit bez kompletnej zmeny projektu.
Projekt momentalne dokaze:
-Vytvorit charakter, dat mu classu(jeho specifiakciu Bojovnik/Mag..) a podla nej mu priradit jeho schopnosti, ktore sa s zvysujucim levelom budu umerne zvysovat.
-Dovolit charakteru sa nauzit kuzla, ktore moze neskor vyuzivat a ich obmedzenie aby nemohli byt pouzivane stale.
-Dat charakteru predmet, ktory mu zvysi jeho momentalne vlastnosti a taktiez ho odobrat a charakter tieto vlastnosti strati
-Vytvorit mapu obsahujucu miestnosti
-Vytvorit miestonosti, ktore mozu obsahovat nepriatelov alebo skryte predmety
-Vytvorit hru, ktora bude obsahovat mapu na ktorej sa bude hrat a taktiez postavu/charakter, ktora na nej bude hrat. Hracovou ulohou je vycistit vsetky miestnosti mapy ci uz od nepriatelov alebo najst skyte predmety.
-Projekt je simuluje suboj dvoch nepriatelov a hladanie predmetu v miestnosti
-Hru a Postavu je mozne si ulozit do textoveho suboru a taktiez nacitat ich z textovych suborov.

Projekt obsahuje:
Character.h/Character.cpp   - Class Character
Klass.h/Klass.cpp           - Class Klass(class characteru)
Spell.h/Spell.cpp           - Class Spell
Item.h/Item.cpp             - Class Item
Stats.h/Stats.cpp           - Class Stats
Room.h/Room.cpp             - Class Room
Map.h/Map.cpp               - Class Map
Game.h/Game.cpp             - Class Game
Load.h/Load.cpp
HouseOfDoom.txt             - txt subor s mapou
Character_Mage.txt          - txt subor obsahujuci Charakteru s klasou/triedou maga
Character_Warrior.txt       - txt subor obsahujuci Characteru s klasou/triedou bojovnika

Testy:
CharacterTest.cpp           - testy na funkcnost Character,Klass,Item,Spell,Stats a ich zakladnych funkcii
MapTest.cpp                 - testy na funkcnost Map a Room a ich zakladnych funkcii
GameTest.cpp                - testy, v ktorych je simulovana jednoducha hra uz z predvytvorenej hry,mapy a charakteru
LoadTest.cpp                - testy na kontrolu spravnej funkcnosti nacitavania zo suboru a ukladanie do suboru + simulacia hry z nacitaneho suboru

Pripomienky z malej verzie:
- dbat na konstantnost
- dbat na to kedy beriem hodnotu a kedy referenciu
- parametre character(vlastnosti) dat do samostatnej triedy - spravene
- vyhnut sa magickym konstantam - spravene
- pouzit anglictinu a deskriptivne nazvy - spravene

Legendy:
[map file]
    <name_of_map>
    <# of rooms>
    <room_1>
    ...
    <room_n>
    <# of ways of travel>
    <way_1>
    ...
    <way_n>

[character file]
    <name_of_character>
    <level>
    <experience>
    <klass>
    <# of spells>
    <spell_1>
    ...
    <spell_n>
    <# of items>
    <item_1>
    ...
    <item_n>

[room string]
    <name_of_room> , <state_of_room> , <enemies> , <items>
[enemies string]
    <# of enemies> @ <enemy_1> @ ... @ <enemy_n>
[items string]
    <# of items> @ <item_1> @ ... @ <item_n>
[character string]
    <name_of_character> ; <level> ; <experience> ; <klass> ; <spells> ; <items>
[klass string]
    <name_of_class> : <exp_val> : <hp_val> : <mana_val> : <power_val> : <defense_val> : <magic_val>
[spell string]
    <name_of_spell> : <power> : <mana_cost> : <type>
[item string]
    <name_of_item> : <type> : <value>
