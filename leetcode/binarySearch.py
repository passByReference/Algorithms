def binarySearch(vec, begin, end, number):
  if(len(vec) == 1 and vec[(begin + end) / 2] != number):
    return 'not found'
  if(vec[(begin + end) / 2] == number):
    return 'found'
  else:
    for i in range(begin, end):
      if vec[i] < number:
	return binarySearch(vec, (begin + end) / 2, end, number)
      elif vec[i] > number:
	return binarySearch(vec, begin, (begin + end) / 2, number)
  
def main():
  vec = [3,4,6,8,9,24,56,78]
  number = int(raw_input('Enter a number: '))
  print binarySearch(vec, 0, len(vec), number)
  
main()