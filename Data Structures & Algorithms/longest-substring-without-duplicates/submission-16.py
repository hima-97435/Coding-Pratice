class Solution:
    def lengthOfLongestSubstring(self, s: str) -> int:
        set_list=set()
        l = r =0
        ans=0
        while r< len(s):
            if s[r] in set_list:
                while s[r] in set_list:
                    set_list.remove(s[l])
                    l+=1
            set_list.add(s[r])
            ans=max(ans,r-l+1)
            r+=1
        return ans

        