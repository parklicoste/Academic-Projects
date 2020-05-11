package comp2402a2;

import java.util.AbstractList;
import java.util.Collection;
import java.lang.*;

/**
 * This is a copy of the JCF class ArrayList.  It implements the List
 * interface as a single array a.  Elements are stored at positions
 * a[0],...,a[size()-1].  Doubling/halving is used to resize the array
 * a when necessary.
 * @author morin
 *
 * @param <T> the type of objects stored in the List
 */
public class BlockedList<T> extends AbstractList<T> {
	/**
	 * keeps track of the class of objects we store
	 */
	Factory<T> f;

	/**
	 * The number of elements stored
	 */
	int n;

  int j;

  T[] a;

	/**
	 * The block size
	 */
	int b;

	//ArrayDeque<ArrayDeque<T>> a;


	/**
	 * Constructor
	 * @param t the type of objects that are stored in this list
	 * @param b the block size
	 */
	public BlockedList(Class<T> t, int b) {
		f = new Factory<T>(t);
		n = 0;
		j = 0;
		a = f.newArray(1);
		// TODO: Implement this
		//a = new ArrayDeque<ArrayDeque<T>>((Class<ArrayDeque<T>>)(new ArrayDeque<T>(t)).getClass());
	}

	protected void resize() {
		T[] bd = f.newArray(Math.max(2*n,1));
		for (int k = 0; k < n; k++)
			bd[k] = a[(j+k) % a.length];
		a = bd;
		j = 0;
	}

	public int size() {
		return n;
	}

	public T get(int i) {
		// TODO: Implement this
		if (i < 0 || i > n - 1) throw new IndexOutOfBoundsException();
		return a[(j+i)%a.length];
		/*int numBlock = Math.ceil(i/b);
		return a.get(numblock).get(i%b);// - (numBlock-1)(b) + a[0].size()];*/
	}

	public T set(int i, T x) {
		// TODO: Implement this
		if (i < 0 || i > n - 1) throw new IndexOutOfBoundsException();
		/*T y = a.get(numblock).get(i%b);
		a.get(numblock).set(i%b,x);
		return y;*/
		T y = a[(j+i)%a.length];
		a[(j+i)%a.length] = x;
		return y;
	}

	public void add(int i, T x) {
		// TODO: Implement this
		if (i < 0 || i > n) throw new IndexOutOfBoundsException();
		if (n+1 > a.length) resize();
		if (i < n/2) { // shift a[0],..,a[i-1] left one position
			j = (j == 0) ? a.length - 1 : j - 1; //(j-1)mod a.length
			for (int k = 0; k <= i-1; k++)
				a[(j+k)%a.length] = a[(j+k+1)%a.length];
		} else { // shift a[i],..,a[n-1] right one position
			for (int k = n; k > i; k--)
				a[(j+k)%a.length] = a[(j+k-1)%a.length];
		}
		a[(j+i)%a.length] = x;
		n++;
	}

	public T remove(int i) {
		// TODO: Implement this
		if (i < 0 || i > n - 1) throw new IndexOutOfBoundsException();
		T x = a[(j+i)%a.length];
		if (i < n/2) {  // shift a[0],..,[i-1] right one position
			for (int k = i; k > 0; k--)
				a[(j+k)%a.length] = a[(j+k-1)%a.length];
			j = (j + 1) % a.length;
		} else { // shift a[i+1],..,a[n-1] left one position
			for (int k = i; k < n-1; k++)
				a[(j+k)%a.length] = a[(j+k+1)%a.length];
		}
		n--;
		if (3*n < a.length) resize();
		return x;
}

public void clear(){
	n=0;
	resize();
	}
}
