#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QLabel>
#include <QKeyEvent>
#include <QPrinter>
namespace Ui {
class MainWindow;
}

class QTreeWidgetItem;
QT_END_NAMESPACE
//Foster
typedef QList<QTreeWidgetItem *> StyleItems;

class MainWindow : public QMainWindow
{
    Q_OBJECT    
//Foster
public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();


private:
    int result;
    bool Zedit_permit;
    bool modified;
    QString FFileName;
    double iFR[3]= {1,0,0};

    void setPage();
    void makeTarget();
    void clearPage();
    void results();
    void readPage();
    void calculateFraction();
    void setFileName(QString filename);
//    void getInitialDir();
    int checkFileSave();
    void readFile(QString file);

protected:
    void keyPressEvent(QKeyEvent *e);

private slots:
    void on_actionExecute_triggered();

    void on_target_combo_box_currentIndexChanged(int index);
    void on_thickness_edit_textEdited(const QString &arg1);
    void on_Element_edit_textEdited(const QString &arg1);
    void on_Z_edit_textEdited(const QString &arg1);

    void on_fractions0_textEdited(const QString &arg1);
    void on_fractions1_textEdited(const QString &arg1);
    void on_fractions2_textEdited(const QString &arg1);

    void on_actionWeb_Documentation_triggered();
    void on_action_About_triggered();
    void on_action_Print_triggered();
    //void on_printPreviewAction_triggered();
    void on_action_Exit_triggered();

    void on_action_Save_As_triggered();
    void on_action_Save_triggered();
    void on_action_Open_triggered();

    void on_actionPrint_Preview_triggered();
    void printPreview(QPrinter*);

private:
    Ui::MainWindow *ui;
    //Foster
    QMap<QString, StyleItems> currentPageMap();
    //Foster

};

#endif // MAINWINDOW_H
