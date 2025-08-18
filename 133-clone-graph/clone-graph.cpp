/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/
class Solution {
private:
    unordered_map<Node*, Node*> mp;
    void DFS(Node* node) {
        Node* newNode = new Node(node->val);
        mp[node] = newNode;
        for (auto neighbor : node->neighbors) {
            if (!mp.count(neighbor)) {
                DFS(neighbor);
            }
            mp[node]->neighbors.push_back(mp[neighbor]);
        }
    }

public:
    Node* cloneGraph(Node* node) {
        if (!node)
            return nullptr;
        DFS(node);
        return mp[node];
    }
};