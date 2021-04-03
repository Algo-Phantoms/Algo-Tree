
/**
 * Tower of Hanoi. Recursive method is used.
 * Author - Khushee Kapoor
 * Shift(N,A,B,C)
 * A,B,C are 3 pegs such that peg A contains N number of discs. The discs are to be moved from peg A to 
 * peg C in ascending order of their sizes. The method used for this purposive is recursive method.
 * Algorithm used:
 * 1. [Set the base case]
 *      If(N==1)
 *      Display("Moving Disc A -> C")
 *      else
 * 2. [Recurisve Case]
 *      Shift(N-1,A,C,B)
 *      Display("Moving Disc A -> C")
 *      Shift(N-1,B,A,C)
 *      
 * So first recursive call moves n-1 disks from ‘first’ to ‘middle’ using ‘last’. So after that call 
 * n-1 disks are in ‘middle ‘ peg in order of size and the ‘first’ peg contains the nth disk i.e, 
 * the largest one. So, now move that disk from ‘first’ peg to ‘last’ peg. Then again by the 
 * 2nd recursive call move n-1 disk from ‘middle’ peg to ‘last’ peg using ‘first’ peg. So , after 
 * all these, ‘last’ peg contains all disks in order of size . 
 */
import java.util.*;
public class Tower_of_Hanoi
{
   public void Shift(int N, String first, String middle, String last)
   {
       if (N==1)
       { 
           System.out.println("Disc moved from \t"+first+"->"+last);
       }
       else
       {
           Shift(N-1, first, last, middle);
           System.out.println("Disc moved from \t"+first+"->"+last);
           Shift(N-1, middle, first, last);
        }
    }
    
   public static void main()
   {
       Tower_of_Hanoi ob = new Tower_of_Hanoi();
       System.out.println("Enter number of discs:");
       Scanner scanner = new Scanner(System.in);
       int N = scanner.nextInt();
       ob.Shift(N,"A","B","C");
    }
}
/** Sample Input: 3
 * Sample Output:
 * Disc moved from 	A->C
 * Disc moved from 	A->B
 * Disc moved from 	C->B
 * Disc moved from 	A->C
 * Disc moved from 	B->A
 * Disc moved from 	B->C
 * Disc moved from 	A->C
*/

/** Sample Input: 4
 * Sample Output:
 * Disc moved from 	A->B
 * Disc moved from 	A->C
 * Disc moved from 	B->C
 * Disc moved from 	A->B
 * Disc moved from 	C->A
 * Disc moved from 	C->B
 * Disc moved from 	A->B
 * Disc moved from 	A->C
 * Disc moved from 	B->C
 * Disc moved from 	B->A
 * Disc moved from 	C->A
 * Disc moved from 	B->C
 * Disc moved from 	A->B
 * Disc moved from 	A->C
 * Disc moved from 	B->C
*/

/** Time Complexity: O(2^n)
 * Space Complexity: O(n) */
 
 
