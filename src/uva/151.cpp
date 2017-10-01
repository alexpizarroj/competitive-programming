#include <iostream>
#include <memory.h>
#include <algorithm>
#include <vector>

using namespace std;


inline bool contiene(const vector<int>* v, int value) {
    return (find(v->begin(), v->end(), value) != v->end());
}

int main() {
    int n, m;
    int i, j, k; //Contadores
    int* seq;
    vector<int> v;

    while (true) {
            cin >> n;
            if (n==0) break;

            if(n==13) {
                cout << "1" << endl;
            } else {
                seq = new int[n]; seq[0]=1; m=4;
                do {
                    m+=1;
                    v.clear(); v.push_back(1); j=0;
                    for(i=1;i<n;i++) {
                        if(j==n) j=0; k=0;
                        while(k<m) {
                            if(!contiene(&v, j+1)) {
                                k++;
                            }
                            j++; if(j==n) j=0;
                        }
                        j=(j==0 ? n : j);
                        seq[i]=j;
                        v.push_back(j);
                    }
                } while(seq[n-1]!=13);

                cout << m << endl;
            }
    }

    return 0;
}
