//Java program to merge K-sorted linked list.
//User will provide k sorted linked list and program will merge them and return the listed list in sorted order.

import java.util.*;

public class MergedKSortedLinkedList{

    //class which store data and next pointer of the head pointer
    class Node{
        int data;
        Node next;
        Node(int data){
            this.data = data;
            next = null;
        }
    }
    Node head;

    MergedKSortedLinkedList(){
        head = null;
    }

    //Method for storing data into linked list
    void InsertEnd(int data){
        if(head == null){
            head = new Node(data);
            return;
        }
        Node temp = head;
        while(temp.next!=null)
            temp = temp.next;
        temp.next = new Node(data);
    }

    //Method to display linked list
    void showLinkedList(){
        Node temp = head;
        while(temp!= null){
            System.out.println(temp.data+" ");
            temp = temp.next;
        }
    }


    //main method
    public static void main(String args[]){
        
        Scanner scanner = new Scanner(System.in);
        System.out.println("Enter number of Linked List");
        int k = scanner.nextInt();
        MergedKSortedLinkedList ll[] = new MergedKSortedLinkedList[k];
        for(int i=0;i<k;i++){
            ll[i] = new MergedKSortedLinkedList();
            System.out.println("Enter number of elements for "+(i+1)+" Linked List");
            int n = scanner.nextInt();
            for(int j=0;j<n;j++){
                System.out.println("Enter "+(j+1)+" element for "+ (i+1)+" Linked List");
                ll[i].InsertEnd(scanner.nextInt());
            }
        }
        ll[0].showLinkedList();
        scanner.close();
    }
}