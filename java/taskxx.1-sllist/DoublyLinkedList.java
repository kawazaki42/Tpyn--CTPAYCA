public class DoublyLinkedList<T> extends SinglyLinkedList<T> {
    public class Node extends SinglyLinkedList<T>.Node {
        protected Node prev;

        public Node(T data, Node next, Node prev) {
            super(data, next);
            this.prev = prev;
        }
    }

    // @Override
    protected Node first, last;

    @Override
    public void append(T newData) {
        // Node<T> oldLast = (DoublyLinkedList<T>.Node)last;
        assert(last.next == null);
        Node oldLast = new Node(last.data, null, last.prev);
        super.append(newData);
        last.prev = oldLast;
    }
}
