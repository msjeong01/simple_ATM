#include "ATMController.h"

int main(){
    ATMController atm;
    std::string input;

    // 1. Insert Card
    std::cout << "Input Card: ";
    std::cin >> input;
    atm.insertCard(input);

    // 2. Check the PIN number
    std::cout << "Input PIN number: ";
    std::cin >> input;
    if(!atm.checkPin(input)){
        return 1;
    }

    // 3. Select Account
    std::cout << "Select an account: ";
    std::cin >> input;
    atm.selectAccount(input);

    // 4. set balance
    int balance = 0;
    std::cout << "Set balance: ";
    std::cin >> balance;
    atm.setBalance(balance);

    // 5. deposit
    int deposit = 0;
    std::cout << "Deposit $ ";
    std::cin >> deposit;
    atm.depositCash(deposit);

    // 6. withdraw
    int withdraw = 0;
    std::cout << "Withdraw $ ";
    std::cin >> withdraw;
    if(!atm.withdrawCash(withdraw)){
        return 1;
    }

    // 7. Extract the card
    atm.extractCard();
    return 0;
}