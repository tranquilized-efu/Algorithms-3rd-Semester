#include <bits/stdc++.h>
using namespace std;

struct Activity {
    int start;
    int finish;
};

// Sort activities according to finish time
bool compare(Activity a, Activity b) {
    return a.finish < b.finish;
}

int main() {
    int n;

    // cout << "Enter number of activities: ";
    cin >> n;

    vector<Activity> activities(n);

    // Input activities
    for (int i = 0; i < n; i++) {
        // cout << "Enter start and finish time for activity ";
        // cout << i + 1 << ": ";
        cin >> activities[i].start >> activities[i].finish;
    }

    // Sort according to finish time
    sort(activities.begin(), activities.end(), compare);

    cout << "Selected activities:\n";

    // Select the first activity
    int lastFinish = activities[0].finish;

    cout << "(" << activities[0].start << ", " << activities[0].finish << ")\n";

    int count = 1;

    // Select remaining activities
    for (int i = 1; i < n; i++) {

        // If current activity starts after or exactly when previous activity finishes
        if (activities[i].start >= lastFinish) {

            cout << "(" << activities[i].start << ", " << activities[i].finish << ")\n";

            lastFinish = activities[i].finish;
            count++;
        }
    }

    cout << "\nMaximum number of non-overlapping activities: " << count << endl;

    return 0;
}