/*
You are given two non-empty linked lists representing two non-negative integers. 
The digits are stored in reverse order, and each of their nodes contains a single 
digit. Add the two numbers and return the sum as a linked list.
You may assume the two numbers do not contain any leading zero, except the number 0 itself.
*/
#include <iostream>
 struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
 
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* sum = new ListNode(0);
        ListNode* temp = sum;
        int carry = 0, total;
        while(l1||l2||carry)
        {
            total = (l1 ? l1->val : 0) + (l2 ? l2->val : 0) + carry;
            carry= total/10;
            temp->next = new ListNode(total%10);
            temp = temp->next;
            if(l1)l1=l1->next;
            if(l2)l2= l2->next;
        }
        ListNode* result = sum->next;
        delete sum;
        return result;
    }
};

ListNode* reverseList(ListNode* head) {
    ListNode* prev = nullptr;
    ListNode* curr = head;
    while(curr)
    {
        ListNode* next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    return prev;
}

void freeList(ListNode* head) {
    while (head) {
        ListNode* next = head->next;
        delete head;
        head = next;
    }
}

int main(){
    ListNode* l1 = new ListNode(12);
    l1->next = new ListNode(4);
    l1->next->next = new ListNode(13);
    ListNode* l2 = new ListNode(25);
    l2->next = new ListNode(6);
    l2->next->next = new ListNode(4);
    Solution sol;
    ListNode* sum = sol.addTwoNumbers(l1, l2);
    l1 = reverseList(l1);
    l2 = reverseList(l2);
    sum = reverseList(sum);
    std::cout << "l1: "; 
    while(l1)
    {
        std::cout << l1->val << "->";
        l1 = l1->next;
    }
    std::cout << "NULL\n";
    std::cout << "l2: "; 
    while(l2)
    {
        std::cout << l2->val << "->";
        l2 = l2->next;
    }
    std::cout << "NULL\n";
    std::cout << "sum: ";
    while(sum)
    {
        std::cout << sum->val << "->";
        sum = sum->next;
    }
    std::cout << "NULL\n";
    return 0;
}