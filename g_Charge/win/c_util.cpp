#include <QString>
#include <QDebug>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <math.h>
#define ALPHA_FC   FineStructConst   // fine-structure constant;

#define max(x,y) (x>y ? x : y)
#define min(x,y) (x<y ? x : y)


const char *symb=
"n H HeLiBeB C N O F NeNaMgAlSiP S ClArK CaScTiV CrMnFeCoNiCuZn"
"GaGeAsSeBrKrRbSrY ZrNbMoTcRuRhPdAgCdInSnSbTeI XeCsBaLaCePrNdPm"
"SmEuGdTbDyHoErTmYbLuHfTaW ReOsIrPtAuHgTlPbBiPoAtRnFrRaAcThPaU "
"NpPuAmCmBkCfEsFmMdNoLrRfDbSgBhHsMtB0B1B2B3B4B5B6B7B8B9C0C1C2C3C"
"4C5C6C7C8C9D0??";


double pow_int(double par, int power);
long double pow_int(long double par, int power);
double pow2(double par);
char *GetNextSymbol(char *s);
char *GetNextDelimeter(char *s);
char *GetIntFromString(int &V, char *s);
char *GetDoubleFromString(double &V, char *s);
double mzsqrt(double X);
char* eos(char *b);
char* ElementName(int IZ);
int GetZfromName(QString el_init);

//double GetPrivateProfileDouble(char* lpAppName, char* lpKeyName,  double def_value, char* ini_file);
//unsigned long GetPrivateProfileULong(char* lpAppName, char* lpKeyName,  unsigned long def_value, char* ini_file);
//WWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWW
//WWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWW
//WWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWW
long double pow_int(long double par, int power)
{
long double S=1;

for(int i=1; i<=power; i++) S*=par;
return S;
}
//WWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWW
//WWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWW
//WWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWW
double pow_int(double par, int power)
{
double S=1;

for(int i=1; i<=power; i++) S*=par;
return S;
}

//WWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWW
double pow2(double par)
{
return par*par;
}

//---------------------------------------------------------------------------
char *GetNextSymbol(char *s)
{
char c;

while(true) {
        c=*s;
        if(c=='\0' || c=='\n' || c=='\r') {return NULL;}

        if( !(c==' ' || c=='\t' || c==',')) break;
        s++;
        }
return s;
}
//---------------------------------------------------------------------------
char *GetNextDelimeter(char *s)
{
char c;

while(true) {
        c=*s;
        if(c=='\0' || c=='\n' || c=='\r')   {return NULL;}
        if( c==' ' || c=='\t' || c==',') break;
        s++;
        }
return s;
}

//---------------------------------------------------------------------------
char *GetIntFromString(int &V, char *s)
{
s=GetNextSymbol(s); if(!s) return NULL;
V=atoi(s);
return GetNextDelimeter(s);
}
//---------------------------------------------------------------------------
char *GetDoubleFromString(double &V, char *s)
{
s=GetNextSymbol(s); if(!s) return NULL;
V=atof(s);
return GetNextDelimeter(s);
}
//WWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWW
//WWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWW
double mzsqrt(double X) {
      X=max(0.,X);
      return sqrt(X);
      };
//WWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWW
//WWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWW
char* eos(char *b)
{
  //  qDebug() <<" in eos() "<< b;
    char *s; s=b;

while(1)  {
   if(*s==0 || *s=='\n' || *s==';' ) break;
   s++;
   }
return s;
}
//WWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWW
//WWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWW
char* ElementName(int IZ) {


if(IZ<0 || IZ>130) IZ=131;
return &((char*)symb)[IZ*2];
}
//WWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWW
//WWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWW
int GetZfromName(QString el_init)
 {
    int i;
    //const char* el = el_init.toStdString().c_str();
    char ss[3]="  ";
    char *s = &ss[0];
    char *seos;                                     // format: ii cc  ii+\0

    s[0]=el_init.at(0).toLatin1();
    if(el_init.size() ==2) s[1]=el_init.at(1).toLatin1();
    else                   s[1]=0;


    seos=eos(s);

    while(*s <= '9') { if(s==seos) return 131;      s++;   }

    if( *s     <= 'z' && *s       >= 'a' ) 	  *s  =  char(*s     - ('a'-'A'));
    if( *(s+1) <= 'Z' && *(s+1)   >= 'A' ) *(s+1) =  char(*(s+1) + ('a'-'A'));


//int shift=2;

 for(i=0; i<=130; i++)							// from 2 symbols
        if(strncmp(s, symb+2*i, 2) == 0) break;

 if(i > 130 )  {
  //	shift=1;
    for(i=0; i<=130; i++)                                 // from 1 symbol
        if(  *(symb+2*i  ) == *s   &&
                 *(symb+2*i+1) == ' ' 	) break;
      }

return i;
}

//WWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWW
//WWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWW
//WWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWW
/*double GetPrivateProfileDouble(char* lpAppName, char* lpKeyName,  double def_value, char* ini_file)
{
char buffer[30], def[30];

sprintf(def,"%g",def_value);
//GetPrivateProfileString(lpAppName,lpKeyName,def,buffer,14,ini_file);
return atof(buffer);
}
//WWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWW
//WWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWW
//WWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWW
unsigned long GetPrivateProfileULong(char* lpAppName, char* lpKeyName,  unsigned long def_value, char* ini_file)
{
char buffer[30], def[30];

sprintf(def,"%ul",def_value);
//GetPrivateProfileString(lpAppName,lpKeyName,def,buffer,19,ini_file);
return atol(buffer);
}
*/
