



public class ContactInfo{
    private String streetNumber; 
    private String unitNumber; 
    private String state; 
    private int zipCode; 
    private String email;

    public ContactInfo(){ 

    }

    public ContactInfo(String streetNumber, String unitNumber, String state, int zipCode, String email){
        this.streetNumber = streetNumber;
        this.unitNumber = unitNumber;
        this.state = state;
        this.zipCode = zipCode;
        this.email = email;

    }

    public void setStreetNumber(String streetNumber){
        this.streetNumber = streetNumber;

    }
    public void setUnitNumber(String unitNumber){
        this.unitNumber = unitNumber;
    }
    public void setState(String state){
        this.state = state;
    }
    public void setZipCode(int zipCode){
        this.zipCode = zipCode;
    }
    public void setEmail(String email){
        this.email = email;
    }
    public String getStreetNumber(){
        return streetNumber;
    }
    public String getUnitNumber(){
        return unitNumber;
    }
    public String getState(){
        return state;
    }
    public int getZipCode(){
        return zipCode;
    }
    public String getEmail(){
        return email;
    }
    public String toString(){

       return ("Street Number: " + streetNumber + ";" + '\n' + "Unit Number: " +  unitNumber + ";" +'\n' +  "State: " +state +";" + '\n'+ "ZipCode: "+ zipCode +";" + '\n'  +  "Email: " + email);
    } 





}

