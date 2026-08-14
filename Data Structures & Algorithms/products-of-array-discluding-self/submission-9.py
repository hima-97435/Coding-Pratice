class Solution:
    def productExceptSelf(self, nums: List[int]) -> List[int]:
        n= len(nums)
        prefix = [1]*(n+1)
        suffix = [1]*(n+1)

        i=1
        while i<=n:
            prefix[i]=prefix[i-1]*nums[i-1]
            i+=1
        
        i=n-1
        while(i>=0):
            suffix[i]=suffix[i+1]*nums[i]
            i-=1

        i=0
        ans=[]
        while i<n:
            ans.append(prefix[i]*suffix[i+1])
            i+=1   
        return ans
        