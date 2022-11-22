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
    
    #define pp pair<int,ListNode*>
    
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        ListNode *dummy=new ListNode(0),*t=dummy;
        priority_queue<pp,vector<pp>,greater<pp>>p;
        for(int i=0;i<lists.size();i++)
        {
            ListNode*temp=lists[i];
            if(temp)
            p.push({temp->val,temp});
        }
        
        while(!p.empty())
        {
            pair<int,ListNode*> tt= p.top();
            p.pop();
            ListNode* temp = tt.second->next;
            t->next=tt.second;
            t=t->next;
            if(temp)
                p.push({temp->val,temp});
        }
        return dummy->next;
    }
};