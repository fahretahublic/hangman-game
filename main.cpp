//
//  main.cpp
//  program4
//
//  Created by Fahreta Hublic on 12/13/21.
//

#include <iostream>

#include "Guess.h"
#include "Hangman.h"
namespace std;

int main()
{
    while(true)
    {
        try
        {
            Hangman g = Hangman();
            g.startHangman();
            g.play();
            break;
        }

        catch(const char* a)
        {
            cout << "invalid" << endl;
            continue;
        }
    }
}
