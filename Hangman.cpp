//
//  Hangman.cpp
//  program4
//
//  Created by Fahreta Hublic on 12/13/21.
//

#include <iostream>
#include "Hangman.h"
#include "Guess.h"
using namespace std;

     Hangman::Hangman()
     {
        currentState = STARTUP;
        guesslist = Guess();
        hangmanlist = Guess();
     }

    void Hangman::startHangman()
    {
        string input;
        cout << "enter word for hangman:" << endl;
        cin >> input;

        system("CLS");

        for(int i = 0; i < input.size(); ++i)
        {
            if(!isalpha(input[i])) throw("error");
            Guess* guess = new Guess(input[i], false, nullptr);
            hangmanlist.add(guess);
            }
    }
        void Hangman::play()
        {
            do
            {
                if(currentState == HUNG)
                {
                    cout << endl;
                    cout << "you lose";
                    cout << endl;
                    break;
                }

                system("CLS");

                switch(currentState)
                {
                case STARTUP:
                    cout << "";
                    break;
                case PLATFORM:
                    cout << "Platform";
                    break;
                case HEAD:
                    cout << "Platform, Head";
                    break;
                case BODY:
                    cout << "Platform, Head, Body";
                    break;
                case LEFT_ARM:
                    cout << "Platform, Head, Body, Left arm";
                    break;
                case RIGHT_ARM:
                    cout << "Platform, Head, Body, Left arm, Right arm";
                    break;
                case LEFT_LEG:
                    cout << "Platform, Head, Body, Left arm, Right arm, Left leg";
                    break;
                case RIGHT_LEG:
                    cout << "Platform, Head, Body, Left arm, Right arm, Left leg, Right leg";
                    break;
                case HUNG:
                    break;
                }
                cout << endl;

                Guess* head = (Guess*)hangmanlist.getHead();

                while(head != nullptr)
                {
                    if(head->getIsShow())
                    {
                        cout << (char)head->getLetter() << " ";
                    }
                    else
                    {
                        cout << "- ";
                    }
                    head = (Guess*) head->getNext();
                }
                cout << endl;
                cout << "guess a letter (quit to exit program)" << endl;;

                string input2;
                cin >> input2;

                if (input2 == "quit")
                {
                    cout << "exiting program" << endl;
                    break;
                }
                else
                {
                    if (input2.size() > 1 || !isalpha(input2[0]))
                    {
                        cout << "try again" << endl;
                    }

                    else
                    {
                        char ch = toupper(input2[0]);
                        Guess* guessHead = guesslist.getHead();
                        bool exists = false;

                        while(guessHead != nullptr)
                        {
                            if(guessHead->getLetter( ) == ch)
                            {
                                exists = true;
                                break;
                            }
                            guessHead = guessHead->getNext();
                        }

                        if(!exists)
                        {
                            guesslist.add(new Guess(ch,nullptr));
                            Guess* head = (Guess*) hangmanlist.getHead();
                            int shownCount = 0;
                            int match = 0;

                            while(head != nullptr)
                            {
                                if(head->getLetter() == ch)
                                {
                                    ++match;
                                    head->setIsShow(true);
                                }

                                if(head->getIsShow())
                                {
                                    ++shownCount;
                                }
                                head = (Guess*) head->getNext();
                            }

                            if(match == 0)
                            {
                                currentState = State(currentState + 1);
                            }

                            if(shownCount == hangmanlist.getSize())
                            {
                                cout << endl;
                                cout << "yay you win :)" << endl;
                                break;
                            }
                        }
                    }
                }
            }while(true);
        }
