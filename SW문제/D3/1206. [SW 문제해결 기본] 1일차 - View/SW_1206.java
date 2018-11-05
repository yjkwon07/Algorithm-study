package study_day1;

import java.awt.List;
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.Collection;
import java.util.Collections;
import java.util.IntSummaryStatistics;

public class SW_1206 {
	static int sum =0;
	static String building_array[];
	static int check2[] = new int[2]; 
	
	public static void main(String[] args) throws IOException{
		BufferedReader bf= new BufferedReader(new InputStreamReader(System.in));
		for(int loop =1; loop <= 10; loop++) {
			int T= Integer.parseInt(bf.readLine());
			int check1[] = new int[4];
			init();
			building_array = bf.readLine().split(" ");
			check1[0] = Integer.parseInt(building_array[0]);
			check1[1] = Integer.parseInt(building_array[1]);
			check1[2] = Integer.parseInt(building_array[building_array.length-2]);
			check1[3] = Integer.parseInt(building_array[building_array.length-1]);
			if(check1[0] != 0 && check1[1] != 0 && check1[2] != 0 && check1[3] != 0) {
				break;
			
			}
			else {
				for(int i = 2; i <= building_array.length-3; i++) {
					check_max(i);
					sum_good_view(i);
				}
				System.out.println("#"+loop+" "+sum);
			}
		}
	}

	private static void init() {
		// TODO Auto-generated method stub
		sum =0; 
		check2 =new int[2]; 
	}

	private static void sum_good_view(int number) {
		// TODO Auto-generated method stub
		int compare[] = new int[2]; 
		compare[0] = ( Integer.parseInt(building_array[number]) - check2[0]);
		compare[1] = ( Integer.parseInt(building_array[number]) - check2[1]);
		if(compare[0] == 0 || compare[1] == 0)
			sum+=0;
		else if(compare[0] <0 ||compare[1] < 0)
			sum +=0;
		else {
			IntSummaryStatistics stat = Arrays.stream(compare).summaryStatistics();
			sum += stat.getMin();
		}
	}

	private static void check_max(int number) {
		// TODO Auto-generated method stub
		check2[0] = Math.max(Integer.parseInt(building_array[number-2]), Integer.parseInt(building_array[number-1]) );
		check2[1] = Math.max(Integer.parseInt(building_array[number+2]), Integer.parseInt(building_array[number+1]) );
	}
}
