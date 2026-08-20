class Solution {
public:
    Node* flatten(Node* head) {

        if(head == NULL)
            return head;

        Node* temp = head;

        while(temp) {

            if(temp->child) {

                Node* next = temp->next;

                // Attach child list
                temp->next = flatten(temp->child);

                // Set prev pointer
                temp->next->prev = temp;

                // Remove child pointer
                temp->child = NULL;

                // Go to the end of child list
                Node* tail = temp;

                while(tail->next) {
                    tail = tail->next;
                }

                // Attach original next
                if(next != NULL) {
                    tail->next = next;
                    next->prev = tail;
                }
            }

            temp = temp->next;
        }

        return head;
    }
};