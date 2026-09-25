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
    void reorderList(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head;
        while(fast && fast->next){
            slow= slow->next;
            fast = fast->next->next;
        }
        ListNode*  prev = NULL;
        ListNode* curr = slow->next;
        slow->next = NULL;
       

        while(curr){
             ListNode* next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }

      ListNode* first = head;
      ListNode* second = prev;

      while(first && second){
        ListNode* next1 = first->next;
        ListNode* next2 = second->next;

        first->next = second;
        second->next = next1;

        first = next1;
        second = next2;
      }
        
    }
};