
#include "c_constant.h"

#include <math.h>
#define A0_FC      BohrRadius_cm     // Bohr radius in cm;
#define ALPHA_FC   FineStructConst   // fine-structure constant;
#define AU_FC      aem_MeV           // atomic mass unit in MeV ;

extern double pow_int(double par, int power);
extern double pow2(double par);

double ION(double Z_P, double Z_T, double E_KIN);
void ETATABLE(void);
double EXTRAPOL(double ETA);
double INTERPOL(double ETA);

double ETA_T1[26],ETA_T2[26],ETA_T3[26];
int INDEX_TAB[26];

#define  IDINT(a)    int(a)

//WWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWW
//WWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWW
double ION(double Z_P, double Z_T, double E_KIN)
{
//CCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCC
//     Calculates K-shell ionization cross section
//     according to
//     R.RICE, G.BASBAS, F.D.MCDANIEL,
//     ATOMIC DATA AND NUCLEAR DATA TABLES 20, 503-511(1977)
//
//     Z_P   : Nuclear charge of projectile
//     Z_T   : Nuclear charge of target
//     E_KIN : Projectile kinetic energy in MeV/u
//     SIGION: Cross section in cm2
//     E_K  - K-shell binding energy of projectile
//CCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCC
//      char CHR;
      double FK;
//CCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCC
      ETATABLE();

      double t = A0_FC*Z_T / Z_P / Z_P;
      double SIGMA0 = 4.*PI*t*t;

      double BETA   = sqrt(E_KIN*E_KIN+2.*AU_FC*E_KIN)/(E_KIN+AU_FC);
      double GAMMA  = 1./sqrt(1.-BETA*BETA);

              t = ALPHA_FC*Z_P;    if(t>1)t=1;
      double E_K = 1.-sqrt(1.-t*t);

      double V_V0   = BETA/ALPHA_FC;
      double ETA    = pow_int(V_V0/Z_P,2);

      if (ETA<=95.)  FK = INTERPOL(ETA);
      else           FK = EXTRAPOL(ETA);

//      double REL_FAC = 1.;
      double REL_FAC = 1. +(log(GAMMA*GAMMA)-BETA*BETA)/log(2.*BETA*BETA/E_K);

      double SIGION = SIGMA0*FK*REL_FAC;
      return SIGION;
}
//CCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCC
//CCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCC
//CCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCC



//WWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWW
//WWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWW
double  EXTRAPOL(double ETA) {
//CCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCC
//     Find FK by extrapolation
//CCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCC
      double C1      = 0.2834;
      double C2      = 1.6476;
      double C3      = 8.0519;

      double ETA_T   = 95.;
      double FK_95   = 2.666e-2;

      double G_ETA   = C2/(4.*ETA)   + C3/(32.*pow2(ETA));
      double G_ETA_T = C2/(4.*ETA_T) + C3/(32.*pow2(ETA_T));
      double D_ETA_T = ETA_T*FK_95 -C1*log(95.) + G_ETA_T;

      double FK      = C1*log(ETA)+D_ETA_T -G_ETA;
      FK      = FK/ETA;

      return FK;
}
//WWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWW
//WWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWW

double INTERPOL(double ETA)
 {
//CCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCC
//     Find FK by interpolation
//CCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCC
double ST, ETA_H, B, FK =-777;
int I_ETA,I;

 if ( ETA>0.1 && ETA<=1.) {

     ETA_H = 100.*ETA;
     I_ETA = IDINT(ETA_H);

        for(I=1; I<=22; I++)
          if(  INDEX_TAB[I  ]<=I_ETA  &&
               INDEX_TAB[I+1]>=I_ETA   ) {
                ST=100.* (   ETA_T1[I+1]-   ETA_T1[I])/
                   double(INDEX_TAB[I+1]-INDEX_TAB[I]);

                B = -ST*double(INDEX_TAB[I+1])/100. + ETA_T1[I+1];
                return FK= ST*ETA +B;
                }
      }
      //=======================================================
  else if ( ETA > 1 && ETA<=10) {

        ETA_H = 10.*ETA;
        I_ETA = IDINT(ETA_H);

        for(I=1; I<=22; I++)
          if(  INDEX_TAB[I  ]<=I_ETA  &&
               INDEX_TAB[I+1]>=I_ETA   ) {
                ST=10. * (   ETA_T2[I+1]-   ETA_T2[I])/
                   double(INDEX_TAB[I+1]-INDEX_TAB[I]);

                B = -ST*double(INDEX_TAB[I+1])/10. + ETA_T2[I+1];
                return FK= ST*ETA +B;
                }
        }
   //=======================================================
 else  if ( ETA>10. && ETA <= 95.) {

        ETA_H = 1.*ETA;
        I_ETA = IDINT(ETA_H);

        for(I=1; I<=22; I++)
          if(  INDEX_TAB[I  ]<=I_ETA  &&
               INDEX_TAB[I+1]>=I_ETA   ) {
                ST=      (   ETA_T3[I+1]-   ETA_T3[I])/
                   double(INDEX_TAB[I+1]-INDEX_TAB[I]);

                B = -ST*double(INDEX_TAB[I+1])     + ETA_T3[I+1];
                return FK= ST*ETA +B;
                }
        }
//WWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWW
//WWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWW
//fprintf(*,*) 'FK in void ION out of limits' {
return FK;
}
//CCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCC
//CCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCC
//CCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCC


//WWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWW
//WWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWW
void ETATABLE() {
//CCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCC
//     Table with values for ETA
//CCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCC
//       0.1 <= ETA <= 0.95
//CCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCC
        ETA_T1[1]  = 4.118e-2;
        ETA_T1[2]  = 6.292e-2;
        ETA_T1[3]  = 8.760e-2;
        ETA_T1[4]  = 1.142e-1;
        ETA_T1[5]  = 1.420e-1;
        ETA_T1[6]  = 1.703e-1;
        ETA_T1[7]  = 2.262e-1;
        ETA_T1[8]  = 2.794e-1;
        ETA_T1[9]  = 3.282e-1;
        ETA_T1[10] = 3.722e-1;
        ETA_T1[11] = 4.113e-1;
        ETA_T1[12] = 4.535e-1;
        ETA_T1[13] = 4.888e-1;
        ETA_T1[14] = 5.182e-1;
        ETA_T1[15] = 5.422e-1;
        ETA_T1[16] = 5.617e-1;
        ETA_T1[17] = 5.773e-1;
        ETA_T1[18] = 5.895e-1;
        ETA_T1[19] = 5.988e-1;
        ETA_T1[20] = 6.058e-1;
        ETA_T1[21] = 6.107e-1;
        ETA_T1[22] = 6.138e-1;
        ETA_T1[23] = 6.154e-1;

//       1. <= ETA <= 9.5
        ETA_T2[1]  = 6.154e-1;
        ETA_T2[2]  = 6.112e-1;
        ETA_T2[3]  = 5.965e-1;
        ETA_T2[4]  = 5.767e-1;
        ETA_T2[5]  = 5.549e-1;
        ETA_T2[6]  = 5.325e-1;
        ETA_T2[7]  = 4.908e-1;
        ETA_T2[8]  = 4.526e-1;
        ETA_T2[9]  = 4.190e-1;
        ETA_T2[10] = 3.895e-1;
        ETA_T2[11] = 3.638e-1;
        ETA_T2[12] = 3.359e-1;
        ETA_T2[13] = 3.119e-1;
        ETA_T2[14] = 2.912e-1;
        ETA_T2[15] = 2.731e-1;
        ETA_T2[16] = 2.572e-1;
        ETA_T2[17] = 2.431e-1;
        ETA_T2[18] = 2.305e-1;
        ETA_T2[19] = 2.193e-1;
        ETA_T2[20] = 2.091e-1;
        ETA_T2[21] = 1.998e-1;
        ETA_T2[22] = 1.914e-1;
        ETA_T2[23] = 1.837e-1;

//       10. <= ETA <= 95.
        ETA_T3[1]  = 1.837e-1;
        ETA_T3[2]  = 1.585e-1;
        ETA_T3[3]  = 1.396e-1;
        ETA_T3[4]  = 1.249e-1;
        ETA_T3[5]  = 1.132e-1;
        ETA_T3[6]  = 1.035e-1;
        ETA_T3[7]  = 8.869e-2;
        ETA_T3[8]  = 7.770e-2;
        ETA_T3[9]  = 6.923e-2;
        ETA_T3[10] = 6.251e-2;
        ETA_T3[11] = 5.704e-2;
        ETA_T3[12] = 5.147e-2;
        ETA_T3[13] = 4.694e-2;
        ETA_T3[14] = 4.317e-2;
        ETA_T3[15] = 4.000e-2;
        ETA_T3[16] = 3.728e-2;
        ETA_T3[17] = 3.492e-2;
        ETA_T3[18] = 3.286e-2;
        ETA_T3[19] = 3.104e-2;
        ETA_T3[20] = 2.942e-2;
        ETA_T3[21] = 2.797e-2;
        ETA_T3[22] = 2.666e-2;

        INDEX_TAB[1]  = 10;
        INDEX_TAB[2]  = 12;
        INDEX_TAB[3]  = 14;
        INDEX_TAB[4]  = 16;
        INDEX_TAB[5]  = 18;
        INDEX_TAB[6]  = 20;
        INDEX_TAB[7]  = 24;
        INDEX_TAB[8]  = 28;
        INDEX_TAB[9]  = 32;
        INDEX_TAB[10] = 36;
        INDEX_TAB[11] = 40;
        INDEX_TAB[12] = 45;
        INDEX_TAB[13] = 50;
        INDEX_TAB[14] = 55;
        INDEX_TAB[15] = 60;
        INDEX_TAB[16] = 65;
        INDEX_TAB[17] = 70;
        INDEX_TAB[18] = 75;
        INDEX_TAB[19] = 80;
        INDEX_TAB[20] = 85;
        INDEX_TAB[21] = 90;
        INDEX_TAB[22] = 95;
        INDEX_TAB[23] = 100;
}
//CCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCC
//CCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCC
//CCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCC
