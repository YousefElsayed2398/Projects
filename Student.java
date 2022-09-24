

public class Student extends ContactInfo{
    private String firstName;
    private String lastName;
    private String id;
    private ContactInfo address;
    public static int currStudent;


    public Student(){
     
    }

    public Student(String firstName, String lastName, String id, ContactInfo address){
        this.firstName = firstName;
        this.lastName = lastName;
        this.id = id;
        this.address = address;
        currStudent++;

    }

    public String getFirstName(){
        return firstName;
    }
    public String getLastName(){
        return lastName;
    }
    public String getId(){
        return id;
    }
    public void setFirstName(String firstName){
        this.firstName = firstName;

    }
    public void setLastName(String lastName){
        this.lastName = lastName;
    }
    public void setId(String id){
        this.id = id;
    }
    public static void reset(){
        currStudent = 0;
    }

    public void setContactInfo(ContactInfo address){
         this.address = address;
    }

    public static int getActiveStudents(){
        return currStudent;
    }

    public ContactInfo getContactInfo(){
        return address;
    }


    @Override
    public String toString(){
        
       return ("First Name: " + firstName + ";" +'\n' + "Last Name: " + lastName + ";" + '\n' + "Id: " + id+ '\n' + ";" ) + " " + address.toString();
        
    }





}