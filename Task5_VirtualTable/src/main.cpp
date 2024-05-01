#include <iostream>
#include "../header/musician2.hpp"

int main() {
    // Musician musician;
    // musician.vptr->play = &Musician::play; // Присваиваем адрес метода play
    // (musician.*musician.vptr->play)(); 
    // return 0;

	
    Musician musician;
    String str;
    Brass br;
    // musvtbl.fplay = &Musician::play;
    void (Musician::* fplay)() = &Musician::play;
    (musician.*fplay)();
    (str.*fplay)();
    (br.*fplay)();
    // (musician.*musician.vptr->fplay)(); // Вызов метода play через указатель
    strvtbl.fplay = &String::play;
    // (str.*musician.vptr->fplay)(); 
    (br.*fplay)();
}

