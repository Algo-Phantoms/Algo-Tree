import java.util.Scanner;

public class SelectionSort {
    static void selectionsort(int arr[],int n){
        int i,j,temp;
        for(i=0;i<n;i++){
            for(j=i+1;j<n;j++){
                if(arr[j]<arr[i]){
                    temp=arr[j];
                    arr[j]=arr[i];
                    arr[i]=temp;
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
        selectionsort(arr, n);
        printArray(arr, n);
}

}
