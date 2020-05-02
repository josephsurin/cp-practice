# two sum II - input array is sorted
# two sum with sorted (ascending order) input array

# @param {Integer[]} numbers
# @param {Integer} target
# @return {Integer[]}
def two_sum(numbers, target)
  numbers.each_with_index {|x, i|
    j = numbers.bsearch_index{ |v| target - x <=> v }
    if j != nil and i != j
      return [i+1, j+1]
    end
  }    
end
