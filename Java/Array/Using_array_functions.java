
import java.lang.reflect.Array;
import java.util.Arrays;
import java.util.Scanner;


/**
 *
 * @author Dipty
 */
public class Using_array_functions {
    public static void main(String[] args) {
        int arr[] = {4, 6, 1, 8, 3, 9, 7, 4, 2};
        //sorting array non descending order
        Arrays.sort(arr);
        System.out.println(Arrays.toString(arr));
        
        
         // Copy the whole array
        int[] copy = Arrays.copyOf(arr, arr.length);
        System.out.println("Copied array => \n" + 
                           Arrays.toString(copy));
 
        // Copy a specified range into a new array.
        int[] rcopy = Arrays.copyOfRange(arr, 1, 5);
        System.out.println("Copied subarray => \n" + 
                           Arrays.toString(rcopy));
        
         // To fill a range with a particular value
        Arrays.fill(arr, 0, 4, 0);
        System.out.println("Array filled with 0 "+
          "from 0 to 3 => \n" + Arrays.toString(arr));
 
        // To fill complete array with a particular value
        Arrays.fill(arr, 10);
        System.out.println("Array completely filled"+
                  " with 10=>\n"+Arrays.toString(arr));
    }
}
