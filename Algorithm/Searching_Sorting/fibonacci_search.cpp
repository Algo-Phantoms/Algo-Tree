


    /*Fibonacci search is an efficient search algorithm based on divide and conquer principle that can find an element in the given sorted array
    */

    /*Algorithm --->
    Let the length of given array be n [0...n-1] and the element to be searched be x.

    Then we use the following steps to find the element with minimum steps:

    Find the smallest Fibonacci number greater than or equal to n. Let this number be c [ Fibonacci number]. Let the two Fibonacci numbers preceding it be
    be a and b.

    While the array has elements to be checked:
    -> Compare x with the last element of the range covered by a.
    -> If x matches, return index value
    -> Else if x is less than the element, move the third Fibonacci variable two Fibonacci down, indicating removal of approximately two-third of the
    unsearched array.

    -> Else x is greater than the element, move the third Fibonacci variable one Fibonacci down. Reset offset to index. Together this results into removal
    of approximately front one-third of the unsearched array.

    Since there might be a single element remaining for comparison, check if b is '1'. If Yes, compare x with that remaining element. If match, return
    index value.
    From the above algorithm it is clear if we have to search the larger section of the array then the time taken will be more and will result into worst case and it's complexity wil be O(log n). If on the very first search, we get our element then it will be considered as the best case and complexcity will be O(1). When we consider the average case then case left and lies between the best and worst i when we have to search the element on the smaller section of the array and hence we get our average case complexity as O(log n).


    According to the algorithm we will first sort the array.
    */

    //program


    #include<bits/stdc++.h>
    using namespace std;


    int min(int x, int y) { return (x <= y) ? x : y; }
    // function created to find the min value between x and y

    int FibonacciSearch(int arr[], int x, int n){
         //function created returns index of x if present,  else returns -1.
    int a = 0;
    int b = 1;
    int c = a + b;
         // a,b,c are variables that stores the fibonacci numbers sequentially.

    while(c < n){
         // until c does not become equal to or greater than n , loop executes

    a = b;
    b = c;
    c = a + b;
    }
    int offset = -1;
         // Marks the eliminated range from front

    while (c > 1) {
         // checking if c is at valid location

    int i = min(offset + a, n - 1);
         // i will be assigned the value of min() used .


    if (arr[i] < x) {
        /*If x is greater than the value at index ,c cut the subarray array from offset to i*/
            c = b;
            b = a;
            a = c - b;
            offset = i;
        }
         else if (arr[i] > x) {
        /*If x is greater than the value at index ,c
           cut the subarray after i+1 */
            c = a;
            b = b - a;
            a = c - b;
        }


        else
            return i;
            //if element found return index
    }

    if (b && arr[offset + 1] == x)
        return offset + 1;
             // if not then return -1
    return -1;
    }


    int main(){
     int l;
    cout<<"\nEnter the number of elements in array which should be less than 10";
    cin>>l;
    int arr[10];
    cout<<"Enter elements in array";
    for(int i=0;i<l;i++)
    {
    cin>>arr[i];
    }         //array defined and declared

    sort(arr, arr + l);

    int n = sizeof(arr)/sizeof(arr[0]);
    int x;
    cout<<"\nEnter element to be searched :" ;
    cin>>x;
    cout<<"Found at index:"<<FibonacciSearch(arr, x, n);

    return 0;
    }



    /* complexities */

    /* Worst case time complexity:  O(log n)
      Average case time complexity:  O(log n)
      Best case time complexity:  O(1)
      Space complexity:  O(1)   */


    /*  constraints :
      size of array is 10.*/


      // test cases --->

    /* sample input :
      7
      100 90 30 15 60 120 10
      30
    */


    /* sample output:
      2  */



    /* sample input :
      5
      40 60 22 10 45
      22

      sample output:
      1  */



    /* sample input :
      2
      40 60
      60

      sample output:
      -1  */
