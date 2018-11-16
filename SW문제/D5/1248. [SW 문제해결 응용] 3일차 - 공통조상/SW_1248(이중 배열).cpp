#include <stdio.h>
 
int relation[10000][2];
int relation_rev[10000];
int ancestors_t1[10000];
int ancestors_t2[10000];
int queue[10000];
 
int main(){
    int T;
    scanf("%d", &T);
    for (int test_case = 1; test_case <= T; test_case++){
        int n, m;   //����, ����
        int t1, t2;
        int i, j;
 
        //input
        scanf("%d %d %d %d", &n, &m, &t1, &t2);
        for (i = 0; i < m; i++){
            int u, v;
            scanf("%d %d", &u, &v);
            //relation[u] = v;
            if (relation[u][0] == 0) relation[u][0] = v;
            else relation[u][1] = v;
            // ���� ���  
            relation_rev[v] = u;
        }
 
        // t1�� ����� ����
        int now = t1;
        ancestors_t1[0] = t1;
        int t1_length = 1;
        while (now != 1){ // �ְ� ������ �ƴ� ������ // ������ �׻� 1 
            now = relation_rev[now];
            ancestors_t1[t1_length] = now;
            t1_length++;
        }
 
        //t2�� ����� ����
        now = t2;
        ancestors_t2[0] = t2;
        int t2_length = 1;
        while (now != 1){ // �ְ� ������ �ƴ� ������
            now = relation_rev[now];
            ancestors_t2[t2_length] = now;
            t2_length++;
        }
 
        //���� ���� ã��
        int josang = 1;
        if (ancestors_t2[0] != josang){ // t2 ������� Ÿ�f�µ� ó���� �ְ������̸� ������ �ǹ̰� ����
            //���� ã�� �÷���
            int check = 0;
            for (i = 0; i < t1_length; i++){
                //���� ���������� �����ߴµ� �ְ������̸� �ݺ��� �� �ǹ̰� ����
                if (i == t1_length - 1 && ancestors_t1[i] == josang) break;
 
                //ã������ �ݺ��� Ż��
                if (check == 1) break;
 
                for (j = 0; j < t2_length; j++){
                    if (ancestors_t1[i] == ancestors_t2[j]){
                        josang = ancestors_t1[i];
                        check = 1;
                        break;
                    }
                }
            }
        }
 
        //���� ������ ��� �ڽĵ� ī��Ʈ
        int cnt = 1;
        int front = 0;
 
        queue[0] = josang;
        while (front != cnt){
            int now = queue[front];
            if (relation[now][0] != 0){
                queue[cnt] = relation[now][0];
                cnt++;
            }
            if (relation[now][1] != 0){
                queue[cnt] = relation[now][1];
                cnt++;
            }
            front++;
        }
 
        printf("#%d %d %d\n", test_case, josang, cnt);
 
        //�ʱ�ȭ
        for (i = 0; i < n; i++){
            relation[i][0] = 0; relation[i][1] = 0;
        }
    }
}
