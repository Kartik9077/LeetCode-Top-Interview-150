class WordDictionary {
private:
    struct TrieNode {
        TrieNode* children[26];
        bool isEnd;
        TrieNode() {
            for (int i = 0; i < 26; i++) children[i] = nullptr;
            isEnd = false;
        }
    };

    TrieNode* root;

    bool dfsSearch(string &word, int index, TrieNode* node) {
        if (!node) return false;
        if (index == word.size()) return node->isEnd;

        char c = word[index];
        if (c == '.') {
            for (int i = 0; i < 26; i++) {
                if (dfsSearch(word, index + 1, node->children[i])) return true;
            }
            return false;
        } else {
            return dfsSearch(word, index + 1, node->children[c - 'a']);
        }
    }

public:
    WordDictionary() {
        root = new TrieNode();
    }

    void addWord(string word) {
        TrieNode* cur = root;
        for (char c : word) {
            if (!cur->children[c - 'a']) {
                cur->children[c - 'a'] = new TrieNode();
            }
            cur = cur->children[c - 'a'];
        }
        cur->isEnd = true;
    }

    bool search(string word) {
        return dfsSearch(word, 0, root);
    }
};


/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */
/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */