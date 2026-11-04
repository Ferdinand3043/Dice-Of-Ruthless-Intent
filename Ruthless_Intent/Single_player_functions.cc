#include <iostream>
#include <cstdlib>
#include <limits>
#include "Prototypes.h"
#include "Bot_functions.cc"
using std::cout;
using std::endl;
using std::getline;


void greeting(){
    
    cout << "\n\n-------------------------------";
    cout << "\n|" << " * Dice Of Ruthless Intent * " << "|" << "\n-------------------------------" << endl; 
    cout << "\nPress ENTER to continue..";
    getchar();
}


void defaultmenu(){


    cout << "\n\n\tMain Menu:\n";

    const char *decisions[10] = {"\n\t1. Single Player Match", "\t2. Player vs Bot Match", "\t3. How To Play", "\t4. Quit"};

    for(int i = 0; i < 4; i++){
        cout << decisions[i] << endl;
    }

    cout << ("\n\nChoose between 1 & 4 for decision: ");

    while(!(cin >> answer) || answer > 4 || answer < 1){
        cout << "\nEnter valid input between 1 & 3: ";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }


    switch(answer){

        case 1:
            setup();
            break;

        case 2:
            bots();
            break;
        
        case 3:
            how_to();
            break;

        case 4:
            cout << "\nSee you later!" << endl;
            exit(1);
    };

}


void setup(){


    cout << "\n\nEnter a username: ";
    std::getline(std::cin >> std::ws, username);

    cout << "\n\nHow many dice would you like to play with " << username << "?" << endl
    << "\n\t(Four dice limit! More dice increases probability to win more cash!): ";

    while(!(cin >> choice) || choice == 0 || choice < 0 || choice > 4){
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

    switch(choice){

        case 1:
            single_roll();
            break;

        case 2:
            double_roll();
            break;
        
        case 3:
            triple_roll();
            break;

        case 4:
            quad_roll();
            break;
    };

}



void how_to(){

    cout << "\n\n\t*In Dice Of Ruthless Intent, the player can choose between 1 - 4 dice." << endl 
    << "\tThe more dice used will increase the probability of more cash earned and getting achievements. " << endl 
    << " \tAt any point during gameplay the player can enter 0 to quit a match. *\n" << endl;

    defaultmenu();
}



void single_roll(){

    cout << "\n\nHow much would you like to gamble " << username << "? ";

    while(!(cin >> jackpot) || jackpot == 0 || jackpot < 0){
        cout << "\n\n\tJackpot rules: \n" << endl
            << "1. No Negative numbers." << endl
            << "2. An initial balance of 0 is not allowed." << endl
            << "3. No character input." << endl
            << "\n\nHow much would you like to gamble " << username << "? ";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }


    cout << "\n\n\t\t\t* At any point during gameplay press '0' to quit *";

    cout << "\n\n\nStarting balance: $" << jackpot << endl;

    do{
    
        cout << "\n\n\nProvide a number from 1 - 6 for roll: ";

        while(!(cin >> a) || a > 6 || a < 0){
        cout << "\nNumbers between 1 & 6 only. Re-enter roll number: ";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }

        if(a == 0){
            cout << "\n\nAre you sure you would like to quit " << username << "?" << endl
            << "\t(Enter 0 to quit OR 1 to continue gameplay): ";
            
            while(!(cin >> a) || a < 0 || a > 1){
                cout << "\nNot valid input. Enter 0 to quit OR 1 to continue gameplay: ";
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
            }

            if(a == 0){
                cout << "\n\nThank you for playing " << username << "!" << endl;
                exit(1);
            }
            else{
            continue;
            }   
        
        }

        dice = (rand() % 6) + 1;

        if(a == dice){
            jackpot += 50;
        }else{
            jackpot -= 25;
        }

        cout << "\n\nDice Roll: " << dice << endl;
        const int rolled_dice[] = {dice};
        display_dice_images(rolled_dice, 1);
        
        cout << "Balance: $" << jackpot;

        if(jackpot == 0 || jackpot < 0){
            cout << "\n\nYou ran out of money! Would you like to play again " << username << "? " << endl
            << "(press 1 to restart OR press 0 to quit): ";
            cin >> restart;

            switch(restart){

                case 0:
                    cout << "\nThank you for playing " << username << "!" << endl;
                    exit(1);
            
                case 1:
                    setup();
                    single_roll();
            }
        
        }
    } while(a != 0);
}


void double_roll(){


    cout << "\n\nHow much would you like to gamble " << username << "? ";

    while(!(cin >> jackpot) || jackpot == 0 || jackpot < 0){
        cout << "\n\n\tJackpot rules: \n" << endl
            << "1. No Negative numbers." << endl
            << "2. An initial balance of 0 is not allowed." << endl
            << "3. No character input." << endl
            << "\n\nHow much would you like to gamble " << username << "? ";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    
    cout << "\n\n\n\t\t\t* At any point during gameplay press '0' to quit *";

    cout << "\nStarting balance: $" << jackpot << endl;

    do{

        cout << "\n\nProvide two numbers from 1 - 6 for roll: ";


        while (true) {
            if (!(cin >> a) || a > 6 || a < 0) {
                cout << "\nNumbers between 1 & 6 only. Re-enter all roll numbers: ";
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                continue;
            }

            if (a == 0 || (cin >> b && b >= 1 && b <= 6)) {
                break;
            }

            cout << "\nNumbers between 1 & 6 only. Re-enter all roll numbers: ";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }

        if(a == 0){
            cout << "\n\nAre you sure you would like to quit " << username << "?" << endl
            << "\tEnter 0 to quit OR 1 to continue gameplay: ";
            
            while(!(cin >> a) || a < 0 || a > 1){
                cout << "\nNot valid input. Enter 0 to quit OR 1 to continue gameplay: ";
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
            }

            if(a == 0){
                cout << "\nThank you for playing " << username << "!" << endl;
                exit(1);
            }
            else{
            continue;
            }   
        }

        dice = (rand() % 6) + 1;
        dice_2 = (rand() % 6) + 1;

        const int matches = (a == dice) + (b == dice_2);
        if(matches > 0){
            jackpot += 25 * matches;
        }else{
            jackpot -= 25;
        }

        cout << "\n\nDice Roll: " << dice << " & " << dice_2 << endl;
        const int rolled_dice[] = {dice, dice_2};
        display_dice_images(rolled_dice, 2);

        cout << "Balance: $" << jackpot << endl;

        if(jackpot == 0 || jackpot < 0){
            cout << "\n\nYou ran out of money! Would you like to play again " << username << "? " << endl
            << "(press 1 to restart OR press 0 to quit): ";
            cin >> restart;

            switch(restart){

                case 0:
                    cout << "\nThank you for playing " << username << "!" << endl;
                    exit(1);
            
                case 1:
                    setup();
                    double_roll();
            }
        
        };
    
    } while(a != 0);
    
}


void triple_roll(){


    cout << "\n\nHow much would you like to gamble " << username << "? ";

    while(!(cin >> jackpot) || jackpot == 0 || jackpot < 0){
        cout << "\n\n\tJackpot rules: \n" << endl
            << "1. No Negative numbers." << endl
            << "2. An initial balance of 0 is not allowed." << endl
            << "3. No character input." << endl
            << "\n\nHow much would you like to gamble " << username << "? ";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    
    cout << "\n\n\n\t\t\t* At any point during gameplay press '0' to quit *";

    cout << "\nStarting balance: $" << jackpot << endl;

    do{

        cout << "\n\nProvide three numbers from 1 - 6 for roll: ";


        while (true) {
            if (!(cin >> a) || a > 6 || a < 0) {
                cout << "\nNumbers between 1 & 6 only. Re-enter all roll numbers: ";
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                continue;
            }

            if (a == 0 || (cin >> b >> c && b >= 1 && b <= 6 && c >= 1 && c <= 6)) {
                break;
            }

            cout << "\nNumbers between 1 & 6 only. Re-enter all roll numbers: ";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }

        if(a == 0){
            cout << "\n\nAre you sure you would like to quit " << username << "?" << endl
            << "Enter 0 to quit OR 1 to continue gameplay: ";
            
            while(!(cin >> a) || a < 0 || a > 1){
                cout << "\nNot valid input. Enter 0 to quit OR 1 to continue gameplay: ";
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
            }

            if(a == 0){
                cout << "\nThank you for playing " << username << "!" << endl;
                exit(1);
            }
            else{
            continue;
            }   
        }

        dice = (rand() % 6) + 1;
        dice_2 = (rand() % 6) + 1;
        dice_3 = (rand() % 6) + 1;


        const int matches = (a == dice) + (b == dice_2) + (c == dice_3);
        if(matches > 0){
            jackpot += 25 * matches;
        }else{
            jackpot -= 25;
        }
        


        cout << "\n\nDice Roll: " << dice << " & " << dice_2 << " & " << dice_3 << endl;
        cout << "\n\nDice Roll: " << dice << " & " << dice_2 << " & " << dice_3 << endl;
        const int rolled_dice[] = {dice, dice_2, dice_3};
        display_dice_images(rolled_dice, 3);

        cout << "Balance: $" << jackpot << endl;

        if(jackpot == 0 || jackpot < 0){
            cout << "\n\nYou ran out of money! Would you like to play again " << username << "? " << endl
            << "(press 1 to restart OR press 0 to quit): ";
            cin >> restart;

            switch(restart){

                case 0:
                    cout << "\nThank you for playing " << username << "!" << endl;
                    exit(1);
            
                case 1:
                    setup();
                    triple_roll();
            }
        
        };
    
    } while( a != 0);
    
}


void quad_roll(){

    cout << "\n\nHow much would you like to gamble " << username << "? ";

    while(!(cin >> jackpot) || jackpot == 0 || jackpot < 0){
        cout << "\n\n\tJackpot rules: \n" << endl
            << "1. No Negative numbers." << endl
            << "2. An initial balance of 0 is not allowed." << endl
            << "3. No character input." << endl
            << "\n\nHow much would you like to gamble " << username << "? ";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    
    cout << "\n\n\n\t\t\t* At any point during gameplay press '0' to quit *";

    cout << "\nStarting balance: $" << jackpot << endl;

    do{

        cout << "\n\nProvide four numbers from 1 - 6 for roll: ";


        while (true) {
            if (!(cin >> a) || a > 6 || a < 0) {
                cout << "\nNumbers between 1 & 6 only. Re-enter all roll numbers: ";
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                continue;
            }

            if (a == 0 || (cin >> b >> c >> d &&
                           b >= 1 && b <= 6 && c >= 1 && c <= 6 && d >= 1 && d <= 6)) {
                break;
            }

            cout << "\nNumbers between 1 & 6 only. Re-enter all roll numbers: ";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }

        if(a == 0){
            cout << "\n\nAre you sure you would like to quit " << username << "?" << endl
            << "Enter 0 to quit OR 1 to continue gameplay: ";
            
            while(!(cin >> a) || a < 0 || a > 1){
                cout << "\nNot valid input. Enter 0 to quit OR 1 to continue gameplay: ";
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
            }

            if(a == 0){
                cout << "\nThank you for playing " << username << "!" << endl;
                exit(1);
            }
            else{
            continue;
            }   
        }

        dice = (rand() % 6) + 1;
        dice_2 = (rand() % 6) + 1;
        dice_3 = (rand() % 6) + 1;
        dice_4 = (rand() % 6) + 1;

        const int matches = (a == dice) + (b == dice_2) + (c == dice_3) + (d == dice_4);
        if(matches > 0){
            jackpot += 25 * matches;
        }else{
            jackpot -= 25;
        }

        cout << "\n\nDice Roll: " << dice << " & " << dice_2 << " & " << dice_3 << " & " <<  dice_4 << endl;
        const int rolled_dice[] = {dice, dice_2, dice_3, dice_4};
        display_dice_images(rolled_dice, 4);

        cout << "Balance: $" << jackpot << endl;

        if(jackpot == 0 || jackpot < 0){
            cout << "\n\nYou ran out of money! Would you like to play again " << username << "? " << endl
            << "(press 1 to restart OR press 0 to quit): ";
            cin >> restart;

            switch(restart){

                case 0:
                    cout << "\nThank you for playing " << username << "!" << endl;
                    exit(1);
            
                case 1:
                    setup();
                    quad_roll();
            }
        
        };
    
    } while( a != 0);
    
};
