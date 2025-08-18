class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int s=accumulate(nums.begin(),nums.end(),s);
        if(s<target)return 0;
        int right=0;
        int left=1;int length=INT_MAX;
      int sum=nums[right];
      if(sum>=target){
        return 1;
      }
      if(nums.size()==1){
        if(nums[0]>=target)return 1;
        return 0;
      }
      while(left<nums.size()){
        
        if((sum+nums[left])<target){
        sum+=nums[left];
        left++;}
        else if(sum+nums[left]>=target){
            length=min(length,left-right+1);
            sum-=nums[right];
            right++;
        }

      }
    
    
      return length;

        
    }
};