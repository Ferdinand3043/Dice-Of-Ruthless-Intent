#include <iostream>
#include <limits>
#include <cstdlib>
#include <ctime>
#include "Prototypes.h"
#include "Dice_images.cc"
using std::cout;



void mystic_single_roll(){
    
    
    cout << "\n\n\n\n" << username <<  "'s" << " starting balance: $" << jackpot << endl;

    mystic_jackpot = jackpot;

    cout << "Mystic's starting balance: $" << mystic_jackpot << "\n\n\n" << endl; 


    do{
    
        mystic_dice1 = (rand() % 6) + 1;

        cout << "\n\n\nMystic rolls.... : " << mystic_dice1 << 
        "\t\t\t" << username << "'s roll: ";

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


        if(mystic_dice1 == dice){
            mystic_jackpot += 50;
        }else{
            mystic_jackpot -=25;
        }


        cout << "\n\n\n\t\t\tDice Roll: " << dice << "\n" << endl;
        display_dice_image(dice);

        cout << "\nMystic's Balance: $" << mystic_jackpot
        << "\t\t\t" << username <<  "'s" << " Balance: $" << jackpot << "\n"
        <<"\n-------------------------------------------------------------------";
    

        if (jackpot <= 0 || mystic_jackpot <= 0) {
            mystic_game_over_single_roll();
            return;
        }
    } while(a != 0);

}


void mystic_dual_roll(){


    cout << "\n\n\n\n" << username <<  "'s" << " starting balance: $" << jackpot << endl;

    mystic_jackpot = jackpot;

    cout << "Mystic's starting balance: $" << mystic_jackpot << "\n\n\n" << endl; 


    do{
    
        mystic_dice1 = (rand() % 6) + 1;
        mystic_dice2 = (rand() % 6) + 1;
        
        cout << "\n\n\nMystic rolls.... : " << mystic_dice1 << " " << mystic_dice2 << 
        "\t\t\t" << username << "'s roll: ";

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

        const int matches = (a == dice || a == dice_2) + (b == dice || b == dice_2);
        if(matches > 0){
            jackpot += 25 * matches;
        }else{
            jackpot -= 25;
        }


        const int matches_1 = (mystic_dice1 == dice || mystic_dice1 == dice_2) + (mystic_dice2 == dice_2 || mystic_dice2 == dice);
        if(matches_1 > 0){
            mystic_jackpot += 25 * matches_1;
        }else{
            mystic_jackpot -= 25;
        }

        cout << "\n\n\n\t\t\tDice Roll: " << dice << " & " << dice_2 << "\n" << endl;
        const int rolled_dice[] = {dice, dice_2};
        display_dice_images(rolled_dice, 2);

        cout << "\nMystic's Balance: $" << mystic_jackpot
        << "\t\t\t" << username <<  "'s" << " Balance: $" << jackpot << "\n"
        <<"\n-------------------------------------------------------------------";

        if (jackpot <= 0 || mystic_jackpot <= 0) {
            mystic_game_over_double_roll();
            return;
        }
    } while(a != 0);

}


void mystic_triple_roll(){

    cout << "\n\n\n\n" << username <<  "'s" << " starting balance: $" << jackpot << endl;

    mystic_jackpot = jackpot;

    cout << "Mystic's starting balance: $" << mystic_jackpot << "\n\n\n" << endl; 

    
    do{
    
        mystic_dice1 = (rand() % 6) + 1;
        mystic_dice2 = (rand() % 6) + 1;
        mystic_dice3 = (rand() % 6) + 1;


        cout << "\n\n\nMystic rolls.... : " << mystic_dice1 << " " << mystic_dice2 << " " << mystic_dice3 << 
        "\t\t\t" << username << "'s roll: ";


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
        dice_3 = (rand() % 6) + 1;


        const int matches = (a == dice || a == dice_2 || a == dice_3) + 
        (b == dice || b == dice_2 || b == dice_3) + 
        (c == dice || c == dice_2 || c == dice_3);

        if(matches > 0){
            jackpot += 25 * matches;
        }else{
            jackpot -= 25;
        }
        

        const int matches_1 = (mystic_dice1 == dice || mystic_dice1 == dice_2 || mystic_dice1 == dice_3) + 
        (mystic_dice2 == dice || mystic_dice2 == dice_2 || mystic_dice2 == dice_3) + 
        (mystic_dice3 == dice || mystic_dice3 == dice_2 || mystic_dice3 == dice_3);
        
        if(matches_1 > 0){
            mystic_jackpot += 25 * matches_1;
        }else{
            mystic_jackpot -= 25;
        }

        cout << "\n\n\n\t\t\tDice Roll: " << dice << " & " << dice_2 <<  " & " << dice_3 << "\n" << endl;
        const int rolled_dice[] = {dice, dice_2, dice_3};
        display_dice_images(rolled_dice, 3);
        
        cout << "\nMystic's Balance: $" << mystic_jackpot
        << "\t\t\t" << username <<  "'s" << " Balance: $" << jackpot << "\n"
        <<"\n-------------------------------------------------------------------";

        if (jackpot <= 0 || mystic_jackpot <= 0) {
            mystic_game_over_triple_roll();
            return;
        }
    } while(a != 0);

}


void mystic_quad_roll(){


    cout << "\n\n\n\n" << username <<  "'s" << " starting balance: $" << jackpot << endl;

    mystic_jackpot = jackpot;

    cout << "Mystic's starting balance: $" << mystic_jackpot << "\n\n\n" << endl; 

    do{
        mystic_dice1 = (rand() % 6) + 1;
        mystic_dice2 = (rand() % 6) + 1;
        mystic_dice3 = (rand() % 6) + 1;
        mystic_dice4 = (rand() % 6) + 1;



        cout << "\n\n\nMystic rolls.... : " << mystic_dice1 << " " << mystic_dice2 << " " << mystic_dice3 << " " << mystic_dice4 <<
        "\t\t\t" << username << "'s roll: ";

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
        dice_3 = (rand() % 6) + 1;
        dice_4 = (rand() % 6) + 1;


        const int matches = (a == dice || a == dice_2 || a == dice_3 || a == dice_4) + 
        (b == dice || b == dice_2 || b == dice_3 || b == dice_4) + 
        (c == dice || c == dice_2 || c == dice_3 || c == dice_4) +
        (d == dice || d == dice_2 || d == dice_3 || d == dice_4);

        if(matches > 0){
            jackpot += 25 * matches;
        }else{
            jackpot -= 25;
        }


        cout << "Mystic rolls.... : " << mystic_dice1 << " " << mystic_dice2 << " " << mystic_dice3 << " " << mystic_dice4;
        

        const int matches_1 = (mystic_dice1 == dice || mystic_dice1 == dice_2 || mystic_dice1 == dice_3 || mystic_dice1 == dice_4) + 
        (mystic_dice2 == dice || mystic_dice2 == dice_2 || mystic_dice2 == dice_3 || mystic_dice2 == dice_4) + 
        (mystic_dice3 == dice || mystic_dice3 == dice_2 || mystic_dice3 == dice_3 || mystic_dice3 == dice_4) +
        (mystic_dice4 == dice || mystic_dice4 == dice_2 || mystic_dice4 == dice_3 || mystic_dice4 == dice_4);

        if(matches_1 > 0){
            mystic_jackpot += 25 * matches_1;
        }else{
            mystic_jackpot -= 25;
        }

        cout << "\n\n\n\t\t\tDice Roll: " << dice << " & " << dice_2 <<  " & " << dice_3 << " & " << dice_4 << "\n" << endl;
        const int rolled_dice[] = {dice, dice_2, dice_3, dice_4};
        display_dice_images(rolled_dice, 4);
        
        cout << "\nMystic's Balance: $" << mystic_jackpot
        << "\t\t\t" << username <<  "'s" << " Balance: $" << jackpot << "\n"
        <<"\n-------------------------------------------------------------------";

        if (jackpot <= 0 || mystic_jackpot <= 0) {
            mystic_game_over_quad_roll();
            return;
        }
    } while(a != 0);

}


void mystic_game_over_single_roll() {
    if (jackpot <= 0 && mystic_jackpot <= 0) {
        cout << "\n\n\n\n(Mystic): It looks like we have a tie " << username << ".......";
    } else if (jackpot <= 0) {
        cout << "\n\n\n\n(Mystic): HA! You ran out of money " << username << "!";
    } else {
        cout << "\n\n\n\n(Mystic): You actually won! This can't be........!";
    }

    cout << "\n\n\n\n(Mystic): Would you like to play again, " << username << "?" << endl
        << "(Press 1 to restart OR press 0 to quit): ";

    while (!(cin >> restart) || (restart != 0 && restart != 1)) {
        cout << "\nNot valid input. Press 1 to restart OR press 0 to quit: ";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    if (restart == 0) {
        cout << "\nThank you for playing " << username << "!" << endl;
        std::exit(0);
    }

    mystic();
}


void mystic_game_over_double_roll(){
    
    if (jackpot <= 0 && mystic_jackpot <= 0) {
        cout << "\n\n\n\n(Mystic): It looks like we have a tie " << username << ".......";
    } else if (jackpot <= 0) {
        cout << "\n\n\n\n(Mystic): Isn't that unfortunate " << username << "!";
    } else {
        cout << "\n\n\n\n(Mystic): You actually won! This can't be........!";
    }   

    cout << "\n\n\n\n(Mystic): Would you like to play again, " << username << "?" << endl
        << "(Press 1 to restart OR press 0 to quit): ";

    while (!(cin >> restart) || (restart != 0 && restart != 1)) {
        cout << "\nNot valid input. Press 1 to restart OR press 0 to quit: ";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    if (restart == 0) {
        cout << "\nThank you for playing " << username << "!" << endl;
        std::exit(0);
    }

    mystic();
}



void mystic_game_over_triple_roll(){

    if (jackpot <= 0 && mystic_jackpot <= 0) {
        cout << "\n\n\n\n(Mystic): It looks like we have a tie " << username << ".......";
    } else if (jackpot <= 0) {
        cout << "\n\n\n\n(Mystic): You should have known better then to use 3 dice against me " << username << "!";
    } else {
        cout << "\n\n\n\n(Mystic):  Not possible! You actually won! This can't be........!";
    }

    cout << "\n\n\n\n(Mystic): Would you like to play again, " << username << "?" << endl
        << "(Press 1 to restart OR press 0 to quit): ";

    while (!(cin >> restart) || (restart != 0 && restart != 1)) {
        cout << "\nNot valid input. Press 1 to restart OR press 0 to quit: ";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    if (restart == 0) {
        cout << "\nThank you for playing " << username << "!" << endl;
        std::exit(0);
    }

    mystic();
};



void mystic_game_over_quad_roll(){

    if (jackpot <= 0 && mystic_jackpot <= 0) {
        cout << "\n\n\n\n(Mystic): It looks like we have a tie " << username << ".......";
    } else if (jackpot <= 0) {
        cout << "\n\n\n\n(Mystic): You really thought you would win " << username << "??";
    } else {
        cout << "\n\n\n\n(Mystic): You actually won! This can't be........!";
    }

    cout << "\n\n\n\n(Mystic): Would you like to play again, " << username << "?" << endl
        << "(Press 1 to restart OR press 0 to quit): ";

    while (!(cin >> restart) || (restart != 0 && restart != 1)) {
        cout << "\nNot valid input. Press 1 to restart OR press 0 to quit: ";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    if (restart == 0) {
        cout << "\nThank you for playing " << username << "!" << endl;
        std::exit(0);
    }

    mystic();

};

void mystic_intro_prompts(){

    const char* prompts[] = {
    
    "\n\n(Mystic): Not you again!",
    "\n\n(Mystic): Ready to lose??",
    "\n\n(Mystic): I love a challenge ~",
    "\n\n(Mystic): Finally a formidable opponent...",
    "\n\n(Mystic): Winning.....is what im good at ~",
    "\n\n(Mystic): Just give up now...there's no hope for you! HAHAHA",
    "\n\n(Mystic): You just might have a chance!......sike ~"

    };

    srand(static_cast<unsigned int>(std::time(0)));

    int randomIndex = rand() % (sizeof(prompts) / 
    sizeof(prompts[0]));

    cout << prompts[randomIndex] << endl; 

}
