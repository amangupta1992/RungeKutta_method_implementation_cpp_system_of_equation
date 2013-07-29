#include<iostream.h>
#include<conio.h>
int main()
{//ay''+by'+cy=dx+e
//intial and final value of xi and xf and h
//intial value of y and y' 
    float a,b,c,d,e,xi,xf,h,y0,yd0;
    float k11,k21,k31,k41,k12,k22,k32,k42;
float y[10][2];
int ny;
    cout<<"WELCOME TO RUNGE KUTTA METHOD";
    cout<<endl;
    cout<<"ay''+by'+cy=dx+e";
    cout<<endl;
    cin>>a>>b>>c>>d>>e;
    cout<<"intial and final value of xi and xf and h";
    cout<<endl;
    cin>>xi>>xf>>h;
    cout<<"intial value of y and y'";
    cout<<endl;
    cin>>y0>>yd0;
    ny=(xf-xi)/h;    
    k11=h*yd0;
    k12=h*(d*xi + e - (c*y0) - (b*yd0));
    k21=h*(yd0+(k12/2));
    k22=h*(d*(xi+h/2) + e - (c*(y0+k11/2)) - (b*(yd0+k12/2)));
    k31=h*(yd0+k22/2);
    k32=h*(d*(xi+h/2) + e - (c*(y0+k21/2)) - (b*(yd0+k22/2)));
    k41=h*(yd0+k32);
    k42=h*(d*(xi+h) + e - (c*(y0+k31)) - (b*(yd0+k32)));
    cout<<"k11= "<<k11<<endl;
    cout<<"k12= "<<k12<<endl;
    cout<<"k21= "<<k21<<endl;
    cout<<"k22= "<<k22<<endl;
    cout<<"k31= "<<k31<<endl;
    cout<<"k32= "<<k32<<endl;
    cout<<"k41= "<<k41<<endl;
    cout<<"k42= "<<k42<<endl;
y[0][0]=y0;
y[0][1]=yd0;
for(int i=1;i<=ny;i++)
{
y[i][0]=y[i-1][0]+(k11+2*k21+2*k31+k41)/6;
y[i][1]=y[i-1][1]+(k12+2*k22+2*k32+k42)/6;
xi=xi+h;
k11=h*y[i][1];
    k12=h*(d*xi + e - (c*y[i][0]) - (b*y[i][1]));
    k21=h*(y[i][1]+(k12/2));
    k22=h*(d*(xi+h/2) + e - (c*(y[i][0]+k11/2)) - (b*(y[i][1]+k12/2)));
    k31=h*(y[i][1]+k22/2);
    k32=h*(d*(xi+h/2) + e - (c*(y[i][0]+k21/2)) - (b*(y[i][1]+k22/2)));
    k41=h*(y[i][1]+k32);
    k42=h*(d*(xi+h) + e - (c*(y[i][0]+k31)) - (b*(y[i][1]+k32)));
    
}

cout<<"the final result is:"<<y[ny][0]<<","<<y[ny][1];

getch();
    return 0;
    }
