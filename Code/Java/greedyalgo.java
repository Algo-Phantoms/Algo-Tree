/*
Calulating Min use of Coin or Notes for Arranging Specific Amount
Logic is to take coins with greater value first. This can reduce
the total number of coins needed. Start from the largest possible denomination and
then keep adding denominations while the remaining value is greater than 0.
after all the size of ans containing notes / coins were used for min notes is
Final Answer or Number of Minimum Notes for Arranging a fix value
*/

package algo;
import java.util.Scanner;

public class algojava {
    public static void main(String[] args) {
        Scanner scan = new Scanner(System.in);
        // After Demonitization in India Due to Launch of 200 and 2000 Notes in Market :)
        int[] arr = {1, 2, 5, 10, 20, 50, 100, 200, 500, 1000, 2000};
        int k = scan.nextInt();
        findMin(k, arr);

    }
    public static void findMin(int V,int[] notes)
    {
        Vector<Integer> ans = new Vector<>();
        int n = notes.length;
        // Traverse through all notesmination of Notes / Currency
        for (int i = n - 1; i >= 0; i--)
        {
            while (V >= notes[i])
            {
                V -= notes[i];
                ans.add(notes[i]);
            }
        }
        // Printing which Notes will make use of Minimum Coins / Notes
        for (int i = 0; i < ans.size(); i++)
        {
            System.out.print(ans.elementAt(i)+" ");
        }
        System.out.println();
        System.out.println("Min No of Coins / Notes is "+ ans.size());
    }
}
/*
    Test Cases:
        Input : 94
        Output: 50 20 20 2 2
                Min No of Coins / Notes is 5

        Input : 72
        Output: 50 20 2
                Min No of Coins / Notes is 3

        Time Complexity: O(n)  where n is No. of Different Denomination of Notes Available
        Space Complexity: O(1)
 */
