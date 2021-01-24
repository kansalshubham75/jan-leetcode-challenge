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
    ListNode* merge(ListNode* l1,ListNode* l2){
        ListNode* dum=new ListNode(-1);
        ListNode* curr=dum;
        while(l1 || l2){
            int v1=l1?l1->val:1e9,v2=l2?l2->val:1e9;
            if(v1<v2){
                curr->next=l1;
                l1=l1->next;
            }else{
                curr->next=l2;
                l2=l2->next;
            }
            curr=curr->next;
        }
        curr=dum->next;
        dum->next=NULL;
        delete dum;
        return curr;
    }
    ListNode* helper(vector<ListNode*>& lists,int s,int e){
        if(s==e)return lists[s];
        int mid=(s+e)>>1;
        auto l=helper(lists,s,mid);
        auto r=helper(lists,mid+1,e);
        return merge(l,r);
    }
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        int n=lists.size();
        if(!n)return NULL;
        return helper(lists,0,n-1);
    }
};