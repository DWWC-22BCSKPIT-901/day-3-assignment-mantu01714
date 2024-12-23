//Q.2: Merge Two Sorted Linked Lists

#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(nullptr) {}
};

ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
    if (!list1) return list2;
    if (!list2) return list1;
    if (list1->val <= list2->val) {
        list1->next = mergeTwoLists(list1->next, list2);
        return list1;
    } else {
        list2->next = mergeTwoLists(list1, list2->next);
        return list2;
    }
}

void printList(ListNode* head) {
    while (head != nullptr) {
        cout << head->val << " ";
        head = head->next;
    }
}

ListNode* createList(int n) {
    ListNode* head = nullptr;
    ListNode* tail = nullptr;
    for (int i = 0; i < n; i++) {
        int val;
        cin >> val;
        ListNode* newNode = new ListNode(val);
        if (!head) {
            head = newNode;
            tail = newNode;
        } else {
            tail->next = newNode;
            tail = newNode;
        }
    }
    return head;
}

int main() {
    int n1, n2;
    cout << "Enter number of elements in list1: ";
    cin >> n1;
    cout << "Enter elements of list1 in sorted order: ";
    ListNode* list1 = createList(n1);

    cout << "Enter number of elements in list2: ";
    cin >> n2;
    cout << "Enter elements of list2 in sorted order: ";
    ListNode* list2 = createList(n2);

    ListNode* mergedList = mergeTwoLists(list1, list2);
    cout << "Merged sorted list: ";
    printList(mergedList);
    return 0;
}
