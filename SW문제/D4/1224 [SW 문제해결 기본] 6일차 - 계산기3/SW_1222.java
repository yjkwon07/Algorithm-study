package study_day1;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Stack;

/*
 문자열로 이루어진 계산식이 주어질 때, 이 계산식을 후위 표기식으로 바꾸어 계산하는 프로그램을 작성하시오.

예를 들어

“3+4+5+6+7”

라는 문자열로 된 계산식을 후위 표기식으로 바꾸면 다음과 같다.

"34+5+6+7+"

변환된 식을 계산하면 25를 얻을 수 있다.

문자열 계산식을 구성하는 연산자는 + 하나뿐이며 피연산자인 숫자는 0 ~ 9의 정수만 주어진다.

[입력]

각 테스트 케이스의 첫 번째 줄에는 문자열 계산식의 길이가 주어진다. 그 다음 줄에 문자열 계산식이 주어진다.

총 10개의 테스트 케이스가 주어진다.

[출력]

#부호와 함께 테스트 케이스의 번호를 출력하고, 공백 문자 후 답을 출력한다.

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
			
			// cal_후위
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
	

