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
TreeNode *dummy=new TreeNode(-1);
	TreeNode *t=dummy;
public:
	void helper(TreeNode *root){
		if(root){
			helper(root->left);
			t->right=root;
			root->left=nullptr;
			t=root;
			helper(root->right);
		}
	}
	TreeNode* increasingBST(TreeNode* root) {
		 helper(root);
		return dummy->right;
	}
};