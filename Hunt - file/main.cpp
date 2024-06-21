/*
Indiana Namaul Husnah
5024201061 - Teknik Komputer 2020
*/
#include <iostream>
#include <windows.h>
#include <graphics.h>
#include <math.h>
#include <stdlib.h>
#include <mmsystem.h>
void gameplay(), howtoplay(), beforeplay(),credits();
float scoreK=0;
char score[99];

using namespace std;

class CKapal
{
public:
    float xh,yh,rh;
    float xL;
    float xp, yp;
    float xf, yf, sc;
    float fx=1; float fy=1;

    void initSea(float xsea)
    {
        xL=xsea;
    }

    void GerakKanan(){
        if( GetAsyncKeyState(VK_RIGHT) & 0x8000)
    {
    xh=xh+5; xp=xp+5;
    }
    if( GetAsyncKeyState(VK_LEFT) & 0x8000)
    {
    xh=xh-5; xp=xp-5;
    }
    }

    void sea(){

    int stangle = 50, endangle = 135;
    int stangle2 = 135, endangle2 = 50;
    int radius = 20;
    xL=200;
    setcolor(COLOR(2, 0, 97));
    setfillstyle(SOLID_FILL,COLOR(2, 0, 97));
    for (int xL=0; xL<=700; xL=xL+50){
            arc(xL, 340, stangle, endangle, radius);
    }
    for (int xL=25; xL<=700; xL=xL+50){
            arc(xL, 310, -stangle2, -endangle2, radius);
    }
    floodfill(xL,340,COLOR(2, 0, 97));
}

    void initfish(float xfish, float yfish, float scfish)
    {
        xf=xfish;
        yf=yfish;
        sc=scfish;
    }
    void fish()
{
    float x[25], y[25];
    int i;
    sc=10;
    x[0]=-2.42;y[0]=-0.045;
    x[1]=-2.1494;y[1]=-0.0244;
    x[2]=-2.422;y[2]=0.154;
    x[3]=-2.162;y[3]=0.32;
    x[4]=-1.724;y[4]=0.52;
    x[5]=-1.08;y[5]=0.665;
    x[6]=-0.202;y[6]=0.674;
    x[7]=0.635;y[7]=0.525;
    x[8]=1.28;y[8]=0.24;
    x[9]=1.54;y[9]=0.24;
    x[10]=2.26;y[10]=0.72;
    x[11]=1.925;y[11]=0.035;
    x[12]=2.29;y[12]=-0.46;
    x[13]=1.532;y[13]=-0.184;
    x[14]=1.2933;y[14]=-0.18405;
    x[15]=1.085;y[15]=-0.265;
    x[16]=0.75;y[16]=-0.4;
    x[17]=-0.36;y[17]=-0.555;
    x[18]=-1.385;y[18]=-0.515;
    x[19]=-1.85;y[19]=-0.345;
    x[20]=-2.42;y[20]=-0.045;
    setcolor(COLOR(201, 194, 109));
    setfillstyle(SOLID_FILL,COLOR(201, 194, 109));
    for(i=0;i<20;i++){
        line(x[i]*sc+xf,-y[i]*sc+yf,x[i+1]*sc+xf,-y[i+1]*sc+yf);
    }
    floodfill(0.2*sc+xf,0*sc+yf,COLOR(201, 194, 109));
}

 void fish2()//fish hadap kiri
{
    float x[25], y[25];
    int i;
    sc=10;
    x[0]=2.42;y[0]=0.045;
    x[1]=2.1494;y[1]=0.0244;
    x[2]=2.422;y[2]=-0.154;
    x[3]=2.162;y[3]=-0.32;
    x[4]=1.724;y[4]=-0.52;
    x[5]=1.08;y[5]=-0.665;
    x[6]=0.202;y[6]=-0.674;
    x[7]=-0.635;y[7]=-0.525;
    x[8]=-1.28;y[8]=-0.24;
    x[9]=-1.54;y[9]=-0.24;
    x[10]=-2.26;y[10]=-0.72;
    x[11]=-1.925;y[11]=-0.035;
    x[12]=-2.29;y[12]=0.46;
    x[13]=-1.532;y[13]=0.184;
    x[14]=-1.2933;y[14]=0.18405;
    x[15]=-1.085;y[15]=0.265;
    x[16]=-0.75;y[16]=0.4;
    x[17]=0.36;y[17]=0.555;
    x[18]=1.385;y[18]=0.515;
    x[19]=1.85;y[19]=0.345;
    x[20]=2.42;y[20]=0.045;
    setcolor(COLOR(201, 194, 109));
    setfillstyle(SOLID_FILL,COLOR(201, 194, 109));
    for(i=0;i<20;i++){
        line(x[i]*sc+xf,-y[i]*sc+yf,x[i+1]*sc+xf,-y[i+1]*sc+yf);
    }
    floodfill(0.2*sc+xf,0*sc+yf,COLOR(201, 194, 109));
}

    void gerakfishA()
    {
        xf=xf-fx*2;
        yf=yf-fy*0.2;
        if(xf<-100){
            xf=600;
        }
        if(yf<400){
            fy=-1;
        }
        if(yf>800){
            fy=1;
        }

    }
    void gerakfishB()
    {
        xf=xf-fx*1;
        yf=yf-fy*1;
        if(xf<-100){
            xf=600;
        }
        if(yf<400){
            fy=-1;
        }
        if(yf>800){
            fy=1;
        }
    }
    void gerakfishC()//ke kanan deh
    {
        xf=xf+fx*2;
        yf=yf-fy*0.5;
        //kembali ke asal
        if(xf>800){
            xf=-100;
        }
        if(yf<400){
            fy=-1;
        }
        if(yf>800){
            fy=1;
        }
    }

    void initKapalKN(float xpp, float ypp, float scc){
    xp=xpp;
    yp=ypp;
    sc=scc;

    }
    void KapalKN1(){
    float x0,y0,x1,y1,x2,y2,x3,y3,x4,y4,x5,y5;
    float x6,y6,x7,y7,x8,y8,x9,y9,x10,y10,x11,y11,x12,y12,x13,y13;
    setcolor(COLOR(179, 90, 39));
    //Badan kpl
    x0=-4;y0=2;
    x1=0;y1=1.79;
    x2=4;y2=2;
    x3=3;y3=0;
    x4=-3;y4=0;
    line(x0*sc+xp,-y0*sc+yp,x1*sc+xp,-y1*sc+yp);
    line(x1*sc+xp,-y1*sc+yp,x2*sc+xp,-y2*sc+yp);
    line(x2*sc+xp,-y2*sc+yp,x3*sc+xp,-y3*sc+yp);
    line(x3*sc+xp,-y3*sc+yp,x4*sc+xp,-y4*sc+yp);
    line(x4*sc+xp,-y4*sc+yp,x0*sc+xp,-y0*sc+yp);
    setfillstyle(SOLID_FILL, COLOR(179, 90, 39));
    floodfill(0*sc+xp,-1*sc+yp, COLOR(179, 90, 39));

 //kiri
    setcolor(COLOR(179, 90, 39));
    x0=-4;y0=2;
    x1=-4.2;y1=2.1;
    x2=-4.4;y2=2.2;
    x3=-3.2;y3=0;
    x4=-3;y4=0;
    line(x0*sc+xp,-y0*sc+yp,x1*sc+xp,-y1*sc+yp);
    line(x1*sc+xp,-y1*sc+yp,x2*sc+xp,-y2*sc+yp);
    line(x2*sc+xp,-y2*sc+yp,x3*sc+xp,-y3*sc+yp);
    line(x3*sc+xp,-y3*sc+yp,x4*sc+xp,-y4*sc+yp);
    line(x4*sc+xp,-y4*sc+yp,x0*sc+xp,-y0*sc+yp);
    setfillstyle(SOLID_FILL, COLOR(179, 90, 39));
    floodfill(-3.6*sc+xp,-1.1*sc+yp, COLOR(179, 90, 39));

//kanan
    setcolor(COLOR(179, 90, 39));
    x0=4;y0=2;
    x1=4.2;y1=2.1;
    x2=4.4;y2=2.2;
    x3=3.2;y3=0;
    x4=3;y4=0;
    line(x0*sc+xp,-y0*sc+yp,x1*sc+xp,-y1*sc+yp);
    line(x1*sc+xp,-y1*sc+yp,x2*sc+xp,-y2*sc+yp);
    line(x2*sc+xp,-y2*sc+yp,x3*sc+xp,-y3*sc+yp);
    line(x3*sc+xp,-y3*sc+yp,x4*sc+xp,-y4*sc+yp);
    line(x4*sc+xp,-y4*sc+yp,x0*sc+xp,-y0*sc+yp);
    setfillstyle(SOLID_FILL, COLOR(179, 90, 39));
    floodfill(3.6*sc+xp,-1*sc+yp, COLOR(179, 90, 39));
//tiang
    setcolor(LIGHTGRAY);
    x0=-0.09;y0=1.79;
    x1=-0.09;y1=6;
    x2=0.09;y2=6;
    x3=0.09;y3=1.79;
    line(x0*sc+xp,-y0*sc+yp,x1*sc+xp,-y1*sc+yp);
    line(x1*sc+xp,-y1*sc+yp,x2*sc+xp,-y2*sc+yp);
    line(x2*sc+xp,-y2*sc+yp,x3*sc+xp,-y3*sc+yp);
    line(x3*sc+xp,-y3*sc+yp,x0*sc+xp,-y0*sc+yp);
    setfillstyle(SOLID_FILL, LIGHTGRAY);
    floodfill(0*sc+xp,-3*sc+yp, LIGHTGRAY);
//bndera
    setcolor(COLOR(255, 239, 212));
    x0=0.09;y0=2.2;
    x1=0.2;y1=2.2;
    x2=4;y2=2.2;
    x3=0.2;y3=6;
    x4=0.2;y4=6;
    x5=0.09;y5=6;
    line(x0*sc+xp,-y0*sc+yp,x1*sc+xp,-y1*sc+yp);
    line(x1*sc+xp,-y1*sc+yp,x2*sc+xp,-y2*sc+yp);
    line(x2*sc+xp,-y2*sc+yp,x3*sc+xp,-y3*sc+yp);
    line(x3*sc+xp,-y3*sc+yp,x4*sc+xp,-y4*sc+yp);
    line(x4*sc+xp,-y4*sc+yp,x1*sc+xp,-y1*sc+yp);
    line(x4*sc+xp,-y4*sc+yp,x5*sc+xp,-y5*sc+yp);
    setfillstyle(SOLID_FILL,COLOR(255, 239, 212));
    floodfill(2*sc+xp,-4*sc+yp,COLOR(255, 239, 212));
//circle
    setcolor(BLACK);
    circle(xp-30, yp-24, sc-10);
    circle(xp-30, yp-24, sc-13);
    circle(xp+30, yp-24, sc-10);
    circle(xp+30, yp-24, sc-13);
    circle(xp, yp-22, sc-10);
    circle(xp, yp-22, sc-13);

    }

    void KKE(){
    float x0,y0,x1,y1,x2,y2,x3,y3,x4,y4,x5,y5;
    float x6,y6,x7,y7,x8,y8,x9,y9,x10,y10,x11,y11,x12,y12,x13,y13,x14,y14;
    sc=6.5;

//Kke
    x0=-1.1;y0=5.7;
    x1=-1.9;y1=6.6;
    x2=-3.14;y2=7.1;
    x3=-3.25;y3=5.65;
    x4=-2.9;y4=4.4;
    x5=-1.1;y5=5.7;
    setcolor(COLOR(255, 208, 133));
    //setcolor(WHITE);
    line(x0*sc+xp,-y0*sc+yp,x1*sc+xp,-y1*sc+yp);
    line(x1*sc+xp,-y1*sc+yp,x2*sc+xp,-y2*sc+yp);
    line(x2*sc+xp,-y2*sc+yp,x3*sc+xp,-y3*sc+yp);
    line(x3*sc+xp,-y3*sc+yp,x4*sc+xp,-y4*sc+yp);
    line(x4*sc+xp,-y4*sc+yp,x5*sc+xp,-y5*sc+yp);
    setfillstyle(SOLID_FILL,COLOR(255, 208, 133));
    floodfill(-2.2*sc+xp,-5.14*sc+yp,COLOR(255, 208, 133));

    line(-x0*sc+xp,-y0*sc+yp,-x1*sc+xp,-y1*sc+yp);
    line(-x1*sc+xp,-y1*sc+yp,-x2*sc+xp,-y2*sc+yp);
    line(-x2*sc+xp,-y2*sc+yp,-x3*sc+xp,-y3*sc+yp);
    line(-x3*sc+xp,-y3*sc+yp,-x4*sc+xp,-y4*sc+yp);
    line(-x4*sc+xp,-y4*sc+yp,-x5*sc+xp,-y5*sc+yp);
    setfillstyle(SOLID_FILL,COLOR(255, 208, 133));
    floodfill(2*sc+xp,-5.14*sc+yp,COLOR(255, 208, 133));

    setcolor(COLOR(255, 208, 133));
    x0=0;y0=6;
    x1=-1.1;y1=5.7;
    x2=-1.95;y2=5.25;
    x3=-2.9;y3=4.4;
    x4=-3.47;y4=3.51;
    x5=-3.675;y5=2.75;
    x6=-3.375;y6=1.855;
    x7=-2.76;y7=0.985;
    x8=-1.878;y8=0.246;
    x9=-0.916;y9=0.072;
    x10=0;y10=0;

    line(x0*sc+xp,-y0*sc+yp,x1*sc+xp,-y1*sc+yp);
    line(x1*sc+xp,-y1*sc+yp,x2*sc+xp,-y2*sc+yp);
    line(x2*sc+xp,-y2*sc+yp,x3*sc+xp,-y3*sc+yp);
    line(x3*sc+xp,-y3*sc+yp,x4*sc+xp,-y4*sc+yp);
    line(x4*sc+xp,-y4*sc+yp,x5*sc+xp,-y5*sc+yp);
    line(x5*sc+xp,-y5*sc+yp,x6*sc+xp,-y6*sc+yp);
    line(x6*sc+xp,-y6*sc+yp,x7*sc+xp,-y7*sc+yp);
    line(x7*sc+xp,-y7*sc+yp,x8*sc+xp,-y8*sc+yp);
    line(x8*sc+xp,-y8*sc+yp,x9*sc+xp,-y9*sc+yp);
    line(x9*sc+xp,-y9*sc+yp,x10*sc+xp,-y10*sc+yp);

    line(-x0*sc+xp,-y0*sc+yp,-x1*sc+xp,-y1*sc+yp);
    line(-x1*sc+xp,-y1*sc+yp,-x2*sc+xp,-y2*sc+yp);
    line(-x2*sc+xp,-y2*sc+yp,-x3*sc+xp,-y3*sc+yp);
    line(-x3*sc+xp,-y3*sc+yp,-x4*sc+xp,-y4*sc+yp);
    line(-x4*sc+xp,-y4*sc+yp,-x5*sc+xp,-y5*sc+yp);
    line(-x5*sc+xp,-y5*sc+yp,-x6*sc+xp,-y6*sc+yp);
    line(-x6*sc+xp,-y6*sc+yp,-x7*sc+xp,-y7*sc+yp);
    line(-x7*sc+xp,-y7*sc+yp,-x8*sc+xp,-y8*sc+yp);
    line(-x8*sc+xp,-y8*sc+yp,-x9*sc+xp,-y9*sc+yp);
    line(-x9*sc+xp,-y9*sc+yp,-x10*sc+xp,-y10*sc+yp);
    setfillstyle(SOLID_FILL,COLOR(255, 208, 133));
    floodfill(-0.3*sc+xp,-2.05*sc+yp,COLOR(255, 208, 133));

    //bdn
   // setcolor(COLOR(255, 208, 133));
    x0=-1.878;y0=0.246;
    x1=-2.21;y1=-0.54;
    x2=-2.48;y2=-1.28;
    x3=-2.62;y3=-1.97;
    x4=-2.275;y4=-2.575;
    x5=-1.76;y5=-2.28;
    x6=-1.74;y6=-1.38;
    x7=-1.7;y7=-3.64;
    x8=-1.46;y8=-4.76;
    x9=-1.07;y9=-5.16;
    x10=-0.56;y10=-5.16;
    x11=-0.3;y11=-4.7;
    x12=-0.16;y12=-3.9;
    x13=0;y13= -3.9;
    x14=1.878;y14=0.246;
    line(x0*sc+xp,-y0*sc+yp,x14*sc+xp,-y14*sc+yp);

    line(x0*sc+xp,-y0*sc+yp,x1*sc+xp,-y1*sc+yp);
    line(x1*sc+xp,-y1*sc+yp,x2*sc+xp,-y2*sc+yp);
    line(x2*sc+xp,-y2*sc+yp,x3*sc+xp,-y3*sc+yp);
    line(x3*sc+xp,-y3*sc+yp,x4*sc+xp,-y4*sc+yp);
    line(x4*sc+xp,-y4*sc+yp,x5*sc+xp,-y5*sc+yp);
    line(x5*sc+xp,-y5*sc+yp,x6*sc+xp,-y6*sc+yp);
    line(x5*sc+xp,-y5*sc+yp,x7*sc+xp,-y7*sc+yp);
    line(x7*sc+xp,-y7*sc+yp,x8*sc+xp,-y8*sc+yp);
    line(x8*sc+xp,-y8*sc+yp,x9*sc+xp,-y9*sc+yp);
    line(x9*sc+xp,-y9*sc+yp,x10*sc+xp,-y10*sc+yp);
    line(x10*sc+xp,-y10*sc+yp,x11*sc+xp,-y11*sc+yp);
    line(x11*sc+xp,-y11*sc+yp,x12*sc+xp,-y12*sc+yp);
    line(x12*sc+xp,-y12*sc+yp,x13*sc+xp,-y13*sc+yp);

    line(-x0*sc+xp,-y0*sc+yp,-x1*sc+xp,-y1*sc+yp);
    line(-x1*sc+xp,-y1*sc+yp,-x2*sc+xp,-y2*sc+yp);
    line(-x2*sc+xp,-y2*sc+yp,-x3*sc+xp,-y3*sc+yp);
    line(-x3*sc+xp,-y3*sc+yp,-x4*sc+xp,-y4*sc+yp);
    line(-x4*sc+xp,-y4*sc+yp,-x5*sc+xp,-y5*sc+yp);
    line(-x5*sc+xp,-y5*sc+yp,-x6*sc+xp,-y6*sc+yp);
    line(-x5*sc+xp,-y5*sc+yp,-x7*sc+xp,-y7*sc+yp);
    line(-x7*sc+xp,-y7*sc+yp,-x8*sc+xp,-y8*sc+yp);
    line(-x8*sc+xp,-y8*sc+yp,-x9*sc+xp,-y9*sc+yp);
    line(-x9*sc+xp,-y9*sc+yp,-x10*sc+xp,-y10*sc+yp);
    line(-x10*sc+xp,-y10*sc+yp,-x11*sc+xp,-y11*sc+yp);
    line(-x11*sc+xp,-y11*sc+yp,-x12*sc+xp,-y12*sc+yp);
    line(-x12*sc+xp,-y12*sc+yp,-x13*sc+xp,-y13*sc+yp);
    setfillstyle(SOLID_FILL,COLOR(255, 208, 133));
    floodfill(-0.19290*sc+xp,0.5524*sc+yp,COLOR(255, 208, 133));

    //mt
    x0=-1.74;y0=2.84;
    x1=-1.39;y1=2.79;
    x2=-0.99;y2=2.68;
    x3=-0.816;y3=2.418;
    x4=-1.072;y4=2.248;
    x5=-1.38;y5=2.335;
    x6=-1.47;y6= 2.63;
    setcolor(BLACK);
    line(x0*sc+xp,-y0*sc+yp,x1*sc+xp,-y1*sc+yp);
    line(x1*sc+xp,-y1*sc+yp,x2*sc+xp,-y2*sc+yp);
    line(x2*sc+xp,-y2*sc+yp,x3*sc+xp,-y3*sc+yp);
    line(x3*sc+xp,-y3*sc+yp,x4*sc+xp,-y4*sc+yp);
    line(x4*sc+xp,-y4*sc+yp,x5*sc+xp,-y5*sc+yp);
    line(x5*sc+xp,-y5*sc+yp,x6*sc+xp,-y6*sc+yp);
    line(x6*sc+xp,-y6*sc+yp,x1*sc+xp,-y1*sc+yp);

    line(-x0*sc+xp,-y0*sc+yp,-x1*sc+xp,-y1*sc+yp);
    line(-x1*sc+xp,-y1*sc+yp,-x2*sc+xp,-y2*sc+yp);
    line(-x2*sc+xp,-y2*sc+yp,-x3*sc+xp,-y3*sc+yp);
    line(-x3*sc+xp,-y3*sc+yp,-x4*sc+xp,-y4*sc+yp);
    line(-x4*sc+xp,-y4*sc+yp,-x5*sc+xp,-y5*sc+yp);
    line(-x5*sc+xp,-y5*sc+yp,-x6*sc+xp,-y6*sc+yp);
    line(-x6*sc+xp,-y6*sc+yp,-x1*sc+xp,-y1*sc+yp);

    //alis
    x0=-1.49;y0=3.2928;
    x1=-1.4834;y1=3.4294;
    x2=-0.93;y2=3.52;
    x3=-0.762;y3=3.384;
    line(x0*sc+xp,-y0*sc+yp,x1*sc+xp,-y1*sc+yp);
    line(x1*sc+xp,-y1*sc+yp,x2*sc+xp,-y2*sc+yp);
    line(x2*sc+xp,-y2*sc+yp,x3*sc+xp,-y3*sc+yp);
    line(x3*sc+xp,-y3*sc+yp,x0*sc+xp,-y0*sc+yp);

    line(-x0*sc+xp,-y0*sc+yp,-x1*sc+xp,-y1*sc+yp);
    line(-x1*sc+xp,-y1*sc+yp,-x2*sc+xp,-y2*sc+yp);
    line(-x2*sc+xp,-y2*sc+yp,-x3*sc+xp,-y3*sc+yp);
    line(-x3*sc+xp,-y3*sc+yp,-x0*sc+xp,-y0*sc+yp);
    //:)
    x0=-0.3;y0=2.05;
    x1=-0.1;y1=1.74;
    x2=-0.1;y2=1.43;
    x3=-0.46;y3=1.5;
    x4=-0.49;y4=1.41;
    x5=-0.05;y5=1.31;
    x6=0.36;y6=1.41;
    x7=0.34;y7=1.5;
    x8=0;y8=1.43;
    x9=0;y9=1.74;
    x10=0.2;y10=2.05;

    line(x0*sc+xp,-y0*sc+yp,x1*sc+xp,-y1*sc+yp);
    line(x1*sc+xp,-y1*sc+yp,x2*sc+xp,-y2*sc+yp);
    line(x2*sc+xp,-y2*sc+yp,x3*sc+xp,-y3*sc+yp);
    line(x3*sc+xp,-y3*sc+yp,x4*sc+xp,-y4*sc+yp);
    line(x4*sc+xp,-y4*sc+yp,x5*sc+xp,-y5*sc+yp);
    line(x5*sc+xp,-y5*sc+yp,x6*sc+xp,-y6*sc+yp);
    line(x6*sc+xp,-y6*sc+yp,x7*sc+xp,-y7*sc+yp);
    line(x7*sc+xp,-y7*sc+yp,x8*sc+xp,-y8*sc+yp);
    line(x8*sc+xp,-y8*sc+yp,x9*sc+xp,-y9*sc+yp);
    line(x9*sc+xp,-y9*sc+yp,x10*sc+xp,-y10*sc+yp);
    line(x10*sc+xp,-y10*sc+yp,x0*sc+xp,-y0*sc+yp);

    }


};
float sun(float xS, float yS, float sc)
{
    setcolor(COLOR(255, 111, 0));
    setfillstyle(SOLID_FILL,COLOR(255, 111, 0));
    circle(50+xS,105+yS,30);
    floodfill(50+xS,105+yS,COLOR(255, 111, 0));
}

float moon(float xM, float yM, float sc)
{
    setcolor(DARKGRAY);
    setfillstyle(SOLID_FILL,DARKGRAY);
    circle(50+xM,105+yM,30);
    floodfill(50+xM,105+yM,DARKGRAY);
}

float clouds(float xc, float yc, float sc)
{

    float x[12], y[12];
    int i;
    sc=18;
    //lini lini
    x[0]=-17;y[0]=2;
    x[1]=-19;y[1]=3;
    x[2]=-18.4;y[2]=5;
    x[3]=-17.2;y[3]=6.2;
    x[4]=-14.6;y[4]=5.6;
    x[5]=-14.4;y[5]=4.6;
    x[6]=-13;y[6]=5;
    x[7]=-12;y[7]=4;
    x[8]=-11;y[8]=4;
    x[9]=-10;y[9]=3;
    x[10]=-7;y[10]=2;
    x[11]=-17;y[11]=2;
    setcolor(WHITE);
    setfillstyle(SOLID_FILL,WHITE);
    for(i=0;i<11;i++){
        line(x[i]*sc+xc,-y[i]*sc+yc,x[i+1]*sc+xc,-y[i+1]*sc+yc);
    }
    floodfill(-13*sc+xc,-3*sc+yc,WHITE);

    setcolor(WHITE);
    setfillstyle(SOLID_FILL,WHITE);
    for(i=0; i<11; i++){
        line(-x[i]*sc+xc,-y[i]*sc+yc,-x[i+1]*sc+xc,-y[i+1]*sc+yc);
    }
    floodfill(13*sc+xc,-3*sc+yc,WHITE);

}

float gambar(float xp, float yp, float sc){
    float x0,x1,x2,x3,x4, y0,y1,y2,y3,y4;
    x0=0;y0=2;
    x1=2;y1=2;
    x2=2;y2=0;
    line(x0*sc+xp, -y0*sc+yp, x1*sc+xp,-y1*sc+yp);
    line(x1*sc+xp, -y1*sc+yp, x2*sc+xp, y2*sc+yp);
    line(x0*sc+xp, y0*sc+yp, -x1*sc+xp, y1*sc+yp);
    line(-x1*sc+xp, y1*sc+yp, -x2*sc+xp, y2*sc+yp);
    x0-2;y0=-2;
    x1=2;y1=2;
    line(x0*sc+xp, y1*sc+yp, x1*sc+xp, y2*sc+yp);
    line(x0*sc+xp, -y1*sc+yp, -x1*sc+xp, y2*sc+yp);
    //tambah
    x0=-2;y0=0;
    x1=2;y1=0;
    line(x0*sc+xp, y0*sc+yp, x1*sc+xp,y1*sc+yp);
    x0=0;y0=-2;
    x1=0;y1=2;
    line(x0*sc+xp, y0*sc+yp, x1*sc+xp,y1*sc+yp);

}

void harpoon(float xh, float yh, float sc)
    {
    float x[5], y[5];
    int i;
    sc=10;
    x[0]=1.4;y[0]= 8.45;
    x[1]=1.75;y[1]= 8.15;
    x[2]=-9.4;y[2]=-5.85;
    x[3]=-9.5;y[3]=-5.75;
    x[4]=1.4;y[4]= 8.45;
    setcolor(COLOR(135, 123, 85));
    setfillstyle(SOLID_FILL, COLOR(135, 123, 85));
    for(i=0;i<4;i++){
        line(x[i]*sc+xh,-y[i]*sc+yh,x[i+1]*sc+xh,-y[i+1]*sc+yh);
    }
    floodfill(0.15*sc+xh,-6.5*sc+yh,COLOR(135, 123, 85));
    }
void fishe(float xf, float yf, float sc){
    float x[25], y[25];
    int i;
    sc=20;
    x[0]=-2.42;y[0]=-0.045;
    x[1]=-2.1494;y[1]=-0.0244;
    x[2]=-2.422;y[2]=0.154;
    x[3]=-2.162;y[3]=0.32;
    x[4]=-1.724;y[4]=0.52;
    x[5]=-1.08;y[5]=0.665;
    x[6]=-0.202;y[6]=0.674;
    x[7]=0.635;y[7]=0.525;
    x[8]=1.28;y[8]=0.24;
    x[9]=1.54;y[9]=0.24;
    x[10]=2.26;y[10]=0.72;
    x[11]=1.925;y[11]=0.035;
    x[12]=2.29;y[12]=-0.46;
    x[13]=1.532;y[13]=-0.184;
    x[14]=1.2933;y[14]=-0.18405;
    x[15]=1.085;y[15]=-0.265;
    x[16]=0.75;y[16]=-0.4;
    x[17]=-0.36;y[17]=-0.555;
    x[18]=-1.385;y[18]=-0.515;
    x[19]=-1.85;y[19]=-0.345;
    x[20]=-2.42;y[20]=-0.045;
    setcolor(COLOR(201, 194, 109));
    setfillstyle(SOLID_FILL,COLOR(201, 194, 109));
    for(i=0;i<20;i++){
        line(x[i]*sc+xf,-y[i]*sc+yf,x[i+1]*sc+xf,-y[i+1]*sc+yf);
    }
    floodfill(0.2*sc+xf,0*sc+yf,COLOR(201, 194, 109));
}

void loadscreen()
{
    settextstyle(8,0,1);
    outtextxy(180,250, "loading");
    circle(180,300,4);
        for(int i = 0; i<200; i+=2)
        {
            setcolor(COLOR(209, 227, 255));
            circle(180+i,300,4);

            if(i>80)
            {
                setcolor(WHITE);
                outtextxy(180,250,"loading .");
            }
            if(i>130)
            {
                setcolor(WHITE);
                outtextxy(180,250,"loading . .");
            }
            if(i>180)
            {
                setcolor(WHITE);
                outtextxy(180,250,"loading . . .");
            }
            delay(40);
        }
    cleardevice();
}

void mainmenu(){

    while(1){

    rectangle(0,0,600,700);
    setfillstyle(SOLID_FILL,COLOR(209, 227, 255));
    floodfill(100,100,COLOR(209, 227, 255));
    int mouse_x, mouse_y;
    mouse_x=mousex();
    mouse_y=mousey();
    setcolor(BLACK);
    setbkcolor(COLOR(209, 227, 255));
    settextstyle(3,0,8);
    outtextxy(205,70,"HUNT");
    settextstyle(3,0,3);
    outtextxy(280,185,"play");
    outtextxy(255,285,"how to play");
    outtextxy(275,385,"credit");
    outtextxy(285,485,"exit");
    rectangle(180,170,420,230);
    rectangle(180,270,420,330);
    rectangle(180,370,420,430);
    rectangle(180,470,420,530);

    if((mouse_y>170)&&(mouse_y<230)&&(mouse_x>180)&&(mouse_x<420))
    {
        if(ismouseclick(WM_LBUTTONDOWN))
        {
            cleardevice();
            beforeplay();
            gameplay();
            clearmouseclick(WM_LBUTTONDOWN);
        }
    }
    if((mouse_y>270)&&(mouse_y<330)&&(mouse_x>180)&&(mouse_x<420))
    {
        if(ismouseclick(WM_LBUTTONDOWN))
        {
            cleardevice();
            howtoplay();
            clearmouseclick(WM_LBUTTONDOWN);
        }
    }

     if((mouse_y>370)&&(mouse_y<430)&&(mouse_x>180)&&(mouse_x<420))
    {
        if(ismouseclick(WM_LBUTTONDOWN))
        {
            cleardevice();
            credits();
            clearmouseclick(WM_LBUTTONDOWN);
        }
    }

    if((mouse_y>470)&&(mouse_y<530)&&(mouse_x>180)&&(mouse_x<420))
    {
        if(ismouseclick(WM_LBUTTONDOWN))
        {
            closegraph();
            exit(0);
            clearmouseclick(WM_LBUTTONDOWN);
            break;
        }
    }
    }

}

void howtoplay(){
    cleardevice();

    while(1){
            setcolor(BLACK);
        CKapal KPHowtoplay;
        //setcolor(WHITE);
        settextstyle(3,0,8);
        outtextxy(138,50,"how to play");
        settextstyle(3,0,3);
        outtextxy(50,185,"press right arrow key -> to moving your boat");
        outtextxy(50,215,"press left arrow key <- to moving your boat");
        outtextxy(50,245,"press space bar to start hunting!");

        KPHowtoplay.initKapalKN(400,600,20);
        KPHowtoplay.KapalKN1();

        setcolor(WHITE);
        gambar(295, 470, 1);
        gambar(345, 500, 1);
        gambar(395, 470, 1);
        gambar(445, 500, 1);
        gambar(495, 470, 1);
        gambar(545, 500, 1);
         if(GetAsyncKeyState(27)<0)
        {
            cleardevice();
            clearmouseclick(WM_LBUTTONDOWN);
            return mainmenu();
        }
    }


}

void credits(){
    cleardevice();
    readimagefile("logo.jpg",300,400,500,600);
    while(1){
    setcolor(BLACK);
    settextstyle(3,0,8);
    outtextxy(185,50,"credits");
    settextstyle(3,0,3);
    outtextxy(50,185,"Indiana Namaul Husnah");
    outtextxy(50,215,"5024201061");
    outtextxy(50,245,"Teknik Komputer 2020");
    outtextxy(50,275,"Institut Teknologi Sepuluh Nopember");


    if(GetAsyncKeyState(27)<0)
        {
            cleardevice();
            clearmouseclick(WM_LBUTTONDOWN);
            return mainmenu();
        }
}
}
void beforeplay(){
    cleardevice();
    while(1){
        settextstyle(3,0,3);
        outtextxy(130,185,"get as many fish as possible overnight!");
        outtextxy(180,215,"press space to start game");
    if (GetAsyncKeyState(VK_SPACE) & 0x8000)
        {
            cleardevice();
            clearmouseclick(WM_LBUTTONDOWN);
            gameplay();
        }
    if(GetAsyncKeyState(27)<0)
        {
            cleardevice();
            clearmouseclick(WM_LBUTTONDOWN);
            return mainmenu();
        }
}
}


void gameover(){
        sndPlaySound("gameova.wav",SND_ASYNC|SND_LOOP);
        setbkcolor(COLOR(209, 227, 255));
        cleardevice();
        int page=0;
        setactivepage(page);
        setvisualpage(page);
        while(1){
        setcolor(BLACK);
        settextstyle(3,0,3);
        outtextxy(245,185,"time's up");
        settextstyle(3,0,3);
        outtextxy(240, 215, score);
        settextstyle(3,0,3);
        outtextxy(185,245,"press esc to main menu");
        setcolor(BLACK);
        if(scoreK>=10){
            gambar(220, 130, 15);
            gambar(290, 130, 15);
            gambar(360, 130, 15);
        }
        if(scoreK>=5){
            gambar(220, 130, 15);
            gambar(290, 130, 15);
        }
         if(scoreK>=1){

            gambar(220, 130, 15);

        }
        if(GetAsyncKeyState(27)<0)
            {

                cleardevice();
                return mainmenu();
            }

            page=1-page;
        }


}

void gameplay(){

    int page = 0;
    setbkcolor(BLACK);
    float xp,yp,sc;
    float xcl, ycl; xcl = 300; ycl = 220;
    float f; f=-1;
    float xMo, yMo; xMo=500; yMo=20;
    float xMs, yMs; xMs=600; yMs=20;

    float xh1, yh1; xh1=160; yh1=300;
    float xh, yh; xh=160, yh=300;
    float bp=0;
    float xff, yff;xff=200;yff=600;
    float xff1, yff1;xff1=600;yff1=600;
    float flagx; flagx=1;
    float flagy; flagy=1;

    float flagx1; flagx1=1;
    float flagy1; flagy1=1;

    CKapal h1, h2, sea1, fs1, fs2, fs3, fs4, KP, KEI;
    sea1.initSea(200);
    KEI.initKapalKN(160,280,6.5);
    KP.initKapalKN(200,330,20);
    //init fish
    fs1.initfish(600,400,20);
    fs2.initfish(666,450,20);
    fs3.initfish(566,500,20);
    fs4.initfish(599,550,20);;

    while(1){
    setactivepage(page);
    setvisualpage(1-page);
    cleardevice();

    sea1.sea();
    harpoon(xh, yh, sc); harpoon(xh1, yh1, sc);
    KEI.KKE(); KEI.GerakKanan();
    KP.KapalKN1(); KP.GerakKanan();
    fishe(xff, yff, sc); fishe(xff1, yff1, sc);

    fs1.fish(); fs1.gerakfishA();
    fs2.fish2(); fs2.gerakfishC();
    fs3.fish(); fs3.gerakfishB();
    fs4.fish2(); fs4.gerakfishC();


    //score
    setcolor(WHITE);
    settextstyle(3,0,3);
    outtextxy(10, 10, score); // ambil score dari array score[99]
    sprintf(score,"score = %.f", scoreK); //tampilkan score dari scoreK

    setcolor(WHITE);
    gambar(100, 70, 1); gambar(150, 80, 1); gambar(200, 90, 1);
    gambar(350, 50, 1); gambar(400, 70, 1); gambar(450, 80, 1);

    clouds(xcl, ycl, sc);
        xcl=xcl+f*0.4; //0.4
        if(xcl>310){
            f=-1;
        }
        if(xcl<290){
            f=1;
        }
    moon(xMo, yMo, sc);
        xMo=xMo-0.4; //30. 0.4
        if(xMo<-100){
            sun(450, yMs, sc);
            xMs=xMs-1;
            setbkcolor(COLOR(38, 74, 255));
        }

    //shoot
    if(GetAsyncKeyState(VK_SPACE) & 0x8000)
        {
            PlaySound(TEXT("water.wav"), NULL, SND_ASYNC);
            xh1=xh;
            yh1=yh;
            bp=1;

        }
    if(bp==1)
        {

        yh1=yh1+6;
        xh1=xh1-5;
        if((xh1>0.42*20+xff)&&(xh1<6.29*20+xff)&&(yh1>-0.024*20+yff)&&(yh1<0.665*20+yff))
        {
            xff=700;
            yff=700;
            scoreK+=1;
        }
        if((xh1>0.42*20+xff1)&&(xh1<6.29*20+xff1)&&(yh1>-0.024*20+yff1)&&(yh1<0.665*20+yff1))
        {
            xff1=900;
            yff1=800;
            scoreK+=1;
        }
    }

    if( GetAsyncKeyState(VK_RIGHT) & 0x8000)
    {
    xh=xh+5;
    }
    if( GetAsyncKeyState(VK_LEFT) & 0x8000)
    {
    xh=xh-5;
    }

        xff=xff-flagx*7;
        yff=yff-flagy*0.5;
        if(xff<-100){
            xff=900;
        }
        if(yff<400){
            flagy=-1;
        }
        if(yff>800){
            flagy=1;
        }

        xff1=xff1-flagx1*5;
        yff1=yff1+flagy1*2;
        if(xff1<-100){
            xff1=800;
        }
        if(yff1<400){
            flagy1=1;
        }
        if(yff1>800){
            flagy1=-1;
        }
    //gameover
    if(xMo<-140){
        cleardevice();
        setbkcolor(BLACK);
        gameover();
         if(GetAsyncKeyState(27)<0)
            {
                cleardevice();
                return mainmenu();
            }

        }
    delay(20);
    page = 1-page;
    }

}

int main(){

    initwindow(600,700, "HUNT");
    loadscreen();
    sndPlaySound("gameplay.wav",SND_ASYNC|SND_LOOP);
    mainmenu();
    gameplay();

}

