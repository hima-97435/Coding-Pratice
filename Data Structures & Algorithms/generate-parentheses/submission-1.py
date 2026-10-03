class Solution:
    def generateParenthesis(self, n: int) -> List[str]:
        res = []
        cur=""
        def dfs(open, close):
            nonlocal cur
            if len(cur) == 2*n:
                res.append(cur)
                return
            if open<n:
                cur+='('
                dfs(open+1,close)
                cur=cur[:-1]
            if close<open:
                cur+=')'
                dfs(open,close+1)
                cur =cur[:-1]
        dfs(0,0)
        return res
        