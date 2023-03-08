#include <iostream>
using namespace std;

class Vec
{
private:
    int _size;
    int _cap;
    int* arr;

public:
    Vec()
    {
        _size = 0;
        _cap = 10;
        arr = new int[_cap];
    }

    void insert(int n, int j)
    {

      if ( _size + 1 > _cap )
        {
            _cap *= 2; //doubling capacity
            reserve(_cap);
        }
      
        for (int i = _size - 1; i >= n; i--)
        {
            arr[i + 1] = arr[i];
        }
        arr[n] = j;
        _size++;
    }

    void reserve(int new_cap)
    {
        if (new_cap > _cap)
        {
            _cap = new_cap;
            int* tmp = new int[_cap];
            for (int i = 0; i < _size; i++)
            {
                tmp[i] = arr[i];
            }
            delete[] arr;
            arr = tmp;
        }
    }

    void push_back(int x)
    {
        if (_size == _cap)
        {
            _cap *= 2;
            reserve(_cap);
        }
        arr[_size++] = x;
    }

    void pop()
    {
        if (_size > 0)
            _size--;
    }

    void remove ( int index ){
      int didskip = 0;
      int *tmp = new int[_cap];
      for ( int i = 0; i < _size; i++ ){
          if(i != index){
            tmp[i-didskip] = arr[i]; 
            }

        if( i == index )
          didskip++;
        }
      
      delete[]arr;
      arr = tmp;
      _size--;
      }

    int& at(int idx)
    {
        if (idx >= _size || idx < 0)
        {
            throw "[Vector] Index out of bound!";
        }
        return arr[idx];
    }

    int& operator[](int idx)
    {
        if (idx >= _size || idx < 0)
        {
            throw "[Vector] Index out of bound!";
        }
        return arr[idx];
    }

    int get_size() const
    {
        return _size;
    }

    int get_capacity() const
    {
        return _cap;
    }
    //to get pointer array
    int* get_arr() const
    {
        return arr;
    }
    //to print the array
    void get_array(){
      cout << "[ ";
      for ( int i = 0; i < _size - 1; i++ ){
        cout << arr[i] << ", ";
      }
      cout << arr[_size-1] << " ";
      cout << "] <-- Get Array" << endl;
    }

    void index_of( int num ){
      bool flag = false;
      cout<<"Index of "<< num << " in the vector is ";
      
      for( int i = 0; i < _size; i++ ){
        if ( arr[i] == num ){
          flag = true;
          cout << i << " ";
        }
       }
      if( flag == false )
        cout << "Not found" << endl;
    cout << endl;
      
    }

    bool operator<(const Vec& other) const
    {
        if (_size != other._size)
        {
            return _size < other._size;
        }
        for (int i = 0; i < _size; i++)
        {
            if (arr[i] < other.arr[i])
            {
                return true;
            }
            else if (arr[i] > other.arr[i])
            {
                return false;
            }
        }
        return false;
    }

    bool operator>(const Vec& other) const
    {
        if (_size != other._size)
        {
            return _size > other._size;
        }
        for (int i = 0; i < _size; i++)
        {
            if (arr[i] > other.arr[i])
            {
                return true;
            }
            else if (arr[i] < other.arr[i])
            {
                return false;
            }
        }
        return false;
    }

    bool operator<=(const Vec& other) const
    {
        return !(*this > other);
    }

    bool operator>=(const Vec& other) const
    {
        return !(*this < other);
    }

    bool operator==(const Vec& other) const
    {
        if (_size != other._size)
        {
            return false;
        }
        for (int i = 0; i < _size; i++)
        {
            if (arr[i] != other.arr[i])
            {
                return false;
            }
        }
        return true;
    }

    bool operator!=(const Vec& other) const
    {
        return !(*this == other);
    }

  Vec operator+(const Vec& other){
    Vec result;
    int size;
    
    if(_cap > other._cap){
      result._cap = _cap;
    }
    else {
      result._cap = other._cap;
    }
  
    delete[] result.arr;
    int *tmp = new int[result._cap];
    result.arr = tmp;
  
    if(_size > other._size){
      size = _size;
    }else{
      size = other._size;
    }
    
    for( int i = 0; i <= size; i++){
      result.push_back(arr[i] + other.arr[i]);
    }
    
    return result;
}

    

    ~Vec()
    {
        delete[] arr;
        cout<<"destructor called \n";
    }
};

ostream& operator<<(ostream& os, Vec& v)
{
    os << "[ ";
    for (int i = 0; i < v.get_size() - 1; i++)
    {
        os << v.get_arr()[i] << ", ";
    }
    os << v.get_arr()[v.get_size() - 1] << " ]";
    return os;
}

int main()
{
  //Vector class
  Vec v;
  
  //Push Back
  v.push_back(0);
  v.push_back(9);
  v.push_back(9);
  v.push_back(9);
  v.push_back(12);
  
  //Insert
  v.insert(1, 7);
  
  // [] operator
  v[3] = 5; //setting the 4th number to 5 using []
  cout << v[3]<<" <- 4th element changed using [] " << endl;
  
  // .at 
  v.at(3) = 787; //again changing using .at
  cout << v <<" <- Again changed using .at"<< endl;
  
  //pop
  v.pop();
  cout<<v<< " <-- After popping the vector "  <<endl;
  cout << v.get_capacity()<<" <-- Capacity " << endl;
  
  //reserve
  v.reserve(30);
  cout << v.get_capacity()<<" <-- Capacity after using reserve " << endl;
  cout << v << endl; 
  
  cout << v.get_size()<<" Get Size " << endl; //Get Size
  cout << v.get_capacity() <<" Get Capacity "<< endl; //Get Capacity
  v.get_array();//Get Array
  
  //Another vector for comparison
  Vec c;
  c.push_back(20);
  c.push_back(30);
  c.push_back(40);
  c.push_back(42);
  c.push_back(22);
  
  //Equal
  if(c == v){
    cout<< c <<" and "<< v << " are Equal " <<endl;
  } else {
    cout<< c <<" and "<< v << " are not Equal " <<endl;
  }
  
  //Greater than
  if(c > v){
    cout<< c <<" is greater than "<< v <<endl;
  } else {
     cout<< c <<" is not greater than "<< v <<endl;
  }
  
  //Less than
  if(c < v){
    cout<< c <<" is less than "<< v <<endl;
  } else {
     cout<< c <<" is not less than "<< v <<endl;
  }
  
  //Greater or equal than
  if(c >= v){
    cout<< c <<" is greater or equal than "<< v <<endl;
  } else {
     cout<< c <<" is not greater or equal than "<< v <<endl;
  }
  
  //Less or equal than
  if(c <= v){
    cout<< c <<" is less or equal than "<< v <<endl;
  } else {
     cout<< c <<" is not less or equal than "<< v <<endl;
  }

  //Addition
  Vec h = v+c;
  cout << h <<" <-- New Vector after addition"<<"\n";
  
  //Remove
  h.remove(2);
  cout<<h<<" after remove "<<"\n";
  
  //Index Of
  h.index_of(12);
  
  //Insert
  h.insert(1,87);
  cout<<h<<" Inserting 87 in vector \n";
  
  return 0;
}