package study_day1;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;

/*
 * 정렬 
 * 그리디 
 */

public class BJ_11399 {
	
	public static void main(String[] args) throws IOException {
		BufferedReader bf = new BufferedReader(new InputStreamReader(System.in));
		int count = Integer.parseInt(bf.readLine());
		
		String pre_array[] = bf.readLine().split(" ");
		int array[] =new int [count];
		for(int loop =0; loop < count; loop++) {
			 array[loop] = Integer.parseInt(pre_array[loop]); 
		}
		Arrays.sort(array);
		int last = count;
		int total = 0;
		for(int loop =0; loop < count; loop++) {
			total += array[loop] * last;
			last--;
		}
		System.out.println(total);
	}
}
