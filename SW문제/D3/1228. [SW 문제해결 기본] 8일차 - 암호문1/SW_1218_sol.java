package study_day1;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.StringTokenizer;
 
public class SW_1218_sol {
 
    public static void main(String[] args) throws NumberFormatException, IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringBuilder sb = new StringBuilder();
        int T = 10;
 
        for (int z = 1; z <= T; z++) {
            int N = Integer.parseInt(br.readLine());
            StringTokenizer st = new StringTokenizer(br.readLine());
            ArrayList<String> lst = new ArrayList<String>(N);
            for (int i = 0; i < N; i++) {
                lst.add(st.nextToken());
            }
 
            int numOfIns = Integer.parseInt(br.readLine());
            st = new StringTokenizer(br.readLine());
            for (int i = 0; i < numOfIns; i++) {
                String first = st.nextToken();
                 
                switch(first) {
                case "I":
                    int iX = Integer.parseInt(st.nextToken());
                    int iY = Integer.parseInt(st.nextToken());
                     
                    for(int j=0; j<iY; j++) {
                        lst.add(iX+j, st.nextToken());
                    }
                     
                    break;
                     
                case "D":
                    int dX = Integer.parseInt(st.nextToken());
                    int dY = Integer.parseInt(st.nextToken());
                    for(int j=0; j<dY; j++) {
                        lst.remove(dX);
                    }
                    break;
                     
                case "A":
                    int aY = Integer.parseInt(st.nextToken());
                    for(int j=0; j<aY; j++) {
                        lst.add(st.nextToken());
                    }
                    break;
                }
            }
            sb.append("#"+z + " ");
            for(int j=0; j<10; j++) {
                sb.append(lst.get(j) + " ");
            }
            sb.append("\n");
        }
        System.out.print(sb);
         
 
    }
 
}