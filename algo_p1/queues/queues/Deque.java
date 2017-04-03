import java.util.Iterator;
import java.util.NoSuchElementException;
public class Deque<Item> implements Iterable<Item> {
    private Node first, last;
    private int size = 0;
    
    private class Node {
        private Item item;
        private Node next;
        private Node prev;
    }
    public Deque() {
        first = null;
        last = null;
    }
    public boolean isEmpty() {
        return first == null;
    }

    public int size() {
        return size;
    }

    public void addFirst(Item item) {
        if (item == null) throw new NullPointerException();
        Node oldFirst = first;
        first = new Node();
        first.item = item;
        first.next = oldFirst;
        first.prev = null;
        if (oldFirst != null) oldFirst.prev = first;
        else last = first;
        ++size;
    }

    public void addLast(Item item) {
        if (item == null) throw new NullPointerException();
        Node oldLast = last;
        last = new Node();
        last.item = item;
        last.next = null;
        last.prev = oldLast;
        if (oldLast == null) first = last;
        else    oldLast.next = last;
        ++size;
    }

    public Item removeFirst() {
        if (isEmpty()) throw new NoSuchElementException();
        Item item = first.item;
        first = first.next;
        if (first != null) {
            first.prev = null;
            if (first.next == null) last = first;
        }
        else last = first;
        --size;
        return item;
    }

    public Item removeLast() {
        if (isEmpty()) throw new NoSuchElementException();
        Item item = last.item;
        last = last.prev;
        if (last != null) {
            last.next = null;
            if (last.prev == null) first = last;
        }
        else first = last;
        --size;
        return item;
    }

    public Iterator<Item> iterator() {
        return new DequeIterator();
    }
    private class DequeIterator implements Iterator<Item> {
        private Node curr = first;

        public boolean hasNext() {
            return curr != null;
        }
        public Item next() {
            if (curr == null) throw new NoSuchElementException();
            Item item = curr.item;
            curr = curr.next;
            return item;
        }
        public void remove() {
            throw new UnsupportedOperationException();
        }
    }

    public static void main(String[] args) {
       
    }
}
