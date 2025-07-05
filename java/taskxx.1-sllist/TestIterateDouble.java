class TestIterateDouble {
    public static void main(String[] args) {
        DoublyLinkedList<Double> l;
        l = new DoublyLinkedList<>();
        for(String a : args) {
            l.append( Double.parseDouble(a) );
        }
        for(double x : l) {
            System.out.println(x);
        }
        // return 0;
    }
}
