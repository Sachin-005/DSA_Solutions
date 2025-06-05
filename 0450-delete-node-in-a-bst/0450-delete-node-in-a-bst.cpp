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
    TreeNode* helper(TreeNode* root){
        if(!root->left && !root->right){
            delete root;
            return nullptr;
        }
        if(!root->left){
            TreeNode* newRoot = root->right;
        delete root;
        return newRoot;;
        }
         if(!root->right){
          TreeNode* newRoot = root->left;
        delete root;
        return newRoot;
        }
        TreeNode* rightChild = root->right;
        TreeNode* lastChild = findLastRight(root->left);
        lastChild->right = rightChild;;
        return root->left;


    }
    TreeNode* findLastRight(TreeNode* root){
        while(root->right){
            root=root->right;
        }
        return root;
    }
    TreeNode* deleteNode(TreeNode* root, int key) {
        
        if(!root) return root;
        if(root->val == key){
            return helper(root);
        }
        TreeNode* dummy = root;
        while(root){
           if(key < root->val ){
            if(root->left!= nullptr && root->left->val == key){
                root->left = helper(root->left);
                break;
            }
            else{
                root = root->left;
            }
           }
           else{
            if(root->right!=nullptr && root->right->val == key){
                root->right = helper(root->right);
                break;
            }
            else{
                root = root->right;
            }
           }
        }
        return dummy;
    }
};