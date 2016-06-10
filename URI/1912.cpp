#include <cstdio>
#include <algorithm>
#include <functional>
#include <cmath>

#define EPS 0.000001

using namespace std;

int n, a;
int c[100100];

double area(double cut) {
	double ans = 0.0;
	for (int i = 0; i < n && c[i] > cut; i++)
		ans += c[i] - cut;
	return ans;
}

int main() {
	while (scanf("%d %d", &n, &a), n || a) {
		double min = 0.0, max = 0.0;
		int sum = 0;

		for (int i = 0; i < n; i++) {
			int x;
			scanf("%d", &x);
			c[i] = x;
			sum += x;
			if (x > max)
				max = x; 
		}

		if (sum == a) {
			printf(":D\n");
			continue;
		}

		if (sum < a) {
			printf("-.-\n");
			continue;
		}

		sort(c, c + n, greater<int>());

		double mid = (min + max)/2;
		double ar = area(mid);
		while (fabs(ar - a) > EPS) {
			if (ar < a)
				max = mid;
			else
				min = mid;
			mid = (min + max)/2;
			ar = area(mid);
		}

		printf("%.4lf\n", mid);
	}

	return 0;
}