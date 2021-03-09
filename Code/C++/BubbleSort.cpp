#include<iostream>
using namespace std;

class bubsort
{
public:
	int arr[10], n;


	void getdata();
	void display();
	void sort();
};


void bubsort :: getdata()
{
	cout<<"Enter the size of array: ";
	cin>>n;
	cout<<"Accept the array elements: ";

	for(int i=0; i<n; i++)
		cin>>arr[i];
}


void bubsort :: display()
{
	cout<<"sorted array: ";
	for(int i=0; i<n; i++)
		cout<<arr[i]<<" ";
}


void bubsort :: sort()
{
	for(int i=n-1; i>0; i--)
	{
		for(int j=0; j<i; j++)
		{
			int temp;
			if(arr[j]>arr[j+1])
			{
				temp=arr[j];
				arr[j]=arr[j+1];
				arr[j+1]=temp;
			}
		}
	}
}

int main()
{

	bubsort b;
	b.getdata();
	b.display();
	return 0;
}
