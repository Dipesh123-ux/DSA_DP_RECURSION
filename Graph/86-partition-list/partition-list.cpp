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
    ListNode* partition(ListNode* head, int x) {
        vector<int> v1, v2;
        ListNode *ptr = head;
        while(ptr != NULL){
            if(ptr->val < x){
                v1.push_back(ptr->val);
            }
            else{
                v2.push_back(ptr->val);
            }
            ptr = ptr->next;
        }

        reverse(v1.begin(),v1.end());
        reverse(v2.begin(),v2.end());

            ListNode *fina = NULL;
     
        for(int i : v2){
             ListNode* newNode = new ListNode(i);
            newNode->next = fina;
            fina = newNode;
        }

           for(int i : v1){
            ListNode* newNode = new ListNode(i);
            newNode->next = fina;
            fina = newNode;
        }


        return fina;
    }
};