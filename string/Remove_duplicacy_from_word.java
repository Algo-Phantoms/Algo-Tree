
import java.util.*;  // Calling the util package
 public class Remove {
   
    
 /*recursive function calduplicacy() eliminates duplicate characters by adding characters to the new string if a new character is found in the 0th index of original string.
 The original string is then trimmed by deleting the first character each time till it becomes null.*/


   public void calduplicacy(String original,String nestring)  
{
    if(original.equals(""))
    {
    System.out.println("After removal of duplicate characters: "+nestring);
    
    }
    else{
        if(nestring.equals(""))
       { nestring=original.charAt(0)+nestring;}
        else{
            char ch=original.charAt(0);int count=0;
            for(int charcount=0;charcount<nestring.length();charcount++)
            {
                if(ch==nestring.charAt(charcount)||ch==(char)(nestring.charAt(charcount)+32)||ch==(char)(nestring.charAt(charcount)-32))
                count++;
            }
            if(count==0)
            nestring=nestring+ch;
        }
            calduplicacy(original.substring(1),nestring);
    }
}
   
    public static void main(String args[])
    {
        Scanner scan=new Scanner(System.in);
        
        System.out.println("Enter a word");
        String input=scan.nextLine();
        Remove d=new Remove();
        d.calduplicacy(input,"");
    }
    
}

/* 		OUTPUT:


 Test Case 1:

 Enter a word
 Mississippi
 After removal of duplicate characters: Misp

 Test Case 2:

 Enter a word
 Repository
 After removal of duplicate characters: Reposity

 Test Case 3: 
 Enter a word
 PneumonoultrAmicroscopIcsilicovolCanoconIOsis
 After removal of duplicate characters: PneumoltrAicsv


*/

