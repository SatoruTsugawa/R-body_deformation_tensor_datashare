#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define R1 150
#define t 10
#define R2 100
#define H 200.0
#define g 1.0
#define Rc 200
#define rc 100
#define _USE_MATH_DEFINES

int main(void){

int i,j,k,zzz;

FILE *file5;
char filename5[100];
sprintf(filename5,"Fig.3c.txt");
file5 = fopen(filename5,"w");
FILE *file6;
char filename6[100];
sprintf(filename6,"Fig.3i.txt");
file6 = fopen(filename6,"w");



for(zzz=0;zzz<=600;zzz++){ 
double a=-(1.0/1200.0)*(zzz-1200);
double b=-(50.0/3.0)*zzz;
double al=zzz*0.25;

double R,Theta,Z,Theta1;
double r,theta,z;
double dR1,dR2,dR3,dTh1,dTh2,dTh3,dZ1,dZ2,dZ3;
double F11,F12,F13,F21,F22,F23,F31,F32,F33;
double dr1,dr2,dr3,dth1,dth2,dth3,dz1,dz2,dz3;
double *alpha,*dumy;
double c,d,e,f;
dumy = (double *)calloc(1000+10,sizeof(double));
alpha = (double *)calloc(1000+10,sizeof(double));
for(i=0;i<200;i++){ 
dumy[199-i]=(zzz-i)*0.25;
}

int label=0;

for(i=0;i<200;i++){ 
	Theta=(2*M_PI*i*1.0/100.0);
	if(dumy[i]>0){
		if(dumy[i]<70)alpha[i]=(dumy[i])*M_PI/180;
		if(dumy[i]>=70)alpha[i]=(70.0)*M_PI/180;
	}
	else if(dumy[i]<=0)alpha[i]=0;
	c=g*Rc*cos(alpha[i])/rc;
	d=-sin(alpha[i])/rc;
	e=g*Rc*sin(alpha[i]);
	f=cos(alpha[i]);
for(j=0;j<10;j++){ 
	R=R1+i*0.25+t*j*1.0/10.0;
	if(Theta<2*M_PI)Z=(H/(2*M_PI*2.0))*(2*M_PI-Theta);
	if(Theta>=2*M_PI)Z=(H/(2*M_PI*2.0))*(Theta-2*M_PI);
	r=sqrt(a*R*R+b);
	theta=c*Theta+d*Z;
	z=e*Theta+f*Z;
	if(zzz%50==0)fprintf(file5,"%lf %lf %lf %d\n",r*cos(theta),r*sin(theta),z,label);
	label=label+1;
}
for(k=0;k<40;k++){ 
	R=R1+i*0.25+t;
	if(Theta<2*M_PI)Z=(H/(2*M_PI*2.0))*(2*M_PI-Theta)+(H-2*(H/(2*M_PI*2.0))*(2*M_PI-Theta))*(k/40.0);
	if(Theta>=2*M_PI)Z=(H/(2*M_PI*2.0))*(Theta-2*M_PI)+(H-2*(H/(2*M_PI*2.0))*(Theta-2*M_PI))*(k/40.0);
	r=sqrt(a*R*R+b);
	theta=c*Theta+d*Z;
	z=e*Theta+f*Z;
	if(zzz%50==0)fprintf(file5,"%lf %lf %lf %d\n",r*cos(theta),r*sin(theta),z,label);
	label=label+1;
}
for(j=0;j<10;j++){ 
	R=R1+i*0.25+t-t*j*1.0/10.0;
	if(Theta<2*M_PI)Z=(H-(H/(2*M_PI*2.0))*(2*M_PI-Theta));
	if(Theta>=2*M_PI)Z=(H-(H/(2*M_PI*2.0))*(Theta-2*M_PI));
	r=sqrt(a*R*R+b);
	theta=c*Theta+d*Z;
	z=e*Theta+f*Z;
	if(zzz%50==0)fprintf(file5,"%lf %lf %lf %d\n",r*cos(theta),r*sin(theta),z,label);
	label=label+1;
}
for(k=0;k<40;k++){ 
	R=R1+i*0.25;
	if(Theta<2*M_PI)Z=H-(H/(2*M_PI*2.0))*(2*M_PI-Theta)-(H-2*(H/(2*M_PI*2.0))*(2*M_PI-Theta))*(k/40.0);
	if(Theta>=2*M_PI)Z=H-(H/(2*M_PI*2.0))*(Theta-2*M_PI)-(H-2*(H/(2*M_PI*2.0))*(Theta-2*M_PI))*(k/40.0);
	r=sqrt(a*R*R+b);
	theta=c*Theta+d*Z;
	z=e*Theta+f*Z;
	double Theta1,theta1,z1;
	Theta1=(2*M_PI*(i+1)*1.0/100.0);
	theta1=c*Theta1+d*Z;
	z1=e*Theta1+f*Z;
	double Theta2,theta2,z2;
	Theta2=(2*M_PI*(i+2)*1.0/100.0);
	theta2=c*Theta2+d*Z;
	z2=e*Theta2+f*Z;
	double Theta3,theta3,z3;
	Theta3=(2*M_PI*(i+3)*1.0/100.0);
	theta3=c*Theta3+d*Z;
	z3=e*Theta3+f*Z;
	double tx1,ty1,tz1,tx2,ty2,tz2,tx3,ty3,tz3;
	tx1=r*cos(theta1)-r*cos(theta);
	ty1=r*sin(theta1)-r*sin(theta);
	tz1=z1-z;
	tx2=r*cos(theta2)-r*cos(theta1);
	ty2=r*sin(theta2)-r*sin(theta1);
	tz2=z2-z1;
	tx3=r*cos(theta3)-r*cos(theta2);
	ty3=r*sin(theta3)-r*sin(theta2);
	tz3=z3-z2;
	double tpx1,tpy1,tpz1,tpx2,tpy2,tpz2;
	tpx1=tx2-tx1;
	tpy1=ty2-ty1;
	tpz1=tz2-tz1;
	tpx2=tx3-tx2;
	tpy2=ty3-ty2;
	tpz2=tz3-tz2;
	double nx1,ny1,nz1,nx2,ny2,nz2;
	nx1=tpx1/sqrt(tpx1*tpx1+tpy1*tpy1+tpz1*tpz1);
	ny1=tpy1/sqrt(tpx1*tpx1+tpy1*tpy1+tpz1*tpz1);
	nz1=tpz1/sqrt(tpx1*tpx1+tpy1*tpy1+tpz1*tpz1);
	nx2=tpx2/sqrt(tpx2*tpx2+tpy2*tpy2+tpz2*tpz2);
	ny2=tpy2/sqrt(tpx2*tpx2+tpy2*tpy2+tpz2*tpz2);
	nz2=tpz2/sqrt(tpx2*tpx2+tpy2*tpy2+tpz2*tpz2);
	double npx,npy,npz;
	npx=nx2-nx1;
	npy=ny2-ny1;
	npz=nz2-nz1;
	double tex,tey,tez;
	tex=tx2/sqrt(tx2*tx2+ty2*ty2+tz2*tz2);
	tey=ty2/sqrt(tx2*tx2+ty2*ty2+tz2*tz2);
	tez=tz2/sqrt(tx2*tx2+ty2*ty2+tz2*tz2);
	double bx,by,bz;
	bx=tey*nz1-tez*ny1;
	by=tez*nx1-tex*nz1;
	bz=tex*ny1-tey*nx1;
	double curv=sqrt(tpx1*tpx1+tpy1*tpy1+tpz1*tpz1);
	double tors=bx*npx+by*npy+bz*npz;

	if(zzz%50==0)fprintf(file5,"%lf %lf %lf %d\n",r*cos(theta),r*sin(theta),z,label);
	double height;
	if(Theta<2*M_PI)height=H-2*(H/(2*M_PI*2.0))*(2*M_PI-Theta);
	if(Theta>=2*M_PI)height=H-2*(H/(2*M_PI*2.0))*(Theta-2*M_PI);

	if(k==20)fprintf(file6,"%d %lf %lf %lf %lf %lf %lf %lf\n",zzz,Theta,r*cos(theta),r*sin(theta),z,curv,tors,height);
	label=label+1;
}


	for(k=0;k<40;k++){ 
		if(0<=i && i<8){
			Z=H-H*(k/40.0); 
			theta=c*Theta+d*Z;
			z=e*Theta+f*Z;
			R=R1;
			dR1=1*cos(Theta);
			dR2=1*sin(Theta);
			dR3=0;
			double DR1=cos(Theta);
			double DR2=sin(Theta);
			double DR3=0;
			dTh1=-1*sin(Theta);
			dTh2=1*cos(Theta);
			dTh3=0;
			double beta=90*M_PI/180;
			dZ1=dTh1*(cos(beta)+DR1*DR1*(1-cos(beta)))+dTh2*(DR1*DR2*(1-cos(beta))-DR3*sin(beta))+dTh3*(DR3*DR1*(1-cos(beta))+DR2*sin(beta));
			dZ2=dTh1*(DR1*DR2*(1-cos(beta))+DR3*sin(beta))+dTh2*(cos(beta)+DR2*DR2*(1-cos(beta)))+dTh3*(DR2*DR3*(1-cos(beta))-DR1*sin(beta));
			dZ3=dTh1*(DR3*DR1*(1-cos(beta))-DR2*sin(beta))+dTh2*(DR2*DR3*(1-cos(beta))+DR1*sin(beta))+dTh3*(cos(beta)+DR3*DR3*(1-cos(beta)));
			F11=a*Rc/sqrt(a*Rc*Rc+b);
			F12=0;
			F13=0;
			F21=0;
			F22=g*cos(alpha[i]);
			F23=-g*sin(alpha[i]);
			F31=0;
			F32=g*sin(alpha[i]);
			F33=cos(alpha[i]);
			dr1=F11*dR1+F12*dR2+F13*dR3;
			dr2=F21*dR1+F22*dR2+F23*dR3;
			dr3=F31*dR1+F32*dR2+F33*dR3;
			dth1=F11*dTh1+F12*dTh2+F13*dTh3;
			dth2=F21*dTh1+F22*dTh2+F23*dTh3;
			dth3=F31*dTh1+F32*dTh2+F33*dTh3;
			dz1=F11*dZ1+F12*dZ2+F13*dZ3;
			dz2=F21*dZ1+F22*dZ2+F23*dZ3;
			dz3=F31*dZ1+F32*dZ2+F33*dZ3;
		}
	}

	if(i==0){
		double L1=sqrt(dR1*dR1+dR2*dR2+dR3*dR3);
		double L2=sqrt(dTh1*dTh1+dTh2*dTh2+dTh3*dTh3);
		double L3=sqrt(dZ1*dZ1+dZ2*dZ2+dZ3*dZ3);
		double l1=sqrt(dr1*dr1+dr2*dr2+dr3*dr3);
		double l2=sqrt(dth1*dth1+dth2*dth2+dth3*dth3);
		double l3=sqrt(dz1*dz1+dz2*dz2+dz3*dz3);
		double prod1=dr1*dth1+dr2*dth2+dr3*dth3;
		double prod2=dth1*dz1+dth2*dz2+dth3*dz3;
		double prod3=dz1*dr1+dz2*dr2+dz3*dr3;
	}
}

if(zzz%50==0)fprintf(file5,"\n\n");
fprintf(file6,"\n\n");
free(dumy);
free(alpha);

}
	
fclose(file5);
fclose(file6);

return 0;
}


