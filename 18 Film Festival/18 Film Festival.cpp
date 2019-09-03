// 18 Film Festival.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
struct Film {
	int begin, end;
	bool operator <(const Film& f) const {
		return end < f.end;
	}
};
int main()
{
	int num = 0;
	while (cin >> num && num != 0) {
		vector<Film> movies(num);
		for (int i = 0; i < num; i++) {
			cin >> movies[i].begin >> movies[i].end;
		}
		sort(movies.begin(), movies.end());
		int endTime = movies[0].end;
		int count = 1;
		for (int i = 1; i < num; i++) {
			if (movies[i].begin >= endTime) {
				count++;
				endTime = movies[i].end;
			}
		}
		cout << count << endl;
	}
	return 0;
}
