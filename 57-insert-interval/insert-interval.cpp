class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& ne) {
        int i=0;vector<vector<int>>ans;
      int n=intervals.size();
      while(i<n&&ne[0]>intervals[i][1])
      {
  ans.push_back(intervals[i]);i++;

      }
      if(i==n)
      {
        ans.push_back(ne);
        return ans;
      }
    while(i<n&&ne[1]>=intervals[i][0])
    {
        ne[0]=min(intervals[i][0],ne[0]);
        ne[1]=max(intervals[i][1],ne[1]);
        i++;

    }ans.push_back(ne);
     while(i<n)
     {
        ans.push_back(intervals[i]);
        i++;
     }
     return ans;
    }
};