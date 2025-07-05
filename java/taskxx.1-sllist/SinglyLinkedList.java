public class SinglyLinkedList<T> implements Iterable<T> {
    public class Node {
        public T data;
        protected Node next;

        public Node(T data, Node next) {
            this.data = data;
            this.next = next;
        }
    }

    protected Node first, last;

    public Node getFirst() {
        return first;
    }

    public Node getLast() {
        return last;
    }

    public void append(T newData) {
        Node newNode = new Node(newData, null);
        if(last != null) {
            last.next = newNode;
            last = newNode;
        } else {
            assert first == null;
            first = last = newNode;
        }
    }

    protected class Iterator implements java.util.Iterator<T> {
        private Node cur;
        public Iterator() {
            cur = first;
        }
        public T next() {
            T result = cur.data;
            cur = cur.next;
            return result;
        }
        public boolean hasNext() {
            return cur != null;
        }
    }

    public Iterator iterator() {
        return new Iterator();
    }
}
