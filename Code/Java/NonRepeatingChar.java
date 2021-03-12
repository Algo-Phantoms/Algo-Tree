// Java program to find first non-repeating character in a string
import java.util.*;

public class Main {
 public static void main(String[] args) {
  Scanner sc = new Scanner(System.in);
  String str;
  str = sc.nextLine();
  System.out.println("The given string is: " + str);
  for (int i = 0; i < str.length(); i++) {
   boolean flag = true;
   for (int j = 0; j < str.length(); j++) {
    if (i != j && str.charAt(i) == str.charAt(j)) {
     flag = false;
     break;
    }
   }
   if (flag) {
    System.out.println("The first non repeated character in the given string is: " + str.charAt(i));
    break;
   }
  }
 }
}
