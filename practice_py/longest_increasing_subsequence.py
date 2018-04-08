class Solution(object):
    # O(n^2)
    def lengthOfLIS(self, nums):
        if len(nums) == 0:
            return 0
        tmp = [1 for i in range(len(nums))]
        for i in range(len(nums)):
            for j in range(i):
                if nums[j] < nums[i]:
                    tmp[i] = max(tmp[i], tmp[j]+1)
        return max(tmp)
        