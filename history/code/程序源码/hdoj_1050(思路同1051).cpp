#include<iostream>
using namespace std;
struct stick {
	int start, end;
};
int main() {
	int T;
	cin >> T;
	while (T--) {
		int num;
		cin >> num;
		struct stick * room = new struct stick[num];		
		for (int i = 0; i < num; ++i) {			
			int t1, t2;
			cin >> t1 >> t2;
			if (t1 > t2)
				swap(t1, t2);
			room[i].start = (int)(t1 + 1) / 2;
			room[i].end = (int)(t2 + 1) / 2;
			for (int j = i; j > 0; --j) {
				if ((room[j].start < room[j - 1].start) || ((room[j].start == room[j - 1].start)&&room[j].end<room[j-1].end) ) {
					struct stick t = room[j];
					room[j] = room[j - 1];
					room[j - 1] = t;
				}				
			}
		}		
		bool isSeen[210] = { false };
		int totalTime=0;
		struct stick lastSeen;
		int i = 0;
		while (i < num) {			
			lastSeen = room[i];
			for (int j = i+1; j < num; ++j) {
				if (isSeen[j])
					continue;
				if (room[j].start > lastSeen.end) {
					isSeen[j] = true;
					lastSeen = room[j];
				}
			}
			do {
				i++;
			} while (isSeen[i]);
			totalTime += 10;
		}
		cout << totalTime << endl;
	}	
	return 0;
}