#include <bits/stdc++.h>
using namespace std;

class Node {
public:
    int data;
    Node* next;
    Node(int val) {
        data = val;
        next = nullptr;
    }
};

// Insert at end
void insertAtEnd(Node*& head, int val) {
    Node* newNode = new Node(val);
    if (!head) {
        head = newNode;
        return;
    }
    Node* temp = head;
    while (temp->next)
        temp = temp->next;
    temp->next = newNode;
}

// Print linked list
void printList(Node* head) {
    while (head) {
        cout << head->data << " -> ";
        head = head->next;
    }
    cout << "NULL\n";
}

// Reverse linked list (Iterative)
Node* reverseList(Node* head) {
    Node* prev = nullptr;
    Node* curr = head;
    Node* next = nullptr;
    while (curr) {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    return prev;
}

// Find middle of linked list (Tortoise-Hare)
Node* findMiddle(Node* head) {
    if (!head) return nullptr;
    Node* slow = head;
    Node* fast = head;
    while (fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
}

// Detect cycle using Floyd's algorithm
bool detectCycle(Node* head) {
    Node* slow = head;
    Node* fast = head;
    while (fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;
        if (slow == fast) return true;  // cycle found
    }
    return false;
}

// Remove cycle if present
void removeCycle(Node* head) {
    Node* slow = head;
    Node* fast = head;

    // Detect cycle
    bool hasCycle = false;
    while (fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;
        if (slow == fast) {
            hasCycle = true;
            break;
        }
    }

    if (!hasCycle) return;

    // Move one pointer to head and move both at same speed
    slow = head;
    Node* prev = nullptr;
    while (slow != fast) {
        prev = fast;
        slow = slow->next;
        fast = fast->next;
    }

    // Break the cycle
    prev->next = nullptr;
}

int main() {
    Node* head = nullptr;

    // Create Linked List
    for (int i = 1; i <= 6; i++)
        insertAtEnd(head, i);

    cout << "Original List:\n";
    printList(head);

    // Find Middle
    Node* mid = findMiddle(head);
    cout << "\nMiddle Element: " << (mid ? to_string(mid->data) : "None") << endl;

    // Reverse List
    head = reverseList(head);
    cout << "\nReversed List:\n";
    printList(head);

    // Create a cycle manually for testing
    cout << "\nCreating cycle for testing...\n";
    head->next->next->next = head->next; // cycle created

    cout << "Cycle Detected? " << (detectCycle(head) ? "Yes" : "No") << endl;

    // Remove cycle
    removeCycle(head);
    cout << "Cycle Removed.\n";
    cout << "Cycle Detected? " << (detectCycle(head) ? "Yes" : "No") << endl;

    // Final List
    cout << "\nFinal List after removing cycle:\n";
    printList(head);

    return 0;
}
