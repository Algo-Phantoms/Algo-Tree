package openSource;

/*
 Given an array consisting of 0s,1s and 2s.The task is to write a function that sorts the given array.
 The function should put all 0s first,then all 1s and all 2s in last.
*/

class Seg01and2
{
    // Function to sort the given array, the array is assumed to have values in between 0,1 and 2.

    public void Segregate01and2(int a[])
    {
        int len = a.length;
        int low = 0;
        int mid = 0;
        int high = len - 1;

        while (mid <= high)
        {
            switch (a[mid])
            {
                // If the value is 0 then swap low and mid values and increase both mid and low by one.

                case 0:
                    {
                        int temp = a[low];
                        a[low] = a[mid];
                        a[mid] = temp;
                        low++;
                        mid++;
                        break;
                    }

                // If the value is 1 then increase mid by one.

                case 1:
                    {
                        mid++;
                        break;
                    }

                // If the value is 2 then swap mid and high values and decrease the high value by one.

                case 2:
                    {
                        int temp = a[high];
                        a[high] = a[mid];
                        a[mid] = temp;
                        high--;
                        break;
                    }
            }
        }
    }

    //Function to print the array.

    public void print(int a[])
    {
        for (int ele : a)
        {
            System.out.print(ele + " ");
        }
    }
}

//Driver function to check for above functions.
public class Segregate01and2
{
    public static void main(String[] args)
    {
        System.out.println("Dutch National Flag Algorithm. ");

        int a[] = {1, 0, 2, 1, 0, 2, 1, 0, 0, 1,0};

        Seg01and2 arr = new Seg01and2();
        arr.Segregate01and2(a);
        arr.print(a);


    }
}
