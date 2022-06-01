#include <iostream>

using namespace std;

class Vector
{
  protected:
    int *array;
    int size;

  public: 
    Vector() : size(0) { }; //Конструктор по умолчанию

    virtual void Write(int size){
      this->size = size;
      array = new int[size];
      for (int i=0; i < size; i++)
        array[i] = rand() % 20 + 1;
    }

    int &operator[](int j) //перегрузка доступа по индексу[]    
    {
      return array[j];
    }
    Vector& operator = ( Vector &vec ) //перегрузка оператора присваивания
    {
        for (int i = 0; i < vec.size; i++)
        {
            array[i] = vec.array[i];
        }
        return *this;
    }


  ~Vector(){
    delete[] array;
  }
//Перегрузка оператора вывода
friend ostream& operator<< (ostream &out, const Vector &vector);
  
};

ostream& operator<< (ostream &out, const Vector &vec)
{
    out << "Элементы вектора "<< endl;
    for (int i =0; i<vec.size; i++){
      out << vec.array[i] << endl;
    }
    return out; 
}

class SafeVector : public Vector 
{
  private:
    int lower_idx;
    int upper_idx;

  public:
    SafeVector() : lower_idx(1), upper_idx(2) { };
    void Write(int size_){
    size = size_;
    array = new int[size];
    for (int i=0; i < size; i++)
      array[i] = rand() % 20 + 1;
    }

    void ShowVector(int lx, int ux)
  {
    cout << "Вывод элементов, находящихся в интервале от "<< lx << " до " << ux << endl;
    for (int i=lx; i<ux; i++)
      cout << array[i] << endl;
  }
  ~SafeVector() { };
  
};