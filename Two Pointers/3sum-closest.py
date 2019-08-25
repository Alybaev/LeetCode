'''
125 / 125 test cases passed.
Status: Accepted
Runtime: 188 ms
Memory Usage: 13.8 MB
Your runtime beats 27.82 % of python3 submissions.
Your memory usage beats 0% of python3 submissions

'''
class Solution:
    def threeSumClosest(self, nums: List[int], target: int) -> int:
        nums.sort()
        res = nums[0] + nums[1] + nums[len(nums) - 1]
        min_close = abs(nums[0] + nums[1] + nums[len(nums) - 1] - target)

        for i in range(len(nums) - 2):
            left = i + 1
            right = len(nums) - 1
            while left < right:
                if nums[i] + nums[left] + nums[right] - target == 0:
                    return nums[i] + nums[left] + nums[right]
                else:
                    close = abs(nums[i] + nums[left] + nums[right] - target)
                    if(close < min_close):
                        min_close = close
                        res = nums[i] + nums[left] + nums[right]
                    if nums[i] + nums[left] + nums[right] - target < 0:
                        left += 1
                    else:
                        right -= 1

        return res
