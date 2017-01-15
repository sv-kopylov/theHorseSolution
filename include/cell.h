#ifndef CELL_H
#define CELL_H
enum methods {uur, urr, drr, ddr, ddl, dll, ull, uul, nopass};


class pos
{
public:
    int x;
    int y;
    pos(int xx=0,int yy=0): x(xx), y(yy){}
    void Set (int xx,int yy);
    void Set (pos a);
    void get_position ();
};
pos Uur(pos a);
pos Urr(pos a);
pos Drr(pos a);
pos Ddr(pos a);
pos Ddl(pos a);
pos Dll(pos a);
pos Ull(pos a);
pos Uul(pos a);
bool Check (pos a);


class cell
{
private:
    pos Position;
    int step;
    methods avalabel_metods[9];
    int next_metod;

public:
    cell();
    void SetPosition (int xx, int yy);
    void SetPosition (pos pp);
    void Clear_cell();
    void Swith_cell(int st);
    bool Is_empty() {return step==0;}
    int X() {return Position.x;}
    int Y() {return Position.y;}
    const int Step()const {return step;}
    void complete_av_metods ();
    void transposition ();
    void Showcell() const;
    void Showmetohods () const;
    const int Giv_method ();
    const methods select_metod (int n);


};


#endif // CELL_H
