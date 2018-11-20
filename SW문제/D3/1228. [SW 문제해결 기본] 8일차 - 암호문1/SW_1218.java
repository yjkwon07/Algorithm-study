package study_day1;

import java.util.List;

/* 
 * 
 0 ~ 999999 ������ ���� �����Ͽ� ���� ��ȣ���� �ִ�.

��ȣ���� ���� �����ؾ� �� ���� �߻��ߴµ�, �� ��ȣ���� Ư�� ���۵� ó����θ� ������ �����ϴ�.

�� ó����� ������ ���� 1���� ����� �����Ѵ�.

1. I(����) x, y, s : �տ������� x�� ��ġ �ٷ� ������ y���� ���ڸ� �����Ѵ�. s�� ������ ���ڵ��̴�.[ ex) I 3 2 123152 487651 ]

���� ��Ģ�� �°� �ۼ��� ��ɾ �����Ͽ� ���� ���ڿ��� �־����� ��, ��ȣ���� �����ϰ�, ������ ����� ó�� 10�� ���ڸ� ����ϴ� ���α׷��� �ۼ��Ͽ���.

[�Է�]

ù ��° �� : ���� ��ȣ���� ���� N ( 10 �� N �� 20 �� ����)

�� ��° �� : ���� ��ȣ��

�� ��° �� : ��ɾ��� ���� ( 5 �� N �� 10 �� ����)

�� ��° �� : ��ɾ�

���� ���� �� ���� �� ���� �׽�Ʈ ���̽��̸�, �� 10���� �׽�Ʈ ���̽��� �־�����.

[���]

#��ȣ�� �Բ� �׽�Ʈ ���̽��� ��ȣ�� ����ϰ�, ���� ���� �� ������ ��ȣ���� ó�� 10�� ���� ����Ѵ�.

I
 */

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;

public class SW_1218 {
	public static void main(String[] args) throws IOException {
		BufferedReader bf= new BufferedReader(new InputStreamReader(System.in));
		List<Integer> list = new ArrayList<Integer>();
	
		for(int count =1; count <= 10; count++) {
			int start_line = Integer.parseInt(bf.readLine());
			String pre_array[] = bf.readLine().split(" ");
			
			for(int number = 0; number < start_line; number++) {
				list.add(Integer.parseInt(pre_array[number]));
			}
			
			int third_line = Integer.parseInt(bf.readLine());
			String order_array[] = bf.readLine().split(" ");
			int location = 0;
			for(int loop = 0; loop < third_line; loop++) {
				int x, y;
				int counting =0;
				switch(order_array[location]) {
					case "I":
						x = Integer.parseInt(order_array[location+1]);
						y = Integer.parseInt(order_array[location+2]);
						for (int number2= (location+3); counting<y; number2++) {
							list.add(x, Integer.parseInt(order_array[number2]));
							x++;
							counting++;
						}
						location += y+3;
						break;
						
					case "D":
						x = Integer.parseInt(order_array[location+1]);
						y = Integer.parseInt(order_array[location+2]);
						while(counting<y) {
							list.remove(x);
							counting++;
						}
						location += 3;
						break;
						
					case "A":
						y = Integer.parseInt(order_array[location+1]);
						location++;
						while(counting<y) {
							list.add(list.size(), Integer.parseInt(order_array[location++]));
							counting++;
						}
						location ++;
						break;
				}
			}
			
			System.out.print("#"+ count);
			for(int number =0; number<10; number++) {
				System.out.print(" "+list.get(number));
			}
			System.out.println();
			list.clear();
		}
	}
}
