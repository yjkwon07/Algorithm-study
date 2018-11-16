package study_day1;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;
 
public class SW_1211_sol{
    static int[][] ladder;
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        ladder = new int[100][102];
        for(int i=1; i<=10; i++) {
            br.readLine();
            for(int j=0; j<100; j++) {
                StringTokenizer st = new StringTokenizer(br.readLine());
                for(int k=1; k<=100; k++) {
                    ladder[j][k] = Integer.parseInt(st.nextToken());
                }
            }
             
            int min = Integer.MAX_VALUE;
            int result = 0;
            for(int j=1; j<=100; j++) {
                if(ladder[0][j] == 1) {
                    int t = findGate(0,j,0,1);
                    if(t <= min) { 
                        min = t;
                        result = j-1;
                    }
                }
            }
            System.out.println("#"+i+" "+result);       
        }
    }
    private static int findGate(int x,int y,int check,int result) {
        if(ladder[x][y-1] == 1 && check == 0) {
            while(true) {
            	y--;
                result++;
                if(ladder[x][y] == 0) return findGate(x, y+1,1,result-1);
            }x
        }else if(ladder[x][y+1] == 1 && check == 0) {
            while(true) {
                y++;
                result++;
                if(ladder[x][y] == 0) return findGate(x, y-1,1,result-1);
            }
        }else {
            if(x+1>=100) return result++;
            return findGate(x+1, y, 0,result+1);
        }
         
    }
}



