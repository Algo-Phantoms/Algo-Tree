package collection;

import java.util.Scanner;

public class BooleanParenthesisProblem {
	static int countParenth(char symbols[],
            char operator[],
            int n)
{
int F[][] = new int[n][n];
int T[][] = new int[n][n];

// Fill diagonal entries first
// All diagonal entries in T[i][i]
// are 1 if symbol[i] is T (true).
// Similarly, all F[i][i] entries
// are 1 if symbol[i] is F (False)
for (int i = 0; i < n; i++) {
F[i][i] = (symbols[i] == 'F') ? 1 : 0;
T[i][i] = (symbols[i] == 'T') ? 1 : 0;
}

// Now fill T[i][i+1], T[i][i+2],
// T[i][i+3]... in order And F[i][i+1],
// F[i][i+2], F[i][i+3]... in order
for (int gap = 1; gap < n; ++gap)
{
for (int i = 0,
 j = gap; j < n;
 ++i, ++j)
{
T[i][j] = F[i][j] = 0;
for (int g = 0; g < gap; g++)
 
{
    // Find place of parenthesization
    // using current value of gap
    int k = i + g;

    // Store Total[i][k]
    // and Total[k+1][j]
    int tik = T[i][k]
      + F[i][k];
    int tkj = T[k + 1][j]
      + F[k + 1][j];

    // Follow the recursive formulas
    // according to the current operator
    if (operator[k] == '&')
    {
        T[i][j] += T[i][k]
                * T[k + 1][j];
        F[i][j]
            += (tik * tkj
                - T[i][k]
                * T[k + 1][j]);
    }
    if (operator[k] == '|')
    {
        F[i][j] += F[i][k]
                * F[k + 1][j];
        T[i][j]
            += (tik * tkj
                - F[i][k]
                * F[k + 1][j]);
    }
    if (operator[k] == '^')
    {
        T[i][j] += F[i][k]
               * T[k + 1][j]
                   + T[i][k]
                   * F[k + 1][j];
        F[i][j] += T[i][k]
               * T[k + 1][j]
                   + F[i][k]
               * F[k + 1][j];
    }
}
}
}
return T[0][n - 1];
}
 
    public static void main(String[] args)
    {
    	Scanner sc=new Scanner(System.in);
    	System.out.println("Enter the symbols:");
        char symbols[] = sc.next().toCharArray();
        System.out.println("Enter the operators:");
        char operators[] = sc.next().toCharArray();
        int n = symbols.length;
 
        System.out.println("Result: "+
            countParenth(symbols, operators, n));
    }

}
