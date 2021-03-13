/*This is a Java Program to print a 2D Array of 'r' rows and 'c' columns in a wave form.*/
package javacode;
import java.util.*;
public class WaveArrayPrint{
        public static void waveprint(int a[][], int r, int c){
                for(int column = 0; column < c; column++){
                        if(column%2==0){
                                // even -->print top to botom
                                for(int row = 0; row < r; row++){
                                        System.out.print(a[row][column]+" ");
                                }
                        }
                        else{
                                // odd --> print bottom to top
                                for(int row = r-1; row>=0;row--){
                                        System.out.print(a[row][column]+" ");
                                }
                        }
                }
        }
        public static void main(){
                Scanner sc = new Scanner(System.in);
                int r = sc.nextInt();
		int c = sc.nextInt();
		int a[][] = new int[r][c];
		for(int  i = 0; i < r; i++ ){
			for(int j =0; j < c; j++){
				a[i][j]=sc.nextInt();
			}
		}
		waveprint(a,r,c);
        }
}


/* 
	Test case :
	Input : 3 3
	1 2 3
	4 5 6
	7 8 9
	Output : 1 4 7 8 5 2 3 6 9 
        
        Input : 4 4
	 1  2   3  4
	 5  6   7  8 
	 9 10  11 12
	13 14  15 16
	Output: 1 5 9 13 14 10 6 2 3 7 11 15 16 12 8 4
*/
