#include <iostream>
#include <string>
using namespace std;

class person{
    private:
    int age;
    char name[25], address[25], MobNo[25];

    public:
    void getpersonData(){
        cout<<"Enter Name : ";
        cin>>name;
        cout<<"Enter age : ";
        cin>>age;
        cout<<"Enter Mobile No : ";
        cin>>MobNo;
        cout<<"Enter Address : ";
        cin>>address;
    }

    void showPersonData(){
        cout<<"Name : "<<name<<endl;
        cout<<"Age : "<<age<<endl;
        cout<<"Mobile No : "<<MobNo<<endl;
        cout<<"Address : "<<address<<endl;
    }
};
int main(){
    person p1;
    p1.getpersonData();
    p1.showPersonData();
    return 0;
}