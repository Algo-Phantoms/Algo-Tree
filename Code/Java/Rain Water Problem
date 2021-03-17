class Main
{
    
    public static int trap(int[] bars)
    {
        int n = bars.length;
        int water = 0;
 
        int[] left = new int[n-1];
        left[0] = Integer.MIN_VALUE;

        for (int i = 1; i < n - 1; i++) {
            left[i] = Integer.max(left[i - 1], bars[i - 1]);
        }
 
        /*
        int[] right = new int[n];
        right[n - 1] = Integer.MIN_VALUE;
        for (int i = n - 2; i >= 0; i--) {
            right[i] = Integer.max(right[i + 1], bars[i + 1]);
        }
 
        for (int i = 1; i < n - 1; i++)
        {
            if (Integer.min(left[i], right[i]) > bars[i]) {
                water += Integer.min(left[i], right[i]) - bars[i];
            }
        }
        */
 
        
        int right = Integer.MIN_VALUE;
 
       
        for (int i = n - 2; i >= 1; i--)
        {
            right = Integer.max(right, bars[i + 1]);
 
        
            if (Integer.min(left[i], right) > bars[i]) {
                water += Integer.min(left[i], right) - bars[i];
            }
        }
 
        return water;
    }
 
    public static void main(String[] args)
    {
        int[] heights = { 7, 0, 4, 2, 5, 0, 6, 4, 0, 5 };
 
        System.out.print("The maximum amount of water that can be trapped is " +
                                trap(heights));
    }
}


