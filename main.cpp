#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

//welcome message
void welcome_message() {
    cout << "WELCOME TO THE DICE ROLL GAME......!"<<endl;
}

//checking user's age
int user_age() {
    int age;
    cout <<"Enter your age: ";
    cin>>age;
    
    if (age<18){
        cout <<"Access denied. Player must be older than 18"<<endl;
        exit(0);
    }
    return age;
}

//setting a 1000 wallet for user
int starting_balance() {
    int balance = 1000;
    cout << "Your starting wallet balance is: " << balance << endl;
    return balance;
}

//setting random number generator
int main() {
    srand(time(0));
    welcome_message();  //recalling welcome function
    int age = user_age();   //input and check user's age
    int balance = starting_balance();
    int bet,recharge_amount,withdraw_amount;
    string choice;
    
    //main game
    while(true){
        cout<<"Your current wallet balance is: "<<balance<<endl;
        cout<<"Enter betting amount (100 , 300 , 500): ";
        cin>>bet;
        
        if(bet!=100 && bet!=300 && bet!=500){
            cout<<"Invalid betting amout, please choose 100 , 300 , 500"<<endl;
            continue;   //asking user to enter betting amount again
        }
        //checking whether wallet balance is enough to play
        if (balance < bet){
            cout <<"Insufficient wallet balance. Do you want to recharge (y/n): ";
            cin >> choice;
            if (choice == "y"){
                cout <<"Enter recharge amount (Maximum 5000): ";
                cin >> recharge_amount;
                
                //setting maximum betting amount as 5000
                if (recharge_amount > 5000){
                    cout << "Recharging failed. Maximum amount is 5000" << endl;
                    continue;       //going to the main loop without recharging
                }
                balance += recharge_amount;     //addding recharge amount to the balance
                cout <<"Current wallet balance is: "<<balance<<endl;
            }else{
                break;      //ending the if your doest' want to recharge
            }
        }
        
        //reducing the bet amount from the balance
        balance -= bet;
        
        int u_wins = 0, c_wins = 0;
        int rounds = 0;
        int last_round_winner = 0;
        
        //playing three rounds
        while (rounds < 3){
            int u_roll = (rand() % 6+1) + (rand() % 6+1);
            int c_roll = (rand() % 6+1) + (rand() % 6+1);
            
            cout << "\nRound " << (rounds + 1) << ":\n";
            cout << "User rolled: " << u_roll << endl;
            cout << "Computer rolled: " << c_roll << endl;
            
            //result comparison
            if (u_roll > c_roll){
                cout << "User win this round" << endl;
                u_wins++;
                
                //user early win check
                if(last_round_winner == 1){
                    cout << "User won two consecutive rounds" <<endl;
                    break;      //since user won two consecutive rounds game ends
                }
                last_round_winner = 1;
            } else if(c_roll > u_roll) {
                cout << "Computer win this round" << endl;
                c_wins++;
                
                //computer early win check
                if (last_round_winner == 2){
                    cout << "Computer win two consecutive rounds" <<endl;
                    break;      //since computer won two consecutive rounds game ends
                }
                last_round_winner = 2;
            }else {
                cout << "Round tied" << endl;   //both rolled same number
                last_round_winner = 0;
            }
            rounds++;
        }
        
        //determine the winner
        if (u_wins > c_wins) {
            cout << "User won the game" << endl;
            balance += (bet*2);     //since user won bet amount has to be doubled
        } else if (c_wins > u_wins) {
            cout << "Computer won the game" << endl;
        }else {
            cout << "Game tied" << endl;    //both won equal no.of rounds
            balance += bet;     //since game tied betting amount refunded
        }
        
        cout << "Current wallet balance is: " << balance << endl;
        
        //Asking user want to play again
        cout << "Play again? (y/n): ";
        cin >> choice;
        
        if (choice == "n") {
            
            //asking whether user want to withdraw money
            cout << "Do you want to withdraw money? (y/n): ";
            cin >> choice;
            if (choice == "y") {
                cout << "Enter withdrawal amout: ";
                cin >> withdraw_amount;
                if (withdraw_amount <= balance){
                    balance -= withdraw_amount;
                    cout << "Successfully withdrawed money" << endl;
                    cout << "Available wallet balance is: " << balance << endl;
                } else {
                    cout << "Insufficient wallet balance" << endl;
                }
            }
            cout << "Thank for playing......!" << endl;
            break;
        }
    }
    return 0;
}

    
    


