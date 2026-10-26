#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>
#include "selectionAlgo.h"

const int maxSize = 101;

void displayArr(int arr[]);

int main()
{
    std::srand(std::time(0));

    int unsortedArr[maxSize];

    // Generate random votes from 1 to 5
    for (int i = 0; i < maxSize; i++)
    {
        unsortedArr[i] = (std::rand() % 5) + 1;
    }

    std::string candidates[5] = {
        "Bo Dalton Capistrano",
        "Cornelius Raymon Agustin",
        "Deja Jayla Banaga",
        "Lalla Brielle Yabut",
        "Franklin Relano Castro"
    };

    std::cout << "Unsorted Array:\n";
    displayArr(unsortedArr);

    // Sort the votes
    selectionSort(unsortedArr, maxSize);

    std::cout << "\nSorted Array:\n";
    displayArr(unsortedArr);

    // Manual count
    int manualCount[6] = {0};

    for (int i = 0; i < maxSize; i++)
    {
        manualCount[unsortedArr[i]]++;
    }

    // Algorithm count
    int voteCount[6] = {0};

    for (int i = 0; i < maxSize; i++)
    {
        int vote = unsortedArr[i];

        if (vote >= 1 && vote <= 5)
        {
            voteCount[vote]++;
        }
    }

    // Find the winner
    int winner = 1;

    for (int i = 2; i <= 5; i++)
    {
        if (voteCount[i] > voteCount[winner])
        {
            winner = i;
        }
    }

    // Display results
    std::cout << "\nVote Count Results:\n";

    for (int i = 1; i <= 5; i++)
    {
        std::cout << "\nCandidate " << i << ": ";
        std::cout << candidates[i - 1] << "\n";

        std::cout << "Manual Count: ";
        std::cout << manualCount[i] << "\n";

        std::cout << "Algorithm Count: ";
        std::cout << voteCount[i] << "\n";
    }

    std::cout << "\nWinner: Candidate " << winner << "\n";
    std::cout << "Name: "
              << candidates[winner - 1] << "\n";
    std::cout << "Votes: " << voteCount[winner] << "\n";

    return 0;
}

void displayArr(int arr[])
{
    for (int i = 0; i < maxSize; i++)
    {
        std::cout << arr[i] << " ";

        if ((i + 1) % 20 == 0)
        {
            std::cout << "\n";
        }
    }

    std::cout << "\n";
}

