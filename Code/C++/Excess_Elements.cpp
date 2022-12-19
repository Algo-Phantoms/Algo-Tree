/*
This program is to find the excess elements from one of the two arrays entered by the user.
C language is implemented here. Each of the element is compared with the element of the other array only if the corresponding position of the 
pos array is not assigned as compared and equated (ie 0).
It then prints the excess elements of the second array.
*/

#include <iostream>
using namespace std;

void Extra(int a[10], int b[10], int pos[10], int m, int n)
{
    int i,j;
            //Loop for comparing the elements
        for(int  i=0;i<m;i++)
                       for(int j=0;j<n;j++)
                        //This condition tells us that corresponding elements in array b is not present in array a
                        if(pos[j]==0)
                                if(a[i]==b[j]){
                                        //So that the corresponding element in b wont be considered again later
                                        pos[j]=1;
                                        break;
                                }
        

        cout << "The Excess Elements are: ";
        for(int i=0;i<n;i++)
        {
                //If the positions were 0, that tells us elements in those positions are not equal to the elements in the corresponding positons in array a.
                if(pos[i]==0)
                    {
                        cout << b[i];
                        cout << " ";
                    }
        }
        cout << "\n";
}

int main()
{
        int a[10], b[10],pos[10], m,n;
        cout<<"Enter the size of both the arrays\n";   
        //Reads the size of both the arrays

        cin >> m;
        cin >> n;
        //Inputs the elements of the first array
        cout <<"Enter the first array: ";  
        for(int i=0;i<m;i++)
                cin >> a[i] ;
        //Inputs along with the extra elements of the second array 
        cout << "Enter the second array (With the excess elements): ";
        for(int j=0;j<n;j++){
                cin >> b[j];
                pos[j]=0;  // Corrseponding array used for comparison
        }
        Extra(a, b, pos,  m, n);

        return 0;
}

/*

Sample Input: 
Enter the size of both the arrays
4
7
Enter the elements of first array: 1 2 3 4 
Enter the elements of second array: 1 2 3 4 5 6 7

Sample Output:
Excess elements: 5 6 7 

Time Complexity: O(m*n) (Worst case)
Space Complexity: O(n*m)
*/
