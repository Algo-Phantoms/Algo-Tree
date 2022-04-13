import java.util.Scanner;

class DemoCheckPalindrome{
public static void main(String args[]){
  Scanner sc=new Scanner(System.in);
  int n=sc.nextInt();
  String str="";
  int temp=n;
  while(n>0){
     str+=n%10;
     n/=10;
  }
   if(Integer.parseInt(str)==temp)
    System.out.println("Number is Palindrome");
   else System.out.println("Number is not a Palindrome");
  }
}
