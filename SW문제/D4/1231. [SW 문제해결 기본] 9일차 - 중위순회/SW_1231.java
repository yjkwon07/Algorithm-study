package study_day1;

import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.Date;
import java.text.SimpleDateFormat;

public class number17 {
	
	static int [] left;
	static int [] right;
	static String[] data; 
	static String Answer = "";
	
	public static void main_17(String[] args) throws Exception{
		BufferedReader bf = new BufferedReader(new InputStreamReader(System.in));
		
		
		
		for(int count=1; count<= 10; count++) {
			
			left = new int[101];
			right = new int[101];
			data = new String[101];
			
			// input: 트리개수
			int loop = Integer.parseInt(bf.readLine());
			
			if(loop > 100)
				throw new Exception(); 
			
			// Input : No, Value, Left, Right
			String TreeData[];
			
			for(int number =0; number< loop; number++) {
				TreeData = bf.readLine().trim().split(" ");
				int index = Integer.parseInt(TreeData[0]);
				data[index] = TreeData[1];
				
				if(TreeData.length > 2) {
					left[index] = Integer.parseInt(TreeData[2]);
				}
				if(TreeData.length >3) { // right
					right[index] = Integer.parseInt(TreeData[3]);
				}
			}
			
			Answer = "";
			printTreeIn(1);
			String result = String.format("#%d %s", count, Answer);
			
			System.out.println(result);
		}
	}
	
	// 중위순회 (선위면 먼저 자기부터 출력, 후위면 자신을  가장 나중에 출력)
	private static void printTreeIn(int address) {
		
		if(left[address] != 0) {
			printTreeIn(left[address]);
		}
		Answer += data[address];
		if(right[address] != 0) {
			printTreeIn(right[address]);
		}
	}
}