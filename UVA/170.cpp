#include <iostream>
#include <queue>
#define SIZE 14

using namespace std;

static queue<char*> decks[SIZE];

inline void clear(queue<char*> &q ) { queue<char*> empty; swap(q, empty); }


int toIdx(char c) {
    if(c>=50 && c<=58) return c-48;
    if(c=='A') return 1;
    else if(c=='T') return 10;
    else if(c=='J') return 11;
    else if(c=='Q') return 12;
    else if(c=='K') return 13;
}

int main() {
    int d, playedCards;
    int i,j;
    char* card;

    while (1) {
        // Lectura de entrada
        for(i=1;i<SIZE;i++) clear(decks[i]);
        for(i=0;i<4;i++) {
            for(j=SIZE-1;j>0;j--) {
                card = new char[2]; cin >> card;
                if(i==0 && j==SIZE-1 && card[0]=='#') return 0;
                decks[j].push(card);
            }
        }
        // Jugamos
        playedCards=0; d=13;
        while (decks[d].size()>0) {
            card = decks[d].front();
            decks[d].pop();

            d=toIdx(card[0]);
            playedCards+=1;
        }
        /*//Mostramos con cuántas cartas queda cada mazo
        for(i=1;i<SIZE;i++) {
            cout << (i>1 ? " " : "") << decks[i].size();
        }
        cout << endl;*/
        // Respuesta
        cout << (playedCards<10 ? "0" : "") << playedCards << "," << card << endl;
    }

    return 0;
}


/*
TS QC 8S 8D QH 2D 3H KH 9H 2H TH KS KC
9D JH 7H JD 2S QS TD 2C 4H 5H AD 4D 5D
6D 4S 9S 5S 7S JS 8H 3D 8C 3S 4C 6S 9C
AS 7C AH 6H KD JC 7D AC 5C TC QD 6C 3C
*/
