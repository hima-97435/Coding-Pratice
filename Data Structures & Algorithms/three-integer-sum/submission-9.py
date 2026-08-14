class Solution:
    def threeSum(self, nums: List[int]) -> List[List[int]]:
        n = len(nums)
        nums.sort()
        ans=[]
        for i in range(0,n):
            if i>0 and nums[i] == nums[i-1] :
                continue
            l = i+1
            r = n-1
            while l<r:
                sum = nums[i]+nums[l]+nums[r]
                if sum>0:
                    r-=1
                elif sum<0:
                    l+=1
                else:
                    ans.append([nums[i],nums[l], nums[r]])
                    l+=1
                    r-=1
                    while l < r and  nums[l] == nums[l-1] :
                        l+=1
        return ans
        