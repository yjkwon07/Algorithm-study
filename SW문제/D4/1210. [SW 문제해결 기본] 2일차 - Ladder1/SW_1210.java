package study_day1;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

/*
 * 0으로 모든 배열에 패딩을 한다 <- out length Error를 마기 위함 (x) -> 범위를 지정하면되니깐 안해두됨
 * 마지막 라인에 2를 서치한다.
 * 서치한 좌표값을 x,y값으로 받는다
 * 상,좌,우에 1을 겁색하여 좌표값을 수정한다. 
 * 배열의 첫라인을 도달 했을 때, y값을 반환한다.
 */

public class SW_1210 {
	public static void main(String[] args) throws IOException{
	    int array[][] = new int[102][102];
		String pre_array[] = new String[10000]; 
		BufferedReader bf=new BufferedReader(new InputStreamReader(System.in));
		int cnt = 0;
		int x=0;
		int y=0;
				
		// Test셋이 10번 수행한다.
		for(int count = 0; count < 10; count++) {
			// 토큰 하나는 각 테스트 케이스
			// 활용 가치가 없다.
			bf.readLine();
			
			// 한개의 배열에 100번 입력을 받는다.
			x=0;
			y=0;
			for(int i=0; i<100; i++) {
				pre_array=bf.readLine().split(" ");
				cnt=0;
				for(int j=0; j<100; j++) {
					array[i][j]	= Integer.parseInt(pre_array[cnt]); 
					cnt++;
					if(2 == array[i][j]) {
	    	            x = 98;
	    	            y = j;
					}
				}
			}
	
			// search start index
			while(x != 0) {
				array[x][y]=0;
		       if(y-1>=0 && (array[x][y-1] ==1)) // 왼
					y--;
		       else if(y+1<100 && (array[x][y+1] == 1)) // 오
					y++;
				else // 위
					x--;
			}
			System.out.println("#"+(count+1)+" "+y);
		}


	}

}
