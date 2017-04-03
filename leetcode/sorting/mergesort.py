import math

def mergesort(arr, n):
  if n > 1:
    leftarr = arr[ : int(math.ceil(n / 2))]
    rightarr = arr[int(math.ceil(n / 2)) : ]
    
    mergesort(leftarr, len(leftarr))
    mergesort(rightarr, len(rightarr))
    
    i = 0
    j = 0
    k = 0
    print 'left half ', leftarr
    print 'right half ', rightarr
    print arr
    while i < len(leftarr) and j < len(rightarr):
      if leftarr[i] < rightarr[j]:
	arr[k] = leftarr[i]
	i += 1
      else:
	arr[k] = rightarr[j]
	j += 1
      k += 1
    print 'after merging', arr
    print i, ' ', j
    # either i or j will reach its maximum value at this stage
    # so the order of the following while loops does not matter
    
    # following while loops are used to fill in the original array (arr)
    # with unmoved (sorted) numbers
    while i < len(leftarr):
      arr[k] = leftarr[i]
      i += 1
      k += 1
    
    while j < len(rightarr):
      arr[k] = rightarr[j]
      j += 1
      k += 1
    print 'current arr', arr
      
      
      
      
    """  
    if arr1[0] > arr2[0]:
      return mergesort(arr2, len(arr2)) + mergesort(arr1, len(arr1))
    else:
      return mergesort(arr1, len(arr1)) + mergesort(arr2, len(arr2))
    """
def main():
  arr = [6,5,3,1,8,7,2,4]
  n = len(arr)
  mergesort(arr, n)
  print arr
  
main()
  