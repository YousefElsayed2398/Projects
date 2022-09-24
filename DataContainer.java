public interface DataContainer {

	public void add(String element);

	public String remove();
		
	public void clear();

	public String getFirst();

	public String getLast();

	public boolean isEmpty();

	public boolean isFull();
	
	public int getCapacity();

	public int size();

	public void ensureCapacity();

	public String toString();


}
