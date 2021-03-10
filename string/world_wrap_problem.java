
public class word_wrap_problem 
{
	final int MAX = Integer.MAX_VALUE; 
	   
	void solveWordWrap (int l[], int n, int M) 
	{ 
	       
	        int arr1[][] = new int[n+1][n+1]; //2-D array for storing the extra spaces
	      
	        int arr2[][]= new int[n+1][n+1];  //cost of a line which has words 
	      
	        int arr3[] = new int[n+1]; //total cost of optimal arrangement of words
	      
	        int p[] =new int[n+1]; // to print the solution 
	      
	        for (int i = 1; i <= n; i++)  // calculate extra spaces in single line
	        { 
	            arr1[i][i] = M - l[i-1]; 
	            for (int j = i+1; j <= n; j++) 
	            {
	            	arr1[i][j] = arr1[i][j-1] - l[j-1] - 1; 
	        
	            }
	        }
	          
	        for (int i = 1; i <= n; i++)//Calculate line cost corresponding to the above calculated extra spaces 
	        { 
	            for (int j = i; j <= n; j++) 
	            { 
	                if (arr1[i][j] < 0) 
	                    arr2[i][j] = MAX; 
	                else if (j == n && arr1[i][j] >= 0) 
	                    arr2[i][j] = 0; 
	                else
	                    arr2[i][j] = arr1[i][j]*arr1[i][j]; 
	            } 
	        } 
	           
	        arr3[0] = 0; 
	        for (int j = 1; j <= n; j++) //Calculate minimum cost and find minimum cost arrangement. 
	        { 
	            arr3[j] = MAX; 
	            for (int i = 1; i <= j; i++) 
	            { 
	                if (arr3[i-1] != MAX && arr2[i][j] != MAX &&  
	                   (arr3[i-1] + arr2[i][j] < arr3[j])) 
	                { 
	                    arr3[j] = arr3[i-1] + arr2[i][j]; 
	                    p[j] = i; 
	                } 
	            } 
	        }  
	}
	
	//Method to print the solution
	
	int printing_the_solution(int p[], int n) 
	{ 
		int k; 
		if (p[n] == 1) 
		{
			k = 1;
		}
		else
		{
	        k = printing_the_solution (p, p[n]-1) + 1; 
	        System.out.println("Line number" + " " + k + ": " +  
	                    "From word no." +" "+ p[n] + " " + "to" + " " + n); 
		}
	        return k; 
	}
	
	public static void main(String[] args)
    {
		
    }
}
