#include <iostream>
#include <string>
#include "start_to_end.h"
#include "insert_vector.h"
#include "queue_nSTL.h"
#include "List.h"

using namespace std;

void task_one() {
    int size = 4;
    int size_str = 0;

    float* vec = new float[size];

    char* char_v = new char[150];
    cout << endl << "Input word: ";
    cin >> char_v;

    while (char_v[size_str] != '\0') size_str++;
    cout << endl << size_str;
    
    
    cout << endl << "Input float vector: " << endl;
    for (int i = 0; i < size; i++) {
        cout << "Input elem for array < " << i + 1 << " >: ";
        cin >> vec[i];
    }

    Start_to_End<char>* temp_one = new Start_to_End<char>(char_v, size_str);

    temp_one->show_vec_str(size_str);
    temp_one->ste_vec();
    temp_one->show_vec_str(size_str);

   
    Start_to_End<float>* temp = new Start_to_End<float>(vec, size);
    cout << "\nAfter\n\n";
    temp->show_vec();
    temp->ste_vec();
    cout << "\nBefor\n\n";
    temp->show_vec();
}

void task_two() {
    int size_vector = 4;

    cout << endl << "Example with float vector" << endl;
    Vector<float>* I = new Vector<float>(size_vector);
    I->show_vector();
    
    I->insert_element();

    I->show_vector();

    I->~Vector();

    cout << endl << "Example with char* vector" << endl;
    Vector<char>* C = new Vector<char>(120);
    C->show_vector();

    C->insert_element();

    C->show_vector();

    C->~Vector();
}

void test_three() {
    queue_nSTL<float> f;
    while (true) {
        cout << "\n----------------------------------------------------";
        char operation_letter;
        cout << "\n\nInput operation letter \n p - push\n o - pop\n f - front\n b - back\n s - show\n q - exit\n e - empty\n: ";
        cin >> operation_letter;

        switch (operation_letter) {
        case 'p':
            float temp_data;
            cout << "\n--------------------------";
            cout << "\nInput data (format - float): ";
            cin >> temp_data;
            cout << "\n--------------------------";

            f.push(temp_data);

            break;

        case 'o':
            cout << "\n--------------------------";
            cout << "\nDelete data (format - float): " << f.front();
            cout << "\n--------------------------";

            f.pop();

            break;

        case 'f':
            cout << "\n--------------------------";
            cout << "\nFrirst data in queue (format - float): " << f.front();
            cout << "\n--------------------------";

            break;

        case 'b':
            cout << "\n--------------------------";
            cout << "\nLast data in queue (format - float): " << f.back();
            cout << "\n--------------------------";

            break;

        case 'e':
            cout << "\n--------------------------";
            cout << "\nIs empty queue: " << f.empty();
            cout << "\n--------------------------";

            break;

        case 's':
            cout << "\n--------------------------";
            cout << "\nAll queue";
            cout << "\n--------------------------";
            f.show_queue();

            break;
        }
        if (operation_letter == 'q') break;
    }
}

void test_four() {
    List<float>* l = new List<float>();
    l->Insert(23.5, 0);
    l->Insert(23.89, 0);
    l->Insert(23.8923, 0);
    l->Insert(0, 0);
    cout << l->Get_Element(0);
    l->Print_All_List();

}

void switch_task() {
    int temp_index_task = 0;
    cout << "Input number task (1-4): ";
    cin >> temp_index_task;

    switch (temp_index_task)
    {
    case 1:
        task_one();
        break;
    case 2:
        task_two();
        break;
    case 3:
        test_three();
        break;
    case 4:
        test_four();
        break;
    default:
        break;
    }
}

int main()
{
    switch_task();
    return 0;
}
