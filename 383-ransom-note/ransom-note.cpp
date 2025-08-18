class Solution {
public:
    bool canConstruct(string ra, string ma) {
         unordered_map<char,int>mp,mpp;
         for(auto it:ra)mp[it]++;
         for(auto it:ma)mpp[it]++;

         for(auto it:mp){
            char x=it.first;
            if(mpp.find(x)==mpp.end())return 0;
            else if(mpp[x]<mp[x])return 0;
         }
         return 1;
    }
};