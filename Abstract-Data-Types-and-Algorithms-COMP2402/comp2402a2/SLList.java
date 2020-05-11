package comp2402a2;

import java.util.AbstractList;
import java.util.Iterator;
import java.util.Queue;
import java.util.NoSuchElementException;
import java.lang.*;

/**
 * An implementation of a FIFO Queue as a singly-linked list.
 * This also includes the stack operations push and pop, which
 * operate on the head of the queue
 * @author morin
 *
 * @param <T> the class of objects stored in the queue
 */
public class SLList<T> extends AbstractList<T> implements Queue<T> {
	class Node {
		T x;
		Node next;
	}

	/**
	 * Front of the queue
	 */
	Node head;

	/**
	 * Tail of the queue
	 */
	Node tail;

	/**
	 * The number of elements in the queue
	 */
	int n;

	public T get(int i) {
		// TODO: Implement this
		if (i < 0 || i > n - 1) throw new IndexOutOfBoundsException();
		//
		/*Node currNode = new Node();
		for(currNode = head; currNode != null && i != 0; currNode = currNode.next , --i){}
		return currNode.x;*/
		Node u = head;
		int p = 0;
		while(u != null){
			if(p == i)
				break;
			u = u.next;
			p++;
		}
		return u.x;
	}

	public T set(int i, T x) {
		// TODO: Implement this
		if (i < 0 || i > n - 1) throw new IndexOutOfBoundsException();
		/*Node currNode = new Node();
		for(currNode = head ;currNode != null && i != 0 ; currNode = currNode.next , i--){}
			T temp = currNode.x;
			currNode.x = x;
			return temp;*/
			Node u = head;
			int p = 0;
			while(u != null){
				if(p == i)
					break;
				u = u.next;
				p++;
			}
			T temp = u.x;
			u.x = x;
			return temp;

	}

	public void add(int i, T x) {
		// TODO: Implement this
		if (i < 0 || i > n) throw new IndexOutOfBoundsException();
		int track = 0;



		Node v = new Node();
		Node u = head;

		Node tmpNode = new Node();
		tmpNode.x = x;
		tmpNode.next = null;

		while( u != null && track < i ){
			v = u;
			u = u.next;
			track++;
		}

		if(i == 0){ // empty case first case
			head = tmpNode;
			tmpNode.next = u;
		}
		else{
			v.next = tmpNode;
			tmpNode.next = u;
		}
		if(i == n)
			tail = tmpNode;
		n++;
	}

	public T remove(int i) {
		// TODO: Implement this
		if (i < 0 || i > n - 1) throw new IndexOutOfBoundsException();

		if(n == 0) return null;
		int track = 0;

		Node v = new Node();
		Node u = head;
		while( u != null && track != i){
			v = u;
			u = u.next;
			track++;
		}
		if(track == 0){
			head = u.next;
		}
		else{
			v.next = u.next;
			if (track == n-1)
				tail = v;
		}
		--n;
		return u.x;
	}


	public void reverse() {
		// TODO: Implement this
		Node u = head;
		Node v = null;
		Node next = null;
		tail = u;
		while (u != null){
            next = u.next;
            u.next = v;
            v = u;
            u = next;
        }
        head = v;
}

	public Iterator<T> iterator() {
		class SLIterator implements Iterator<T> {
			protected Node p;

			public SLIterator() {
				p = head;
			}
			public boolean hasNext() {
				return p != null;
			}
			public T next() {
				T x = p.x;
				p = p.next;
				return x;
			}
			public void remove() {
				throw new UnsupportedOperationException();
			}
		}
		return new SLIterator();
	}

	public int size() {
		return n;
	}

	public boolean add(T x) {
		Node u = new Node();
		u.x = x;
		if (n == 0) {
			head = u;
		} else {
			tail.next = u;
		}
		tail = u;
		n++;
		return true;
	}

	public boolean offer(T x) {
		return add(x);
	}

	public T peek() {
		if (n == 0) return null;
		return head.x;
	}

	public T element() {
		if (n == 0) throw new NoSuchElementException();
		return head.x;
	}

	public T poll() {
		if (n == 0)
			return null;
		T x = head.x;
		head = head.next;
		if (--n == 0)
			tail = null;
		return x;
	}

	/**
	 * Stack push operation - push x onto the head of the list
	 * @param x the element to push onto the stack
	 * @return x
	 */
	public T push(T x) {
		Node u = new Node();
		u.x = x;
		u.next = head;
		head = u;
		if (n == 0)
			tail = u;
		n++;
		return x;
	}

	protected void deleteNext(Node u) {
		if (u.next == tail)
			tail = u;
		u.next = u.next.next;
	}

	protected void addAfter(Node u, Node v) {
		v = u.next.next;
		u.next = v;
		if (u == tail)
			tail = v;
	}

	protected Node getNode(int i) {
		Node u = head;
		for (int j = 0; j < i; j++)
			u = u.next;
		return u;
	}

	/**
	 * Stack pop operation - pop off the head of the list
	 * @return the element popped off
	 */
	public T remove() {
		if (n == 0)	return null;
		T x = head.x;
		head = head.next;
		if (--n == 0) tail = null;
		return x;
	}

	public T pop() {
		if (n == 0)	return null;
		T x = head.x;
		head = head.next;
		if (--n == 0) tail = null;
		return x;
	}


	public static void main(String[] args) {
		/*
			//System.out.println("teri maa di fuddi");
			SLList<Integer> bakchod = new SLList<> ();
			System.out.println("teri maa di fuddi we are ADDDINGGG");
			bakchod.add(0,5);
			bakchod.add(1,10);
			bakchod.add(2,15);
			bakchod.add(3,29);
			bakchod.add(4,30);
			bakchod.add(5,35);

System.out.println("What is my HEAD");
System.out.println(bakchod.head.x);
System.out.println("===========TAIL");
System.out.println(bakchod.tail.x);


			System.out.println("\nteri maa di fuddi we are using GET function\n");
			for(int i=0; i< bakchod.size() ; i++)
				System.out.println(bakchod.get(i));

		  System.out.println("REMOVING at POS 3\n");
			bakchod.remove(3);

			System.out.println("Printing after removing element using GET function\n");
			for(int i=0; i< bakchod.size() ; i++)
				System.out.println(bakchod.get(i));

			System.out.println("setting the  3rd and 5th element element\n");
			bakchod.set(2,50);
			bakchod.set(4,60);

				for(int i=0; i< bakchod.size() ; i++)
					System.out.println(bakchod.get(i));

			System.out.println("Reversing the order\n");
				bakchod.reverse();
			for(int i=0; i< bakchod.size() ; i++)
					System.out.println(bakchod.get(i));

					System.out.println("What is my HEAD");
					System.out.println(bakchod.head.x);
					System.out.println("===========TAIL");
					System.out.println(bakchod.tail.x);

System.out.println("remove all");
					for(int i=0; bakchod.size() !=0 ; )
						System.out.println(bakchod.remove(i));

*/


	}
}
