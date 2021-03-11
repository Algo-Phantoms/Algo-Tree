/*This is a Java Program to print a 2D Array of 'r' rows and 'c' columns in a spiral form.*/
import java.util.*;
public class spiral_array
{
	public static void main(String[] args){
		Scanner sc = new Scanner(System.in);
		int r = sc.nextInt();
		int c = sc.nextInt();
		int a[][] = new int[r][c];
		for(int  i = 0; i < r; i++ ){
			for(int j =0; j < c; j++){
				a[i][j]=sc.nextInt();
			}
		}
		spiralprint(a,r,c);
	}
	
	public static void spiralprint(int a[][], int r, int c){
		//start row
		int sr = 0;
		//end row 
		int er = r-1; 
		// start coloumn
		int sc = 0;
		//end column
		int ec = c-1;
		int ele = 0;
		while(ele < r*c){
			// top row
			for(int i=sc; i<=ec;i++){
				System.out.print(a[sr][i] + " ");
				ele++;
			}
			sr++;
			if(ele == r*c)
				break;
			// last column
			for(int i=sr; i<=er;i++){
				System.out.print(a[i][ec] + " ");
				ele++;
			}
			ec--;
			if(ele == r*c)
				break;
			// last row
			for(int i=ec; i>=sc;i--){
				System.out.print(a[er][i] + " ");
				ele++;
			}
			er--;
			if(ele == r*c)
				break;
			// first coloumn
			for(int i=er;i>=sr;i--){
				System.out.print(a[i][sc] + " ");
				ele++;
			}
			sc++;
		}
	}
}
/* 
	Test Cases :
	Input : 3 3
	1 2 3
	4 5 6
	7 8 9
	Output : 1 2 3 6 9 8 7 4 5
	
	Input : 4 4
	 1  2   3  4
	 5  6   7  8 
	 9 10  11 12
	13 14  15 16
	Output: 1 2 3 4 8 12 16 15 14 13 9 5 6 7 11 10
 */
