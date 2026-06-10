#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define R1 200
#define t 10
#define H 200.0
#define g 1.0
#define Rc 200
#define rc 100
#define _USE_MATH_DEFINES

int main(void){

int i,j,k,zzz;

FILE *file5;
char filename5[100];
sprintf(filename5,"Fig.3a.txt");
file5 = fopen(filename5,"w");
FILE *file51;
char filename51[100];
sprintf(filename51,"Fig.4ab.txt");
file51 = fopen(filename51,"w");
FILE *file6;
char filename6[100];
sprintf(filename6,"Fig.3dfh_Fig.4cd.txt");
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
	R=R1-i*0.25+t*j*1.0/10.0;
	Z=0;
	r=sqrt(a*R*R+b);
	theta=c*Theta+d*Z;
	z=e*Theta+f*Z;
	if(zzz%50==0)fprintf(file5,"%lf %lf %lf %d\n",r*cos(theta),r*sin(theta),z,label);
	label=label+1;
}
for(k=0;k<40;k++){ 
	R=R1-i*0.25+t;
	Z=H*(k/40.0); 
	r=sqrt(a*R*R+b);
	theta=c*Theta+d*Z;
	z=e*Theta+f*Z;
	if(zzz%50==0)fprintf(file5,"%lf %lf %lf %d\n",r*cos(theta),r*sin(theta),z,label);
	label=label+1;
}
for(j=0;j<10;j++){ 
	R=R1-i*0.25+t-t*j*1.0/10.0;
	Z=H; 
	r=sqrt(a*R*R+b);
	theta=c*Theta+d*Z;
	z=e*Theta+f*Z;
	if(zzz%50==0)fprintf(file5,"%lf %lf %lf %d\n",r*cos(theta),r*sin(theta),z,label);
	label=label+1;
}
for(k=0;k<40;k++){ 
	R=R1-i*0.25;
	Z=H-H*(k/40.0); 
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
	double rx0,ry0,rz0,rx1,ry1,rz1,rx2,ry2,rz2,rx3,ry3,rz3,d1;
	double tx1,ty1,tz1,tx11,ty11,tz11,tx2,ty2,tz2,tx3,ty3,tz3;
	rx0=r*cos(theta);
	ry0=r*sin(theta);
	rz0=z;
	rx1=r*cos(theta1);
	ry1=r*sin(theta1);
	rz1=z1;
	rx2=r*cos(theta2);
	ry2=r*sin(theta2);
	rz2=z2;
	rx3=r*cos(theta3);
	ry3=r*sin(theta3);
	rz3=z3;
	tx1=rx1-rx0;
	ty1=ry1-ry0;
	tz1=rz1-rz0;
	d1=sqrt(tx1*tx1+ty1*ty1+tz1*tz1);
	tx2=rx2-rx1;
	ty2=ry2-ry1;
	tz2=rz2-rz1;
	tx3=rx3-rx2;
	ty3=ry3-ry2;
	tz3=rz3-rz2;
	double thet1,dd1,dd2,dd3;
	dd1=sqrt(tx1*tx1+ty1*ty1+tz1*tz1);
	dd2=sqrt(tx2*tx2+ty2*ty2+tz2*tz2);
	thet1=acos((tx1*tx2+ty1*ty2+tz1*tz2)/(dd1*dd2));
	double curv=thet1/d1;
	double npx1,npy1,npz1,npx2,npy2,npz2;
	npx1=tx2-tx1;
	npy1=ty2-ty1;
	npz1=tz2-tz1;
	npx2=tx3-tx2;
	npy2=ty3-ty2;
	npz2=tz3-tz2;
	double nx1,ny1,nz1,nx2,ny2,nz2;
	nx1=npx1/sqrt(npx1*npx1+npy1*npy1+npz1*npz1);
	ny1=npy1/sqrt(npx1*npx1+npy1*npy1+npz1*npz1);
	nz1=npz1/sqrt(npx1*npx1+npy1*npy1+npz1*npz1);
	nx2=npx2/sqrt(npx2*npx2+npy2*npy2+npz2*npz2);
	ny2=npy2/sqrt(npx2*npx2+npy2*npy2+npz2*npz2);
	nz2=npz2/sqrt(npx2*npx2+npy2*npy2+npz2*npz2);
	double tex,tey,tez,tex1,tey1,tez1;
	tex=tx2/sqrt(tx2*tx2+ty2*ty2+tz2*tz2);
	tey=ty2/sqrt(tx2*tx2+ty2*ty2+tz2*tz2);
	tez=tz2/sqrt(tx2*tx2+ty2*ty2+tz2*tz2);
	tex1=tx3/sqrt(tx3*tx3+ty3*ty3+tz3*tz3);
	tey1=ty3/sqrt(tx3*tx3+ty3*ty3+tz3*tz3);
	tez1=tz3/sqrt(tx3*tx3+ty3*ty3+tz3*tz3);
	double bx,by,bz,bx1,by1,bz1;
	bx=tey*nz1-tez*ny1;
	by=tez*nx1-tex*nz1;
	bz=tex*ny1-tey*nx1;
	bx1=tey1*nz2-tez1*ny2;
	by1=tez1*nx2-tex1*nz2;
	bz1=tex1*ny2-tey1*nx2;
	double thet11,dd11,dd22;
	dd11=sqrt(bx*bx+by*by+bz*bz);
	dd22=sqrt(bx1*bx1+by1*by1+bz1*bz1);
	thet11=acos((bx*bx1+by*by1+bz*bz1)/(dd11*dd22));
	double tors=thet11/d1;

	if(zzz%50==0)fprintf(file5,"%lf %lf %lf %d\n",r*cos(theta),r*sin(theta),z,label);
	if(zzz%50==0)fprintf(file51,"%lf %lf %lf %d %lf %lf\n",r*cos(theta),r*sin(theta),z,label,curv,tors);
	if(k==20)fprintf(file6,"%d %lf %lf %lf %lf %lf %lf %lf\n",zzz,Theta,r*cos(theta),r*sin(theta),z,curv,tors,H);
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
if(zzz%50==0)fprintf(file51,"\n\n");
fprintf(file6,"\n\n");
free(dumy);
free(alpha);

}

fclose(file5);
fclose(file51);
fclose(file6);

return 0;
}


