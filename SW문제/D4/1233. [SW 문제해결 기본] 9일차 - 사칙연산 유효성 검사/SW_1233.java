package study_day1;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

class SW_1233{
     
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        for(int testCase = 0; testCase<10; testCase++){
            int n = Integer.parseInt(br.readLine());
            int result = 1; 
             
            for(int i = 0; i< n; i++){
                String[] tmp = (br.readLine()).split(" ");
                 
                if(tmp.length==2 &&(tmp[1].equals("-")||tmp[1].equals("+")||tmp[1].equals("*")||tmp[1].equals("/")))
                {
//                	System.out.print(tmp[1]);
                	result = 0;
                }
            }
                
 
            System.out.println("#"+(testCase+1)+" "+result);
        }
    }
}