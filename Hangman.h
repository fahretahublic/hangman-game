//
//  Hangman.h
//  program4
//
//  Created by Fahreta Hublic on 12/13/21.
//

#ifndef HANGMAN_H
#define HANGMAN_H
#include "Guess.h"
#include <string>
#include <iostream>

class Hangman
{
private:
    enum State
    {
        STARTUP, PLATFORM, HEAD, BODY, LEFT_ARM, RIGHT_ARM, LEFT_LEG, RIGHT_LEG, HUNG
    };

    State currentState;
    Guess hangmanlist;
    Guess guesslist;

public:
    Hangman();
    void startHangman();
    void play();

};

#endif
