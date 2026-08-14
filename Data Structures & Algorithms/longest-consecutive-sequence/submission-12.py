class Solution:
    def longestConsecutive(self, nums: List[int]) -> int:
        nums_list= set(nums)
        longest = 0
        for x in nums:
            if x-1 not in nums_list:
                length=1
                while (x+length) in nums_list:
                    length+=1
                longest=max(longest,length)
        return longest
        