package study_day1;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.Collections;

public class SW_1208 {
	public static void main(String[] args) throws IOException{
		BufferedReader bf =new BufferedReader(new InputStreamReader(System.in));
		String pre_array[];
		int array[];
		int size;
		int total; 
		for(int i = 1; i <= 10; i++) {
			total = 0;
			size = Integer.parseInt(bf.readLine());
			pre_array = bf.readLine().split(" ");
			array = Arrays.asList(pre_array).stream().mapToInt(Integer::parseInt).toArray();
			for(int count=0; count < size; count++) {
				Arrays.sort(array);
				array[0]++;
				array[array.length-1]--;
			}
			Arrays.sort(array);
			total = array[array.length-1] - array[0];
			System.out.println("#"+i+" "+total);
		}
	}
}
