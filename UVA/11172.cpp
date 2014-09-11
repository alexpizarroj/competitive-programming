#include <iostream>

using namespace std;

int main() {
    int t,i,a,b;

    cin >> t;
    for(i=0;i<t;i++) {
        cin >> a >> b;
        if (a<b) cout << "<" << endl;
        else if (a>b) cout << ">" << endl;
        else cout << "=" << endl;
    }

    return 0;
}
