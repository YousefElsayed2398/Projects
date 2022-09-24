public class TwoEndsContainer implements DataContainer {
  public String dataArray[];
  public int initialCapacity;


  public TwoEndsContainer(){
      this.initialCapacity = 100;
      this.dataArray = new String[initialCapacity];
  }

  public TwoEndsContainer(int capacity){
      this.initialCapacity = capacity;
      this.dataArray = new String[initialCapacity];
      
  }

  @Override
  public void add(String element) {
      //null,null,null,null....
      
    ensureCapacity();
      for(int i = 0; i < dataArray.length; i++){
          if(dataArray[i] == null){
              dataArray[i] = element;
              break;
          }
      }
      
  }

  
  @Override
  public String remove() {
    String styin = dataArray[0];
    for(int i = 0; i < size() - 1; i++){
      dataArray[i] = dataArray[i + 1];
    }
     return styin;
  }
      


  @Override
  public void clear() {
      String[] tempArr = new String[dataArray.length];
      dataArray = tempArr;
  }
  

  @Override
  public String getLast() {
      return dataArray[size() - 1];
  }

  @Override
  public String getFirst(){
      return dataArray[0];
  }

  @Override
  public boolean isEmpty() {
      if(dataArray[0] == null) return true;
      return false;
  }

  @Override
  public boolean isFull() {
      if(dataArray[dataArray.length - 1] != null) return true;
      return false;
  }

  @Override
  public int size() {
      int add = 0;
      for(int i= 0; i< dataArray.length; i++){
          if(dataArray[i] != null){
              add++;
          }
      }
      return add;
  }

  @Override
  public void ensureCapacity() {
      if(isFull() == true){
          String[] doublArray = new String[dataArray.length * 2];
          for(int i = 0; i < dataArray.length; i++){
              doublArray[i] = dataArray[i];
              
          }
          this.dataArray = doublArray;
      }
      
  }

  @Override
  public int getCapacity() {
      return initialCapacity;
      
  }
  

  @Override
  public String toString(){
      
      String kin = "";

      for(int k = 0; k < size(); k++){
          if(k == size() - 1){
              kin += dataArray[k];
          }
          else{
              kin += dataArray[k] + ", ";
          } 
          
      }
     
      return "[" + kin + "]";
  }

  

}
