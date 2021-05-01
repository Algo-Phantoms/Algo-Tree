//Class node which contains node of a linked list
//It contains function for inserting node
public class Node{
    int data;
    Node next;
    Node(){}
    Node(int data){
        this.data = data;
    }
    Node head;

    //method for insertion of data
    void insert(int data){
        if(head == null){
            head = new Node(data);
            return;
        }
        Node temp = head;
        while(temp.next!=null){
            temp = temp.next;
        }
        temp.next = new Node(data);
    }
    
    //method to show data
    void show(){
        Node temp = head;
        while(temp!=null){
            System.out.print(temp.data+" ");
            temp = temp.next;
        }
        System.out.println();
    }
}

/*
Input:
[1,2,3,4]
Output:
[1,2,3,4]
*/
