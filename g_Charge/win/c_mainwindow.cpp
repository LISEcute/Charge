#include <QDesktopServices>
#include <QUrl>
#include <QErrorMessage>
#include <QDebug>
#include <QPainter>
#include <QRectF>
#include <QToolButton>
#include <QMessageBox>
#include <QPrinterInfo>
#include <QNetworkAccessManager>

#if defined(QT_PRINTSUPPORT_LIB)
#include <QtPrintSupport/qtprintsupportglobal.h>
#if QT_CONFIG(printer)
#if QT_CONFIG(printdialog)
#include <QPrintDialog>
#endif
#include <QPrinter>
#if QT_CONFIG(printpreviewdialog)
#include <QPrintPreviewDialog>
#endif
#endif
#endif

//---------------------------------------------
#include "c_mainwindow.h"
#include "ui_c_mainwindow.h"
#include "c_element.h"
#include "c_ftype.h"
#include "c_about.h"
#include "g_Charge/source/c_constant.h"




#define U_FC       aem_mg            // atomic mass unit in mg ;
// Foster version -// Foster version -// Foster version -// Foster version -// Foster version -

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

extern int TARGET(int Z_T);
extern int RunCharge();
extern int GetZfromName(QString el_init);
extern char* ElementName(int IZ);

extern long double FE[3];
extern long double FF[3][3];
extern long double FD[3];

extern QString LISErootPATH;
extern QString localPATH;
extern const char *FileNameAbsent;
extern QString FileArg;

//WWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWW
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
//------------------------------------------
    setWindowFlags( Qt::Window | Qt::CustomizeWindowHint |
                    Qt::WindowTitleHint | Qt::WindowSystemMenuHint |
                    Qt::WindowMinimizeButtonHint | Qt::WindowMaximizeButtonHint | Qt::WindowCloseButtonHint );
    //------------------------------------------

    int i=0;
    while(AvailableTarget[i].Element)
        ui->target_combo_box->addItem(AvailableTarget[i++].Element);

    Zedit_permit = true;


    modified = false;
    result = -777;

    for(int i=0; i<4;i++){
        ui->tableWidget->verticalHeader()->setSectionResizeMode(i, QHeaderView::Stretch);
        for(int j=0;j<3;j++){
            ui->tableWidget->item(i,j)->setText("0");
            }
        }

    ui->tableWidget->horizontalHeader()->setMinimumHeight(25);
    ui->tableWidget->verticalHeader()->setMinimumWidth(75);

    ui->tableWidget->horizontalHeader()->setSectionResizeMode(0, QHeaderView::Stretch);
    ui->tableWidget->horizontalHeader()->setSectionResizeMode(1, QHeaderView::Stretch);
    ui->tableWidget->horizontalHeader()->setSectionResizeMode(2, QHeaderView::Stretch);

    ui->tableWidget->horizontalHeader()->setVisible(true);  // some Qt-gluk , it's necessary to declare here
    ui->tableWidget->verticalHeader()->setVisible(true);


    FFileName  = FileArg.size()>0? FileArg : localPATH + FileNameAbsent;
    setFileName(FFileName);
    if(FileArg.size()>0) readFile(FFileName);

    //QMessageBox::information(this, LISErootPATH, FFileName +"\n" + localPATH);
    setPage();
}
//WWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWW
MainWindow::~MainWindow(){    delete ui;}
//WWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWW
void MainWindow::keyPressEvent(QKeyEvent *e)
{
    qDebug() << "keyPressEvent";
    if(e->key()==Qt::Key_Enter || e->key()==Qt::Key_Return){
        qDebug() << "Enter pressed";
        on_actionExecute_triggered();
    }
}
//WWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWW
void MainWindow::setPage()
{
    Zedit_permit = true;
    int i=0;
    while(Z_T > AvailableTarget[i].Z &&
            AvailableTarget[i].Element)
                                      i++;

    if(!AvailableTarget[i].Element) i--;

    ui->target_combo_box->setCurrentIndex(i);
    on_target_combo_box_currentIndexChanged(i);

    ui->Z_edit->setText(QString::number(Z_P));
    on_Z_edit_textEdited(QString::number(Z_P));
    ui->energy_edit->setText(QString::number(E_KIN));
    ui->thickness_edit->setText(QString::number(TTHICK_M));
    ui->fractions0->setText(QString::number(iFR[0]));
    ui->fractions1->setText(QString::number(iFR[1]));
    ui->fractions2->setText(QString::number(iFR[2]));

    calculateFraction();

    clearPage();     modified=false;
}
//WWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWW
void MainWindow::makeTarget()
{
    TARGET(Z_T);
    TTHICK_A = TTHICK_M/(A_T*U_FC);
    ui->thickness_label->setText(QString::number(TTHICK_A,'e',4));
    clearPage();
}
//WWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWW
void MainWindow::clearPage()
{
    ui->eiko1_label->setText("-");
    ui->eiko12_label->setText("-");
    ui->rec1_label->setText("-");
    ui->rec12_label->setText("-");
    ui->born1_abel->setText("-");
    ui->born2_label->setText("-");
    ui->dcap02->setText("-");
    ui->dcap20->setText("-");

    ui->code1_label->setText("-");
    ui->code2_label->setText("-");
    ui->thie1_label->setText("-");
    ui->thie2_label->setText("-");

    ui->eq0_label->setText("-");
    ui->eq1_label->setText("-");
    ui->eq2_label->setText("-");

    for(int i=0; i<4;i++){
        for(int j=0;j<3;j++){
            ui->tableWidget->item(i,j)->setText(" ");
        }
    }

result =-777;
}
//WWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWW
void MainWindow::results()
{
    ui->eiko1_label->setText(QString::number(EIKO_1,'e',4));
//    ui->eiko1_label->setText(QString::number(QSslSocket::supportsSsl()));

    ui->eiko12_label->setText(QString::number(EIKO_2,'e',4));
    ui->rec1_label->setText(QString::number(REC_1,'e',4));
    ui->rec12_label->setText(QString::number(REC_2,'e',4));
    ui->born1_abel->setText(QString::number(BORN_1,'e',4));
    ui->born2_label->setText(QString::number(BORN_2,'e',4));
    ui->dcap02->setText(QString::number(D_CAPT,'e',4));
    ui->dcap20->setText(QString::number(D_IONIS,'e',4));

    ui->eq0_label->setText(QString::number(FE[0],'e',3));
    ui->eq1_label->setText(QString::number(FE[1],'e',3));
    ui->eq2_label->setText(QString::number(FE[2],'e',3));

    ui->code1_label->setText(QString::number(ETHICK_M,'e',4));
    ui->code2_label->setText(QString::number(ETHICK_A,'e',4));
    ui->thie1_label->setText(QString::number(TAU_M,'e',4));
    ui->thie2_label->setText(QString::number(TAU_A,'e',4));

    for(int j=0;j<3;j++){
            ui->tableWidget->item(0,j)->setText(QString::number((double)FD[j],'e',3));
        }

    for(int i=1; i<4;i++){
        for(int j=0;j<3;j++){
            ui->tableWidget->item(i,j)->setText(QString::number((double)FF[i-1][j],'e',3));
        }
    }
}
//WWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWW
void MainWindow::readPage()
{
    Z_T = AvailableTarget[ui->target_combo_box->currentIndex()].Z;
    E_KIN = ui->energy_edit->text().toDouble();
}
//WWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWW
void MainWindow::calculateFraction()
{
    double Sum=iFR[0]+iFR[1]+iFR[2];

    if(Sum<0) {
            FR[0] =1;
            FR[1]= FR[2] =0;
            }
    else    for(int i=0; i<3; i++)
                     FR[i]=iFR[i]/Sum;

    ui->norm0->setText(QString::number(FR[0],'f',4));
    ui->norm1->setText(QString::number(FR[1],'f',4));
    ui->norm2->setText(QString::number(FR[2],'f',4));
}
//WWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWW
void MainWindow::on_target_combo_box_currentIndexChanged(int index)
{
    Z_T = AvailableTarget[index].Z;
    QString zz = "Z = " + QString::number(Z_T);
    ui->Z_label->setText(zz);

    modified = true;
    makeTarget();
}
//WWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWW
void MainWindow::on_actionExecute_triggered()
{
    readPage();

    result = RunCharge();
    if(result<0){
        QString cc;
        switch(result) {
                  case -1  : cc="Convergence cannot be reached"; break;
                  case -2  : cc="Fraction FRN2 < 0.\n\rIncrease energy"; break;
                  case -3  : cc="Fraction FRN1 < 0.\n\rIncrease energy"; break;
                  case -5  : cc="Overflow in the final\n\r"
                                "fraction calculation.\n\r"
                                "1.Increase energy?\n\r"
                                "2.Decrease thickness?"; break;
                  case -6  : cc="one of 'charge_data' files is absent"; break;
                  case -11  : cc="file 'Target' is absent"; break;
                  case -12  :
                  case -13  :
                  case -14  : cc="Error in subroutine 'Target'"; break;

                  default : cc=" ";
                  }
        QErrorMessage em;
        em.showMessage(cc);
        em.exec();
    }
results();
}
//WWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWW
void MainWindow::on_thickness_edit_textEdited(const QString &arg1)
{
    TTHICK_M = arg1.toDouble();
    modified=true;
    makeTarget();
}
//WWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWW
void MainWindow::on_Element_edit_textEdited(const QString &arg1)
{
if(!Zedit_permit) return;
if(arg1.isEmpty()) return;

int Z = GetZfromName(arg1);
// qDebug() << "Z = " << Z;
if(Z > 3 && Z < 131) {
    //  qDebug() << "Z = " << Z;
    Zedit_permit = false;
    Z_P = Z;
    ui->Z_edit->setText(QString::number(Z_P));
    clearPage();

    modified = true;               Zedit_permit=true;
    }
}
//WWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWW
void MainWindow::on_Z_edit_textEdited(const QString &arg1)
{
    if(!Zedit_permit) return;
    if(arg1.isEmpty()) return;
    Zedit_permit = false;

    Z_P = arg1.toInt();
    char *el = ElementName(Z_P);
    char elm[2];
    elm[0] = el[0];
    elm[1] = el[1];
    //qDebug() << elm;
    QString em = QString::fromLocal8Bit(elm,2);//QString::fromStdString(elm);// + elm[1];
    ui->Element_edit->setText(em);
    Zedit_permit = true;

    modified = true;    clearPage();
}
//WWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWW
void MainWindow::on_fractions0_textEdited(const QString &arg1)
{
    iFR[0] = qMax(arg1.toDouble(), 0.);
    calculateFraction();
    modified=true;     clearPage();
}
//WWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWW
void MainWindow::on_fractions1_textEdited(const QString &arg1)
{
    iFR[1] = qMax(arg1.toDouble(), 0.);
    calculateFraction();

    modified=true;  clearPage();
}
//WWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWW
void MainWindow::on_fractions2_textEdited(const QString &arg1)
{
    iFR[2] = qMax(arg1.toDouble(), 0.);
    calculateFraction();
    modified=true;   clearPage();
}
//WWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWW
void MainWindow::on_actionWeb_Documentation_triggered()
{
    QDesktopServices::openUrl(QUrl("http://lise.nscl.msu.edu/6_2/lise++_6_2.pdf#page=3"));
}
//WWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWW
void MainWindow::on_action_About_triggered()
{
    About *about_page = new About;
    about_page->setWindowFlags(Qt::CustomizeWindowHint |
                               Qt::WindowTitleHint | Qt::WindowCloseButtonHint);

    about_page->show();
}
//WWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWW
void MainWindow::on_action_Exit_triggered()
{
if(checkFileSave()== QMessageBox::Cancel) return;
exit(1);
}
//WWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWW
QMap<QString, StyleItems> MainWindow::currentPageMap()
{
    QMap<QString, StyleItems> pageMap;
    return pageMap;
}
//WWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWW
void MainWindow::on_action_Print_triggered()
{
#if defined(QT_PRINTSUPPORT_LIB) && QT_CONFIG(printer)

    QPrinter printer(QPrinter::HighResolution);
    printer.setOutputFormat(QPrinter::NativeFormat);
//    printer.setOutputFormat(QPrinter::PdfFormat);
    QPrintDialog printDialog(&printer, this);
    printDialog.setWindowTitle(tr("Print Widget"));

    if (printDialog.exec() != QDialog::Accepted)  return;

    QPainter painter;
    painter.begin(&printer);


    double xscale = printer.pageRect(QPrinter::DevicePixel).width()/double(this->width());
    double yscale = printer.pageRect(QPrinter::DevicePixel).height()/double(this->height());
    double scale = 0.9 * qMin(xscale, yscale);
    painter.translate(printer.paperRect(QPrinter::DevicePixel).x() + printer.pageRect(QPrinter::DevicePixel).width()/2,
                      printer.paperRect(QPrinter::DevicePixel).y() + printer.pageRect(QPrinter::DevicePixel).height()/2);


    painter.scale(scale, scale);
    painter.translate(-width()/2, -height()/2);

    this->render(&painter);
    painter.end();

#endif
}
//WWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWW
void MainWindow::on_actionPrint_Preview_triggered()
{
#ifndef QT_NO_PRINTER
    QPrinter printer(QPrinter::HighResolution);
    QPrintPreviewDialog preview(&printer, this);
    int width = 1.2 * printer.pageRect(QPrinter::Point).width();
    int height = 1.2 * printer.pageRect(QPrinter::Point).height();
    preview.setMinimumSize(width,height);
    preview.setWindowFlags ( Qt::Window );
    setWindowTitle(tr("Print Preview"));
    connect(&preview, SIGNAL(paintRequested(QPrinter*)),this, SLOT(printPreview(QPrinter*)));
    preview.exec();
#endif
}
//WWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWW
void MainWindow::printPreview(QPrinter* printer)
{
// Oleg --> it goes to pdf only

    QPainter painter(printer);
    painter.setRenderHints(QPainter::Antialiasing |
                           QPainter::TextAntialiasing |
                           QPainter::SmoothPixmapTransform, true);
    double xscale = printer->pageRect(QPrinter::DevicePixel).width()/double(this->width());
    double yscale = printer->pageRect(QPrinter::DevicePixel).height()/double(this->height());
    double scale = 0.9 * qMin(xscale, yscale);
    painter.translate(printer->paperRect(QPrinter::DevicePixel).x() + printer->pageRect(QPrinter::DevicePixel).width()/2,
                      printer->paperRect(QPrinter::DevicePixel).y() + printer->pageRect(QPrinter::DevicePixel).height()/2);

    painter.scale(scale, scale);
    painter.translate(-width()/2, -height()/2);

    this->render(&painter);
}
//WWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWW
