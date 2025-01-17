#include <iostream>
#include <map>
#include <thread>
#include <mutex>
#include <vector>

// Initialize the map with customer IDs and balances
void initializeCustomerRecords(std::map<long, int> &customerRecords, int startingBalance, int numAccounts) {
    for (long i = 0; i < numAccounts; ++i) {
        customerRecords[i] = startingBalance;
    }
}

// Withdraw function
void withdrawTwoMx(std::map<long, int> &customerRecords, int index, int withdraw_amount, std::mutex &mxOdd, std::mutex &mxEven) {
    if (index % 2 == 0) {
        mxEven.lock();
    } else {
        mxOdd.lock();
    }

    if (customerRecords.find(index) != customerRecords.end()) {
        customerRecords[index] -= withdraw_amount;
    }

    if (index % 2 == 0) {
        mxEven.unlock();
    } else {
        mxOdd.unlock();
    }
}

// Deposit function
void depositTwoMx(std::map<long, int> &customerRecords, int index, int deposit_amount, std::mutex &mxOdd, std::mutex &mxEven) {
    if (index % 2 == 0) {
        mxEven.lock();
    } else {
        mxOdd.lock();
    }

    if (customerRecords.find(index) != customerRecords.end()) {
        customerRecords[index] += deposit_amount;
    }

    if (index % 2 == 0) {
        mxEven.unlock();
    } else {
        mxOdd.unlock();
    }
}

// Thread function for withdrawing from all accounts
void withdrawFromAllAccounts(std::map<long, int> &customerRecords, int withdraw_amount, std::mutex &mxOdd, std::mutex &mxEven) {
    for (const auto &entry : customerRecords) {
        withdrawTwoMx(customerRecords, entry.first, withdraw_amount, mxOdd, mxEven);
    }
}

// Thread function for depositing into all accounts
void depositToAllAccounts(std::map<long, int> &customerRecords, int deposit_amount, std::mutex &mxOdd, std::mutex &mxEven) {
    for (const auto &entry : customerRecords) {
        depositTwoMx(customerRecords, entry.first, deposit_amount, mxOdd, mxEven);
    }
}

int main() {
    // Initialize variables
    std::map<long, int> customerRecords;
    const int startingBalance = 1000;
    const int numAccounts = 10;
    const int withdrawAmount = 100;
    const int depositAmount = 200;

    std::mutex mxOdd, mxEven;
    initializeCustomerRecords(customerRecords, startingBalance, numAccounts);

    std::thread withdrawThread(withdrawFromAllAccounts, std::ref(customerRecords), withdrawAmount, std::ref(mxOdd), std::ref(mxEven));
    std::thread depositThread(depositToAllAccounts, std::ref(customerRecords), depositAmount, std::ref(mxOdd), std::ref(mxEven));

    withdrawThread.join();
    depositThread.join();

    std::cout << "Final Balances:" << std::endl;
    for (const auto &entry : customerRecords) {
        std::cout << "Customer ID: " << entry.first << ", Balance: " << entry.second << std::endl;
    }

    return 0;
}
