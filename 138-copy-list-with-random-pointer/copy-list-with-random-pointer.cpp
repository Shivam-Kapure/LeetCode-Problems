/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if(head == NULL)
            return NULL;

        Node* temp1 = head;

        while(temp1 != NULL) {
            Node* newNode = new Node(temp1->val);
            newNode->next = temp1->next;
            temp1->next = newNode;
            temp1 = temp1->next->next;
        }

        Node* temp2 = head;
        while(temp2 != NULL) {
            if(temp2->random != NULL) {
                temp2->next->random = temp2->random->next;
            }
            else {
                temp2->next->random = NULL;
            }
            temp2 = temp2->next->next;
        }

        Node* ogHead = head;
        Node* copyHead = head->next;
        Node* copyTemp = copyHead;
        while(ogHead != NULL) {
            ogHead->next = ogHead->next->next;

            if(copyTemp->next != NULL) {
                copyTemp->next = copyTemp->next->next;
            }
            
            copyTemp = copyTemp->next;
            ogHead = ogHead->next;
        }
        return copyHead;
    }
};