#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node *next, *prev, *random;
    Node(int val) : data(val), next(nullptr), prev(nullptr), random(nullptr) {}
};

// Function to print list (for verification)
void printList(Node* head) {
    Node* temp = head;
    cout << "List: \n";
    while (temp) {
        cout << "Data: " << temp->data;
        if (temp->prev) cout << ", Prev: " << temp->prev->data;
        else cout << ", Prev: NULL";
        if (temp->next) cout << ", Next: " << temp->next->data;
        else cout << ", Next: NULL";
        if (temp->random) cout << ", Random: " << temp->random->data;
        else cout << ", Random: NULL";
        cout << "\n";
        temp = temp->next;
    }
    cout << "----------------------------------\n";
}

// Function to clone doubly linked list with random pointers
Node* cloneList(Node* head) {
    if (!head) return nullptr;

    // Step 1: Insert cloned nodes after every original node
    Node* curr = head;
    while (curr) {
        Node* copy = new Node(curr->data);
        copy->next = curr->next;
        copy->prev = curr;
        curr->next = copy;
        if (copy->next) copy->next->prev = copy;
        curr = copy->next;
    }

    // Step 2: Set random pointers for copied nodes
    curr = head;
    while (curr) {
        if (curr->random)
            curr->next->random = curr->random->next;
        curr = curr->next->next;
    }

    // Step 3: Separate the two lists
    curr = head;
    Node* clonedHead = head->next;
    while (curr) {
        Node* copy = curr->next;
        curr->next = copy->next;
        if (copy->next)
            copy->next->prev = curr;
        if (copy->next)
            copy->next = copy->next->next;
        curr = curr->next;
    }

    return clonedHead;
}

// Driver Code
int main() {
    // Create sample doubly linked list with random pointers
    Node* head = new Node(1);
    Node* n2 = new Node(2);
    Node* n3 = new Node(3);
    Node* n4 = new Node(4);

    head->next = n2; n2->prev = head;
    n2->next = n3; n3->prev = n2;
    n3->next = n4; n4->prev = n3;

    // Setting random pointers
    head->random = n3;   // 1 -> 3
    n2->random = head;   // 2 -> 1
    n3->random = n4;     // 3 -> 4
    n4->random = n2;     // 4 -> 2

    cout << "Original:\n";
    printList(head);

    Node* clonedHead = cloneList(head);

    cout << "Cloned:\n";
    printList(clonedHead);

    return 0;
}
