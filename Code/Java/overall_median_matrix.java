/*
 * To find the overall median of a matrix
 * 
 * Example:
 * 
 * A = [ [1, 3, 5],[2, 6, 9],[3, 6, 9] ]
 * 
 * output: 5
 * 
 * Explanation: 
 * Total elements we have
 * 1,2,3,3,5,6,6,9,9 
 * here there are 9 elements and median would be (n+1)/2 = 4th term
 * 
 * 4th term = 5
 * 
 */

import java.util.*;

public class overall_median_matrix
{
    public void main()
    {
        Scanner scanner = new Scanner(System.in);

        System.out.println("Enter number of rows: ");
        int m = scanner.nextInt(); scanner.nextLine();

        System.out.println("Enter number of columns: ");
        int n = scanner.nextInt(); scanner.nextLine();

        int A[][] = new int[m][n];

        int i, j, count = 0, temp, index;

        System.out.println("Enter elements: ");

        //accpeting values in matrix from user
        for(i = 0; i < m; i ++)
        {
            for(j = 0; j < n; j ++)
            {
                A[i][j] = scanner.nextInt(); scanner.nextLine();
            }
        }

        int flatA[] = new int[m*n];

        //converting matrix into one dimensional array
        for(i = 0; i < m; i ++)
        {
            for(j = 0; j < n; j ++)
            {
                flatA[count] = A[i][j];
                count++;
            }
        }

        //sorting the one dimensional array
        for(i = 0; i < m * n - 1; i++)
        {
            for(j = 0; j < m * n - i - 1; j++)
            {
                if(flatA[j] > flatA[j+1])
                {
                    temp = flatA[j];
                    flatA[j] = flatA[j+1];
                    flatA[j+1] = temp;
                }
            }
        }
        
        if(m * n % 2 == 0)
        {
            index = ((m * n) / 2) - 1;
        }
        else
        {
            index = (((m * n) + 1) / 2) - 1;
        }
        
        System.out.println("Median is: "+flatA[index]);
    }
}

/*
 * Test Cases-
 * 
 * 1.
 * Enter number of rows: 
 * 3
 * Enter number of columns: 
 * 3
 * Enter elements: 
 * 1
 * 3
 * 5
 * 2
 * 6
 * 9
 * 3
 * 6
 * 9
 * Median is: 5
 * 
 * 2.
 * Enter number of rows: 
 * 2
 * Enter number of columns: 
 * 4
 * Enter elements: 
 * 1
 * 3
 * 7
 * 2
 * 3
 * 9
 * 7
 * 6
 * Median is: 3
 * 
 * Time Complexity: O(m*n)
 * Space Complexity: O(m*n)
 * where m in number of rows and n is number of columns
 */
        