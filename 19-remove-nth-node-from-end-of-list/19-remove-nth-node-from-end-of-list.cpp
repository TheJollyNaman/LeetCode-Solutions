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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
       ListNode * start = new ListNode();
        start->next = head;
        ListNode * fast = start;
        ListNode * slow = start;
        
        for(int i=0 ; i<n ; i++)
            fast=fast->next;
        
        while(fast->next!=NULL){
            fast=fast->next;
            slow=slow->next;
        }
        //take pointer delnode=start->next;
        slow->next=slow->next->next;
        //here you can delete delnode;
    return start->next; 
    }
};

