class Solution {
public:

    int dp[30][2][2];

    int f(string &s,int idx,bool tight,bool prev){
        if(idx == s.size()) return 1;

        if(dp[idx][tight][prev] != -1) return dp[idx][tight][prev];

        int lb=0;
        int ub=tight ? s[idx]-'0' : 1;

        int res=0;
        for(int dig=lb;dig<=ub;dig++){
            if(dig==1 && prev) continue;
            res += f(s,idx+1,tight&&dig==ub,dig==1);
        }

        return dp[idx][tight][prev] = res;
    }

    int findIntegers(int n) {
        string s=bitset<32>(n).to_string();
        int idx_of_first_set_bit=s.find('1');
        s=s.substr(idx_of_first_set_bit);

        memset(dp,-1,sizeof(dp));
        return f(s,0,1,0);
    }
};