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
        std::err << "Uncorrect PIN number, please try again" << std::endl;
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

int ATMController::checkBalance(){
    if(!checkState(State::Transaction)) return -1;
    return balance;
}

void ATMController::checkDeposit(int total){

}

bool ATMController::withdrawCash(int total){

}

void ATMController::extractCard(){

}