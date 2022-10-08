// g++ -std=c++17 lec03.cpp && ./a.out
#include <iostream>

void pp(int& a)
{
    std::cout << &a << " " << a << " " << sizeof(a) << std::endl;
}

template <class T>
class DynamicArray 
{
    T* m_arr;
    size_t m_size;

public:
    DynamicArray(size_t size)
        : m_arr(new T[size])
        , m_size(size)
    {
        std::cout << "Array Constructor\n";
    }

    ~DynamicArray()
    {
        delete[] m_arr;
        std::cout << "Array Destructor\n";
    }

    T get(size_t index) const
    {
        return m_arr[index];
    }

    void set(size_t index, T val)
    {
        m_arr[index] = val;
    }

    void print() const
    {
        for (size_t i = 0; i < m_size; i++)
        {
            std::cout << i << " " << m_arr[i] << std::endl;
        }
    }

    T & operator [](size_t index)
    {
        return m_arr[index];
    }
};

int main(int argc, char* argv[])
{
    DynamicArray<float> myArray(10);

    myArray[3] = 3.14159;
    myArray[2] = 2.78;

    myArray.print();

    return 0;
}