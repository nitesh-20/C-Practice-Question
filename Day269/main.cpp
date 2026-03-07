#include <iostream>
#include <vector>
#include <limits>

using namespace std;

int main() {
	int n;
	cout << "Enter number of elements: ";
	cin >> n;

	if (cin.fail() || n <= 0) {
		cout << "Invalid input. Please enter a positive integer.\n";
		return 0;
	}

	vector<int> arr(n);
	cout << "Enter " << n << " integers:\n";
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
		if (cin.fail()) {
			cout << "Invalid input detected.\n";
			return 0;
		}
	}

	int minValue = arr[0], maxValue = arr[0];
	long long sum = 0;
	for (int value : arr) {
		if (value < minValue) minValue = value;
		if (value > maxValue) maxValue = value;
		sum += value;
	}

	double average = static_cast<double>(sum) / n;

	cout << "\n--- Array Statistics ---\n";
	cout << "Minimum: " << minValue << "\n";
	cout << "Maximum: " << maxValue << "\n";
	cout << "Sum    : " << sum << "\n";
	cout << "Average: " << average << "\n";

	int target;
	cout << "\nEnter a number to search: ";
	cin >> target;
	if (cin.fail()) {
		cout << "Invalid target input.\n";
		return 0;
	}

	int index = -1;
	for (int i = 0; i < n; i++) {
		if (arr[i] == target) {
			index = i;
			break;
		}
	}

	if (index == -1) {
		cout << target << " not found in the array.\n";
	} else {
		cout << target << " found at index " << index << ".\n";
	}

	return 0;
}
