/*

Flood fill, also called seed fill, is an algorithm 
that determines and alters the area connected to a
given node in a multi-dimensional array with some matching attribute. 

To perform a "flood fill", consider the starting pixel, 
plus any pixels connected 4-directionally to the starting pixel of the same color as the starting pixel, 
plus any pixels connected 4-directionally to those pixels (also with the same color as the starting pixel), and so on. 
Replace the color of all of the aforementioned pixels with the newColor.
At the end, return the modified image.

*/
import java.util.*;

class FloodFill {
    public static int[][] floodFill(int[][] image, int sr, int sc, int newColor) {
        int color = image[sr][sc];
        if (color != newColor) {
            dfs(image, sr, sc, color, newColor);
        }
        return image;
    }
    
    public static void dfs(int[][] image, int sr, int sc, int color, int newColor) {
        if (sr < 0 || sr >= image.length || sc < 0 || sc >= image[0].length || image[sr][sc] != color) {
            return;
        }
        image[sr][sc] = newColor;
        dfs(image, sr + 1, sc, color, newColor);    //recursive calls
        dfs(image, sr - 1, sc, color, newColor);
        dfs(image, sr, sc + 1, color, newColor);
        dfs(image, sr, sc - 1, color, newColor);
    }

    public static void main(String args[]){
        Scanner sc = new Scanner(System.in);
        System.out.println("Enter length and breadth of grid: ");
        int length = sc.nextInt();
        int breadth = sc.nextInt();
        int grid[][] = new int[length][breadth];
        System.out.println("Enter colours of the grid (integers): ");
        for(int i=0;i<length;i++){
            for(int j=0;j<breadth;j++){
                grid[i][j] = sc.nextInt();
            }
        } 
        System.out.println("Enter starting cell co-ordinates: ");
        int row = sc.nextInt();
        int cols = sc.nextInt();
        System.out.println("Enter new colour number: ");
        int colour = sc.nextInt();
        int[][] result = floodFill(grid, row, cols, colour);
        System.out.println("Final color-changed grid: ");
        for(int i=0;i<result.length;i++){
            for(int j=0;j<result[0].length;j++){
                System.out.print(result[i][j]+"\t");
            }
            System.out.println();
        }
        sc.close();
    }
}

/**
 * OUTPUT:
 * Enter length and breadth of grid: 
3 3
Enter colours of the grid (integers): 
1 1 1
1 1 0
1 0 1
Enter starting cell co-ordinates: 
1 1
Enter new colour number: 
2
Final color-changed grid: 
2   2   2
2   2   0
2   0   1
 * 
 * 
 * 
 * 
 * Time Complexity: O(n) where n is the number of cells
 * Space Complexity: O(n) which is the stack size for any recursive call
 */