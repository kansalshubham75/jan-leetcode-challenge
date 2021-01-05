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
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode* dum=new ListNode(-101);
        ListNode* curr=head;
        ListNode* nh=dum;
        while(curr){
            ListNode* temp=curr->next;
            int cnt=0;
            while(temp && temp->val==curr->val){
                cnt++;
                temp=temp->next;
            }
            if(!cnt){
                nh->next=new ListNode(curr->val);
                nh=nh->next;
            }
            curr=temp;
        }
        return dum->next;
    }
};