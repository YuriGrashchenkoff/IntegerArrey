// IntegerArrey.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include "IntArray.h"

using namespace std;

int main()
{
    int r_m;
    int index;
    int remuve_;
    int aa;
   
    cout << "Enter the length of the array:" << endl;
    cin >> aa;

    try
    {
        IntArray array1(aa);

        for (int i{ 0 }; i < aa; ++i)
            array1[i] = i + 1;

        // Уменьшить размер массива на r_m
        cout << "To which element to reduce the array" << endl;
        cin >> r_m;

        array1.resize(r_m);

        //Вставить 20 после элемента index 
        cout << "After which element to insert the number 20" << endl;
        cin >> index;

        array1.insertBefore(20, index);

        // Удалить элемент с индексом remove 
        cout << "Delete an item with an index" << endl;
        cin >> remuve_;

        array1.remove(remuve_);


        // Добавить 30 и 40 в конце и начале массива
        array1.insertAtEnd(30);
        array1.insertAtBeginning(40);

        for (int i{ 0 }; i < array1.getLength(); ++i)
            std::cout << array1[i] << ' ';
    }
    catch (const char* exception)
    {
        cout << "Exception: " << exception << endl;
    }
      
    std::cout << '\n';

    return 0;
}

// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
