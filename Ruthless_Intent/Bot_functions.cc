#include <iostream>
#include <limits>
#include "Prototypes.h"
#include "Mystic.cc"
using std::cout;
using std::endl;



void bots(){

    cout << "\n\nEnter a username: ";
    std::getline(std::cin >> std::ws, username);


    cout << "\n\n\tOpponents List:\n";

    const char *bots[10] = {"\n1. Mystic", "\n2. Maze", "\n3. Stitch", "\n4. Blitz", "\n5. Noval"}; 

    for(int i = 0; i < 5; i++){
        cout << bots[i] << endl;
    }

    cout << ("\n\nWho would you like to gamble against ") << username << "?" << endl
    << ("(Enter 1 to 5 for decision): ");


    while(!(cin >> answer_2) || answer_2 > 1 || answer_2 < 1){
        cout << "\n\nMystic is the only active bot: ";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
    
    
    switch(answer_2){

        case 1:
            mystic();
            break;

        case 2: maze();
            break;

        case 3: stitch();
            break;
        
        case 4: blitz();
            break;
        
        case 5: noval();
            break;

    }
}




void mystic(){

    mystic_intro_prompts();
    cout << "\n\n\n(Mystic): I hope your ready to lose all your cash " << username << "!";

    cout << "\n\n\n\n(Mystic): How much are you willing to wager " << username << "? ";

    while(!(cin >> jackpot) || jackpot == 0 || jackpot < 0){
        cout << "\n\n\tJackpot rules: \n" << endl
            << "1. No Negative numbers." << endl
            << "2. An initial balance of 0 is not allowed." << endl
            << "3. No character input." << endl
            << "\n\n(Mystic): That is not a valid wager " << username << "......how much would you like to gamble? ";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }


    cout << "\n\n\n(Mystic): How many dice would you like to play with " << username << "?" << endl
    << "\n\t(Four dice limit! More dice increases probability to win more cash!): ";

    while(!(cin >> choice_2) || choice_2 == 0 || choice_2 < 0 || choice_2 > 4){
        cout << "\n\n\tDice rules: \n" << endl
            << "1. No Negative numbers." << endl
            << "2. It is not possible to play with 0 dice." << endl
            << "3. Only 4 dice are allowed." << endl
            << "4. No character input." << endl
            << "\n\nHow many dice would you like to play with " << username << "?" << endl
            << "\n\t(More dice increases probability to win!): ";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    mystic_intro_prompts();
    cout << "\n\n\n(Mystic): Good luck " << username << "   " << "....you will need it..!";



    switch(choice_2){

        case 1:
            mystic_single_roll();
            break;
        
        case 2:
            mystic_dual_roll();
            break;
        
        case 3:
            mystic_triple_roll();
            break;

        case 4:
            mystic_quad_roll();
    }

}

void maze(){}


void stitch(){}


void blitz(){}


void noval(){}

