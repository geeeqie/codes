import java.util.NoSuchElementException;


public class Subset {
    public static void main(String[] args)
    {
        RandomizedQueue<String> queue = new RandomizedQueue<String>();

        int N = Integer.parseInt(args[0]);

        try {
            while (true)
                queue.enqueue(StdIn.readString());
        }
        catch (NoSuchElementException e) {
            for (int i = 0; i < N; i++) {
                StdOut.println(queue.dequeue());
            }
        }
    }
}
