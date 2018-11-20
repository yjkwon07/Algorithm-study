package study_day1;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Stack;

/*
그림과 같이 도식화한 지도에서 A도시에서 출발하여 B도시로 가는 길이 존재하는지 조사하려고 한다.

길 중간 중간에는 최대 2개의 갈림길이 존재하고, 모든 길은 일방 통행으로 되돌아오는 것이 불가능하다.

다음과 같이 길이 주어질 때, A도시에서 B도시로 가는 길이 존재하는지 알아내는 프로그램을 작성하여라.

 - A와 B는 숫자 0과 99으로 고정된다.

 - 모든 길은 순서쌍으로 나타내어진다. 위 예시에서 2번에서 출발 할 수 있는 길의 표현은 (2, 5), (2, 9)로 나타낼 수 있다.

 - 가는 길의 개수와 상관없이 한가지 길이라도 존재한다면 길이 존재하는 것이다.

 - 단 화살표 방향을 거슬러 돌아갈 수는 없다.
 */

/*
 [제약 사항]

출발점은 0, 도착점은 99으로 표현된다.

정점(분기점)의 개수는 98개(출발점과 도착점 제외)를 넘어가지 않으며, 한 개의 정점에서 선택할 수 있는 길의 개수도 2개를 넘어가지 않는다.

아래 제시된 가이드 라인은 제안사항일 뿐 강제사항은 아니다.
 */

/*
 [데이터 저장 가이드]

정점(분기점)의 개수가 최대 100개 이기 때문에, size [100]의 정적 배열 2개을 선언하여, 각 정점의 번호를 주소로 사용하고, 저장되는 데이터는 각 정점에서 도착하는 정점의 번호를 저장한다.

위 그림을 저장하였을 때 결과는 다음과 같다.
 */

/*
 [입력]

각 테스트 케이스의 첫 줄에는 테스트 케이스의 번호와 길의 총 개수가 주어지고 그 다음 줄에는 순서쌍이 주어진다.

순서쌍의 경우, 별도로 나누어 표현되는 것이 아니라 숫자의 나열이며, 나열된 순서대로 순서쌍을 이룬다. 
 */

public class SW_1219 {
	static int[] stack_line1 = new int[100];
	static int[] stack_line2 = new int[100];
	
	public static void main(String[] args) throws IOException{
		BufferedReader bf = new BufferedReader(new InputStreamReader(System.in));
		Stack<Integer> st = new Stack<>();

		//10번 순회
		for(int count =1; count<=10; count++) {

			bf.readLine();
			String stack_string[] = bf.readLine().split(" ");			
			
			// 초기화 
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
				// stack1 갈 수 있을 때
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

				// 둘 다 길이 없을 때
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
