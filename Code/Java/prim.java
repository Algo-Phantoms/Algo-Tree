import java.util.Scanner;
public class prim
{
    static Scanner scan;
    public static void main(String args[])
    {
        scan=new Scanner(System.in);
        int graph[][]=new int[7][7];
        //0=a,1=b,2=c,3=d,4=e,5=f,6=z
        int visited[]=new int[7];
        int min=999;int u=0;int v=0;int total=0;
        {
            int i=0;
            while (i<7) {
                visited[i]=0;
                int j=0;
                while (j<7) {
                    graph[i][j]=scan.nextInt();
                    if(graph[i][j]==0)
                    {
                        graph[i][j]=999;
                    }
                    j++;
                }
                i++;
            }
        }
        visited[0]=1;
        int count=0;
        while (count<6) {
            min=999;
            for(int i=0;i<7;i++)
            {
                if(visited[i]==1)
                {
                    int j=0;
                    while (j<7) {
                        if(visited[j]==0)
                        {
                            if(min>graph[i][j])
                            {
                                min=graph[i][j];
                                u=i;
                                v=j;
                            }
                        }
                        j++;
                    }
                }
            }
            visited[v]=1;
            total=total+min;
            System.out.println("Edge"+u+"--->"+v+": Weight :"+min);
            count++;
        }
        System.out.println("The Weight of the minimum spanning tree is:"+total);
    }
}
/*
0=a,1=b,2=c,3=d,4=e,5=f,6=z
0 4 3 0 0 0 0
4 0 0 0 12 5 0
3 0 0 7 10 0 0
0 0 7 0 2 0 0
0 0 10 2 0 0 5
0 5 0 0 0 0 16
0 0 0 0 5 16 0
Edge0--->2: Weight :3
Edge0--->1: Weight :4
Edge1--->5: Weight :5
Edge2--->3: Weight :7
Edge3--->4: Weight :2
Edge4--->6: Weight :5
The Weight of the minimum spanning tree is:26
 */
