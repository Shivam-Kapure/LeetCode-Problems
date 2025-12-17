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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* fh = nullptr;
        ListNode* ft = nullptr;

        if(list1 == NULL)
            return list2;
        if(list2 == NULL)
            return list1;

        while(list1 != NULL && list2 != NULL) {
            if(fh == NULL || ft == NULL) {
                if(list1->val <= list2->val) {
                    fh = list1;
                    ft = list1;
                    list1 = list1->next;
                }
                else {
                    fh = list2;
                    ft = list2;
                    list2 = list2->next;
                }
            }
            else if(list1->val <= list2->val) {
                ft->next = list1;
                ft = ft->next;
                list1 = list1->next;
            }
            else {
                ft->next = list2;
                ft = ft->next;
                list2 = list2->next;
            }
        }
        if(list1 == NULL) {
            ft->next = list2;
            ft = ft->next;
        }
        if(list2 == NULL) {
            ft->next = list1;
            ft = ft->next;
        }
        return fh;
    }
};