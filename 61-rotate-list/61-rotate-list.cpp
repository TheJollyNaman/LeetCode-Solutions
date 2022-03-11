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
    ListNode* rotateRight(ListNode* head, int k) {
        int len=1;
        ListNode* temp = head;
        
        if(head==NULL){
            return head;
        }
        
        while(temp->next!=NULL){
            len++;
            temp=temp->next;
        }
        
        k=k%len;
        if(k==0){
            return head;
        }
        
        int templen=len;
        templen=len-k;
        
        temp=head;
        while(templen-1){
            temp=temp->next;
            templen--;
        }
        ListNode* nex=temp->next;
        temp->next=NULL;
        ListNode* newhead=nex;
        while(nex->next!=NULL){
            nex=nex->next;
        }
        nex->next=head;
        return newhead;
        
    }
};