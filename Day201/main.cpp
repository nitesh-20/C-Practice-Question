#include <iostream>
#include <vector>
using namespace std;

// Queue implemented using two stacks (vectors)
class MyQueue {
    vector<int> s1; // input stack
    vector<int> s2; // output stack

    void transfer() {
        while (!s1.empty()) {
            s2.push_back(s1.back());
            s1.pop_back();
        }
    }
public:
    void enqueue(int x) {
        s1.push_back(x);
    }
    void dequeue() {
        if (s2.empty()) transfer();
        if (!s2.empty()) s2.pop_back();
        else cout << "Queue is empty.\n";
    }
    int front() {
        if (s2.empty()) transfer();
        if (!s2.empty()) return s2.back();
        throw runtime_error("Queue is empty");
    }
    bool empty() const {
        return s1.empty() && s2.empty();
    }
    int size() const {
        return (int)s1.size() + (int)s2.size();
    }
};

int main() {
    MyQueue q;
    cout << "Queue using two stacks - Demo\n";
    cout << "Menu:\n1) Enqueue\n2) Dequeue\n3) Front\n4) Size\n5) Empty\n6) Exit\n";
    int choice;
    while (true) {
        cout << "\nEnter choice: ";
        if (!(cin >> choice)) break;
        if (choice == 6) break;
        try {
            if (choice == 1) {
                int x; cout << "Enter value to enqueue: "; cin >> x;
                q.enqueue(x);
                cout << x << " enqueued.\n";
            } else if (choice == 2) {
                if (q.empty()) cout << "Queue is empty.\n";
                else {
                    cout << "Front element " << q.front() << " will be dequeued.\n";
                    q.dequeue();
                }
            } else if (choice == 3) {
                if (q.empty()) cout << "Queue is empty.\n";
                else cout << "Front: " << q.front() << "\n";
            } else if (choice == 4) {
                cout << "Size: " << q.size() << "\n";
            } else if (choice == 5) {
                cout << (q.empty() ? "Empty" : "Not empty") << "\n";
            } else {
                cout << "Invalid choice\n";
            }
        } catch (const exception& e) {
            cout << "Error: " << e.what() << "\n";
        }
    }
    cout << "Goodbye!\n";
    return 0;
}