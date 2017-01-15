#include "cell.h"
#include <iostream>

void pos::get_position (){
using std::cout;
using std::cin;
cout<<"Enter X position: ";
cin>>x; while (cin.get()!='\n') continue;
while (x<0||x>9){
    cout<<"Incorrect value\n";
    cout<<"Enter X position: ";
cin>>x; while (cin.get()!='\n') continue;
}
cout<<"Enter Y position: ";
cin>>y; while (cin.get()!='\n') continue;
while (y<0||y>9){
    cout<<"Incorrect value\n";
    cout<<"Enter Y position: ";
cin>>y; while (cin.get()!='\n') continue;
}
}
void pos::Set (int xx,int yy){
        x=xx;
        y=yy;
    }
void pos::Set (pos a) {
        x=a.x;
        y=a.y;
    }
pos Uur(pos a) {
    pos b;
    b.x=a.x-2;
    b.y=a.y+1;
    return b;
     }
pos Urr(pos a){
    pos b;
    b.x=a.x-1;
    b.y=a.y+2;
    return b;
     }
pos Drr(pos a){
    pos b;
    b.x=a.x+1;
    b.y=a.y+2;
    return b;
     }
pos Ddr(pos a){
    pos b;
    b.x=a.x+2;
    b.y=a.y+1;
    return b;
     }
pos Ddl(pos a){
    pos b;
    b.x=a.x+2;
    b.y=a.y-1;
    return b;
     }
pos Dll(pos a){
    pos b;
    b.x=a.x+1;
    b.y=a.y-2;
    return b;
     }
pos Ull(pos a){
    pos b;
    b.x=a.x-1;
    b.y=a.y-2;
    return b;
     }
pos Uul(pos a){
    pos b;
    b.x=a.x-2;
    b.y=a.y-1;
    return b;
     }
bool Check (pos a){
     if (a.x<0||a.x>9||a.y<0||a.y>9)
        return false;
     else
        return true;
     }

cell::cell(): Position(0, 0), step(0), next_metod(0){
        for (int i=0; i<9;i++)
            avalabel_metods[i]=nopass;
        }
void cell::SetPosition (int xx, int yy){
        Position.Set (xx, yy);
        }
void cell::SetPosition (pos pp){
        Position.Set (pp);
        }
void cell::complete_av_metods (){
    pos a;
    int i=0;
    a=Uur(Position);
    if (Check(a))
        avalabel_metods[i++]=uur;

    a=Urr(Position);
    if (Check(a))
        avalabel_metods[i++]=urr;

    a=Drr(Position);
    if (Check(a))
        avalabel_metods[i++]=drr;

    a=Ddr(Position);
    if (Check(a))
        avalabel_metods[i++]=ddr;

    a=Ddl(Position);
    if (Check(a))
        avalabel_metods[i++]=ddl;

    a=Dll(Position);
    if (Check(a))
        avalabel_metods[i++]=dll;

    a=Ull(Position);
    if (Check(a))
        avalabel_metods[i++]=ull;

    a=Uul(Position);
    if (Check(a))
        avalabel_metods[i++]=uul;

}
void cell::Showcell() const{
using std::cout;
using std::endl;
cout <<"x = "<<Position.x<<" y = "<<Position.y<<endl;
cout <<"step = "<<step<<endl;
cout <<"Availabel methods:\n";
for (int i=0;i<9;i++)
cout<< avalabel_metods[i]<< " ";
cout<<endl;
cout<< "Num of next metod = "<<next_metod<<endl;
}
void cell::Showmetohods () const {
using std::cout;
using std::endl;
for (int i=0;i<9;i++)
cout<< avalabel_metods[i]<< " ";
cout<<endl;
}
void cell::Clear_cell(){
            step=0;
            next_metod=0;
        }
void cell::Swith_cell(int st){
            step = st;
            if (avalabel_metods[next_metod]<nopass)
            if (next_metod<8)

            next_metod++;
        }
const int cell::Giv_method () {
            if (avalabel_metods[next_metod]<nopass)
            return avalabel_metods[next_metod++];
            else
            return avalabel_metods[next_metod];
        }













