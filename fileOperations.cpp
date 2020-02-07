#include<iostream>
#include<fstream>
#include<cstdio>
#include<cstdlib>
#include<string>
#include<unistd.h>
#include<fcntl.h>
using namespace std;

int main(){
	
	//Open, reset, find, read, findnext, delete, modify, insert, close
	fstream file("testFile.txt", ios::in | ios::out | ios::app);
	fstream newFile("newFile.txt", ios::in | ios::out | ios::trunc);
	
	string buff;
	
	string str, newStr;
	int flag;
	int line;
	
	int choice;
	while(true){
		cout << endl;
		cout << "testFile.txt is open." << endl;
		cout << endl;
		cout << "1. Reset" << endl;
		cout << "2. Find all" << endl;
		cout << "3. Read" << endl;
		cout << "4. Delete" << endl;
		cout << "5. Modify" << endl;
		cout << "6. Insert" << endl;
		cout << "7. Exit" << endl;
		cout << "Enter your choice." << endl;
		cin >> choice;
		
		cout << endl;
		
		switch(choice){
		case 1:
			file.close();
			remove("testFile.txt");
			file.open("testFile.txt", ios::in | ios::out | ios::app);
			cout << "File cleared." << endl;
			break;			
		case 2:
			flag = 0;
			line = 0;
			
			cout << "Enter string to search for." << endl;
			cin.ignore();
			getline(cin, str);
			
			while(getline(file, buff)){
				line++;
				size_t found = buff.find(str);
				if(found != string::npos){
					cout << "Line: " << line << endl;
					cout << "Position: " << found + 1 << endl;
					flag = 1;
					cout << endl;
				}
			}
			
			if(!flag)
				cout << "No matches." << endl;
			break;
		case 3:
			while(getline(file, buff)){
				cout << buff << cout;
			}
			break;
		case 4:
			file.close();
			remove("testFile.txt");
			file.open("testFile.txt", ios::in | ios::out | ios::app);
			cout << "File cleared." << endl;
			break;
		case 5:
			cout << "Enter string to replace." << endl;
			cin.ignore();
			getline(cin, str);
			
			cerr << "DEBUG: str: " << str << endl;
			
			cout << "Enter string to replace with." << endl;
			getline(cin, newStr);
			
			cerr << "DEBUG: newStr: " << newStr << endl;
			
			while(getline(file, buff)){
				size_t found = buff.find(str);
				if(found != string::npos){
					buff.replace(found, str.length(), newStr);
				}
				
				newFile << buff << endl;
			}
			
			rename("newFile.txt", "testFile.txt");
			
			newFile.close();
			file.close();
			file.open("testFile.txt", ios::in | ios::out | ios::app);
			
			cout << "Replacement complete." << endl;
			break;
		case 6:
			cout << "Enter string to insert." << endl;
			cin.ignore();
			getline(cin, str);
			
			file << str << endl;
			
			cout << endl;
			cout << "Insertion complete." << endl;
			
			break;
		case 7:
			return 0;
		
		
		}
	}
	
	file.close();

	return 0;
}
