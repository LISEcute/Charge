
#include <math.h>
#include <stdio.h>
#include <string>

#include <QString>
#include <QFile>
#include <QTextStream>
#include <QDebug>
#include "c_constant.h"

#define pow(x,y)   exp((y)*log(x))

#define ALPHA_FC   FineStructConst   // fine-structure constant;
#define U_FC       aem_mg            // atomic mass unit in mg ;
#define AU_FC      aem_MeV           // atomic mass unit in MeV ;
#define EM_FC      Mass_e            // electron mass in MeV;
#define C_FC       vc                // speed of light in cm/s;
#define A0_FC      BohrRadius_cm     // Bohr radius in cm;
#define RY_FC      Rydberg_eV        // Rydberg in eV;
#define PI_FC      PI                // Pi;
#define BARN       1e24              // barn in cm2;


extern double pow_int(double par, int power);
extern long double pow_int(long double par, int power);
extern double pow2(double par);
extern char *GetDoubleFromString(double &V, char *s);
extern char *GetIntFromString(int &V, char *s);

extern int NRC(double Z_P, double Z_T, double E_KIN, double &SIGMA01, double &SIGMA12);
extern double REC(double Z_P, double Z_T, double E_KIN);
extern double ION(double Z_P, double Z_T, double E_KIN);

/*
extern double EIKO_1, EIKO_2;
extern double REC_1,  REC_2;
extern double BORN_1, BORN_2;
extern double D_IONIS, D_CAPT;
extern double SIGMA01, SIGMA12, SIGMA02, SIGMA10, SIGMA21, SIGMA20;

extern double TAU_A, TAU_M;
extern double ETHICK_A, ETHICK_M;
extern double A_T, RHO;

extern double FR[3];
extern double FE[3];
extern double FF[3][3];
extern double FD[3];
*/
int         Z_P      = 79;
int         Z_T      = 13;
double      E_KIN    = 1000;
double      TTHICK_M = 100;
double      R_INIT   = 0.;

double A_T, RHO, TTHICK_A;

double      EIKO_1,EIKO_2;
double      REC_1,REC_2,BORN_1,BORN_2;
double      D_IONIS, D_CAPT;
double      SIGMA01, SIGMA12, SIGMA02, SIGMA10, SIGMA21, SIGMA20;
double      TAU_A, TAU_M;
double      ETHICK_A, ETHICK_M;

long double FR[3];
long double FE[3];
long double FF[3][3];
long double FD[3];

//WWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWW

int RunCharge();
int CSD(double Z_P, double Z_T, double E_KIN, double TTHICK_M, double TTHICK_A);
int TARGET(int Z_T);
double FRACTION(double SIG01, double SIG02,
                double SIG10, double SIG12,
                double SIG20, double SIG21,
                double X1, double init);


//CCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCC
//     PROGRAM TO CALCULATE CHARGE STATES OF THREE-COMPONENT SYSTEMS
//CCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCC
int RunCharge()
{
      int Result=CSD(Z_P,Z_T,E_KIN,TTHICK_M,TTHICK_A);

      EIKO_1 *= BARN;
      EIKO_2 *= BARN;
      REC_1  *= BARN;
      REC_2  *= BARN;

      BORN_1 *= BARN;
      BORN_2 *= BARN;
      D_CAPT = D_CAPT*BARN;
      D_IONIS= D_IONIS*BARN;

return Result;
}
//CCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCC

int CSD(double Z_P, double Z_T, double E_KIN, double /*TTHICK_M*/, double TTHICK_A)
{
//CCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCC
//     Calculates ...
//
//     Z_P      :
//     Z_T      :
//     E_KIN    :
//     TTHICK_M :
//     TTHICK_A :
//CCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCC
      // implicit DOUBLE PRECISION [A-H][O-Z];

/*      common /RESULT1/ EIKO_1,EIKO_2,BORN_1,BORN_2,REC_1,REC_2;
      common /RESULT2/ D_CAPT,D_IONIS;
      common /RESULT8/ ETHICK_M,ETHICK_A,TAU_M;
      common /CONSTAN/ AU_FC,EM_FC,C_FC,ALPHA_FC,A0_FC,RY_FC,PI_FC,U_FC;

*/

//CCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCC


      if(NRC(Z_P,Z_T,E_KIN,EIKO_1,EIKO_2)<0)return -6;

      REC_1 = REC(Z_P,    Z_T,E_KIN);    //ok
      REC_2 = REC(Z_P-0.3,Z_T,E_KIN);    //wrong

      BORN_1 = ION(Z_P,      Z_T,E_KIN);
      BORN_2 = ION(Z_P - 0.3,Z_T,E_KIN);

//     Normalization factor (Anholt, PRA 1979)
      double CNORM  =pow(1. +pow2( Z_P*ALPHA_FC/2.), -2.);
      BORN_1 *=    CNORM;
      BORN_2 *= 2.*CNORM;


      D_IONIS = BORN_1*0.1;
      D_CAPT  = EIKO_1*0.1;

      double SIGKREC  = REC_2 /1.2002;
      REC_2   -= SIGKREC/2.;

      SIGMA01 = EIKO_1  + REC_1;
      SIGMA12 = EIKO_2  + REC_2;
      SIGMA02 = D_CAPT;
      SIGMA10 = BORN_1 ;
      SIGMA21 = BORN_2 ;
      SIGMA20 = D_IONIS;

//     equilibrium thickness according to Thieberger et al.:
      TAU_A = 4.6/(SIGMA10+SIGMA01/2.);  // atoms/cm2
      TAU_M = TAU_A*A_T*U_FC;            // mg/cm2

      int Res_target = TARGET(Z_T);
      if( Res_target < 0 ) return -10 + Res_target;


//==============================================================================
//     find equilibrium target thickness
      double XN;
      double XN2 = 1./SIGMA10;
      double XN1 = XN2*0.9999;
      double FRN1, FRN2;

  for(int I=1; I<=30; I++) {

        FRN2 = FRACTION(SIGMA01,SIGMA02,SIGMA10,SIGMA12,SIGMA20,SIGMA21,XN2,0);
        if(FRN2<0) return -2;

        FRN1 = FRACTION(SIGMA01,SIGMA02,SIGMA10,SIGMA12,SIGMA20,SIGMA21,XN1,0);
        if(FRN1<0) return -3;

        double t = FRN1-FRN2;
        if(t==0) XN=0;
        else     XN  = XN1-(XN1-XN2)*FRN1/t;
        XN2 = XN1;
        XN1 = XN;
        if (FRN2<1.e-3) {
                ETHICK_A = XN;                   // atoms/cm2
                ETHICK_M = ETHICK_A*A_T*U_FC;    // mg/cm2

                //     calculate charge-state distribution for the given target thickness
                FRN1 = FRACTION(SIGMA01,SIGMA02,SIGMA10,SIGMA12,SIGMA20,SIGMA21,TTHICK_A,1);
                return (FRN1 > 0 ? 1 : -5);
                }
        }

        return -1;        //fprintf(*,*) 'Convergence cannot be reached';

}
//CCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCC

double FRACTION(double SIG01, double SIG02,
                double SIG10, double SIG12,
                double SIG20, double SIG21, double X1, double init)
{
//CCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCC
//    SIGij    : charge-exchange cross section i-->j
//CCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCC
      // implicit DOUBLE PRECISION[A-H][O-Z];
      long double P[3][3],N[3][3];

//      common /INITCSD/ FR0,FR1,FR2,R_INIT,D0,D1,D2;
//      common /CONSTAN/ AU_FC,EM_FC,C_FC,ALPHA_FC,A0_FC,RY_FC,PI_FC,U_FC;
//CCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCC
      double PID    = X1;
  //    qDebug() << "Calculationg FD[]!";
      double ALPHA = SIG01 + SIG02;
      double BETA  = SIG10 + SIG12;
//Qt-Oleg      double GAMMA = SIG20 + SIG21;
      double A     = -(BETA+SIG21);
      double B     = (SIG01-SIG21);
      double F     = (SIG10-SIG20);
      double G     = -(ALPHA+SIG20);
      double D     = A*G-B*F;
      double tt    = pow2(G-A)+4.*B*F;
      if(tt<0) return -1;
      double Q     = 0.5*sqrt(tt);

      double SIGSUM= -(A+G);
      double S     = 0.5*(G-A);

      FE[0]  = (BETA *SIG20+SIG10*SIG21)/D;
      FE[1]  = (ALPHA*SIG21+SIG01*SIG20)/D;
      FE[2]  = (SIG20*(A-B)+G*(A+SIG21)-F*(B+SIG21))/D;

      P[0][1]  =  1.0/2./Q*(B*FE[2]+(B+S-Q)*FE[1]);
      P[1][1]  = -1.0/2./Q*((S-Q)*(1.0-FE[1])+B*FE[0]);
      P[2][1]  =  1.0/2./Q*(FE[1]*(S-Q)-B*FE[0]);

      P[0][0]  =  P[0][1]  *(S+Q)/B;
      P[1][0]  =  P[1][1]  *(S+Q)/B;
      P[2][0]  =  P[2][1]  *(S+Q)/B;

      P[0][2]  = -P[0][1]  *(B+S+Q)/B;
      P[1][2]  = -P[1][1]  *(B+S+Q)/B;
      P[2][2]  = -P[2][1]  *(B+S+Q)/B;

      N[0][1]  = -1.0/2./Q*(B*FE[2]+(B+S+Q)*FE[1]);
      N[1][1]  =  1.0/2./Q*((S+Q)*(1.0-FE[1])+B*FE[0]);
      N[2][1]  = -1.0/2./Q*(FE[1]*(S+Q)-B*FE[0]);

      N[0][0]  =  N[0][1]  *(S-Q)/B;
      N[1][0]  =  N[1][1]  *(S-Q)/B;
      N[2][0]  =  N[2][1]  *(S-Q)/B;

      N[0][2]  = -N[0][1]  *(B+S-Q)/B;
      N[1][2]  = -N[1][1]  *(B+S-Q)/B;
      N[2][2]  = -N[2][1]  *(B+S-Q)/B;

      if (init==0.) { FE[0] = FE[1] = FE[2] = 0.; }

     long double PID_Q = PID*Q;
     if(PID_Q >20000)
                return -2;

     long double emPQ = expl(-PID_Q);
     long double epPQ = expl( PID_Q);
     long double eSP  = expl(-0.5*SIGSUM*PID);

//     INITIAL CHARGE STATE 0 ELECTRONS

      for(int i=0; i<3; i++)
         for(int j=0; j<3; j++)
              FF[i][j]=FE[j]+(P[i][j]*epPQ+N[i][j]*emPQ)*eSP;

      for(int i=0; i<3; i++){
            FD[i] = FR[0]*FF[0][i] + FR[1]*FF[1][i] + FR[2]*FF[2][i];
           // qDebug() << "FD[" << i << "] = " << (double)FD[i];
      }

      long double X2=0;
      for(int i=0; i<3; i++)
         for(int j=0; j<3; j++)
                        X2+=pow2(FF[i][j]);

      X2 = sqrt(X2);

       return X2;

}
//CCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCC


int TARGET(int Z_T) {
//CCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCC
//     Reads target data
//
//     Z_T    : Nuclear charge of target
//     A_T    : Mass number of target nucleus
//     RHO    : Density of target material in g/cm3
//CCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCC
#define SizeBuf 100
//char buffer[SizeBuf], *t;
int ZTS;
//FILE *f_target;

//CCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCC
//AnsiString target_NameFile = ExtractFilePath(ParamStr(0)) + "charge_data\\target.data";
//std::string target_NameFile = ExtractFilePath(ParamStr(0)) + "charge_data\\target.data";
QFile targetFile(":/charge_data/target.txt");
if(!targetFile.open(QIODevice::ReadOnly|QIODevice::Text)){
    qDebug() << "Could not open charge data file";
    return -1;
}else {
    int n = 0;
    QTextStream in(&targetFile);
    while(!in.atEnd()){
        QString line = in.readLine();
        if(n >= 7){
            QStringList ln = line.split(" ", Qt::SkipEmptyParts);
            ZTS = ln.at(0).toInt();
            A_T = ln.at(1).toDouble();
            RHO = ln.at(2).toDouble();
            if(ZTS==Z_T){
                targetFile.close();
                return Z_T;
            }
        }
        n++;
    }

}

targetFile.close();
return -4;
//f_target= fopen(target_NameFile.c_str(), "rt");
//if(!f_target) return -1;

// read comments
// for(int I=1; I<=7; I++)
//     if(!fgets(buffer,SizeBuf,f_target)) {fclose(f_target); return -2;}


//for(int I=1; I<=92; I++) {         //L10
//       if(!fgets(buffer,SizeBuf,f_target)) {fclose(f_target); return -3;}
//         t=buffer;
//         t=GetIntFromString(ZTS, t);        if(!t) goto error_format;
//         t=GetDoubleFromString(A_T, t);        if(!t) goto error_format;
//         t=GetDoubleFromString(RHO, t);
//        if(ZTS==Z_T) { fclose(f_target); return Z_T;}
//        }

//error_format:
////      fprintf(*,*) 'TARGET double NOT FOUND';
//      fclose(f_target);
//      return -4;
}

