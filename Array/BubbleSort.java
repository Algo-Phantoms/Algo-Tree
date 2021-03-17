import java.util.Scanner;

public class BubbleSort {
    static void bubblesort(int arr[],int n){
        int i,j,temp;
        for(i=0;i<n-1;i++){
            for(j=0;j<n-1-i;j++){
                if(arr[j+1]<arr[j]){
                    temp=arr[j];
                    arr[j]=arr[j+1];
                    arr[j+1]=temp;

                }
            }
        }
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
        bubblesort(arr, n);
        printArray(arr, n);
}

}

