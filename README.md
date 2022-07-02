# Hra
Mandatory project from subject Programming 3 which was graded A. Assignment is in Slovak language.

## Zadanie
Semestrálny projekt spočíva v navrhnutí, naprogramovaní a prezentovaní programu v C++ v rozsahu o niečo viac ako jedného cvičenia. 
 
Téma a približný obsah musia byť schválené vedením predmetu.
 
Projekt musí byť rozdelený do štyroch až piatich na seba nadväzujúcich úloh (ako v cvičeniach) a musí obsahovať sadu funkčných testov.
 
Vypracovaný semestrálny projekt bude obsahovať:  
• stručný popis projektu a jeho vlastností  
• vypracované (a funkčné) riešenie v jazyku C++  
• sadu testov dokazujúcich funkčnosť a správnosť riešenia  
 
Odovzdaný semestrálny projekt bude obsahovať:      
• riešenie v *.cpp a *.h súboroch (stačí odovzdať zdrojáky)  
• sadu testov pre Google Tests, ktoré verujú správnosť celého riešenia   
 
Všetky súbory vložíte do jedného zip súboru a odovzdajte na stránke.

## Riešenie  
Projekt bol povodne mysleny aj povoleny ako hra, ktora bude cela prebiehat v konzole. Pri prvej vezrii projektu mi bolo povedane, ze to tak nie je mozne tak mat, preto je hra prerobena.  
Z dovodu, ze hra bola povodne myslena ako "konzolova", niektore jej funkcie maju divnu simulaciu ale nevedel som si to inak predstavit bez kompletnej zmeny projektu.
Projekt momentalne dokaze:  
- Vytvorit charakter, dat mu classu(jeho specifiakciu Bojovnik/Mag..) a podla nej mu priradit jeho schopnosti, ktore sa s zvysujucim levelom budu umerne zvysovat.  
- Dovolit charakteru sa nauzit kuzla, ktore moze neskor vyuzivat a ich obmedzenie aby nemohli byt pouzivane stale.  
- Dat charakteru predmet, ktory mu zvysi jeho momentalne vlastnosti a taktiez ho odobrat a charakter tieto vlastnosti strati.  
- Vytvorit mapu obsahujucu miestnosti.  
- Vytvorit miestonosti, ktore mozu obsahovat nepriatelov alebo skryte predmety.  
- Vytvorit hru, ktora bude obsahovat mapu na ktorej sa bude hrat a taktiez postavu/charakter, ktora na nej bude hrat. Hracovou ulohou je vycistit vsetky miestnosti mapy ci uz od nepriatelov alebo najst skyte predmety.  
- Projekt je simuluje suboj dvoch nepriatelov a hladanie predmetu v miestnosti.  
- Hru a Postavu je mozne si ulozit do textoveho suboru a taktiez nacitat ich z textovych suborov.  

**Projekt obsahuje:**  
1. Character.h/Character.cpp   - Class Character
2. Klass.h/Klass.cpp           - Class Klass(class characteru)
3. Spell.h/Spell.cpp           - Class Spell
4. Item.h/Item.cpp             - Class Item
5. Stats.h/Stats.cpp           - Class Stats
6. Room.h/Room.cpp             - Class Room
7. Map.h/Map.cpp               - Class Map
8. Game.h/Game.cpp             - Class Game
9. Load.h/Load.cpp
10. HouseOfDoom.txt             - txt subor s mapou
11. Character_Mage.txt          - txt subor obsahujuci Charakteru s klasou/triedou maga
12. Character_Warrior.txt       - txt subor obsahujuci Characteru s klasou/triedou bojovnika

**Testy:**  
1. CharacterTest.cpp           - testy na funkcnost Character,Klass,Item,Spell,Stats a ich zakladnych funkcii
2. MapTest.cpp                 - testy na funkcnost Map a Room a ich zakladnych funkcii
3. GameTest.cpp                - testy, v ktorych je simulovana jednoducha hra uz z predvytvorenej hry,mapy a charakteru
4. LoadTest.cpp                - testy na kontrolu spravnej funkcnosti nacitavania zo suboru a ukladanie do suboru + simulacia hry z nacitaneho suboru

