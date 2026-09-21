#include <bits/stdc++.h>
using namespace std;

int LCS(string s1, string s2, int n, int m){
    //Base case
    if(n == 0 || m == 0) return 0;

    //If the last characters are same
    if(s1[n-1] == s2[m-1]){
        return 1 + LCS(s1, s2, n-1, m-1);
    }
    //If the last Characters are different
    else {
        int a = LCS(s1, s2, n-1, m);
        int b = LCS(s1, s2, n, m-1);
        if(a > b){
            return a;
        }
        else {
            return b;
        }
    }
}
int main(){
    string s1,s2;
    cin >> s1 >> s2;
    
    int n = s1.length();
    int m = s2.length();

    int result = LCS(s1, s2, n ,m);
    cout << "LCS is: " << result;
    return 0;
}