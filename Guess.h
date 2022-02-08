//
//  Guess.h
//
//  Created by Reta Hublic on 12/13/21.
//

#ifndef GUESS_H
#define GUESS_H

class Guess
{
    private:
        char letter;
        Guess* next;
        Guess* head;
        bool isShow;
        int sz;
    
    public:
        Guess() = default;
        Guess(char letter, Guess* next);
        void setLetter(char letter);
        void setNext(Guess* next);
        int getLetter();
        Guess* getNext();
        Guess(char letter, bool isShow, Guess* next);
        void setIsShow(bool isShow);
        bool getIsShow();
        void add(Guess* a);
        int getSize();
        Guess* getHead();
};

#endif
