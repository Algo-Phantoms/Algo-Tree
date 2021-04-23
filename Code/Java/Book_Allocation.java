/* 
Book Allocation  

Provided "n" number of books and "m" number of students. Books are arranged in increasing number of its pages. Each student is assigned to read pages in consecutive order.
Assign books in such a manner that maximum number of pages each student get to read is minimum.
*/

import java.util.*;
import java.lang.*;
import java.io.*;

class Book_Allocation {
    // function to check if "key" number of pages can be allocated or not
    public static boolean pageread(int a[], int n, int key, int m) {
        int sum = 0;
        int cnt = 1;

        for (int j = 0; j < n; j++) {

            // if number of pages is greater than key then it can't be allocated
            if (a[j] > key)
                return false;

            // counting the number of students required to allocate "sum" number of pages
            if (sum + a[j] > key) {
                // incrementing the number students and updating current number of pages in "sum"
                cnt++;
                sum = a[j];
                // if count of students is greater than given students "m", then its not
                // possible to allocate these many books to given students "m"
                if (cnt > m)
                    return false; 
            }
            // else update current number of pages
            else {
                sum += a[j]; 
            }
        }
        return true;
    }

    // function to find the page distribution
    public static int binary_search(int a[], int n, int m) {
        int ans = Integer.MAX_VALUE;
        // if students are greater than number of books then its impossible to allocate pages
        if (n < m)
            return -1;

        int sum = 0;
        for (int i = 0; i < n; i++)
            sum += a[i];

        int low = 0;
        int high = sum;
        while (low <= high) {
            int mid = (low + high) / 2;
            // checking if "mid" number of pages can be distributed as minimum possible pages
            if (pageread(a, n, mid, m) == true) {
                // if "mid" number of pages can be allocated then find minimum of current
                // minimum pages and "mid"
                ans = Math.min(ans, mid);
                high = mid - 1;
            } 
            else {
                low = mid + 1;
            }
        }
        return ans;
    }

    public static void main(String[] args) throws java.lang.Exception {
        Scanner sc = new Scanner(System.in);
        System.out.print("Enter number of pages of each books: ");
        int n = sc.nextInt(); 
        System.out.print("Enter number of students: ");
        int m = sc.nextInt(); 
        
        // array for page distribution of each book
        int[] a = new int[n];
        for (int i = 0; i < n; i++) {
            a[i] = sc.nextInt();
        }
        int ans = binary_search(a, n, m);
        System.out.println("Minimum number of pages = " + ans);
    }
}

/*
Test Cases
1.
Input - 
Enter number of pages of each books: 6
Enter number of students: 3 
13 28 34 40 57 85 
Output -
Minimum number of pages = 97

2.
Input - 
Enter number of pages of each books: 7
Enter number of students: 5
10 24 33 49 59 66 107 
Output -
Minimum number of pages = 107

Time complexity : O(n*log(sum)) where n = number of books, sum = sum of the pages of all the books 
Space complexity: O(1), no extra space is used
 */
