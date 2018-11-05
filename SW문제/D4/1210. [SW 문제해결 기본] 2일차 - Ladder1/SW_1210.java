package study_day1;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

/*
 * 0���� ��� �迭�� �е��� �Ѵ� <- out length Error�� ���� ���� (x) -> ������ �����ϸ�Ǵϱ� ���صε�
 * ������ ���ο� 2�� ��ġ�Ѵ�.
 * ��ġ�� ��ǥ���� x,y������ �޴´�
 * ��,��,�쿡 1�� �̻��Ͽ� ��ǥ���� �����Ѵ�. 
 * �迭�� ù������ ���� ���� ��, y���� ��ȯ�Ѵ�.
 */

public class SW_1210 {
	public static void main(String[] args) throws IOException{
	    int array[][] = new int[102][102];
		String pre_array[] = new String[10000]; 
		BufferedReader bf=new BufferedReader(new InputStreamReader(System.in));
		int cnt = 0;
		int x=0;
		int y=0;
				
		// Test���� 10�� �����Ѵ�.
		for(int count = 0; count < 10; count++) {
			// ��ū �ϳ��� �� �׽�Ʈ ���̽�
			// Ȱ�� ��ġ�� ����.
			bf.readLine();
			
			// �Ѱ��� �迭�� 100�� �Է��� �޴´�.
			x=0;
			y=0;
			for(int i=0; i<100; i++) {
				pre_array=bf.readLine().split(" ");
				cnt=0;
				for(int j=0; j<100; j++) {
					array[i][j]	= Integer.parseInt(pre_array[cnt]); 
					cnt++;
					if(2 == array[i][j]) {
	    	            x = 98;
	    	            y = j;
					}
				}
			}
	
			// search start index
			while(x != 0) {
				array[x][y]=0;
		       if(y-1>=0 && (array[x][y-1] ==1)) // ��
					y--;
		       else if(y+1<100 && (array[x][y+1] == 1)) // ��
					y++;
				else // ��
					x--;
			}
			System.out.println("#"+(count+1)+" "+y);
		}


	}

}
