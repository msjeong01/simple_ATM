#include <string>
#include <iostream>

# define PIN "9999"

class ATMController{
    public:
        enum class State {
            IDLE,
            CardInserted,
            PinChecked,
            AccountSelected,
            Transaction
        };

        ATMController();
        ~ATMController();

        void insertCard(const std::string& cardNumber);
        bool checkPin(const std::string& pinNumber);
        void selectAccount(const std::string& selectAccount);
        void setBalance(int input);
        int checkBalance();
        void depositCash(int input);
        bool withdrawCash(int output);
        void extractCard();

    private:
        State state;
        std::string card;
        std::string account;
        int balance;

        bool checkState(State required) const;
};