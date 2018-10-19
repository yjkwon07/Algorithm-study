package study_day1;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;

public class BJ_2217 {
	public static void main(String[] args) throws IOException {
		BufferedReader bf = new BufferedReader(new InputStreamReader(System.in));
		int count = Integer.parseInt(bf.readLine());
		int array[] = new int[count];
		for(int loop = 0; loop < count; loop++) {
			array[loop] = Integer.parseInt(bf.readLine());
		}
		Arrays.sort(array);
		int max = 0;
		for(int loop = 0; loop < count; loop++) { 
			if(max < ( array[loop] * (count-loop)))
				max = ( array[loop] * (count-loop));
		}
		System.out.println(max);
	}
}
