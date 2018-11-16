package study_day1;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.Arrays;
import java.util.HashMap;
import java.util.HashSet;
import java.util.Map;
import java.util.Set;

public class SW_1240 {
	
	public static int rate_code[] = new int[4]; // 4개의 비율 rate
	public static int total_code[] = new int[8]; // 8개의 암호 코드 
	public static int rate = 99999; // rate의  초기 비율 
	public static int total = 0;
	public static Map<String, Integer> map;
	public static int count_point =7; // code는 마지막 부터 -> 0까지 
	public static int idx = 0; // rate_code의 인덱스
	public static Set<String> st; // 중복 검사  피하기
	public static int rate_count = 0; // rate의  카운팅 
	public static boolean start_flag = false; // 마지막 1의 시작점을 찾았는가? 
	public static byte current_point = 0; // 현재 위치 값 ( 0 || 1)
	public static boolean rate_ischeck = false; // 비율 구했냐 ? 
	
	public static void init() {
		st.clear(); //st 초기화 
		rate_count = 0; // rate (계산해야할 길이 측정  초기화 )
		idx = 0; // idx 초기화
		start_flag = false;
		current_point =0; 
		rate_ischeck = false;
		rate = 99999; 	
		Arrays.fill(rate_code,0);
	}
	
	public static void main(String[] args) throws IOException {
		BufferedReader bf = new BufferedReader(new InputStreamReader(System.in));
		BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
		st= new HashSet<>(); 
		StringBuilder sb = new StringBuilder(); // 마지막 배열의 1을 찾은 후 저장 rate의 비율로 

		map = new HashMap<>();
		map.put("3211", 0);
		map.put("2221", 1);
		map.put("2122", 2);
		map.put("1411", 3);
		map.put("1132", 4);
		map.put("1231", 5);
		map.put("1114", 6);
		map.put("1312", 7);
		map.put("1213", 8);
		map.put("3112", 9);

		// 라인 입력 
		int count = Integer.parseInt(bf.readLine());
		int N = 0;
		int M = 0;
		
		for(int i = 1; i <= count; i++) {
			String array[] = bf.readLine().split(" ");
			N = Integer.parseInt(array[0]);
			M = Integer.parseInt(array[1]);
			init();
			
			for ( int k = 0; k < N; k++ ) {
				String get_line = bf.readLine(); 
								
				if(st.contains(get_line)) {
					continue;
				}
				
				else {
					st.add(get_line);
					for(int j = M-1; j >=0; j--) {						
						
						if(!start_flag && get_line.charAt(j) == '1') {
							sb.append(get_line.charAt(j));
							rate_code[idx]++;
							start_flag = true;
							rate_count++;
							current_point = (byte)(get_line.charAt(j) - '0');
						}
						
						else if(start_flag && rate_count < rate * 56) { // 56개수 * 비율 => 계사해야할 크기
							sb.append(get_line.charAt(j));							
							if(current_point != (byte)(get_line.charAt(j) - '0') ) {
								idx++;
								idx %= 4;
								if(idx == 0 ) {								
									if(!rate_ischeck) {
										rate = rate_check(rate_code[2], rate_code[0]); // GCD
										rate_ischeck = true;
									}
									code_check();
									Arrays.fill(rate_code, 0);
								}
							}							
							rate_code[idx]++;
							rate_count++;
							current_point = (byte)(get_line.charAt(j) - '0');
						}
						

					}
					
					if(rate_count == rate * 56) {
						if(!st.contains(sb.toString())) {
							st.add(sb.toString());
							code_check();
							check_security();
							System.out.println("#"+i+" "+total);
						}
					}

				} // else _end
			}
		}
	}

	private static void check_security() {
		// TODO Auto-generated method stub
		int sum = 0; 
		sum = ( total_code[0] + total_code[2] + total_code[4] + total_code[6]) * 3 + (total_code[1] + total_code[3] + total_code[5] + total_code[7]  );
		if( sum % 10 == 0) { 
			total = (total_code[0]+total_code[1]+total_code[2]+total_code[3]+total_code[4]+total_code[5]+total_code[6]+total_code[7]);
		}
		else 
			total= 0;
	}

	private static int rate_check(int a, int b) {
		// TODO Auto-generated method stub
		if(b == 0) return a; 
		else 
			return	rate_check(b , a%b);
	}

	private static void code_check() {
		// TODO Auto-generated method stub
		StringBuilder sb = new StringBuilder();
		sb.append(""+rate_code[3]+rate_code[2]+rate_code[1]+rate_code[0]);
		int check = Integer.parseInt(sb.toString()) / rate;
		total_code[count_point] = map.get(String.valueOf(check));
		count_point--;
		if(count_point == -1)
			count_point = 7;
	}

}