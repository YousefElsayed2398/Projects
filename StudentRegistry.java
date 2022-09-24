

public class StudentRegistry extends Student{

    private Student[] studentData;
    private static int index = 0;
    



    public StudentRegistry(int capacity){
        studentData = new Student[capacity];

    }

    public Student[] getStudentData(){
        return studentData;
    }

    public void  setStudentData(Student[] studentData){
        this.studentData = studentData;
    }

    public int getCapacity(){
        return studentData.length;
    }
    public boolean addStudent(Student newData){
        if(index >= getCapacity()) return false;

        studentData[index] = newData;
        index++;
        

        return true;
    }
    

    public Student removeStudent(int i){
        if(i >= getCapacity()){
            return null;
        }
        Student last = null;
        if(index != 0){
            last = studentData[index - 1];
        }
        else {
            last = studentData[index];
        }
        Student s1 = studentData[i];
        Student[] array = new Student[studentData.length];
        for(int k = 0; k < studentData.length; k++){
            if(studentData[k] == last){
                array[k] = null;
            }
            else if(studentData[k] != s1){
                array[k] = studentData[k];
            }
            else if(studentData[k] == s1){
                array[k] = last;
            }


        }
        studentData = array;
        return s1;
    }



    }


    
    
