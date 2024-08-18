#include <iostream>
#include <ctime>
using namespace std;
char bang[3][3];
const char ki_tu_nguoi_chs='O';
const char ki_tu_may_tinh='X';
char ki_hieu_nguoi_chien_thang;
void in_bang()
{
    cout<<' '<<bang[0][0]<<' '<<"| "<<bang[0][1]<<" |"<<' '<<bang[0][2]<<' '<<"\n";
    cout<<"---"<<"|"<<"---"<<"|"<<"---"<<"\n";
    cout<<' '<<bang[1][0]<<' '<<"| "<<bang[1][1]<<" |"<<' '<<bang[1][2]<<' '<<"\n";
    cout<<"---"<<"|"<<"---"<<"|"<<"---"<<"\n";
    cout<<' '<<bang[2][0]<<' '<<"| "<<bang[2][1]<<" |"<<' '<<bang[2][2]<<' '<<"\n";
}
void reset_bang()
{
    for (int i = 0; i < sizeof(bang)/sizeof(bang[0]); i++)
    {
        for (int j = 0; j < sizeof(bang[0])/sizeof(char); j++)
        {
            bang[i][j]=' ';
        }
    }
    
}
void luot_nguoi_chs()
{
    cout<<"Lượt của fen:\n";
    int x,y;
    do
    {
        do
        {
            cout<<"Nhập số hàng ô cần đánh: ";
            cin>>x;
            x--;
        } while (x!=2 && x!=1 && x!=0);
        do
        {
            cout<<"Nhập số cột ô cần đánh: ";
            cin>>y;
            y--;
        } while (y!=2 && y!=1 && y!=0);
        if (bang[x][y]==' ')
        {
            bang[x][y]=ki_tu_nguoi_chs;
            break;
        }
        else if (bang[x][y]==ki_tu_may_tinh || bang[x][y]==ki_tu_nguoi_chs)
        {
            cout<<"Ô này đã được đi rùi, vui lòng nhập lại\n";
        }
    } while (bang[x][y]!=' ');
}
void luot_may_tinh()
{
    srand(time(NULL));
    int m=(rand()%3);
    int n=(rand()%3);
    do
    {
        if (bang[m][n]==' ' )
        {
            bang[m][n]=ki_tu_may_tinh;
            break;
        }
        else
        {
            int m = rand()%3;
            int n = rand()%3;
            if (bang[m][n]==' ' )
            {
                bang[m][n]=ki_tu_may_tinh;
                break;
            }
        }
    } while (bang[m][n]!=' ');
}   
bool check_khong_gian_trong()
{
    int khong_gian_trong=(sizeof(bang)/sizeof(bang[0]))*(sizeof(bang[0])/sizeof(char));
    for (int i = 0; i < sizeof(bang)/sizeof(bang[0]); i++)
    {
        for (int j = 0; j < sizeof(bang[0])/sizeof(char); j++)
        {
            if (bang[i][j]!=' ')
            {
                khong_gian_trong--;
            }
        }
    }
    if (khong_gian_trong==0)
    {
        return false;
    }
    else
    { 
        return true;
    }
}
bool quyet_dinh_co_nguoi_chien_thang()
{
    //theo hàng chéo
    if (bang[0][0]==ki_tu_nguoi_chs && bang[1][1]==ki_tu_nguoi_chs && bang[2][2]==ki_tu_nguoi_chs)
    {
        ki_hieu_nguoi_chien_thang=ki_tu_nguoi_chs;
        return true;
    }
    else if (bang[0][0]==ki_tu_may_tinh && bang[1][1]==ki_tu_may_tinh && bang[2][2]==ki_tu_may_tinh)
    {
        ki_hieu_nguoi_chien_thang=ki_tu_may_tinh;
        return true;
    }
    else if (bang[0][2]==ki_tu_nguoi_chs && bang[1][1]==ki_tu_nguoi_chs && bang[2][0]==ki_tu_nguoi_chs)
    {
        ki_hieu_nguoi_chien_thang=ki_tu_nguoi_chs;
        return true;
    }
    else if (bang[0][2]==ki_tu_may_tinh && bang[1][1]==ki_tu_may_tinh && bang[2][0]==ki_tu_may_tinh)
    {
        ki_hieu_nguoi_chien_thang=ki_tu_may_tinh;
        return true;
    }
    
    //theo hàng ngang //theo hàng dọc
    for (int i = 0; i < sizeof(bang)/sizeof(bang[0]); i++)
    {
        if (bang[i][0]==ki_tu_nguoi_chs && bang[i][1]==ki_tu_nguoi_chs && bang[i][2]==ki_tu_nguoi_chs)
        {
            ki_hieu_nguoi_chien_thang=ki_tu_nguoi_chs;
            return true;
            break;
        }
        else if (bang[i][0]==ki_tu_may_tinh && bang[i][1]==ki_tu_may_tinh && bang[i][2]==ki_tu_may_tinh)
        {
            ki_hieu_nguoi_chien_thang=ki_tu_may_tinh;
            return true;
            break;
        }
        else if (bang[0][i]==ki_tu_nguoi_chs && bang[1][i]==ki_tu_nguoi_chs && bang[2][i]==ki_tu_nguoi_chs)
        {
            ki_hieu_nguoi_chien_thang=ki_tu_nguoi_chs;
            return true;
            break;
        }
        else if (bang[0][i]==ki_tu_may_tinh && bang[1][i]==ki_tu_may_tinh && bang[2][i]==ki_tu_may_tinh)
        {
            ki_hieu_nguoi_chien_thang=ki_tu_may_tinh;
            return true;
            break;
        }
    }
    return false;
}
void in_ra_nguoi_chien_thang(char ki_tu_nguoi_chien_thang)
{
    if (ki_tu_nguoi_chien_thang==ki_tu_may_tinh)
    {
        cout<<"Sorry fen bạn thua máy tính rùi:///\n";
    }
    else if (ki_tu_nguoi_chien_thang==ki_tu_nguoi_chs)
    {
        cout<<"Gút chóp fen bạn thắng rùi!!!!!\n";
    }
}    
int main()
{
    char phan_hoi;
    do
    {
        reset_bang();
        in_bang();
    do
    {
        if (check_khong_gian_trong()==false && quyet_dinh_co_nguoi_chien_thang()==false)
        {
            cout<<"Hòa rùi fen :D\n";
            break;
        }
        else if (quyet_dinh_co_nguoi_chien_thang()==true && ki_hieu_nguoi_chien_thang==ki_tu_nguoi_chs)
        {
            break;
        }
        else if (quyet_dinh_co_nguoi_chien_thang()==true && ki_hieu_nguoi_chien_thang==ki_tu_may_tinh)
        {
            break;
        }
        luot_nguoi_chs();
        in_bang();
        if (check_khong_gian_trong()==false && quyet_dinh_co_nguoi_chien_thang()==false)
        {
            cout<<"Hòa rùi fen :D\n";
            break;
        }
        if (quyet_dinh_co_nguoi_chien_thang()==true && ki_hieu_nguoi_chien_thang==ki_tu_nguoi_chs)
        {
            break;
        }
        else if (quyet_dinh_co_nguoi_chien_thang()==true && ki_hieu_nguoi_chien_thang==ki_tu_may_tinh)
        {
            break;
        }
        cout<<"Lượt của máy tính: \n";
        luot_may_tinh();
        in_bang();
    }
    while (check_khong_gian_trong()==true && quyet_dinh_co_nguoi_chien_thang()==false);
    in_ra_nguoi_chien_thang(ki_hieu_nguoi_chien_thang);
    do
    {
        cout<<"Bạn muốn chs lại ko fen? YES (Y) OR NO(N) ONLY: ";
        cin>>phan_hoi;
    } while (phan_hoi!='Y' && phan_hoi!='N');
    } while (phan_hoi=='Y');
    cout<<"Cảm ơn fen vì đã dành thời gian chs nhé!!!";
    return 0;
}
