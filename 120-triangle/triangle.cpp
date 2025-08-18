class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        vector<int> minimumPaths;
        minimumPaths.push_back(triangle.at(0).at(0));
        for (int i{1}; i < triangle.size(); ++i) {
            auto triangleRow = triangle.at(i);
            triangleRow.at(0) += minimumPaths.front();
            for (int j = 1; j < triangleRow.size() - 1; j++) {
                triangleRow.at(j) += min(minimumPaths.at(j - 1), minimumPaths.at(j));
            }
            triangleRow.at(triangleRow.size() - 1) += minimumPaths.back();
            minimumPaths.swap(triangleRow);
        }

        return *min_element(minimumPaths.begin(), minimumPaths.end());
    }
};