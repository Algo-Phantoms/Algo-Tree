#include<iostream> // for `i/o operation`
#define N 3 // defining size `N`

/*
function to swap values of two valiables
*/
void swap(int &num1, int &num2){
    int temp = num1;
    num1 = num2;
    num2 = temp;
}

/*
function to print the matrix in matrix form
*/
void printMatrix(int matrix[N][N]){
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            std::cout<< "["<< matrix[i][j]<< "]\t";
        }
        std::cout<< std::endl;
    }
}

/*
main function or the driver function
*/
int main(){
    /* ###Test Case:
    Matrix:
        1 2 3
        4 5 6
        7 8 9
    After Rotation:
        3 6 9
        2 5 6
        7 8 9
    */
    
    // Initializing matrix
    int matrix[N][N] = {
                        {1, 2, 3},
                        {4, 5, 6},
                        {7, 8, 9}
                    };
    std::cout<< "\nInitial Matrix Is: "<< std::endl;
    printMatrix(matrix);

    for(int i = 0; i < N; i++){
        for(int j = i; j < N; j++){
            swap(matrix[i][j], matrix[j][i]);
        }
    }
    // std::cout<< "\nTranspose Of Matrix Is: "<< std::endl;
    // printMatrix(matrix);

    for(int i = 0; i < N; i++){
        int start = 0, end = N-1;

        while(start < end){
            swap(matrix[start][i], matrix[end][i]);
            start += 1;
            end -= 1;
        }
    }
    std::cout<< "\n90` Rotation Of Matrix Is: "<< std::endl;
    printMatrix(matrix);

    return 0;
}