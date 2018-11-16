package study_day1;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class SW_1218{
	public static void main(String[] args) throws IOException {
		BufferedReader bf= new BufferedReader(new InputStreamReader(System.in));
		for(int count=1; count<=10; count++) {
			int length= Integer.parseInt(bf.readLine());
			String[] check =new String[length];
			check = bf.readLine().split("");
			char get_start[] = new char[length];
			int start = 1;
		
			for(int loop=0; loop<length; loop++) {
				if(check[loop].charAt(0) == '{' || check[loop].charAt(0) == '[' || check[loop].charAt(0) =='(' || check[loop].charAt(0) =='<') {
					get_start[start] = check[loop].charAt(0);
					start++;
				}
				
				else if( check[loop].charAt(0) == '}' || check[loop].charAt(0) == ']' || check[loop].charAt(0) ==')' || check[loop].charAt(0) =='>' ) {
					start--;	
					if(start == 0)
						break;
					else if(check[loop].charAt(0) == '}') {
							while(get_start[start] != '{' ) {
								start--;
								if(start < 0)
									break;
							}
						}
						else if(check[loop].charAt(0) == ']') {
							while(get_start[start] != '[' ) {
									start--;
									if(start == 0)
										break;
								}
							}
						else if( check[loop].charAt(0) ==')' ) {
							while(get_start[start] != '(' ) {
								start--;
								if(start == 0)
									break;
								}
						}
						else {
							while(get_start[start] != '<' ) {
								start--;
								if(start == 0)
									break;
							}
						}
				}
				
				else 
					System.out.println("#"+count+" "+0);
			}

			if(start != 0)
				System.out.println("#"+count+" "+1);
			else
				System.out.println("#"+count+" "+0);
			
		}
	}
}
