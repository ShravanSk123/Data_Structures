// returns the kth smallest or kth largest element in the given array of size n

import java.io.*;
import java.util.*;

class mainClass {
	public static void main (String[] args) {
	    Scanner sc = new Scanner(System.in);
	    int n,k;
	    n = sc.nextInt();
	    k = sc.nextInt();
	    if (k > n) {
        throw new ArithmeticException("k must be less than or equal to n");
      }
    
	    int a[] = new int[n];
		  //PriorityQueue<Integer> p = new PriorityQueue<>(); // creates min heap for kth smallest
		  PriorityQueue<Integer> p = new PriorityQueue<>(Collections.reverseOrder()); //creates max heap for kth largest
		  for(int i=0;i<n;i++){
		    a[i] = sc.nextInt();
		    p.add(a[i]); // add element to priority queue()min heap or max heap
		  }
    
		  int ke=0;
		  while(!p.isEmpty() && k>0){
		    ke = p.peek(); // fetches the top most element
		    p.poll(); // deletes the top most element
		    k--;
		  }
    
		  System.out.println(ke);
  }
}
