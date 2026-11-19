#include <iostream>
#include <iomanip>
using namespace std;

//VARIABLES
int enterAccnumber;
int enterPin;
int attempts = 3;
int user = -1;

double depositAmount;
double withdrawalAmount;
double sendAmount;

// USER DETAILS
string names[4] = {"Kutloano", "Smangaliso", "Lesedi", "Katlego"};

int accountNumber[4] = {13579, 24680, 97531, 86420};

int pin[4] = {1376, 3255, 5892, 6568};

double balances[4] = {15000, 3275.90, 456, 1600.56};



// PART 1: LOGINS
// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

void logins()
{
    do
    {
        cout << "========== LOGINS ==========" << endl;

        cout << "Enter account number: ";
        cin >> enterAccnumber;

        cout << "Enter PIN: ";
        cin >> enterPin;

        // SEARCH FOR CUSTOMER DETAILS
        for(int i = 0; i < 4; i++)
        {
            if(enterAccnumber == accountNumber[i] &&
               enterPin == pin[i])
            {
                user = i;
                break;
            }
        }

        // CHECK LOGINS
        if(user == -1)
        {
            attempts--;

            cout << "Incorrect account number or PIN!" << endl;
            cout << "Attempts remaining: " << attempts << endl;
        }

    }
    while(user == -1 && attempts > 0);

    // LOGIN SUCCESSFUL
    if(user != -1)
    {
        cout<<""<<endl;
        cout << "Login successful!" << endl;
        cout << "Welcome, " << names[user] << "." << endl;
    }
    else
    {
        cout<<""<<endl;
        cout << "Your account is blocked!" << endl;

    }
}



// PART 2: CHECKING BALANCE
// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

void showBalance()
{
    cout << "Your current balance is R"
         << fixed << setprecision(2)
         << balances[user] << endl;
}



// PART 3: DEPOSIT
// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

void deposit()
{
    cout << "Enter amount to deposit: R";
    cin >> depositAmount;

    if(depositAmount > 0)
    {
        balances[user] = balances[user] + depositAmount;

        cout<<""<<endl;
        cout << "Deposit successful!" << endl;
        cout << "New balance: R" << balances[user] << endl;
    }
    else
    {
        cout << "Invalid amount! Deposit must be more than R0." << endl;
    }
}


// PART 4: WITHDRAWAL
// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

void widraw()
{
    cout << "Enter withdrawal amount: R";
    cin >> withdrawalAmount;

    if(withdrawalAmount <= 0)
    {
        cout << "Invalid amount! Enter an amount greater than R0." << endl;
    }

    else if(withdrawalAmount > balances[user])
    {
        cout << "Insufficient funds!" << endl;
        cout << "Available balance: R" << balances[user] << endl;
    }

    else
    {
        balances[user] = balances[user] - withdrawalAmount;

        cout<<""<<endl;
        cout << "Withdrawal successful!" << endl;
        cout << "Remaining balance: R" << balances[user] << endl;
    }
}


// PART 5: SENDING CASH
// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

void sendCash()
{
    int receiverAcc;
    int receiverIndex = -1;

    cout << "Enter receiver's account number: ";
    cin >> receiverAcc;

    // SEARCHING FOR RECEIVER ACCOUNT
    for(int i = 0; i < 4; i++)
    {
        if(accountNumber[i] == receiverAcc)
        {
            receiverIndex = i;
            break;
        }
    }

    // CHECKING IF ACCOUNT EXISTS
    if(receiverIndex == -1)
    {
        cout << "Account does not exist!" << endl;
    }

    // PREVENT SENDING MONEY TO YOURSELF
    else if(receiverIndex == user)
    {
        cout << "You cannot send money to your own account!" << endl;
    }

    else
    {
        cout << "Account holder: " << names[receiverIndex] << endl;

        cout << "Enter amount to send: R";
        cin >> sendAmount;

        if(sendAmount <= 0)
        {
            cout << "Invalid amount! Enter an amount greater than R0." << endl;
        }

        else if(sendAmount > balances[user])
        {
            cout << "Insufficient funds!" << endl;
        }

        else
        {
            // DEDUCTING MONEY FROM SENDER
            balances[user] = balances[user] - sendAmount;

            // ADDING MONEY TO RECEIVER
            balances[receiverIndex] =
                balances[receiverIndex] + sendAmount;
            cout<<""<<endl;
            cout << "Money sent successfully!" << endl;
            cout << "Sent to: " << names[receiverIndex] << endl;
            cout << "Remaining balance: R" << balances[user] << endl;
        }
    }
}


// PART 6: BANKING MENU
// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

void menu()
{
    int option;

    do
    {
        cout<<""<<endl;
        cout<<""<<endl;
        cout << "========== BANKING SERVICES MENU ==========" << endl;
        cout << "1. Check Balance" << endl;
        cout << "2. Deposit" << endl;
        cout << "3. Withdrawal" << endl;
        cout << "4. Send Cash" << endl;
        cout << "5. EXIT" << endl;
        cout << "==================================" << endl;

        cout << "Enter your option: ";
        cin >> option;

        switch(option)
        {
            case 1:
                showBalance();
                break;

            case 2:
                deposit();
                break;

            case 3:
                widraw();
                break;

            case 4:
                sendCash();
                break;

            case 5:
                cout<<""<<endl;
                cout<<""<<endl;
                cout << "Thank you for banking with us" << endl;
                cout << "Goodbye, " <<names[user] << "." << endl;
                break;

            default:
                cout << "Invalid option! Please try again." << endl;
        }

    }
    while(option != 5);
}


// MAIN FUNCTION
// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

int main()
{
    // STEP 1: CUSTOMER LOGIN
    logins();

    // STEP 2: OPEN MENU ONLY IF LOGIN IS SUCCESSFUL
    if(user != -1)
    {
        menu();
    }
    else
    {
        cout << "Access denied!" << endl;
    }

    return 0;
}
