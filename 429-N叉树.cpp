#include<iostream>
#include <vector>

using namespace std;

class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};

/*
class Solution {
public:
    vector<vector<int>> levelOrder(Node* root) {
        vector<vector<int>> res;
        if(root == nullptr)
            return res;
        vector<Node*> temp;
        temp.emplace_back(root);
        while(temp.size() != 0){
            size_t size = temp.size();
            vector<int> col_num;
            for(int i = 0;i < size; i++){
                col_num.emplace_back(temp[0]->val);
                Node* node = temp[0];
                for(int j = 0; j < node->children.size(); j++){
                    temp.emplace_back(temp[0]->children[j]);
                }
                temp.erase(temp.begin());
            }
            res.emplace_back(col_num);
        }
        return res;
    }
};
*/
class Solution {
public:
    vector<vector<int>> levelOrder(Node* root) {
        if (!root) {
            return {};
        }

        vector<vector<int>> ans;
        queue<Node*> q;
        q.push(root);

        while (!q.empty()) {
            int cnt = q.size();
            vector<int> level;
            for (int i = 0; i < cnt; ++i) {
                Node* cur = q.front();
                q.pop();
                level.push_back(cur->val);
                for (Node* child: cur->children) {
                    q.push(child);
                }
            }
            ans.push_back(move(level));
        }

        return ans;
    }
};


