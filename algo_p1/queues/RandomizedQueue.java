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
            for (; i <= tail; ++i, ++j) { // tail has the value just added
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
            ++currSize;
            if (tail < length - 1) ++tail;
            else if (head != 0) tail = 0;
            else {
                // resize
                length = length * 2;
                resize();
            }
        }
    }

    public Item dequeue() {
        if (isEmpty()) throw new NoSuchElementException();
        int index = getValidIndex();
        while (queue[index] == null) {
            System.out.println("is null");
            index = getValidIndex();
        }
        if (index == head) {
            if (head < tail) {
                while (head < tail && queue[head] == null) ++head;
            }
            else {
                while (head < length && queue[head] == null) ++head;
                if (queue[head] == null) {
                    head = 0;
                    while (head < tail && queue[head] == null) ++head;
                }
            }
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
            if (currSize > 0) {
                int currHead = head;
                int currTail = tail;
                if (currHead < currTail) {
                    for (int i = 0; currHead < currTail; i++, currHead++) {
                        indexList[i] = currHead;
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
                StdRandom.shuffle(indexList, 0, currSize - 1);
            }
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
        for (int i = 0; i < 2000; i++) {
            rq.enqueue(i);
        }
        int counter = 0;
        for (int i = 0; i < 50; i++) {
            rq.dequeue();
        }
        Iterator<Integer> iter = rq.iterator();
        while (iter.hasNext()) {
            System.out.println(iter.next());
            ++counter;
        }
        System.out.println("counter: ");
        System.out.println(counter);
    }




}
