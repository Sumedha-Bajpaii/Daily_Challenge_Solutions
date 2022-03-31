class Solution:
    def ispossible(self,mid,A,M):
        count = 1
        sm = 0
        for i in A:
            sm += i
            if sm>mid:
                count += 1
                sm = i
        return True if count<=M else False
        
    def splitArray(self, nums, M):
        lo = max(nums)
        hi = sum(nums)
        ans = 0
        while lo <= hi:
            mid = (lo + hi)//2
            #is it possible to divide nums into maximum M subarrays
            #such that max possible sum is mid
            if self.ispossible(mid,nums,M):
                ans = mid
                hi = mid-1      #go for better ans #decrease max sum per subarray
            else:
                lo = mid+1
        return ans  