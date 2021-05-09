/*Problem Statement: 
Given an integer array containing digits from [0, 9], 
the task is to print all possible letter combinations that the numbers could represent. */

#include<bits/stdc++.h>
using namespace std;

char keypad[][10]={" ","ABC","DEF","GHI","JKL","MNO","PQRS","TUV","WXYZ"};

void generate_names(char *in,char *out,int i,int j)
{
	//Base case
	if(in[i]=='\0')
	{
		out[j]='\0';
		cout<<out<<endl;
		return;
	}
	int digit=in[i]-'0';
	for(int k=0;keypad[digit][k]!='\0';k++)
	{
		out[j]=keypad[digit][k];
		//filling the remaining part
		generate_names(in,out,i+1,j+1);
	}
	return;
}
int main()
{
	char in[100]; //Denotes the input string
	cin>>in;
	char out[100]; //Denotes the output string
	generate_names(in,out,0,0);
	return 0;
}
/* Testcases :
1) Input : 23
Output :
DG
DH
DI
EG
EH
EI
FG
FH
FI
2) Input : 67
Output : 
PT
PU
PV
QT
QU
QV
RT
RU
RV
ST
SU
SV 
Time Complexity : O(4^n)
Space Complexity : O(n) 
Here, n denotes the no of characters present in the input string
*/

