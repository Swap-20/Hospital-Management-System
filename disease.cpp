#include <iostream>
#include <string>
using namespace std;

class Disease{
    private:
    char diseaseName[25], virusName[25];

    public:
    void getDiseaseData(){
        cout<<"Enter Disease Name : ";
        cin>>diseaseName;
        cout<<"Enter Virus Name : ";
        cin>>virusName;
    }

    void showDiseaseList(){
        cout<<endl;
        cout<<"Disease : "<<diseaseName<<endl;
        cout<<"Virus : "<<virusName<<endl;
    }
};
int main(){
    Disease d;
    d.getDiseaseData();
    d.showDiseaseList();
    return 0;
}