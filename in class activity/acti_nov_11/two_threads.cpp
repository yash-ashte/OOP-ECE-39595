#include <iostream>
#include <thread>
#include <vector>
#include <chrono>

using namespace std;

const long LASTNUM = 100000;

void sumNumbers(long start, long end, long &sum) {
    long localSum = 0;
    for (long i = start; i < end; i++) {
        localSum += i;
    }
    sum = localSum;
}

// Sequential version of sum
void SingleThread(long NumT) {
    vector<long> sums(NumT, 0);
    long totalSum = 0;
    
    for (long i = 0; i < NumT; i++) {
        sumNumbers(1, LASTNUM, sums[i]);
        totalSum += sums[i];
        cout << "Sequential Sum " << i + 1 << ": " << sums[i] << endl;
    }
    cout << "Total Sequential Sum: " << totalSum << endl;
}

// Multithreaded version
void MultiThread(long NumT) {
    vector<thread> threads;
    vector<long> sums(NumT, 0);
    long totalSum = 0;

    for (long i = 0; i < NumT; i++) {
        threads.emplace_back(sumNumbers, 1, LASTNUM, ref(sums[i]));
    }

    for (auto &t : threads) {
        t.join();
    }

    for (long i = 0; i < NumT; i++) {
        cout << "Parallel Sum " << i + 1 << ": " << sums[i] << endl;
        totalSum += sums[i];
    }
    cout << "Total Parallel Sum: " << totalSum << endl;
}

// Function to compare time for sequential vs parallel execution
void CompareSequentialVsParallel(long NumT) {
    auto start = chrono::steady_clock::now();
    SingleThread(NumT);
    auto mid = chrono::steady_clock::now();
    MultiThread(NumT);
    auto end = chrono::steady_clock::now();

    auto sequentialTime = chrono::duration_cast<chrono::microseconds>(mid - start).count();
    auto parallelTime = chrono::duration_cast<chrono::microseconds>(end - mid).count();

    cout << "Sequential Execution Time: " << sequentialTime << " microseconds" << endl;
    cout << "Parallel Execution Time: " << parallelTime << " microseconds" << endl;
}

int main() {
    long NumT = 4; // Example number of threads; adjust as needed
    CompareSequentialVsParallel(NumT);

    return 0;
}
