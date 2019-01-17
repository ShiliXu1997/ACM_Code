//************************************************************************
// File Name: C.cpp
// Author: Shili_Xu
// E-Mail: shili_xu@qq.com 
// Created Time: 2018年02月26日 星期一 01时00分52秒
//************************************************************************

#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
using namespace std;

long long k, d, t;

int main()
{
	scanf("%lld %lld %lld", &k, &d, &t);
	long long circle;
	double energy;
	for (long long i = k / d; i <= k / d + 1; i++)
		if (i * d >= k) {circle = i * d; break;}
	energy = (double)k + (double)0.5 * (circle - k);
	double time = circle * floor(t / energy);
	double remain = (double)t - (double)floor(t / energy) * energy;
	if (remain < k)
		time += remain;
	else
		time += ((double)k + (remain - k) * 2);
	printf("%.10f", time);
	return 0;
}

