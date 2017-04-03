import math

def mergesort(arr):
    size = len(arr)
    if size > 1:
        mid = int(size / 2)
        left = arr[:mid]
        right = arr[mid:]
        mergesort(left)
        mergesort(right)
        i = 0
        j = 0
        k = 0
        while i < len(left) and j < len(right):
            if left[i] < right[j]:
                arr[k] = left[i]
                i += 1
            else:
                arr[k] = right[j]
                j += 1
            k += 1
        while i < len(left):
            arr[k] = left[i]
            i += 1
            k += 1
        while j < len(right):
            arr[k] = right[j]
            j += 1
            k += 1
def main():
  arr = [6,5,3,1,8,7,2,4]
  mergesort(arr)
  print (arr)
  
main()
  
