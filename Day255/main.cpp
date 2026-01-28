#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Medium level DSA: Activity Selection (Interval Scheduling)
// Given n activities with start and finish times, select the maximum number
// of non-overlapping activities using a greedy algorithm (sort by end time).

struct Activity {
    int start;
    int end;
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    
    

    cout << "===== Activity Selection (Maximum Non-Overlapping Intervals) =====\n";

    int n;
    cout << "Enter number of activities: ";
    if (!(cin >> n) || n <= 0) {
        cout << "Invalid n. Exiting.\n";
        return 0;
    }

    vector<Activity> a(n);
    cout << "Enter start and end time for each activity (s e):\n";
    for (int i = 0; i < n; ++i) {
        cin >> a[i].start >> a[i].end;
        if (a[i].end < a[i].start) {
            cout << "End time < start time, swapping.\n";
            swap(a[i].start, a[i].end);
        }
    }

    // Sort by end time (ascending)
    sort(a.begin(), a.end(), [](const Activity &x, const Activity &y) {
        if (x.end == y.end) return x.start < y.start;
        return x.end < y.end;
    });

    int count = 0;
    int lastEnd = -1e9; // very small

    vector<Activity> chosen;

    for (const auto &act : a) {
        if (act.start >= lastEnd) {
            // we can take this activity
            ++count;
            chosen.push_back(act);
            lastEnd = act.end;
        }
    }

    cout << "Maximum number of non-overlapping activities: " << count << "\n";
    cout << "Chosen activities (start, end):\n";
    for (const auto &act : chosen) {
        cout << act.start << ' ' << act.end << '\n';
    }

    return 0;
}
