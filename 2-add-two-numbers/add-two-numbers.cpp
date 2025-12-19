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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* dummy = new ListNode();
        ListNode* temp = dummy;
        ListNode* temp1 = l1;
        ListNode* temp2 = l2;
        int carry = 0;

        while(temp1 != NULL || temp2 != NULL || carry != 0) {
            int x = (temp1 != NULL) ? temp1->val : 0;
            int y = (temp2 != NULL) ? temp2->val : 0;
            int sum = x + y + carry;
            carry = sum/10;
            int digit = sum % 10;

            ListNode* newNode = new ListNode(digit);
            temp->next = newNode;
            if(temp1 != NULL)
                temp1 = temp1->next;
            if(temp2 != NULL)
                temp2 = temp2->next;
            temp = temp->next;
        }
        return dummy->next;
    }
};