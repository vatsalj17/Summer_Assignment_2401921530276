import java.util.Random;

public class TestCompartment {
    public static void main(String[] args) {
        Compartment[] compartments = new Compartment[10];
        Random random = new Random();

        for (int i = 0; i < 10; i++) {
            int type = random.nextInt(4) + 1;
            if (type == 1) {
                compartments[i] = new Luggage();
            } else if (type == 2) {
                compartments[i] = new Ladies();
            } else if (type == 3) {
                compartments[i] = new General();
            } else {
                compartments[i] = new FirstClass();
            }
        }

        for (int i = 0; i < 10; i++) {
            System.out.println(compartments[i].notice());
        }
    }
}
