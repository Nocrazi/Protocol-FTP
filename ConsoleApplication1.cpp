// ConsoleApplication1.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <list>
#include <bitset>
#include <math.h>

using namespace std;

long convertCharsToLongMsb(char* str,size_t size)
{
    long l = 0;
    size_t step = 8;
    
    for (int i = 0; i < size; ++i)
    {
        size_t countStep = (size - i - 1);
        size_t offset = step * countStep;
        l |= (static_cast<long>(str[i]) & 255) << offset;
    }

    return l;

}

char* convertLongToCharsMsb(long value, size_t size)
{
    char *str = new char[size + 1];
    str[size] = '\0';
    size_t step = 8;

    for (int i = 0; i < size; ++i)
    {
        size_t countStep = (size - i - 1);
        size_t offset = step * countStep;
        long l = value >> offset;
        str[i] = static_cast<char>(l);
    }

    return str;

}


long convertCharsToLongLsb(char* str, size_t size)
{
    long l = 0;
    size_t step = 8;

    for (int i = size - 1; i >= 0; --i)
    {
        size_t offset = step * i;
        l |= (static_cast<long>(str[i]) & 255) << offset;
    }

    return l;

}


char* convertLongToCharsLsb(long value, size_t size)
{
    char* str = new char[size + 1];
    str[size] = '\0';
    size_t step = 8;
    long range = 255;
    cout << bitset<32>(value).to_string() << endl;


    for (int i = 0; i < size; ++i)
    {
        size_t offset = step * i;
        long l = value & (range << offset);
        l = l >> offset;
        str[i] = static_cast<char>(l);
    }

    return str;

}



class MyClass1
{
public:

    template<typename T>
    void func1(T* data)
    {

    }
};

class MyClass2 : public MyClass1
{
public:

    template<typename T>
    void func1(T* data)
    {
        cout << "int" << endl;
    }
};

int main()
{
    ifstream file;
    file.open("E:\\Разработка аудиоплеера\\Музыка\\vocSong1.voc", ios::binary | ios::beg);
    char *str = new char[100];
    file.read(str, 40);
    //advance(str, 20);
    cout << str << endl;
    long value = convertCharsToLongLsb(str, 2);
    cout << value << endl;
    cout << convertLongToCharsLsb(value, 2) << endl;

    //advance(str, 2);
    //cout << convertChars(str, 2) << endl;
    //advance(str, 2);
    //cout << convertChars(str, 2) << endl;
    //advance(str, 2);
    //cout << convertChars(str, 4) << endl;
    //advance(str, 4);
    //cout << convertChars(str, 4) << endl;
    //advance(str, 4);
    //cout << convertChars(str, 4) << endl;
    //delete str;

    MyClass2 *mc2 = new MyClass2;
    MyClass1 * mc1 = mc2;
    
    int i = 12;
    mc1->func1(&i);

    //int a = 12;
    //void* p = &a;
    //cout << typeid( decltype(p)).name();

}

