package study_day1;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.LinkedList;
import java.util.Queue;
 
public class number15_sol {
    static final int n = 16;
    static final int dx[] = {0,0,1,-1};
    static final int dy[] = {1,-1,0,0};
    static int map[][];
    static boolean visit[][];
    
    static class nn{
        int x , y;
        nn(int x, int y) {
            this.x= x;
            this.y= y;
        }
    }
    
    static boolean finish ;
    
 public static void main_sol(String[] args) throws IOException{
    BufferedReader bf=  new BufferedReader(new InputStreamReader(System.in));
    int testcase = 10;
    Queue<nn> q ;
    for(int t=1; t<=testcase; t++){
        int k = Integer.parseInt(bf.readLine());
        map = new int[n][n];
        visit = new boolean[n][n];
        q= new LinkedList<>();
        finish = false;
        for(int i=0; i<16; i++){
            String str = bf.readLine();
            for(int j=0; j<16; j++){
                map[i][j] = str.charAt(j)-48;
                if(map[i][j] == 2){
                    q.offer(new nn(i,j));                   
                    visit[i][j] = true;
                }
            }
        }
         
        while(!q.isEmpty()){
            nn p = q.poll();
            if(map[p.x][p.y] == 3){
                finish = true;
                break;
            }
            for(int i=0; i<4; i++){
                int x= p.x+dx[i];
                int y= p.y+dy[i];
                if(x>=0 && y>=0 && x<n && y<n && map[x][y] !=1){
                    if(visit[x][y] == false){
                        visit[x][y] = true;
                        q.offer(new nn(x,y));
                    }
                }
            }
        }
         
        if(finish){
            System.out.println("#"+t+" "+1);
        }
        else{
            System.out.println("#"+t+" "+0);
        }
    }
    bf.close();
 }
  
}
