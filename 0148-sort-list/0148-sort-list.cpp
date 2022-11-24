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
    
    ListNode* split(ListNode *head){
        ListNode* t1=head;
        ListNode* t2=head,*prev=nullptr;
        while(t1&&t1->next){
            t1=t1->next->next;
            prev=t2;
            t2=t2->next;
        }
        prev->next=nullptr;
        return t2;
    }
    
    ListNode *merge(ListNode *t1,ListNode *t2){
        ListNode *dummy=new ListNode(0),*t=dummy;
        
        while(t1&&t2)
        {
            if(t1->val < t2->val)
            {   
                dummy->next=t1;
                dummy=dummy->next;
                t1=t1->next;
            }else{
                dummy->next=t2;
                dummy=dummy->next;
                t2=t2->next;
            }
        }
        
        while(t1)
        {
                dummy->next=t1;
                dummy=dummy->next;
                t1=t1->next;
        }
        
        while(t2)
        {
            dummy->next=t2;
                dummy=dummy->next;
                t2=t2->next;
        }
        return t->next;
        
    }
    
    ListNode* sortList(ListNode* head) {
        if(head==nullptr || head->next==nullptr)
            return head;
        ListNode* mid = split(head);
        ListNode *l = sortList(head);
        ListNode *r = sortList(mid);
        return merge(l,r);
    }
};