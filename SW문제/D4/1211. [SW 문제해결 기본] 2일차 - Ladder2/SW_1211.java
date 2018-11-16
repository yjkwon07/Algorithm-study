package study_day1;
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.StringTokenizer;


public class number6 {
	public static void main(String[] args) throws IOException {
		BufferedReader bf = new BufferedReader(new InputStreamReader(System.in));
		int result = 0;
		int labber[][] = new int[100][100];
		int idx =0;
		int min , min_index = 0;
		int pre_result = 0;
		int temp=0;
		
		for(int T = 1; T <= 10; T++) {
			bf.readLine();
			idx =0; 
			
			for(int i = 0; i < 100; i++) {
				String array[] = bf.readLine().split(" ");
				for(int j=0; j < 100; j++) {
					labber[i][j] = Integer.parseInt(array[j]);
				}
			}
			
			min = Integer.MAX_VALUE;
			min_index = Integer.MAX_VALUE;
			
			for (int y = 0; y < 100; y++) {
				temp = y; 
				pre_result= 0; 
				if (labber[0][temp] == 0) continue;
				for(int x= 0; x <100; x++) {
					if ((temp < 99) && (labber[x][temp + 1] == 1))
	                    while ((temp < 99) && (labber[x][temp + 1] == 1)) {
	                    	temp++;
	                    	pre_result++;
	                    }
	                else if ((temp > 0) && (labber[x][temp - 1] == 1))
	                    while ((temp > 0) && (labber[x][temp - 1] == 1)) {
	                    	temp--;
	                    	pre_result++;
	                    }
					pre_result++;
	            }

				if(min >= pre_result) {
					min = pre_result;
					min_index = y;
				}
			}
			System.out.println("#"+T+" "+min_index);
		}
	}
}