#include <stdio.h>
#include <sstream>
#include <memory.h>
#include <string.h>
#include <algorithm>

using namespace std;

struct TEAM {
    char *name, *lowername;
    int nameLen;
    int points, games, wins, ties, losses, scored, against, diff;
};

static TEAM teams[30];
static int T;
static int i, j, k;

bool cmpTeam_nameCS (TEAM a, TEAM b) { return strcmp(a.name, b.name) < 0; }

bool cmpTeam(TEAM a, TEAM b) {
    if(a.points != b.points) return a.points > b.points;
    if(a.wins != b.wins) return a.wins > b.wins;
    if(a.diff != b.diff) return a.diff > b.diff;
    if(a.scored != b.scored) return a.scored > b.scored;
    if(a.games != b.games) return a.games < b.games;
    return strcmp(a.lowername, b.lowername) < 0;
}

TEAM *findTeam(const char* name) {
    int first = 0, last = T-1, mid;
    while (first <= last) {
        mid = (first + last) / 2;
        if ( strcmp(name, teams[mid].name) > 0)
            first = mid + 1;
        else if ( strcmp(name, teams[mid].name) < 0)
            last = mid - 1;
        else
            return &teams[mid];
    }
    return NULL;
}

int u_toint(const char* str) {
    int ret;
    stringstream ss(str); ss >> ret;
    return ret;
}


int main() {
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    #endif

	int N, G;
	int goals[2]; char* teamn[2]; TEAM *team[2];
	char tournamentName[101], *teamName, match[70], *pstr;
	bool gettingTeam, firstDone = false;

	memset(tournamentName, 0, 101);
	memset(match, 0, 70);

	scanf("%d\n", &N);
	while (N--) {
	    // Entrada
        gets(tournamentName);
        scanf("%d\n", &T);
        for(i = 0; i != T; i++) {
            teamName = new char[31];
            gets(teamName);
            j = strlen(teamName);
            //
            teams[i].name = teamName;
            teams[i].nameLen = j;
            teams[i].points = 0;
            teams[i].games = 0;
            teams[i].wins = 0;
            teams[i].ties = 0;
            teams[i].losses = 0;
            teams[i].scored = 0;
            teams[i].against = 0;
            teams[i].diff = 0;
            //
            teamName = new char[31];
            memcpy(teamName, teams[i].name, 31);
            for(k = 0; k != j; k++) teamName[k] = tolower(teamName[k]);
            teams[i].lowername = teamName;
        }
        sort(teams, teams+T, cmpTeam_nameCS);
        // Resolucion
        scanf("%d\n", &G);
        i = G; while(i--) {
            gets(match);
            gettingTeam = true; j = 0;
            pstr = strtok(match, "#@");
            while (pstr != NULL) {
                if(gettingTeam) {
                    teamn[j] = pstr;
                    gettingTeam = false;
                } else {
                    goals[j] = u_toint(pstr);
                    gettingTeam = (j == 0 ? false : true);
                    if(!j) j++;
                }

                pstr = strtok(NULL, "#@");
            }
            team[0] = findTeam(teamn[0]);
            team[1] = findTeam(teamn[1]);
            if (goals[0] > goals[1]) {
                team[0]->points += 3;
                team[0]->wins += 1;
                team[1]->losses += 1;
            } else if (goals[1] > goals[0]) {
                team[1]->points += 3;
                team[1]->wins += 1;
                team[0]->losses += 1;
            } else {
                team[0]->points += 1;
                team[1]->points += 1;
                team[0]->ties += 1;
                team[1]->ties += 1;
            }
            team[0]->scored += goals[0];
            team[0]->against += goals[1];
            team[1]->scored += goals[1];
            team[1]->against += goals[0];
            team[0]->games += 1;
            team[1]->games += 1;
        }
        for(i = 0; i != T; i++) teams[i].diff = teams[i].scored - teams[i].against;
        sort(teams, teams+T, cmpTeam);
        // Salida
        if(firstDone) printf("\n");
        printf("%s\n", tournamentName);
        for(i = 0; i != T; i++) {
            printf("%d) %s %dp, %dg (%d-%d-%d), %dgd (%d-%d)\n",
                   i+1, teams[i].name, teams[i].points, teams[i].games, teams[i].wins, teams[i].ties, teams[i].losses,
                   teams[i].diff, teams[i].scored, teams[i].against);
        }
        firstDone = true;
	}

    return 0;
}
