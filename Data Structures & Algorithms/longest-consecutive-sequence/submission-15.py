class Solution:
    def longestConsecutive(self, nums: List[int]) -> int:
        arr=set(nums)
        ans=0
        for i in range(len(nums)):
            if nums[i]-1 not in arr:
                length =1
                while nums[i]+length in arr : 
                    length+=1
                ans=max(ans,length)
        return ans

        