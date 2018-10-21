package study_day1;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;

public class number20_sol {

	     
	    static HashMap<Integer, Integer> hm;
	    static Set<String> st;
	    static int n,m;
	    static StringBuilder sb;
	    static boolean start;
	    static byte digit_number;
	    static int current_digit;
	    static int save_result[];
	    static int new_code[];
	    static int code_len = 56;
	    static int code_count = 8;
	    static int code_rate = 99999;
	    static boolean rate_calc;
	    static int total_count;
	    static int hex_count = 1;
	    static int save_index = 1;
	 
	    public static void maissn(String[] args) throws NumberFormatException, IOException {
	        // TODO Auto-generated method stub
	        hm = new HashMap<>();
	        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	        // count 
	        int tc = Integer.valueOf(br.readLine());
	        // 비율 저장 
	        hm = new HashMap<>();
	        hm.put(3211, 0);
	        hm.put(2221,1);
	        hm.put(2122,2);
	        hm.put(1411,3);
	        hm.put(1132,4);
	        hm.put(1231,5);
	        hm.put(1114,6);
	        hm.put(1312,7);
	        hm.put(1213,8);
	        hm.put(3112,9);
	         
	         
	        for(int z=1; z<=tc;z++) {
	             //  n m : get 
	            String lines[] = br.readLine().split(" ");
	            n = Integer.valueOf(lines[0]);
	            m = Integer.valueOf(lines[1]);
	            st = new HashSet<>();
	            for(int i=0; i<n; i++) {
	                String line = br.readLine();
	                 
	                init_state();
	                //기존에 라인읽어서 검사 했던거면 통과하기 
	                if(st.contains(line))continue;
	                //해당 입력 hashset에 저장하기 
	                st.add(line);
	                 
	                // 입력문자의 맨 뒤에서부터 탐색을 진행해줘야함 
	                for(int k=m-1; k>=0 ;k--) {
	                    char line_index = line.charAt(k);
	                    //우리는 1부터 오는걸 찾아야함
	                     if(!start && line_index == '0') {
	                         continue;
	                     }
	                      
	                     //해당 인덱스가 0과 9 사이인지
	                     // 9보다 큰지 판단하기
	                      
	                     //0과 9 사이일 경우 해당 인덱스 값을 digit_number로 변환
	                     //byte 사용이유는 어짜피 15까지의 숫자이기 때문에 (공간절약) 
	                     if(line_index >='0' && line_index <='9') {
	                         digit_number = (byte) (line_index - '0');
//	                         System.out.println("digit: "+ digit_number);
	                     }
	                     //만약 문자가 10이상인 경우 10에 해당하는 -A(10)을 뺴준후 10을 더해서 십진수로 변환 
	                     else {
	                         digit_number = (byte) (line_index -'A' + 10);
//	                         System.out.println("digit: "+ digit_number);
	                     }
	                      
	                     //해당 발견한 첫수가 1이 될때 까지 봐야함, 0이면 지나치기 
	                     //16진수를 2진수로 ,, 4비트니까
	                     //12 - > 1100
	                     //6 ->  0110
	                     //3 -> 0011
	                     //1 -> 0001
	                     //4 -> 0100
	                     // 894
	                     // 0010 1001 0100 
	                     // start = false 
	                     // hexcount = 1 
	                     // coderate = 99999 
	                     // code_lan 
	                     // save_index = 0 
	                     //  0 : 0 : 0 : 0 
	                     // 00000 111 0000 111 000 1110  
	                     // 5 : 3: 2 :5 : 
	                     sb.append(line_index);
	                     for(int search=0; search<=3; search++) {
	                         //처음비트가 1인경우를 찾았음 
	                         if(!start && ((digit_number >> search) & 1) == 1) {
	                             start = true;
	                             save_result[save_index]++;
	                             current_digit = (digit_number >> search) & 1;
	                              
	                         }
	                         else if(start && hex_count < code_rate * code_len ){
	                              
	                             //현재 비교할 current_digit과 다음에 넘어온 비트가 다른경우 
	                             //index를 증가시켜줘야함 
	                             if(current_digit != ((digit_number >> search) & 1)) {
	                                 save_index = (save_index+1) % 4;
	                                  
	                                 //배열이 다차고 하나의 암호가 완성된 경우임 
	                                 if(save_index == 0) {
	                                     //해당 라인의 코드 비율을 구해줘야함
	                                     // 56의 배수라 했음으로 해당 길이만큼 비율을 맞춰주면됨 
	                                     if(!rate_calc) {
//	                                    	 System.out.println("coderate: "+ code_rate);
//	                                    	 System.out.println("save: "+save_result[1]+" "+save_result[0]);
	                                         code_rate = gcd(save_result[2],save_result[0]);
	                                         rate_calc=true;
	                                     }
	                                     calc_code();
//	                                     System.out.println("coderate: "+ code_rate);
	                                 }
	                             }
	                             save_result[save_index]++;
	                             hex_count++;
	                             current_digit = (digit_number >> search) & 1;
	                              
	                         }
	                     }
	                     
//	                     System.out.println("coderate: "+ code_rate);
	                     if(hex_count == code_rate * code_len) {
	                         System.out.println("st:"+st.toString());
	                         
	                         if(st.contains(sb.toString())) {
	                             init_state();
	                             continue;
	                         }
	                         calc_code();
	                         st.add(sb.toString());
	                         
	                         total_count += calc_index_sum();
	                         init_state();
	                         
	                     }
	                      
	                      
	                      
	                }
	            }
	             System.out.println("#" + z + " "+total_count);
	             total_count = 0;
	        }
	         
	    }
	     
	    public static void init_state() {
	        hex_count =1;
	        code_count = 8;
	        new_code = new int[code_count];
	        rate_calc = false;
	        save_index = 0;
	        sb = new StringBuilder();
	        start = false;
	        save_result = new int[4];
	    }
	     
	    public static int calc_index_sum() {
	        int temp_index =1;
	        int even_sum = 0;
	        int old_sum = 0;
	        int total = 0;
	        for(int i=0; i<8; i++) {
	            //짝수 
	            if(temp_index++ % 2 ==0 ) {
	                even_sum += new_code[i];
	            }
	            else {
	                old_sum +=new_code[i];
	            }
	        }
	        total =  old_sum*3 + even_sum;
	         
	         
	        int result = 0;
	        if(total % 10 ==0) {
	            for(int i=0; i<8; i++)
	                result+=new_code[i];
	        }
	     
	        return result;
	    }
	     
	    public static void calc_code() {
	         
	        int index_count = 0;
	        //2131
	   
	        for(int i=0; i<4;i++) {
	            index_count += save_result[i] *Math.pow(10, i);
	        }
	         
	        // index_count = 1312
//	      System.out.println(hm.get(index_count));
//	 System.out.println("code_rate: "+ code_rate);
	        new_code[--code_count] = hm.get(index_count/code_rate);
	        save_result = new int[4];
	         
	         
	    }
	     
	    public static int gcd(int a, int b) {
	        if(b == 0) {
	            return a;
	        }
	        else return gcd(b , a%b);
	    }
}
