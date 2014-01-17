import java.util.Iterator;

public class Deque<Item> implements Iterable<Item> {
    private static class Elem<Item> {
        private Item item;
        private Elem<Item> prev;
        private Elem<Item> next;
    };
    private Elem<Item> first;
    private Elem<Item> last;
    private int size;

    // construct an empty deque
    public Deque()
    {
        first = null;
        last = null; 
        size = 0;
    }
    // is the deque empty?
    public boolean isEmpty()
    {
        return (size == 0);
    }

    // return the number of items on the deque
    public int size()
    {
        return size;
    }
    // insert the item at the front
    public void addFirst(Item item)
    {
        if (item == null) throw new NullPointerException();

        Elem<Item> oldfirst = first;
        first = new Elem<Item>();
        first.item = item;
        first.prev = oldfirst;
        first.next = null;
        if (isEmpty()) {
            last = first;
        } else {
            oldfirst.next = first;
        }
        size++;
    }
    // insert the item at the end
    public void addLast(Item item)
    {
        if (item == null) throw new NullPointerException();

        Elem<Item> oldlast = last;
        last = new Elem<Item>();
        last.item = item;
        last.next = oldlast;
        last.prev = null;
        if (isEmpty()) {
            first = last;
        } else {
            oldlast.prev = last;
        }
        size++;
    }
    // delete and return the item at the front
    public Item removeFirst()
    {
        if (isEmpty()) throw new java.util.NoSuchElementException();
        Item item = first.item;

        first = first.prev;
        size--;
        if (isEmpty()) {
            last = null;
        } else {
            first.next.prev = null;
            first.next = null;
        }
        return item;
    }

    // delete and return the item at the end
    public Item removeLast()
    {
        if (isEmpty()) throw new java.util.NoSuchElementException();
        Item item = last.item;
        last = last.next;
        size--;
        if (isEmpty()) {
            first = null;
        } else {
            last.prev.next = null;
            last.prev = null;
        }
        return item;
    }

    // return an iterator over items in order from front to end
    public Iterator<Item> iterator()
    {
        return new ListIterator<Item>(first);
    }

    private class ListIterator<Item> implements Iterator<Item> {
        private Elem<Item> current;

        public ListIterator(Elem<Item> first) {
            current = first;
        }

        public boolean hasNext()  { return current != null; }
        public void remove()      { throw new UnsupportedOperationException();  }

        public Item next() {
            if (!hasNext()) throw new java.util.NoSuchElementException();
            Item item = current.item;
            current = current.prev;
            return item;
        }
    }
}
