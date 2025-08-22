class Solution {
public:
    int minimumArea(vector<vector<int>>& grid) {
        int n=grid.size(),m=grid[0].size();
        int s=INT_MAX,e=INT_MIN,l=INT_MAX,r=INT_MIN;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++)
            {
               if(grid[i][j]==1)
               {
                s=min(s,i);
                e=max(e,i);
                l=min(l,j);
                r=max(r,j);
               }
            }
        }
        return ((e-s+1)*(r-l+1));


    }
};