#include <iostream>
#include <vector>
#include <deque>
#include <algorithm>
#include <limits>
#include <climits>
using namespace std;

// Singly linked list (basic)
struct Node {
    int val;
    Node* next;
    Node(int v): val(v), next(nullptr) {}
};

struct SinglyLinkedList {
    Node* head = nullptr;
    void insert_end(int x) {
        Node* n = new Node(x);
        if (!head) { head = n; return; }
        Node* cur = head;
        while (cur->next) cur = cur->next;
        cur->next = n;
    }
    bool remove_value(int x) {
        Node* cur = head; Node* prev = nullptr;
        while (cur) {
            if (cur->val == x) {
                if (!prev) head = cur->next;
                else prev->next = cur->next;
                delete cur;
                return true;
            }
            prev = cur; cur = cur->next;
        }
        return false;
    }
    void display() const {
        Node* cur = head;
        while (cur) { cout << cur->val << " "; cur = cur->next; }
        cout << '\n';
    }
};

// Stack using vector
struct SimpleStack {
    vector<int> a;
    void push(int x){ a.push_back(x); }
    bool pop(){ if (a.empty()) return false; a.pop_back(); return true; }
    int top() const { return a.empty() ? INT_MIN : a.back(); }
    void display() const { for (auto v: a) cout << v << ' '; cout << '\n'; }
};

// Queue using deque
struct SimpleQueue {
    deque<int> q;
    void enqueue(int x){ q.push_back(x); }
    bool dequeue(){ if (q.empty()) return false; q.pop_front(); return true; }
    int front() const { return q.empty() ? INT_MIN : q.front(); }
    void display() const { for (auto v: q) cout << v << ' '; cout << '\n'; }
};

// Binary search on a sorted vector
bool binarySearch(const vector<int>& a, int target){
    int l=0, r=(int)a.size()-1;
    while (l<=r){
        int m = l + (r-l)/2;
        if (a[m]==target) return true;
        if (a[m]<target) l = m+1; else r = m-1;
    }
    return false;
}

void printMenu(){
    cout<<"\nDSA Demo Menu:\n";
    cout<<"1) Linked List: insert end\n";
    cout<<"2) Linked List: remove value\n";
    cout<<"3) Linked List: display\n";
    cout<<"4) Stack: push\n";
    cout<<"5) Stack: pop\n";
    cout<<"6) Stack: display\n";
    cout<<"7) Queue: enqueue\n";
    cout<<"8) Queue: dequeue\n";
    cout<<"9) Queue: display\n";
    cout<<"10) Binary search (on array)\n";
    cout<<"0) Exit\n";
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    SinglyLinkedList list;
    SimpleStack st;
    SimpleQueue qu;

    int choice = -1;
    while (choice!=0){
        printMenu();
        if (!(cin>>choice)) break;
        if (choice==0) break;
        int x;
        switch(choice){
            case 1:
                cout<<"value: "; cin>>x; list.insert_end(x);
                break;
            case 2:
                cout<<"value: "; cin>>x; cout<<(list.remove_value(x)?"removed":"not found")<<"\n";
                break;
            case 3:
                cout<<"List: "; list.display(); break;
            case 4:
                cout<<"value: "; cin>>x; st.push(x); break;
            case 5:
                cout<<(st.pop()?"popped":"stack empty")<<"\n"; break;
            case 6:
                cout<<"Stack: "; st.display(); break;
            case 7:
                cout<<"value: "; cin>>x; qu.enqueue(x); break;
            case 8:
                cout<<(qu.dequeue()?"dequeued":"queue empty")<<"\n"; break;
            case 9:
                cout<<"Queue: "; qu.display(); break;
            case 10: {
                int n; cout<<"n: "; cin>>n; vector<int> a(n);
                cout<<"enter "<<n<<" values:\n";
                for (int i=0;i<n;i++) cin>>a[i];
                sort(a.begin(), a.end());
                cout<<"target: "; cin>>x;
                cout<<(binarySearch(a,x)?"found":"not found")<<"\n";
                break; }
            default:
                cout<<"invalid\n";
        }
    }
    return 0;
}
