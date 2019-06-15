package study_day1;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.Collections;

public class SW_1204 {
	public static void main(String[] args) throws IOException {
		BufferedReader bf = new BufferedReader(new InputStreamReader(System.in));
		int T = Integer.parseInt(bf.readLine());
		int total_array[];
		int max = 0;
		int index = -1;
		for(int loop=1; loop <= T; loop++) {
			index = -1;
			max = 0;
			bf.readLine();
			String array[] = bf.readLine().split(" ");

			total_array = new int [array.length];
			Arrays.fill(total_array,0);

			for(int i =0; i < array.length; i++) 
				total_array[Integer.parseInt(array[i])]++;
			for(int i = 0; i <array.length; i++) {
				// 같은 최빈값은 큰 수가 최빈값으로
				if(max <= total_array[i] && index < i) {
					max = total_array[i];
					index = i;
				}
			}
			System.out.println("#"+loop+" "+index);
		}
    	}
}
