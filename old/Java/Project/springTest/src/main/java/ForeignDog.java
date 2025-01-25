public class ForeignDog implements IPet {

    String name;
    String color;

    public String getName() {
        return name;
    }

    public void setName(String name) {
        this.name = name;
    }

    public String getColor() {
        return color;
    }

    public void setColor(String color) {
        this.color = color;
    }

    @Override
    public void eat() {

        System.out.println(" dog" +name+" eat meat");
    }

    @Override
    public void sleep() {

        System.out.println(" dog "+ name+ " alway sleep");

    }
}
