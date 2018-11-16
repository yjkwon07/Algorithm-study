#include <stdio.h>
 
const int MAXN = 10005;
 
int N, M, A, B;
int deg[MAXN], up[MAXN];
int sub[MAXN], cnt[MAXN];
int Q[MAXN], fr, re;
 
int main() {
    	int T; 
		for (scanf("%d", &T); T--;) {
        scanf("%d%d%d%d", &N, &M, &A, &B);
        for (int i = 1; i <= M; i++) {
            int x, y; scanf("%d%d", &x, &y);
            up[y] = x;
            deg[x]++;
        }
        fr = re = 0;
        
        for (int i = 1; i <= N; i++) {
            sub[i] = 1;
            if (deg[i] == 0) Q[re++] = i;
        }
        while (fr < re) {
            int x = Q[fr++]; int y = up[x];
            deg[y]--;
            sub[y] += sub[x];
            if (deg[y] == 0) Q[re++] = y;
        }
        int ans = 1;
        while (A) {
            cnt[A]++; A = up[A];
        }
        while (B) {
            cnt[B]++;
            if (cnt[B] == 2) {
                ans = B;
                break;
            }
            B = up[B];
        }
        static int tc = 0;
        printf("#%d %d %d\n", ++tc, ans, sub[ans]);
        for (int i = 1; i <= N; i++) deg[i] = up[i] = sub[i] = cnt[i] = 0;
    }
}
