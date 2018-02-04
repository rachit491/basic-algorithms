/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

vector<TreeNode*> splitBST(TreeNode* root, int V) {
    vector<TreeNode *> vec(2, NULL);
    
    if(root == NULL)
        return vec;
    
    if(root->val > V) {
        vec[1] = root;
        auto root2 = splitBST(root->left, V);
        root->left = root2[1];
        vec[0] = root2[0];
    } else {
        vec[0] = root;
        auto root2 = splitBST(root->right, V);
        root->right = root2[0];
        vec[1] = root2[1];
    }
    
    return vec;
}