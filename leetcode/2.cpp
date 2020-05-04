/* add two numbers
 * given two non-empty linked lists representing two non-negative integers, return a linked list representing the sum of the two integers
 * digits are stored in reverse order (e.g. 1->0->3 represents the number 301)
 */

/**
 * Definition for singly-linked list.
 */
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int s = l1->val + l2->val;
        bool carry = s >= 10; 
        ListNode* c = new ListNode(s%10);
        ListNode* o = c;
        l1 = l1->next;
        l2 = l2->next;
        while(l1 || l2) {
            s = l1 && l2 ? l1->val + l2->val : (l1 ? l1->val : l2->val);
            s += (int)carry;
            carry = s >= 10;
            ListNode* a = new ListNode(s%10);
            c->next = a;
            c = c->next;
            if(l1) l1 = l1->next;
            if(l2) l2 = l2->next;
        }
        if(carry) {
            ListNode* a = new ListNode(1);
            c->next = a;
        }
        return o;
    }
};
