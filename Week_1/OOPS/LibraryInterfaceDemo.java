class LibraryInterfaceDemo {
    public static void main(String[] args) {
        // Test case #1:
        KidUser kid = new KidUser();
        kid.registerAccount(10);
        kid.registerAccount(18);
        kid.requestBook("Kids");
        kid.requestBook("Fiction");

        // Test case #2:
        AdultUser adult = new AdultUser();
        adult.registerAccount(5);
        adult.registerAccount(23);
        adult.requestBook("Kids");
        adult.requestBook("Fiction");
    }
}
