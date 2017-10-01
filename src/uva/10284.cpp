#include <iostream>
#include <cstdio>
#include <vector>
#include <string>
#include <cstring>
#define PB 				        push_back
#define fup(i,a,b) 		        for(int i = (a); (i) < int(b); i++)
#define fdo(i,a,b) 		        for(int i = (a); (i) > int(b); i--)
#define fupi(i,a,b) 		    for(int i = (a); (i) <= int(b); i++)
#define fdoi(i,a,b) 		    for(int i = (a); (i) >= int(b); i--)
#define foreach(it, a) 	        for(typeof((a).begin()) it=(a).begin(); it != (a).end(); it++)
#define dall(a)		 	        (a).begin(), (a).end()
#define dset(a,v) 		        memset(a, v, sizeof(a))
#define dclr(a)         	 	memset(a, 0, sizeof(a))
using namespace std;

typedef pair<int,int> pii;
template<class T> bool inline between(const T& lb, const T& v, const T& ub) { return lb<=v && v<=ub; }

class Piece
{
public:
    char id; // case insensitive identifier
    bool useOnlyWm, movesHV, movesDiag;
    vector< pii > wm, bm; // white/black moves

    Piece(char id, const vector<pii> &wm,
          bool movesHV = false, bool movesDiag = false,
          bool useOnlyWm = true, const vector<pii> &bm = vector<pii>())
          :
          id(id), useOnlyWm(useOnlyWm), movesHV(movesHV), movesDiag(movesDiag),
          wm(wm), bm(bm) {}
};
vector<Piece> pieces;

class Chess {
    bool safe[10][10];
    char board[10][10];
    int r;
public:
    void runPiece(char id, int r, int c);
    void fromFen(string fen);
    void displayBoard();
    int countEmptyNonAttacked() { return r; }
};

void initPieces()
{
    vector<pii> pwm, pbm;
    pwm.PB( pii(-1, -1) ); pwm.PB( pii(-1, 1) );
    pbm.PB( pii(1, -1) ); pbm.PB( pii(1, 1) );

    vector<pii> nm;
    nm.PB( pii(-2,-1) ); nm.PB( pii(-2,1)  );
    nm.PB( pii(-1,-2) ); nm.PB( pii(-1,2)  );
    nm.PB( pii(1,-2)  ); nm.PB( pii(1,2)   );
    nm.PB( pii(2,-1)  ); nm.PB( pii(2,1)   );

    vector<pii> km;
    km.PB( pii(0,-1) );  km.PB( pii(0,1) );  // h
    km.PB( pii(-1,0) );  km.PB( pii(1,0) );  // v
    km.PB( pii(-1,-1) ); km.PB( pii(1,1) );  // main diag
    km.PB( pii(-1,1) );  km.PB( pii(1,-1) ); // second diag

    Piece p('p', pwm, false, false, false, pbm);
    Piece n('n', nm);
    Piece k('k', km);
    Piece r('r', vector<pii>(), true, false);
    Piece b('b', vector<pii>(), false, true);
    Piece q('q', vector<pii>(), true, true);

    pieces.PB(p); pieces.PB(n); pieces.PB(k); pieces.PB(r); pieces.PB(b); pieces.PB(q);
}

void Chess::runPiece(char id, int r, int c)
{
    char ch = tolower(id);
    fup(a,0,pieces.size())
    {
        if ( pieces[a].id == ch )
        {
            const Piece& p = pieces[a];

            safe[r][c] = false;
            if( p.useOnlyWm || isupper(id) )
            {
                // run white moves
                fup(i,0,p.wm.size())
                {
                    int x = r + p.wm[i].first, y = c + p.wm[i].second;
                    if( between(1,x,8) && between(1,y,8) ) safe[x][y] = false;
                }
            }
            if( !p.useOnlyWm && islower(id) )
            {
                // run black moves
                fup(i,0,p.bm.size())
                {
                    int x = r + p.bm[i].first, y = c + p.bm[i].second;
                    if( between(1,x,8) && between(1,y,8) ) safe[x][y] = false;
                }
            }
            if( p.movesHV )
            {
                int i, j;
                // hor bw
                i = r, j = c - 1;
                while ( board[i][j] == '.' && j >= 1 ) { safe[i][j] = false; j--; }
                // hor fw
                i = r, j = c + 1;
                while ( board[i][j] == '.' && j <= 8 ) { safe[i][j] = false; j++; }
                // ver bw
                i = r - 1, j = c;
                while ( board[i][j] == '.' && i >= 1 ) { safe[i][j] = false; i--; }
                // ver fw
                i = r + 1, j = c;
                while ( board[i][j] == '.' && i <= 8 ) { safe[i][j] = false; i++; }
            }
            if( p.movesDiag )
            {
                int i, j;
                // main diag bw
                i = r - 1, j = c - 1;
                while ( board[i][j] == '.' && i >= 1 && j >= 1 )
                    { safe[i][j] = false; i--, j--; }
                // main diag fw
                i = r + 1, j = c + 1;
                while ( board[i][j] == '.' && i <= 8 && j <= 8 )
                    { safe[i][j] = false; i++, j++; }
                // second diag bw
                i = r - 1, j = c + 1;
                while ( board[i][j] == '.' && i >= 1 && j <= 8 )
                    { safe[i][j] = false; i--, j++; }
                // second diag fw
                i = r + 1, j = c - 1;
                while ( board[i][j] == '.' && i <= 8 && j >= 1 )
                    { safe[i][j] = false; i++, j--; }
            }

            break;
        }
    }
}

void Chess::fromFen(string fen)
{
    int f, c;

    // Board parsing
    f = c = 1;
    fupi(i,1,8) fupi(j,1,8) board[i][j] = '.';
    fup(i,0,fen.size())
    {
        if( fen[i] == '/' ) { f++, c = 1; continue; }
        if( isdigit(fen[i]) )
        {
            c += fen[i]-'0';
        }
        else
        {
            board[f][c] = fen[i];
            c++;
        }
    }

    // Safe squares location process
    dset(safe, true);
    for(f = 1; f <= 8; f++)
    {
        for(c = 1; c <= 8; c++)
        {
            if( board[f][c] != '.' )
            {
                runPiece(board[f][c], f, c);
            }
        }
    }

    // Counting
    r = 0;
    fupi(i,1,8) fupi(j,1,8) if( safe[i][j] ) r++;
}

int main() {
	#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
	#endif

    Chess c;
    char buffer[300];

    initPieces();
	while ( gets(buffer) != NULL )
	{
        c.fromFen(buffer);
        printf("%d\n", c.countEmptyNonAttacked() );
	}

    return 0;
}
