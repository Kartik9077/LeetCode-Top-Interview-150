class Solution {
    void permutations(vector<vector<int>>&ans,vector<int>&temp,vector<bool>&visit,vector<int>nums)
    {
      if(temp.size()==nums.size())
      {
        ans.push_back(temp);
        return;
      }
     for(int i=0;i<visit.size();i++)
     {
  if(visit[i]==0)
  { temp.push_back(nums[i]);
  visit[i]=1;
    permutations(ans,temp,visit,nums);
    visit[i]=0;
    temp.pop_back();
  }
     }

    }
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>>ans;
        vector<int>temp;
        vector<bool>visit(nums.size(),0);
        permutations(ans,temp,visit,nums);
        return ans;

    }
};