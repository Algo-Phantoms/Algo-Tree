import java.util.Scanner;

public class check_prime {
    public static void main(String[] args){
        Scanner scan = new Scanner(System.in);
        System.out.println("Enter No : ");
        int n = scan.nextInt();
        System.out.println(isPrime(n));
    }
    public static boolean isPrime(int n) {
        int count = 0;
        for (int i =2 ;i<n ; i++){
            if (n%i==0){
                return false;
            }
        }
        return true;
    }
}
