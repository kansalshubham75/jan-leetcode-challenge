/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode(int x) { val = x; }
 * }
 */
class Solution {
    public ListNode mergeTwoLists(ListNode l1, ListNode l2) {
        if(l1==null)
            return l2;
        if(l2==null)
            return l1;
        ListNode p1=l1;
        ListNode p2=l2;
        ListNode head=null;
        ListNode h=null;
        while(p1!=null && p2!=null){
            if(p1.val<p2.val){
                if(h==null)
                {
                    head=l1;
                    h=l1;
                }else{
                    h.next=p1;
                    h=p1;
                }
                p1=p1.next;
                h.next=null;
                
            }else{
                if(h==null)
                {
                    h=l2;
                    head=l2;
                }else{
                    h.next=p2;
                    h=p2;
                }
                p2=p2.next;
                h.next=null;
            }
        }
        if(p1!=null){
            h.next=p1;
        }
        if(p2!=null){
            h.next=p2;
           
        }
        return head;
    }
}