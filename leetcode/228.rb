# summary ranges
# given a sorted integer array without duplicates, return the summary of its ranges

# @param {Integer[]} nums
# @return {String[]}
def summary_ranges(nums)
  return [] if nums.empty?
  out = []
  start = nums[0]
  for i in 1..nums.length-1
    if nums[i] != nums[i-1] + 1
      if start < nums[i-1]
        out.push(String(start) + "->" + String(nums[i-1]))
      else
        out.push(String(start))
      end
      start = nums[i]
    end
  end
  if start == nums[-1]
    out.push(String(start))
  else
    out.push(String(start) + "->" + String(nums[-1]))
  end
  return out
end
