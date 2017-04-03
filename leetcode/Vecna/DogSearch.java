public class DogSearch
{
 public static void main(String[] args)
  {
    //This code will not compile correctly until you fix it.
    //
    //We are trying to count the number of times the word
    //dog appears in some input text, but we can't seem to
    //remember the appropriate method call in the String class,
    //and are not sure our approach will work.
    //task: Use the JDK documentation to help us finish the code,
    //then discuss the ambiguity in the problem description, and
    //reword it to remove the ambiguity in the space provided below.
    //
    //The ambiguity is that whether the "dog" must be a single word,
    //or could be a combined word, for instance "hotdog", and that 
    //whether it is case sensitive or insensitive.
    //
    //To remove the ambiguity, I'd say that this algorithm finds the
    //number of time "dog" appears in the input string with the 
    //specification that the word must be all lowercase and that
    //it could be either a single word "dog" or a combined word as in
    //"hotdog". 
    //
    //
    //
    //
    //

    String input = new String("The Dogman was no ordinary dog, nor man, but rather a peculiar dog-like man who barked like a dog, and panted like a dog, he even ate like a dog.  He owned a dog named Doglips, and interestingly enough, his favorite food was hotdogs.");
    System.out.println(input);
    int index = -1;
    int count = 0;
    String input_temp = input;//copy the original input to a temp string to make changes, 
                              //so the original string is intact and may be used later.
    System.out.print("Counting dogs:");
    do{
      index = input_temp.indexOf("dog");//get the index of first occurence of "dog".
      if(index != -1){
        count++;
        System.out.print(count+" ");
      }
      input_temp= input_temp.substring(index + 1);//remove the part of string from 
                                                  //the beginning to the first occurence of "dog"
    }while(index != -1);
    System.out.println("The word \"dog\" appears "+count+" times.");
  } 
}



