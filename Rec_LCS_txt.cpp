#include <bits/stdc++.h>
using namespace std;

vector<string> readFile(string myFile) {

    ifstream file(myFile);

    vector<string> words;
    string word;

    if (!file.is_open()) {
        cout << "Error opening " << myFile << endl;
        return words;
    }

    while (file >> word) {
        words.push_back(word);
    }

    file.close();

    return words;
}

int LCS(vector<string> &text1, vector<string> &text2, int i, int j, vector<vector<int>> &dp) {

    if (i == 0 || j == 0) {
        return 0;
    }

    if (dp[i][j] != 0) {
        return dp[i][j];
    }

    if (text1[i - 1] == text2[j - 1]) {

        dp[i][j] = 1 + LCS(text1, text2, i - 1, j - 1, dp);
    }
    
    else {

        int a = LCS(text1, text2, i - 1, j, dp);
        int b = LCS(text1, text2, i, j - 1, dp);

        dp[i][j] = max(a, b);
    }

    return dp[i][j];
}

vector<string> getLCS(vector<string> &text1, vector<string> &text2, vector<vector<int>> &dp) {

    int i = text1.size();
    int j = text2.size();

    vector<string> result;

    while (i > 0 && j > 0) {

        if (text1[i - 1] == text2[j - 1]) {

            result.push_back(text1[i - 1]); 
            i--;
            j--;
        }

        else {
            if (dp[i - 1][j] >= dp[i][j - 1]) i--;
            else j--;
        }
    }

    int left = 0;
    int right = result.size() - 1;

    while (left < right) {

        string temp = result[left];
        result[left] = result[right];
        result[right] = temp;

        left++;
        right--;
    }

    return result;
}

int main() {

    vector<string> text1 = readFile("file1.txt");
    vector<string> text2 = readFile("file2.txt");

    int n = text1.size();
    int m = text2.size();

    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));

    int lcsLength = LCS(text1, text2, n, m, dp);
    cout << "LCS Length: " << lcsLength << endl;

    vector<string> lcs = getLCS(text1, text2, dp);

    cout << "LCS: ";
    for(int i = 0; i < lcs.size(); i++){
        cout << lcs[i] << " ";
    }

    return 0;
}