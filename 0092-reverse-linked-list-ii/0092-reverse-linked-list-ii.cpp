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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if(!head||left==right) return head;
        ListNode dummy(0);
        dummy.next=head;
        ListNode* left_prev=&dummy;
        ListNode* curr=head;

        for(int i=0; i<left-1; ++i){
            left_prev=left_prev->next;
            curr=curr->next;
        }

        ListNode* tail=curr;
        ListNode* prev=nullptr;

        for(int i=0; i<(right-left+1); ++i){
            ListNode* next_node=curr->next;
            curr->next=prev;
            prev=curr;
            curr=next_node;
        }
        left_prev->next=prev;
        tail->next=curr;

        return dummy.next;
    }
};