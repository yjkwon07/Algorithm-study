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
	        // ���� ���� 
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
	                //������ �����о �˻� �ߴ��Ÿ� ����ϱ� 
	                if(st.contains(line))continue;
	                //�ش� �Է� hashset�� �����ϱ� 
	                st.add(line);
	                 
	                // �Է¹����� �� �ڿ������� Ž���� ����������� 
	                for(int k=m-1; k>=0 ;k--) {
	                    char line_index = line.charAt(k);
	                    //�츮�� 1���� ���°� ã�ƾ���
	                     if(!start && line_index == '0') {
	                         continue;
	                     }
	                      
	                     //�ش� �ε����� 0�� 9 ��������
	                     // 9���� ū�� �Ǵ��ϱ�
	                      
	                     //0�� 9 ������ ��� �ش� �ε��� ���� digit_number�� ��ȯ
	                     //byte ��������� ��¥�� 15������ �����̱� ������ (��������) 
	                     if(line_index >='0' && line_index <='9') {
	                         digit_number = (byte) (line_index - '0');
//	                         System.out.println("digit: "+ digit_number);
	                     }
	                     //���� ���ڰ� 10�̻��� ��� 10�� �ش��ϴ� -A(10)�� ������ 10�� ���ؼ� �������� ��ȯ 
	                     else {
	                         digit_number = (byte) (line_index -'A' + 10);
//	                         System.out.println("digit: "+ digit_number);
	                     }
	                      
	                     //�ش� �߰��� ù���� 1�� �ɶ� ���� ������, 0�̸� ����ġ�� 
	                     //16������ 2������ ,, 4��Ʈ�ϱ�
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
	                         //ó����Ʈ�� 1�ΰ�츦 ã���� 
	                         if(!start && ((digit_number >> search) & 1) == 1) {
	                             start = true;
	                             save_result[save_index]++;
	                             current_digit = (digit_number >> search) & 1;
	                              
	                         }
	                         else if(start && hex_count < code_rate * code_len ){
	                              
	                             //���� ���� current_digit�� ������ �Ѿ�� ��Ʈ�� �ٸ���� 
	                             //index�� ������������� 
	                             if(current_digit != ((digit_number >> search) & 1)) {
	                                 save_index = (save_index+1) % 4;
	                                  
	                                 //�迭�� ������ �ϳ��� ��ȣ�� �ϼ��� ����� 
	                                 if(save_index == 0) {
	                                     //�ش� ������ �ڵ� ������ ���������
	                                     // 56�� ����� �������� �ش� ���̸�ŭ ������ �����ָ�� 
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
	            //¦�� 
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
