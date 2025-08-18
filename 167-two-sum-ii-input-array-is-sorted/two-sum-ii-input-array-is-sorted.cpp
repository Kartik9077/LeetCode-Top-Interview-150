class Solution {
public:
    vector<int> twoSum(vector<int>& num, int target) {
      int n=num.size();
      int i=0,j=num.size()-1;
      while(i<j){
        int sum=num[i]+num[j];
        if(sum==target)break;
        if(sum<target)i++;
        if(sum>target)j--;

      }
      return {i+1,j+1};
        
    }
};