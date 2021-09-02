import java.util.Scanner;
 
public class SegmentTree {
 
    static int[] segArr;
 
    public static void main(String[] args) {
 
        Scanner scn = new Scanner(System.in);
        int[] arr = new int[scn.nextInt()];
 
        // array on which operations / queries will be performed.
        for (int i = 0; i  0) {
            int check = scn.nextInt();
 
            if (check == 1) {
                int ql = scn.nextInt();
                int qr = scn.nextInt();
 
                System.out.println(getQuery(0, 0, arr.length - 1, ql, qr, arr));
            } else {
 
                int idx = scn.nextInt();
                int value = scn.nextInt();
                update(value, idx, 0, 0, arr.length - 1, arr);
 
            }
        }
 
    }
 
    public static int construct(int saIdx, int left, int right, int[] arr) {
        
        if (left == right) {
            
            return segArr[saIdx] = arr[left];
        }
 
   
        int mid = (left + right) / 2;
        int leftChild = construct(2 * saIdx + 1, left, mid, arr);
        int rightChild = construct(2 * saIdx + 2, mid + 1, right, arr);
      
        segArr[saIdx] = leftChild + rightChild;
        return segArr[saIdx];
    }
 
    .
 
    public static int getQuery(int saIdx, int left, int right, int ql, int qr, int[] arr) {
 
        
        if (left > qr || right = ql && right <= qr) {
            return segArr[saIdx];
        } else {

            int mid = (left + right) / 2;
            int leftResult = getQuery(2 * saIdx + 1, left, mid, ql, qr, arr);
            int rightResult = getQuery(2 * saIdx + 2, mid + 1, right, ql, qr, arr);
            return leftResult + rightResult;
        }
 
    }
 
    public static void update(int value, int idx, int saIdx, int left, int right, int[] arr) {
        o simply return.
       
        if (idx  right) {
            return;
        }
        
        if (idx == left && idx == right) {
            arr[left] = value;
            segArr[saIdx] = value;
            return;
        }
        
        else {
            int mid = (left + right) / 2;
            update(value, idx, 2 * saIdx + 1, left, mid, arr);
            update(value, idx, 2 * saIdx + 2, mid + 1, right, arr);
 
            segArr[saIdx] = segArr[2 * saIdx + 1] + segArr[2 * saIdx + 2];
        }
    }
 
}
