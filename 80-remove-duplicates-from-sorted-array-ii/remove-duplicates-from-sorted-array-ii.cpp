class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if(nums.size()<=2)return nums.size();
        int k=2,i=2;
        while(i<nums.size()){
            if(nums[i]!=nums[k-2]){
                nums[k]=nums[i];
                k++;
            }
            i++;
        }
        return k;
    }
};