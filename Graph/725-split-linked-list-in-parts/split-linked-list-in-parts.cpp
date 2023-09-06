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

int count(ListNode* head){
    int c = 0;
    while(head != NULL){
        c++;
        head = head->next;
    }
    return c;
}



public:
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
       

        vector<ListNode*> ans;

    //    if(head == NULL){
    //        return ans;
    //    }

        int c = count(head);
        int l;
        int r;
        if(c <= k){
           l = 1;
        }
        else{
            l = c / k ;
            r = c % k;
        }

        ListNode* temp = head;
        int f = 0;
        int n = k;

        while(n-- ){

          ListNode *ptr = temp;
          int j = 0;
          if(r > 0){
             j = 1;
             r--; 
          }
            
          for(int i = 0; i < l-1 + j; i++){
              ptr = ptr->next;
          }
         if(temp != NULL && ptr != NULL){
          ans.push_back(temp);
          temp = ptr->next;
          ptr->next = NULL;
         }
         else{
             ans.push_back(temp);
         }

        }




        return ans;
    }
};