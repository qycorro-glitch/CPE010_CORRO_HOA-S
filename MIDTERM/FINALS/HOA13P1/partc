
#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <ctime>
#include <thread>
#include <vector>
#include <chrono>
#include <algorithm>
#include "selectionAlgo.h"
#include "../HOA7P1/supple/selectionAlgo.h"

using Clock = std::chrono::steady_clock;

double ms(Clock::time_point a, Clock::time_point b)
{
    return std::chrono::duration<double, std::milli>(b - a).count();
}

// Sort chunks [start,end) in parallel, then merge pairwise
void parallelSelectionSort(std::vector<int>& v, int numThreads)
{
    int n = v.size();
    std::vector<int> bounds(numThreads + 1);
    for (int t = 0; t <= numThreads; t++)
        bounds[t] = (int)((long long)n * t / numThreads);

    std::vector<std::thread> threads;
    for (int t = 0; t < numThreads; t++)
    {
        threads.emplace_back([&v, &bounds, t]() {
            selectionSort(v.data() + bounds[t], bounds[t + 1] - bounds[t]);
        });
    }
    for (auto& th : threads) th.join();

    // Merge sorted chunks (sequential, O(n) per merge)
    for (int t = 1; t < numThreads; t++)
        std::inplace_merge(v.begin(), v.begin() + bounds[t], v.begin() + bounds[t + 1]);
}

// Each thread counts its own slice into a private array (no data race)
void parallelCount(const std::vector<int>& v, int numThreads, int counts[6])
{
    int n = v.size();
    std::vector<std::vector<int>> local(numThreads, std::vector<int>(6, 0));
    std::vector<std::thread> threads;
    for (int t = 0; t < numThreads; t++)
    {
        int s = (int)((long long)n * t / numThreads);
        int e = (int)((long long)n * (t + 1) / numThreads);
        threads.emplace_back([&v, &local, t, s, e]() {
            for (int i = s; i < e; i++) local[t][v[i]]++;
        });
    }
    for (auto& th : threads) th.join();
    for (int t = 0; t < numThreads; t++)
        for (int c = 1; c <= 5; c++) counts[c] += local[t][c];
}

void runTest(int n, const std::vector<int>& threadCounts)
{
    std::vector<int> original(n);
    for (int i = 0; i < n; i++) original[i] = (std::rand() % 5) + 1;

    std::cout << "\n=== N = " << n << " votes ===\n";
    std::cout << std::left << std::setw(10) << "Threads"
              << std::setw(14) << "Sort (ms)"
              << std::setw(14) << "Count (ms)"
              << std::setw(10) << "Speedup"
              << "Correct?\n";

    double baseline = 0;
    std::vector<int> reference = original;
    std::sort(reference.begin(), reference.end());

    for (int T : threadCounts)
    {
        std::vector<int> v = original;

        auto t0 = Clock::now();
        if (T == 1) selectionSort(v.data(), n);
        else        parallelSelectionSort(v, T);
        auto t1 = Clock::now();

        int counts[6] = {0};
        auto t2 = Clock::now();
        parallelCount(v, T, counts);
        auto t3 = Clock::now();

        double sortMs = ms(t0, t1);
        if (T == 1) baseline = sortMs;
        bool ok = (v == reference) && (counts[1]+counts[2]+counts[3]+counts[4]+counts[5] == n);

        std::cout << std::left << std::setw(10) << T
                  << std::setw(14) << std::fixed << std::setprecision(3) << sortMs
                  << std::setw(14) << ms(t2, t3)
                  << std::setw(10) << std::setprecision(2) << (baseline / sortMs)
                  << (ok ? "Yes" : "NO") << "\n";
    }
}

int main()
{
    std::srand(std::time(0));
    std::cout << "Hardware threads available: "
              << std::thread::hardware_concurrency() << "\n";

    std::vector<int> tc = {1, 2, 4, 8};
    runTest(101, tc);      // original problem size
    runTest(20000, tc);    // larger size so threading effects are visible
    runTest(50000, tc);
    return 0;
}