#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

int main()
{
    string user_name;
    double account_balance;
    double amount;

    cout << "Input your name: ";
    getline(cin, user_name);
    cout << "Input your balance: ";
    cin >> account_balance;
    if (account_balance >0) {
        cout << fixed << setprecision(2);
        cout << "Input your deposit : ";
        cin >> amount;
        if (amount >0) {
            cout << "Deposit amount: " << amount << endl;
            account_balance += amount;
            cout << "New balance: " << account_balance << endl;
            cout << "Input your withdrawal amount: ";
            cin >> amount;
                if (amount <= account_balance && amount >0 ){
                    cout << "Withdrawal: " << amount << endl;
                    account_balance -= amount;
                    cout << "Final balance: " << account_balance << endl;
        }
                else 
                    cout<<"Withdrawal must be smaller or equal and greater 0 than Account balance";
    }
        else
            cout<<"Deposit must be greater than 0";
}
    else
        cout<<"Account cannot be equal 0 or negative";
    return 0;
}
