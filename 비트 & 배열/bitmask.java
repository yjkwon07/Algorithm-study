package study_day1;
/*
 * bit_mask
 * reverse
 * ��Ʈ�� ���� �� �Ųٷ� ����� �Ǿ� �ùٸ� ��Ʈ���� ��������� �ٽ� reverse()�� ����Ѵ�.
 */
public class bitmask {
	public static void main(String[] args) {
		int a= 355;
		
		System.out.println(""+Integer.toBinaryString(a));
		
	//	for(int i = 0; i < 32; i++) {
	//		// reverse
	//		if( ( (a >> i) &  1) == 1) {
	//			System.out.print("1");
	//		}
	//		else
	//			System.out.print("0");
	//		if(i != 0 && i % 4 == 0)
	//			System.out.println();
	//	}
		
		int b =0;
		while (a!=0){
			  b<<=1;
			  b|=( a &1);
			  a>>=1;
			System.out.println(b);
		}
		
		System.out.println(Integer.toBinaryString(b));
		System.out.println(Integer.reverse(b));
		int x =Integer.reverse(b);
		System.out.println(Integer.toBinaryString(x));
	}
}
