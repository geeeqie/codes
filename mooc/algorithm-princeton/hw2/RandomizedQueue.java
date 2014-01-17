import java.util.Iterator;
import java.util.NoSuchElementException;

public class RandomizedQueue<Item> implements Iterable<Item> {
    private Item[] array;
    private int size;

    // construct an empty randomized queue
    public RandomizedQueue() {
        array = (Item[]) new Object[1];
        size = 0;
    }

    // is the queue empty?
    public boolean isEmpty() {
        return (size == 0);
    }

    // return the number of items on the queue
    public int size() {
        return size;
    }

    // add the item
    public void enqueue(Item item) {
        if (item == null) throw new NullPointerException();

        if (array.length <= size) {
            Item[] arraynew = (Item[]) new Object[array.length*2];
            for (int i = 0; i < size; i++) {
                arraynew[i] = array[i];
            }
            array = arraynew;
        }
        array[size] = item;
        size++;
    }

    // delete and return a random item
    public Item dequeue() {
        if (isEmpty()) throw new NoSuchElementException();
        int i = StdRandom.uniform(size);
        Item item = array[i];
        size--;
        array[i] = array[size];
        array[size] = null;
        if (size < array.length/4) {
            Item[] arraynew = (Item[]) new Object[array.length/2];
            for (int j = 0; j < size; j++) {
                arraynew[j] = array[j];
            }
            array = arraynew;
        }
        return item;
    }

    // return (but do not delete) a random item
    public Item sample() {
        if (isEmpty()) throw new NoSuchElementException();
        int i = StdRandom.uniform(size);
        return array[i];
    }

    // return an independent iterator over items in random order
    public Iterator<Item> iterator() {
        return new RandomArrayIterator();
    }
    private class RandomArrayIterator implements Iterator<Item> {
        private Item[] rarray;
        private int pos;
        public RandomArrayIterator()
        {
            rarray = (Item[]) new Object[size];
            for (int i = 0; i < size; i++) {
                rarray[i] = array[i];
            }
            StdRandom.shuffle(rarray);
            pos = 0;
        }
        public boolean hasNext() {
            return pos < size;
        }
        public Item next()
        {
            if (!hasNext()) throw new NoSuchElementException();
            return rarray[pos++];
        }
        public void remove()
        {
            throw new UnsupportedOperationException();
        }
    }
}
