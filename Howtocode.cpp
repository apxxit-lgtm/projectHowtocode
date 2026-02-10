#include<iostream>
#include<string>
#include<iomanip>
using namespace std;

//================= โครงสร้างข้อมูลต่อโต๊ะ =================
struct TableOrder {
    string List[50];
    int Price[50];
    int Amount[50];
    int count = 0;
    int total = 0;
};

TableOrder tables[6];     // โต๊ะ 1-5 ใช้จริง

//================= Global variables =================
string food;
int Num;
int table = 0;
int price[6];
int menu;
int more;
int amount;
int check;

//int grandTotal = 0;       // ยอดรวมทั้งวัน
int useTable[6] = { 0 };  // สถิติการใช้โต๊ะ

//================= prototypes =================
void home();
void employ();
void menuu();
void customer();
int moree();
void selectTable();
void showBill();
void Host();
void summarize();
void checktable();
void checkfood();
void printbill();
void backtohome();

//====================================================

void home() {
    cout << "============================================================\n";
    cout << "||                                                        ||\n";
    cout << "||          >>> RESTAURANT MANAGEMENT SYSTEM <<<          ||\n";
    cout << "||                                                        ||\n";
    cout << "============================================================\n";
    cout << "||                                                        ||\n";
    cout << "||   (1) CUSTOMER                                         ||\n";
    cout << "||   (2) EMPLOYEE                                         ||\n";
    cout << "||   (3) HOST / ADMIN                                     ||\n";
    cout << "||                                                        ||\n";
    cout << "||   (0) EXIT                                             ||\n";
    cout << "||                                                        ||\n";
    cout << "============================================================\n";
    cout << "SELECT OPTION >> ";
    cin >> Num;
}

void backtohome() {
    cout << "\n";
    cout << ">>> [0] Back to Home <<<\n";
    cout << ">>> [9] Change Table <<< ";
    cout << "\nSELECT OPTION >> ";
}



void customer() {
    while (true) {

        if (table == 0) {
            selectTable();
            if (table == 0) {
                cout << endl;
                cout << endl;
                return;
            } // ← ป้องกันเข้าเมนูอาหารโดยไม่เลือกโต๊ะ
        }
        cout << "\n\n\n========================================\n";
        cout << "            ORDER CATEGORIES            \n";
        cout << "========================================\n";
        cout << "[1] RECOMMENDED MENU \n";
        cout << "[2] MAIN COURSES\n";
        cout << "[3] BEVERAGES\n";
        cout << "[4] DESSERTS\n";
        cout << "----------------------------------------\n";
        cout << "[0] HOME        [9] CHANGE TABLE \n";
        cout << "----------------------------------------\n";
        cout << "SELECT MENU >> ";

        cin >> menu;
        menuu();

        if (menu == 0) {
            cout << endl;
            cout << endl;

            return;
        }

        if (menu == 9) {
            selectTable();        // เลือกโต๊ะใหม่
            continue;            // กลับไปที่ customer() ใหม่;
        }

        cout << "Amount : ";
        cin >> amount;

        if (menu >= 1 && menu <= 4) {

            TableOrder& t = tables[table];   // ← ใช้โต๊ะปัจจุบัน

            t.List[t.count] = food;
            t.Price[t.count] = price[menu];
            t.Amount[t.count] = amount;

            t.total += price[menu] * amount;

            cout << " \n";
            cout << ">> Added : " << food << " x" << amount
                << " - " << price[menu] * amount << " Baht <<\n";
            cout << " \n";

            t.count++;
        }
        else {
            cout << "Invalid menu!\n";
        }


        if (menu == 0) return;

        if (menu == 9) {           // ★ เพิ่ม
            selectTable();        // เลือกโต๊ะใหม่
            continue;            // กลับไปที่ customer() ใหม่;
        }

        int result = moree();
        if (result == 0) return; // กลับไป main
    }
}



void selectTable() {
    cout << "\n";
    cout << "\n\n================== SELECT TABLE ==================\n";
    cout << "  1. Table 1\n";
    cout << "  2. Table 2\n";
    cout << "  3. Table 3\n";
    cout << "  4. Table 4\n";
    cout << "  5. Table 5\n";
    cout << "--------------------------------------------------\n";
    cout << "  0. Back to Home\n";
    cout << "--------------------------------------------------\n";
    cout << "CHOOSE YOUR TABLE >> ";
    cin >> table;



    if (table >= 1 && table <= 5) {
        useTable[table]++; //เก็บสถิติว่าโต๊ะนี้ถูกใช้งาน 1 ครั้ง
    }
}


void menuu() {
    int item, size;

    if (menu == 0) return;
    if (menu == 1) {
        cout << "\n\n\n============= RECOMMENDED =============\n";
        cout << " 1) Spicy Tom Yum Goong Soup With Rice   80/85 BTH\n";
        cout << " 2) Mango Sticky Rice                    50/55 BTH\n";
        cout << " 3) Som Tam Thai                         50/60 BTH\n";
        cout << "---------------------------------------\n";
        cout << "Select Item >> ";
        cin >> item;

        if (item == 1) { food = "Spicy Tom Yum Goong Soup With Rice"; cout << "(1) Normal 80  (2) Extra 85 : "; cin >> size; price[menu] = (size == 1) ? 60 : 65; }
        else if (item == 2) { food = "Mango Sticky Rice"; cout << "(1) Normal 50  (2) Extra 55 : "; cin >> size; price[menu] = (size == 1) ? 50 : 55; }
        else if (item == 3) { food = "Som Tam Thai"; cout << "(1) Normal 55  (2) Extra 60 : "; cin >> size; price[menu] = (size == 1) ? 55 : 60; }
        else { cout << "Invalid!\n"; return; }
    }

    // ================= MAIN COURSES =================
    else if (menu == 2) {
        cout << "\n\n\n========== MAIN COURSES ==========\n";
        cout << " 1) Fried Pork With Rice            30/35 BTH\n";
        cout << " 2) Fried Chicken With Rice         30/35 BTH\n";
        cout << " 3) Fried Fish With Rice            45/50 BTH\n";
        cout << "----------------------------------\n";
        cout << "Select Item >> ";
        cin >> item;

        if (item == 1) { food = "Pork Rice"; cout << "(1) Normal 30  (2) Extra 35 : "; cin >> size; price[menu] = (size == 1) ? 30 : 35; }
        else if (item == 2) { food = "Chicken Rice"; cout << "(1) Normal 30  (2) Extra 35 : "; cin >> size; price[menu] = (size == 1) ? 30 : 35; }
        else if (item == 3) { food = "Fried Fish Rice"; cout << "(1) Normal 45  (2) Extra 50 : "; cin >> size; price[menu] = (size == 1) ? 45 : 50; }
        else { cout << "Invalid!\n"; return; }
    }

    // ================= BEVERAGES =================
    else if (menu == 3) {
        cout << "\n\n\n========== BEVERAGES ==========\n";
        cout << " 1) Water          10 BTH\n";
        cout << " 2) Soft Drink     20 BTH\n";
        cout << " 3) Orange Juice   35 BTH\n";
        cout << "--------------------------------\n";
        cout << "Select Item >> ";
        cin >> item;

        if (item == 1) { food = "Water"; price[menu] = 10; }
        else if (item == 2) { food = "Soft Drink"; price[menu] = 20; }
        else if (item == 3) { food = "Orange Juice"; price[menu] = 35; }
        else { cout << "Invalid!\n"; return; }
    }

    // ================= DESSERTS =================
    else if (menu == 4) {
        cout << "\n\n\n========== DESSERTS ==========\n";
        cout << " 1) Ice Cream   15 BTH \n";
        cout << " 2) Cake        30 BTH \n";
        cout << "-------------------------------\n";
        cout << "Select Item >> ";
        cin >> item;

        if (item == 1) { food = "Ice Cream"; price[menu] = 15; }
        else if (item == 2) { food = "Cake"; price[menu] = 30; }
        else { cout << "Invalid!\n"; return; }
    }
}


int moree() {
    while (true) {
        cout << "More order? (1) yes / (2) no  " << endl;
        backtohome();
        cout << ": "; cin >> more;

        if (more == 1) {
            return 1; // กลับไป main → main เรียก customer() ใหม่เอง
        }
        else if (more == 2) {
            showBill();
            return 0;
        }
        else if (more == 0) {
            return 0; // กลับไป main
        }
        else if (more == 9) {
            selectTable();        // เลือกโต๊ะใหม่
            return 1;            // กลับไปที่ customer() ใหม่;
        }
        else {
            cout << "Invalid!! please choose again" << endl;
        }
    }
}

void showBill() {

    TableOrder& t = tables[table];

    cout << "\n----------- BILL SUMMARY -----------\n";
    cout << "Table : " << table << endl;

    for (int i = 0; i < t.count; i++) {
        cout << i + 1 << ". "
            << t.List[i] << " x"
            << t.Amount[i] << " = "
            << t.Price[i] * t.Amount[i]
            << " Baht\n";
    }

    cout << "Total Price : "
        << t.total << " Baht\n";
}

//================= EMPLOYEE =================

void employ() {

    while (true) {

        cout << "\n======= TABLE STATUS =======\n";

        for (int i = 1; i <= 5; i++) {

            cout << "Table " << i << " : ";

            if (tables[i].count > 0)
                cout << "[NOT AVAILABLE]\n";
            else
                cout << "[AVAILABLE]\n";
        }

        cout << "Select table \n(Press 0 to Exit) : ";
        cin >> check;

        if (check == 0) return;

        TableOrder& t = tables[check];

        cout << "\n===== TABLE " << check << " =====\n";

        if (t.count == 0) {
            cout << "No orders\n";
        }
        else {
            for (int i = 0; i < t.count; i++) {
                cout << t.List[i]
                    << " x" << t.Amount[i]
                    << " = " << t.Price[i] * t.Amount[i]
                    << endl;
            }

            cout << "Total : " << t.total << endl;
        }

        cout << "1.Clear table\n0.Back\nSelect : ";
        int cmd;
        cin >> cmd;

        if (cmd == 1) {
            tables[check] = TableOrder();
            cout << ">>> CLEARED <<<\n";
        }
    }
}

//================= HOST =================

void Host() {
    int choose;

    while (true) {
        cout << "\n--- HOST MENU ---\n";
        cout << "1.Summary sale\n";
        cout << "2.Check amount use table\n";
        cout << "3.Check amount food sale\n";
        cout << "0.Back\n";
        cin >> choose;

        if (choose == 1) summarize();
        else if (choose == 2) checktable();
        else if (choose == 3) checkfood();
        else if (choose == 0) break;
    }
}

void summarize() {
    checktable();
    checkfood();
    cout << "TOTAL REVENUE : ";
     
}

void checktable() {
    for (int i = 1; i <= 5; i++)
        cout << "Table "
        << i << " used "
        << useTable[i]
        << " times\n";
}

void checkfood() {
    //for (int i = 1; i <= 5; i++) {

      //  TableOrder& t = tables[i];

      //  if (t.count > 0) {
       //     cout << "\nTable " << i << endl;

       //     for (int j = 0; j < t.count; j++)
         //       cout << t.List[j]
          //      << " x" << t.Amount[j]
          //      << endl;
     //   }
    //}
}



//================= MAIN =================

int main() {

    while (true) {

        home();    // home() เป็นคนรับค่า Num แล้ว

        if (cin.fail()) { //ไม่รับค่าอื่นนอกจากint
            cin.clear(); // ปลดล็อค
            cin.ignore(1000, '\n'); //ทิ้งข้อมูล
            cout << "Invalid selection! Try again.\n";
            continue;
        }

        if (Num == 0) {
            cout << "\nExiting program\n";
            return 0;
        }

        else if (Num == 1) {
            table = 0;
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
                    cout << "wrong password\n";
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
                    cout << "wrong password\n";
                }
            }
        }

        else {
            cout << "Invalid selection! Try again.\n";
        }
    }
}

