import java.util.*;

public class kadane_algo {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int size = sc.nextInt();
        int[] items = new int[size];

        for (int i = 0;i < size; i++) 
            items[i] = sc.nextInt();

        System.out.print(maximumSubArray(items));
    }

    public static int maximumSubArray(int[] items) {
        int sum = 0;
        int maxTotal = items[0];
    
        for (int i : items) {
            sum += i;
            maxTotal = Math.max(sum,maxTotal);
    
            if (sum < 0) sum = 0;
        }
    
        return maxTotal;
    }
}


