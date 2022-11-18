/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        
        ListNode *f=headA,*s=headB;
        int c1=0,c2=0;
        while(f){
            c1++;
            f=f->next;
        }
        while(s)
        {
            c2++;
            s=s->next;
        }
        
        f=headA,s=headB;
        
        int c = abs(c1-c2);
        if(c1>c2)
        {
            while(c--)f=f->next;
        }
        else{
            while(c--)s=s->next;
        }
        while(s)
        {
            if(s==f)
                return s;
            s=s->next;
            f=f->next;
        }
        return s;
    }
};