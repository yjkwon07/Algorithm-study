package study_day1;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.HashSet;
import java.util.LinkedList;
import java.util.Queue;
import java.util.Set;
/*
 * out put suceess  -> but, not sucess why ??? 
 * 
 */

public class pre {
	public static String code[] =new String[8];
	public static int check_code[] = new int[8];
	public static int loop;
	public static int total;
	public static void check() {
		total =0; 

		total = ( check_code[0] + check_code[2] + check_code[4] + check_code[6] )* 3 + ( check_code[1] + check_code[3] + check_code[5] + check_code[7] );
		if(total % 10 == 0) {
			System.out.println("# "+ loop+ " "+(check_code[0] + check_code[2] + check_code[4] + check_code[6]+check_code[1] + check_code[3] + check_code[5] + check_code[7]));
		}
		else 
			System.out.println("# "+ loop+ " 0");
	}
	public static void main(String[] args) throws IOException{
		BufferedReader bf = new BufferedReader(new InputStreamReader(System.in));
		Set <String> set = new HashSet<>();
		Queue<String> qu = new LinkedList<>();
		
		int count = Integer.parseInt(bf.readLine());
		
		for(loop=1; loop <= count; loop++) {
			Arrays.fill(code, null);
			Arrays.fill(check_code, 0);
			qu.clear();
			set.clear();
			String st[] = bf.readLine().split(" ");
			int N = Integer.parseInt(st[0]);
			int M = Integer.parseInt(st[1]);
			
//			// 1번 제약 사항 
//			if(1 > N || 50 < N)
//				break;
//			if(1 > M || 100 <= M)
//				break;
			
			for(int i = 0; i < N; i++) {

				// get 1 line
				String array = bf.readLine();
				for(int j = M-1; j >= 0; j--) {
					// 마지막 1이라는것이 존재 시 code 존재 확인 가능 
					// 모든 비율은 1로 끝난다. 
					if(array.charAt(j) == '1' ) {
						array = array.substring(j-55, j+1);
						if(!set.contains(array)) {
							qu.add(array);
							set.add(array);
							break;
						}
						else
						break;
					}
				}
			}
			
			for( String array : qu) {
//				String array = qu.poll();
				code[0] = array.substring(0,7);
				code[1] = array.substring(7,14);
				code[2] = array.substring(14,21);
				code[3] = array.substring(21,28);
				code[4] = array.substring(28,35);
				code[5] = array.substring(35,42);
				code[6] = array.substring(42,49);
				code[7] = array.substring(49,56);
				
				if(code[0] != null) {
					for(int number_loop=0; number_loop < code.length; number_loop++) {
						switch(code[number_loop]) {
							case "0001101":
								check_code[number_loop] = 0;
								break;
							case "0011001":
								check_code[number_loop] = 1;
								break;
							case "0010011":
								check_code[number_loop] = 2;
								break;
							case "0111101":
								check_code[number_loop] = 3;
								break;
							case "0100011":
								check_code[number_loop] = 4;
								break;
							case "0110001":
								check_code[number_loop] = 5;
								break;
							case "0101111":
								check_code[number_loop] = 6;
								break;
							case "0111011":
								check_code[number_loop] = 7;
								break;
							case "0110111":
								check_code[number_loop] = 8;
								break;
							case "0001011":
								check_code[number_loop] = 9;
								break;							
						}
					}
				}// if_end
				check();
			}
			
			
			
		}
	}
}
