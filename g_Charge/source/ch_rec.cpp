#include "c_constant.h"
#include <math.h>

#define AU_FC      aem_MeV           // atomic mass unit in MeV ;
#define EM_FC      Mass_e            // electron mass in MeV;
#define C_FC       vc                // speed of light in cm/s;
#define A0_FC      BohrRadius_cm     // Bohr radius in cm;
#define RY_FC      Rydberg_eV        // Rydberg in eV;
#define PI_FC      PI                // Pi;
#define U_FC       aem_mg            // atomic mass unit in mg ;
#define BARN       1e24              // barn in cm2;


extern double pow_int(double par, int power);


double  REC (double Z_P, double Z_T, double E_KIN);
double KREC (double Z_P, double E_KIN);
double FELEC(double Z_T, double E_KIN);

//WWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWW
//WWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWW
double REC(double Z_P, double Z_T, double E_KIN)
{
//CCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCC
//     Calculates REC cross section
//
//     Z_P   : Nuclear charge of projectile
//     Z_T   : Nuclear charge of target
//     E_KIN : Projectile kinetic energy in MeV/u
//     SIGREC: cross section in cm2
//CCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCC

//     Number of quasi-free target electrons
      double FREEEL = FELEC(Z_T,E_KIN);

//     K-REC cross section per electron
      double SIGKREC = KREC(Z_P,E_KIN);

      double SIGREC = 1.2002*FREEEL*SIGKREC;

      return SIGREC;
      }
//WWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWW
//WWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWW
double KREC(double Z_P, double E_KIN) {
//CCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCC
//     Calculates K-REC cross section per electron
//
//     Z_T   : Nuclear charge of target
//     E_KIN : Projectile kinetic energy in MeV/u
//     SIGREC: cross section in cm2
//CCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCC
#define    ALPHA_FC   7.297352521000e-03   // fine-structure constant

      double t = 1.0 - pow_int(Z_P*ALPHA_FC,2);
      if(t<0) t=0;

      double E_K = 510.9 * (1. - sqrt(t));
      double EK_REC = E_K+E_KIN*1000./1823.;
      double ETAK   = sqrt(E_K/(EK_REC-E_K));
      double ETAK2 = ETAK * ETAK;
      double EK     =ETAK2/(1+ETAK2);
      double BK     = exp(-4*ETAK*atan(1./ETAK))/(1.-exp(-2.*PI*ETAK));

      double SIGKREC= 9.165e-21*ETAK*ETAK*EK*EK*BK;

      return SIGKREC;
      }
//CCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCC
//CCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCC
//CCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCC



//WWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWW
//WWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWW
double FELEC(double Z_T, double E_KIN) {
//CCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCC
//     Calculates number of quasi-free target electrons
//
//     Z_T   : Nuclear charge of target
//     E_KIN : Projectile kinetic energy in MeV/u
//     FREEEL: Number of quasi-free target electrons
//CCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCC
   double Z_AB[5] = { 0 , 0.3, 4.15, 11.25, 27.85 };
   double FREEEL = Z_T;

   for( int N=1; N<=4; N++) {
        double t = (Z_T-Z_AB[N])*ALPHA_FC/N;
        double tc = EM_FC*1.0e3;
        double E_BIN  = (1. - sqrt(1.-t*t))* tc;
        double BETA_P = sqrt(E_KIN*E_KIN + 2.0*AU_FC*E_KIN)/(E_KIN + AU_FC);
        double BETA_E = sqrt(E_BIN*E_BIN + 2.0*EM_FC*tc   )/(E_BIN + tc   );
        double VER    = BETA_E/BETA_P;
        if (VER<=0.2) return FREEEL;
        FREEEL -= 2*N*N;
        if (FREEEL<=0.0) return 0;
        }

return FREEEL;
}
//CCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCC
