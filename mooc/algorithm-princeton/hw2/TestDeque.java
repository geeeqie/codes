import static org.junit.Assert.*;

import org.junit.Test;


public class TestDeque {

	@Test
	public void DequeTest() {
		Deque<Integer> queue = new Deque<Integer>();
		int n = 1024000;
		for (int i = 0; i < n; i++) {
			int j = StdRandom.uniform(4);
			if (j == 0)
				queue.addFirst(i);
			if (j == 1)
				queue.addLast(i);
			if (j == 2 && !queue.isEmpty())
				queue.removeFirst();
			if (j == 3 && !queue.isEmpty())
				queue.removeLast();
		}
//		for (int i = 0; i < n; i++) {
//			assertEquals(queue.removeFirst().intValue(), n-i-1);
//			assertEquals(queue.removeLast().intValue(), n-i-1);
//		}
//		assertEquals(queue.isEmpty(), true);

	}
	@Test
	public void RandomizedQueueTest() {
		RandomizedQueue<Integer> queue = new RandomizedQueue<Integer>();
		int n = 100;
		for (int i = 0; i < n; i++) {
			queue.enqueue(i);
		}
		for (int i = 0; i < n; i++) {
			queue.dequeue();
		}
		assertEquals(queue.isEmpty(), true);

	}
}
