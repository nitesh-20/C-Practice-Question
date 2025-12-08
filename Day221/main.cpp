#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Merge overlapping intervals
struct Interval {
    int start;
    int end;
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cout << "Merge Intervals Demo\n";
    cout << "Enter number of intervals: ";
    int n;
    if (!(cin >> n) || n <= 0) return 0;

    vector<Interval> intervals(n);
    cout << "Enter " << n << " intervals as: start end\n";
    for (int i = 0; i < n; ++i) {
        cin >> intervals[i].start >> intervals[i].end;
        if (intervals[i].start > intervals[i].end) {
            swap(intervals[i].start, intervals[i].end);
        }
    }

    sort(intervals.begin(), intervals.end(), [](const Interval& a, const Interval& b) {
        if (a.start != b.start) return a.start < b.start;
        return a.end < b.end;
    });

    vector<Interval> merged;
    merged.push_back(intervals[0]);

    for (int i = 1; i < n; ++i) {
        Interval& last = merged.back();
        if (intervals[i].start <= last.end) {
            last.end = max(last.end, intervals[i].end);
        } else {
            merged.push_back(intervals[i]);
        }
    }

    cout << "\nMerged intervals:\n";
    for (const auto& in : merged) {
        cout << in.start << " " << in.end << "\n";
    }

    return 0;
}