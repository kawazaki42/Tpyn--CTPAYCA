public class DoublyLinkedList<T> extends SinglyLinkedList<T> {
    public class Node extends SinglyLinkedList<T>.Node {
        protected Node next;
        protected Node prev;

        public Node(T data, Node next, Node prev) {
            super(data, next);
            this.prev = prev;
        }
    }

    // @Override
    protected Node first, last;

    @Override
    public Node getFirst() {
        return first;
    }

    @Override
    public Node getLast() {
        return last;
    }

    @Override
    public void append(T newData) {
        Node newNode = new Node(newData, null, last);
        
        // last.data;
        // last.prev;
        if(last != null)
            last.next = newNode;
        
        last = newNode;
        
        if(first == null) {
            first = last;
        }
    }

    // Never try that at home, kids!
//     @Override
//     public void append(T newData) {
//         // Node<T> oldLast = (DoublyLinkedList<T>.Node)last;
//         Node oldLast = null;
//         if(last != null) {
//             assert last.next == null;
//             oldLast = new Node(last.data, null, last.prev);
//         }
//         super.append(newData);
//         last = super.last;
// 
//         if(oldLast != null) {
//             // oldLast.data;
//             // oldLast.prev;
//             oldLast.next = last;
//         }
// 
//         // last.data;
//         last.next = null;
//         last.prev = oldLast;  // nullable
//     }
}
