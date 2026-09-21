#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;
    vector<vector<int>> v;
    for(int i=0; i<n; i++){
        int start,finish;
        cin >> start >> finish;
        v.push_back({start, finish});
    }
    sort(v.begin(), v.end(), [&](vector<int> &a, vector<int> &b){return a[1] < b[1];});
    for(int i=0; i<n; i++){
        cout << start << finish;
    }
    int take = 1;
    int finish = v[0][1];
    for(int i=1; i<n; i++){
        if(v[i][0] >= finish){
            take++;
            finish = v[i][1];
        }
    }
    cout << take <<"\n";
    return 0;
}