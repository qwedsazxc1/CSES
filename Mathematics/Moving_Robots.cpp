#include <bits/stdc++.h>

using namespace std;

int main(){
	int k;
	cin >> k;
	int way[8][8] = {};
	double pro[8][8] = {};
	for (int i = 0; i < 8; i++){
		for (int j = 0; j < 8; j++){
			pro[i][j] = 1;
			if (i != 0)
				way[i][j]++;
			if (j != 0)
				way[i][j]++;
			if (i != 7)
				way[i][j]++;
			if (j != 7)
				way[i][j]++;
		}
	}
	for (int i = 0; i < 8; i++){
		for (int j = 0; j < 8; j++){
			double sinpro[8][8] = {};
			sinpro[i][j] = 1;
			for (int t = 0; t < k; t++){
				double temp[8][8] = {};
				for (int l = 0; l < 8; l++){
					for (int m = 0; m < 8; m++){
						if (l > 0)
							temp[l][m] += sinpro[l - 1][m] / way[l - 1][m];
						if (m > 0)
							temp[l][m] += sinpro[l][m - 1] / way[l][m - 1];
						if (l < 7)
							temp[l][m] += sinpro[l + 1][m] / way[l + 1][m];
						if (m < 7)
							temp[l][m] += sinpro[l][m + 1] / way[l][m + 1];
					}
				}
				for (int l = 0; l < 8; l++)
					for (int m = 0; m < 8; m++)
						sinpro[l][m] = temp[l][m];
			}
			for (int l = 0; l < 8; l++){
				for (int m = 0; m < 8; m++){
					pro[l][m] *= (1 - sinpro[l][m]);
				}
			}
		}
	}
	double ans = 0;
	for (int i = 0; i < 8; i++)
		for (int j = 0; j < 8; j++)
			ans += pro[i][j];
	cout << fixed << setprecision(6) << ans << "\n";
	return 0;
}
