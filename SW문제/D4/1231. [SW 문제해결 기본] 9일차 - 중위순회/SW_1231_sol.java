package study_day1;
import java.io.BufferedReader;
import java.io.InputStreamReader;
 
class SW_1231_sol {
 
    static int[] left;
    static int[] right;
    static String[] data;
    static String Answer = "";
 
    public static void main(String args[]) throws Exception {
 
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
 
        for (int T = 1; T <= 10; T++) {
 
            left = new int[101];
            right = new int[101];
            data = new String[101];
 
            // Input : 트리개수
            int dataSize = Integer.parseInt(br.readLine());
 
            // Input : No, Val, Left, Right
            String[] treeData;
            for (int i = 0; i < dataSize; i++) {
                treeData = br.readLine().trim().split(" ");
                int index = Integer.parseInt(treeData[0]);
                data[index] = treeData[1];
 
                if (treeData.length > 2) { // left
                    left[index] = Integer.parseInt(treeData[2]);
                }
                if (treeData.length > 3) { // right
                    right[index] = Integer.parseInt(treeData[3]);
                }
            }
 
            Answer = "";
            printTreeIn(1);
            String result = String.format("#%d %s", T, Answer);
             
            System.out.println(result);
        }
 
    }
 
    // 중위순회 (선위면 먼저 자기부터 출력, 후위면 자신을 가장 나중에 출력)
    private static void printTreeIn(int address) {
 
        if (left[address] != 0) {
            printTreeIn(left[address]);
        }
        Answer += data[address];
        if (right[address] != 0) {
            printTreeIn(right[address]);
        }
 
    }
 
}
