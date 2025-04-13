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

void ATMController::insertCard(const std::string& card){

}

bool ATMController::checkPin(const std::string& pin){

}

void ATMController::selectAccount(const std::string& account){

}

int ATMController::checkBalance(){

}

void ATMController::checkDeposit(int total){

}

bool ATMController::withdrawCash(int total){

}

void ATMController::extractCard(){

}