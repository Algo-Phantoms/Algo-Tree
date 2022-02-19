import java.util.*;

public class NQueensBB {
    //answer list
    public static ArrayList<ArrayList<Integer>> answer= new ArrayList<>();
    
    static ArrayList<ArrayList<Integer>> nQueen(int n) 
    {
        boolean[][] grid= new boolean[n][n];
        boolean[] cols= new boolean[n];   //boolean array to check for occupied columns
        boolean[] d1= new boolean[2*n-1]; //boolean array to check for occupied slash diagonals
        boolean[] d2= new boolean[2*n-1]; //boolean array to check for occupied backslash diagonals
        
        solve(grid, 0, cols, d1, d2); //helper function
        
        return answer;
        
    }
    
    
    public static void solve(boolean[][] grid, int row, boolean[] cols, boolean[] d1, boolean[] d2 )
    {
        if(row==grid.length)
        { 
            //if we reach the end of the grid that means we have found a solution

            ArrayList<Integer> p = new ArrayList<>();

            //now we store 1 based indexing of the columns in which the queen is placed in each row
            
            for(int i=0; i<grid.length; i++)
            {
                for(int j=0; j<grid[0].length; j++)
                {
                    if(grid[i][j]==true)
                    {
                    p.add(j+1);
                    break;
                        
                    }
                }
                
            }
            
            //adding this solution to the answer list
            answer.add(p);
            return;
            
        }
        
        
        for(int col=0; col<grid[0].length; col++)
        {
            if(cols[col]==false && d1[row+col]==false && d2[row-col+grid.length-1]==false)
            {
                grid[row][col]=true;
                cols[col]=true;
                d1[row+col]=true;
                d2[row-col+ grid.length-1]=true;
                
                solve(grid, row+1, cols, d1, d2);
                
                grid[row][col]=false;
                cols[col]=false;
                d1[row+col]=false;
                d2[row-col+grid.length-1]=false;
                
                
                
                
            }
            
        }
    }

    public static void main(String[] args) 
    {
        int n=4;

        ArrayList<ArrayList<Integer>> ans= nQueen(n);

        //prints the possible solutions with the column number at which the Queen is placed in each row

        System.out.println(ans);
        
    }
    
}
