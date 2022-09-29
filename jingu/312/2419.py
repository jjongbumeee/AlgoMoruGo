class Solution(object):
    def longestSubarray(self, nums):
        result = 0
        cnt = 0
        
        for i in range(len(nums)-1):
            print({nums[i], nums[i+1]})
            if len({nums[i], nums[i+1]}) is 1:
                cnt+=1
                result = max(result,cnt)
            else:
                cnt=0
            
        return(result+1)
                
