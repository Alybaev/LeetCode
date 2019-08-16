/*
20 / 20 test cases passed.
Status: Accepted
Runtime: 28 ms
Memory Usage: 16.8 MB
Your runtime beats 33.25 % of cpp submissions
Your memory usage beats 60.00 % of cpp submissions.
*/

/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;

    Node() {}

    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/
class Solution {
public:

    map<Node*, Node*> vis;
    Node* cloneGraph(Node* node) {
        if(!node)return NULL;
        Node* copy = new Node((*node).val,{});
        vis[node] = copy;
        for(auto& v: (*node).neighbors){

            
            if( vis.find(v) == vis.end() ){
                (*copy).neighbors.push_back(cloneGraph(v));
            }else{
                (*copy).neighbors.push_back( vis[v]);
            }
        }
 
        
        return copy;
    }
};