#include "field.h"
#include "cell.h"
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <cstdlib>


using std::cout;
using std::endl;
using std::cerr;
using std::ofstream;
using std::ifstream;
//using std::write;
//using std::read;

field::field(): spent_time(0) { //ctot
    for (int i=0; i<XMAX; i++)
        for (int j=0;j<YMAX;j++)
    {
        arr_of_cells[i][j].SetPosition(i,j);
        arr_of_cells[i][j].complete_av_metods();
    }
    current_step=1;
    current_pos.Set(0,0);
    previous_pos.Set(0,0);

}
field::field(char * str): spent_time(0) { //ctot
    for (int i=0; i<XMAX; i++)
        for (int j=0;j<YMAX;j++)
    {
        arr_of_cells[i][j].SetPosition(i,j);
        arr_of_cells[i][j].complete_av_metods();
        arr_of_cells[i][j].transposition();
    }
    current_step=1;
    current_pos.Set(0,0);
    previous_pos.Set(0,0);

}
field::field(pos start):spent_time(0)  { //ctor
    for (int i=0; i<XMAX; i++)
        for (int j=0;j<YMAX;j++)
    {
        arr_of_cells[i][j].SetPosition(i,j);
        arr_of_cells[i][j].complete_av_metods();
    }
    current_step=1;
    arr_of_steps [1] = start;
    current_pos = start;
    previous_pos.Set(0,0);

}
void field::Show_result(){

    for (int i=0; i<XMAX; i++)
    {

        for (int j=0;j<YMAX;j++)
    {
        cout.width(3);

        cout << arr_of_cells[i][j].Step()<<"| ";

    }
    cout<<endl<<endl;
    }
}
void field::Show_cells_metods() {
    for (int i=0; i<XMAX; i++)
    for (int j=0;j<YMAX;j++)
    {
      arr_of_cells[i][j].Showmetohods();
       cout<<endl;
    }


}
bool field::next_step (){
    pos tmp = arr_of_steps[current_step];
    pos next_pos;
    int method_num = arr_of_cells[tmp.x][tmp.y].Giv_method();
    while (method_num<=nopass)
    {
        switch (method_num)
        {
    case uur:
        next_pos=(Uur(tmp));
        break;
    case urr:
        next_pos=(Urr(tmp));
        break;
    case drr:
        next_pos=(Drr(tmp));
        break;
    case ddr:
        next_pos=(Ddr(tmp));
        break;
    case ddl:
        next_pos=(Ddl(tmp));
        break;
    case dll:
        next_pos=(Dll(tmp));
        break;
    case ull:
        next_pos=(Ull(tmp));
        break;
    case uul:
        next_pos=(Uul(tmp));
        break;
    case nopass:
        return false;
        break;
    default:
        cerr<<"Something gona wrong\n";
        return false;
        break;
        }
        if (!(arr_of_cells[next_pos.x][next_pos.y].Is_empty()))
        {
        method_num = arr_of_cells[tmp.x][tmp.y].Giv_method();
       // cout<<"give new method\n";
        }
        else {
        previous_pos = tmp;
        current_pos = next_pos;

        arr_of_cells[tmp.x][tmp.y].Swith_cell(current_step);
       // cout<<"cell switched\n";

        current_step++;
        arr_of_steps [current_step]= next_pos;
        break;
        }
    }
return true;

    }
void field::back_step (){
     pos tmp = arr_of_steps[current_step];
     arr_of_cells[tmp.x][tmp.y].Clear_cell();
     current_step--;
     tmp = arr_of_steps[current_step];
     current_pos = arr_of_steps[current_step];
     previous_pos = arr_of_steps[current_step-1];
    //  cout<<"fall down\n";
   if (arr_of_cells[tmp.x][tmp.y].Giv_method()==nopass)

   back_step();
    return;
}
cell & field::operator()(pos a){
    return arr_of_cells[a.x][a.y];
}
void field::savebin (ofstream & ofs){
ofs.write ((char*)this, sizeof (field));
}
void field::getbin (ifstream & ifs){
ifs.read((char*)this, sizeof (field));
}
void field::show_time(){
    long hours=0;
    int minutes=0;
    int secundas=0;
    hours=(spent_time-((long)spent_time%3600))/3600;
    secundas = (int)spent_time%60;
    minutes = (((long)spent_time - secundas)/60)%60;
    cout<<hours<<": "<<minutes<<": "<<secundas;

}
const cell field::get_cell(int x, int y){
return arr_of_cells[x][y];
}
void field::saveresult(){
    std::stringstream buff;
    buff<<"result_"<<++num_of_results<<".horse";
    std::string fname = buff.str();
    std::ofstream fout(fname.c_str(), std::ios_base::binary);
        if (!fout.is_open()) {
            cerr<<"file can't be saved"<<endl;
            std::exit(EXIT_FAILURE);
        }
        fout.write ((char*)this, sizeof (field));

}







