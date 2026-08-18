class Solution:
    def generateMatrix(self, n: int) -> List[List[int]]:
        ans = [[0]*n for _ in range(n)]
        left,right,top, bottom = 0,n-1,0,n-1
        val=1
        while left<=right:
            for c in range(left, right+1):
                ans[top][c]=val
                val+=1
            top+=1
            for c in range (top,bottom+1):
                ans[c][right]=val
                val+=1
            right-=1
            for c in range(right, left-1,-1):
                ans[bottom][c]= val
                val+=1
            bottom-=1
            for c in range(bottom , top-1,-1):
                ans[c][left]=val
                val+=1
            left+=1
        return ans
        