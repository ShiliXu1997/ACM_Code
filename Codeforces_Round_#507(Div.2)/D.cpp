//******************************************************************************
// File Name: D.cpp
// Author: Shili_Xu
// E-Mail: shili_xu@qq.com
// Created Time: 2018年09月06日 星期四 02时02分08秒
//******************************************************************************

#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <ctime>
using namespace std;
typedef long long ll;

ll n, k;
string s;

int main()
{
	srand(time(0));
	cin >> n >> k;
	ll l = 1, r = n;
	while (true) {
		if (r - l + 1 > k * 5 + 4) {
			ll mid = (l + r) / 2;
			cout << max((ll)1, l - k) << " " << min(n, mid + k) << endl;
			cin >> s;
			if (s == "Yes") {
				l = max((ll)1, l - k);
				r = min(n, mid + k);
			}
			else {
				l = min(n, mid + k + 1);
				r = min(n, r + k);
			}
		}
		else {
			ll pos = l + rand() % (r - l + 1);
			cout << pos << " " << pos << endl;
			cin >> s;
			if (s == "Yes")
				break;
			else {
				l = max((ll)1, l - k);
				r = min(n, r + k);
			}
		}
	}
	return 0;
}
