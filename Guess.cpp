//
//  Guess.cpp
//
//  Created by Reta Hublic on 12/13/21.
//

#include <iostream>
#include "Guess.h"
#include "Hangman.h"
using namespace std;


        Guess::Guess(char letter, Guess* next) : letter(letter), next(next)
        {
        }
        void Guess::setLetter(char letter)
        {
            this->letter = toupper(letter);
        }

        void Guess::setNext(Guess* next)
        {
            this->next = next;
        }

        int Guess::getLetter()
        {
            return this->letter;
        }

        Guess* Guess::getNext()
        {
            return this->next;
        }

        Guess::Guess(char letter, bool isShow, Guess* next)
        {
            setLetter(letter);
            setNext(next);
            this->isShow = isShow;
        }

        void Guess::setIsShow(bool isShow)
        {
            this->isShow = isShow;
        }

        bool Guess::getIsShow()
        {
            return this->isShow;
        }

        void Guess::add(Guess* a)
        {
            if(head == nullptr)
            {
                head = a;
                next = a;
            }
            else
            {
                next->setNext(a);
                next = a;
            }
            ++sz;
        }

        int Guess::getSize()
        {
            return this->sz;
        }

        Guess* Guess::getHead()
        {
            return this->head;
        }
