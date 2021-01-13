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
        ListNode* dum=new ListNode(-1);
        ListNode* curr=dum;
        int c=0;
        while(l1 || l2){
            int v1=l1?l1->val:0,v2=l2?l2->val:0;
            l1=l1?l1->next:l1;
            l2=l2?l2->next:l2;
            int sum=v1+v2+c;
            c=sum/10;
            curr->next=new ListNode(sum%10);
            curr=curr->next;
        }
        if(c)curr->next=new ListNode(c);
        return dum->next;
    }
};