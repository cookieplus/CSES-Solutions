/**
Grid Paths
==========
Đề bài:
	Grid n x n với 1 số điểm không được đi qua (trap).
	Chỉ có thể sang phải hoặc đi xuống.
	Tính số cách đi từ góc trái trên xuống góc phải dưới.
	Giới hạn: 1 <= n <= 1000.
	In:
		n
		n line, mỗi line n dấu (.) hoặc dấu (*)
	Out:
		Số cách.
Phân tích:
	Gọi dp[r][c] là số cách để đi từ điểm (1,1) tới điểm (r, c).
	Để đi đến (r, c) có thể đi từ 
	đi xuống từ (r-1,c) 
	sang phải từ (r, c-1)
	dp[r][c] = dp[r-1][c] + dp[r][c-1]
	Tất nhiên với điều kiện các ô tương ứng (r-1, c), (r, c-1) có thể đến được.
*/
#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const int maxN = 1000;
const ll MOD = 1e9+7;

int N;
char c[maxN+1][maxN+1];
ll dp[maxN+1][maxN+1];

int main(){
    scanf("%d", &N);
    for(int i = 1; i <= N; i++)
        for(int j = 1; j <= N; j++)
            scanf(" %c", &c[i][j]);

    dp[1][1] = (c[1][1] == '.');
    for(int i = 1; i <= N; i++){
        for(int j = 1; j <= N; j++){
            if(c[i][j] == '.'){
                if(c[i-1][j] == '.')    dp[i][j] += dp[i-1][j];
                if(c[i][j-1] == '.')    dp[i][j] += dp[i][j-1];
                dp[i][j] %= MOD;
            }
        }
    }

    printf("%lld\n", dp[N][N]);
}
