#include <iostream>
#include <windows.h>

using namespace std;

int input;
string ai_response;
int replay;
int win;

string answer(int user_input);
int outcome(int user_input, string ai_input);

int main()
{
    cout << "\n\n\n\nWelcome to my little game. This is a small game i made for the first time!\n\n";
    cout << "You are going to play Rock, Paper, Scissors against me.\n\n";
    cout << "Please enter the number of your choice of attack and press 'Enter'\n";
    
    do
    {
        cout << "Press...\n";
        cout << "[1] for Rock,\n";
        cout << "[2] for Paper'\n";
        cout << "[3] for Scissors\n";
        cin >> input;

        ai_response = answer(input);

        cout << "Your opponent chose... " << ai_response << "\n\n\n";


        int win = outcome(input,ai_response);
        if(win == 0)
        {
            cout << "Press 1 for 'Yes', 0 for 'No'";
            cin >> replay;
            if(replay == 0){
                cout << "Okay Bye.... :-(\n";
            }
        }
        else {
            replay = 0;
        }

    } while (replay == 1);
    
}


// Opponent answer function
string answer(int user_input){

    if (user_input == 1){

        return "Paper";
    }
    else if (user_input == 2){

        return "Scissors";
    }
    else {

        return "Rock";
    }
}


// check outcome function
int outcome(int user_input, string ai_input){
    
    if((user_input == 1 && ai_input == "Paper") ||
        (user_input == 2 && ai_input == "Scissors") ||
        (user_input == 3 && ai_input == "Rock"))
        {
            Sleep(1000);
            cout << "Sorry...you lost......Play again? :-D\n";
            return 0;
        }
    else 
    {
        cout << "Yes...You won...I dont want to play anymore...Byebye";
        return 1;
    }    
}
