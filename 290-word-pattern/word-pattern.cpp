class Solution {
public:
    bool wordPattern(string pattern, string s) {
        unordered_map<char, string> mp;
        unordered_map<string, char> mp1;
        int j = 0;
        for (int i = 0; i < pattern.size(); i++) {
            if (j >= s.size()) return false;

            string temp = "";
            while (j < s.size() && s[j] != ' ') {
                temp += s[j++];
            }

            auto it = mp.find(pattern[i]);
            auto it1 = mp1.find(temp);

            if (it != mp.end() && it1 != mp1.end()) {
                if (it->second != temp || it1->second != pattern[i])
                    return false;
            } else if ((it != mp.end()) != (it1 != mp1.end())) {
                return false;
            }

            mp[pattern[i]] = temp;
            mp1[temp] = pattern[i];
            j++;
        }

        if (j < s.size()) return false;

        return true;
    }
};