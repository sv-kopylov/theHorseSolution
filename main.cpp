#include "cell.h"
#include "field.h"
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <boost/thread.hpp>

static volatile bool is_runing = true;


using std::cout;
using std::cerr;
using std::endl;
using std::cin;

void change_flag (){
    char ch='x';
    cout<<"<q> to quit: "<<endl;
    while ((ch!='q')&&is_runing){
    ch = cin.get();
    if (ch=='q'){
    is_runing = false;
    }
    }


}

void see_result();

int main() {

 //   see_result();
 //   return 0;

 cout<<"would you count <y> - yes?\n";
 char wyc;
 cin>>wyc;
 if (wyc=='y')
 {

     char* file = "field.horse";
    field Mainfield("evristic");




std::ifstream fin (file, std::ios_base::binary);
        if (!fin.is_open()) {
            cout<<"There is no saved file, you have to start new calculation"<<endl;
            }
       Mainfield.getbin(fin);
       Mainfield.Show_result();


 int stst;
 do {
cout <<"The current step is: "<<Mainfield.c_Step()<<" Enter a stop step: ";
cin>>stst;
if (stst<0||stst>100)
    cout<<"bad range, try again\n";
 }
 while (stst<0||stst>100);

clock_t t;
long double result=0;
t=clock();
boost::thread thr(change_flag);

while ((Mainfield.c_Step())<=stst&&(is_runing)){

   if (!(Mainfield.next_step()))
        Mainfield.back_step();
        if (Mainfield.c_Step()==100) Mainfield.saveresult();

}
is_runing = false;
result=(clock()-t);
Mainfield.set_time(result/CLOCKS_PER_SEC);
std::ofstream fout(file, std::ios_base::binary);
        if (!fout.is_open()) {
            cerr<<"file can't be saved"<<endl;
            exit(EXIT_FAILURE);
        }
        Mainfield.savebin(fout);

Mainfield.Show_result();
cout<<endl;
cout<<"The whole time counting: ";
Mainfield.show_time();

cout<<endl;
cout<<"Current step is: "<<Mainfield.c_Step()<<endl;

thr.join();

 }

 cout<<"would you see a result <y> - yes ?\n";
 cin>>wyc;
 if (wyc=='y') see_result();

return 0;


}
void see_result(){
    int n;
    cout << "Enter a num of result here: ";
    cin>>n;
    std::stringstream buff;
    buff<<"result_"<<n<<".horse";
    std::string fname = buff.str();

    std::ifstream fin (fname, std::ios_base::binary);
        if (!fin.is_open()) {
            cout<<"There is no saved file, you have to start new calculation"<<endl;
            }
            field a;
       a.getbin(fin);
       a.Show_result();

}

