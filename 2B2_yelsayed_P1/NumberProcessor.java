

public class NumberProcessor {

	public static boolean isSpecial(int input) { // DONE
		if (input == 0 || input < 0) {  // checks if input is less then or = to 0
			return false;
		}
		int[] list = new int[input]; // creates a new list 
		

		
		for (int i = 1; i < input; ++i) { // loops till the input val
			if (input % i == 0) { // chesk if theyre divisble 
				list[i] = i; // if yes then it adds it to the list
			}
		} // {1,2,4}
		int sum = 0;
		for (int k = 0; k < list.length; ++k) { // loops through the list
			sum += list[k]; // adds the val to sum
		}
		if (sum == input) { // if it's the same then it'll be true 
			return true;
		} else {
			return false;
		}
	}

	public static boolean isUniquePrime(int num) { // DONE
		int hold = num;
		String newS;
		boolean prime = false;
		do {
			String numS = String.valueOf(num); // turns it to string 
			newS = numS.substring(1, numS.length()) + numS.charAt(0); // adds the frist inddex to the end
			num = Integer.valueOf(newS); //back to int
			if (isPrime(num)) { //checks if prime
				prime = true; 
			}
		} while (num != hold); //checks the curr hold to the num
		return prime;
	}

	public static boolean isPrime(int num) { // method i made to checks if it's prime
		boolean prime = true;
		for (int i = 2; i < num; ++i) {
			if (num % i == 0) {
				prime = false;
			}
		}
		if (num <= 1) {
			prime = false;
		}
		return prime;
	}

	

	public static boolean isSquareAdditive(int num) {  //DONE
		int res = 0;
		String rest;

		res = (int)Math.pow(num,2); //makes the curr val a int and raises the num to the 2nd 
		rest = String.valueOf(res); // turs the num to a string
		String firsthalf = rest.substring(0, rest.length()/2); // splits the string in half -- first half
		String secondhalf = rest.substring(rest.length() / 2, rest.length()); // splits the string in half -- second half
		int last = Integer.valueOf(firsthalf);  // back to int
		int left = Integer.valueOf(secondhalf); //back to int
		last = last + left;  // adding it back to eacherother
		if(last == num){ // checks if they equal eachother
			return true; // 
		}
		else{
			return false; // returns false if other wise
		}



	}

	public static int masonSequence(int num) { // DONE
		int sum = 1;
		if (num == 1) {  // if it's one them it returns it
			return sum;
		}
		if (num <= 0) { // if it's less the it's 0
			return 0;
		}
		for (int i = 2; i <= num; ++i) {
			sum += i; //  loops from 2 to the curr number 

		}
		return sum;
	}

	
	public static boolean isReversibleSum(int num) { //DONE
		String val = "";
		String kin = String.valueOf(num);


		for(int i = 1; i <= num; i++){ // loops til the numer 
			if(num % i == 0){ // cheks it's divisibility
				if(isPrime(i)){
					val += String.valueOf(i); // turns to a sting
				}
			}
		}

		int sum = 0;

		for(int k = 0; k < val.length(); k++){  // loops through the characters to add to the sum
			sum += Character.getNumericValue(val.charAt(k));   // adds to the sums the chachaters
		}
		int lin = 0;
		for(int w = 0; w < kin.length(); w++){
			lin += Character.getNumericValue(kin.charAt(w)); // does the same as the one above
		}

		if(lin == sum){
            String sin = "";  // empty sting
            for (int i = kin.length()-1;i >= 0; i--) { // loops to cheack the vals 
                sin += Character.getNumericValue(kin.charAt(i));
            }
            int win = Integer.valueOf(sin); // changes it back to an int

            if (win == num){  // chensk if they are the same backwards
                return true;
            }
		}
		return false;

	}

	

	public static boolean isIncremental(int array[]) {
	int keeps = 0;	
	int edcount = 0;
	int loopy = 1;
	boolean tif = false;

	if(array.length == 1) return true; // atuo retrun true if it's 1
	
	for(int k = 0; k < 10; k++){
		int lik = k * (k + 1) / 2; //this is to chek 
		if(array.length == lik){ // 
			tif = true;
		}
	}
	if(tif == false) return false;

	for(int i = 0; i < array.length; i++){ // loops through the array 
		edcount += array[i];
		keeps++;  // adds to the counter 

		if(keeps == loopy){ // chencks if the counter is the same as the loopy vals to know if it need to reset the vals
			if(edcount != array[0]){
				return false;  // returns false
			}
			edcount = 0; // changes the vals and updates loopy
			loopy++;
			keeps = 0;
		}
		
	}
	return true;

}

	
	public static void descendingSort(int[] data) {  //DONE
		int larg;
		int i;
		int k;
		int indx;
		int temp = 0;
		
		for(i = 0; i < data.length; i++){ // loops through the data array 
			indx = i;
			larg = data[i]; //sets the first val with the larg variable
			for( k = i; k < data.length; k++){ // loops to cheks if the vals are larger then the curr val
				if(data[k] > larg){
					larg = data[k]; // if statment to set the vals
					indx = k;
				}
			}
			temp = data[i];
			data[i] = data[indx]; //holds and changes the values of the data
			data[indx] = temp;
		}




	}

	
	public static boolean isPairArray(int array[]) {   //DONE
		boolean pair = false; 
		int i;
		int trac = 0; // uding it to track 

		int sum = 0;
		for (i = 0; i < array.length; ++i) {  // loops through the array  
			for (int k = i; k < array.length; ++k) {  // looping through the overther vals to add them
				sum = array[i] + array[k]; // adding the vals
				if (sum == 18) { //chekcs if it equals 18 ones
					trac++; //the amount of pairs of 18's
				}

			}
		}
		if (trac == 1) { // cheks if theres only 1 on trac so it an print
			pair = true;

		}
		return pair;

	}

	

	public static int[] arrayPattern(int n) {  //DONE
		int[] newArr = new int[n*n];  // n^2
		int sum = 1;
		int holf = n;


		for(int i = newArr.length - 1; i >= 0; i--){  // loops through the array from the end 
			
			if(sum > holf){   // cheks to see if the 
				newArr[i] = 0;  // sets the values of i to 0 if it's less
			}
			else{
				newArr[i] = sum++; // set's the vals at i to sum  
			}
			if(i % n == 0){  // cheks it's divisibility to set and rest it
				holf--;
				sum = 1;
			}
		}
		return newArr;
	}

		

	



	public static boolean isSummative(int array[]) { //DONE
		boolean YoN = false;

		int tot = 0;
		for (int i = 0; i < array.length - 1; ++i) {  // loops through and adds to tot
			tot += array[i];   // adds the values of the elements 
		}
		if (tot == array[array.length - 1] || array.length == 1) { // loops through tot to check if it equals the elemsnt at the nth val
			YoN = true;
		}
		return YoN;  // retrun the result of the boolean
	}

}