
import java.util.Arrays;
import java.util.Scanner;

/**
 *
 * @author Dipty
 */
public class Basic_array {
    public static void main(String[] args) {
        int[] arr = new int[1005];
        int i,j, n;
        Scanner input = new Scanner(System.in);
        n = input.nextInt();
        for( i = 0;i < n;i++)
        {
            arr[i] = input.nextInt();
        }
    
        for( i = 0;i < n;i++)
        {
            System.out.print(arr[i] + " ");
        }
        System.out.println("");
        
        
    }
}
