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
    ListNode* sortList(ListNode* head) {
        vector<int> arr;
        ListNode* temp= head;
        while(head){
            arr.push_back(head->val);
            head=head->next;
        }
        sort(arr.begin(),arr.end());
        int i=0;
        head=temp;
        while(temp){
            temp->val = arr[i++];
            temp=temp->next;
        }
        return head;
    }
};