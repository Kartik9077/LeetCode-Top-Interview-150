class Solution {
public:
    vector<char> choices = {'A', 'C', 'G', 'T'};

    int minMutation(string startGene, string endGene, vector<string>& bank) {
        unordered_set<string> st(bank.begin(), bank.end());
        queue<pair<string, int>> q;

        q.push({startGene, 0});
        if (st.find(startGene) != st.end()) st.erase(startGene);

        while (!q.empty()) {
            auto front = q.front();
            q.pop();
            string temp = front.first;
            int mini = front.second;

            if (temp == endGene) return mini;

            for (int i = 0; i < temp.length(); i++) {
                char original = temp[i];
                for (int j = 0; j < choices.size(); j++) {
                    temp[i] = choices[j];
                    if (st.find(temp) != st.end()) {
                        st.erase(temp);
                        q.push({temp, mini + 1});
                    }
                }
                temp[i] = original;
            }
        }
        return -1;
    }
};