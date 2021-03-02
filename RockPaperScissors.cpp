#include <iostream>
#include <windows.h>
#include <ctime>

using namespace std;

int input;
int ai_response;
char replay;
int win;
int ran_num;

int answer(int user_input);
void outcome(int user_input, int ai_input);

int main()
{
    //intro
    cout << "\n\n\n\nWelcome to my little game. This is a small game I made for the first time!\n\n";
    cout << "You are going to play Rock, Paper, Scissors against me.\n\n";
    cout << "Please enter the number of your choice of attack and press 'Enter'\n";
    
    //run at least once and check for valid response, if not skip functions and loop again
    do
    {
        cout << "Press...\n";
        cout << "[1] for Rock,\n";
        cout << "[2] for Paper'\n";
        cout << "[3] for Scissors\n";
        cin >> input;
        if( input < 1 || input > 3)
        {
            cout << "Invalid number.\n";
        }
        else
        {
            ai_response = answer(input);
            outcome(input,ai_response);   

        //run at least once and check for valid replay response, if not, keep looping
            do
            {
                cout << "Want to play again? y/n \n";
                cin >> replay;
                
                if(replay == 'y'){
                    cout << "Okay Let's go!\n";
                }
                else if (replay == 'n'){
                    cout << "Okay, Bye!\n";
                }
                else {
                    cout << "Not a valid response. Try again\n";
                }    
            } while (replay != 'y' && replay != 'n');
        }
    } while (replay != 'n');
    
}


// Opponent answer function

int answer(int user_input){ // user input num to output string
    cout << "You chose ";
    if(user_input ==1) {
        cout << "Rock\n";
    }
    else if(user_input == 2) {
        cout << "Paper\n";
    }
    else {
        cout << "Scissors\n";
    }

    srand(time(0)); //seed rng with current time
    int ran_num = (rand() % 3) + 1; //get random number from generator and add 1, so answer is always 1,2 or 3
    cout << "your opponent chose ";
    if( ran_num == 1){
        cout << "Rock\n";
    }
    else if(ran_num == 2){
        cout << "Paper\n";
    }
    else {
        cout << "Scissors\n";
    }
    
    return ran_num;
    
}


// check outcome function
void outcome(int user_input, int ai_input){
    Sleep(1000); // minor delay for visual purpose
    if(user_input == ai_input)
    {
        cout << "Draw!\n";
    }
    else if ((user_input == 1 && ai_input == 2) ||
        (user_input == 2 && ai_input == 3) ||
        (user_input == 3 && ai_input == 1)){
            
        cout << "Sorry, you lost...\n";     
        
    }
    else {
        cout << "You won!\n";
    }    
}
