# missing number
# given an array of n distinct numbers from 0, 1, 2, ..., n, find the one number missing from the array

# @param {Integer[]} nums
# @return {Integer}
def missing_number(nums)
  n = nums.length    
  return (n*(n+1))/2 - nums.sum()
end
