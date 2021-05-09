# Here we are printing the matrix in clockwise direction

def spiral_clockwise(rows, cols, matrix):

    row_start = 0
    row_end = rows - 1
    col_start = 0
    col_end = cols - 1
    count = 0

    while(count < rows*cols):

        if count < rows*cols:

            for cur in range(col_start, col_end + 1):

                count += 1
                print(matrix[row_start][cur], end=" ")

        row_start += 1

        if count < rows*cols:

            for cur in range(row_start, row_end + 1):

                count += 1
                print(matrix[cur][col_end], end=" ")

        col_end -= 1

        if count < rows*cols:

            for cur in range(col_end, col_start - 1, -1):

                count += 1
                print(matrix[row_end][cur], end=" ")

        row_end -= 1
        if count < rows*cols:
            for cur in range(row_end, row_start - 1, -1):

                count += 1
                print(matrix[cur][col_start], end=" ")

        col_start += 1


def main():
    rows = int(input())
    columns = int(input())
    matrix = [[int(input()) for element in range(columns)] for row in range(rows)]

    spiral_clockwise(rows, columns, matrix)


if __name__ == "__main__":
    main()


"""
        Test case 1:

        4 4         //no of rows and columns

        11 12 13 14 //matrix
        21 22 23 24
        31 32 33 34
        41 42 43 44

        OUTPUT:

        11 12 13 14 24 34 44 43 42 41 31 21 22 23 33 32


        
        Test case 2:
        
        6 4
        
        11 13 15 17
        19 12 14 16
        18 10 21 23
        25 27 29 22
        24 26 28 30
        31 33 35 37
        
        OUTPUT:
        
        11 13 15 17 16 23 22 30 37 35 33 31 24 25 18 19 12 14 21 29 28 26 27 10

        
        
        Test case 3:

        1 4

        11 12 13 14

        OUTPUT:

        12 12 13 14

"""