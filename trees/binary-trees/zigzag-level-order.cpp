class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> result;
        
        if(root == NULL) {
            return result;
        }
        
        queue<TreeNode *> q;
        vector<int> res;
        int level = 0;
        
        q.push(root);
        q.push(NULL);
        
        while(!q.empty()) {
            TreeNode* tmp = q.front();
            q.pop();
            
            if(tmp == NULL) {
                if(!q.empty())  q.push(tmp);
                if(level % 2 == 1) {
                    reverse(res.begin(), res.end());
                }
                result.push_back(res);
                res.erase(res.begin(), res.end());
                ++level;
                continue;
            }
            
            res.push_back(tmp->val);
            
            if(tmp->left) {
                q.push(tmp->left);
            }
            if(tmp->right) {
                q.push(tmp->right);
            }
        }
        
        return result;
    }
};