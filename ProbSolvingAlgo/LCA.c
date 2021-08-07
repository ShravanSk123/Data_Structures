// Lowest Common Ancestor in binary tree of two nodes p and q
// Using recursion
// Leetcode problem -- https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-tree/

struct TreeNode* lowestCommonAncestor(struct TreeNode* root, struct TreeNode* p, struct TreeNode* q) {
    if(!root) return NULL;
    if(root->val == p->val || root->val == q->val) return root;
    
    struct TreeNode* l = lowestCommonAncestor(root->left, p, q);
    struct TreeNode* r = lowestCommonAncestor(root->right, p, q);
    
    if(l && r) return root;
    if(l) return l;
    return r;
}

// Time complexity is O(n)
