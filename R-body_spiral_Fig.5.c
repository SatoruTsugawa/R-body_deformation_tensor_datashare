#include <stdio.h>
#include <stdlib.h>
#include <math.h>
//#define R1 159
#define R1 200
//#define t 13.1
//#define t 5.0
#define R2 56.5
//#define H 231
#define H 200
//#define a 0.301
//#define b -4417.3
//#define g 1.0
//#define Rc 159
#define Rc 200
//#define rc 56.5
#define rc 100
#define _USE_MATH_DEFINES

int main(void){

FILE *file1;
char filename1[100];
//sprintf(filename1,"Fig.5c.txt");
//sprintf(filename1,"Fig.5d.txt");
//sprintf(filename1,"Fig.5e.txt");
//sprintf(filename1,"Fig.5f.txt");
sprintf(filename1,"Fig.5i.txt");
file1 = fopen(filename1,"w");

int i,j,k,zzz,ttt,sss,s,ggg,mmm,kkk,KKK,KK,PH;
double t,g,m,k1,K,K1,ph,al,alpha;
//for(ttt=0;ttt<=50;ttt++){ 
//t=ttt*0.2;
t=10;
//for(ggg=0;ggg<=50;ggg++){ 
//g=1.0+ggg*0.005;
g=1.0;
//for(mmm=0;mmm<=50;mmm++){ 
//m=1.0+mmm*0.005;
m=1.0;
//for(kkk=0;kkk<=50;kkk++){ 
//k1=1.0+kkk*0.005;
k1=1.0;

//for(sss=0;sss<=50;sss++){ 
//s=150+sss;
s=200;

//for(KKK=0;KKK<=50;KKK++){ 
//K=50+KKK;
K=50;

//for(KK=0;KK<=50;KK++){ 
//K1=KK;
K1=1.0;

for(PH=0;PH<50;PH++){ 
ph=(M_PI/2.0)*PH/50.0;


/*FILE *file1;
char filename1[100];
sprintf(filename1,"test1.txt");
file1 = fopen(filename1,"w");
FILE *file2;
char filename2[100];
sprintf(filename2,"test2.txt");
file2 = fopen(filename2,"w");
FILE *file3;
char filename3[100];
sprintf(filename3,"test-dXdYdZ.txt");
file3 = fopen(filename3,"w");
FILE *file4;
char filename4[100];
sprintf(filename4,"test-dxdydz.txt");
file4 = fopen(filename4,"w");
*/


FILE *file50;
char filename50[100];
sprintf(filename50,"movie-particle-shapein-t0-phi=20.txt");
file50 = fopen(filename50,"w");
FILE *file51;
char filename51[100];
sprintf(filename51,"movie-particle-shapeout-t0-phi=20.txt");
file51 = fopen(filename51,"w");
FILE *file5;
char filename5[100];
sprintf(filename5,"movie-particle-shapein-t1-phi=20.txt");
file5 = fopen(filename5,"w");
FILE *file55;
char filename55[100];
sprintf(filename55,"movie-particle-shapeout-t1-phi=20.txt");
file55 = fopen(filename55,"w");
FILE *file60;
char filename60[100];
sprintf(filename60,"movie-particle-tangent-vectors-t0-phi=20.txt");
file60 = fopen(filename60,"w");
FILE *file6;
char filename6[100];
sprintf(filename6,"movie-particle-tangent-vectors-t1-phi=20.txt");
file6 = fopen(filename6,"w");

for(zzz=0;zzz<=75;zzz++){ 
//for(zzz=0;zzz<1;zzz++){ 
al=zzz*1.0;
alpha=al*M_PI/180; //角度初期30度，70度
//double al=75;

double R,Theta,Z;
double r,theta,z;
double c,d,e,f;
//printf("%d %d %lf %lf\n",PH,zzz,ph,alpha);
double dR1,dR2,dR3,DR1,DR2,DR3,beta,dTh1,dTh2,dTh3,dZ1,dZ2,dZ3;
double F11,F12,F13,F21,F22,F23,F31,F32,F33;
double dr1,dr2,dr3,dth1,dth2,dth3,dz1,dz2,dz3;

c=g*Rc*cos(alpha)/rc;
d=-m*sin(alpha)/rc;
e=g*Rc*sin(alpha);
f=m*cos(alpha);
int label=0;
int label1=0;
double a=1-(1-0.301)*alpha/(75*M_PI/180);
double b=-4417.3*alpha/(75*M_PI/180);

for(i=0;i<s;i++){ //回転
	Theta=(2*M_PI*i*1.0/(s*1.0)); 
//変形前と変形後の形の出力
/*for(j=0;j<6;j++){ //r軸
	R=R1+t*j*1.0/6.0;
	Z=0;
	r=sqrt(a*R*R+b);
	theta=c*Theta+d*Z;
	z=e*Theta+f*Z;
	if(zzz==0)fprintf(file50,"%lf %lf %lf\n",R*cos(Theta),R*sin(Theta),Z);
	if(zzz==150)fprintf(file5,"%lf %lf %lf\n",r*cos(theta),r*sin(theta),z);
	label=label+1;
}*/
/*for(k=0;k<=50;k++){ //z軸
	R=R1+t;
	Z=H*(k/50.0); 
	r=sqrt(a*R*R+b);
	theta=c*Theta+d*Z;
	z=e*Theta+f*Z;
	if(zzz==0)fprintf(file50,"%lf %lf %lf\n",R*cos(Theta),R*sin(Theta),Z);
	if(zzz==150)fprintf(file5,"%lf %lf %lf\n",r*cos(theta),r*sin(theta),z);
	label=label+1;
}*/
/*for(j=0;j<6;j++){ //r軸
	R=R1+t-t*j*1.0/6.0;
	Z=H; 
	r=sqrt(a*R*R+b);
	theta=c*Theta+d*Z;
	z=e*Theta+f*Z;
	if(zzz==0)fprintf(file50,"%lf %lf %lf\n",r*cos(Theta),R*sin(Theta),Z);
	if(zzz==150)fprintf(file5,"%lf %lf %lf\n",r*cos(theta),r*sin(theta),z);
	label=label+1;
}*/
//内側or外側だけ出力
for(k=0;k<=K;k++){ //z軸
//	R=R1;//内側
//	R=R1+(t*K1/50);//外側
	R=R1+t;//外側
	Z=H*(k/(K*1.0)); 
	r=sqrt(a*R*R+b);
//	double phi=20.0*M_PI/180;
	double phi=ph;
	if(k>=1)Theta=4.0*tan(phi)/Rc+Theta;//
	theta=c*Theta+d*Z;
	z=e*Theta+f*Z;

	dR1=1;
	dR2=0;
	dR3=0;
	dTh1=0;
	dTh2=1;
	dTh3=0;
	dZ1=0;
	dZ2=0;
	dZ3=1;
	F11=k1;
	F12=0;
	F13=0;
	F21=0;
	F22=g*cos(alpha);
	F23=-m*sin(alpha);
	F31=0;
	F32=g*sin(alpha);
	F33=m*cos(alpha);
	dr1=F11*dR1+F12*dR2+F13*dR3;
	dr2=F21*dR1+F22*dR2+F23*dR3;
	dr3=F31*dR1+F32*dR2+F33*dR3;
	dth1=F11*dTh1+F12*dTh2+F13*dTh3;
	dth2=F21*dTh1+F22*dTh2+F23*dTh3;
	dth3=F31*dTh1+F32*dTh2+F33*dTh3;
	dz1=F11*dZ1+F12*dZ2+F13*dZ3;
	dz2=F21*dZ1+F22*dZ2+F23*dZ3;
	dz3=F31*dZ1+F32*dZ2+F33*dZ3;
//全体描画
/*	if(zzz==0)fprintf(file50,"%lf %lf %lf\n",R*cos(Theta),R*sin(Theta),Z);
	if(zzz==150)fprintf(file5,"%lf %lf %lf\n",r*cos(theta),r*sin(theta),z);
	if(zzz==0)fprintf(file60,"%lf %lf %lf %d %lf %lf %lf %lf %lf %lf %lf %lf %lf\n",R*cos(Theta),R*sin(Theta),Z,label1,
	dR1*cos(Theta)-dR2*sin(Theta),dR1*sin(Theta)+dR2*cos(Theta),dR3,
	dTh1*cos(Theta)-dTh2*sin(Theta),dTh1*sin(Theta)+dTh2*cos(Theta),dTh3,
	dZ1*cos(Theta)-dZ2*sin(Theta),dZ1*sin(Theta)+dZ2*cos(Theta),dZ3);
	if(zzz==150)fprintf(file6,"%lf %lf %lf %d %lf %lf %lf %lf %lf %lf %lf %lf %lf\n",r*cos(theta),r*sin(theta),z,label1,
	dr1*cos(theta)-dr2*sin(theta),dr1*sin(theta)+dr2*cos(theta),dr3,
	dth1*cos(theta)-dth2*sin(theta),dth1*sin(theta)+dth2*cos(theta),dth3,
	dz1*cos(theta)-dz2*sin(theta),dz1*sin(theta)+dz2*cos(theta),dz3);
*/
//全体描画
	if(zzz==0 && i<=4 && k<=4)fprintf(file50,"%lf %lf %lf\n",R*cos(Theta),R*sin(Theta),Z);
	double Xin1=R*cos(Theta);
	double Yin1=R*sin(Theta);
	double Zin1=Z;
	double Xin3=R*cos(Theta);
	double Yin3=R*sin(Theta);
	double Zin3=Z+(1.0/(K*1.0));
	double Xin2=Xin1+R*(2*M_PI*1.0/(s*1.0))*(dTh1*cos(Theta)-dTh2*sin(Theta));
	double Yin2=Yin1+R*(2*M_PI*1.0/(s*1.0))*(dTh1*sin(Theta)+dTh2*cos(Theta));
	double Zin2=Zin1+R*(2*M_PI*1.0/(s*1.0))*dTh3;
	double Xout1=Xin1+t*(dR1*cos(Theta)-dR2*sin(Theta));
	double Yout1=Yin1+t*(dR1*sin(Theta)+dR2*cos(Theta));
	double Zout1=Zin1+t*dR3;
	double Xout2=Xin2+t*(dR1*cos(Theta+2*M_PI*1.0/(s*1.0))-dR2*sin(Theta+2*M_PI*1.0/(s*1.0)));
	double Yout2=Yin2+t*(dR1*sin(Theta+2*M_PI*1.0/(s*1.0))+dR2*cos(Theta+2*M_PI*1.0/(s*1.0)));
	double Zout2=Zin2+t*dR3;

	double Lin=sqrt((Xin1-Xin2)*(Xin1-Xin2)+(Yin1-Yin2)*(Yin1-Yin2)+(Zin1-Zin2)*(Zin1-Zin2));
	double Lout=sqrt((Xout1-Xout2)*(Xout1-Xout2)+(Yout1-Yout2)*(Yout1-Yout2)+(Zout1-Zout2)*(Zout1-Zout2));
	if(zzz==0 && i<=4 && k<=4)fprintf(file51,"%lf %lf %lf\n",Xout1,Yout1,Zout1);
//	if(zzz==0 && i<=0 && k<=0)fprintf(file1,"%lf %lf %lf %lf\n",R*2*M_PI*1.0/(s*1.0),t,Lin,Lout);
	double xin1=r*cos(theta);
	double yin1=r*sin(theta);
	double zin1=z;
	double xin3=r*cos(theta)+(1.0/(K*1.0))*(dz1*cos(theta)-dz2*sin(theta));
	double yin3=r*sin(theta)+(1.0/(K*1.0))*(dz1*sin(theta)+dz2*cos(theta));
	double zin3=z+(1.0/(K*1.0))*dz3;
	double xin2=xin1+R*(2*M_PI*1.0/(s*1.0))*(dth1*cos(theta)-dth2*sin(theta));
	double yin2=yin1+R*(2*M_PI*1.0/(s*1.0))*(dth1*sin(theta)+dth2*cos(theta));
	double zin2=zin1+R*(2*M_PI*1.0/(s*1.0))*dth3;
	double xout1=xin1+t*(K1/50.0)*(dr1*cos(theta)-dr2*sin(theta));
	double yout1=yin1+t*(K1/50.0)*(dr1*sin(theta)+dr2*cos(theta));
	double zout1=zin1+t*(K1/50.0)*dr3;
	double lin=sqrt((xin1-xin2)*(xin1-xin2)+(yin1-yin2)*(yin1-yin2)+(zin1-zin2)*(zin1-zin2));
	double Din=sqrt((Xin1-Xin3)*(Xin1-Xin3)+(Yin1-Yin3)*(Yin1-Yin3)+(Zin1-Zin3)*(Zin1-Zin3));
	double din=sqrt((xin1-xin3)*(xin1-xin3)+(yin1-yin3)*(yin1-yin3)+(zin1-zin3)*(zin1-zin3));
	double tt0=t*(K1/50.0);
	double tt1=sqrt((xin1-xout1)*(xin1-xout1)+(yin1-yout1)*(yin1-yout1)+(zin1-zout1)*(zin1-zout1));
	double vec1x=xin1;
	double vec1y=yin1;
	double vec1z=zin1;
	double vec2x=R*(2*M_PI*1.0/(s*1.0))*(dth1*cos(theta)-dth2*sin(theta));
	double vec2y=R*(2*M_PI*1.0/(s*1.0))*(dth1*sin(theta)+dth2*cos(theta));
	double vec2z=R*(2*M_PI*1.0/(s*1.0))*dth3;
	double sq1=sqrt(vec1x*vec1x+vec1y*vec1y+vec1z*vec1z);
	double sq2=sqrt(vec2x*vec2x+vec2y*vec2y+vec2z*vec2z);
	double phi1=acos((vec1x*vec2x+vec1y*vec2y+vec1z*vec2z)/(sq1*sq2));
//	if(zzz==0 && i<=0 && k<=0)fprintf(file1,"%lf %lf %lf %lf\n",R*2*M_PI*1.0/(s*1.0),g,Lin,lin);
//	if(zzz==0 && i<=0 && k<=0)fprintf(file1,"%lf %lf %lf %lf\n",H*1.0/(K*1.0),m,Din,din);
//	if(zzz==0 && i<=0 && k<=0)fprintf(file1,"%lf %lf %lf %lf\n",t*(K1/50.0),k1,tt0,tt1);
	if(i<=0 && k==1)fprintf(file1,"%d %lf %lf %lf %lf %lf\n",PH,alpha,phi,phi1,alpha,sq1);
	
	if(zzz==75 && i<=4 && k<=4)fprintf(file5,"%lf %lf %lf\n",r*cos(theta),r*sin(theta),z);
	if(zzz==75 && i<=4 && k<=4)fprintf(file55,"%lf %lf %lf\n",r*cos(theta)+t*(dr1*cos(theta)-dr2*sin(theta)),r*sin(theta)+t*(dr1*sin(theta)+dr2*cos(theta)),z+t*dr3);
	if(zzz==0 && i<=4 && k<=4)fprintf(file60,"%lf %lf %lf %d %lf %lf %lf %lf %lf %lf %lf %lf %lf\n",R*cos(Theta),R*sin(Theta),Z,label1,
	t*(dR1*cos(Theta)-dR2*sin(Theta)),t*(dR1*sin(Theta)+dR2*cos(Theta)),t*dR3,
	R*(2*M_PI*1.0/200.0)*(dTh1*cos(Theta)-dTh2*sin(Theta)),R*(2*M_PI*1.0/200.0)*(dTh1*sin(Theta)+dTh2*cos(Theta)),R*(2*M_PI*1.0/200.0)*dTh3,
	4*(dZ1*cos(Theta)-dZ2*sin(Theta)),4*(dZ1*sin(Theta)+dZ2*cos(Theta)),4*dZ3);
	if(zzz==75 && i<=4 && k<=4)fprintf(file6,"%lf %lf %lf %d %lf %lf %lf %lf %lf %lf %lf %lf %lf\n",r*cos(theta),r*sin(theta),z,label1,
	t*(dr1*cos(theta)-dr2*sin(theta)),t*(dr1*sin(theta)+dr2*cos(theta)),t*dr3,
	R*(2*M_PI*1.0/200.0)*(dth1*cos(theta)-dth2*sin(theta)),R*(2*M_PI*1.0/200.0)*(dth1*sin(theta)+dth2*cos(theta)),R*(2*M_PI*1.0/200.0)*dth3,
	4*(dz1*cos(theta)-dz2*sin(theta)),4*(dz1*sin(theta)+dz2*cos(theta)),4*dz3);

	label1=label1+1;
}

}
//if(zzz==0)fprintf(file50,"\n");
//fprintf(file50,"\n\n");
//fprintf(file5,"\n\n");
//fprintf(file60,"\n\n");
//fprintf(file6,"\n\n");

}//zzzのおわり

fclose(file50);
fclose(file51);
fclose(file5);
fclose(file55);
fclose(file60);
fclose(file6);

//}//sssの終わり
//}//tttの終わり
}//PHの終わり
fclose(file1);

return 0;
}


