class Solution:
    def minWindow(self, s: str, t: str) -> str:
        if t == "":
            return ""
        map, window={},{}
        for x in t:
            map[x]=1+map.get(x,0)
        have , need =0 , len(map)
        res, reslen = [-1,-1], float("infinity")
        l=0
        for r in range(len(s)):
            c=s[r]
            window[c]=1+window.get(c,0)
            
            if c in map and window[c] == map[c]:
                have+=1
            
            while have == need:
                if(r-l+1)<reslen:
                    res= [ l,r]
                    reslen=r-l+1
                
                window[s[l]]-=1
                if s[l] in map and window[s[l]]<map[s[l]]:
                    have-=1
                l+=1
        l,r=res
        return s[l:r+1] if reslen != float("infinity") else ""    
        