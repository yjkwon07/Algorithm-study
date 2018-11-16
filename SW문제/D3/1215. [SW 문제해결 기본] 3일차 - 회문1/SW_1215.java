package study_day1;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

/*
 * "�ⷯ��" �Ǵ� "level" �� ���� �Ųٷ� �о �տ������� ���� �Ͱ� ���� �����̳� ������ ȸ��(����, palindrome)�̶� �Ѵ�.
* �־��� 8x8 ��� �����ǿ��� ����, ���θ� ��� ���� ���õ� ���̸� ���� ȸ���� �� ������ ���ϴ� �����̴�.

 �� ĭ�� ���� ���ڴ� c��� char type���� �־����� 'A', 'B', 'C' �� �ϳ��̴�.
���� ���� ������ ���簢������ �־�����.
ABA�� ȸ���̸�, ABBA�� ȸ���̴�. 
A���� ���� 1¥�� ȸ���̴�.
����, ���� ������ ���ؼ� �������θ� �Ǵ��Ѵ�.
��, �Ʒ� ������ ����� ��θ� ���󰡸� ���� 7¥�� ȸ���� ������ ������ �ƴϱ� ������ �������� �ʴ´�.
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
