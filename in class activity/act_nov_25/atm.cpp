#include <iostream>
#include <random>
#include <vector>
#include <iterator>
#include <stdexcept>
#include <string>

std::mt19937 gen(42000);

using bill = std::size_t; // store bills by serial number
using cash_stack = std::vector<bill>;

// Base ATMException class
class ATMException {
public:
    virtual void message() const {
        std::cout << "The ATM has experienced an error during your request. Request canceled, try again." << std::endl;
    }
    virtual ~ATMException() = default;
};

// Exception for invalid withdrawal amount (not divisible by 20)
class InvalidAmountException : public ATMException {
public:
    void message() const override {
        std::cout << "Withdrawal amount must be a multiple of 20. Please try again." << std::endl;
    }
};

// Exception for insufficient funds
class InsufficientFundsException : public ATMException {
public:
    void message() const override {
        std::cout << "Insufficient funds in the ATM for the requested withdrawal amount. Please try again." << std::endl;
    }
};

// ATM which holds only 20 dollar bills up to a limited capacity
class ATM {
    std::vector<bill> bills;
public:
    ATM(int capacity) {
        // fill up the ATM with bills
        for (int i = 0; i < capacity; i++)
            bills.push_back(gen());
    }

    // Withdraw function with exception handling
    std::vector<bill> withdraw(int dollar_amount) {
        if (dollar_amount % 20 != 0) {
            throw InvalidAmountException();
        }

        int num_bills = dollar_amount / 20;
        if (num_bills > bills.size()) {
            throw InsufficientFundsException();
        }

        std::vector<bill> withdrawn_bills;
        for (int i = 0; i < num_bills; ++i) {
            withdrawn_bills.push_back(bills.back());
            bills.pop_back();
        }

        return withdrawn_bills;
    }

    friend std::ostream& operator<<(std::ostream& os, const ATM& atm);
};

std::ostream& operator<<(std::ostream& os, const ATM& atm) {
    std::copy(atm.bills.begin(), atm.bills.end(), std::ostream_iterator<bill>(os, " "));
    return os;
}

template <class T>
T read(std::istream& is) {
    T t;
    is >> t;
    return t;
}

int main() {
    ATM atm(10); // Initialize ATM with 10 bills
    std::cout << "Welcome to the ATM interface!\n";
    bool running = true;

    while (running) {
        std::cout << "Menu options:\n"
                  << "\t* 'withdraw <amount>'\n"
                  << "\t* 'view'\n"
                  << "\t* 'quit'\n";
        std::cout << "=> ";
        std::string command = read<std::string>(std::cin);

        if (command == "withdraw") {
            try {
                int withdraw_amount = read<int>(std::cin);
                cash_stack withdrawn = atm.withdraw(withdraw_amount);
                std::cout << "Here are your withdrawn bills: ";
                std::copy(withdrawn.begin(), withdrawn.end(), std::ostream_iterator<bill>(std::cout, " "));
                std::cout << "\n";
            } catch (const ATMException& ex) {
                ex.message();
            }
        } else if (command == "view") {
            std::cout << "Bills currently in the ATM: " << atm << "\n";
        } else if (command == "quit") {
            running = false;
        } else {
            std::cout << "Oopsie-whoopsie, I don't know what '" << command << "' means! n_n\n";
        }
    }

    std::cout << "Bye\n";
    return 0;
}
