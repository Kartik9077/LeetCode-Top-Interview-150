/*
// Definition for a QuadTree node.
class Node {
public:
    bool val;
    bool isLeaf;
    Node* topLeft;
    Node* topRight;
    Node* bottomLeft;
    Node* bottomRight;
    
    Node() {
        val = false;
        isLeaf = false;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }
    
    Node(bool _val, bool _isLeaf) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }
    
    Node(bool _val, bool _isLeaf, Node* _topLeft, Node* _topRight, Node* _bottomLeft, Node* _bottomRight) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = _topLeft;
        topRight = _topRight;
        bottomLeft = _bottomLeft;
        bottomRight = _bottomRight;
    }
};
*/

class Solution {
private:
    bool check(vector<vector<int>>&grid, int i, int j, int size)
    {
        for(int l = i; l < i+size; l++)
        {
            for(int k = j; k < j+size; k++)
            {
                if(grid[l][k] != grid[i][j])
                return false;
            }
        }
        return true;
    }
    Node* solve(vector<vector<int>>&grid, int i, int j, int size)
    {
        bool isLeaf = check(grid, i, j, size);

        if(isLeaf)
        {
            Node* root = new Node(grid[i][j] == 1, true);
            return root;
        }

        Node* root = new Node(true, 0, NULL, NULL, NULL, NULL);

        int half = size/2;

        root->topLeft = solve(grid, i, j, half);
        root->topRight = solve(grid, i, j+half, half);
        root->bottomLeft = solve(grid, i+half, j, half);
        root->bottomRight = solve(grid, i+half, j+half, half);

        return root;
    }
public:
    Node* construct(vector<vector<int>>& grid) {
        int n = grid.size();
        return solve(grid, 0, 0, n);
    }
};