
#include "c_constant.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#include <QFile>
#include <QTextStream>

#include <QDebug>

int NRC(double ZP, double ZT, double E_KIN, double &SIGMA01, double &SIGMA12);

double EIKONALS(double ZT,   double ZP, double ZTS,
              int NIMIN,    int NIMAX,  int NFMIN, int NFMAX,
              double E_KIN, int IEL);

double EIKONAL(double ZT, double ZP, double ZTS, int NI, int NF, double E_KIN);

extern double pow_int(double par, int power);

//WWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWW
//WWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWW
int NRC(double ZP, double ZT, double E_KIN, double &SIGMA01, double &SIGMA12)
{
    //CCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCC
    //     Calculates NRC cross section
    //
    //     ZP      : Nuclear charge of projectile
    //     ZT      : Nuclear charge of target
    //     E_KIN    : Projectile kinetic energy in MeV/u
    //     SIGMAij  : NRC cross section for state i --> state j
    //CCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCC

    //FILE *f_proj;
    int NIMIN, NIMAX, NFMIN, NFMAX;

    //#define SizeBuf 200
    //char buffer[SizeBuf];

    //sprintf(buffer,"charge_data\\x%i.data", int(ZT));
    //AnsiString target_NameFile = ExtractFilePath(ParamStr(0)) + buffer;
    //f_proj=fopen(target_NameFile.c_str(),"rt");
    //if( !f_proj  ) return -1;

    QString dfname = ":/charge_data/x" + QString::number(ZT) + ".txt";
   // qDebug() << dfname;
    QFile df(dfname);
    if(!df.open(QIODevice::ReadOnly | QIODevice::Text)){
        return -1;
    }
    double  ZPnew    = ZP;
    double  ZTS = 0;
    SIGMA01 = 0;
    SIGMA12 = 0;
    double  SIGALL = 0;
    ////double  SIGSUM=0;

    int NUM=0;                               // ???????   NUM=2, but we have a lot of sections at least for Uranium

    for(int IEL=0; IEL<=1; IEL++)
        {
        QTextStream in(&df);
        QString lin = in.readLine();
       // QStringList ln = lin.split(" ", Qt::SkipEmptyParts);
        NUM = lin.split(" ",Qt::SkipEmptyParts).first().toInt();
      //  in.readLine();
        //in >> NUM;
       // qDebug() << "NUM = " << NUM;
        if(NUM <= 0) {
            df.close();
            return -3;
        }
       for(int j=1;j<=NUM;j++){
          // qDebug() << "j = " << j;
           QString line = in.readLine();

           line.clear();
           line = in.readLine();
            ZT = line.split(" ", Qt::SkipEmptyParts).first().toDouble();
          //  qDebug() << "ZT = " << ZT;
            line = in.readLine();
            ZTS = line.split(" ", Qt::SkipEmptyParts).first().toDouble();
         //   qDebug() << "ZTS = " << ZTS;
            line = in.readLine();
            NIMIN = line.split(" ", Qt::SkipEmptyParts).first().toInt();
         //   qDebug() << "NIMIN = " << NIMIN;
            line = in.readLine();
            NIMAX = line.split(" ", Qt::SkipEmptyParts).first().toInt();
         //   qDebug() << "NIMAX = " << NIMAX;
            line = in.readLine();
            NFMIN = line.split(" ", Qt::SkipEmptyParts).first().toInt();
       //     qDebug() << "NFMIN = " << NFMIN;
            line = in.readLine();
            NFMAX = line.split(" ", Qt::SkipEmptyParts).first().toInt();
         //    qDebug() << "NFMAX = " << NFMAX;
            if (IEL==1) ZPnew = ZP -  (j==1 ? 0.3 : 1.0);

            SIGALL += EIKONALS(ZT,ZPnew,ZTS,NIMIN,NIMAX,NFMIN,NFMAX,E_KIN,IEL);

        }
      // qDebug() << "after loop";
        if (IEL==0) SIGMA01 = SIGALL;
        if (IEL==1) SIGMA12 = SIGALL;
        SIGALL = 0;
        df.seek(0);
    }

    df.close();
    return 1;


    /**
L9999: fprintf(6,*) 'ALLOCATION ERROR FILE: ',C_FILE;
      fprintf(6,*) '*      CREATE NEW FILE !         *';
      ZTS= ZTS1;
*/
}
//CCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCC
//CCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCC
//CCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCC


//WWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWW
//WWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWW
double EIKONALS(double ZT,   double ZP,  double ZTS,
                int NIMIN,    int NIMAX,
                int NFMIN,    int NFMAX,
                double E_KIN, int IEL)
{
//CCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCC
      // implicit DOUBLE PRECISION[A-H][O-Z];
//int I_TEST;

      //CCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCC
double SIGSUM = 0;
//double SIGMAX;

  for(int I=NIMIN; I<=NIMAX; I++) {

        for(int F=NFMIN; F<=NFMAX; F++) {

          double SIGMAX = EIKONAL(ZT,ZP,ZTS,I,F,E_KIN);
          double v = I*I*F*F;
          double SIGMA = SIGMAX*2.*v;

                                //    ASSUME FULL INITIAL S SHELL
          if(F==1 && IEL==1) SIGMA = SIGMAX*v;

                                //    FINAL S SHELL HAS ONE ELECTRON
          SIGSUM += SIGMA;
          }
      }

return SIGSUM;
}
//CCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCC
//CCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCC
//CCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCC



//WWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWW
//WWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWW
double EIKONAL(double ZT, double ZP, double ZTS, int NI, int NF, double E_KIN)
{
//CCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCC
//     Relativistic Eikonal Approximation
//     according to
//     W.E.Meyerhof and R.Anholt, Phys. Rev. A32, 3291 (1985).
//CCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCC
      // implicit DOUBLE PRECISION[A-H][O-Z];

//CCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCC
//constants
//qDebug() << "here";
/*
double      AU       = aem_MeV;
double      A0       = BohrRadius_cm;
double      ALPHA    = FineStructConst;
*/

double      AU       = 931.49432;
double      A0       = 0.529177249e-8;
double      ALPHA    = 1./137.036;       // stupid stuff
double      PIh       = 3.141592654;

//_____________RELATIVISTISCHE ATOMARE ENERGIEN ________________________

double A2 = ALPHA*ALPHA;

ZT /= double(NI);
ZP /= double(NF);
ZTS /= double(NI);

long double E_INITAL = 1./A2*sqrtl(1.-A2*ZT*ZT);
long double E_FINAL  = 1./A2*sqrtl(1.-A2*ZP*ZP);

//_______________________________________________________________________
long double        BETA   = sqrtl(E_KIN*E_KIN +2.*AU*E_KIN) / (E_KIN+AU);
long double        V      = BETA/ALPHA;
long double        ETA    = 1./V;
long double        GAMMA  = 1.0/sqrtl(1.0-BETA*BETA);
long double        DELTA  = sqrtl( (GAMMA - 1.) / (GAMMA + 1.) );
long double        P_     = ETA*(E_FINAL/GAMMA - E_INITAL);

//_______________S_ORB___________________________________________________
ALPHA  = 1./137.;     // stupid stuff

long double D2 = DELTA*DELTA;
long double D4 = D2*D2;
long double GGts = GAMMA/(GAMMA+1.)*ZTS/ZT;
long double sum_PT = ZP+ZT;
long double kk = (1.- 0.5*D2);
long double ETA_ZTS  = ETA*ZTS;
long double ETA_ZTS2 = ETA_ZTS * ETA_ZTS;
long double ETA_ZTS_ZT_P = ETA_ZTS / ZT * P_ ;

long double S_ORB  = 5.*PIh*DELTA*ALPHA*(
                1./18.   * sum_PT       * kk  -
                1./8./PI * ZT* ETA_ZTS * kk  -
                1./18.   * GGts * ZP        +
                1./28.   * ZP*GGts*GGts     -
                1./28.   * GGts*(sum_PT - D2*ZP)
                );


//_______________S_MAGN__________________________________________________
double S_MAGN = -D2
              + 5./16.*D4
              + 5./8. *D2*GGts
              + 2./8. *D2*ETA_ZTS2
              + 5./48.*D4*ETA_ZTS2;

//_______________S_EIK___________________________________________________

double S_EIK  = 1.
               +  5./4. * ETA_ZTS_ZT_P
               +  5./12.* ETA_ZTS_ZT_P * ETA_ZTS_ZT_P
               +  1./6. * ETA_ZTS2                      ;

//_______________SIGMA___________________________________________________
double vr1 = ZP*ZT;
double vr2 = ZT*ZT + P_*P_;
double vr125 = pow_int(vr1/vr2,5);

double v3   = PIh*ETA*ZTS;


double  SIGMA1  = 256.
                *  vr125
                / (5.*V*V)
                * (1.+GAMMA)/ 2.0 / GAMMA/ GAMMA
                * v3 /sinhl(v3)
                * expl(-2.*ETA*ZTS* atanl(-P_/ZT))
                * (S_EIK+S_ORB+S_MAGN);

/*
      SIGMA1  = 2.D0**8*(Z_P*Z_T)**5/(5.D0*V**2*(Z_T**2+P_**2)**5)
     &          *(1.D0+GAMMA)/(2.D0*GAMMA**2)
     &          *PI*ETA*ZTS
     &          /DSINH(PI*ETA*ZTS)
     &          *DEXP(-2.D0*ETA*ZTS*DATAN(-P_/Z_T) )
     &          *(S_EIK+S_ORB+S_MAGN)
*/

double SIGMA   = SIGMA1*PI*A0*A0;
//_______________________________________________________________________

return SIGMA;
}

