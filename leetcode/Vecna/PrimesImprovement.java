public class PrimesImprovement
{
  public static void main(String[] args)
  {
 
    //This code should print out the prime numbers.
    //task: Fix and improve the algorithm
    
    System.out.println("Printing primes from 1 to 100");
    int i;
    int j;
    boolean prime;
    for(i = 1; i <= 100; i++)
    {
      prime = isPrime(i);
      if(prime) System.out.print(i + " ");
    }
    System.out.println();
  }

  public static boolean isPrime(int n)
  {
	  if(n < 2) return false;
	  if(n == 2) return true;
	  else return notDivisibleFrom(n, 2);
  }
  //Determines whether n is divisible by any number between p 
  //and square root of n
  public static boolean notDivisibleFrom(int n, int p)
  {
	  if(n < p * p) return true;//Empty interval
	  if(n % p == 0) return false;//fails if n is divisible by p
	  else return notDivisibleFrom(n, p + 1);
  }
}


