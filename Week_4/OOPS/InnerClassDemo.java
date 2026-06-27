public class InnerClassDemo {
    public void display() {
        System.out.println("Outer class display");
    }

    public class Inner {
        public void display() {
            System.out.println("Inner class display");
        }
    }

    public static void main(String[] args) {
        InnerClassDemo outer = new InnerClassDemo();
        outer.display();
        
        InnerClassDemo.Inner inner = outer.new Inner();
        inner.display();
    }
}
