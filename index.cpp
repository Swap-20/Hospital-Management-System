#include <iostream>
#include <fstream>
#include <sstream>
#include <windows.h>
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
        Sleep(5000);
    }
}