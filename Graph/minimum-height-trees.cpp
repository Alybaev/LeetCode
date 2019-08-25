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
        using Graph = vector<vector<int>>;

        Graph g(n);
        for(vector<int>& edge : edges){
            g[edge[0]].push_back(edge[1]);
            g[edge[1]].push_back(edge[0]);
        }
        queue<int> q;
        queue<int> sub;
        int root = 0;
        vector<int> res;
        vector<int> d(n, -1);
        
        for(int i = 0;i < 2;i++){
            vector<int> vis(n,0);

            q.push(root);
            d[root] = 0;
            while(!q.empty()){
                int u = q.front();
                vis[u] = 1;
                q.pop();
                for(int& v: g[u]){
                    if(not vis[v]){
                        if(i == 1){
                            d[v] = d[u] + 1;
                        }
                        sub.push(v);

                    }
                }
                if(sub.empty()){
                    root = u;
                }
                if(q.empty()){
                    swap(q, sub);
                }

            }
        }

        int h = *(max_element(d.begin(), d.end() ) );
        res.push_back( find(d.begin(), d.end(), h / 2) - d.begin() );
        

        if(h % 2 != 0){
 
            res.push_back(  find(d.begin(), d.end(), h / 2 + 1) - d.begin());
        }
        
       
        return res;
        
    }
};