package study_day1;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

/*
	 * "기러기" 또는 "level" 과 같이 거꾸로 읽어도 앞에서부터 읽은 것과 같은 문장이나 낱말을 회문(回文, palindrome)이라 한다.
	* 주어진 8x8 평면 글자판에서 가로, 세로를 모두 보아 제시된 길이를 가진 회문의 총 개수를 구하는 문제이다.

	 각 칸의 들어가는 글자는 c언어 char type으로 주어지며 'A', 'B', 'C' 중 하나이다.
	글자 판은 무조건 정사각형으로 주어진다.
	ABA도 회문이며, ABBA도 회문이다. 
	A또한 길이 1짜리 회문이다.
	가로, 세로 각각에 대해서 직선으로만 판단한다.
	즉, 아래 예에서 노란색 경로를 따라가면 길이 7짜리 회문이 되지만 직선이 아니기 때문에 인정되지 않는다.
 */

public class SW_1215{
	public static void main_8(String[] args) throws IOException{
		BufferedReader bf = new BufferedReader(new InputStreamReader(System.in));
		String xy_board[][] = new String[8][8];
		int ok_count1 =0;
		int ok_count2 =0;
		int total_count =0;
		
		for(int count =0; count <10; count++) {
			total_count =0;
			int check = Integer.parseInt(bf.readLine());
			
			for(int x = 0; x <8; x++) {
				String line_array[] = bf.readLine().split("");
				for(int y = 0; y<8; y++) {
					xy_board[x][y] = line_array[y];
				}
			} // end setting 

			
			for(int x=0; x<8; x++) {				
				for(int y=0; y<8; y++) {
					ok_count1 = 0; 
					ok_count2 = 0;
					for(int loop=0; loop<check/2; loop++) {
						if((y+check-1-loop)<8 && xy_board[x][y+loop].equals(xy_board[x][y+check-1-loop]) ) {	
							ok_count1++;
						}
						if((y+check-1-loop)<8 && xy_board[y+loop][x].equals(xy_board[y+check-1-loop][x]) )  {	
							ok_count2++;
						}
					}
					if(ok_count1 == check/2 && ok_count2 == check/2) {
						total_count+=2;
					}
					else if(ok_count1 == check/2 || ok_count2 == check/2) {
						total_count++;
					}
				}
			}// first for end 
			System.out.println("#"+(count+1)+" "+total_count);
		}// count 10 end
  	}
}
