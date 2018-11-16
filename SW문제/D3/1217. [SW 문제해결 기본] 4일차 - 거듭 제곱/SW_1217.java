package study_day1;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class SW_1217{
	
	public static void main(String[] args) throws IOException {
		int check[] = new int[2]; 
		BufferedReader bf =new BufferedReader(new InputStreamReader(System.in));
		for(int count=1; count <=10; count++) {
			bf.readLine();
			String[] pre_check = bf.readLine().split(" ");
			check[0] = Integer.parseInt(pre_check[0]);
			check[1] = Integer.parseInt(pre_check[1]);
			System.out.println("#"+count+" "+spring(check[0], check[1]));
		}
	}
private static int spring(int number1, int number2) {
	if(number2 == 0)
		return 1;
	else
		return number1*spring(number1,(number2-1));
}
}
