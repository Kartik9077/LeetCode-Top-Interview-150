class Solution {
public:
    int hIndex(vector<int>& ci) {
         if(ci.size()==1&&ci[0]==0)return 0;
        if(ci.size()==1)return 1;
        int low=0,high=ci.size();
        while(low<high){
            int mid=(low+high+1)/2;
            int count=0;
            for(auto it:ci){
                if(it>=mid)count++;
            }
            if(count>=mid)low=mid;
            else high=mid-1;
        }
        return low;
    }
};