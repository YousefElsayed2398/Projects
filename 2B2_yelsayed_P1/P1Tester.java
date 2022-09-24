/** Example of using unit tests for this assignment.  To run them on the command line, make
 * sure that the junit-cs211.jar is in the same directory.  
 * 
 * On Mac/Linux:
 *  javac -cp .:junit-cs211.jar *.java         # compile everything
 *  java -cp .:junit-cs211.jar P1Tester        # run tests
 * 
 * On windows replace colons with semicolons: (: with ;)
 *  demo$ javac -cp .;junit-cs211.jar *.java   # compile everything
 *  demo$ java -cp .;junit-cs211.jar P1Tester  # run tests
 */
import org.junit.*;
import static org.junit.Assert.*;
import java.util.*;
  
public class P1Tester {
  public static void main(String args[]){
    org.junit.runner.JUnitCore.main("P1Tester");
  }
  
  int dataSpecial[] = {9, -12, 6, 496, 625, 0};
  boolean resSpecial[] = {false, false, true, true, false, false};

  void checkIsSpecial(int a) {
	  int n = dataSpecial[a];
	  boolean result = resSpecial[a];
	  String errMsg = String.format("isSpecial(%d) incorrect", n);
	  assertEquals(errMsg, result, NumberProcessor.isSpecial(n));
  }
     
  @Test public void isSpecial_00() { checkIsSpecial(0); }
  @Test public void isSpecial_01() { checkIsSpecial(1); }
  @Test public void isSpecial_02() {checkIsSpecial(2); }
  @Test public void isSpecial_03() { checkIsSpecial(3); }
  @Test public void isSpecial_04() { checkIsSpecial(4); }
  @Test public void isSpecial_05() { checkIsSpecial(5); }

  int numUnique[]= {2,  9, -197,113,1193};
  boolean resUnique[] = {true, false, false, true, true};
  
  void checkIsUniquePrime(int a) {
	  boolean result = resUnique[a];
	  String errMsg = String.format("isUniquePrime(%d) incorrect", numUnique[a]);
	  assertEquals(errMsg, result, NumberProcessor.isUniquePrime(numUnique[a]));
  }

  @Test public void isUniquePrime_00() { checkIsUniquePrime(0); }
  @Test public void isUniquePrime_01() { checkIsUniquePrime(1); }
  @Test public void isUniquePrime_02() { checkIsUniquePrime(2); }
  @Test public void isUniquePrime_03() { checkIsUniquePrime(3); }
  @Test public void isUniquePrime_04() { checkIsUniquePrime(4); }

  
  
  
  int numSequence[]= {2,17,25,0,-13, 100};
  int resSequence[]= {3,   153,    325, 0, 0, 5050};

  void checkMasonSequence(int a) {
	  
	  String errMsg = String.format("incorrect masonSequence(%d)", numSequence[a]);
	  assertEquals(errMsg, resSequence[a], NumberProcessor.masonSequence(numSequence[a]));
  }

  @Test public void MasonSequence_00() { checkMasonSequence(0); }
  @Test public void MasonSequence_01() { checkMasonSequence(1); }
  @Test public void MasonSequence_02() { checkMasonSequence(2); }
  @Test public void MasonSequence_03() { checkMasonSequence(3); }
  @Test public void MasonSequence_04() { checkMasonSequence(4); }
  @Test public void MasonSequence_05() { checkMasonSequence(5); }
  

   

  int [] numSquare= {9,45,10,34,55,999,703,222};
  boolean[] resSquare = {true, true, false, false, true, true, true, false};

  void checkIsSquareAdditive(int a) {
	  String errMsg = String.format("isSquareAdditive(%d) incorrect", numSquare[a]);
	  assertEquals(errMsg, resSquare[a], NumberProcessor.isSquareAdditive(numSquare[a]));
  }
 
  @Test public void IsSquareAdditive_00() { checkIsSquareAdditive(0); }
  @Test public void IsSquareAdditive_01() { checkIsSquareAdditive(1); }
  @Test public void IsSquareAdditive_02() { checkIsSquareAdditive(2); }
  @Test public void IsSquareAdditive_03() { checkIsSquareAdditive(3); }
  @Test public void IsSquareAdditive_04() { checkIsSquareAdditive(4); }
  @Test public void IsSquareAdditive_05() { checkIsSquareAdditive(5); }
  @Test public void IsSquareAdditive_06() { checkIsSquareAdditive(6); }
  

  static final double ERROR = 0.000001;

  int numReverseNum[] = { 202,  1000,  1881, 454, 9, 223};
  boolean resReverseNum[]  = {true, false, true,  true, false, false};
  
  void checkIsReversibleSum(int a) {
	  String errMsg = String.format("isReversibleSum(%d) incorrect", numReverseNum[a]);
	  assertEquals(errMsg, resReverseNum[a], NumberProcessor.isReversibleSum(numReverseNum[a]));
  }
 
  @Test public void IsReversibleSum_00() { checkIsReversibleSum(0); }
  @Test public void IsReversibleSum_01() { checkIsReversibleSum(1); }
  @Test public void IsReversibleSum_02() { checkIsReversibleSum(2); }
  @Test public void IsReversibleSum_03() { checkIsReversibleSum(3); }
  @Test public void IsReversibleSum_04() { checkIsReversibleSum(4); }
  @Test public void IsReversibleSum_05() { checkIsReversibleSum(5); }
 
  
  int resPattern[][]= {{0 , 0 , 0 , 0 , 0 , 1 , 0 , 0 , 0 , 0 , 2 , 1 , 0 , 0 , 0 , 3 , 2 , 1 , 0 , 0 , 4 , 3 , 2 , 1 , 0 , 5 , 4 , 3 , 2 , 1 , 6 , 5 , 4 , 3 , 2 , 1 },{0 , 0 , 1 , 0 , 2 , 1 , 3 , 2 , 1},{1},{0 , 0 , 0 , 1 , 0 , 0 , 2 , 1 , 0 , 3 , 2 , 1 , 4 , 3 , 2 , 1},{0 , 0 , 0 , 0 , 0 , 0 , 1 , 0 , 0 , 0 , 0 , 0 , 2 , 1 , 0 , 0 , 0 , 0 , 3 , 2 , 1 , 0 , 0 , 0 , 4 , 3 , 2 , 1 , 0 , 0 , 5 , 4 , 3 , 2 , 1 , 0 , 6 , 5 , 4 , 3 , 2 , 1 , 7 , 6 , 5 , 4 , 3 , 2 , 1 }};
 int numPattern[] = {6, 3, 1, 4, 7};

  void checkArrayPattern(int a) {
	
	  String errMsg = String.format("arrayPattern(%d) incorrect ", numPattern[a]);
	  assertArrayEquals(errMsg, resPattern[a], NumberProcessor.arrayPattern(numPattern[a]));
  }
	  
  @Test public void arrayPattern_00() { checkArrayPattern(0); }
  @Test public void arrayPattern_01() { checkArrayPattern(1); }
  @Test public void arrayPattern_02() { checkArrayPattern(2); }
  @Test public void arrayPattern_03() { checkArrayPattern(3); }
  @Test public void arrayPattern_04() { checkArrayPattern(4); }
  

  
  int numIncremental[][]= {{4,3,1,1,0,3},{9,9,9},{5,4,1,5},{6,2,4,2,2,2,6},{7,2,5,1,3,3,7,0,0,0},{1,1,0,0,1,1,0,0,0,4},{3},{-6,-2,-4,-2,-2,-2}};
  boolean resIncremental[] = {true, false, false, false, true, false, true, true};


  void checkIsIncremental(int a) {
	  int[] list = numIncremental[a];
	  boolean result = resIncremental[a];
	  String errMsg = String.format("isIncremental incorrect for array %s", Arrays.toString(list));
	  assertEquals(errMsg, result, NumberProcessor.isIncremental(list));
  }
	  
  @Test public void isIncremental_00() { checkIsIncremental(0); }
  @Test public void isIncremental_01() { checkIsIncremental(1); }
  @Test public void isIncremental_02() { checkIsIncremental(2); }
  @Test public void isIncremental_03() { checkIsIncremental(3); }
  @Test public void isIncremental_04() { checkIsIncremental(4); }
  @Test public void isIncremental_05() { checkIsIncremental(5); }
  @Test public void isIncremental_06() { checkIsIncremental(6); }
  @Test public void isIncremental_07() { checkIsIncremental(7); }
  
  
  int numSort[][]= {{4, 7, -4, 19, 0, 9, 0, -15, 10, 1},{4,0,-5,-7},{-4,-10,-1,-9,-8,-6},{1,2,3,4,5,6},{1},{0,0,0,0,0,0,0}};
  int resSort[][]= {{19,10, 9, 7, 4, 1, 0, 0, -4, -15},{4,0,-5,-7},  {-1,-4,-6,-8,-9,-10},{6,5,4,3,2,1},{1},{0,0,0,0,0,0,0}};
  

  void checkSort(int a) {
	  int[] list = numSort[a];
	  int[] result = resSort[a];
	  NumberProcessor.descendingSort(list);
	  String errMsg = String.format("descendingSort incorrect for array %s", Arrays.toString(numSort[a]));
	  assertArrayEquals(errMsg, result, list);
  }
	  
  @Test public void Sort_00() { checkSort(0); } 
  @Test public void Sort_01() { checkSort(1); }
  @Test public void Sort_02() { checkSort(2); }
  @Test public void Sort_03() { checkSort(3); }
  @Test public void Sort_04() { checkSort(4); }
  @Test public void Sort_05() { checkSort(5); }

  int[][] numPair = { {2,17,25,0,-13, 10,0},{18},{18,0,0,0},{14,4,7,8},{12,9,6,9}};
  boolean[] resPair =  { false,false,false,true,false};

  void checkIsPairArray(int a) {
	  String errMsg = String.format("isPairArray incorrect for array %s", Arrays.toString(numPair[a]));
	  assertEquals(errMsg, resPair[a], NumberProcessor.isPairArray(numPair[a]));
  }
	  

  @Test public void isPairArray_00() { checkIsPairArray(0); }
  @Test public void isPairArray_01() { checkIsPairArray(1); }
  @Test public void isPairArray_02() { checkIsPairArray(2); }
  @Test public void isPairArray_03() { checkIsPairArray(3); }

  
  int [][] numSummative= {{1,1,2,4,8,1},{0,0,0,0,0,0},{2,2,4,8,16},{9,5,7,9},{8}};
  
  @Test public void isSummative_01() 
  { assertFalse("isSummative_01 is not correct", NumberProcessor.isSummative(numSummative[0])); }
  @Test public void isSummative_02() 
   { assertTrue("isSummative_02 is not correct", NumberProcessor.isSummative(numSummative[1])); }
  @Test public void isSummative_03() 
 { assertTrue("isSummative_03 is not correct", NumberProcessor.isSummative(numSummative[2])); }
  @Test public void isSummative_04() 
   { assertFalse("isSummative_04 is not correct", NumberProcessor.isSummative(numSummative[3])); }
  @Test public void isSummative_05() 
 { assertTrue("isSummative_05 is not correct", NumberProcessor.isSummative(numSummative[4])); }
 
  
  
  
}