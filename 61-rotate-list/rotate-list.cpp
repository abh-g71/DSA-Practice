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
    ListNode* rotateRight(ListNode* head, int k) {
        if(head == NULL || head->next==NULL || k==0) return head;
        ListNode* temp = head ;
        int count = 1;
        int n=0;
        while(temp){
            n++;
            temp = temp->next;
        }
        temp = head;
        k %= n;
        if(k==0) return head;
        int c1 = n-k;
        while(count < c1 && temp->next){
            count++;
            temp = temp->next;
        }
        ListNode* next = temp->next;
        temp->next = NULL;
        temp = next;
        while(temp->next){
            temp = temp->next;
        }
        temp->next = head;
        return next;
        
    }
};