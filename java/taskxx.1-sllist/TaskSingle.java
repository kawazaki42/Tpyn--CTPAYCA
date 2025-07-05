public class TaskSingle {
    public static void main(String[] args) {
        SinglyLinkedList<Double> l;
        l = new SinglyLinkedList<>();
        for(String s : args) {
            l.append( Double.parseDouble(s) );
        }
        double sum = 0.0;
        for(double d : l) {
            // System.out.println(d);
            sum += d*d;
        }
        System.out.println(sum);
    }
}
