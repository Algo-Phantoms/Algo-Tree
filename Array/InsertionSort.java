import java.util.Scanner;

public class InsertionSort {

    static void insertionsort(int arr[],int n){
        int i,key,j;
        for(i=0;i<n;i++){
            key=arr[i];
            j=i-1;
            while(j>=0 && arr[j]>key){
                arr[j+1]=arr[j];
                j=j-1;
            }
        }

        arr[j+1] = key;
    }


    static void printArray(int arr[],int size){
        for(int i=0;i<size;i++){
            System.out.print(arr[i] + " ");
          
            System.out.println();
        }
    }
    public static void main(String[] args) {
        Scanner sr = new Scanner(System.in);
        int[] arr = new int[5];
        int n = arr.length;
        for (int i = 0; i < n; i++) {
           
            arr[i] = sr.nextInt();

        }
        insertionsort(arr, n);
        printArray(arr, n);
}
}
