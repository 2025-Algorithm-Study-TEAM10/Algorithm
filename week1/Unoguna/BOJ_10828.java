package week01.Unoguna;
import java.io.*;
import java.util.*;

public class BOJ_10828 {

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        Stack<Integer> stack= new Stack<>();

        int N = Integer.parseInt(br.readLine());
        for(int i=0; i<N; i++){
            String[] op = br.readLine().split(" ");
            if(op.length == 1){
                if(op[0].equals("top")){
                    if(!stack.isEmpty()) System.out.println(stack.lastElement());
                    else System.out.println("-1");
                }
                else if(op[0].equals("size")){
                    System.out.println(stack.size());
                }
                else if(op[0].equals("empty")){
                    if(stack.isEmpty()) System.out.println("1");
                    else System.out.println("0");
                }
                else if(op[0].equals("pop")){
                    if(!stack.isEmpty()) System.out.println(stack.pop());
                    else System.out.println("-1");
                }
            }
            else{
                int num = Integer.parseInt(op[1]);
                stack.push(num);
            }
        }
    }

}
