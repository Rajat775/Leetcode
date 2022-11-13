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
    ListNode* swapPairs(ListNode* head) {
        
        if(head==nullptr)
            return head;
        
        if(head->next == nullptr)
            return head;
        
        ListNode *t1=head,*d=head->next,*t2=head->next,*prev=nullptr;
        
        while(t1 && t2)
        {
            ListNode * temp1= t1->next->next,*temp2;
            if(temp1!=nullptr)
                temp2=t2->next->next; 
            else
                temp2=nullptr;
            t1->next=t2->next;
            t2->next=t1;
            if(prev)
                prev->next = t2;
            prev=t1;
            t1=temp1;
            t2=temp2;
        }
        return d;
    }
};