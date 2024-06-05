/********************************************************************************
** Form generated from reading UI file 'c_mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_C_MAINWINDOW_H
#define UI_C_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *action_Open;
    QAction *action_Save;
    QAction *action_Save_As;
    QAction *action_Print;
    QAction *action_Exit;
    QAction *action_About;
    QAction *actionWeb_Documentation;
    QAction *actionExecute;
    QAction *actionPrint_Preview;
    QWidget *centralWidget;
    QVBoxLayout *verticalLayout_3;
    QHBoxLayout *horizontalLayout_2;
    QGroupBox *ProjectileBox;
    QGridLayout *gridLayout_2;
    QSpacerItem *verticalSpacer;
    QLabel *label_3;
    QLineEdit *energy_edit;
    QLabel *label;
    QLineEdit *Z_edit;
    QLineEdit *Element_edit;
    QLabel *label_4;
    QLabel *label_2;
    QSpacerItem *horizontalSpacer_3;
    QGroupBox *groupBox;
    QGridLayout *gridLayout_3;
    QLabel *label_5;
    QLabel *label_8;
    QLabel *label_7;
    QLabel *label_9;
    QLineEdit *fractions0;
    QLineEdit *fractions1;
    QLabel *norm0;
    QLabel *norm1;
    QLineEdit *fractions2;
    QLabel *norm2;
    QLabel *label_6;
    QSpacerItem *horizontalSpacer_4;
    QGroupBox *TargetBox;
    QGridLayout *gridLayout_4;
    QLabel *label_17;
    QLabel *thickness_label;
    QLabel *label_15;
    QLineEdit *thickness_edit;
    QComboBox *target_combo_box;
    QLabel *label_14;
    QLabel *Z_label;
    QSpacerItem *horizontalSpacer;
    QSpacerItem *horizontalSpacer_2;
    QHBoxLayout *horizontalLayout;
    QGroupBox *groupBox_3;
    QGridLayout *gridLayout_5;
    QLabel *label_19;
    QLabel *eiko1_label;
    QLabel *label_21;
    QLabel *label_18;
    QLabel *born1_abel;
    QLabel *label_22;
    QLabel *eiko12_label;
    QLabel *label_24;
    QLabel *label_25;
    QLabel *label_26;
    QLabel *rec1_label;
    QLabel *label_28;
    QLabel *label_29;
    QLabel *label_36;
    QLabel *label_35;
    QLabel *label_33;
    QLabel *born2_label;
    QLabel *rec12_label;
    QLabel *label_31;
    QLabel *label_32;
    QLabel *label_38;
    QLabel *label_39;
    QLabel *label_40;
    QLabel *dcap02;
    QLabel *label_42;
    QLabel *label_43;
    QLabel *dcap20;
    QLabel *label_45;
    QVBoxLayout *verticalLayout_2;
    QGroupBox *groupBox_4;
    QGridLayout *gridLayout_6;
    QLabel *code1_label;
    QLabel *code2_label;
    QLabel *eq1_label;
    QLabel *eq0_label;
    QLabel *thie1_label;
    QLabel *thie2_label;
    QLabel *eq2_label;
    QLabel *label_54;
    QLabel *label_46;
    QLabel *label_52;
    QLabel *label_56;
    QLabel *label_55;
    QLabel *label_47;
    QLabel *label_48;
    QLabel *label_53;
    QFrame *line;
    QGroupBox *groupBox_5;
    QVBoxLayout *verticalLayout;
    QTableWidget *tableWidget;
    QMenuBar *menuBar;
    QMenu *menuFile;
    QMenu *menuHelp;
    QToolBar *mainToolBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(638, 615);
        QSizePolicy sizePolicy(QSizePolicy::Policy::Preferred, QSizePolicy::Policy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(MainWindow->sizePolicy().hasHeightForWidth());
        MainWindow->setSizePolicy(sizePolicy);
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/icons/charge1.ico"), QSize(), QIcon::Normal, QIcon::Off);
        MainWindow->setWindowIcon(icon);
        MainWindow->setToolButtonStyle(Qt::ToolButtonTextBesideIcon);
        action_Open = new QAction(MainWindow);
        action_Open->setObjectName("action_Open");
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/icons/open.png"), QSize(), QIcon::Normal, QIcon::Off);
        action_Open->setIcon(icon1);
        action_Save = new QAction(MainWindow);
        action_Save->setObjectName("action_Save");
        QIcon icon2;
        icon2.addFile(QString::fromUtf8(":/icons/save.png"), QSize(), QIcon::Normal, QIcon::Off);
        action_Save->setIcon(icon2);
        action_Save_As = new QAction(MainWindow);
        action_Save_As->setObjectName("action_Save_As");
        action_Print = new QAction(MainWindow);
        action_Print->setObjectName("action_Print");
        action_Print->setPriority(QAction::LowPriority);
        action_Exit = new QAction(MainWindow);
        action_Exit->setObjectName("action_Exit");
        action_About = new QAction(MainWindow);
        action_About->setObjectName("action_About");
        QIcon icon3;
        icon3.addFile(QString::fromUtf8(":/icons/lisepp_small.bmp"), QSize(), QIcon::Normal, QIcon::Off);
        action_About->setIcon(icon3);
        actionWeb_Documentation = new QAction(MainWindow);
        actionWeb_Documentation->setObjectName("actionWeb_Documentation");
        actionExecute = new QAction(MainWindow);
        actionExecute->setObjectName("actionExecute");
        QIcon icon4;
        icon4.addFile(QString::fromUtf8(":/icons/bolt1.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionExecute->setIcon(icon4);
        actionPrint_Preview = new QAction(MainWindow);
        actionPrint_Preview->setObjectName("actionPrint_Preview");
        actionPrint_Preview->setPriority(QAction::LowPriority);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName("centralWidget");
        verticalLayout_3 = new QVBoxLayout(centralWidget);
        verticalLayout_3->setSpacing(10);
        verticalLayout_3->setContentsMargins(11, 11, 11, 11);
        verticalLayout_3->setObjectName("verticalLayout_3");
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(10);
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        ProjectileBox = new QGroupBox(centralWidget);
        ProjectileBox->setObjectName("ProjectileBox");
        QSizePolicy sizePolicy1(QSizePolicy::Policy::Preferred, QSizePolicy::Policy::Preferred);
        sizePolicy1.setHorizontalStretch(1);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(ProjectileBox->sizePolicy().hasHeightForWidth());
        ProjectileBox->setSizePolicy(sizePolicy1);
        ProjectileBox->setStyleSheet(QString::fromUtf8("QLineEdit {\n"
"max-width: 85px;\n"
"}"));
        gridLayout_2 = new QGridLayout(ProjectileBox);
        gridLayout_2->setSpacing(6);
        gridLayout_2->setContentsMargins(11, 11, 11, 11);
        gridLayout_2->setObjectName("gridLayout_2");
        verticalSpacer = new QSpacerItem(20, 10, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Fixed);

        gridLayout_2->addItem(verticalSpacer, 3, 3, 1, 1);

        label_3 = new QLabel(ProjectileBox);
        label_3->setObjectName("label_3");
        label_3->setLayoutDirection(Qt::RightToLeft);
        label_3->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout_2->addWidget(label_3, 2, 5, 1, 1);

        energy_edit = new QLineEdit(ProjectileBox);
        energy_edit->setObjectName("energy_edit");
        QSizePolicy sizePolicy2(QSizePolicy::Policy::Preferred, QSizePolicy::Policy::Fixed);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(energy_edit->sizePolicy().hasHeightForWidth());
        energy_edit->setSizePolicy(sizePolicy2);
        energy_edit->setMinimumSize(QSize(60, 0));
        energy_edit->setMaximumSize(QSize(87, 16777215));
        energy_edit->setAlignment(Qt::AlignCenter);

        gridLayout_2->addWidget(energy_edit, 2, 6, 1, 1);

        label = new QLabel(ProjectileBox);
        label->setObjectName("label");
        sizePolicy.setHeightForWidth(label->sizePolicy().hasHeightForWidth());
        label->setSizePolicy(sizePolicy);
        label->setAlignment(Qt::AlignCenter);

        gridLayout_2->addWidget(label, 0, 0, 1, 1);

        Z_edit = new QLineEdit(ProjectileBox);
        Z_edit->setObjectName("Z_edit");
        Z_edit->setMinimumSize(QSize(50, 0));
        Z_edit->setMaximumSize(QSize(87, 16777215));
        Z_edit->setAlignment(Qt::AlignCenter);

        gridLayout_2->addWidget(Z_edit, 2, 3, 1, 1);

        Element_edit = new QLineEdit(ProjectileBox);
        Element_edit->setObjectName("Element_edit");
        sizePolicy2.setHeightForWidth(Element_edit->sizePolicy().hasHeightForWidth());
        Element_edit->setSizePolicy(sizePolicy2);
        Element_edit->setMinimumSize(QSize(50, 0));
        Element_edit->setMaximumSize(QSize(87, 16777215));
        Element_edit->setAlignment(Qt::AlignCenter);

        gridLayout_2->addWidget(Element_edit, 2, 0, 1, 1);

        label_4 = new QLabel(ProjectileBox);
        label_4->setObjectName("label_4");

        gridLayout_2->addWidget(label_4, 2, 7, 1, 1);

        label_2 = new QLabel(ProjectileBox);
        label_2->setObjectName("label_2");
        sizePolicy.setHeightForWidth(label_2->sizePolicy().hasHeightForWidth());
        label_2->setSizePolicy(sizePolicy);
        label_2->setAlignment(Qt::AlignCenter);

        gridLayout_2->addWidget(label_2, 0, 3, 1, 1);

        horizontalSpacer_3 = new QSpacerItem(15, 20, QSizePolicy::Policy::MinimumExpanding, QSizePolicy::Policy::Minimum);

        gridLayout_2->addItem(horizontalSpacer_3, 2, 4, 1, 1);

        groupBox = new QGroupBox(ProjectileBox);
        groupBox->setObjectName("groupBox");
        groupBox->setAutoFillBackground(false);
        groupBox->setStyleSheet(QString::fromUtf8("QLineEdit {\n"
"max-width: 50px;\n"
"}"));
        gridLayout_3 = new QGridLayout(groupBox);
        gridLayout_3->setSpacing(6);
        gridLayout_3->setContentsMargins(11, 11, 11, 11);
        gridLayout_3->setObjectName("gridLayout_3");
        gridLayout_3->setHorizontalSpacing(11);
        label_5 = new QLabel(groupBox);
        label_5->setObjectName("label_5");
        sizePolicy.setHeightForWidth(label_5->sizePolicy().hasHeightForWidth());
        label_5->setSizePolicy(sizePolicy);
        label_5->setAlignment(Qt::AlignCenter);

        gridLayout_3->addWidget(label_5, 0, 1, 1, 1);

        label_8 = new QLabel(groupBox);
        label_8->setObjectName("label_8");
        label_8->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout_3->addWidget(label_8, 1, 0, 1, 1);

        label_7 = new QLabel(groupBox);
        label_7->setObjectName("label_7");
        sizePolicy.setHeightForWidth(label_7->sizePolicy().hasHeightForWidth());
        label_7->setSizePolicy(sizePolicy);
        label_7->setAlignment(Qt::AlignCenter);

        gridLayout_3->addWidget(label_7, 0, 3, 1, 1);

        label_9 = new QLabel(groupBox);
        label_9->setObjectName("label_9");
        label_9->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout_3->addWidget(label_9, 2, 0, 1, 1);

        fractions0 = new QLineEdit(groupBox);
        fractions0->setObjectName("fractions0");
        sizePolicy2.setHeightForWidth(fractions0->sizePolicy().hasHeightForWidth());
        fractions0->setSizePolicy(sizePolicy2);
        fractions0->setMinimumSize(QSize(50, 0));
        fractions0->setAlignment(Qt::AlignCenter);

        gridLayout_3->addWidget(fractions0, 1, 1, 1, 1);

        fractions1 = new QLineEdit(groupBox);
        fractions1->setObjectName("fractions1");
        sizePolicy2.setHeightForWidth(fractions1->sizePolicy().hasHeightForWidth());
        fractions1->setSizePolicy(sizePolicy2);
        fractions1->setMinimumSize(QSize(50, 0));
        fractions1->setAlignment(Qt::AlignCenter);

        gridLayout_3->addWidget(fractions1, 1, 2, 1, 1);

        norm0 = new QLabel(groupBox);
        norm0->setObjectName("norm0");
        norm0->setAlignment(Qt::AlignCenter);

        gridLayout_3->addWidget(norm0, 2, 1, 1, 1);

        norm1 = new QLabel(groupBox);
        norm1->setObjectName("norm1");
        norm1->setAlignment(Qt::AlignCenter);

        gridLayout_3->addWidget(norm1, 2, 2, 1, 1);

        fractions2 = new QLineEdit(groupBox);
        fractions2->setObjectName("fractions2");
        sizePolicy2.setHeightForWidth(fractions2->sizePolicy().hasHeightForWidth());
        fractions2->setSizePolicy(sizePolicy2);
        fractions2->setMinimumSize(QSize(50, 0));
        fractions2->setAlignment(Qt::AlignCenter);

        gridLayout_3->addWidget(fractions2, 1, 3, 1, 1);

        norm2 = new QLabel(groupBox);
        norm2->setObjectName("norm2");
        norm2->setAlignment(Qt::AlignCenter);

        gridLayout_3->addWidget(norm2, 2, 3, 1, 1);

        label_6 = new QLabel(groupBox);
        label_6->setObjectName("label_6");
        sizePolicy.setHeightForWidth(label_6->sizePolicy().hasHeightForWidth());
        label_6->setSizePolicy(sizePolicy);
        label_6->setAlignment(Qt::AlignCenter);

        gridLayout_3->addWidget(label_6, 0, 2, 1, 1);

        horizontalSpacer_4 = new QSpacerItem(5, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        gridLayout_3->addItem(horizontalSpacer_4, 1, 4, 1, 1);

        gridLayout_3->setColumnStretch(0, 2);
        gridLayout_3->setColumnStretch(1, 3);
        gridLayout_3->setColumnStretch(2, 3);
        gridLayout_3->setColumnStretch(3, 3);
        gridLayout_3->setColumnStretch(4, 1);

        gridLayout_2->addWidget(groupBox, 4, 0, 1, 8);

        gridLayout_2->setRowStretch(4, 2);

        horizontalLayout_2->addWidget(ProjectileBox);

        TargetBox = new QGroupBox(centralWidget);
        TargetBox->setObjectName("TargetBox");
        TargetBox->setStyleSheet(QString::fromUtf8("max-width: 3000px;"));
        gridLayout_4 = new QGridLayout(TargetBox);
        gridLayout_4->setSpacing(6);
        gridLayout_4->setContentsMargins(11, 11, 11, 11);
        gridLayout_4->setObjectName("gridLayout_4");
        gridLayout_4->setHorizontalSpacing(12);
        gridLayout_4->setVerticalSpacing(10);
        gridLayout_4->setContentsMargins(-1, 25, -1, -1);
        label_17 = new QLabel(TargetBox);
        label_17->setObjectName("label_17");

        gridLayout_4->addWidget(label_17, 3, 2, 1, 1);

        thickness_label = new QLabel(TargetBox);
        thickness_label->setObjectName("thickness_label");
        thickness_label->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout_4->addWidget(thickness_label, 3, 1, 1, 1);

        label_15 = new QLabel(TargetBox);
        label_15->setObjectName("label_15");

        gridLayout_4->addWidget(label_15, 2, 2, 1, 1);

        thickness_edit = new QLineEdit(TargetBox);
        thickness_edit->setObjectName("thickness_edit");
        sizePolicy2.setHeightForWidth(thickness_edit->sizePolicy().hasHeightForWidth());
        thickness_edit->setSizePolicy(sizePolicy2);
        thickness_edit->setAlignment(Qt::AlignCenter);

        gridLayout_4->addWidget(thickness_edit, 2, 1, 1, 1);

        target_combo_box = new QComboBox(TargetBox);
        target_combo_box->setObjectName("target_combo_box");

        gridLayout_4->addWidget(target_combo_box, 0, 1, 1, 1);

        label_14 = new QLabel(TargetBox);
        label_14->setObjectName("label_14");
        label_14->setAlignment(Qt::AlignBottom|Qt::AlignLeading|Qt::AlignLeft);

        gridLayout_4->addWidget(label_14, 1, 1, 1, 1);

        Z_label = new QLabel(TargetBox);
        Z_label->setObjectName("Z_label");

        gridLayout_4->addWidget(Z_label, 0, 2, 1, 1);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        gridLayout_4->addItem(horizontalSpacer, 0, 0, 1, 1);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        gridLayout_4->addItem(horizontalSpacer_2, 0, 3, 1, 1);


        horizontalLayout_2->addWidget(TargetBox);

        horizontalLayout_2->setStretch(0, 1);
        horizontalLayout_2->setStretch(1, 1);

        verticalLayout_3->addLayout(horizontalLayout_2);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(10);
        horizontalLayout->setObjectName("horizontalLayout");
        groupBox_3 = new QGroupBox(centralWidget);
        groupBox_3->setObjectName("groupBox_3");
        QSizePolicy sizePolicy3(QSizePolicy::Policy::Preferred, QSizePolicy::Policy::Preferred);
        sizePolicy3.setHorizontalStretch(1);
        sizePolicy3.setVerticalStretch(1);
        sizePolicy3.setHeightForWidth(groupBox_3->sizePolicy().hasHeightForWidth());
        groupBox_3->setSizePolicy(sizePolicy3);
        gridLayout_5 = new QGridLayout(groupBox_3);
        gridLayout_5->setSpacing(6);
        gridLayout_5->setContentsMargins(11, 11, 11, 11);
        gridLayout_5->setObjectName("gridLayout_5");
        gridLayout_5->setVerticalSpacing(10);
        label_19 = new QLabel(groupBox_3);
        label_19->setObjectName("label_19");

        gridLayout_5->addWidget(label_19, 1, 0, 1, 1);

        eiko1_label = new QLabel(groupBox_3);
        eiko1_label->setObjectName("eiko1_label");

        gridLayout_5->addWidget(eiko1_label, 1, 1, 1, 1);

        label_21 = new QLabel(groupBox_3);
        label_21->setObjectName("label_21");

        gridLayout_5->addWidget(label_21, 1, 2, 1, 1);

        label_18 = new QLabel(groupBox_3);
        label_18->setObjectName("label_18");
        label_18->setAlignment(Qt::AlignCenter);

        gridLayout_5->addWidget(label_18, 0, 0, 1, 3);

        born1_abel = new QLabel(groupBox_3);
        born1_abel->setObjectName("born1_abel");

        gridLayout_5->addWidget(born1_abel, 7, 1, 1, 1);

        label_22 = new QLabel(groupBox_3);
        label_22->setObjectName("label_22");

        gridLayout_5->addWidget(label_22, 2, 0, 1, 1);

        eiko12_label = new QLabel(groupBox_3);
        eiko12_label->setObjectName("eiko12_label");

        gridLayout_5->addWidget(eiko12_label, 2, 1, 1, 1);

        label_24 = new QLabel(groupBox_3);
        label_24->setObjectName("label_24");

        gridLayout_5->addWidget(label_24, 2, 2, 1, 1);

        label_25 = new QLabel(groupBox_3);
        label_25->setObjectName("label_25");
        label_25->setAlignment(Qt::AlignCenter);

        gridLayout_5->addWidget(label_25, 3, 0, 1, 3);

        label_26 = new QLabel(groupBox_3);
        label_26->setObjectName("label_26");

        gridLayout_5->addWidget(label_26, 4, 0, 1, 1);

        rec1_label = new QLabel(groupBox_3);
        rec1_label->setObjectName("rec1_label");

        gridLayout_5->addWidget(rec1_label, 4, 1, 1, 1);

        label_28 = new QLabel(groupBox_3);
        label_28->setObjectName("label_28");

        gridLayout_5->addWidget(label_28, 4, 2, 1, 1);

        label_29 = new QLabel(groupBox_3);
        label_29->setObjectName("label_29");

        gridLayout_5->addWidget(label_29, 5, 0, 1, 1);

        label_36 = new QLabel(groupBox_3);
        label_36->setObjectName("label_36");

        gridLayout_5->addWidget(label_36, 8, 0, 1, 1);

        label_35 = new QLabel(groupBox_3);
        label_35->setObjectName("label_35");

        gridLayout_5->addWidget(label_35, 7, 2, 1, 1);

        label_33 = new QLabel(groupBox_3);
        label_33->setObjectName("label_33");

        gridLayout_5->addWidget(label_33, 7, 0, 1, 1);

        born2_label = new QLabel(groupBox_3);
        born2_label->setObjectName("born2_label");

        gridLayout_5->addWidget(born2_label, 8, 1, 1, 1);

        rec12_label = new QLabel(groupBox_3);
        rec12_label->setObjectName("rec12_label");

        gridLayout_5->addWidget(rec12_label, 5, 1, 1, 1);

        label_31 = new QLabel(groupBox_3);
        label_31->setObjectName("label_31");

        gridLayout_5->addWidget(label_31, 5, 2, 1, 1);

        label_32 = new QLabel(groupBox_3);
        label_32->setObjectName("label_32");
        label_32->setAlignment(Qt::AlignCenter);

        gridLayout_5->addWidget(label_32, 6, 0, 1, 3);

        label_38 = new QLabel(groupBox_3);
        label_38->setObjectName("label_38");

        gridLayout_5->addWidget(label_38, 8, 2, 1, 1);

        label_39 = new QLabel(groupBox_3);
        label_39->setObjectName("label_39");
        label_39->setAlignment(Qt::AlignCenter);

        gridLayout_5->addWidget(label_39, 9, 0, 1, 3);

        label_40 = new QLabel(groupBox_3);
        label_40->setObjectName("label_40");

        gridLayout_5->addWidget(label_40, 10, 0, 1, 1);

        dcap02 = new QLabel(groupBox_3);
        dcap02->setObjectName("dcap02");

        gridLayout_5->addWidget(dcap02, 10, 1, 1, 1);

        label_42 = new QLabel(groupBox_3);
        label_42->setObjectName("label_42");

        gridLayout_5->addWidget(label_42, 10, 2, 1, 1);

        label_43 = new QLabel(groupBox_3);
        label_43->setObjectName("label_43");

        gridLayout_5->addWidget(label_43, 11, 0, 1, 1);

        dcap20 = new QLabel(groupBox_3);
        dcap20->setObjectName("dcap20");

        gridLayout_5->addWidget(dcap20, 11, 1, 1, 1);

        label_45 = new QLabel(groupBox_3);
        label_45->setObjectName("label_45");

        gridLayout_5->addWidget(label_45, 11, 2, 1, 1);


        horizontalLayout->addWidget(groupBox_3);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setSpacing(9);
        verticalLayout_2->setObjectName("verticalLayout_2");
        groupBox_4 = new QGroupBox(centralWidget);
        groupBox_4->setObjectName("groupBox_4");
        gridLayout_6 = new QGridLayout(groupBox_4);
        gridLayout_6->setSpacing(6);
        gridLayout_6->setContentsMargins(11, 11, 11, 11);
        gridLayout_6->setObjectName("gridLayout_6");
        code1_label = new QLabel(groupBox_4);
        code1_label->setObjectName("code1_label");
        code1_label->setAlignment(Qt::AlignCenter);

        gridLayout_6->addWidget(code1_label, 4, 1, 1, 1);

        code2_label = new QLabel(groupBox_4);
        code2_label->setObjectName("code2_label");
        code2_label->setAlignment(Qt::AlignCenter);

        gridLayout_6->addWidget(code2_label, 4, 2, 1, 1);

        eq1_label = new QLabel(groupBox_4);
        eq1_label->setObjectName("eq1_label");
        eq1_label->setAlignment(Qt::AlignCenter);

        gridLayout_6->addWidget(eq1_label, 1, 1, 1, 1);

        eq0_label = new QLabel(groupBox_4);
        eq0_label->setObjectName("eq0_label");
        eq0_label->setAlignment(Qt::AlignCenter);

        gridLayout_6->addWidget(eq0_label, 1, 0, 1, 1);

        thie1_label = new QLabel(groupBox_4);
        thie1_label->setObjectName("thie1_label");
        thie1_label->setAlignment(Qt::AlignCenter);

        gridLayout_6->addWidget(thie1_label, 5, 1, 1, 1);

        thie2_label = new QLabel(groupBox_4);
        thie2_label->setObjectName("thie2_label");
        thie2_label->setAlignment(Qt::AlignCenter);

        gridLayout_6->addWidget(thie2_label, 5, 2, 1, 1);

        eq2_label = new QLabel(groupBox_4);
        eq2_label->setObjectName("eq2_label");
        eq2_label->setAlignment(Qt::AlignCenter);

        gridLayout_6->addWidget(eq2_label, 1, 2, 1, 1);

        label_54 = new QLabel(groupBox_4);
        label_54->setObjectName("label_54");
        label_54->setAlignment(Qt::AlignCenter);

        gridLayout_6->addWidget(label_54, 3, 2, 1, 1);

        label_46 = new QLabel(groupBox_4);
        label_46->setObjectName("label_46");
        label_46->setAlignment(Qt::AlignCenter);

        gridLayout_6->addWidget(label_46, 0, 0, 1, 1);

        label_52 = new QLabel(groupBox_4);
        label_52->setObjectName("label_52");

        gridLayout_6->addWidget(label_52, 3, 0, 1, 1);

        label_56 = new QLabel(groupBox_4);
        label_56->setObjectName("label_56");

        gridLayout_6->addWidget(label_56, 5, 0, 1, 1);

        label_55 = new QLabel(groupBox_4);
        label_55->setObjectName("label_55");

        gridLayout_6->addWidget(label_55, 4, 0, 1, 1);

        label_47 = new QLabel(groupBox_4);
        label_47->setObjectName("label_47");
        label_47->setAlignment(Qt::AlignCenter);

        gridLayout_6->addWidget(label_47, 0, 1, 1, 1);

        label_48 = new QLabel(groupBox_4);
        label_48->setObjectName("label_48");
        label_48->setAlignment(Qt::AlignCenter);

        gridLayout_6->addWidget(label_48, 0, 2, 1, 1);

        label_53 = new QLabel(groupBox_4);
        label_53->setObjectName("label_53");
        label_53->setAlignment(Qt::AlignCenter);

        gridLayout_6->addWidget(label_53, 3, 1, 1, 1);

        line = new QFrame(groupBox_4);
        line->setObjectName("line");
        line->setFrameShape(QFrame::Shape::HLine);
        line->setFrameShadow(QFrame::Shadow::Sunken);

        gridLayout_6->addWidget(line, 2, 0, 1, 3);


        verticalLayout_2->addWidget(groupBox_4);

        groupBox_5 = new QGroupBox(centralWidget);
        groupBox_5->setObjectName("groupBox_5");
        groupBox_5->setMinimumSize(QSize(384, 0));
        groupBox_5->setStyleSheet(QString::fromUtf8(""));
        verticalLayout = new QVBoxLayout(groupBox_5);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName("verticalLayout");
        tableWidget = new QTableWidget(groupBox_5);
        if (tableWidget->columnCount() < 3)
            tableWidget->setColumnCount(3);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(2, __qtablewidgetitem2);
        if (tableWidget->rowCount() < 4)
            tableWidget->setRowCount(4);
        QTableWidgetItem *__qtablewidgetitem3 = new QTableWidgetItem();
        __qtablewidgetitem3->setTextAlignment(Qt::AlignLeading|Qt::AlignVCenter);
        tableWidget->setVerticalHeaderItem(0, __qtablewidgetitem3);
        QTableWidgetItem *__qtablewidgetitem4 = new QTableWidgetItem();
        tableWidget->setVerticalHeaderItem(1, __qtablewidgetitem4);
        QTableWidgetItem *__qtablewidgetitem5 = new QTableWidgetItem();
        tableWidget->setVerticalHeaderItem(2, __qtablewidgetitem5);
        QTableWidgetItem *__qtablewidgetitem6 = new QTableWidgetItem();
        tableWidget->setVerticalHeaderItem(3, __qtablewidgetitem6);
        QTableWidgetItem *__qtablewidgetitem7 = new QTableWidgetItem();
        __qtablewidgetitem7->setTextAlignment(Qt::AlignCenter);
        tableWidget->setItem(0, 0, __qtablewidgetitem7);
        QTableWidgetItem *__qtablewidgetitem8 = new QTableWidgetItem();
        __qtablewidgetitem8->setTextAlignment(Qt::AlignCenter);
        tableWidget->setItem(0, 1, __qtablewidgetitem8);
        QTableWidgetItem *__qtablewidgetitem9 = new QTableWidgetItem();
        __qtablewidgetitem9->setTextAlignment(Qt::AlignCenter);
        tableWidget->setItem(0, 2, __qtablewidgetitem9);
        QTableWidgetItem *__qtablewidgetitem10 = new QTableWidgetItem();
        __qtablewidgetitem10->setTextAlignment(Qt::AlignCenter);
        tableWidget->setItem(1, 0, __qtablewidgetitem10);
        QTableWidgetItem *__qtablewidgetitem11 = new QTableWidgetItem();
        __qtablewidgetitem11->setTextAlignment(Qt::AlignCenter);
        tableWidget->setItem(1, 1, __qtablewidgetitem11);
        QTableWidgetItem *__qtablewidgetitem12 = new QTableWidgetItem();
        __qtablewidgetitem12->setTextAlignment(Qt::AlignCenter);
        tableWidget->setItem(1, 2, __qtablewidgetitem12);
        QTableWidgetItem *__qtablewidgetitem13 = new QTableWidgetItem();
        __qtablewidgetitem13->setTextAlignment(Qt::AlignCenter);
        tableWidget->setItem(2, 0, __qtablewidgetitem13);
        QTableWidgetItem *__qtablewidgetitem14 = new QTableWidgetItem();
        __qtablewidgetitem14->setTextAlignment(Qt::AlignCenter);
        tableWidget->setItem(2, 1, __qtablewidgetitem14);
        QTableWidgetItem *__qtablewidgetitem15 = new QTableWidgetItem();
        __qtablewidgetitem15->setTextAlignment(Qt::AlignCenter);
        tableWidget->setItem(2, 2, __qtablewidgetitem15);
        QTableWidgetItem *__qtablewidgetitem16 = new QTableWidgetItem();
        __qtablewidgetitem16->setTextAlignment(Qt::AlignCenter);
        tableWidget->setItem(3, 0, __qtablewidgetitem16);
        QTableWidgetItem *__qtablewidgetitem17 = new QTableWidgetItem();
        __qtablewidgetitem17->setTextAlignment(Qt::AlignCenter);
        tableWidget->setItem(3, 1, __qtablewidgetitem17);
        QTableWidgetItem *__qtablewidgetitem18 = new QTableWidgetItem();
        __qtablewidgetitem18->setTextAlignment(Qt::AlignCenter);
        tableWidget->setItem(3, 2, __qtablewidgetitem18);
        tableWidget->setObjectName("tableWidget");
        sizePolicy3.setHeightForWidth(tableWidget->sizePolicy().hasHeightForWidth());
        tableWidget->setSizePolicy(sizePolicy3);
        tableWidget->setMinimumSize(QSize(365, 145));
        tableWidget->setStyleSheet(QString::fromUtf8("margin: 2;\n"
"QTableWidgetItem {\n"
"text-align: center;\n"
"}"));
        tableWidget->setFrameShape(QFrame::StyledPanel);
        tableWidget->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        tableWidget->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        tableWidget->setSizeAdjustPolicy(QAbstractScrollArea::AdjustIgnored);
        tableWidget->setAutoScroll(false);
        tableWidget->setAutoScrollMargin(5);
        tableWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);
        tableWidget->setDragEnabled(false);
        tableWidget->setDragDropOverwriteMode(false);
        tableWidget->setSelectionMode(QAbstractItemView::ExtendedSelection);
        tableWidget->setTextElideMode(Qt::ElideNone);
        tableWidget->horizontalHeader()->setVisible(false);
        tableWidget->horizontalHeader()->setCascadingSectionResizes(false);
        tableWidget->horizontalHeader()->setMinimumSectionSize(50);
        tableWidget->horizontalHeader()->setDefaultSectionSize(75);
        tableWidget->horizontalHeader()->setStretchLastSection(false);
        tableWidget->verticalHeader()->setVisible(false);
        tableWidget->verticalHeader()->setCascadingSectionResizes(false);
        tableWidget->verticalHeader()->setMinimumSectionSize(20);
        tableWidget->verticalHeader()->setDefaultSectionSize(25);
        tableWidget->verticalHeader()->setProperty("showSortIndicator", QVariant(false));
        tableWidget->verticalHeader()->setStretchLastSection(false);

        verticalLayout->addWidget(tableWidget);


        verticalLayout_2->addWidget(groupBox_5);

        verticalLayout_2->setStretch(0, 1);
        verticalLayout_2->setStretch(1, 1);

        horizontalLayout->addLayout(verticalLayout_2);

        horizontalLayout->setStretch(0, 1);
        horizontalLayout->setStretch(1, 2);

        verticalLayout_3->addLayout(horizontalLayout);

        verticalLayout_3->setStretch(0, 1);
        verticalLayout_3->setStretch(1, 2);
        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName("menuBar");
        menuBar->setGeometry(QRect(0, 0, 638, 20));
        menuFile = new QMenu(menuBar);
        menuFile->setObjectName("menuFile");
        menuHelp = new QMenu(menuBar);
        menuHelp->setObjectName("menuHelp");
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName("mainToolBar");
        mainToolBar->setMovable(false);
        mainToolBar->setToolButtonStyle(Qt::ToolButtonTextBesideIcon);
        MainWindow->addToolBar(Qt::ToolBarArea::TopToolBarArea, mainToolBar);
#if QT_CONFIG(shortcut)
        label_3->setBuddy(energy_edit);
        label->setBuddy(Element_edit);
        label_2->setBuddy(Z_edit);
        label_5->setBuddy(fractions0);
        label_7->setBuddy(fractions2);
        label_6->setBuddy(fractions1);
        label_14->setBuddy(thickness_edit);
#endif // QT_CONFIG(shortcut)

        menuBar->addAction(menuFile->menuAction());
        menuBar->addAction(menuHelp->menuAction());
        menuFile->addAction(action_Open);
        menuFile->addAction(action_Save);
        menuFile->addAction(action_Save_As);
        menuFile->addSeparator();
        menuFile->addAction(action_Print);
        menuFile->addAction(actionPrint_Preview);
        menuFile->addSeparator();
        menuFile->addAction(action_Exit);
        menuHelp->addAction(action_About);
        menuHelp->addAction(actionWeb_Documentation);
        mainToolBar->addAction(actionExecute);
        mainToolBar->addAction(action_Open);
        mainToolBar->addAction(action_Save);
        mainToolBar->addAction(action_About);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "Charge", nullptr));
        action_Open->setText(QCoreApplication::translate("MainWindow", "&Open...", nullptr));
        action_Save->setText(QCoreApplication::translate("MainWindow", "&Save", nullptr));
        action_Save_As->setText(QCoreApplication::translate("MainWindow", "&Save As...", nullptr));
        action_Print->setText(QCoreApplication::translate("MainWindow", "&Print...", nullptr));
        action_Exit->setText(QCoreApplication::translate("MainWindow", "&Exit", nullptr));
        action_About->setText(QCoreApplication::translate("MainWindow", "&About", nullptr));
        actionWeb_Documentation->setText(QCoreApplication::translate("MainWindow", "Web Documentation", nullptr));
        actionExecute->setText(QCoreApplication::translate("MainWindow", "  Execute", nullptr));
#if QT_CONFIG(tooltip)
        actionExecute->setToolTip(QCoreApplication::translate("MainWindow", "Execute", nullptr));
#endif // QT_CONFIG(tooltip)
        actionPrint_Preview->setText(QCoreApplication::translate("MainWindow", "Print Preview", nullptr));
        ProjectileBox->setTitle(QCoreApplication::translate("MainWindow", "Projectile", nullptr));
        label_3->setText(QCoreApplication::translate("MainWindow", "Energy = ", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "Element", nullptr));
        label_4->setText(QCoreApplication::translate("MainWindow", "MeV/u", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindow", "Z", nullptr));
        groupBox->setTitle(QCoreApplication::translate("MainWindow", "Initial charge state distribution", nullptr));
        label_5->setText(QCoreApplication::translate("MainWindow", "Z-q=0", nullptr));
        label_8->setText(QCoreApplication::translate("MainWindow", "fractions ", nullptr));
        label_7->setText(QCoreApplication::translate("MainWindow", "Z-q=2", nullptr));
        label_9->setText(QCoreApplication::translate("MainWindow", "normalization ", nullptr));
        norm0->setText(QCoreApplication::translate("MainWindow", "TextLabel", nullptr));
        norm1->setText(QCoreApplication::translate("MainWindow", "TextLabel", nullptr));
        norm2->setText(QCoreApplication::translate("MainWindow", "TextLabel", nullptr));
        label_6->setText(QCoreApplication::translate("MainWindow", "Z-q=1", nullptr));
        TargetBox->setTitle(QCoreApplication::translate("MainWindow", "Target", nullptr));
        label_17->setText(QCoreApplication::translate("MainWindow", " atoms/cm<sup>2</sup>", nullptr));
        thickness_label->setText(QCoreApplication::translate("MainWindow", "TextLabel", nullptr));
        label_15->setText(QCoreApplication::translate("MainWindow", " mg/cm<sup>2</sup>", nullptr));
        label_14->setText(QCoreApplication::translate("MainWindow", "Thickness", nullptr));
        Z_label->setText(QCoreApplication::translate("MainWindow", "Z = 13", nullptr));
        groupBox_3->setTitle(QCoreApplication::translate("MainWindow", "Cross sections", nullptr));
        label_19->setText(QCoreApplication::translate("MainWindow", "EIKO (01) = ", nullptr));
        eiko1_label->setText(QCoreApplication::translate("MainWindow", "TextLabel", nullptr));
        label_21->setText(QCoreApplication::translate("MainWindow", "barn", nullptr));
        label_18->setText(QCoreApplication::translate("MainWindow", "<span style=\"color: #0a47c0;\">Non-radiative electron capture (NRC)</span>", nullptr));
        born1_abel->setText(QCoreApplication::translate("MainWindow", "TextLabel", nullptr));
        label_22->setText(QCoreApplication::translate("MainWindow", "EIKO(12) = ", nullptr));
        eiko12_label->setText(QCoreApplication::translate("MainWindow", "TextLabel", nullptr));
        label_24->setText(QCoreApplication::translate("MainWindow", "barn", nullptr));
        label_25->setText(QCoreApplication::translate("MainWindow", "<span style=\"color: #0a47c0;\">Radiative electron capture (REC)</span>", nullptr));
        label_26->setText(QCoreApplication::translate("MainWindow", "REC (01) = ", nullptr));
        rec1_label->setText(QCoreApplication::translate("MainWindow", "TextLabel", nullptr));
        label_28->setText(QCoreApplication::translate("MainWindow", "barn", nullptr));
        label_29->setText(QCoreApplication::translate("MainWindow", "REC (12) = ", nullptr));
        label_36->setText(QCoreApplication::translate("MainWindow", "BORN (21) = ", nullptr));
        label_35->setText(QCoreApplication::translate("MainWindow", "barn", nullptr));
        label_33->setText(QCoreApplication::translate("MainWindow", "BORN (10) = ", nullptr));
        born2_label->setText(QCoreApplication::translate("MainWindow", "TextLabel", nullptr));
        rec12_label->setText(QCoreApplication::translate("MainWindow", "TextLabel", nullptr));
        label_31->setText(QCoreApplication::translate("MainWindow", "barn", nullptr));
        label_32->setText(QCoreApplication::translate("MainWindow", "<span  style=\"color: #0a47c0;\">Ionization cross section</span>", nullptr));
        label_38->setText(QCoreApplication::translate("MainWindow", "barn", nullptr));
        label_39->setText(QCoreApplication::translate("MainWindow", "<span  style=\"color: #0a47c0;\">Double cross section</span>", nullptr));
        label_40->setText(QCoreApplication::translate("MainWindow", "DCAP (02) = ", nullptr));
        dcap02->setText(QCoreApplication::translate("MainWindow", "TextLabel", nullptr));
        label_42->setText(QCoreApplication::translate("MainWindow", "barn", nullptr));
        label_43->setText(QCoreApplication::translate("MainWindow", "DION (20) = ", nullptr));
        dcap20->setText(QCoreApplication::translate("MainWindow", "TextLabel", nullptr));
        label_45->setText(QCoreApplication::translate("MainWindow", "barn", nullptr));
        groupBox_4->setTitle(QCoreApplication::translate("MainWindow", "Equilibrium charge state", nullptr));
        code1_label->setText(QCoreApplication::translate("MainWindow", "TextLabel", nullptr));
        code2_label->setText(QCoreApplication::translate("MainWindow", "TextLabel", nullptr));
        eq1_label->setText(QCoreApplication::translate("MainWindow", "TextLabel", nullptr));
        eq0_label->setText(QCoreApplication::translate("MainWindow", "TextLabel", nullptr));
        thie1_label->setText(QCoreApplication::translate("MainWindow", "TextLabel", nullptr));
        thie2_label->setText(QCoreApplication::translate("MainWindow", "TextLabel", nullptr));
        eq2_label->setText(QCoreApplication::translate("MainWindow", "TextLabel", nullptr));
        label_54->setText(QCoreApplication::translate("MainWindow", "atoms/cm<sup>2</sup>", nullptr));
        label_46->setText(QCoreApplication::translate("MainWindow", "Z - q = 0", nullptr));
        label_52->setText(QCoreApplication::translate("MainWindow", "Equilibrium thickness", nullptr));
        label_56->setText(QCoreApplication::translate("MainWindow", "Thieberger et al.", nullptr));
        label_55->setText(QCoreApplication::translate("MainWindow", "This code", nullptr));
        label_47->setText(QCoreApplication::translate("MainWindow", "Z - q = 1", nullptr));
        label_48->setText(QCoreApplication::translate("MainWindow", "Z - q = 2", nullptr));
        label_53->setText(QCoreApplication::translate("MainWindow", "mg/cm<sup>2</sup>", nullptr));
        groupBox_5->setTitle(QCoreApplication::translate("MainWindow", "Charge distribution after target", nullptr));
        QTableWidgetItem *___qtablewidgetitem = tableWidget->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QCoreApplication::translate("MainWindow", "0 el.", nullptr));
        QTableWidgetItem *___qtablewidgetitem1 = tableWidget->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QCoreApplication::translate("MainWindow", "1 el.", nullptr));
        QTableWidgetItem *___qtablewidgetitem2 = tableWidget->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QCoreApplication::translate("MainWindow", "2 el.", nullptr));
        QTableWidgetItem *___qtablewidgetitem3 = tableWidget->verticalHeaderItem(0);
        ___qtablewidgetitem3->setText(QCoreApplication::translate("MainWindow", "user", nullptr));
        QTableWidgetItem *___qtablewidgetitem4 = tableWidget->verticalHeaderItem(1);
        ___qtablewidgetitem4->setText(QCoreApplication::translate("MainWindow", "for Z-q = 0", nullptr));
        QTableWidgetItem *___qtablewidgetitem5 = tableWidget->verticalHeaderItem(2);
        ___qtablewidgetitem5->setText(QCoreApplication::translate("MainWindow", "for Z-q = 1", nullptr));
        QTableWidgetItem *___qtablewidgetitem6 = tableWidget->verticalHeaderItem(3);
        ___qtablewidgetitem6->setText(QCoreApplication::translate("MainWindow", "for Z-q = 2", nullptr));

        const bool __sortingEnabled = tableWidget->isSortingEnabled();
        tableWidget->setSortingEnabled(false);
        tableWidget->setSortingEnabled(__sortingEnabled);

        menuFile->setTitle(QCoreApplication::translate("MainWindow", "&File", nullptr));
        menuHelp->setTitle(QCoreApplication::translate("MainWindow", "Help", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_C_MAINWINDOW_H
