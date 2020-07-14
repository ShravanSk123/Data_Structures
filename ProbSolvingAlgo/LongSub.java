import java.util.*;

class ModStack{
	static void pushint(Stack<Integer> stack1,Stack<Integer> stack2,int x){
	    stack1.push(new Integer(x));
		if(stack2.size()==0){
			stack2.push(x);
		}
		else{
			int mins = Math.min(x,stack2.peek());
			stack2.push(mins);
		}
	}
	static void popint(Stack<Integer> stack1,Stack<Integer> stack2){
	    Integer y1 = (Integer)stack1.pop();
		Integer y2 = (Integer)stack2.pop();
	}
	static int getMin(Stack<Integer> stack2){
		return (Integer)stack2.peek();
	}
	public static void main(String[] args){
	    Stack<Integer> stack1 = new Stack<Integer>(); //stores the stack elements
	    Stack<Integer> stack2 = new Stack<Integer>(); //stores the minimum in resultant stack
	    pushint(stack1,stack2,10);
	    pushint(stack1,stack2,2);
	    pushint(stack1,stack2,3);
	    pushint(stack1,stack2,8);
	    popint(stack1,stack2);
	    System.out.println(stack1);
	    System.out.println(stack2);
	    System.out.println(getMin(stack2));
	    
	}
}
