//Prefix tree - trie
// for reoccuring characters
#include<iostream>
#include<map>
#include<string>
#include<queue>
#include<list>
using namespace std;

class node{
public:

	char data;
	map<char,node*> m;
	bool is_terminal;

	node(char c){
		data = c;
		is_terminal = false;
	}
	
};

class Trie{
    node* root;
public:

	Trie(){
		root = new node('\0');
	}

	void Addword(char word[]){
		node* temp = root;

		for(int i=0;word[i]!='\0';i++){
			char ch = word[i];

			if(temp->m.count(ch)==0){ //if not present

                node* child = new node(ch);
                temp->m[ch] = child; // create link
                temp = child;
			}
			else{

				temp = temp->m[ch]; // next address

			}
		}

		temp->is_terminal = true; // last node
	}

	bool search(char word[]){

		node* temp = root;

		for(int i=0;word[i]!='\0';i++){

			char ch = word[i];

			if(temp->m.count(ch)==1){ // if present 
                 temp = temp->m[ch];
			}
			else{ // not present
               return false;
			}
			
		}
    return temp->is_terminal; // not always at last node
	}


};
int main()
{
	Trie T;
	T.Addword("adf");
	T.Addword("not");
	T.Addword("nott");

	char word[1000];
	cin >> word;



	cout << boolalpha<<T.search(word);
	
	return 0;
}

/* Test Case -

Input - adf
Output - true
*/