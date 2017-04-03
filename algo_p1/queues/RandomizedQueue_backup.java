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

    private int getValidIndex() {
        int index = 0;
        if (head < tail) {
            index = StdRandom.uniform(head, tail);
        } else {
            if (StdRandom.uniform(0, 2) == 0) {
                index = StdRandom.uniform(0, tail);
            } else {
                index = StdRandom.uniform(head, length);
            }
        }
        return index;
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
        int index = getValidIndex();
        while (queue[index] == null) {
            index = getValidIndex();
        }
        Item item = queue[index];
        queue[index] = null;
        --currSize;
        return item;

    }

    public Item sample() {
        if (isEmpty()) throw new NoSuchElementException();
        int index = getValidIndex();
        while (queue[index] == null) {
            index = getValidIndex();
        } 
        return queue[index];

    }

    public Iterator<Item> iterator() {
        return new RandomizedQueueIterator();
    }

    private class RandomizedQueueIterator implements Iterator<Item> {
        private int[] indexList;
        private int iter = 0;

        public RandomizedQueueIterator() {
            indexList = new int[length];
            for (int i = 0; i < length; ++i) {
                indexList[i] = -1;
            }
            int currHead = head;
            int currTail = tail;
            System.out.println(currHead);
            System.out.println(currTail);
            System.out.println(currSize);
            System.out.println();
            if (currHead < currTail) {
                for (int i = 0; currHead < currTail ; i++, currHead++) {
                    indexList[i] = currHead;
                    System.out.println("currHead: ");
                    System.out.println(currHead);
                    System.out.println("i: ");
                    System.out.println(i);

                }
            } else {
                int i = 0;
                for (; i < currTail; ++i) {
                    indexList[i] = i;
                }
                while (currHead < length) {
                    indexList[i] = currHead;
                    ++currHead;
                }
            }
            System.out.println("unshuffled index: ");
            for (int i = 0; i < currSize; ++i) {
                System.out.println(indexList[i]);
            }
            StdRandom.shuffle(indexList, 0, currSize - 1);
            System.out.println("shuffled index: ");
            for (int i = 0; i < currSize; ++i) {
                System.out.println(indexList[i]);
            }
            System.out.println();
        }
        public boolean hasNext() {
            if (indexList[iter] == -1) return false;
            return queue[indexList[iter]] != null;
        }

        public Item next() {
            if (indexList[iter] == -1) throw new NoSuchElementException();
            Item item = queue[indexList[iter]];
            if (item == null) throw new NoSuchElementException();
            ++iter;
            return item;            
        }

        public void remove() {
            throw new UnsupportedOperationException();
        }
    }

    public static void main(String[] args) {
        RandomizedQueue rq = new RandomizedQueue();
        for (int i = 0; i < 10; ++i) {
            rq.enqueue(i);
        }
        Iterator<Integer> iter = rq.iterator();
        Iterator<Integer> iter2 = rq.iterator();
        while (iter.hasNext()) {
            System.out.println(iter.next());
            System.out.println(iter2.next());
        }

    }




}
