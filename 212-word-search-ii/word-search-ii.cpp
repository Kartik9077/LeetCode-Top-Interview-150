class TrieNode {
    public:
        vector<TrieNode *> children;
        bool isEnd;
        string word;
        TrieNode() : children(26, nullptr), isEnd(false), word("") {};
};

class Solution {
public:
    TrieNode * root;
    Solution() {
        root = new TrieNode();
    }

    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        int row = board.size();
        if (row == 0) {
            return {};
        }
        int col = board[0].size();
        int size = words.size();

        for (int idx = 0; idx < size; idx++) {
            insert(words[idx]);
        }

        // iterate over the board and try out the possibility
        vector<string> ans;
        for (int r = 0; r < row; r++) {
            for (int c = 0; c < col; c++) {
                dfs(board, r, c, root, ans);
            }
        }
        return ans;
    }

    bool isSafe(vector<vector<char>> &board, int r, int c) {
        if (r >= board.size() || r < 0 || c >= board[0].size() || c < 0) {
            return false;
        }
        return true;
    }

    vector<pair<int, int>> dir = {{0, 1}, {1, 0}, {-1, 0}, {0, -1}};
    void dfs(vector<vector<char>> &board, int r, int c, TrieNode * ptr, vector<string> &ans) {
        if (!isSafe(board, r, c) || board[r][c] == '#') {
            return;
        }

        char ch = board[r][c];
        if (ch == '#' || ptr->children[ch-'a'] == NULL) {
            return;
        }
        board[r][c] = '#';
        ptr = ptr->children[ch-'a'];
        if (ptr->isEnd) {
            ans.push_back(ptr->word);
            ptr->isEnd = false;
        }

        // check neighbours 
        for (int i = 0; i < 4; i++) {
            int dr = dir[i].first + r;
            int dc = dir[i].second + c;
            if (isSafe(board, dr, dc) && board[dr][dc] != '#') {
                dfs(board, dr, dc, ptr, ans);
            }
        }

        board[r][c] = ch;
    }

    void insert(string word) {
        int len = word.length();
        TrieNode * ptr = root;
        for (int idx = 0; idx < len; idx++) {
            char c = word[idx];
            int id = c - 'a';
            if (ptr->children[id] == NULL) {
                ptr->children[id] = new TrieNode();
            }
            ptr = ptr->children[id];
        }
        ptr->isEnd = true;
        ptr->word = word;
    }
};