#include <bits/stdc++.h>
using namespace std;

// Node structure for Doubly Linked List
struct Node {
    int key, value;
    Node* prev;
    Node* next;
    Node(int k, int v) : key(k), value(v), prev(NULL), next(NULL) {}
};

class LRUCache {
private:
    int capacity;
    unordered_map<int, Node*> cache; // key -> node
    Node* head; // Most recently used (MRU)
    Node* tail; // Least recently used (LRU)

    // Helper: Add node right after head
    void addNode(Node* node) {
        node->next = head->next;
        node->prev = head;
        head->next->prev = node;
        head->next = node;
    }

    // Helper: Remove a node
    void removeNode(Node* node) {
        Node* prevNode = node->prev;
        Node* nextNode = node->next;
        prevNode->next = nextNode;
        nextNode->prev = prevNode;
    }

    // Helper: Move a node to the front (MRU position)
    void moveToHead(Node* node) {
        removeNode(node);
        addNode(node);
    }

    // Helper: Remove the least recently used node (tail->prev)
    Node* popTail() {
        Node* node = tail->prev;
        removeNode(node);
        return node;
    }

public:
    // Constructor
    LRUCache(int capacity) {
        this->capacity = capacity;
        head = new Node(0, 0);
        tail = new Node(0, 0);
        head->next = tail;
        tail->prev = head;
    }

    // Get the value of a key
    int get(int key) {
        if (cache.find(key) == cache.end()) return -1;

        Node* node = cache[key];
        moveToHead(node);
        return node->value;
    }

    // Put key-value pair into cache
    void put(int key, int value) {
        if (cache.find(key) != cache.end()) {
            Node* node = cache[key];
            node->value = value;
            moveToHead(node);
        } else {
            Node* node = new Node(key, value);
            cache[key] = node;
            addNode(node);

            if ((int)cache.size() > capacity) {
                Node* tailNode = popTail();
                cache.erase(tailNode->key);
                delete tailNode;
            }
        }
    }

    // Display current cache state (for understanding)
    void display() {
        Node* curr = head->next;
        cout << "Cache state (MRU -> LRU): ";
        while (curr != tail) {
            cout << "[" << curr->key << ":" << curr->value << "] ";
            curr = curr->next;
        }
        cout << "\n";
    }
};

// Driver code
int main() {
    LRUCache lru(3); // Cache capacity = 3

    lru.put(1, 10);
    lru.put(2, 20);
    lru.put(3, 30);
    lru.display();

    cout << "Accessing key 2 -> " << lru.get(2) << endl;
    lru.display();

    cout << "Inserting key 4, value 40" << endl;
    lru.put(4, 40); // Evicts key 1 (least recently used)
    lru.display();

    cout << "Accessing key 1 -> " << lru.get(1) << endl; // returns -1
    cout << "Accessing key 3 -> " << lru.get(3) << endl; // returns 30
    lru.display();

    return 0;
}
