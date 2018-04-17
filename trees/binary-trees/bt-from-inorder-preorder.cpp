class Solution {
public: 
    TreeNode* helper(vector<int>& preorder, int pl, int pr, vector<int>& inorder, int il, int ir) {
        if(pl >= pr || il >= ir) 
            return NULL;
        
        auto f = find(inorder.begin()+il, inorder.begin()+ir, preorder[pl]);
        int pos = f - inorder.begin()-il;
        
        TreeNode* root = new TreeNode(preorder[pl]);
        
        root->left = helper(preorder, pl+1, pl+pos+1, inorder, il, il+pos);
        root->right = helper(preorder, pl+pos+1, pr, inorder, il+pos+1, ir);
        
        return root;
    }
    
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        //preorder - root, left, right
        //inorder  - left, root, right
        
        if(preorder.size() != inorder.size())
            return NULL;
        
        return helper(preorder, 0, preorder.size(), inorder, 0, inorder.size());
    }
};