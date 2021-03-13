import java.util.*;
class node
{
	int data;
	node next;
	node(int data)
	{
		this.data=data;
	}
}
class operation
{
	node start;
	void insert_first(int d)
	{
		node newnode=new node(d);
		newnode.next=start;
		start=newnode;
	}
	void delete_first()
	{
		start=start.next;
	}
	void traversal()
	{
		node ptr;
		ptr=start;
		if(ptr==null)
		{
			System.out.println("empty");
			return;
		}
		while(ptr!=null)
		{
			System.out.println(ptr.data+"\t");
				ptr=ptr.next;
		}
	}
	void insert_after(int key,int data)
	{
		if(start==null)
		{
			System.out.println("empty");
			return;
		}
		node ptr=start;
		while(ptr!=null)
		{
			if(ptr.data==key)
			{
				node newnode=new node(data);
				newnode.next=ptr.next;
				ptr.next=newnode;
				return;
			}
			ptr=ptr.next;
		}
		System.out.println("elements found");
	}
	/*void delete_key(int key)
	{
		node ptr=start;
		node prev=start;
		while(ptr.data!=key)
		{
			if(ptr.next==null)
			{
				System.out.println("elements not found");
				return;
			}
			prev=ptr;
				ptr=ptr.next;
			
			if(ptr==start)
				start=start.next;
			else
				prev.next=ptr.next;
		}
	}*/
	void delete_key(int key)
	{
		if(start==null)
		{
			System.out.println("empty list");
			return;
		}
		if(start.data==key)
		{
			start=start.next;
			return;
		}
		node ptr=start;
		while(ptr.next!=null)
		{
			if(ptr.next.data==key)
			{
				ptr.next=ptr.next.next;
				return;
			}
			ptr=ptr.next;
		}
		System.out.println("key not found");
	}
	void insert_last(int data)
	{		
		node newnode=new node(data);
		{
			if(start==null)
			{
				System.out.println("empty list");
				return;
			}
			node ptr=start;
			while(ptr.next!=null)
				ptr=ptr.next;
			ptr.next=newnode;
		}
	}
	void delete_last()
	{
		if(start==null)
		{
			System.out.println("empty list");
			return;
		}
		if(start.next==null)
		{
			start=null;
			return;
		}
		node ptr=start;
		while(ptr.next.next!=null)
			ptr=ptr.next;
		ptr.next=null;
	}
}
class linkedlist
{
	public static void main(String[] args) 
	{
		Scanner s=new Scanner(System.in);
		int c;
		int key;
		int data;
		operation o=new operation();
		do
		{
			System.out.println("enter your choice 1:insert_first 2:delete 3:traversal 4:insert_after 5:DELETE-KEY 6:insert_last 7:delete_last 8:exit");
			c=s.nextInt();
			switch(c)
			{
				case 1:
				System.out.println("enter data");
				data=s.nextInt();
				o.insert_first(data);
				break;
				case 2:
				o.delete_first();
				break;
				case 3:
				System.out.println("the element of linklist");
				o.traversal();
				break;
				case 4:
				System.out.println("enetr key");
				key=s.nextInt();
				System.out.println("eneter data");
				data=s.nextInt();
				o.insert_after(key,data);
				break;
				case 5:
				System.out.println("eneter key");
				key=s.nextInt();
				o.delete_key(key);
				break;
				case 6:
				System.out.println("enter data");
				data=s.nextInt();
				o.insert_last(data);
				break;
				case 7:
				o.delete_last();
				break;
			}
		}
		while(c<8);
	}
}
