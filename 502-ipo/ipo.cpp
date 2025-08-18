class Solution {
public:
    int findMaximizedCapital(int k, int w,
                             vector<int>& profits,
                             vector<int>& capital) {
        int n = profits.size();
        vector<pair<int,int>> projects(n);
        for(int i = 0; i < n; ++i)
            projects[i] = {capital[i], profits[i]};
        sort(projects.begin(), projects.end());
        
        priority_queue<int> maxProfits;
        
        int idx = 0;    
        int currCap = w;  
        for(int turn = 0; turn < k; ++turn) {
            while(idx < n && projects[idx].first <= currCap) {
                maxProfits.push(projects[idx].second);
                ++idx;
            }
            if(maxProfits.empty()) 
                break;
            
            currCap += maxProfits.top();
            maxProfits.pop();
        }
        
        return currCap;
    }
};