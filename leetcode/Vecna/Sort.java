public class Sort{
	
	public static void main(String[] args){
	//This code will sort the numbers in the array.
        //task: Modify the algorithm to reverse the sort, then comment on its efficiency in the space 
	//provided below:
        //The array is reversed in the original array, so the space efficiency is O(n), where n is the number of elements in the sorted array. 
        //
        //
        //
        //
		int[] unsorted = new int[100];
		for(int i = 0; i < 100; i++)
			unsorted[i] = (int)(Math.random() * 100);
		System.out.println("Here are the unsorted nubers:");
		for(int i = 0; i < 100; i++) System.out.print(unsorted[i] + " ");
		System.out.println();
		int[] sorted = new int[100];
		for(int i = 0; i < 100; i++){
			int hi = -1;
			int hiIndex = -1;
			for(int j = 0; j < 100; j++){
				if(unsorted[j] > hi){
					hi = unsorted[j];
					hiIndex = j;
				}
			}
			sorted[i] = hi;
			unsorted[hiIndex] = -1;

		}
		System.out.println("Here are the sorted numbers:");
		for(int i = 0; i < 100; i++) System.out.print(sorted[i] + " ");
		System.out.println();
		System.out.println("Reversed:");
		int temp = 0;
		//swap the first number with the last one, and shrink the range from both beginning and end
		//until the head pointer and the tail pointer are converged
		for(int head = 0, tail = 99; head < tail; head++, tail--){
			temp = sorted[head];
			sorted[head] = sorted[tail];
			sorted[tail] = temp;
		}
		for(int num : sorted) System.out.print(num + " ");
		System.out.println();

	}	
}

