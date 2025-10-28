#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node* prev;
    Node* child;

    Node(int val) : data(val), next(nullptr), prev(nullptr), child(nullptr) {}
};

// -------------------------------------
// Helper: Connect nodes linearly
// -------------------------------------
Node* createList(vector<int> vals) {
    if (vals.empty()) return nullptr;
    Node* head = new Node(vals[0]);
    Node* curr = head;
    for (int i = 1; i < vals.size(); ++i) {
        curr->next = new Node(vals[i]);
        curr->next->prev = curr;
        curr = curr->next;
    }
    return head;
}

// -------------------------------------
// Flatten multilevel doubly linked list
// -------------------------------------
Node* flattenList(Node* head) {
    if (!head) return nullptr;
    Node* curr = head;
    stack<Node*> stk;

    while (curr) {
        if (curr->child) {
            // If next exists, push it for later
            if (curr->next) stk.push(curr->next);
            // Connect child as next
            curr->next = curr->child;
            curr->child->prev = curr;
            curr->child = nullptr;
        } else if (!curr->next && !stk.empty()) {
            // Pop a saved next and reconnect
            Node* temp = stk.top();
            stk.pop();
            curr->next = temp;
            temp->prev = curr;
        }
        curr = curr->next;
    }
    return head;
}

// -------------------------------------
// Convert to circular doubly linked list
// -------------------------------------
Node* makeCircular(Node* head) {
    if (!head) return nullptr;
    Node* tail = head;
    while (tail->next)
        tail = tail->next;
    // Connect head and tail
    tail->next = head;
    head->prev = tail;
    return head;
}

// -------------------------------------
// Display circular doubly linked list
// -------------------------------------
void displayCircular(Node* head, int limit = 20) {
    if (!head) return;
    Node* temp = head;
    int count = 0;
    cout << "Circular Doubly Linked List:\n";
    do {
        cout << temp->data << " ⇄ ";
        temp = temp->next;
        count++;
        if (count > limit) break; // prevent infinite loop
    } while (temp != head);
    cout << "(back to head)\n";
}

// -------------------------------------
// MAIN
// -------------------------------------
int main() {
    // Create main list: 1 ⇄ 2 ⇄ 3 ⇄ 4
    Node* head = createList({1, 2, 3, 4});

    // Child list for node 3: 7 ⇄ 8 ⇄ 9
    Node* child1 = createList({7, 8, 9});

    // Child list for node 8: 11 ⇄ 12
    Node* child2 = createList({11, 12});

    // Connect children
    head->next->next->child = child1;  // 3 → 7
    child1->next->child = child2;      // 8 → 11

    cout << "Flattening the multilevel doubly linked list...\n";
    Node* flatHead = flattenList(head);

    cout << "\nConverting flattened list to circular form...\n";
    Node* circularHead = makeCircular(flatHead);

    cout << "\nFinal Flattened + Circular Doubly Linked List:\n";
    displayCircular(circularHead);

    return 0;
}
