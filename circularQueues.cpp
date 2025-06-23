/**
 * @mainpage Documentation circular Queues
 * 
 * @section Introduction
 * this project from structur data 
 * this project use structur data queues,implements circular arrays.
 * 
 * @section Operations
 * - en queue for insert elements into queues
 * - de queue for delete elements from queues
 * - show data/display
 * 
 * @section How to use 
 * 1. Insert 
 * 2. Delete
 * 3. Display
 * 4. Exit
 * 
 * @author yProfil
 * - Nama  :Rangga Fadhilah Akbar
 * - Nim   :20240140211
 * - Kelas :E
 * @brief 
 * @version 0.1
 * @date 2025-06-23
 * 
 * @copyright Gibran@umy.ac.id (c) 2025
 * 
 */
 
#include <iostream>
using namespace std;
/**
 * @class Queues
 * @brief This class is for operation queues
 * 
 */
class Queues{
private:
    int FRONT;/// private variable front for indicate the frist element
    int REAR ;/// private variable rear to for indicate the last element
    int max =5;/// private variable max to for maximum capasity of element
    int queues_array[5];///private variable queue_array for store element
public:
/**
 * @brief Construct a new Queues object
 * set default queues null
 * with front = -1 and rear =-1
 */
    Queues() {
        FRONT = -1;
        REAR = -1;
    }
    /**
     * @brief method for entering data into a queues
     * 
     * 
     */
    void insert(){
        int num;
        cout <<"enter a number: ";
        cin >> num;
        cout << endl;

        // cek apakah antrian penuh
        if ((FRONT == 0 && REAR == max -1) || (FRONT == REAR +1)){
            cout << "\nQueue overflow\n";
            return;
        } 
        // cek apakah antrian kosong
        if (FRONT == -1){
            FRONT =0;
            FRONT=0;
        }
        else{
            // jika REAR berada di posisi terakhir array, kembali ke awal array
            if (REAR == max -1)
            REAR =0;
            else 
            REAR = REAR + 1;
        }
        queues_array [REAR] =num;
    }
void remove (){
    //cek apakah antrian kosong 
    if (FRONT== -1){
        cout << "Queue underflow\n";
        return;
    } 
    cout << "\n The element delected from the queue is:" << queues_array[FRONT] << "\n";

    // cek jika antrian hanya memiliki 1 elemen
    if (FRONT== REAR){
        FRONT= -1;
        REAR = -1;
    }
    else{
        // jika element yg di hapus berada diposisi terakhir array, kembali ke awal array
        if (FRONT == max -1)
            FRONT = 0;
        else
        FRONT - FRONT + 1;
    }
}
void display(){
    int FRONT_position = FRONT;
    int REAR_position = REAR;

    //cek apakah antrian kosong
    if (FRONT == -1){
        cout << "Queue is Empty\n";
        return;
    }
    cout << "\nElements is the queue are ...\n";

    // jika front_position <= Rear_position, iterasi dari FRONT hingga REAR 
    if (FRONT_position <= REAR_position){
        while (FRONT_position <= REAR_position){
            cout << queues_array[FRONT_position] << "  ";
            FRONT_position++;
        }
        cout << endl;
    }
    else {
        // jika  front_position > Rear_position, iterasi dari FRONT hingga akhir array
    while (FRONT_position <= max - 1){
        cout << queues_array[FRONT_position] << "  ";
        FRONT_position++;
    }
    FRONT_position =0;

    // literasi dari awal array hingga REAR
    while (FRONT_position <= REAR_position){
        cout << queues_array [FRONT_position] << "  ";
        FRONT_position++;
    }
    cout << endl;
        }
    }
};
int main(){
    Queues q;
    char ch;

    while (true)
    {
        try 
    {
        cout << "menu" << endl;
        cout << "1.implement insert operation" << endl;
        cout << "2.implement delete operation" << endl;
        cout << "3.Display values" << endl;
        cout << "4.exit" << endl;
        cout << "Enter your Choice (1-4):";
        cin >> ch;
        cout << endl;

        switch (ch)
        {
        case '1':
        {
            q.insert();
            break;
        }
        case '2':
        {
            q.remove();
            break;
        }
        case '3':
        {
            q.display();
            break;
        }
        case '4':
        {
            return 0;
        }
        default:
        {
            cout << "invalid option!!" << endl;
            break;
        }
        }
    }
    catch (exception &e)
    {
        cout << "check for the values entered." << endl;
    }
    
    }
}