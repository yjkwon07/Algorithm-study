package study_day1;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Stack;

public class BJ_11047 {
	public static void main(String[] args) throws IOException {
		Stack<Integer> st = new Stack<>();
		BufferedReader bf = new BufferedReader(new InputStreamReader(System.in));
		String line_1[] = bf.readLine().split(" ");
		for(int loop=0; loop < Integer.parseInt(line_1[0]); loop++ ) {
			st.push(Integer.parseInt(bf.readLine()));
		}
		int n , result =0; 
		n = Integer.parseInt(line_1[1]);
		while(!st.isEmpty()) {
			result += n / st.peek();
			n %= st.pop();
		}
		System.out.println(result);
	}
}
