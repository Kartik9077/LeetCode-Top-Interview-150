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
   bool check(TreeNode* p,TreeNode* q){
    if(p==nullptr&&q==nullptr)return 1;
    if(p==nullptr||q==nullptr)return 0;
    return p->val==q->val &&check(p->right,q->right)&&check(p->left,q->left);
   }
    bool isSameTree(TreeNode* p, TreeNode* q) {
        return check(p,q);
    }
};