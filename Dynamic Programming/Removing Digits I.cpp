/*
    Có thể giải bằng tham lam.
    Hoặc giải bằng DP:
        Với mỗi số d có nhiều chữ số cho trước, ta thử trừ đi từng chữ số KHÁC 0 của d (vì bỏ 0 đi thì d không đổi)
        dp[i] = min(dp[i], dp[(i sau khi trừ chữ số khác 0)] + 1);
*/
    
#include <bits/stdc++.h>

using namespace std;
const int maxN = 1e6;
const int INF = 0x3f3f3f3f;

int N, dp[maxN+1];

int main(){
    scanf("%d", &N);
    fill(dp+1, dp+N+1, INF);
    for(int i = 1; i <= N; i++){
        int d = i;
        // Với mỗi số d có nhiều chữ số cho trước, ta thử trừ đi từng chữ số KHÁC 0 của d (vì bỏ 0 đi thì d không đổi)
        // dp[i] = min(dp[i], dp[(i sau khi trừ chữ số khác 0)] + 1);
        while(d > 0){
            if(d%10 != 0)
                dp[i] = min(dp[i], dp[i-(d%10)]+1);
            d /= 10;
        }
    }

    printf("%d\n", dp[N]);
}
