#include "c_mainwindow.h"
#include <QApplication>
#include <QStyleFactory>

#include <QDir>
#include <QSettings>
#include <QStandardPaths>
#include <QNetworkAccessManager>

extern void getInitialDir(void);

extern QString LISErootPATH;
extern QString MyDocCompPATH;
extern const char *LISEini;

QString FileArg="";
int fontsizeGlobal=9;
int useHighDpiScaling=1;

//WWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWW

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

//    qDebug() << QSslSocket::supportsSsl()
//             << QSslSocket::sslLibraryBuildVersionString()
//             << QSslSocket::sslLibraryVersionString();


    LISErootPATH = QCoreApplication::applicationDirPath();
    if(LISErootPATH.size()<=0)
        {
        QString arg0 = QDir::fromNativeSeparators(argv[0]);
        QDir dir(arg0);
        LISErootPATH = dir.currentPath();
        }

    if(argc>1) FileArg = QDir::fromNativeSeparators(argv[1]);

    //---------------------------------------------------------------------------------- read font size start
    getInitialDir();

//    if(!useHighDpiScaling)
//      QCoreApplication::setAttribute(Qt::AA_Use96Dpi);

 //   QApplication::setAttribute(useHighDpiScaling ? Qt::AA_EnableHighDpiScaling :
//                                                   Qt::AA_DisableHighDpiScaling);
    //---------------------------------------------------------------------------------- read font size stop

    //------------------------------------------------------------------ style start
    app.setFont(QFont("Arial", fontsizeGlobal, QFont::Normal));
    app.setOrganizationName("FRIB/MSU");
    app.setStyle(QStyleFactory::create("Fusion"));
    QFile FileStyle(":/w_Main/mainstyle.qss");
    FileStyle.open(QFile::ReadOnly);
    QString StyleSheet = QLatin1String(FileStyle.readAll());
    qApp->setStyleSheet(StyleSheet);
     //------------------------------------------------------------------ style end

    //qApp->addLibraryPath("./plugins");

    MainWindow w;
    w.show();

    return app.exec();
}
