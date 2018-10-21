package study_day1;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.nio.Buffer;
import java.util.Arrays;
import java.util.HashMap;
import java.util.HashSet;
import java.util.Map;
import java.util.Set;

public class number20_sol2 {
	static Map<Integer, Integer>  map = new HashMap<>(); // 코드, 숫자 저장
	static Set<String> set = new HashSet<>(); // 중복 배제를 위한 저장 
	static StringBuilder sb = new StringBuilder(); // 저장할 암호 코드 
	static String now; // 입력 
	static int[] proportion = new int [4]; // 숫자를 나타내는 코드 비율 
	static int[] crypt = new int[9]; // 변환한 숫자 저장 
	static int rate, index, cryptIndex, odd, even, count;
	static byte b, p; 
	static boolean first, rateFind; // 비율을 찾았나 
	
	public static void initial() { // 초기화
		rate = 35; 
		index = odd = even =0;
		count = 1; 
		cryptIndex = 8;
		sb.setLength(0);
		Arrays.fill(proportion, 0);
		first = true;
		rateFind = false;
		b = 0;
		p = -1;
	}
	
	public static int gcd(int a, int b) { // 최대 공약수 
		if(b == 0)
			return a;
		else
			return gcd(b, a%b);
	}
	
	public static void fillCrypt() { // 코드 -> 숫자 변환
		int value =0;
		
		for (int l =0; l < 4; l++)
			value += proportion[l] * Math.pow(10, l);
		
		crypt[cryptIndex--] = map.get(value/rate);
		Arrays.fill(proportion,0); //proportion 초기화 
	}
	
	public static void mainss(String[] args) throws IOException {
		BufferedReader bf = new BufferedReader(new InputStreamReader(System.in));
		
		// testcase = T 
		int testcase = Integer.parseInt(bf.readLine());
		
        // 비율 저장 
		map.put(3211, 0); map.put(2221, 1); map.put(2122, 2); map.put(1411, 3); map.put(1132, 4);
        map.put(1231, 5); map.put(1114, 6); map.put(1312, 7); map.put(1213, 8); map.put(3112, 9);
        
        for (int z = 1; z <= testcase; z++) {
        	// line; N M
        	String[] strs = bf.readLine().split(" ");
        	int N = Integer.parseInt(strs[0]);
        	int M = Integer.parseInt(strs[1]);
        	int sum = 0; 
        	// 새로운 바코드 나올시 set 초기화
        	set.clear();
        	
        	for(int i = 0; i < N; i++) {
        		now = bf.readLine();
        		if(set.contains(now)) continue; //  이미 조사한 코드면 패스 
        		set.add(now);
        		initial();
        		
        		for(int j = M -1; j >= 0; j--) {
        			char c = now.charAt(j); 
        			if(first && c == '0') continue; // 최초의 1을 발견하기 전까지의 0은 패스 
        			
        			if(c <= '9')
        				b = (byte)(c- '0');
        			else
        				b = (byte)(c - 'A' + 10);
        			
        			for(int k = 0; k < 4; k++) { // 0000 4비트 ( 16진수 ) 
        				if(first && ( ( b >> k) & 1)  == 1 ) { // 1의 위치를 찾기 
        					first = false; 
        					proportion[index]++; // index 초기는 0 
        					p = (byte)((b >> k)  & 1); // 1 저장 
        				}// if _end
        				
        				// count 초기는 1
        				// rate 초기는 35
        				
        				else if(!first && count < 56 * rate) {
        					if( (byte) ((b >> k ) & 1) != p) {
        						index = (index + 1) % 4;
        						
        						if(index ==  0) { // 숫자 하나에 해당하는 코드를 다 채웠을 때
        							if(!rateFind) { // 비율을 모른다면 구해주기 
        								rate = gcd(proportion[2], proportion[0]);
        								rateFind = true;
        							}
        							
        							fillCrypt();
        						}
        					}
        					count++;
        					proportion[index]++;
        					p = (byte)(( b >> k ) & 1);
        				} // else if_ end 
        			} // for(k) end
        			
        			sb.append(c); 
        			
        			if(count == 56 * rate) {
        				if(set.contains(sb.toString())) { //  이미 처리한 암호면 초기화 하고 패스 
        					initial();
        					continue;
        				}
        				
        				fillCrypt();
        				int code = crypt[8];
        				
        				for(int l =1; l < 8; l++ ) {
        					if(l % 2 == 1)
        						odd += crypt[l];
        					else
        						even += crypt[l]; 
        				}
        				
        				if((odd * 3 + even + code) % 10 == 0)
        					sum += odd + even + code;
        				set.add(sb.toString());
        				initial();
        			}
        		}
        	}
        	System.out.println("#" + z + " " + sum);
        }
	}
}
