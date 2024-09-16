#include <bits/stdc++.h>
#define ll long long
#define optimize() ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;

class bank {
    static ll cnt; 
    private:
        string name;
        string dob;
        string nid;
        string address;
        string contact_no;
        string password;
        ll acnt_num = 2104027;
        double balance = 0.0;
        bool checkbook_requested = false; 

    public:
        bank() {}

        void create_acnt() {
            // Clear the input buffer
            cin.ignore(numeric_limits<streamsize>::max(), '\n');  

            cout << "Enter your Full Name: " << endl;
            getline(cin, name);  

            cout << "Enter your Date of Birth: " << endl;
            getline(cin, dob);

            cout << "Enter your NID number/Passport number: " << endl;
            getline(cin, nid);

            cout << "Enter your Address: " << endl;
            getline(cin, address);

            cout << "Enter your Contact No. : " << endl;
            getline(cin, contact_no);

            cout << "Set your password: " << endl;
            getline(cin, password);

            cnt++;
            acnt_num += cnt;

            cout << "Your account has been created successfully. Here is your account number: " << acnt_num << endl;
            cout<<endl;
        }

        void deposit(double amount) {
            if (amount > 0) {
                balance += amount;
                cout << "Deposited " << amount << ". New balance: " << balance << endl;
            } else {
                cout << "Invalid amount to deposit." << endl;
            }
        }

        void withdraw(double amount) {
            if (amount > 0 && amount <= balance) {
                balance -= amount;
                cout << "Withdrew " << amount << ". Remaining balance: " << balance << endl;
            } else {
                cout << "Insufficient balance or invalid amount." << endl;
            }
        }

        bool transfer(ll target_account, double amount, bank &recipient) {
            if (amount > 0 && amount <= balance) {
                balance -= amount;
                recipient.deposit(amount);  // Add amount to recipient's account
                cout << "Transferred " << amount << " to account " << target_account << endl;
                return true;
            } else {
                cout << "Insufficient balance or invalid amount." << endl;
                return false;
            }
        }

        void buyTicket(double ticket_price) {
            if (ticket_price > 0 && ticket_price <= balance) {
                balance -= ticket_price;
                cout << "Ticket purchased successfully! Price: " << ticket_price << endl;
                cout << "Remaining balance: " << balance << endl;
            } else {
                cout << "Insufficient balance to buy the ticket!" << endl;
            }
        }

        void mobileRecharge(double recharge_amount) {
            if (recharge_amount > 0 && recharge_amount <= balance) {
                balance -= recharge_amount;
                cout << "Mobile recharge successful! Amount: " << recharge_amount << endl;
                cout << "Remaining balance: " << balance << endl;
            } else {
                cout << "Insufficient balance for mobile recharge!" << endl;
            }
        }

        void accountStatement() const {
            cout << "Account Number: " << acnt_num << endl;
            cout << "Name: " << name << endl;
            cout << "Date of Birth: " << dob << endl;
            cout << "NID/Passport: " << nid << endl;
            cout << "Address: " << address << endl;
            cout << "Contact No.: " << contact_no << endl;
            cout << "Current Balance: " << balance << endl;
            cout << "Checkbook Requested: " << (checkbook_requested ? "Yes" : "No") << endl;
        }

        void requestCheckbook() {
            if (!checkbook_requested) {
                checkbook_requested = true;
                cout << "Checkbook request has been submitted." << endl;
            } else {
                cout << "You have already requested a checkbook." << endl;
            }
        }

        ll getAccountNumber() const {
            return acnt_num;
        }
};


ll bank::cnt = 0;

class BankSystem {
    unordered_map<ll, bank> accounts; 

public:
    void createAccount() {
        bank newAccount;
        newAccount.create_acnt();
        ll acc_num = newAccount.getAccountNumber();
        accounts[acc_num] = newAccount; // Storing account 
    }

    void accountStatement(ll accountNumber) {
        if (accounts.find(accountNumber) != accounts.end()) {
            accounts[accountNumber].accountStatement();
        } else {
            cout << "Account not found!" << endl;
        }
    }

    void depositToAccount(ll accountNumber, double amount) {
        if (accounts.find(accountNumber) != accounts.end()) {
            accounts[accountNumber].deposit(amount);
        } else {
            cout << "Account not found!" << endl;
        }
    }

    void withdrawFromAccount(ll accountNumber, double amount) {
        if (accounts.find(accountNumber) != accounts.end()) {
            accounts[accountNumber].withdraw(amount);
        } else {
            cout << "Account not found!" << endl;
        }
    }

    
    void transferMoney(ll fromAccount, ll toAccount, double amount) {
        if (accounts.find(fromAccount) != accounts.end() && accounts.find(toAccount) != accounts.end()) {
            bank &fromAcc = accounts[fromAccount];
            bank &toAcc = accounts[toAccount];
            fromAcc.transfer(toAccount, amount, toAcc);
        } else {
            cout << "One or both accounts not found!" << endl;
        }
    }

    
    void requestCheckbook(ll accountNumber) {
        if (accounts.find(accountNumber) != accounts.end()) {
            accounts[accountNumber].requestCheckbook();
        } else {
            cout << "Account not found!" << endl;
        }
    }

    // Buy a ticket using account balance
    void buyTicket(ll accountNumber, double ticket_price) {
        if (accounts.find(accountNumber) != accounts.end()) {
            accounts[accountNumber].buyTicket(ticket_price);
        } else {
            cout << "Account not found!" << endl;
        }
    }

  
    void mobileRecharge(ll accountNumber, double recharge_amount) {
        if (accounts.find(accountNumber) != accounts.end()) {
            accounts[accountNumber].mobileRecharge(recharge_amount);
        } else {
            cout << "Account not found!" << endl;
        }
    }
};

int main() {
    optimize();
    BankSystem bankSystem;
    ll accountNumber, toAccountNumber,contact_no;
    int choice;
    double amount;

    while (true) {
        cout<<"----Main Menu----"<<endl;
        cout << "1. Create an account" << endl;
        cout << "2. Deposit money" << endl;
        cout << "3. Withdraw money" << endl;
        cout << "4. Transfer money" << endl;
        cout << "5. Account statement" << endl;
        cout << "6. Request Checkbook" << endl;
        cout << "7. Buy Ticket" << endl;
        cout << "8. Mobile Recharge" << endl;
        cout << "9. Exit" << endl;
        cout << "Enter your choice: "<<endl;
        cin >> choice;

        switch (choice) {
            case 1:
                bankSystem.createAccount();
                break;
            case 2:
                cout << "Enter account number: "<<endl;
                cin >> accountNumber;
                cout << "Enter amount to deposit: "<<endl;
                cin >> amount;
                bankSystem.depositToAccount(accountNumber, amount);
                break;
            case 3:
                cout << "Enter account number: "<<endl;
                cin >> accountNumber;
                cout << "Enter amount to withdraw: "<<endl;
                cin >> amount;
                bankSystem.withdrawFromAccount(accountNumber, amount);
                break;
            case 4:
                cout << "Enter your account number: "<<endl;
                cin >> accountNumber;
                cout << "Enter recipient account number: "<<endl;
                cin >> toAccountNumber;
                cout << "Enter amount to transfer: "<<endl;
                cin >> amount;
                bankSystem.transferMoney(accountNumber, toAccountNumber, amount);
                break;
            case 5:
                cout << "Enter account number: "<<endl;
                cin >> accountNumber;
                bankSystem.accountStatement(accountNumber);
                break;
            case 6:
                cout << "Enter account number: "<<endl;
                cin >> accountNumber;
                bankSystem.requestCheckbook(accountNumber);
                break;
            case 7:
                cout << "Enter account number: "<<endl;
                cin >> accountNumber;
                cout << "Enter ticket price: "<<endl;
                cin >> amount;
                bankSystem.buyTicket(accountNumber, amount);
                break;
            case 8:
                cout << "Enter account number: "<<endl;
                cin >> accountNumber;
                cout << "Enter recharge amount: "<<endl;
                cin >> amount;
                cout<<"Enter mobile no."<<endl;
                cin>>contact_no;
                bankSystem.mobileRecharge(accountNumber, amount);
                break;
            case 9:
                cout << "Exiting..." << endl;
                exit(0);
            default:
                cout << "Invalid choice!" << endl;
        }
    }

    return 0;
}
