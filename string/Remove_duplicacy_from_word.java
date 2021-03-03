package mypack;
import java.util.*; 
 public class Remove {


 /*recursive function calduplicacy() eliminates duplicate characters by adding characters to the new string if a new character is found in the 0th index of original string.
 The original string is then trimmed by deleting the first character each time till it becomes null.*/
 public int recur;
 String newstring;

 Remove()
 {
 recur=0;
 newstring="";
 } 


   public void calduplicacy(String original)  
 { 	
    if(original.equals(""))
    {
    System.out.println("After removal of duplicate characters: "+newstring);

    }
    else{
        if(recur==0)
       { newstring=original.charAt(0)+newstring;}
        else{
            char ch=original.charAt(0);int count=0;
            for(int charcount=0;charcount<newstring.length();charcount++)
            {
                if(ch==newstring.charAt(charcount)||ch==(char)(newstring.charAt(charcount)+32)||ch==(char)(newstring.charAt(charcount)-32))
                count++;
            }
            if(count==0)
            newstring=newstring+ch;
        }
            recur++; calduplicacy(original.substring(1));
    }
}

    public static void main(String[] args)
    {
        Scanner scan=new Scanner(System.in);

        System.out.println("Enter a word");
        String input=scan.nextLine();
        Remove d=new Remove();
        d.calduplicacy(input);
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

