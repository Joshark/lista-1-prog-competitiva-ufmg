// #include <bits/stdc++.h>
#include <vector>
#include <string>
#include <iostream>
#include <sstream>

using namespace std;

int votes[1010][1010];
vector<string> candidates(30);
int qtdCandidates;
int totalVotes = 0;
int voters = 0;
vector<int> running(30);

void countVotes()
{
    int min = 9999;
    int max = 0;

    vector<int> candidateVote(qtdCandidates + 10, 0);

    while (true)
    {
        for (int i = 0; i < voters; i++)
        {
            for (int j = 0; j < qtdCandidates; j++)
            {
                if (running[(votes[i][j]) - 1])
                {
                    candidateVote[(votes[i][j]) - 1]++;
                    break;
                }
            }
        }

        for (int i = 0; i < qtdCandidates; i++)
        {
            if (running[i])
            {
                if (candidateVote[i] > max)
                    max = candidateVote[i];
                if (candidateVote[i] < min)
                    min = candidateVote[i];
            }
        }

        if (min == max)
        {
            break;
        }

        if (max > voters / 2)
        {
            break;
        }

        for (int i = 0; i < qtdCandidates; i++)
        {
            if (candidateVote[i] == min)
            {
                running[i] = 0;
            }
        }

        min = 9999;
        max = 0;
        fill(candidateVote.begin(), candidateVote.end(), 0);
    }

    for (int i = 0; i < qtdCandidates; i++)
    {
        if (running[i] && candidateVote[i] == max)
        {
            cout << candidates[i] << endl;
        }
    }
}

int main()
{
    int cases;
    string ballot;

    vector<int> choice(20, 0);

    cin >> cases;

    while (cases--)
    {
        cin >> qtdCandidates;
        cin.ignore();

        voters = 0;

        for (int i = 0; i < qtdCandidates; i++)
        {
            getline(cin, candidates[i]);
            running[i] = 1;
        }

        while (getline(cin, ballot) && !ballot.empty())
        {
            istringstream iss(ballot);

            for (int i = 0; i < qtdCandidates; i++)
            {
                iss >> votes[voters][i];
            }
            voters++;
        }

        countVotes();

        for (int i = 0; i < 21; i++)
            for (int j = 0; j < 21; j++)
                votes[i][j] = 0;

        if (cases)
            cout << endl;

        totalVotes = 0;
    }
    return 0;
}