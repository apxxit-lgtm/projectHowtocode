#include<iostream>
#include<string>
#include<iomanip>
using namespace std;

// Global variables
string food;
int Num;
int table = 0;
int price[6];
int menu;
int more;

// เก็บออเดอร์โดยใช้ array
string orderList[50];
int orderPrice[50];
int orderCount = 0;
int totalPrice = 0;

// --- prototypes ---
void home();
void employ();
void menuu();
void customer();
void moree();
void selectTable();
void showBill();
void Host();
void summarize();
void checktable();
void checkfood();
void printbill();

// --- Functions ---

void home() {
    cout << "\n===========================================" << endl;
    cout << "        RESTAURANT MANAGEMENT SYSTEM        " << endl;
    cout << "===========================================" << endl;
    cout << " [1] CUSTOMER    [2] EMPLOYEE    [3] HOST    [0] EXIT" << endl;
    cout << "-------------------------------------------" << endl;
    cout << " Please select : ";
    cin >> Num;
}

void employ() {
    cout << "\n-----------------EMPLOYEE-----------------" << endl;
    cout << "Last Order Summary" << endl;
    cout << "Table : " << (table == 0 ? 0 : table) << endl;

    if (orderCount == 0) {
        cout << "No orders yet" << endl;
    }
    else {
        for (int i = 0; i < orderCount; i++) {
            cout << i + 1 << ". " << orderList[i] << " - " << orderPrice[i] << " Baht" << endl;
        }
        cout << "Total price : " << totalPrice << " Baht" << endl;
    }
}

void menuu() {
    int size;
    if (menu == 1) {
        cout << "size : 1.normal 45 / 2.extra 55 " << endl;
        cout << "select size : "; cin >> size;
        food = "Khao man Gai";
        if (size == 1) price[menu] = 45;
        else price[menu] = 55;
    }
    else if (menu == 2) {
        cout << "size : 1.normal 45 / 2.extra 55 " << endl;
        cout << "select size : "; cin >> size;
        food = "Khao ka Moo";
        if (size == 1) price[menu] = 45;
        else price[menu] = 55;
    }
    else if (menu == 3) { food = "Wagyu A5"; price[menu] = 990; }
    else if (menu == 4) { food = "Salmon Sashimi"; price[menu] = 150; }
    else if (menu == 5) { food = "Tom Yum Kung"; price[menu] = 99; }

    if (menu >= 1 && menu <= 5) {
        orderList[orderCount] = food;
        orderPrice[orderCount] = price[menu];
        orderCount++;
        totalPrice += price[menu];
        cout << ">> Added : " << food << " - " << price[menu] << " Baht" << endl;
    }
    else {
        cout << "Invalid menu!" << endl;
    }
}

void selectTable() {
    while (true) {
        if (table >= 1 && table <= 5) {
            cout << "\n-----------------CUSTOMER-----------------" << endl;
            cout << "Select Table (1-5): " << endl;
            for (int i = 1; i <= 5; i++) cout << i << " : Table " << i << endl;
            cout << "table : ";
            cin >> table;
            break;
        }
        else cout << "Invalid select table!";
    }
}

void customer() {
        /*if (table == 0) {
            selectTable();
            break;
        }*/
    while (true) {
        cout << "\n-----------------MENU-----------------" << endl;
        cout << "1. Khao man Gai (45/55)" << endl;
        cout << "2. Khao ka Moo (45/55)" << endl;
        cout << "3. Wagyu A5 (990)" << endl;
        cout << "4. Salmon Sashimi (150)" << endl;
        cout << "5. Tom Yum Kung (99)" << endl;
        cout << "Select menu : ";
        cin >> menu;

        if (menu >= 1 && menu <= 5) {
            menuu();
            moree();
            break;
        }
        else cout << "Invalid!! please choose again" << endl;
    }
}

void moree() {
    cout << "More order? 1.yes / 2.no : ";
    cin >> more;
    if (more == 1) customer();
    else showBill();
}

void showBill() {
    cout << "\n----------- BILL SUMMARY -----------" << endl;
    cout << "Table : " << table << endl;
    for (int i = 0; i < orderCount; i++) {
        cout << i + 1 << ". " << orderList[i] << " - " << orderPrice[i] << " Baht" << endl;
    }
    cout << "Total Price : " << totalPrice << " Baht" << endl;
    cout << "------------------------------------\n";
}

//underconstruction
void summarize() { cout << "\n[System] Summarizing sales... OK\n"; }
void checktable() { cout << "\n[System] Checking tables... OK\n"; }
void checkfood() { cout << "\n[System] Checking food inventory... OK\n"; }
void printbill() { 
    cout << "-------------------------------" << endl;
    cout << "          benefits             " << endl;
    cout << "          " << "table : " << table << "             " << endl;
    cout << "-------------------------------" << endl;
    cout << "Menu           " << "Qty          " << "Total price" << endl;
    cout << orderList[0] << setw(6) << "___________" << setw(6) << orderPrice[0] << endl;
    cout << orderList[1] << setw(6) << "___________" << setw(6) << orderPrice[1] << endl;


}

void Host() {
    int choose;
    while (true) {
        cout << "\n--- HOST MENU ---" << endl;
        cout << "1.Summary sale" << endl;
        cout << "2.Check amount use table" << endl;
        cout << "3.Check amount food sale" << endl;
        cout << "4.Printbill" << endl;
        cout << "0.Back to Home" << endl;
        cout << "Choose : ";
        cin >> choose;

        if (choose == 1) summarize();
        else if (choose == 2) checktable();
        else if (choose == 3) checkfood();
        else if (choose == 4) printbill();
        else if (choose == 0) break;
        else cout << "Invalid!! please choose again" << endl;
    }
}

int main() {
    while (true) {
        home();

        if (Num == 0) {
            cout << endl;
            cout << endl;
            cout << "++++++++===================+++++++++" << endl;
            cout << "|          Exiting program         |" << endl;
            cout << "++++++++===================+++++++++" << endl;
            break;
        }
        else if (Num == 1) {
            customer();
        }
        else if (Num == 2) {
            string password;
            cout << ">>>>>> LOGIN : EMPLOYEE <<<<<<" << endl;
            while (true) {
                cout << "password : ";
                cin >> password;
                if (password == "555") {
                    employ();
                    break;
                }
                else {
                    cout << "______wrong password!!!______" << endl;
                }
            }
        }
        else if (Num == 3) {
            string password;
            cout << ">>>>>> LOGIN : HOST <<<<<<" << endl;
            while (true) {
                cout << "password : ";
                cin >> password;
                if (password == "header") {
                    Host();
                    break;
                }
                else {
                    cout << "______wrong password!!!______" << endl;
                }
            }
        }
        else {
            cout << " Invalid selection! Try again." << endl;
        }
    }
    return 0;
}
