package study_day1;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.LinkedList;
import java.util.Queue;


/*
 ���� �־��� ���ǿ� ���� n���� ���� ó���ϸ� 8�ڸ��� ��ȣ�� ������ �� �ִ�.

- 8���� ���ڸ� �Է� �޴´�.

- ù ��° ���ڸ� 1 ������ ��, �� �ڷ� ������. 

���� ù ��° ���� 2 ������ �� �� �ڷ�, �� ���� ù ��° ���� 3�� �����ϰ� �� �ڷ�, �� ���� ���� 4, �� ���� ���� 5�� �����Ѵ�.

�̿� ���� �۾��� �� ����Ŭ�̶� �Ѵ�.

- ���ڰ� ������ �� 0���� �۾����� ��� 0���� �����Ǹ�, ���α׷��� ����ȴ�. �� ���� 8�ڸ��� ���� ���� ��ȣ�� �ȴ�.

[���� ����]

�־����� �� ���� integer ������ ���� �ʴ´�.

������ ��ȣ �迭�� ��� �� �ڸ� ���� �����Ǿ� �ִ�.
 
[�Է�]

�� �׽�Ʈ ���̽��� ù �ٿ��� �׽�Ʈ ���̽��� ��ȣ�� �־�����, �� ���� �ٿ��� 8���� �����Ͱ� �־�����.
 
[���]

#��ȣ�� �Բ� �׽�Ʈ���̽��� ��ȣ�� ����ϰ�, ���� ���� �� �׽�Ʈ ���̽��� ���� ����Ѵ�.
 */



public class SW_1225{
	public static void main(String[] args) throws IOException {
		BufferedReader bf = new BufferedReader(new InputStreamReader(System.in));
		Queue<Integer> qu = new LinkedList<>();
		for(int count=1; count<=10; count++) {
			bf.readLine();
			String pre_array[] = bf.readLine().split(" ");
			for(int x=0; x<pre_array.length; x++) {
//				System.out.println("queue: "+Integer.parseInt(pre_array[x]));
				qu.offer(Integer.parseInt(pre_array[x]));
			}
			
			int x = -1;
			int dis =1; 
//			int loop_count =1;
			while(x!=0) {
				int number = qu.poll();
//				System.out.println("dis: "+dis);
				x = number-dis;
				
				if (x<0) {
					qu.offer(0);
					break;
				}
				else if(dis == 5) {
					qu.offer(x);
					dis=1;
				}
				
				else {
					qu.offer(x);
					dis++;
				}
				
			}
			System.out.print("#"+count);
			
			while(!qu.isEmpty())
				System.out.print(" "+qu.poll());
			System.out.println();
		}
	}
}
