#include<stdio.h>
 
int v[10001];
int chk[10001];
int V;
 
int countRoot(int r){
    int sum = 1;
    for (int i = 1; i <= V; i++){
    	 printf("%d\n", v[i]);
    	 if (v[i] == r)  sum += countRoot(i);
	}
       
    return sum;
}
int main(){
    int i, j;
    int E, v1, v2;
    int T, p, c;
    scanf("%d", &T);
    for (int t = 1; t <= T; t++)
    {
        scanf("%d %d %d %d", &V, &E, &v1, &v2);
 
        for (i = 0; i < 10001; i++){
            v[i] = 0;
            chk[i] = 0;
        }
        for (i = 0; i < E; i++){
            scanf("%d %d", &p, &c);
            v[c] = p;
        }
 
        c = v1;
        while (c != 1){
            chk[v[c]] = 1;
            c = v[c];
        }
        c = v2;
        while (c != 1){
            if (chk[c]){
                p = c; break;
            }
            c = v[c];
        }
        if (c == 1) p = 1;
 
 
        printf("#%d %d %d\n", t, p, countRoot(p));
    }
    return 0;
}
