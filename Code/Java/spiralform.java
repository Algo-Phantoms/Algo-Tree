/* Problem statement: Java program to print 2D matrix in spiral form 
 At first ,we will take four pointers ,one is top pointer  pointing to first row,down pointer pointing to last row,for columns we need left 
and right pointers.First assign top=0,down=n-1,left=0,right=n-1.Take a direction pointer and initialize it with 0. If direction pointer=0 means we
will move from left to right, 1 means we will move from top to down ,2 means we will move from right to left ,3 means we will move from down to top.
Take the conditions in if else block and print the matrix .
*/

//Solution:
import java.io.*; 
import java.util.*;
public class spiralform {
static void printspiralorder(int[][] arr,int m,int n){
int top=0,down=n-1,left=0,right=n-1,i;
int direction=0;
while(top<=down && left<=right){
if (direction==0){
for(i=left;i<=right;i++){
System.out.print(arr[top][i]+" ");
}
top=top+1;
}
else if (direction==1){
for(i=top;i<=down;i++){
System.out.print(arr[i][right]+" ");
}
right=right-1;
}
else if (direction==2){
for(i=right;i>=left;i--){
System.out.print(arr[down][i]+" ");
}
down=down-1;
}
else if (direction==3){
for(i=down;i>=top;i--){
System.out.print(arr[i][left]+" ");
}
left=left+1;
}
direction=(direction+1)%4;
}
}
public static void main(String[] args)
{
int m,n,i,j;

int arr[][]= new int[10][10];
//To take input from user use scanner class
Scanner sc=new Scanner(System.in);
System.out.println("Enter no.of rows and columns");
m=sc.nextInt();
n=sc.nextInt();
System.out.println("enter 2D matrix:");
for(i=0;i<m;i++){
for(j=0;j<n;j++){
arr[i][j]=sc.nextInt();
}
}
printspiralorder(arr,m,n);
}
}

/*
Test cases: 
 Input: Enter no.of rows and columns: 4 4
        enter 2D matrix: 
        1  2  3  4
        5  6  7  8
        9  10 11 12 
        13 14 15 16 
Ouput: 1 2 3 4 8 12 16 15 14 13 9 5 6 7 11 10

Input : enter no.of rows and columns: 3 3
        enter 2D matrix:
        1 4 5
        8 9 0
        6 7 8
Output: 1 4 5 0 8 9 7 6 8 9 

Time Complexity: O(m*n) where m  is no.of rows and n is no.of columns ,For traversing matrix O(m*n) matrix is required.
Space Complexity:O(1) 

*/
