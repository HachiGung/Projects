#include <iostream>
#include "fstream"
using namespace std;

bool Logged(){
    string username , password , un , ps;

    cout << "Enter username: "; cin >> username;
    cout << "Enter Password: "; cin >> password;

    ifstream read("data\\"+username+".txt");
    getline(read,un);
    getline(read,ps);

    if( un == username && ps == password){
        return true;
    } else{
        return false;
    }
}

int main() {
    int choice;
    cout << "1:Register\n2:Login\nchoice: "; cin >> choice;

    if(choice == 1){
        string username , password;

        cout << "Enter Username :"; cin >> username;
        cout << "Enter password :"; cin >> password;

        ofstream file;
        file.open("data\\"+username+".txt");
        file << username << endl << password;
        file.close();
        main();
    } else if ( choice == 2){
        bool status = Logged();

        if(!status){
            cout << "Login Fail !" << endl;
            system("PAUSE");
            return 0;

        } else{
            
            cout << "Successful Login!" << endl;
            system("PAUSE");
            return 1;
        }
    }
    return 0;
}

