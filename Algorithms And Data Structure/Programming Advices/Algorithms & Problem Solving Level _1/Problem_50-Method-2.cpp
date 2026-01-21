#include <iostream>
using namespace std;

// Function to check if the entered PIN is correct
bool checkPIN(int enteredPIN) 
{
    const int correctPIN = 1234;
    return enteredPIN == correctPIN;//T || F
}

// Function to display the balance
void displayBalance() 
{
    const int balance = 7500;
    cout << "Your Balance is: " << balance << endl;
}

// Function to handle the PIN entry process
void handlePINEntry() 
{
    int attempts = 3;
    int enteredPIN;

    while (attempts > 0) 
    {
        cout << "Enter your PIN: ";
        cin >> enteredPIN;

        if (checkPIN(enteredPIN)) 
        {
            displayBalance();
            return; // Exit the function if the PIN is correct
        }
        else 
        {
            attempts--;
            if (attempts > 0) 
            {
                cout << "Wrong PIN. You have " << attempts << " attempts left." << endl;
            }
        }
    }

    cout << "Card is locked!" << endl;
}

int main() {
    handlePINEntry();
    return 0;
}