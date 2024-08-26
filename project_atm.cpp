#include <bits/stdc++.h>
#include <stdlib.h>
#define ll long long
#define ln endl
#define optimize() ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
#include "atm_class.h"


int main() {
    ATM a;
    int four_digit;
    cin >> four_digit;
    while(true) {
        system("cls");
        cout << "---Please select a transaction---" << ln;
        cout << "1. Withdrawal money" << ln;
        cout << "2. Deposit money" << ln;
        cout << "3. Transfer money" << ln;
        cout << "4. Check main balance" << ln;
        cout << "5. Show transaction history" << ln;
        cout << "6. Exit" << ln;

        int s_choice;
        cin >> s_choice;

        if(s_choice == 1) {
            cout << "Please enter the amount: " << ln;
            int w;
            cin >> w;
            a.withdrawal_money(w);
            system("pause");
        } else if(s_choice == 2) {
            cout << "Please enter the amount: " << ln;
            int w;
            cin >> w;
            a.deposite_money(w);
            system("pause");
        } else if(s_choice == 3) {
            a.transfer_money();
            system("pause");
        } else if(s_choice == 4) {
            a.check_balance();
            system("pause");
        } else if(s_choice == 5) {
            a.show_transaction_history();
            system("pause");
        } else {
            cout << "Thanks for using.." << ln;
            return 0;
        }
    }
}