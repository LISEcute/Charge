#include "c_mainwindow.h"
#include <QApplication>
#include <QDir>
#include <QDebug>
#include <QStandardPaths>
#include <QMessageBox>
#include <QFileDialog>
#include <QSettings>


extern int     Z_P;
extern int     Z_T;
extern double  E_KIN;
extern double  R_INIT;
extern long double  FR[3];

extern double EIKO_1,EIKO_2;
extern double REC_1, REC_2;
extern double BORN_1, BORN_2;
extern double D_IONIS, D_CAPT;
extern double TAU_A, TAU_M;
extern double ETHICK_A, ETHICK_M;
extern double TTHICK_A, TTHICK_M;
extern double A_T, RHO;

extern long double FE[3];
extern long double FF[3][3];
extern long double FD[3];

/*const char *dir_files1="LISEcute/files";
const char *dir_files2="LISE/files";*/

const char *dir_files="/files";
const char *FileNameAbsent = "/cUntitled";
const char *LISEini="/lisepp.ini";

//QString FFileNameCS;
//QString FFileNameHtml;
QString LISErootPATH;
QString MyDocCompPATH;
QString localPATH;


extern int fontsizeGlobal;
extern int useHighDpiScaling;
FILE *mfopen(const QString& filename, const char* operand);

//WWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWW
void getInitialDir(void)
{
    //---------------------------------------------------------  paths begin

        MyDocCompPATH = QStandardPaths::standardLocations(QStandardPaths::DocumentsLocation).constFirst();

        QString FileCheck(LISErootPATH); FileCheck += LISEini;
        FILE *fcheck=mfopen(FileCheck,"at");
        int work_in_LISEroot_main = 0;

        if(fcheck) {                    // work in root directory
              fclose(fcheck);
              QSettings myLiseIni0(FileCheck,QSettings::IniFormat);
              work_in_LISEroot_main = myLiseIni0.value("Version/WorkInROOT",0).toInt();
              if(work_in_LISEroot_main) localPATH = LISErootPATH;
              }

        if(work_in_LISEroot_main==0)
              {
              localPATH = MyDocCompPATH;
              localPATH += "/LISEcute";
              }

        //--------------------------------------------------------- lise.ini  begin
          QString FN1=localPATH;  FN1 += LISEini;
          QSettings myLiseIni1(FN1,QSettings::IniFormat);
          fontsizeGlobal     = myLiseIni1.value("font/size",     fontsizeGlobal).toInt();
          useHighDpiScaling  = myLiseIni1.value("font/scaling",  useHighDpiScaling).toInt();
         //--------------------------------------------------------- lise.ini  end

     localPATH += dir_files;
     QDir pathDir(localPATH);
     if(!pathDir.exists()) pathDir.mkdir(localPATH);

    //---------------------------------------------------------  paths end

}
//WWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWW
//WWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWW
void MainWindow::setFileName(QString filename)
{
if(filename.size()>0) FFileName = filename;

//QString windowName = FFileName.split("/",Qt::SkipEmptyParts).last();
QFileInfo fI(FFileName);
QString windowName = fI.baseName();
if(!windowName.contains(&FileNameAbsent[1])) this->setWindowTitle("Charge - " + windowName);
else                                         this->setWindowTitle("Charge");
}
//WWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWW
int MainWindow::checkFileSave(void)
{
int flagVer = QMessageBox::No;
if ( modified ) {
        int flagVer=  QMessageBox::question(this, "Confirmation", "Save Changes?",
                              QMessageBox::Yes | QMessageBox::No | QMessageBox::Cancel,
                              QMessageBox::Yes);

        if(flagVer == QMessageBox::Yes) on_action_Save_triggered();
        }

return flagVer;
}
//WWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWW
//WWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWW-
//WWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWW
void MainWindow::on_action_Open_triggered()
{
if(checkFileSave()== QMessageBox::Cancel) return;

    QString sfile = QFileDialog::getOpenFileName(this,"Open", FFileName,
                "Charge files (*.charge);;All files (*.*)");


if(sfile.size()<=0) return;

setFileName(sfile);
readFile(sfile);
}
//WWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWW
void MainWindow::readFile(QString file)
{
    QFile f(file);

    FILE *f10=mfopen(FFileName,"rt");
    if(!f10) {
       QMessageBox::information(this, "Open File error","Check file orgigin\n" + FFileName);
       return;
       }
    fclose(f10);

QSettings myOpt(FFileName,QSettings::IniFormat);

myOpt.beginGroup("Projectile");
    Z_P   = myOpt.value("Z",  79).toInt();
    E_KIN = myOpt.value("Energy",   1000).toDouble();
myOpt.endGroup();

myOpt.beginGroup("Target");
    Z_T = myOpt.value("Z",  13).toInt();
    TTHICK_M = myOpt.value("Thickness", 100).toDouble();
myOpt.endGroup();

myOpt.beginGroup("InitFraction");
    iFR[0]    = myOpt.value("ZQ0",   1).toDouble();
    iFR[1]    = myOpt.value("ZQ1",   0).toDouble();
    iFR[2]    = myOpt.value("ZQ2",   0).toDouble();
myOpt.endGroup();

//-----------------------------------------------
setPage();
on_actionExecute_triggered();
}
//WWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWw
//WWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWw
//WWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWw
void MainWindow::on_action_Save_triggered()
{
if(FFileName.size()<=0)
    {
    QMessageBox::information(this, "Save operation error", "File name was not defined\nUse \"Save As\" command");
//    if ( !strcmp(JustName.c_str(), FileNameAbsent)){SaveAsMenuClick(Sender); return;}
    return;
    }

    FILE *f10=mfopen (FFileName, "wt");
    if(!f10) {
       QMessageBox::information(this, "Open File error","Check file origin\n" + FFileName);
       return;
       }

    fclose(f10);
    if(result < 0 || modified) on_actionExecute_triggered();

setFileName(FFileName);

QSettings myOpt(FFileName,QSettings::IniFormat);

myOpt.beginGroup("Projectile");
    myOpt.setValue("Z", Z_P);
    myOpt.setValue("Energy", E_KIN);
myOpt.endGroup();

myOpt.beginGroup("Target");
    myOpt.setValue("Z", Z_T);
    myOpt.setValue("Thickness", TTHICK_M);
    myOpt.setValue("ThicknessAtom", TTHICK_A);
myOpt.endGroup();

myOpt.beginGroup("InitFraction");
    myOpt.setValue("ZQ0", iFR[0]);
    myOpt.setValue("ZQ1", iFR[1]);
    myOpt.setValue("ZQ2", iFR[2]);
myOpt.endGroup();


myOpt.beginGroup("CrossSections");
    myOpt.setValue("EIKO_1", EIKO_1);
    myOpt.setValue("EIKO_2", EIKO_2);
    myOpt.setValue("REC_1", REC_1);
    myOpt.setValue("REC_2", REC_2);
    myOpt.setValue("BORN_1", BORN_1);
    myOpt.setValue("BORN_2", BORN_2);
    myOpt.setValue("D_CAPT", D_CAPT);
    myOpt.setValue("D_IONIS", D_IONIS);
myOpt.endGroup();


myOpt.beginGroup("Equlibrium");
    myOpt.setValue("ZQ0", (double)FE[0]);
    myOpt.setValue("ZQ1", (double)FE[1]);
    myOpt.setValue("ZQ2", (double)FE[2]);
    myOpt.setValue("EqThickM", ETHICK_M);
    myOpt.setValue("EqThickA", ETHICK_A);
    myOpt.setValue("EqThick2_M", TAU_M);
    myOpt.setValue("EqThick2_A", TAU_A);
myOpt.endGroup();


myOpt.beginGroup("Calc_for_UserConditions");
    myOpt.setValue("ZQ0", double(FD[0]));
    myOpt.setValue("ZQ1", double(FD[1]));
    myOpt.setValue("ZQ2", double(FD[2]));
myOpt.endGroup();

myOpt.beginGroup("Condition_ZQ0");
    myOpt.setValue("ZQ0", double(FF[0][0]));
    myOpt.setValue("ZQ1", double(FF[0][1]));
    myOpt.setValue("ZQ2", double(FF[0][2]));
myOpt.endGroup();

myOpt.beginGroup("Condition_ZQ1");
    myOpt.setValue("ZQ0", double(FF[1][0]));
    myOpt.setValue("ZQ1", double(FF[1][1]));
    myOpt.setValue("ZQ2", double(FF[1][2]));
myOpt.endGroup();

myOpt.beginGroup("Condition_ZQ2");
    myOpt.setValue("ZQ0", double(FF[2][0]));
    myOpt.setValue("ZQ1", double(FF[2][1]));
    myOpt.setValue("ZQ2", double(FF[2][2]));
myOpt.endGroup();

modified = false;
}
//WWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWW-
void MainWindow::on_action_Save_As_triggered()
{
QString sfile = QFileDialog::getSaveFileName(this,  "Save",   FFileName,
                                                 "CHARGE files (*.charge);;All files (*.*)");

if(sfile.size()<=0) return;

FFileName = sfile;
on_action_Save_triggered();
}
//WWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWW-
//WWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWW
//WWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWW
FILE *mfopen(const QString& filename, const char* operand)
{

#if !defined(__CYGWIN__) && !defined(_WIN32) && !defined(_WIN64)

  FILE *f =   fopen(filename.toStdString().c_str(),operand);

#else

  QString woperand(operand);
  FILE *f = _wfopen(filename.toStdWString().c_str(), woperand.toStdWString().c_str() );

#endif

return f;
}


//WWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWW
