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
        if(head==nullptr || head->next==nullptr)
            return head;
        ListNode *prev=new ListNode(-1),*t=prev,*t1=head,*t2=head->next;
        while(t1 && t2)
        {
            ListNode* t3 = t1->next->next;
            ListNode*t4;
            if(t3!=nullptr)
                t4=t2->next->next;
            else
                t4=nullptr;
            t2->next=t1;
            t1->next=t3;
            prev->next=t2;
            prev=prev->next->next;
            t1=t3;
            t2=t4;
        }
        return t->next;
    }
};