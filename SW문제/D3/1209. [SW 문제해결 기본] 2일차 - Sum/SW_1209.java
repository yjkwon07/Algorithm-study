package study_day1;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

/*
 * 최대 배열의 크기는 100 * 100
 * 가로 -> 세로 -> 대가선의 총합을 구한다 
 * 모든것은 Integer이다 
 * 총 10개의 테스트 케이스가 주어진다.
 */

public class SW_1209 {
	public static void main(String[] args) throws IOException {
		BufferedReader bf = new BufferedReader(new InputStreamReader(System.in));
		int array[][] = new int[100][100];

		for(int i =0; i < 10; i++) {
			bf.readLine();
			for(int x = 0; x < 100; x++) {
				StringTokenizer st = new StringTokenizer(bf.readLine());
				for(int y = 0; y < 100; y++) { 
					array[x][y] = Integer.parseInt(st.nextToken());
				}
			}

			// 가로 더하기
			// 세로 더하기 
			int max =0; 
			int sum = 0; 
			int sum2 = 0;
			for(int x = 0; x < 100; x++) {
				sum = 0;
				sum2 = 0;
				for(int y = 0; y < 100; y++) { 
					sum += array[x][y];
					sum2 += array[y][x];
				}
				if(max < sum) {
					max = sum;
				}
				if(max < sum2) {
					max = sum2;
				}
			}

			// 대각선 더하기
			sum =0;
			sum2 =0;
			for(int x = 0; x < 100; x++) {
				for(int y = 0; y < 100; y++) { 
					if( x == y) sum+=array[x][y];
				}
				sum2 += array[x][99-x];
			}
			
			if(max < sum) {
				max = sum;
			}
			if(max < sum2) {
				max = sum2;
			}

			System.out.println("#"+(i+1)+" "+max);
		}
	  }	
}
