package study_day1;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.regex.Matcher;
import java.util.regex.Pattern;

public class SW_1213{
	public static void main_pre(String[] args) throws IOException{
		BufferedReader bf = new BufferedReader(new InputStreamReader(System.in));
		for(int count =0; count<10; count++) {
			bf.readLine();
			String check = bf.readLine();
			String or_char = bf.readLine();
			if(or_char.length() >1000)
				break;
			else {
				Pattern p = Pattern.compile(check);
				Matcher m = p.matcher(or_char);
				int check_number = 0;
				while(m.find()) { 
					check_number++;
				}
				System.out.println("#"+(count+1)+" "+check_number);
			}
		}
	}
}
