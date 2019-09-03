// 29 Radar Installation.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <cmath>

using namespace std;

typedef struct Range {
	float left;
	float right;
}Range;
typedef struct Island {
	int x;
	int y;
}Island;
bool cmp(Range a, Range b) {
	return a.right < b.right;
}


int main()
{
	int N, D;
	int caseNum = 0;
	while (cin >> N >> D && !(N == 0 && D == 0)) {
		caseNum++;
		vector<Island> islands(N);
		vector<Range> radarRange(N);
		bool hasSol = true;
		for (int i = 0; i < N; i++) {
			cin >> islands[i].x >> islands[i].y;
			if (abs(islands[i].y) > D) {
				hasSol = false;
			}
			float halfRange = sqrt((double)(D * D - islands[i].y * islands[i].y));
			radarRange[i].left = islands[i].x * 1.0 - halfRange;
			radarRange[i].right = islands[i].x * 1.0 + halfRange;
		}
		if (hasSol == true) {
			sort(radarRange.begin(), radarRange.end(), cmp);
			int radarNum = 0;
			int i = 0;
			while (i < N) {
				float curRight = radarRange[i].right;
				radarNum++;
				while (i < N && radarRange[i].left <= curRight) {
					i++;
				}
			}
			cout << "Case " << caseNum << ": " << radarNum << endl;
		} else {
			cout << "Case " << caseNum << ": " << -1 << endl;
		}
	}
}