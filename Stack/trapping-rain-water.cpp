/*315 / 315 test cases passed.
Status: Accepted
Runtime: 4 ms
Memory Usage: 9.3 MB*/

class Solution {
public:
    int trap(vector<int>& height) {
        if(height.size() < 3){
            return 0;
        }
        stack<int> indxH;
        int res = 0;
        int i = 1;
        while(i < height.size() - 1){
            if(height[i - 1] > height[i]){
                indxH.push(i - 1);
            }
            if(height[i] < height[i + 1] and  not indxH.empty() and height[indxH.top()] > height[i]){
                int minH = min( height[indxH.top()],height[i + 1]);
                res += (i - indxH.top()) * (minH -  height[i]); 
                if(minH == height[indxH.top()]){
                   indxH.pop();
                   height[i] = minH;
                }else{
                   i++; 
                }
                
                
            }else{
                i++;
            }
           
            
        }
        return res;
    }
};