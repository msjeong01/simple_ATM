#include <string>

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

        void insertCard(const std::string& card);
        bool checkPin(const std::string& pin);
        void selectAccount(const std::string& account);
        int checkBalance();
        void checkDeposit(int total);
        bool withdrawCash(int total);
        void extractCard();

    private:
        State state;
        std::string card;
        std::string account;
        int balance;
};