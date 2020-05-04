# transpose matrix
# given a matrix A, return the transpose of A

# @param {Integer[][]} a
# @return {Integer[][]}
def transpose(a)
  return a[0].zip(*a[1..])
end
