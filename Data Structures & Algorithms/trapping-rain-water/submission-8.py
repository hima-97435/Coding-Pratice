class Solution:
    def trap(self, height: List[int]) -> int:
        l , r =0 , len(height)-1
        lmax,rmax=0,0
        ans = 0
        while l<=r :
            if height[l]<height[r]:
                lmax=max(lmax,height[l])
                ans+=lmax-height[l]
                l+=1
            else:
                rmax=max(rmax,height[r])
                ans+=rmax-height[r]
                r-=1
        return ans
