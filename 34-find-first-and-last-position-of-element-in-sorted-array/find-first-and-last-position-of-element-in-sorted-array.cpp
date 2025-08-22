class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int n=nums.size();
        if(n==0)return {-1,-1};
        if(n==1&&nums[0]==target)return{0,0};
        if(n==1&&nums[0]!=target)return {-1,-1};
        int i=0,j=n-1;
        int start=-1,end=-1;
        while(i<=j){
            int mid=i+(j-i)/2;
            if(nums[mid]==target&&mid==0){
                start=mid;break;
            }
            else if(nums[mid]==target&&nums[mid-1]<target){
                start=mid;
                break;

            }
            else if(nums[mid]==target&&nums[mid-1]==target)j=mid-1;
            else if(nums[mid]>target)j=mid-1;
            else i=mid+1;

        }
         i=0,j=n-1;
        while(i<=j){
            int mid=i+(j-i)/2;
            if(nums[mid]==target){
                if(mid==n-1){
                    end=mid;
                    break;

                }
                else if(nums[mid]<nums[mid+1]){
                    end=mid;
                    break;
                }
                else if(nums[mid]==nums[mid+1]){
                    i=mid+1;
                }
        

            }
            else if(nums[mid]<target){
                i=mid+1;
            }
            else j=mid-1;
        }
        return {start,end};

    
    }
};