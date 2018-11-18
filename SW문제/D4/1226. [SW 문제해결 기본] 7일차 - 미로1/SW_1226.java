package study_day1;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.LinkedList;
import java.util.Queue;

/*
 
�Ʒ� �׸��� ���� �̷ΰ� �ִ�. 16*16 ����� ���·� ������� �̷ο��� ��� ������ ��, ����� ������ ���� ��Ÿ����.

���� �»�ܿ� �ִ� ĭ�� (0, 0)�� �������� �Ͽ�, ���ι����� x ����, ���ι����� y �����̶�� �� ��, �̷��� �������� (1, 1)�̰� �������� (13, 13)�̴�.

�־��� �̷��� ��������κ��� ������������ �� �� �ִ� ���� �ִ��� �Ǵ��ϴ� ���α׷��� �ۼ��϶�.

�Ʒ��� ���ÿ����� ���� �����ϴ�.

 */

public class SW_1226{
	static final int n = 100;
	static final int dx[] = {0,0,1,-1};
	static final int dy[] = {1,-1,0,0};
	static int map[][];
	static boolean visit[][];
	
	static class nn{
		int x, y;
		nn(int x, int y){
			this.x = x;
			this.y =  y;
		}
	}
	static boolean finish;
	
	public static void main_15(String[] args) throws IOException {
		BufferedReader bf = new BufferedReader(new InputStreamReader(System.in));
		Queue<nn> q;
		
		for(int count = 1; count <= 10; count++) {
			bf.readLine();
			map = new int[n][n];
			visit = new boolean[n][n];
			q= new LinkedList<>();
			finish =false;
			
			for(int x=0; x<100; x++) {
				String pre_array = bf.readLine();
				for(int y =0; y<100; y++) {
					map[x][y] = pre_array.charAt(y)-48;
					if(map[x][y] == 2) {
						q.offer(new nn(x,y));
						visit[x][y] =true;
					}
				}
			}
			
			while(!q.isEmpty()) {
				nn p = q.poll();
				if(map[p.x][p.y] == 3) {
					finish =true;
					break;
				}
				for(int i =0; i<4; i++) {
					int x = p.x+dx[i];
					int y = p.y+dy[i];
					if(x>=0 && y>=0 && x<n && y<n && map[x][y] !=1) {
						if(visit[x][y] == false) {
							visit[x][y] =true; 
							q.offer(new nn(x,y));
						}
					}
				}
			}
			
			if(finish) {
				System.out.println("#"+count+" "+1);
			}
			else {
				System.out.println("#" + count+ " "+0);
			}
				
		}
		bf.close();
	}
}
