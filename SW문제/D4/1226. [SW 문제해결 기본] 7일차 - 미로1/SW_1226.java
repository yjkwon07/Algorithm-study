package study_day1;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.LinkedList;
import java.util.Queue;

/*
 
아래 그림과 같은 미로가 있다. 16*16 행렬의 형태로 만들어진 미로에서 흰색 바탕은 길, 노란색 바탕은 벽을 나타낸다.

가장 좌상단에 있는 칸을 (0, 0)의 기준으로 하여, 가로방향을 x 방향, 세로방향을 y 방향이라고 할 때, 미로의 시작점은 (1, 1)이고 도착점은 (13, 13)이다.

주어진 미로의 출발점으로부터 도착지점까지 갈 수 있는 길이 있는지 판단하는 프로그램을 작성하라.

아래의 예시에서는 도달 가능하다.

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
