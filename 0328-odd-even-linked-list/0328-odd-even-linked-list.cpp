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
    ListNode* oddEvenList(ListNode* head) {
    if (!head || !head->next) return head;
       
       ListNode* curr = head;
       bool isOdd=true;

       ListNode* oddDummy = new ListNode(-1) , *odd=oddDummy;
       ListNode* evenDummy = new ListNode(-1), *even=evenDummy;
       while(curr){
            ListNode* temp = curr;
            curr = curr->next;
            temp->next = nullptr;

        if(isOdd){
            odd->next = temp;
            odd = temp;
       }
       else{
        even->next = temp;
        even = temp;
       }
        isOdd = !isOdd;
    }
    odd->next = evenDummy->next;

    return oddDummy->next;
    }
};