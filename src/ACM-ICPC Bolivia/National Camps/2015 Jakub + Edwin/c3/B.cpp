#include <bits/stdc++.h>
using namespace std;

int main()
{
	int TC;

	cin >> TC;
	cin.ignore(1);
	while(TC--)
	{
		vector<string> record;
		string s, word;
		vector<string> v;

		getline(cin, s);
		// input record word by word
		istringstream iss(s);
		while(iss >> word) record.push_back(word);

		int pos;
		set<string> st;
		while(true)
		{
			getline(cin, s);
			if (s == "what does the fox say?") break;
			pos = (int) s.rfind(" ");
			st.insert(s.substr(pos+1));
		}

		bool first = true;
		for (int i = 0; i < (int) record.size(); ++i)
		{
			if (st.find(record[i]) == st.end())
			{
				if (first) {
					cout << record[i];
					first = false;
				}
				else cout << " " << record[i];
			}
		}
		cout << endl;
	}

	return 0;
} 