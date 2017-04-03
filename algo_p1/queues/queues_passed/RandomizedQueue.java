import java.util.Iterator;
import edu.princeton.cs.algs4.StdRandom;
import java.util.NoSuchElementException;


public class RandomizedQueue<Item> implements Iterable<Item> {
    private Item[] queue;
    private int length = 1000;
    private int head, tail;
    private int currSize = 0;
    public RandomizedQueue() {
        queue = (Item[]) new Object[length];
        head = 0;
        tail = 0;
    }
    public boolean isEmpty() {
        return currSize == 0;
    }

    public int size() {
        /*
        if (head < tail) return tail - head;
        else if (head > tail) return length - head + tail;
        else if (head == tail) {
            if (head == 0) return 0;
            else return length;
        }
        */
        return currSize;
    }

    private void resize() {
        Item[] newData = (Item[]) new Object[length];
        int i = head, j = 0;
        if (head < tail) {
            for (; i <= tail; ++i, ++j) {
                newData[j] = queue[i];
            }
        }
        else {
            int oldLength = length / 2;
            while (i < oldLength) {
                newData[j] = queue[i];
                ++i;
                ++j;
            }
            i = 0;
            while (i <= tail) {
                newData[j] = queue[i];
                ++i;
                ++j;
            }
        }
        head = 0;
        tail = j;
        queue = newData;
    }

    public void enqueue(Item item) {
        if (item == null) throw new NullPointerException();
        if (currSize <= length) {
            queue[tail] = item;
            if (tail < length - 1) ++tail;
            else if (head != 0) tail = 0;
            else {
                // resize
                length = length * 2;
                resize();
            }
            ++currSize;
        }
    }

    public Item dequeue() {
        if (isEmpty()) throw new NoSuchElementException();
        Item item = queue[head];
        queue[head] = null;
        if (head < length - 1) ++head;
        else head = 0;
        --currSize;
        return item;

    }

    public Item sample() {
        int index = 0;
        if (isEmpty()) throw new NoSuchElementException();
        if (head < tail) {
            index = StdRandom.uniform(head, tail);
        } else {
            if (StdRandom.uniform(0, 2) == 0) {
                index = StdRandom.uniform(0, tail + 1);
            } else {
                index = StdRandom.uniform(head, length);
            }
        }
        return queue[index];

    }

    public Iterator<Item> iterator() {
        return new RandomizedQueueIterator();
    }

    private class RandomizedQueueIterator implements Iterator<Item> {
        private int currHead = head;
        public boolean hasNext() {
            return queue[currHead] != null;
        }

        public Item next() {
            Item item = queue[currHead];
            if (item == null) throw new NoSuchElementException();
            if (currHead < length - 1) {
                ++currHead;
            }
            else currHead = 0;
            return item;
            

        }

        public void remove() {
            throw new UnsupportedOperationException();
        }
    }

    public static void main(String[] args) {
    }




}
