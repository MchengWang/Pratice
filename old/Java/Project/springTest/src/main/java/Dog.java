public class Dog implements IPet {
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

    public void eat()
    {
        System.out.println("Dog:"+name+" eating");

    }

    public void sleep()
    {
        System.out.println("Dog:"+name+" sleeping");
    }

}
