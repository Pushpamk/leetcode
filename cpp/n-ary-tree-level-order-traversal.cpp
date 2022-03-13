/*
// Definition for a Node.
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
*/

class Solution {
public:
    vector<vector<int>> levelOrder(Node* root) {
        queue<Node*> q, q1;
        if (!root) 
            return {};
        q.push(root);
        vector<vector<int>> ans;
        while (!q.empty()) {
            vector<int> tmp;
            while(!q.empty()) {
                Node* cur = q.front();
                q.pop();
                tmp.push_back(cur -> val);
                for (Node* child : (cur -> children)) {
                    q1.push(child);
                }
            }
            ans.push_back(tmp);
            swap(q, q1);
        }
        return ans;
    }
};
