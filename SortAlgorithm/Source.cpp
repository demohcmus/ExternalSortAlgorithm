#include<iostream>
#include<fstream>
#include <string>
#include <vector>
#include <sstream>
using namespace std;
struct Book {
    string id;
    string title;
    string price;
    string user;
    string profile;
    string helpfulness;
    string score;
    string time;
    string summary;
    string text;
};

// Ham tao item cho moi dong data
Book create(string id, string title, string price, string user, string profile, string helpfulness, string score, string time, string summary, string text)
{
    Book item;
    item.id = id;
    item.title = title;
    item.price = price;
    item.user = user;
    item.profile = profile;
    item.helpfulness = helpfulness;
    item.score = score;
    item.time = time;
    item.summary = summary;
    item.text = text;
    return item;
}

// Ham merge 
void merge(vector<Book>& books, int p, int q, int r) {

    int n1 = q - p + 1;
    int n2 = r - q;

    vector<Book> b1;
    vector<Book> b2;

    for (int i = 0; i < n1; i++)
        b1.push_back(books[p + i]);
    for (int j = 0; j < n2; j++)
        b2.push_back(books[q + 1 + j]);

    int i, j, k;
    i = 0;
    j = 0;
    k = p;
    while (i < n1 && j < n2) {
        int res = b1[i].id.compare(b2[j].id);
        if (res <= 0) {
            books[k] = b1[i];
            i++;
        }
        else {
            books[k] = b2[j];
            j++;
        }
        k++;
    }
    while (i < n1) {
        books[k] = b1[i];
        i++;
        k++;
    }
    while (j < n2) {
        books[k] = b2[j];
        j++;
        k++;
    }
}

// Ham sap xep data theo merge sort
void mergeSort(vector<Book>& books, int l, int r) {
    if (l >= r)
        return;
    int m = l + (r - l) / 2;
    mergeSort(books, l, m);
    mergeSort(books, m + 1, r);
    merge(books, l, m, r);

}

// Ham doc file de luu vao vector
vector<Book> readFile(vector<Book> books, string pathfile)
{
    cout << "Reading " << pathfile << " ........." << endl;
    ifstream file(pathfile, ios::out | ios::binary);
    if (!file.is_open()) cout << "Error: file OPEN " << pathfile << endl;

    string id, title, price, user, profile, helpfulness, score, time, summary, text;
    int flag = 0;
    while (file.peek() != EOF)
    {
        Book item;
        getline(file, id, ',');
        getline(file, title, ',');
        getline(file, price, ',');
        getline(file, user, ',');
        getline(file, profile, ',');
        getline(file, helpfulness, ',');
        getline(file, score, ',');
        getline(file, time, ',');
        getline(file, summary, ',');
        getline(file, text, '\n');
        item = create(id, title, price, user, profile, helpfulness, score, time, summary, text);
        books.push_back(item);
        if (flag == 0)
        {
            books.pop_back();
            flag++;
        }

    }
    file.close();
    cout << "\nFinished reading the file " << endl;
    return books;
}

// Ham viet data cua file vao vector
void writeFile(vector<Book> books, string pathfile)
{
    cout << "Writing " << pathfile << " ...................";
    ofstream fileviet;
    fileviet.open(pathfile, ios::in | ios::binary);
    if (!fileviet.is_open()) cout << "Error: OPEN " << pathfile << endl;

    for (auto x : books)
        fileviet << x.id << "," << x.title << "," << x.price << "," << x.user << "," << x.profile << "," << x.helpfulness << "," << x.score << "," << x.time << "," << x.summary << "," << x.text << "\n";

    cout << "Finished writing the file " << endl;
    fileviet.close();
}

// Ham merge hai file thanh mot file
void mergeTwoFile(string pathfile1, string pathfile2, string pathResultFile)
{
    cout << "Merging " << pathResultFile << " ............" << endl;
    ifstream file1(pathfile1, ios::out | ios::binary);
    ifstream file2(pathfile2, ios::out | ios::binary);
    ofstream fileTong(pathResultFile, ios::in | ios::binary);
    if (!file1.is_open() || !file2.is_open() || !fileTong.is_open()) cout << "Error: file OPEN" << endl;
    Book item1, item2;
    string id1, title1, price1, user1, profile1, helpfulness1, score1, time1, summary1, text1;
    string id2, title2, price2, user2, profile2, helpfulness2, score2, time2, summary2, text2;
    int flag = 0;
    while (file1.peek() != EOF && file2.peek() != EOF)
    {
        if (flag == 0)
        {
            getline(file1, id1, ',');
            getline(file1, title1, ',');
            getline(file1, price1, ',');
            getline(file1, user1, ',');
            getline(file1, profile1, ',');
            getline(file1, helpfulness1, ',');
            getline(file1, score1, ',');
            getline(file1, time1, ',');
            getline(file1, summary1, ',');
            getline(file1, text1, '\n');
            item1 = create(id1, title1, price1, user1, profile1, helpfulness1, score1, time1, summary1, text1);
            getline(file2, id2, ',');
            getline(file2, title2, ',');
            getline(file2, price2, ',');
            getline(file2, user2, ',');
            getline(file2, profile2, ',');
            getline(file2, helpfulness2, ',');
            getline(file2, score2, ',');
            getline(file2, time2, ',');
            getline(file2, summary2, ',');
            getline(file2, text2, '\n');
            item2 = create(id2, title2, price2, user2, profile2, helpfulness2, score2, time2, summary2, text2);
        }
        else if (flag == 1)
        {
            getline(file1, id1, ',');
            getline(file1, title1, ',');
            getline(file1, price1, ',');
            getline(file1, user1, ',');
            getline(file1, profile1, ',');
            getline(file1, helpfulness1, ',');
            getline(file1, score1, ',');
            getline(file1, time1, ',');
            getline(file1, summary1, ',');
            getline(file1, text1, '\n');
            item1 = create(id1, title1, price1, user1, profile1, helpfulness1, score1, time1, summary1, text1);
        }
        else if (flag == 2)
        {
            getline(file2, id2, ',');
            getline(file2, title2, ',');
            getline(file2, price2, ',');
            getline(file2, user2, ',');
            getline(file2, profile2, ',');
            getline(file2, helpfulness2, ',');
            getline(file2, score2, ',');
            getline(file2, time2, ',');
            getline(file2, summary2, ',');
            getline(file2, text2, '\n');
            item2 = create(id2, title2, price2, user2, profile2, helpfulness2, score2, time2, summary2, text2);
        }
        int res = item1.id.compare(item2.id);
        if (res <= 0)
        {
            fileTong << item1.id << "," << item1.title << "," << item1.price << "," << item1.user << "," << item1.profile << "," << item1.helpfulness << "," << item1.score << "," << item1.time << "," << item1.summary << "," << item1.text << "\n";
            flag = 1;
        }
        else
        {
            fileTong << item2.id << "," << item2.title << "," << item2.price << "," << item2.user << "," << item2.profile << "," << item2.helpfulness << "," << item2.score << "," << item2.time << "," << item2.summary << "," << item2.text << "\n";
            flag = 2;
        }
    }
    while (file1.peek() != EOF)
    {
        getline(file1, id1, ',');
        getline(file1, title1, ',');
        getline(file1, price1, ',');
        getline(file1, user1, ',');
        getline(file1, profile1, ',');
        getline(file1, helpfulness1, ',');
        getline(file1, score1, ',');
        getline(file1, time1, ',');
        getline(file1, summary1, ',');
        getline(file1, text1, '\n');
        item1 = create(id1, title1, price1, user1, profile1, helpfulness1, score1, time1, summary1, text1);
        fileTong << item1.id << "," << item1.title << "," << item1.price << "," << item1.user << "," << item1.profile << "," << item1.helpfulness << "," << item1.score << "," << item1.time << "," << item1.summary << "," << item1.text << "\n";
    }
    while (file2.peek() != EOF)
    {
        getline(file2, id2, ',');
        getline(file2, title2, ',');
        getline(file2, price2, ',');
        getline(file2, user2, ',');
        getline(file2, profile2, ',');
        getline(file2, helpfulness2, ',');
        getline(file2, score2, ',');
        getline(file2, time2, ',');
        getline(file2, summary2, ',');
        getline(file2, text2, '\n');
        item2 = create(id2, title2, price2, user2, profile2, helpfulness2, score2, time2, summary2, text2);
        fileTong << item2.id << "," << item2.title << "," << item2.price << "," << item2.user << "," << item2.profile << "," << item2.helpfulness << "," << item2.score << "," << item2.time << "," << item2.summary << "," << item2.text << "\n";
    }
    file1.close();
    file2.close();
    fileTong.close();
    cout << "Finished merge file!" << endl;
}



int main(int args, char* argv[])
{
    vector<Book> books;
    string pathData1, pathData2, pathData3, pathData4, pathData5, pathData6, pathData7, pathData8, pathData9, pathData10;
    string pathFile1, pathFile2, pathFile3, pathFile4, pathFile5, pathFile6, pathFile7, pathFile8, pathFile9, pathFile10;
    string pathTongLop1_1, pathTongLop1_2, pathTongLop1_3, pathTongLop1_4, pathTongLop1_5;
    string pathTongLop2_1, pathTongLop2_2, pathTongLop2_3;
    string pathTongDL;
    pathData1 = "1-Books_rating.csv";
    pathData2 = "2-Books_rating.csv";
    pathData3 = "3-Books_rating.csv";
    pathData4 = "4-Books_rating.csv";
    pathData5 = "5-Books_rating.csv";
    pathData6 = "6-Books_rating.csv";
    pathData7 = "7-Books_rating.csv";
    pathData8 = "8-Books_rating.csv";
    pathData9 = "9-Books_rating.csv";
    pathData10 = "10-Books_rating.csv";
    pathFile1 = "file1.csv";
    pathFile2 = "file2.csv";
    pathFile3 = "file3.csv";
    pathFile4 = "file4.csv";
    pathFile5 = "file5.csv";
    pathFile6 = "file6.csv";
    pathFile7 = "file7.csv";
    pathFile8 = "file8.csv";
    pathFile9 = "file9.csv";
    pathFile10 = "file10.csv";
    pathTongLop1_1 = "fileLop1_1.csv";
    pathTongLop1_2 = "fileLop1_2.csv";
    pathTongLop1_3 = "fileLop1_3.csv";
    pathTongLop1_4 = "fileLop1_4.csv";
    pathTongLop1_5 = "fileLop1_5.csv";
    pathTongLop2_1 = "fileLop2_1.csv";
    pathTongLop2_2 = "fileLop2_2.csv";
    pathTongLop2_3 = "fileLop2_3.csv";
    pathTongDL = "fileTongDL.csv";

    //------------- FILE 1 ----------------------
    books = readFile(books, pathData1);
    cout << "Sorting file............" << endl;
    mergeSort(books, 0, books.size() - 1);
    writeFile(books, pathFile1);
    books.clear();
    cout << endl << endl << endl;

    //------------- FILE 2 ----------------------
    books = readFile(books, pathData2);
    cout << "Sorting file............" << endl;
    mergeSort(books, 0, books.size() - 1);
    writeFile(books, pathFile2);
    books.clear();
    cout << endl << endl << endl;

    //------------- FILE 3 ----------------------
    books = readFile(books, pathData3);
    cout << "Sorting file............" << endl;
    mergeSort(books, 0, books.size() - 1);
    writeFile(books, pathFile3);
    books.clear();
    cout << endl << endl << endl;

    //------------- FILE 4 ----------------------
    books = readFile(books, pathData4);
    cout << "Sorting file............" << endl;
    mergeSort(books, 0, books.size() - 1);
    writeFile(books, pathFile4);
    books.clear();
    cout << endl << endl << endl;

    //------------- FILE 5 ----------------------
    books = readFile(books, pathData5);
    cout << "Sorting file............" << endl;
    mergeSort(books, 0, books.size() - 1);
    writeFile(books, pathFile5);
    books.clear();
    cout << endl << endl << endl;

    //------------- FILE 6 ----------------------
    books = readFile(books, pathData6);
    cout << "Sorting file............" << endl;
    mergeSort(books, 0, books.size() - 1);
    writeFile(books, pathFile6);
    books.clear();
    cout << endl << endl << endl;

    //------------- FILE 7 ----------------------
    books = readFile(books, pathData7);
    cout << "Sorting file............" << endl;
    mergeSort(books, 0, books.size() - 1);
    writeFile(books, pathFile7);
    books.clear();
    cout << endl << endl << endl;

    //------------- FILE 8 ----------------------
    books = readFile(books, pathData8);
    cout << "Sorting file............" << endl;
    mergeSort(books, 0, books.size() - 1);
    writeFile(books, pathFile8);
    books.clear();
    cout << endl << endl << endl;

    //------------- FILE 9 ----------------------
    books = readFile(books, pathData9);
    cout << "Sorting file............" << endl;
    mergeSort(books, 0, books.size() - 1);
    writeFile(books, pathFile9);
    books.clear();
    cout << endl << endl << endl;

    //------------- FILE 10 ----------------------
    books = readFile(books, pathData10);
    cout << "Sorting file............" << endl;
    mergeSort(books, 0, books.size() - 1);
    writeFile(books, pathFile10);
    books.clear();
    cout << endl << endl << endl;

    mergeTwoFile(pathFile1, pathFile2, pathTongLop1_1);
    mergeTwoFile(pathFile3, pathFile4, pathTongLop1_2);
    mergeTwoFile(pathFile5, pathFile6, pathTongLop1_3);
    mergeTwoFile(pathFile7, pathFile8, pathTongLop1_4);
    mergeTwoFile(pathFile9, pathFile10, pathTongLop1_5);

    mergeTwoFile(pathTongLop1_1, pathTongLop1_2, pathTongLop2_1);
    mergeTwoFile(pathTongLop1_3, pathTongLop1_4, pathTongLop2_2);
    mergeTwoFile(pathTongLop2_2, pathTongLop1_5, pathTongLop2_3);

    // File pathTongDL la file tong cua tat ca cac file da sap xep
    mergeTwoFile(pathTongLop2_1, pathTongLop2_3, pathTongDL);

    cout << "FINISHED SORT AND MERGE ALL FILE TO " << pathTongDL;


    return 0;
}