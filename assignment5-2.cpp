#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

int main()
{
    string user_name;
    double account_balance;
    double amount;
    int choose_menu;
    cout << "Input your name: ";
    getline(cin, user_name);
    cout << "Please enter your balance amount: ";
    cin >> account_balance;
    if (account_balance >0) {
        cout<<user_name<<" Welcome to your account"<<endl;
        cout<<"1.Make a Deposit"<<endl;
        cout<<"2.Make a Withdrawal"<<endl;
        cout<<"Your option:";
        cin>>choose_menu;
        switch (choose_menu){
            case 1:{
            cout << "Input your deposit : ";
            cin >> amount;
            if (amount >0) {
                cout << "Deposit amount: " << amount << endl;
                account_balance += amount;
                cout << "New balance: " << account_balance << endl;
        }
            else {
                cout<<"Deposit must be greater than 0";
            }
                break;
        }
            case 2:{
                cout << "Input your withdrawal amount: ";
                cin >> amount;
                if (amount <= account_balance && amount >0 ){
                    cout << "Withdrawal: " << amount << endl;
                    account_balance -= amount;
                    cout << "Final balance: " << account_balance << endl;
                }
                else 
                    cout<<"Withdrawal must be smaller or equal and greater 0 than Account balance";
                break;
            }
            default:
                cout<<"Wrong Option";

        }
    }
    else
        cout<<"Account cannot be equal 0 or negative";
    return 0;
}

