class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
    vector<unordered_set<char>>s(201);
    for(int j=0;j<strs.size();j++){
        for(int i=0;i<strs[j].size();i++){
            s[i].insert(strs[j][i]);

        }
    }
    int ans=0;
    for(int i=0;i<s.size();i++){
        if(s[i].size()==1)ans++;
        else break;
    }
    int k=INT_MAX;
    for(int i=0;i<strs.size();i++){
        k=min(k,(int)strs[i].size());

    }
    return strs[0].substr(0,min(ans,k));
    }
};