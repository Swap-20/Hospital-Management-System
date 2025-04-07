#include <iostream>
#include <fstream>
#include <sstream>
#include <windows.h>
#include <vector>
using namespace std;

class Hospital{
    private:
    string Name, Address, Bgroup;
    public:
    Hospital():Name(""),Address(""),Bgroup(""){}

    //Member functions
    void setName(string name){
        Name = name;
    }
    void setAddress(string address){
        Address = address;
    }
    void setBgroup(string bgroup){
        Bgroup = bgroup;
    }

    string getName(){
        return Name;
    }
    string getAddress(){
        return Address;
    }
    string getBgroup(){
        return Bgroup;
    }
};

void admit(Hospital &patient){
    system("cls");

    string name, address, bgroup;

    cout<<"\tEnter Name of Patient : ";
    cin>>name;
    patient.setName(name);

    cout<<"\tEnter Address of Patient : ";
    cin>>address;
    patient.setAddress(address);

    cout<<"\tEnter Bgroup of Patient : ";
    cin>>bgroup;
    patient.setBgroup(bgroup);

    ofstream outfile("Patient.txt",ios::app);
    if(!outfile){
        cout<<"\tError : File can't open!"<<endl;
    }
    else{
        outfile<<"\t"<<patient.getName()<<" : "<<patient.getAddress()<<" : "<<patient.getBgroup()<<endl<<endl;
        cout<<"\tPatient Admitted!"<<endl;
    }
    outfile.close();
    Sleep(3000);
}
void discharge(){
    system("cls");
    string name;
    cout<<"\tEnter Name of Patient : ";
    cin>>name;
    ifstream infile("Patient.txt");
    ofstream outfile("temp.txt");
    if(!infile || !outfile){
        cout<<"\tError : File can't open!"<<endl;
    }
    else{
        string line;
        bool found = false;

        while(getline(infile,line)){
            stringstream ss;
            ss<<line;

            string patientName;
            ss>>patientName;
            if (patientName == name)
            {
                found = true;
                cout<<"\tPatient Discharged!"<<endl;
            }
            else{
                outfile<<line<<endl;
            }
        }
        if(!found){
            cout<<"\tPatient Not Found!"<<endl;
        }
    }
    outfile.close();
    infile.close();
    remove("Patient.txt");
    rename("temp.txt","Patient.txt");
    Sleep(3000);
}
int main(){
    Hospital patient;

    bool exit = false;
    while(!exit){
        system("cls");

        int val;
        cout<<"\tHospital Management System"<<endl;
        cout<<"\t*****************************"<<endl;
        cout<<"\t1.Admit Patient"<<endl;
        cout<<"\t2.Discharge Patient"<<endl;
        cout<<"\t3.Exit"<<endl;
        cout<<"\tEnter Choice : ";
        cin>>val;

        if(val==1){
            admit(patient);
        }
        else if(val==2){
            discharge();
        }
        else if(val==3){
            system("cls");
            exit = true;
            cout<<"\tGood Bye. Have a nice day!"<<endl;
        }
        Sleep(4000);
    }
}