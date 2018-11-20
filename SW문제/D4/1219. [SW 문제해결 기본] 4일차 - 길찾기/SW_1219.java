package study_day1;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Stack;

/*
�׸��� ���� ����ȭ�� �������� A���ÿ��� ����Ͽ� B���÷� ���� ���� �����ϴ��� �����Ϸ��� �Ѵ�.

�� �߰� �߰����� �ִ� 2���� �������� �����ϰ�, ��� ���� �Ϲ� �������� �ǵ��ƿ��� ���� �Ұ����ϴ�.

������ ���� ���� �־��� ��, A���ÿ��� B���÷� ���� ���� �����ϴ��� �˾Ƴ��� ���α׷��� �ۼ��Ͽ���.

 - A�� B�� ���� 0�� 99���� �����ȴ�.

 - ��� ���� ���������� ��Ÿ��������. �� ���ÿ��� 2������ ��� �� �� �ִ� ���� ǥ���� (2, 5), (2, 9)�� ��Ÿ�� �� �ִ�.

 - ���� ���� ������ ������� �Ѱ��� ���̶� �����Ѵٸ� ���� �����ϴ� ���̴�.

 - �� ȭ��ǥ ������ �Ž��� ���ư� ���� ����.
 */

/*
 [���� ����]

������� 0, �������� 99���� ǥ���ȴ�.

����(�б���)�� ������ 98��(������� ������ ����)�� �Ѿ�� ������, �� ���� �������� ������ �� �ִ� ���� ������ 2���� �Ѿ�� �ʴ´�.

�Ʒ� ���õ� ���̵� ������ ���Ȼ����� �� ���������� �ƴϴ�.
 */

/*
 [������ ���� ���̵�]

����(�б���)�� ������ �ִ� 100�� �̱� ������, size [100]�� ���� �迭 2���� �����Ͽ�, �� ������ ��ȣ�� �ּҷ� ����ϰ�, ����Ǵ� �����ʹ� �� �������� �����ϴ� ������ ��ȣ�� �����Ѵ�.

�� �׸��� �����Ͽ��� �� ����� ������ ����.
 */

/*
 [�Է�]

�� �׽�Ʈ ���̽��� ù �ٿ��� �׽�Ʈ ���̽��� ��ȣ�� ���� �� ������ �־����� �� ���� �ٿ��� �������� �־�����.

�������� ���, ������ ������ ǥ���Ǵ� ���� �ƴ϶� ������ �����̸�, ������ ������� �������� �̷��. 
 */

public class SW_1219 {
	static int[] stack_line1 = new int[100];
	static int[] stack_line2 = new int[100];
	
	public static void main(String[] args) throws IOException{
		BufferedReader bf = new BufferedReader(new InputStreamReader(System.in));
		Stack<Integer> st = new Stack<>();

		//10�� ��ȸ
		for(int count =1; count<=10; count++) {

			bf.readLine();
			String stack_string[] = bf.readLine().split(" ");			
			
			// �ʱ�ȭ 
			for(int x=0; x<stack_line1.length; x++) {
				stack_line1[x] = -1;
				stack_line2[x] = -1;
			}
			
			int cnt=0;
			for(int x=0; x < (stack_string.length/4)+1; x++) {
//				System.out.println("cnt: "+cnt);
				stack_line1[Integer.parseInt(stack_string[cnt])] = Integer.parseInt(stack_string[cnt+1]);
//				System.out.println("stack_line1[Integer.parseInt(stack_string[cnt])]: "+stack_line1[Integer.parseInt(stack_string[cnt])] );
				if(!(stack_string.length <= cnt+2))
				stack_line2[Integer.parseInt(stack_string[cnt+2])] = Integer.parseInt(stack_string[cnt+3]);
//				System.out.println("stack_line2[Integer.parseInt(stack_string[cnt+2])]: "+stack_line2[Integer.parseInt(stack_string[cnt+2])] );
					if(stack_string.length < cnt+8 ) {
//						System.out.println("dds");
						cnt+=2;
					}
					else
						cnt+=4;
				
			}

			int DFS=0;
			int pre_DFS =0;
			boolean ok = false;

			while(true) {
				if(DFS == 99) {
					ok = true;
					break;
				}
				// stack1 �� �� ���� ��
				else if(stack_line1[pre_DFS] != -1) {
					DFS= stack_line1[pre_DFS];
					stack_line1[pre_DFS] = -1;
					st.push(pre_DFS);
					pre_DFS = DFS;			
				}
				
				// stack2
				else if(stack_line2[pre_DFS] != -1) {
					DFS= stack_line2[pre_DFS];
					stack_line2[pre_DFS] = -1;
					st.push(pre_DFS);
					pre_DFS = DFS;
				}

				// �� �� ���� ���� ��
				else if(stack_line1[pre_DFS] == -1 && stack_line2[pre_DFS] == -1 ) {
						if(st.isEmpty()) {
							ok = false;
							break;
						}
						else
							pre_DFS = st.pop();
				}
				else
					break;
			}
			
			while(!st.empty()) {
				st.pop();
			}
			
			if(ok) {
				System.out.println("#"+count+" "+1);
			}
			else
				System.out.println("#"+count+" "+0);
		}
	}
}
