#include <bits/stdc++.h>
using namespace std;

int Longest_Common_Subsequence(string text1, string text2, int n, int m, vector<vector<int>>& dp){
    if(n == 0 || m == 0) return 0;

    if(dp[i][j] != -1) return dp[i][j];

    if(text1[n-1] == text2[m-1]){
        dp[i][j] = 1 + Longest_Common_Subsequence(text1, text2, n-1, m-1, dp);
    }

    else {
        int a = Longest_Common_Subsequence(text1, text2, n-1, m, dp);
        int b = Longest_Common_Subsequence(text1, text2, n, m-1, dp);
        dp[i][j] = max(a,b);
    }
    return dp[i][j];
}

int main(){
    string text1 = "abcde";
    string text2 = "ace";

    int n = text1.length();
    int m = text2.length();

    vector<vector<int>> dp(n+1, vector<int>(m+1, -1));

    int result = Longest_Common_Subsequence(text1, text2, n, m, dp);

    cout << result << endl;

    return 0;
}