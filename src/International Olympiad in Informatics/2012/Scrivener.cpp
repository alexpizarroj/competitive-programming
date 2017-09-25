#include<iostream>
#include<cmath>
#include<vector>
using namespace std;

char T[1000001];
int dad[1000001], dadH[1000001], H[1000001];
vector<int> v;
int act, it;

void Init() {
	it = 1;
	act = 0;
	H[0] = -1;
	dad[0] = dadH[0] = 0;
	v.clear();
}

void TypeLetter(char L) {
	T[it] = L;
	H[it] = H[act]+1;
	dad[it] = act;
	if(H[it] % 1000 == 0)
		dadH[it] = it;
	else
		dadH[it] = dadH[act];
	v.push_back(it);
	act = it++;
}

void UndoCommands(int U) {
	act = v[v.size() - U - 1];
	v.push_back(act);
}

char GetLetter(int P) { // O(sqrt(H))
	int i = act;
	while(H[ dadH[i] ] > P) i = dadH[i];// O(sqrt(H))
	while(H[ dad[i] ] >= P) i = dad[i]; // O(sqrt(H))
	return T[i];
}

int main(){
	Init();
	TypeLetter('a');			//  a
	TypeLetter('b');			//  ab
	cout<<GetLetter(1)<<endl;	//b ab
	TypeLetter('d');			//  abd
	UndoCommands(2);			//  a
	UndoCommands(1);			//  abd
	cout<<GetLetter(2)<<endl;	//d abd
	TypeLetter('e');			//  abde
	UndoCommands(1);			//  abd
	UndoCommands(5);			//  ab
	TypeLetter('c');			//  abc
	cout<<GetLetter(2)<<endl;	//c abc
	UndoCommands(2);			//  abd
	cout<<GetLetter(2)<<endl;	//d abd
}
