#include <iostream>
using namespace std;

class Queues{
    int FRONT, REAR, max =5;
    int queues_array[5];
public:
    Queues() {
        FRONT = -1;
        REAR = -1;
    }

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
    int REAR_positionn = REAR;

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