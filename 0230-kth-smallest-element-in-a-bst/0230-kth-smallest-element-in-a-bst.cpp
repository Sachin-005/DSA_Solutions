/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int small=-1;
    void inorder(TreeNode* root, int& counter, int k){
        if(root == nullptr || counter>=k) return;

        inorder(root->left,counter,k);
        counter++;
        if(counter == k){
            small = root->val;
            return;

        }
        inorder(root->right,counter,k);
    }
    int kthSmallest(TreeNode* root, int k) {
        int counter=0;
        inorder(root,counter,k);
        return small;

    }
};