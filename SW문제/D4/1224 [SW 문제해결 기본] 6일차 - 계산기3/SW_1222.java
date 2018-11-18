package study_day1;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Stack;

/*
 ���ڿ��� �̷���� ������ �־��� ��, �� ������ ���� ǥ������� �ٲپ� ����ϴ� ���α׷��� �ۼ��Ͻÿ�.

���� ���

��3+4+5+6+7��

��� ���ڿ��� �� ������ ���� ǥ������� �ٲٸ� ������ ����.

"34+5+6+7+"

��ȯ�� ���� ����ϸ� 25�� ���� �� �ִ�.

���ڿ� ������ �����ϴ� �����ڴ� + �ϳ����̸� �ǿ������� ���ڴ� 0 ~ 9�� ������ �־�����.

[�Է�]

�� �׽�Ʈ ���̽��� ù ��° �ٿ��� ���ڿ� ������ ���̰� �־�����. �� ���� �ٿ� ���ڿ� ������ �־�����.

�� 10���� �׽�Ʈ ���̽��� �־�����.

[���]

#��ȣ�� �Բ� �׽�Ʈ ���̽��� ��ȣ�� ����ϰ�, ���� ���� �� ���� ����Ѵ�.

 */

public class SW_1222{
	public static void main(String[] args) throws IOException {
		BufferedReader bf = new BufferedReader(new InputStreamReader(System.in));
		Stack <Character> st = new Stack<>();
		Stack <Integer> cal_st = new Stack<>();
		for(int count=1; count<=10; count++) {
			bf.readLine();
			String array[] = bf.readLine().split("");
			char right_array[] = new char[array.length];
			int number =0;
			
			for(int x=0; x < array.length; x++) {
				int check =0;
				int check2 =0; 
				if(!(array[x].charAt(0) >= '0') || !(array[x].charAt(0) <= '9')) {
					
					if(st.isEmpty()) {
						st.push(array[x].charAt(0));	
					}
					
					else {
						check =0;
						check2 =0; 
						while(!st.isEmpty()) {
							check =0; 
							check2 =0;
							switch(st.peek()) {
								case '+':
								case '-':
									check=3;
									break;
								case '*':
								case '/':
									check=4;
									break;
								default:
									check=-1;
									break;
							}						

							switch(array[x].charAt(0)) {
								case '+':
								case '-':
									check2=3;
									break;
								case '*':
								case '/':
									check2=4;
									break;
								case ')':
									check2=10;
									break;
								case '(':
									check2=12;
									break;
								default:
									check2=0;
									break;
							}
							
							if(check2 ==10) {
//								System.out.println("array: "+array[x]);s
//								System.out.println("peek:"+st.peek());
								while(!(st.isEmpty()) && st.peek() != '(') {
//									System.out.println("peek:"+st.peek());
									right_array[number] = st.pop();
									number++;
								}
								st.pop();
								break;
							}
							
							else if(check < check2) {
								st.push(array[x].charAt(0));
								break;
							}

							else {
								right_array[number] = st.pop();
								number++;
								if(st.isEmpty()) {
									st.push(array[x].charAt(0));
									break;
								}
							}
							
						}
					}
				}
				else {
					right_array[number] = array[x].charAt(0);
					number++;
				}
			}
			
			while(!st.isEmpty()) {
				right_array[number] = st.pop();
				number++;
			}
//			for(int x =0; x<right_array.length; x++)
//				System.out.print(right_array[x]);
			
			// cal_����
			for(int x=0 ; x<right_array.length; x++) {
				if(right_array[x] >= '0' && right_array[x] <= '9') {
					cal_st.push(right_array[x]-'0');
				}

				else {
					int cal_1 = 0;
					int cal_2 = 0;
					switch(right_array[x]) {
						case '+':
							cal_2 = cal_st.pop();
							cal_1 = cal_st.pop();
							cal_st.push((cal_1+cal_2));
							break;
						
						case '-':
							cal_2 = cal_st.pop();
							cal_1 = cal_st.pop();
							cal_st.push((cal_1-cal_2));
							break;
						case '*':
							cal_2 = cal_st.pop();
							cal_1 = cal_st.pop();
							cal_st.push((cal_1*cal_2));
							break;
						case '/':
							cal_2 = cal_st.pop();
							cal_1 = cal_st.pop();
							cal_st.push((cal_1/cal_2));
							break;
						default:
							break;
					}				
				}
			}
			System.out.println("#"+count+" "+cal_st.pop());
		}
		
	}
}
	

