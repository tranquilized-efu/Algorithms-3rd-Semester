#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;


// Function to create the DP table
vector<vector<int>> createTable(int rows, int cols)
{
    vector<vector<int>> L(rows, vector<int>(cols, 0));

    return L;
}


// Function to fill the DP table
void buildTable(string X, string Y, vector<vector<int>>& L)
{
    int m = X.length();
    int n = Y.length();

    for (int i = 1; i <= m; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            // If characters are equal
            if (X[i - 1] == Y[j - 1])
            {
                L[i][j] = L[i - 1][j - 1] + 1;
            }

            // If characters are different
            else
            {
                L[i][j] = max(L[i - 1][j], L[i][j - 1]);
            }
        }
    }
}


// Function to print the DP table
void printTable(string X, string Y, vector<vector<int>> L)
{
    int m = X.length();
    int n = Y.length();

    cout << "\nDP Table:\n\n";

    cout << "    ";

    for (int j = 0; j < n; j++)
    {
        cout << Y[j] << " ";
    }

    cout << endl;

    for (int i = 0; i <= m; i++)
    {
        if (i == 0)
            cout << "  ";
        else
            cout << X[i - 1] << " ";

        for (int j = 0; j <= n; j++)
        {
            cout << L[i][j] << " ";
        }

        cout << endl;
    }
}


// Function to find the actual LCS
string findLCS(string X, string Y, vector<vector<int>> L)
{
    int i = X.length();
    int j = Y.length();

    string lcs = "";

    while (i > 0 && j > 0)
    {
        // Characters are equal
        if (X[i - 1] == Y[j - 1])
        {
            lcs += X[i - 1];

            i--;
            j--;
        }

        // Move upward
        else if (L[i - 1][j] > L[i][j - 1])
        {
            i--;
        }

        // Move left
        else
        {
            j--;
        }
    }

    // LCS was constructed backwards
    reverse(lcs.begin(), lcs.end());

    return lcs;
}


// Function to print final result
void printResult(string lcs)
{
    cout << "\nLCS = " << lcs << endl;
    cout << "LCS Length = " << lcs.length() << endl;
}


int main()
{
    string X, Y;

    cin >> X >> Y;


    int m = X.length();
    int n = Y.length();


    // Create DP table
    vector<vector<int>> L = createTable(m + 1, n + 1);


    // Fill DP table
    buildTable(X, Y, L);


    // Display DP table
    printTable(X, Y, L);


    // Find actual LCS
    string lcs = findLCS(X, Y, L);


    // Display result
    printResult(lcs);


    return 0;
}
