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
    int deepestLeavesSum(TreeNode* root) {
        int res = 0 , i;
        queue<TreeNode*> que;
        que.push(root);
        while(que.size()){
            for(i = que.size()-1 , res=0 ; i>=0; i--){
                TreeNode* curr = que.front();
                que.pop();
                res+=curr->val;
                if(curr->left!=NULL)
                    que.push(curr->left);
                if(curr->right!=NULL)
                    que.push(curr->right);
            }
        }
        return res;
    }
};