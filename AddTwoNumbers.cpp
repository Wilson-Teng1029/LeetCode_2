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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* head = l1 ;
        while (l1 != NULL || l2 != NULL) {
            if (l1 != NULL && l2 != NULL )
                l1->val += l2->val ;
            else if ( l1 == NULL && l2 != NULL ) {
                l1 = new ListNode ; // ->next
                //l1 = l1->next ;
                l1->val = l2->val ;
            }
            else if ( l2 == NULL && l1 != NULL ) {
                l1->val = l1->val ;
            }
            
            if ( l1->val > 9 ) {
                l1->val -= 10 ;
                if ( l1->next != NULL) 
                    l1->next->val += 1 ;
                else if ( l1->next == NULL ) {
                    l1->next = new ListNode ;
                    l1->next->val += 1 ;
                }
            }
            if ( l2!=NULL ) {
                l2=l2->next ;
            }
            if ( l1!=NULL ) {
                if (l1->next == NULL && l2 != NULL ) {
                    l1->next = new ListNode ;
                    l1 = l1->next ;
                }
                else 
                    l1=l1->next ;
            }
               

        }
        return head ;
    }
};
