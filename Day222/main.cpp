#include <iostream>
#include <list>
#include <unordered_map>
using namespace std;

// LRU Cache implementation (Least Recently Used)
class LRUCache {
    int capacity;
    list<pair<int,int>> dll; // {key, value}, most recent at front
    unordered_map<int, list<pair<int,int>>::iterator> mp; // key -> iterator in list

    void moveToFront(int key) {
        auto it = mp[key];
        dll.splice(dll.begin(), dll, it); // move node to front
    }

public:
    LRUCache(int cap) : capacity(cap) {}

    int get(int key) {
        if (mp.find(key) == mp.end()) return -1;
        moveToFront(key);
        return mp[key]->second;
    }

    void put(int key, int value) {
        if (mp.find(key) != mp.end()) {
            // update existing and move to front
            mp[key]->second = value;
            moveToFront(key);
            return;
        }
        if ((int)dll.size() == capacity) {
            // evict least recently used (back)
            auto node = dll.back();
            mp.erase(node.first);
            dll.pop_back();
        }
        dll.push_front({key, value});
        mp[key] = dll.begin();
    }

    void display() const {
        cout << "Cache state (MRU -> LRU): ";
        for (auto &kv : dll) cout << "[" << kv.first << ":" << kv.second << "] ";
        cout << "\n";
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cout << "LRU Cache Demo\n";
    cout << "Enter cache capacity: ";
    int cap;
    if (!(cin >> cap) || cap <= 0) return 0;

    LRUCache cache(cap);
    cout << "Menu:\n1) Put (key, value)\n2) Get (key)\n3) Display cache\n4) Exit\n";

    while (true) {
        cout << "\nEnter choice: ";
        int choice;
        if (!(cin >> choice)) break;
        if (choice == 4) break;

        if (choice == 1) {
            int k, v;
            cout << "Enter key and value: ";
            cin >> k >> v;
            cache.put(k, v);
            cout << "Inserted/Updated.\n";
        } else if (choice == 2) {
            int k;
            cout << "Enter key: ";
            cin >> k;
            int val = cache.get(k);
            if (val == -1) cout << "Key not found (cache miss).\n";
            else cout << "Value = " << val << " (cache hit).\n";
        } else if (choice == 3) {
            cache.display();
        } else {
            cout << "Invalid choice.\n";
        }
    }

    cout << "Goodbye!\n";
    return 0;
}