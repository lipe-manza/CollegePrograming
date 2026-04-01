
import java.time.LocalDate;
import java.time.Period;

class Person {

    private String name;
    private double weight;
    private double height;
    private String bornDate; // yyyy-MM-dd (ISO)

    public Person(String name, double weight, double height, String bornDate) {
        this.name = name;
        this.weight = weight;
        this.height = height;
        this.bornDate = bornDate;
    }

    public String getName() {
        return this.name;
    }

    public double getWeight() {
        return this.weight;
    }

    public double getHeight() {
        return this.height;
    }

    public String getBornDate() {
        return this.bornDate;
    }

    public int getAge() {
        LocalDate birth = LocalDate.parse(this.bornDate);
        LocalDate today = LocalDate.now();
        return Period.between(birth, today).getYears();
    }
}

public class Agenda {

    private Person[] persons;
    private int count;

    public Agenda() {
        this.persons = new Person[100];
        this.count = 0;
    }

    public void addPerson(Person p) {
        if (this.count < 100) {
            this.persons[this.count] = p;
            this.count++;
        } else {
            System.out.println("Agenda cheia!");
        }
    }

    public Person removePerson(String name) {
        for (int i = 0; i < this.count; i++) {
            if (this.persons[i].getName().equalsIgnoreCase(name)) {

                Person removed = this.persons[i];

                for (int j = i; j < this.count - 1; j++) {
                    this.persons[j] = this.persons[j + 1];
                }

                this.persons[this.count - 1] = null;
                this.count--;

                return removed;
            }
        }

        System.out.println("Nome não encontrado na agenda");
        return null;
    }

    public Person findPersonById(int id) {
        if (id >= 0 && id < count) {
            return this.persons[id];
        }
        System.out.println("ID não encontrado na agenda");
        return null;
    }

    public Person findPersonByName(String name) {
        for (int i = 0; i < this.count; i++) {
            if (this.persons[i].getName().equalsIgnoreCase(name)) {
                return this.persons[i];
            }
        }
        System.out.println("Nome não encontrado na agenda");
        return null;
    }
}
