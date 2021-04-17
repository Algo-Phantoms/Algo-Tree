/*
 *                    Implementation of Queue
 *         
 * Queue is a linear structure which follows a particular order in 
 * which the operations are performed. 
 * The order is First In First Out (FIFO).
 */
import java.util.*;
class Queue {
    int front, rear, size;
    int capacity;
    int array[];

    public Queue(int capacity)
    {
        this.capacity = capacity;
        front = this.size = 0;
        rear = capacity - 1;
        array = new int[this.capacity];
    }

    boolean isFull(Queue queue)
    {
        return (queue.size == queue.capacity);
    }

    boolean isEmpty(Queue queue)
    {
        return (queue.size == 0);
    }

    void enqueue(int item)
    {
        if (isFull(this))
            return;
        this.rear = (this.rear + 1)        % this.capacity;
        this.array[this.rear] = item;
        this.size = this.size + 1;
        System.out.println(item
            + " enqueued to queue");
    }

    int dequeue()
    {
        if (isEmpty(this))
            return Integer.MIN_VALUE;

        int item = this.array[this.front];
        this.front = (this.front + 1)        % this.capacity;
        this.size = this.size - 1;
        return item;
    }

    int front()
    {
        if (isEmpty(this))
            return Integer.MIN_VALUE;

        return this.array[this.front];
    }

    int rear()
    {
        if (isEmpty(this))
            return Integer.MIN_VALUE;

        return this.array[this.rear];
    }

    public static void main(String[] args)
    {
        Scanner in=new Scanner(System.in);
        Queue queue = new Queue(1000);
        System.out.println("No. of elements to be added in Queue :");
        int n=in.nextInt();
        for(int i=0;i<n;i++)
        {
            int input=in.nextInt();
            queue.enqueue(input);

        }

        System.out.println("Front item is "
            + queue.front());
        System.out.println(queue.dequeue()
            + " dequeued from queue\n");
        System.out.println("Front item is "
            + queue.front());

        System.out.println("Rear item is "
            + queue.rear());

            in.close();
    }
}

/*
 * Test Case :
 * Input : No. of elements to be added in Queue :
 * 5 
 * 1 2 3 4 5
 * Output :
 * 1 enqueued to queue
   2
   2 enqueued to queue
   3
   3 enqueued to queue
   4
   4 enqueued to queue
   5
   5 enqueued to queue
   
   Front item is 1
   1 dequeued from queue

   Front item is 2
   Rear item is 5
   
 * Time  Complexity is
 * Insertion(Enqueue) O(1) 
 * Deletion(Dequeue)  O(1) 
 * Space Complexity is O(n) , n is the size of the Queue.
 */