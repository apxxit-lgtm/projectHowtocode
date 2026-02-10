//underconstruction >> FUNCTION OF HOST <<
void summarize() {
    cout << "\n===========================================" << endl;
    cout << "           DAILY BUSINESS SUMMARY          " << endl;
    cout << "===========================================" << endl;

    // 1. รายงานการใช้โต๊ะ
    checktable();
    cout << "-------------------------------------------" << endl;

    // 2. รายงานเมนูที่ขายได้
    checkfood();
    cout << "-------------------------------------------" << endl;

    // 3. สรุปรายได้รวมทั้งหมด
    cout << " >> TOTAL REVENUE TODAY : " << grandTotal << " Baht <<" << endl;
    cout << "===========================================\n" << endl;
}

void checktable() {
    cout << "\n======= TABLE USAGE SUMMARY =======" << endl;
    cout << setw(10) << "      Table No." << setw(20) << "      Times Used" << endl;
    cout << "-----------------------------------" << endl;

    int totalTable = 0;
    for (int i = 1; i <= 5; i++) {
        cout << setw(10) << i << setw(17) << useTable[i] << " times" << endl;
        totalTable += useTable [i] ;
    }

    cout << "-----------------------------------" << endl;
    cout << "Total Table used: " << totalTable << " times" << endl;
}

void checkfood() {
    cout << "---$$$ Today's menu $$$---" << endl;
    if (orderCount == 0) {
        cout << "No orders yet";
    }
    else {
        for (int i = 0; i < orderCount; i++)  cout << List[i] << " - " << orderPrice[i] << endl;
    }


}
void printbill() {
    cout << "-------------------------------" << endl;
    cout << "          benefits             " << endl;
    cout << "          " << "table : " << table << "             " << endl;
    cout << "-------------------------------" << endl;
    cout << "Menu" << " " << setw(15) << "Qty" << setw(15) << " " << "Total price" << endl;
    for (int i = 0; i < orderCount; i++) {
        cout << List[i] << " " << setw(15) << Amount[i] << " " << setw(15) << orderPrice[i] << endl;
    }

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
