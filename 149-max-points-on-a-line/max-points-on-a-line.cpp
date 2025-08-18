class Solution {
public:
    int maxPoints(vector<vector<int>>& points) {
        int maxi=0;
        for(int i=0;i<points.size();i++){
            unordered_map<double,int> m;
            int ans=0;
            for(int j=0;j<points.size();j++){
                if(j==i){
                    continue;
                }
                double slope=(double)(points[i][1]-points[j][1])/(double)(points[i][0]-points[j][0]);
                m[slope]++;
                ans=max(ans,m[slope]);
            }
            maxi=max(maxi,ans);
        }
        return maxi+1;
    }
};