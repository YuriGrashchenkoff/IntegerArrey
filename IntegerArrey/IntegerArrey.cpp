// IntegerArrey.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include "IntArray.h"

using namespace std;

int main()
{
    int r_m;
    // 
   
     IntArray array(10);
      
    // Fill the array with numbers 1 through 10
    for (int i{ 0 }; i < 10; ++i)
        array[i] = i + 1;

    // Resize the array to 8 elements
    cout << "To which element to reduce the array" << endl;
    cin >> r_m;

    array.resize(r_m);

    // Insert the number 20 before element with index 5
     try
     {
         array.insertBefore(20, 5);
     }
     catch (const char* exception)
     {
         cout << "Exception: " << exception << endl;
     }

    // Remove the element with index 3
     try
     {
         array.remove(3);
     }
     catch (const char* exception)
     {
         cout << "Exception: " << exception << endl;
     }

    // Add 30 and 40 to the end and beginning
    array.insertAtEnd(30);
    array.insertAtBeginning(40);

    // Print out all the numbers
    for (int i{ 0 }; i < array.getLength(); ++i)
        std::cout << array[i] << ' ';

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
