#include <iostream>
using namespace std;
#include <vector>
#include <limits>



class BankAccount {
// vector<string> accounts;

private:
string accountNumber;
string accountHolderName;
double balance;


public:
    // this Bank Account for no input
    BankAccount() :accountNumber(" "), accountHolderName(" "), balance(0.0){};

BankAccount(string accountNumber, string accountHolderName, double balance);

string GetNumber()const{return accountNumber;}
    string GetName() const {return accountHolderName;}
    double GetBalance() const{return balance;}

void SetBalance(double balance){this->balance = balance;}
    void SetAccountNumber(string accountNumber){this->accountNumber = accountNumber;}
void deposit (double amount);
    void withdrawal(double amount);
    void SetName(string name){ accountHolderName = name;}


    //Rule of three

    BankAccount(const BankAccount& other): accountNumber(other.accountNumber), accountHolderName(other.accountHolderName),balance(other.balance) {
    }
    BankAccount& operator=(const BankAccount& other) {
        if (this != &other) {
            accountNumber = other.accountNumber;
            accountHolderName = other.accountHolderName;
            balance = other.balance;

        }
        return *this;

    }
    ~BankAccount() {}

    //Arithmetic
    BankAccount& operator+=(double amount) {
        if (amount < 0) {
            cout << "Cannot deposit negative amount." << endl;
            return *this;
        }
        deposit(amount);
        return *this;
    }

    BankAccount& operator-=(double amount) {
        if (amount < 0 ) {
            cout << "Cannot withdraw negative amount." << endl;
            return *this;
        }
        withdrawal(amount);
        return *this;

    }

    // Comparison

    bool operator==(const BankAccount& other)const {
        return accountNumber == other.accountNumber;
    }

    bool operator<(const BankAccount& other) const {
        return balance < other.balance;
    }

    bool operator>(const BankAccount& other) const {
        return balance > other.balance;
    }
    static void printAccount(const BankAccount& account);
    static BankAccount createAccountFromInput();

};


void BankAccount::deposit(double amount){balance+= amount;}
void BankAccount::withdrawal(double amount) {
    if (amount <= balance) {
        balance -= amount;
    }else {
        cout << "Insufficient balance" << endl;
    }
}

BankAccount::BankAccount(string accountNumber, string accountHolderName, double balance) {
 this->accountNumber = accountNumber;
    this->accountHolderName = accountHolderName;
    this->balance = balance;

}

//Static Function
void BankAccount::printAccount(const BankAccount& account) {
    cout << "Account Number: " << account.GetNumber() << ", Name: " << account.GetName() << ", Balance: " << account.GetBalance()<< endl;

}
BankAccount BankAccount::createAccountFromInput() {
    string num;
    string name;
    double bal;
    cout << "Enter number: ";
    cin >> num;
    cout << "Enter name: ";
    cin >> name;
    cout << "Enter balance: ";
    cin >> bal;
    return BankAccount(num, name, bal);

}


int main() {

vector<BankAccount> accountList;
    // BankAccount account;
    // string currNumber;
    // string currName;
    // double currBalance;
    int i;
    int numb;


// for loop for the data entry
for (i = 0; i<4; i++) {
    cout << "Account " << (i+1) << ":" << endl;

    BankAccount accountHolder = BankAccount::createAccountFromInput();
    accountList.push_back(accountHolder);
}


    // do while loop
    do {
        // display options
        cout << "\n1. Display All Accounts      2. Deposit         3. Withdraw         4. Exit" << endl;
        cin >> numb;
        if (cin.fail()) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max());
            cout << "Invaild input." << endl;
            continue;
        }
        // Display all accounts
        if (numb == 1) {
            for (i = 0; i<accountList.size(); i++) {
                BankAccount::printAccount(accountList[i]);
            }
        }
        // deposit

        if (numb == 2) {

            cout<<"Enter account index (0-" << accountList.size()-1 << "): " << endl;
            cin >> i;
            if (i>=0 && i<accountList.size()) {
                double amount;
                cout << "Enter amount: " << endl;

                cin>>amount;

                accountList[i] +=amount;
                cout << "New Balance: " << accountList[i].GetBalance() << endl;
            } else {
                cout << "Invalid account index" << endl;
            }
        }


        // withdraw
        if (numb == 3) {
            cout << "Enter account index(0-" << accountList.size()-1 << "): " << endl;
            cin >> i;

            if (i>=0 && i<accountList.size()) {
                double amount;
                cout << "Enter amount: " << endl;

                cin >> amount;
                accountList[i] -= amount;

                cout << "New Balance: " << accountList[i].GetBalance() << endl;
            } else {
                cout << "Invalid account index" << endl;
            }
        }
    }while (numb != 4);


    return 0;

}