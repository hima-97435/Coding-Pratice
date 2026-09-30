class Solution:
    def maxArea(self, heights: List[int]) -> int:
        l ,r =0 , len(heights)-1
        ans =0
        while l < r:
            tmp = min(heights[l], heights[r])
            tmp*=(r-l)
            ans=max(tmp,ans)

            if heights[l]>heights[r] : 
                r-=1
            else:
                l+=1
        return ans
        