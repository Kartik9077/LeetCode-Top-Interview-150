class Solution {
public:
    bool isAnagram(string s, string t) {
        vector<int>freq(26,0);
        vector<int>fr(26,0);
        for(auto it:s)
            freq[it-'a']++;

        for(auto it:t)
        fr[it-'a']++;

        int j=0; 
        while(j<26){
            if(freq[j]==fr[j]){
                j++;
                continue;
            }
            return 0;
        }
        return 1;

    }
};