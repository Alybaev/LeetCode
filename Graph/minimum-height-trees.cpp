/*
66 / 66 test cases passed.
Status: Accepted
Runtime: 72 ms
Memory Usage: 24.5 MB
Your runtime beats 76.37 % of cpp submissions.
Your memory usage beats 85.71 % of cpp submissions
*/



class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        using g = vector<vector<int>>;
        g(n, vector<int>(n));
        for(vector<int>& edge : edges){
            g[edge[0]].push_back(edge[1]);
            g[edge[1]].push_back(edge[0]);
        }
        queue<int> q;
        int min = n - 1;
        for(int i = 0;i < g.size();i++){
            vector<int> d(n, -1);
            q.push(i);
            d[i] = 0;
            while(!q.empty()){
                int u = q.front();
                q.pop();
                for(int& v: g[u]){
                    q.push(v);
                    d[v] = d[u] + 1;
                }
                
            }
            auto it = max(d.begin(),d.end());
            if(*it < min){
                min = *it;
            }
            
        }
        return min;
        
    }
};