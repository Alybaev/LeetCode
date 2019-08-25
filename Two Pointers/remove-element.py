'''
282 / 282 test cases passed.
Status: Accepted
Runtime: 48 ms
Memory Usage: 13.8 MB
Your runtime beats 29.91 % of cpp submissions. 
Your memory usage beats 6.06 % of cpp submissions
'''


class Solution:
    def removeElement(self, nums: List[int], val: int) -> int:
        nums.sort()
        i = 0
        j = len(nums) - 1
        end = True
        while end:
            if i ==  len(nums) or j == -1:
                return len(nums)  
            end = False
            if nums[j] - val > 0:
                end = True
                j -= 1
            if nums[i]- val < 0:
                end = True
                i += 1
        del nums[i:j+1]
        return len(nums)  