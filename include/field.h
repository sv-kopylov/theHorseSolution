#ifndef FIELD_H
#define FIELD_H
#include "cell.h"
#include <fstream>

const int STEPMAX=100;
const int XMAX=10;
const int YMAX=10;



class field
{
    private:
        int num_of_results = 0;
        cell arr_of_cells[XMAX][YMAX];
        pos arr_of_steps [STEPMAX+1];
        int current_step;
        pos current_pos;
        pos previous_pos;
        long double spent_time;
    public:
        field ();
        field (char* str);
        field(pos start);
        bool next_step ();
        void back_step ();
        void Show_result();
        void Show_cells_metods();
        cell & operator()(pos a);
        const int c_Step() {return current_step;}
        void savebin (std::ofstream & ofs);
        void saveresult();
        void getbin (std::ifstream & ifs);
        void set_time(long double t){spent_time+=t;}
        void show_time();
        const cell get_cell(int x, int y);





};

#endif // FIELD_H
