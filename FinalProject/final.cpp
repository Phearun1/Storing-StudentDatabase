#include <iostream>
#include <iomanip>
#include <stdio.h>
#include <fstream>
#include <stdlib.h>
#include <cstdlib>
#include <string>
#include <string_view>
#include <regex>
#include <vector>
#include <sstream>
#include <chrono>

using namespace std;

class student
{
private:
    string firstname, lastname, gender, ID;
    string gpa;

public: // store function
    void menu();
    void insert();
    void display();
    void modify();
    void search();
    void deleted();
    void sortDescendId();
    void sortAscendId();
    void sortDescendGpa();
    void sortAscendGpa();
    void sortMenu();
};

void student::sortMenu()
{
    char choice;
    cout << "\t\t\t-----------------------------" << endl;
    cout << "\t\t\t|  SORTING STUDENTS SYSTEM  |" << endl;
    cout << "\t\t\t-----------------------------" << endl;
    cout << "\t\t\t 1. Sort Ascending ID" << endl;
    cout << "\t\t\t 2. Sort Descending ID" << endl;
    cout << "\t\t\t 3. Sort Ascending GPA" << endl;
    cout << "\t\t\t 4. Sort Descending GPA" << endl;
    cout << "\t\t\t 5. Return To Main Menu" << endl;

    cout << "\t\t\t............................" << endl;
    cout << "\t\t\tChoose Options:[1/2/3/4/5]" << endl;
    cout << "\t\t\t............................" << endl;
    cout << "\t\t\tEnter Your Choose: ";
    cin >> choice;
    switch (choice)
    {
    case '1':
    { // sort ascending of ID
        system("cls");
        auto now = chrono::system_clock::now();
        sortAscendId();
        auto end = chrono::system_clock::now();
        chrono::duration<double> elapsed_seconds = end - now;
        cout << "\t\t\tFinished Sorting in: " << elapsed_seconds.count() * 1000 << "ms\n";
        system("pause");
        return sortMenu();

    }
    break;
    case '2':
    {
        system("cls");
        auto now = chrono::system_clock::now();
        sortDescendId();
        auto end = chrono::system_clock::now();
        chrono::duration<double> elapsed_seconds = end - now;
        cout << "\t\t\tFinished Sorting in: " << elapsed_seconds.count() * 1000 << "ms\n";
        system("pause");
        return sortMenu();
    }
    break;
    case '3':
    {
        system("cls");
        auto now = chrono::system_clock::now();
        sortAscendGpa();
        auto end = chrono::system_clock::now();
        chrono::duration<double> elapsed_seconds = end - now;
        cout << "\t\t\tFinished Sorting in: " << elapsed_seconds.count() * 1000 << "ms\n";
        system("pause");
        return sortMenu();
    }
    break;
    case '4':
    {
        system("cls");
        auto now = chrono::system_clock::now();
        sortDescendGpa();
        auto end = chrono::system_clock::now();
        chrono::duration<double> elapsed_seconds = end - now;
        cout << "\t\t\tFinished Sorting in: " << elapsed_seconds.count() * 1000 << "ms\n";
        system("pause");
        return sortMenu();
    }
    break;
    case '5':
    {
        menu();
    }
    break;
    default:
    {
        cout << "\n\n\t\t\t Invalid Choice... \nPlease Try Again..."<<endl;
        system("pause");
        return sortMenu();
    }
    }
}

// Project Menu
void student::menu()
{
menustart:
    char choice;
    char x;
    system("cls");
    cout << "\t\t\t-----------------------------" << endl;
    cout << "\t\t\t| STUDENT MANAGEMENT SYSTEM |" << endl;
    cout << "\t\t\t-----------------------------" << endl;
    cout << "\t\t\t 1. Enter New Student" << endl;
    cout << "\t\t\t 2. Display Student" << endl;
    cout << "\t\t\t 3. Modify Student" << endl;
    cout << "\t\t\t 4. Search Student" << endl;
    cout << "\t\t\t 5. Delete Student" << endl;
    cout << "\t\t\t 6. Sort Student" << endl;
    cout << "\t\t\t 7. Exit\n"
         << endl;

    cout << "\t\t\t.............................." << endl;
    cout << "\t\t\tChoose Options:[1/2/3/4/5/6/7]" << endl;
    cout << "\t\t\t.............................." << endl;
    cout << "\t\t\tEnter Your Choose: ";
    cin >> choice;
    switch (choice)
    {
    case '1':
        do // to loop for adding student
        {
            insert();
            cout << "\n\n\t\t\t Add Another Student Record (Y, N) : ";
            cin >> x;
        } while (x == 'y' || x == 'Y');
        break;
    case '2':
        display();
        break;
    case '3':
        modify();
        break;
    case '4':
        search();
        break;
    case '5':
        deleted();
        break;
    case '6':
        sortMenu();
        return sortMenu();
    case '7':
        cout << "\n\t\t\t Program Is Exit";
        exit(0);
    default:
        cout << "\n\n\t\t\t Invalid Choice... \nPlease Try Again...";
        system("pause");
        return;
    }
    goto menustart;
}
void student::insert() // Add student details
{
    system("cls");
    bool validID = true;
    cout << "\n-------------------------------------------------------------------------------------------------------" << endl;
    cout << "------------------------------------- Add Student Details ---------------------------------------------" << endl;
    cout << "\t\t\tEnter ID: ";
    cin >> ID;

    fstream file;
    file.open("studentRecord.csv", ios::in); // write file
    // validation for entering id
    string row;
    while (getline(file, row)) // Will loop to get each row
    {
        stringstream linerow(row);       // Get one row
        if (getline(linerow, row, '\n')) // If the row hits a new line then it will start copying data
        {
            string checkid;
            for (int i = 0; i < row.length(); i++) // Will loop to get each element (index) in the row (STRING)
            {
                if (row[i] == ',') // when i is in the index of comma it will break
                {
                    break;
                }
                checkid += row[i];
            }
            if (checkid == ID) // if new input id is the same as the id
            {
                validID = false;
            }
        }
    }
    file.close();
    if (!validID)
    {
        cout << "ID Taken!!!" << endl;
        return;
    }
    cout << "\t\t\tEnter First Name: ";
    cin >> firstname;
    cout << "\t\t\tEnter Last Name: ";
    cin >> lastname;
    cout << "\t\t\tEnter Gender: ";
    cin >> gender;
    while (1) // validation input for ID
    {
        double gpa2;
        cout << "\t\t\tEnter GPA for student: ";
        cin>>gpa;
        gpa2 = stod(gpa);
        if(gpa2 < 0){
            cout<<"\t\t\tGPA cannot be less than 0"<<endl;
        }
        else if(gpa2 > 4.0){
            cout<<"\t\t\tGPA cannot be more than 4.0"<<endl;
        }
        else
        {
            break;
        }
    }
    file.open("studentRecord.csv", ios::app | ios::out);
    file << ID << "," << firstname << "," << lastname << "," << gender << "," << gpa << endl; // post inputs in csv file
    file.close();
}
void student::display() // Display data of student
{
    cout << left << setw(20) << "ID" << left << setw(20) << "Firstname" << left << setw(20) << "Lastname" << left << setw(20) << "Gender" << left << setw(20) << "GPA" << endl;
    cout << "====================================================================================\n"
         << endl;
    fstream file("studentRecord.csv", ios::in);
    string row;
    int totalstudent = 0;
    while (getline(file, row))
    {
        stringstream linerow(row);
        if (getline(linerow, row, '\n'))
        {
            string did, dfname, dlname, dgender, dgpa;
            bool chid = true;
            bool chfname = false;
            bool chlname = false;
            bool chgender = false;
            bool chgpa = false;
            for (int i = 0; i <= row.length(); i++)
            {
                if (chid)
                {
                    did += row[i];
                    if (row[i + 1] == ',')
                    {
                        chid = false;
                        chfname = true;
                    }
                }
                else if (chfname)
                {
                    if (row[i] == ',')
                    {
                        i += 1;
                    }
                    dfname += row[i];
                    if (row[i + 1] == ',')
                    {
                        chfname = false;
                        chlname = true;
                    }
                }
                else if (chlname)
                {
                    if (row[i] == ',')
                    {
                        i += 1;
                    }
                    dlname += row[i];
                    if (row[i + 1] == ',')
                    {
                        chlname = false;
                        chgender = true;
                    }
                }
                else if (chgender)
                {
                    if (row[i] == ',')
                    {
                        i += 1;
                    }
                    dgender += row[i];
                    if (row[i + 1] == ',')
                    {
                        chgender = false;
                        chgpa = true;
                    }
                }
                else if (chgpa)
                {
                    if (row[i] == ',')
                    {
                        i += 1;
                    }
                    dgpa += row[i];
                }
            }
            cout << setw(20) << did << setw(20) << dfname << setw(20) << dlname << setw(20) << dgender << setw(19) << dgpa << endl;
        }
        totalstudent++;
    }
    cout<<endl;
    cout<<"Total Students: "<<totalstudent<<endl;
    cout<<endl;
    system("pause");
    return;
}
void student::modify() // Modify details of student
{
    system("cls");
    fstream file;
    file.open("studentRecord.csv", ios::in);
    fstream file2;
    file2.open("studentRecordtemp.csv", ios::out);
    string row;
    string modifyById;
    cout << "\t\t\tEnter ID to Modify: ";
    cin >> modifyById;
    string chfname, chlname, chgender, chgpa;
    cout << "\t\t\tEnter First Name: ";
    cin >> chfname;
    cout << "\t\t\tEnter Last Name: ";
    cin >> chlname;
    cout << "\t\t\tEnter Gender: ";
    cin >> chgender;
    cout << "\t\t\tEnter GPA: ";
    cin >> chgpa;
    while (getline(file, row)) // Will loop to get each row
    {
        stringstream linerow(row);       // Get one row
        if (getline(linerow, row, '\n')) // If the row meet a new line then it will start copying data
        {
            string id;
            for (int i = 0; i < row.length(); i++) // Will loop to get each element (index) in the row (STRING)
            {
                if (row[i] == ',') // if meet comma break
                {
                    break;
                }
                id += row[i]; // store id as id in csv
            }
            if (id != modifyById) // if id opposite from ID input stay there
            {
                file2 << row << endl; // print out every row
            }
            else
            {
                file2 << modifyById << "," << chfname << "," << chlname << "," << chgender << "," << chgpa << endl;
            }
        }
    }
    file2.close();
    file.close();
    remove("studentRecord.csv");
    rename("studentRecordtemp.csv", "studentRecord.csv");
}

void student::search() // search data of student
{
    system("cls");
    fstream file;
    file.open("studentRecord.csv", ios::in);
    string row;
    string searchById;
    cout << "\t\t\tEnter ID to search: ";
    cin >> searchById;
    while (getline(file, row)) // Will loop to get each row
    {
        stringstream linerow(row);       // Get one row
        if (getline(linerow, row, '\n')) // If the row hits a new line then it will start copying data
        {
            string id, name, gender;
            for (int i = 0; i < row.length(); i++) // Will loop to get each element (index) in the row (STRING)
            {
                if (row[i] == ',') // meet first comma then break
                {
                    break;
                }
                id += row[i]; // store id
            }
            if (id == searchById) // begin checkign for id
            {
                string ID, firstname, lastname, gender, gpa;
                bool checkID = true;
                bool chfirstname = false;
                bool chlastname = false;
                bool chgender = false;
                bool chgpa = false;
                for (int i = 0; i < row.length(); i++)
                {
                    if (checkID) // check for ID
                    {
                        ID += row[i];          // store id by one by one
                        if (row[i + 1] == ',') // if next index is comma
                        {
                            checkID = false;
                            chfirstname = true;
                            i++;
                        }
                    }
                    else if (chfirstname) // check for firstname
                    {
                        firstname += row[i];   // store firstname
                        if (row[i + 1] == ',') // if next index is comma
                        {
                            chfirstname = false;
                            chlastname = true;
                            i++;
                        }
                    }
                    else if (chlastname) // check for lastname
                    {
                        lastname += row[i];    // store lastname
                        if (row[i + 1] == ',') // if next index is comma
                        {
                            chlastname = false;
                            chgender = true;
                            i++;
                        }
                    }
                    else if (chgender) // check for gender
                    {
                        gender += row[i];      // store gender
                        if (row[i + 1] == ',') // if the next index comma
                        {
                            chgender = false;
                            chgpa = true;
                            i++;
                        }
                    }
                    else if (chgpa) // check for gpa
                    {
                        gpa += row[i]; // store gpa
                    }
                }
                // Print as row
                cout << "\t\t\tID: " << ID << endl;
                cout << "\t\t\tFirst Name: " << firstname << endl;
                cout << "\t\t\tLast Name: " << lastname << endl;
                cout << "\t\t\tGender: " << gender << endl;
                cout << "\t\t\tGPA: " << gpa << endl;
                system("pause");
                // break;
            }

        } // Will get next row
    }
    file.close();
}

void student::deleted() // ddeleted data of student
{
    system("cls");
    fstream file;
    file.open("studentRecord.csv", ios::in); // go read file
    fstream file2;
    file2.open("studentRecordtemp.csv", ios::out); // go and write file
    string row;
    string deleteById;
    cout << "Enter ID to Delete: ";
    cin >> deleteById;
    while (getline(file, row)) // Will loop to get each row
    {
        stringstream linerow(row);       // Get one row
        if (getline(linerow, row, '\n')) // If the row hits a new line then it will start copying data
        {
            string id;
            for (int i = 0; i < row.length(); i++) // Will loop to get each element (index) in the row (STRING)
            {
                if (row[i] == ',')
                {
                    break;
                }
                id += row[i];
            }
            if (id != deleteById) // if id opposite from ID input stay there
            {
                file2 << row << endl; // print out every row
            }
        }
    }
    file2.close();
    file.close();
    remove("studentRecord.csv");
    rename("studentRecordtemp.csv", "studentRecord.csv");
}
void student::sortAscendId()
{
    // we read from the file and take the data from it to sort
    int totalrow = 0;           //
    fstream file; //declares an object of type
    file.open("studentRecord.csv", ios::in);    // open the file "studentRecord.csv" 
    string row; 

    // reads a line from file and stores it in the row and also to know how many row.
    while (getline(file, row)) 
    {
        stringstream linerow(row);       // allows the contents of the row string to be treated like a stream that can be read from.
        if (getline(linerow, row, '\n')) // If the row hits a new line then it will start copying data
        {
            totalrow++;         // increment the totalrow that we have initialize at first
        }                       //  indicating that a new row has been read from the file.
    }
    file.close();
    file.open("studentRecord.csv", ios::in);

    string line[totalrow];   //declares an array of totalrow strings called line
    int position = 0;       //initilize the position to zero
    while (getline(file, row)) // reads a line from the input file stream (file) and stores it in the string variable row
    {
        stringstream linerow(row);       // a new stringstream object called linerow is created from the contents of row.
        if (getline(linerow, row, '\n')) // If the row hits a new line then it will start copying data
        {
            line[position] = row;   //then the contents of row are stored in the line array at the position index. vea dak row ti marn jorl index ti marn
   
        }
        position++;
    }
    file.close();

    for (int i = 0; i < totalrow - 1; i++)      // runs from the first element to the second-to-last element
    {
        int sorted = 0;         // initialize the sorted for the already sort
        for (int j = 0; j < totalrow - i - 1; j++)
        {
            string current = line[j];  // Create temp = current data in the vector
            string next = line[j + 1]; // Create another temp = the next data in the vector
            string currentid, nextid;   // create two empty strings to store the extracted IDs from the current and next rows

            // to get the first ID number from the line
            for (int k = 0; k < current.length(); k++) 
            {
                //student ID is assumed to be the first field so it read the data until comma
                currentid += current[k];            // extract the student ID from the current record
                if (current[k + 1] == ',')          // if there is a comma in the
                {
                    break;
                }
            }
            // to get the next ID number from the line
            for (int k = 0; k < next.length(); k++) //  To get next id
            {
                //the loop is concatenating the character to the end of nextid using the += operator. 
                nextid += next[k];
                if (next[k + 1] == ',') // if it counters a (,) then it reach the end of ID field so excuted 
                {
                    break;
                }
            }

            //Compare the ID by coverting the string to 
            if (stoi(currentid) > stoi(nextid))     // convert string in to integer and If the current ID is greater than the next ID,
            {                                       // the two elements are swapped.
                string temp = line[j];                // temporary variable to hold the current element          
                line[j] = line[j + 1];                  // it is replaced with the next element
                line[j + 1] = temp;                 // assigning the temporary variable to the next element.
                sorted = 1;                         // to show that it has been sorted 1
            }
        }
        if (sorted == 0)            // If no swaps were made, the array is already sorted, and the outer loop is terminated early
        {
            break;
        }
    }
    //create new file call temp and write the sorted data into it
    file.open("studentRecordtemp.csv", ios::out);
    for (int i = 0; i < totalrow; i++)
    {
        file << line[i] << endl;   //writes each element to the new file
    }
    file.close();
    // replaces the old unsorted data file with the new sorted one.
    remove("studentRecord.csv");  //remove the unsorted
    rename("studentRecordtemp.csv", "studentRecord.csv");  //replaced it with temp and rename it to the original 
}

void student::sortDescendId()
{
    int totalrow = 0;
    fstream file;
    file.open("studentRecord.csv", ios::in);
    string row;
    while (getline(file, row)) // Will loop to get each row
    {
        stringstream linerow(row);       // Get one row
        if (getline(linerow, row, '\n')) // If the row hits a new line then it will start copying data
        {
            totalrow++;
        } // Will get next row
    }
    file.close();
    file.open("studentRecord.csv", ios::in);
    string line[totalrow];
    int position = 0;
    while (getline(file, row)) // Will loop to get each row
    {
        stringstream linerow(row);       // Get one row
        if (getline(linerow, row, '\n')) // If the row hits a new line then it will start copying data
        {
            line[position] = row;
        } // Will get next row
        position++;
    }
    file.close();
    for (int i = 0; i < totalrow - 1; i++)
    {
        int sorted = 0;
        for (int j = 0; j < totalrow - i - 1; j++)
        {
            string current = line[j];  // Create temp = current data in the vector
            string next = line[j + 1]; // Create another temp = the next data in the vector
            string currentid, nextid;
            for (int k = 0; k < current.length(); k++) // To get current id
            {
                currentid += current[k];
                if (current[k + 1] == ',')
                {
                    break;
                }
            }
            for (int k = 0; k < next.length(); k++) //  To get next id
            {
                nextid += next[k];
                if (next[k + 1] == ',')
                {
                    break;
                }
            }

            if (stoi(currentid) < stoi(nextid))  //if the first id is smaller than the second id
            {
                string temp = line[j];
                line[j] = line[j + 1];
                line[j + 1] = temp;
                sorted = 1;
            }
        }
        if (sorted == 0)
        {
            break;
        }
    }
    file.open("studentRecordtemp.csv", ios::out);
    for (int i = 0; i < totalrow; i++)
    {
        file << line[i] << endl;
    }
    file.close();
    remove("studentRecord.csv");
    rename("studentRecordtemp.csv", "studentRecord.csv");
}
void student::sortAscendGpa()
{

    int totalrow = 0;
    fstream file;
    file.open("studentRecord.csv", ios::in);
    string row;
    while (getline(file, row)) // Will loop to get each row
    {
        stringstream linerow(row);       // Get one row
        if (getline(linerow, row, '\n')) // If the row hits a new line then it will start copying data
        {
            totalrow++; // count row
        }               // Will get next row
    }
    file.close();
    file.open("studentRecord.csv", ios::in);
    string line[totalrow];
    int position = 0;
    while (getline(file, row)) // Will loop to get each row
    {
        stringstream linerow(row);       // Get one row
        if (getline(linerow, row, '\n')) // If the row hits a new line then it will start copying data
        {
            line[position] = row;
        }           // Will get next row
        position++; // push in array
    }
    file.close();
    for (int i = 0; i < totalrow - 1; i++)
    {
        int sorted = 0;
        for (int j = 0; j < totalrow - i - 1; j++)
        {   
            //for first gpa
            int checkgpa = 0;      
            bool foundgpa = false;
            //second gpa
            int checkgpa2 = 0;
            bool foundgpa2 = false;

            string current = line[j];  // Create temp = current data in the vector
            string next = line[j + 1]; // Create another temp = the next data in the vector
            string currentgpa, nextgpa; // to store the string of the data from the file
            
            //check gpa for the first line
            for (int k = 0; k < current.length(); k++) // To get current id
            {   
                //we let it run from id until it found the gpa
                if (current[k] == ',')   // when the loop reaches a comma, it increments the k
                {
                    k++;
                }
                //Found gpa is first set to false but it will be set to true if the loop encountered the 4th comma
                if (foundgpa)
                {
                    currentgpa += current[k]; // if it is true, it will extract current character to the currentgpa string.
                }
                if (current[k + 1] == ',')    // if it reach one comma, it will increment
                {
                    checkgpa++;
                }
                if (checkgpa == 4)   // when it reach 4, it i will set true to found gpa
                {                    // then the current gpa will store the gpa
                    foundgpa = true;
                }
            }

            //check gpa for the second line
            for (int k = 0; k < next.length(); k++) //  To get next id
            {
                if (next[k] == ',')   //
                {
                    k++;
                }
                if (foundgpa2)
                {
                    nextgpa += next[k];
                }
                if (next[k + 1] == ',')
                {
                    checkgpa2++;
                }
                if (checkgpa2 == 4)
                {
                    foundgpa2 = true;
                }
            }
            if (stod(currentgpa) > stod(nextgpa))    // if the first gpa is larger than the second gpa
            {
                string temp = line[j];   // create a temp to store the gpa
                line[j] = line[j + 1];    //replace the first gpa with the second gpa
                line[j + 1] = temp;         // the second gpa is replace by the temp which is the first one
                sorted = 1;                 // set the sorted to 1
            }
        }
        if (sorted == 0)
        {
            break;
        }
    }
    file.open("studentRecordtemp.csv", ios::out);
    for (int i = 0; i < totalrow; i++)
    {
        file << line[i] << endl;
    }
    file.close();
    remove("studentRecord.csv");
    rename("studentRecordtemp.csv", "studentRecord.csv");
}
void student::sortDescendGpa()
{
    int totalrow = 0;
    fstream file;
    file.open("studentRecord.csv", ios::in);
    string row;
    while (getline(file, row)) // Will loop to get each row
    {
        stringstream linerow(row);       // Get one row
        if (getline(linerow, row, '\n')) // If the row hits a new line then it will start copying data
        {
            totalrow++; // count row
        }               // Will get next row
    }
    file.close();
    file.open("studentRecord.csv", ios::in);
    string line[totalrow];
    int position = 0;
    while (getline(file, row)) // Will loop to get each row
    {
        stringstream linerow(row);       // Get one row
        if (getline(linerow, row, '\n')) // If the row hits a new line then it will start copying data
        {
            line[position] = row;
        }           // Will get next row
        position++; // push in array
    }
    file.close();
    for (int i = 0; i < totalrow - 1; i++)
    {
        int sorted = 0;
        for (int j = 0; j < totalrow - i - 1; j++)
        {
            int checkgpa = 0;
            bool foundgpa = false;
            int checkgpa2 = 0;
            bool foundgpa2 = false;
            string current = line[j];  // Create temp = current data in the vector
            string next = line[j + 1]; // Create another temp = the next data in the vector
            string currentgpa, nextgpa;
            for (int k = 0; k < current.length(); k++) // To get current id
            {
                if (current[k] == ',')
                {
                    k++;
                }
                if (foundgpa)
                {
                    currentgpa += current[k];
                }
                if (current[k + 1] == ',')
                {
                    checkgpa++;
                }
                if (checkgpa == 4)
                {
                    foundgpa = true;
                }
            }
            for (int k = 0; k < next.length(); k++) //  To get next id
            {
                if (next[k] == ',')
                {
                    k++;
                }
                if (foundgpa2)
                {
                    nextgpa += next[k];
                }
                if (next[k + 1] == ',')
                {
                    checkgpa2++;
                }
                if (checkgpa2 == 4)
                {
                    foundgpa2 = true;
                }
            }
            if (stod(currentgpa) < stod(nextgpa))
            {
                string temp = line[j];
                line[j] = line[j + 1];
                line[j + 1] = temp;
                sorted = 1;
            }
        }
        if (sorted == 0)
        {
            break;
        }
    }
    file.open("studentRecordtemp.csv", ios::out);
    for (int i = 0; i < totalrow; i++)
    {
        file << line[i] << endl;
    }
    file.close();
    remove("studentRecord.csv");
    rename("studentRecordtemp.csv", "studentRecord.csv");
}
int main()
{
    student project; // object
    project.menu();  // object calling

    

    return 0;
}