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
    int func(TreeNode* node, int& maxi){
        if(node==NULL){
            return 0;
        }
        
        int leftSum = max( func(node->left,maxi) , 0 );
        int rightSum = max( func(node->right,maxi) , 0 );
        
        maxi=max(maxi,node->val+leftSum+rightSum);
        
        return (node->val) + max(leftSum,rightSum);
    }
    
    
    int maxPathSum(TreeNode* root) {
        int maxi = INT_MIN;
        func(root,maxi);
        return maxi;
    }
};