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
    ListNode* reverseBetween(ListNode* head, int l, int r) {
        if(l == r){
            return head;
        }
        ListNode *curr = head , *prev = NULL;
        int i = 0;
        while(curr != NULL && (i < l-1)){
            prev = curr;
            curr = curr->next;
            i++;
        }

        ListNode *lastNodeOfFirstPart = prev;
        ListNode *lastNodeOfSubList = curr;

        ListNode* next = NULL;

        i = 0;

        while(curr != NULL && (i < r-l+1)){
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
            i++;
        }

        if(lastNodeOfFirstPart != NULL){
            lastNodeOfFirstPart->next = prev;
        }
        else{
            head = prev;
        }

        lastNodeOfSubList->next = curr;

       
        return head;
    }
};