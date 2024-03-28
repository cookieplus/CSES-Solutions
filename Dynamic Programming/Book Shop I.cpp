/**
Book Shop
=========
Đề bài:
	Có n quyển sách. Mỗi quyển có giá hi và số trang si.
	Tìm số trang sách tối đa có thể có với số tiền nhiều nhất là x.
	Mỗi quyển được mua 1 lần.
	In: 
		n, x
		h1... hn
		s1... sn
	Out:
		Số trang sách.
	Giới hạn:
		1 <= n <= 1000		
		1 <= x <= 10^5
		1 <= hi, si <= 1000
Phân tích:
	Gọi dp[x] là số trang sách tối đa có thể mua với x đồng.
	Như vậy có thể có nhiều phương án, bắt đầu từ x-hi đồng, mua được dp[x-hi] trang sách, sau đó mua thêm quyển sách thứ i, có giá hi và số trang sách là si. Tổng cộng sẽ có dp[x-hi] + si.
	dp[x] = max(dp[x], dp[x-hi]+si) với i từ 1 đến n.
	Cuối cùng dp[x] = max(dp)

Đoạn code chính
	for(int i=0; i<N; i++) {
		for(int j=X-h[i]; j>=0; j--) {
			if (dp[j] != -1) {
				dp[j+h[i]] = max(dp[j+h[i]], dp[j] + s[i]);
			}
		}
	}
	result = * max_element(dp.begin(), dp.end());
*/   
#include <bits/stdc++.h>

using namespace std;
const int maxN = 1000;
const int maxX = 1e5;

int N, X, h[maxN], s[maxN], dp[maxX+1];

int main(){
    scanf("%d %d", &N, &X);
    for(int i = 0; i < N; i++)  scanf("%d", &h[i]);
    for(int i = 0; i < N; i++)  scanf("%d", &s[i]);

    fill(dp+1, dp+X+1, -1);
    for(int i = 0; i < N; i++)
        for(int j = X-h[i]; j >= 0; j--)
            if(dp[j] != -1)
                dp[j+h[i]] = max(dp[j+h[i]], dp[j]+s[i]);

    for(int i = 1; i <= X; i++)
        dp[i] = max(dp[i], dp[i-1]);
    printf("%d\n", dp[X]);
}
