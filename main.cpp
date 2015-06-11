#include <iostream>
using namespace std;
//setting up the vector class
template<typename T>
class vector{
    
private:
    // 3 private variables, size of vector, capacity of array, and the contents of the vector
    int _size;
    int _capacity;
    T* _space;
    
public:
    //3 constructors for the vectors
    //empty vector
    vector<T>(){
        _capacity=0;
        _size=0;
        _space=0;
    }
    //empty vector but with an initial size
    vector<T>(int size){
        _capacity=size;
        _size=size;
        _space= new T[size];
    }
    //vector with size and specified contents
    vector <T>(int size, const T specified){
        _size=size;
        _capacity=size;
        _space=new T[size];
        for (int i=0; i<size; i++)
            _space[i]=specified;
    }
    //adding data to a vector, therefor increasing size by one
    void pushback(const T v){
        if(_size>=_capacity){
            //double the size of the original array
            int newsize=_size+1;
            //creates a new array
            T *newarray= new T[newsize];
            //copies existing numbers in array
            for (int i=0; i<_size;i++)
                newarray[i]=v[i];
        }
        
        _space[_size++];
    }
    //goes back one data set,
    void popback(){
        _size--;
    }
    //returns the size of the vector
    unsigned const size(){
        return _size;
    }
    //returns the contents of the vector at a certain location/index
    const T at(int location){
        return _space[location];
    }
    //returns true if the vector is empty
    bool const empty(){
        return _size==0;
    }
    //deletes the contents of a vector
    void clear(){
        delete[]_space;
    }
    // swaps the values of the two vectors
    void swap(vector v1){
        int newsize=v1._size;
        int newcapacity=v1._capacity;
          int * newspace=v1._space;
        v1._size=_size;
        v1._capacity=_capacity;
       v1._space=_space;
        _size=newsize;
        _capacity=newcapacity;
        _space=newspace;
        
    }
};

int main(){
    //testing by callign functions
    
    vector<int> intvect();
    vector<string> strvect(5);
    vector<int> doubvect(1, 3);
    vector<int> doubvect1(3, 1);

    doubvect.swap(doubvect1);


    

   
    
    return 0;
    
}

