public class TaskDouble {
    public static void main(String[] args) {
        DoublyLinkedList<Double> l;
        l = new DoublyLinkedList<>();
        for(String a : args) {
            l.append( Double.parseDouble(a) );
        }
        double prod = 1.0;
        DoublyLinkedList<Double>.Node a, b;
        for(a = l.getFirst(),
            b = l.getLast();
            a != null;
            a = a.next,
            b = b.prev) {
            prod *= a.data + b.data;
        }
        System.out.println(prod);
    }
}


// class EndsIterator<T> implements Iterable, java.util.Iterator {
//     DoublyLinkedList<T>.Node a, b;
//     public EndsIterator(DoublyLinkedList<T> l) {
//         a = l.getFirst();
//         b = l.getLast();
//     }
// 
//     public T[] next() {
//         T[] result = {a.data, b.data};
//         a = (DoublyLinkedList<T>.Node) a.next;
//         b = (DoublyLinkedList<T>.Node) b.prev;
//         return result;
//     }
// 
//     public boolean hasNext() {
//         assert((a == null) == (b == null));
//         return a != null;
//     }
// 
//     public EndsIterator iterator() {
//         return this;
//     }
// }
