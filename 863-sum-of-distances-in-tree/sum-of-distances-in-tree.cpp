class Solution {
public:
    vector<list<int>>graph;
    vector<int>ans;
    vector<int>count;
    void dfs1(int src,int par){
        count[src] = 1;
        for(auto ngh:graph[src]){
            if(par==ngh) continue;
            dfs1(ngh,src);
            count[src] += count[ngh];
            ans[0] += count[ngh];
        }
    }
    void dfs2(int n,int src,int par){
        for(auto ngh:graph[src]){
            if(par==ngh) continue;
            ans[ngh] = ans[src] - count[ngh] + (n-count[ngh]); 
            dfs2(n,ngh,src);
        }
    }
    vector<int> sumOfDistancesInTree(int n, vector<vector<int>>& edges) {
        graph.resize(n);
        ans.resize(n);
        count.resize(n);
        for(int i=0;i<edges.size();i++){
            graph[edges[i][0]].push_back(edges[i][1]);
            graph[edges[i][1]].push_back(edges[i][0]);
        }
        dfs1(0,-1);
        dfs2(n,0,-1);
        return ans;
    }
};
