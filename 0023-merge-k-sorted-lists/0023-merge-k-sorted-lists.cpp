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
    struct compare{
        bool operator()(ListNode* a, ListNode* b){
            return a->val>b->val;
        }
    };

    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<ListNode*, vector<ListNode*>, compare> minHeap;
        for(ListNode* head:lists){
            if(head!=nullptr){
                minHeap.push(head);
            }               
        }
        ListNode* dummy=new ListNode(0);
        ListNode* curr=dummy;
        while(!minHeap.empty()){
            ListNode* smallest=minHeap.top();
            minHeap.pop();
            curr->next=smallest;
            curr=curr->next;
            if(smallest->next!=nullptr){
                minHeap.push(smallest->next);
            }
        }
        ListNode* result=dummy->next;
        delete dummy;
        return result;
    }
};