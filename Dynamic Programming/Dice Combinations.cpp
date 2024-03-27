/**
Dice Combinations
=================
Đề bài: 
	Đếm số cách để cộng các con số trong khoảng từ 1 đến 6 để tạo thành số n.
	In: n
	Out: số cách, mod 10^9+9
	Giới hạn: 1<= n <= 10^6

Phân tích:
	Với tổng bằng n thì có thể tạo bằng cách
		xuất phát từ tổng là n-1 rồi thêm số 1
		xuất phát từ tổng là n-2 rồi thêm số 2
		...
		xuất phát từ tổng là n-6 rồi thêm số 6

	Tạo hàm mục tiêu dp[i] là số cách để tổng bằng i;
	dp[0] = 1;
	dp[1] = dp[0];
	dp[2] = dp[0] + dp[1] (tổng 0 thêm số 2; tổng 1 thêm số 1)
	dp[3] = dpơ0] + dp[1] + dp[2]
	...

	dp[i] = dp[i-6] + dp[i-5]... + dp[i-1]

Đoạn code chính:
	MOD = 10^9+7
	dp[0] = 1;
    for(int i = 1; i <= N; i++)
        for(int j = 1; j <= 6 && i-j >= 0; j++)
            dp[i] = (dp[i] + dp[i-j]) % MOD; 

*/   
#include <bits/stdc++.h>

using namespace std;
const int maxN = 1e6;
const int MOD = 1e9+7;

int N, dp[maxN+1];

int main(){
    scanf("%d", &N);

    dp[0] = 1;
    for(int i = 1; i <= N; i++)
        for(int j = 1; j <= 6 && i-j >= 0; j++)
            dp[i] = (dp[i] + dp[i-j]) % MOD;

    printf("%d\n", dp[N]);
}
