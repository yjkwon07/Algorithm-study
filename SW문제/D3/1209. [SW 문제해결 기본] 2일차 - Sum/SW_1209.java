package study_day1;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

/*
 * �ִ� �迭�� ũ��� 100 * 100
 * ���� -> ���� -> �밡���� ������ ���Ѵ� 
 * ������ Integer�̴� 
 * �� 10���� �׽�Ʈ ���̽��� �־�����.
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
		
		// ���� ���ϱ�
		// ���� ���ϱ� 
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
		
		// �밢�� ���ϱ�
		sum =0;
		sum2 =0;
		for(int x = 0; x < 100; x++) {
			for(int y = 0; y < 100; y++) { 
				if( x == y)
					sum+=array[x][y];
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
