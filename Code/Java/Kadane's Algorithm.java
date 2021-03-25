import java.io.*;
import java.util.*;

public class Main {

    public static int solution(int[] arr) {
        // write your code here
    int currentSum = arr[0];
    int overallSum = arr[0];
    for(int i=1;i<arr.length;i++){
        if(currentSum >=0){
            currentSum += arr[i];
        }else{
            currentSum = arr[i];
        }
        if(currentSum >overallSum){
            overallSum = currentSum;
        }
    }
    return overallSum;
        
    }

    public static void main(String[] args) {
        Scanner scn = new Scanner(System.in);
        int n = scn.nextInt();
        int[] arr = new int[n];
        for (int i = 0; i < arr.length; i++) {
            arr[i] = scn.nextInt();
        }
        System.out.println(solution(arr));
    }
}


/*  CONSTRAINTS
1 <= N <= 10000
-2^31 <= arr[i] <= 2^31 - 1   
*/

/*  
  SAMPLE INPUT
  3
1
2
3
*/

/*  
SAMPLE OUTPUT
6
*/

/*  
TIME COMPLEXITY- O(N)
SPACE COMPLEXITY -O(N)
*/
