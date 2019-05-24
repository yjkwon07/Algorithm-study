package study_day1;

import java.io.BufferedReader;
import java.io.CharArrayReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.LinkedList;
import java.util.Queue;
import java.util.Stack;

public class SW_1232 {
	static class Node{
		int left;
		int right;
		String val;
		Node(String val, int left, int right) {
			this.val = val;
			this.left = left;
			this.right = right;
		}
	}

	static Node node;
	static int total;
	static Node tree[];
	static Queue<Integer> st = new LinkedList<>();
	static Stack<Integer> qu = new Stack<>();
	static int a ,b;
	public static void main(String[] args) throws IOException{
		BufferedReader bf = new BufferedReader(new InputStreamReader(System.in));
		for(int c =1; c <=10; c++) {
			int count = Integer.parseInt(bf.readLine());
			tree = new Node[count+1];
			for(int i =1; i<=count; i++) {
				String array[] = bf.readLine().split(" ");
				if(array.length == 3) {
					node = new Node(array[1],Integer.parseInt(array[2]), 0);
					tree[i] = node;
				}
				else if(array.length == 4) {
					node = new Node(array[1],Integer.parseInt(array[2]), Integer.parseInt(array[3]));
					tree[i] = node;
				}
				else {
					node = new Node(array[1],0 ,0);
					tree[i] = node;
				}					
			}
			
			recursive(1);
			total = qu.pop();
			System.out.println("#"+c+" "+total);
		}
	}

	private static void recursive(int i) {
		if(tree[i].left != 0)
			recursive(tree[i].left );
		if(tree[i].right != 0)
			recursive(tree[i].right );

		switch(tree[i].val.charAt(0)) {
			
			case '*':
				a = qu.pop();
				b =qu.pop();
//				System.out.println(a+" "+ b);
				qu.push(a* b);
			break;
			case '/':
				a = qu.pop();
				b =qu.pop();
//				System.out.println(a+" "+ b);
				qu.push(b / a);			
			break;
			case '-':
				a = qu.pop();
				b =qu.pop();
//				System.out.println(a+" "+ b);
				qu.push(b -a);
			break;
			
			case '+':
				a = qu.pop();
				b =qu.pop();
//				System.out.println(a+" "+ b);
				qu.push(b + a);
			break;
			
			default:
				qu.push(Integer.parseInt(tree[i].val));
			break;
		}
		
		
		
		
	}
}
