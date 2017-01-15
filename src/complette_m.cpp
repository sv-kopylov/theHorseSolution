#include "cell.h"
#include <iostream>

const methods cell::select_metod (int n)
{
    return avalabel_metods[n];

}

void cell::transposition ()
{
    pos a;
    pos tmp = Position;
    int step_rating[9] = {0};
    int i=0;
    while (select_metod(i)<nopass)
    {

        switch (select_metod(i))
        {
        case uur:
            a=(Uur(tmp));
            break;
        case urr:
            a=(Urr(tmp));
            break;
        case drr:
            a=(Drr(tmp));
            break;
        case ddr:
            a=(Ddr(tmp));
            break;
        case ddl:
            a=(Ddl(tmp));
            break;
        case dll:
            a=(Dll(tmp));
            break;
        case ull:
            a=(Ull(tmp));
            break;
        case uul:
            a=(Uul(tmp));
            break;
        }

        if (((a.x==0)&&(a.y==0))||((a.x==0)&&(a.y==9))||((a.x==9)&&(a.y==0))||((a.x==9)&&(a.y==9)))
        {
            step_rating[i]=10;
        }
        else


            if (((a.x==0)&&(a.y==1))||((a.x==0)&&(a.y==8))||((a.x==9)&&(a.y==1))||((a.x==9)&&(a.y==8)))
            {
                step_rating[i]=9;
            }
            else


                if (((a.x==1)&&(a.y==0))||((a.x==8)&&(a.y==9))||((a.x==1)&&(a.y==9))||((a.x==8)&&(a.y==0)))
                {
                    step_rating[i]=9;
                }
                else


                    if ((a.x==0)||(a.y==9)||(a.x==9)||(a.y==0))
                    {
                        step_rating[i]=8;
                    }
                    else


                        if (((a.x==1)&&(a.y==1))||((a.x==1)&&(a.y==8))||((a.x==8)&&(a.y==1))||((a.x==8)&&(a.y==8)))
                        {
                            step_rating[i]=8;
                        }
                        else


                            if ((a.x==1)||(a.y==1)||(a.x==8)||(a.y==8))
                            {
                                step_rating[i]=7;
                            }
                            else
                            {
                                step_rating[i]=6;
                            }

        i++;
    }

    methods t_mt;
    int t_rt;
    int cnt;
    bool flag = false;
    int j;
    while(!flag){
            cnt=0;
            for (j=0;j<8;j++)
            if (step_rating[j]<step_rating[j+1]){
                t_rt = step_rating[j];
                step_rating[j]=step_rating[j+1];
                step_rating[j+1]=t_rt;

                t_mt=avalabel_metods[j];
                avalabel_metods[j]=avalabel_metods[j+1];
                avalabel_metods[j+1]=t_mt;


                cnt++;
            }
            if (cnt==0) flag=!flag;


    }



}
