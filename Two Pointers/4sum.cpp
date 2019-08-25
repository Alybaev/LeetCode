/*
282 / 282 test cases passed.
Status: Accepted
Runtime: 48 ms
Memory Usage: 9.2 MB
Your runtime beats 29.91 % of cpp submissions. 
Your memory usage beats 94.74 % of cpp submissions
*/


class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        sort(nums.begin(),nums.end());
        vector<vector<int>> res = {};
        int n = nums.size() - 2;
        for(int i = 0;i < n;i++){
            for(int k = i + 1;k < nums.size() - 1;k++){
                int left = k + 1;
                int right = nums.size() - 1;
                while(left < right){

                    if(target - (nums[i] + nums[left] + nums[right] + nums[k]) == 0) {
                        vector<int> quad = { nums[i],nums[left],nums[right], nums[k]};
                        if(find(res.begin(),res.end(),quad) == res.end()){
                            res.push_back(quad);

                        }
                        right--;
                        left++;
                    }else{
                                               

                        if(target - (nums[i] + nums[left] + nums[right] + nums[k]) > 0){
                            left++;
                        }else{
                            right--;
                        }
                    }
                }
            }
            
        }
        return res;
    }
};