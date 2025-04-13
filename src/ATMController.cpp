#include "ATMController.h"

ATMController::ATMController()
    : state(State::IDLE), balance(0) {}

ATMController::~ATMController() {}

bool ATMController::checkState(State required) const{
    if(state != required) {
        return false;
    }
    return true;
}

void ATMController::insertCard(const std::string& cardNumber){
    if(!checkState(State::IDLE)) return;
    card = cardNumber;
    state = State::CardInserted;
    std::cout << "Card Number [" << card << "] inserted" << std::endl;
}

bool ATMController::checkPin(const std::string& pinNumber){
    if(!checkState(State::CardInserted)) return false;
    if(pinNumber != PIN){
        std::cerr << "Uncorrect PIN number, please try again" << std::endl;
        return false;
    }
    state = State::PinChecked;
    std::cout << "PIN number checked" << std::endl;
    return true;
}

void ATMController::selectAccount(const std::string& selectAccount){
    if(!checkState(State::PinChecked)) return;
    account = selectAccount;
    state = State::AccountSelected;
    std::cout<< "Account [" << account << "] selected" << std::endl;
}

void ATMController::setBalance(int input){
    if(!checkState(State::AccountSelected)) return;
    balance = input;
    state = State::Transaction;
    std::cout << "Complete to set balance $" << balance << std::endl;
}

int ATMController::checkBalance(){
    if(!checkState(State::Transaction)) return -1;
    return balance;
}

void ATMController::depositCash(int input){
    if(!checkState(State::Transaction)) return;
    balance += input;
    std::cout << "Complete to deposit $" << input << std::endl;
}

bool ATMController::withdrawCash(int output){
    if(!checkState(State::Transaction)) return false;
    if(output > balance){
        std::cerr << "Impossible to withdraw $" << output << ", Out of balance $" << balance << std::endl;
        return false;
    }
    balance -= output;
    std::cout << "Complete to withdraw $" << output << std::endl;
    return true;
}

void ATMController::extractCard(){
    std::cout << "Card Extracted" << std::endl;
    card = "";
    account = "";
    balance = 0;
    state = State::IDLE;
}