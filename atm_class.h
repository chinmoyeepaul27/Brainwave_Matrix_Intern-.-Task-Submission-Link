#include <bits/stdc++.h>
#include <stdlib.h>
#define ll long long
#define ln endl
#define optimize() ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;

class ATM {
private:
    ll main_balance = 0;
    vector<string> transaction_history;

public:
    ATM() {
        cout << "Please insert your card and after inserting card, enter pin: " << ln;
    }

    void withdrawal_money(ll amount) {
        if(amount > main_balance) {
            cout << "Sorry, your current balance is less than the amount." << ln;
        } else {
            main_balance -= amount;
            transaction_history.push_back("Withdrawn: " + to_string(amount));
            cout << "Withdrawal successful. New balance is: " << main_balance << ln;
        }
    }

    void deposite_money(ll amount) {
        main_balance += amount;
        transaction_history.push_back("Deposited: " + to_string(amount));
        cout << "Deposit successful. New balance is: " << main_balance << ln;
    }

    void transfer_money() {
        cout << "Enter the account number: " << ln;
        int acnt; cin >> acnt;
        cout << "Please enter the amount: " << ln;
        int amnt; cin >> amnt;
        if(amnt > main_balance) {
            cout << "Sorry, your current balance is less than the amount." << ln;
        } else {
            main_balance -= amnt;
            transaction_history.push_back("Transferred: " + to_string(amnt) + " to " + to_string(acnt));
            cout << "Money transfer successful. New balance is: " << main_balance << ln;
        }
    }

    void check_balance() {
        cout << "The main balance is: " << main_balance << ln;
    }

    void show_transaction_history() {
        cout << "--- Transaction History ---" << endl;
        if(transaction_history.size() == 0){
          cout<<"No history yet."<<ln;
        }
        else{
          for (auto entry : transaction_history) {
            cout << entry << endl;
        }
        }
    }
};