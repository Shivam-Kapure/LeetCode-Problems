/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

class Solution {
public:
    int lengthofLL(ListNode* head) {
        int length = 0;
        ListNode* temp = head;
        while(temp != NULL) {
            temp = temp->next;
            length++;
        }
        return length;
    }
    
    ListNode* reverseKGroup(ListNode* head, int k, int length) {
        if(length < k) {
            return head;
        }
        ListNode* prev = nullptr;
        ListNode* curr = head;
        ListNode* next = nullptr;
        int count = 0;

        while(curr != NULL && count < k) {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
            count++;
        }

        if(next != NULL) {
            head->next = reverseKGroup(next, k, (length - k));
        }
        return prev;
    }

    ListNode* reverseKGroup(ListNode* head, int k) {
        int length = lengthofLL(head);
        return reverseKGroup(head, k, length);
    }
};