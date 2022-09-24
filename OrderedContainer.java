public class OrderedContainer extends TwoEndsContainer {

    public OrderedContainer() {
        super();
    }

    public OrderedContainer(int capacity) {
        super(capacity);
    }

    @Override
    public String getFirst(){
        return dataArray[size() - 1];

    }

    @Override
    public String getLast(){
        
        return dataArray[0];
    }

    @Override
  public String toString(){
      
      String kin = "";

      for(int k = size() -1; k >= 0; k--){
          if(k == 0){
              kin += dataArray[k];
          }
          else{
              kin += dataArray[k] + ", ";
          } 
          
      }
     
      return "[" + kin + "]";
  }

  @Override
  public String remove(){
      String lik = dataArray[size() -1];
      dataArray[size() - 1] = null;
      return lik;
  }


    @Override
    public void add(String element) {
        super.add(element);
        for (int i = 0; i < size() - 1; i++) {
            for (int k = 0; k < size() - 1; k++) {
                if (dataArray[k+1].compareTo(dataArray[k]) > 0) {
                    String temp = dataArray[k];
                    dataArray[k] = dataArray[k+1];
                    dataArray[k+1] = temp;
                }
            }
        }
    }
}
