#ifndef LEETCODE_MAXANCESTORDIFF1026_H
#define LEETCODE_MAXANCESTORDIFF1026_H
#include "iostream"
#include "vector"
#include "queue"

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

using namespace std;

//int maxAncestorDiff(TreeNode* root) {
//    queue<TreeNode*> tree;
//    vector<int> num;
//    tree.push(root);
//    while(!tree.empty()){
//        TreeNode* temp = tree.front();
//        tree.pop();
//        num.emplace_back(temp->val);
//        if(temp->left == nullptr){
//            num.emplace_back(-1);
//        }else
//            tree.push(temp->left);
//        if(temp->right == nullptr)
//            num.emplace_back(-1);
//        else
//            tree.push(temp->right);
//    }
//
//}

// 使用深度优先搜索
int dfs(TreeNode *root, int mi, int ma) {
    if (root == nullptr) {
        return 0;
    }
    int diff = max(abs(root->val - mi), abs(root->val - ma));
    mi = min(mi, root->val);
    ma = max(ma, root->val);
    diff = max(diff, dfs(root->left, mi, ma));
    diff = max(diff, dfs(root->right, mi, ma));
    return diff;
}

int maxAncestorDiff(TreeNode* root) {
    return dfs(root, root->val, root->val);
}


#endif //LEETCODE_MAXANCESTORDIFF1026_H
