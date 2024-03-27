/**
Minimizing Coins
================
Đề bài:
	Có n loại tiền xu c1, c2,... cn.
	Đếm số cách để có tổng số tiền là x bằng số tiền xu tối thiểu.
	In: 
		Dòng 1: n, x
		Dòng 2: c1, c2...cn

Phân tích:
	Để tạo tổng số tiền là x thì sẽ có n cách khác nhau từ tổng số tiền là x - c1, x-c2,... x-cn,
	sau đó thêm đồng coin tương ứng c1, c2,... cn vào.
	Như vậy ta chọn số nhỏ hơn trong các phương án thu được

	Tạo hàm mục tiêu dp[i] là số đồng xu tối thiểu cần thiết để có tổng là i
	dp[i] = min(dp[i], dp[i-k] + 1); với k thuộc [c1, c2,...cn]

	Code dưới đây thậm chí quét chỉ 1 lần.
*/    
#include <bits/stdc++.h>

using namespace std;
const int maxX = 1e6;
const int INF = 0x3f3f3f3f;

int N, X, c, dp[maxX+1];

int main(){
    scanf("%d %d", &N, &X);
    fill(dp+1, dp+X+1, INF);
    for(int i = 0; i < N; i++){
        scanf("%d", &c);
        for(int j = 0; j <= X-c; j++)
            if(dp[j] != INF)
                dp[j+c] = min(dp[j+c], dp[j]+1);
    }
    printf("%d\n", dp[X] == INF ? -1 : dp[X]);
}
