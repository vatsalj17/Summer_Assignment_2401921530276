public class Box3d extends Box {
    private double height;

    public Box3d(double length, double breadth, double height) {
        super(length, breadth);
        this.height = height;
    }

    public void setHeight(double height) {
        this.height = height;
    }

    public double getVolume() {
        return length * breadth * height;
    }

    public static void main(String[] args) {
        Box3d myBox = new Box3d(2.0, 3.0, 4.0);
        System.out.println("Area: " + myBox.getArea());
        System.out.println("Volume: " + myBox.getVolume());
        
        myBox.setLength(5.0);
        myBox.setBreadth(6.0);
        myBox.setHeight(7.0);
        System.out.println("New Area: " + myBox.getArea());
        System.out.println("New Volume: " + myBox.getVolume());
    }
}
