class Solution {
public:
    bool findTarget(TreeNode* root, int k) {
        vector<int> inorderList;
        inorder(root, inorderList); 
        int left = 0, right = inorderList.size() - 1;
        while (left < right) {
            int sum = inorderList[left] + inorderList[right];
            if (sum == k) return true;
            else if (sum < k) left++;
            else right--;
        }
        return false;
    }

private:
    void inorder(TreeNode* node, vector<int>& result) {
        if (!node) return;
        inorder(node->left, result);
        result.push_back(node->val);
        inorder(node->right, result);
    }
};
