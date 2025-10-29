#include <bits/stdc++.h>
using namespace std;

// Definition for singly-linked list node
struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(nullptr) {}
};

// Function to insert node at the end
void insertNode(ListNode*& head, int val) {
    if (!head) {
        head = new ListNode(val);
        return;
    }
    ListNode* temp = head;
    while (temp->next) temp = temp->next;
    temp->next = new ListNode(val);
}

// Function to print the linked list
void printList(ListNode* head) {
    while (head) {
        cout << head->val;
        if (head->next) cout << " -> ";
        head = head->next;
    }
    cout << endl;
}

// Reverse a linked list segment and return new head
ListNode* reverseSegment(ListNode* head, ListNode* tail) {
    ListNode* prev = nullptr;
    ListNode* curr = head;
    ListNode* stop = tail->next; // Stop point (one after tail)
    
    while (curr != stop) {
        ListNode* nextNode = curr->next;
        curr->next = prev;
        prev = curr;
        curr = nextNode;
    }
    return prev; // New head after reversal
}

// Reverse nodes in k-group
ListNode* reverseKGroup(ListNode* head, int k) {
    if (!head || k <= 1) return head;
    
    ListNode dummy(0);
    dummy.next = head;
    ListNode* prevGroupEnd = &dummy;

    while (true) {
        // Find the kth node
        ListNode* kth = prevGroupEnd;
        for (int i = 0; i < k && kth; i++) kth = kth->next;
        if (!kth) break; // Not enough nodes for another group

        // Define the group boundaries
        ListNode* groupStart = prevGroupEnd->next;
        ListNode* nextGroupStart = kth->next;

        // Reverse current k-group
        kth->next = nullptr;
        ListNode* newGroupHead = reverseSegment(groupStart, kth);

        // Connect previous part with reversed group
        prevGroupEnd->next = newGroupHead;
        groupStart->next = nextGroupStart;

        // Move to the next group
        prevGroupEnd = groupStart;
    }

    return dummy.next;
}

// Wrapper to swap pairs (k = 2)
ListNode* swapPairs(ListNode* head) {
    return reverseKGroup(head, 2);
}

// --- Main Function ---
int main() {
    ListNode* head = nullptr;

    // Sample input
    vector<int> vals = {1, 2, 3, 4, 5, 6, 7};
    for (int v : vals) insertNode(head, v);

    cout << "Original list:\n";
    printList(head);

    // Swap nodes in pairs
    cout << "\nAfter swapping in pairs:\n";
    ListNode* swapped = swapPairs(head);
    printList(swapped);

    // Reverse in k-groups (example: k = 3)
    int k = 3;
    cout << "\nAfter reversing in groups of " << k << ":\n";
    ListNode* reversed = reverseKGroup(swapped, k);
    printList(reversed);

    return 0;
}
