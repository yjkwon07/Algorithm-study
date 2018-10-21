package study_day1;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.lang.reflect.Array;
import java.util.Arrays;

public class number19_sol{
	// static -> 공유 변수 
	static int[] code10;
	
	// sol과 다른점 -> sysout을 main method에 기입 
	// int 반환을 하여 단지 0 or sum을 출력 한다. 
	public static int verify() {
		int sum  = 0;
    	int ret = (code10[0]+code10[2]+code10[4]+code10[6])*3+code10[1]+code10[3]+code10[5]+code10[7];
        if(ret % 10 != 0) return 0;
        for(int i = 0; i < code10.length; i++) {
            sum += code10[i];
        }
        return sum;
	}
	
	public static void main(String[] args) {
	
		try {
			BufferedReader bf = new BufferedReader(new InputStreamReader(System.in));
			
			// BufferWriter -> 라인으로 끊지 않고 계속 이어서 출력 
			// networking 
			BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
			
			int cases = Integer.parseInt(bf.readLine());
			for(int c = 0; c<cases; c++) {
				bw.append("#"+(c+1)+" ");
				String[] size = bf.readLine().split(" ");
				int x= Integer.parseInt(size[0]);
				int y = Integer.parseInt(size[1]);
				
				// 여기서는 2차원 array 
				int start_x = 0;
				int start_y = 0;
				char [][] arr = new char[x][y];
				String []code = new String[8];
				code10 = new int[8];
				
				// for문 라인 수 줄이기 
				// 초기화 하는 과정 code 모든 배열을 -> ""로 초기화 한다.
				Arrays.fill(code, "");
				boolean flag = true; 
				for(int i =0; i < x; i++) {
					String s = bf.readLine();
					for(int j=0; j < y; j++) {
						// arr문자에 값을 입력 
						// 크기 N * M
						arr[i][j] = s.charAt(j);
						
						// 전체 라인을 가져 와야 하기 때문에 
						// breaks; 로 바로 끝낼 수 는 없다.
						// 전체라인은 56개의 문자열 
						if(s.charAt(j) == '1') {
							start_x = i; 
							start_y = j-55;
						}
					}
				}
				
				
				int idx = 0;
				for(int i = 0; i < 56; i ++) {
					code[idx] += arr[start_x][start_y];
					// 0 - 7 순환 
					if( (i+1 % 7 == 0) && (i != 0) )
						idx++;
				}
				
                for(int i = 0; i<code.length; i++) {
                    // String 비교는 equals 
                	if(code[i].equals("0001101")) code10[i] = 0;
                    else if (code[i].equals("0011001")) code10[i] = 1;
                    else if (code[i].equals("0010011")) code10[i] = 2;
                    else if (code[i].equals("0111101")) code10[i] = 3;
                    else if (code[i].equals("0100011")) code10[i] = 4;
                    else if (code[i].equals("0110001")) code10[i] = 5;
                    else if (code[i].equals("0101111")) code10[i] = 6;
                    else if (code[i].equals("0111011")) code10[i] = 7;
                    else if (code[i].equals("0110111")) code10[i] = 8;
                    else if (code[i].equals("0001011")) code10[i] = 9;
                }
                
                bw.append(String.valueOf(verify()));
                bw.append("\n");
			}
			bw.flush();
		}
		catch (Exception e) {
			e.printStackTrace();
		}
	}
}
