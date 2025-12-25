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
class mycompare {
public:
    bool operator() (ListNode* a, ListNode* b) {
        return (a->val > b->val);
    }
};

class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        ListNode* dummy = new ListNode();
        ListNode* temp = dummy;
        priority_queue<ListNode*, vector<ListNode*>, mycompare> pq;
        
        for(int i = 0; i < lists.size(); i++) {
            if(lists[i] != NULL) {
                pq.push(lists[i]);
            }
        }

        while(!pq.empty()) {
            auto least = pq.top();
            pq.pop();
            temp->next = least;
            temp = temp->next;
            if(least->next != NULL) {
                pq.push(least->next);
            }
        }
        return dummy->next;
    }
};