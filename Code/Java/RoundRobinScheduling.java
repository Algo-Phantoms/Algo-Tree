import java.util.LinkedList;
import java.util.Queue;
import java.util.Scanner;

public class RoundRobinScheduling {
    public static void main(String[] args) {
        Scanner scan = new Scanner(System.in);

        System.out.print("Enter number of processes: ");
        int processes = scan.nextInt();

        int burstTime[] = new int[processes];
        System.out.print("Enter burst times: ");
        for (int i = 0; i < processes; i++) {
            burstTime[i] = scan.nextInt();
        }

        System.out.print("Enter time quantum: ");
        int timeQuantum = scan.nextInt();

        Queue<Integer> q = new LinkedList<Integer>();

        for (int i = 0; i < processes; i++) {
            q.add(i);
        }

        System.out.print("The order of execution of processes in the queue is ");

        while (!q.isEmpty()) {
            int pid = q.poll();

            System.out.print(" p" + (pid + 1) + " ");

            burstTime[pid] -= timeQuantum;
            if (burstTime[pid] > 0) {
                q.add(pid);
            }
        }

        System.out.println("\nExecution of all processes is completed!");

        scan.close();
    }

    /*
    Enter number of processes: 3
    Enter burst times: 10 20 5
    Enter time quantum: 5
    The order of execution of processes in the queue is  p1  p2  p3  p1  p2  p2  p2
    Execution of all processes is completed!
    */
}
