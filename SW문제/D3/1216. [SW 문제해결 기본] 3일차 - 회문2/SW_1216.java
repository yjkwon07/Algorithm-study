package study_day1;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class SW_1216{
	public static void main_9(String[] args) throws IOException {
		BufferedReader bf = new BufferedReader(new InputStreamReader(System.in));
		String xy_board[][] = new String[100][100];

		for(int count=1; count<=10; count++) {
			bf.readLine();
			for(int x=0; x<100; x++) {
				String pre_xy[] = bf.readLine().split("");
				for(int y=0; y<100; y++) {
					xy_board[x][y] = pre_xy[y];
				}
			}

			int max = 0;

			for(int check = 0; check<100; check++) {
				for(int x=0; x<100; x++) {	
					for(int y=0; y<100; y++) {
						int ok_count1 = 0; 
						int ok_count2 = 0;
						for(int loop=0; loop<check/2; loop++) {
							if((y+check-1-loop)<100 && xy_board[x][y+loop].equals(xy_board[x][y+check-1-loop]) ) {	
								ok_count1++;
							}
							if((y+check-1-loop)<100 && xy_board[y+loop][x].equals(xy_board[y+check-1-loop][x]) )  {	
								ok_count2++;
							}
						}
						if(ok_count1 == check/2 || ok_count2 == check/2) {
							if(max < check) {
								max = check;
							}
						}
					}
				}
			}// first for end 
			System.out.println("#"+(count)+" "+max);
		}
	}
}
