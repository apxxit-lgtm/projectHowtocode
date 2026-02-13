#include <iostream>
#include <string>
#include <iomanip>
#include <vector> 

using namespace std;

//================= โครงสร้างข้อมูลต่อโต๊ะ =================
struct TableOrder {
    vector<string> List;   // เปลี่ยนเป็น vector
    vector<int> Price;    // เปลี่ยนเป็น vector
    vector<int> Amount;   // เปลี่ยนเป็น vector
    int count = 0;
    int total = 0;
};

TableOrder tables[6];      // โต๊ะ 1-5 ใช้จริง

//================= Global variables =================
string food;
int Num;
int table = 0;
int price[6];
int menu;
int more;
int amount;
int check;

vector<int> useTable(6, 0);

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
void backtohome();

//====================================================

void home() {
    cout << "============================================================" << endl;
    cout << "||                                                        ||" << endl;
    cout << "||          >>> RESTAURANT MANAGEMENT SYSTEM <<<          ||" << endl;
    cout << "||                                                        ||" << endl;
    cout << "============================================================" << endl;
    cout << "||                                                        ||" << endl;
    cout << "||   (1) CUSTOMER                                         ||" << endl;
    cout << "||   (2) EMPLOYEE                                         ||" << endl;
    cout << "||   (3) HOST / ADMIN                                     ||" << endl;
    cout << "||                                                        ||" << endl;
    cout << "||   (0) EXIT                                             ||" << endl;
    cout << "||                                                        ||" << endl;
    cout << "============================================================" << endl;
    cout << "SELECT OPTION >> ";
    cin >> Num;
}

void backtohome() {
    cout << endl;
    cout << ">>> [0] Back to Home <<<" << endl;
    cout << ">>> [9] Change Table <<< " << endl;
    cout << "SELECT OPTION >> " << endl;
}

void customer() {
    while (true) {
        if (table == 0) {
            selectTable();
            if (table == 0) return;
        }
        cout << endl << endl << endl;
        cout << "========================================" << endl;
        cout << "            ORDER CATEGORIES            " << endl;
        cout << "========================================" << endl;
        cout << "[1] RECOMMENDED MENU " << endl;
        cout << "[2] MAIN COURSES" << endl;
        cout << "[3] BEVERAGES" << endl;
        cout << "[4] DESSERTS" << endl;
        cout << "----------------------------------------" << endl;
        cout << "[0] HOME     |   [9] CHANGE TABLE " << endl;
        cout << "----------------------------------------" << endl;
        cout << "SELECT MENU >> ";

        cin >> menu;
        if (menu == 0) return;
        if (menu == 9) {
            selectTable();
            continue;
        }

        menuu();

        cout << "Amount : ";
        cin >> amount;

        if (menu >= 1 && menu <= 4) {
            // ใช้ push_back เพื่อเพิ่มข้อมูลลงใน vector
            tables[table].List.push_back(food);
            tables[table].Price.push_back(price[menu]);
            tables[table].Amount.push_back(amount);

            tables[table].total += price[menu] * amount;

            cout << endl;
            cout << ">> Added : " << food << " x" << amount
                << " - " << price[menu] * amount << " Baht <<" << endl;
            cout << endl;
            tables[table].count++;
        }
        else {
            cout << "Invalid menu!" << endl;
        }

        int result = moree();
        if (result == 0) return;
    }
}

void selectTable() {
    cout << endl << endl;
    cout << "================== SELECT TABLE ==================" << endl;
    cout << "  1. Table 1" << endl;
    cout << "  2. Table 2" << endl;
    cout << "  3. Table 3" << endl;
    cout << "  4. Table 4" << endl;
    cout << "  5. Table 5" << endl;
    cout << "--------------------------------------------------" << endl;
    cout << "  0. Back to Home" << endl;
    cout << "--------------------------------------------------" << endl;
    cout << "CHOOSE YOUR TABLE >> ";
    cin >> table;

    if (table >= 1 && table <= 5) {
        useTable[table]++;
    }
}

void menuu() {
    int item, size;
    if (menu == 1) {
        cout << endl << endl << endl;
        cout << "============= RECOMMENDED =============" << endl;
        cout << " 1) Spicy Tom Yum Goong Soup With Rice   80/85 BTH" << endl;
        cout << " 2) Mango Sticky Rice                    50/55 BTH" << endl;
        cout << " 3) Som Tam Thai                         50/60 BTH" << endl;
        cout << "Select Item >> "; 
        cin >> item;

        if (item == 1) {
            food = "Tom Yum Goong";
            cout << "(1) 80 (2) 85: ";
            cin >> size;
            if (size == 1) price[menu] = 80;
            else price[menu] = 85;
        }
        else if (item == 2) {
            food = "Mango Rice";
            cout << "(1) 50 (2) 55: ";
            cin >> size;
            if (size == 1) price[menu] = 50;
            else price[menu] = 55;
        }
        else if (item == 3) {
            food = "Som Tam";
            cout << "(1) 50 (2) 60: ";
            cin >> size;
            if (size == 1) price[menu] = 50;
            else price[menu] = 60;
        }
    }
    else if (menu == 2) {
        cout << endl << endl << endl;
        cout << "========== MAIN COURSES ==========" << endl;
        cout << " 1) Fried Pork Rice      30/35 BTH" << endl;
        cout << " 2) Fried Chicken Rice   30/35 BTH" << endl;
        cout << "Select Item >> "; 
        cin >> item;

        if (item == 1) {
            food = "Pork Rice";
            cout << "(1) 30 (2) 35: ";
            cin >> size;
            if (size == 1) price[menu] = 30;
            else price[menu] = 35;
        }
        else if (item == 2) {
            food = "Chicken Rice";
            cout << "(1) 30 (2) 35: ";
            cin >> size;
            if (size == 1) price[menu] = 30;
            else price[menu] = 35;
        }
    }
    else if (menu == 3) {
        cout << endl << endl << endl;
        cout << "========== BEVERAGES ==========" << endl;
        cout << " 1) Water 10 | 2) Soft Drink 20" << endl;
        cout << "Select Item >> ";
        cin >> item;
        if (item == 1) { 
            food = "Water"; 
            price[menu] = 10; }
        else { 
            food = "Soft Drink"; 
            price[menu] = 20; }
    }
    else if (menu == 4) {
        cout << endl << endl << endl;
        cout << "========== DESSERTS ==========" << endl;
        cout << " 1) Ice Cream 15 | 2) Cake 30" << endl;
        cout << "Select Item >> "; 
        cin >> item;
        if (item == 1) { 
            food = "Ice Cream"; 
            price[menu] = 15; 
        }
        else { 
            food = "Cake"; price[menu] = 30;
        }
    }
}

int moree() {
    while (true) {
        cout << "More order? (1) yes / (2) no  " << endl;
        backtohome();
        cin >> more;
        if (more == 1) return 1;
        if (more == 2) { 
            showBill(); 
            return 0; 
        }
        if (more == 0) return 0;
        if (more == 9) { 
            selectTable(); 
            return 1; 
        }
        cout << "Invalid!! try again" << endl;
    }
}

void showBill() {
    cout << endl;
    cout << "----------- BILL SUMMARY -----------" << endl;
    cout << "Table : " << table << endl;
    for (int i = 0; i < tables[table].count; i++) {
        cout << i + 1 << ". " << tables[table].List[i] << " x" << tables[table].Amount[i]
            << " = " << tables[table].Price[i] * tables[table].Amount[i] << " Baht" << endl;
    }
    cout << "Total Price : " << tables[table].total << " Baht" << endl;
}

void employ() {
    while (true) {
        cout << endl;
        cout << "======= TABLE STATUS =======" << endl;
        for (int i = 1; i <= 5; i++) {
            cout << "Table " << i << " : ";
            if (tables[i].count > 0) cout << "[NOT AVAILABLE]" << endl;
            else cout << "[AVAILABLE]" << endl;
        }
        cout << "Select table (0 to Exit): "; cin >> check;
        if (check == 0) return;

        if (tables[check].count > 0) {
            for (int i = 0; i < tables[check].count; i++) {
                cout << tables[check].List[i] << " x" << tables[check].Amount[i] << " = "
                    << tables[check].Price[i] * tables[check].Amount[i] << endl;
            }

            cout << "Total : " << tables[check].total << endl;
            cout << "1.Clear table | 0.Back : ";

            int cmd;
            cin >> cmd;
            if (cmd == 1) {
                // เคลียร์ข้อมูลใน vector สำหรับโต๊ะนั้นๆ
                tables[check].List.clear();
                tables[check].Price.clear();
                tables[check].Amount.clear();
                tables[check].count = 0;
                tables[check].total = 0;
                cout << ">>> CLEARED <<<" << endl;
            }
        }
        else cout << "No orders" << endl;
    }
}

void Host() {
    int choose;
    while (true) {
        cout << endl;
        cout << "--- HOST MENU ---" << endl;
        cout << "1.Summary" << endl;
        cout << "2.Table Usage" << endl;
        cout << "0.Back" << endl;
        cout << "SELECT OPTION >> ";
        cin >> choose;
        if (choose == 1) summarize();
        else if (choose == 2) checktable();
        else if (choose == 0) break;
    }
}

void summarize() {
    int grandTotal = 0;
    for (int i = 1; i <= 5; i++) grandTotal += tables[i].total;
    cout << endl;
    cout << "TOTAL REVENUE : " << grandTotal << " Baht" << endl;
}

void checktable() {
    cout << endl;
    cout << "--- TABLE USAGE STATISTICS ---" << endl;
    for (int i = 1; i <= 5; i++)
        cout << "Table " << i << " used " << useTable[i] << " times" << endl;
}

void checkfood() {}

int main() {
    while (true) {
        home();
        if (cin.fail()) {
            cin.clear(); 
            cin.ignore(1000, '\n');
            cout << "Invalid input! Try again." << endl;
            continue;
        }
        if (Num == 0) {
            cout << endl << "Exiting program..." << endl;
            return 0;
        }
        if (Num == 1) { table = 0; customer(); }
        else if (Num == 2 || Num == 3) {
            string pass;
            cout << ">>>>>> LOGIN <<<<<<" << endl;
            cout << "Enter Password: ";
            cin >> pass;
            if (Num == 2 && pass == "555") employ();
            else if (Num == 3 && pass == "header") Host();
            else cout << "Wrong Password!" << endl;
        }
        else cout << "Invalid selection!" << endl;
    }
}
