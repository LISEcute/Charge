/********************************************************************************
** Form generated from reading UI file 'c_about.ui'
**
** Created by: Qt User Interface Compiler version 6.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_C_ABOUT_H
#define UI_C_ABOUT_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include "w_Stuff/w_Label_clickable.h"

QT_BEGIN_NAMESPACE

class Ui_About
{
public:
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QLabel *label_13;
    QLabel *label_10;
    QLabel *label_11;
    QLabel *label_8;
    QLabel *label_14;
    QLabel *label_Version;
    QLabel *label_Date;
    ClickableLabel *label_mail;
    QFrame *frame;
    QGridLayout *gridLayout;
    QLabel *label_2;
    ClickableLabel *label_Charge;
    QLabel *label;
    ClickableLabel *label_LISE;
    QLabel *label_9;

    void setupUi(QWidget *About)
    {
        if (About->objectName().isEmpty())
            About->setObjectName("About");
        About->resize(374, 481);
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/icons/charge1.png"), QSize(), QIcon::Normal, QIcon::Off);
        About->setWindowIcon(icon);
        About->setStyleSheet(QString::fromUtf8("background-color: rgb(85, 85, 225);"));
        verticalLayout = new QVBoxLayout(About);
        verticalLayout->setSpacing(8);
        verticalLayout->setObjectName("verticalLayout");
        verticalLayout->setContentsMargins(12, -1, 12, -1);
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName("horizontalLayout");
        label_13 = new QLabel(About);
        label_13->setObjectName("label_13");
        QSizePolicy sizePolicy(QSizePolicy::Policy::Preferred, QSizePolicy::Policy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(label_13->sizePolicy().hasHeightForWidth());
        label_13->setSizePolicy(sizePolicy);
        label_13->setMaximumSize(QSize(70, 70));
        label_13->setAutoFillBackground(false);
        label_13->setStyleSheet(QString::fromUtf8(""));
        label_13->setPixmap(QPixmap(QString::fromUtf8(":/icons/charge1.png")));
        label_13->setScaledContents(true);

        horizontalLayout->addWidget(label_13);

        label_10 = new QLabel(About);
        label_10->setObjectName("label_10");
        QSizePolicy sizePolicy1(QSizePolicy::Policy::Preferred, QSizePolicy::Policy::Preferred);
        sizePolicy1.setHorizontalStretch(4);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(label_10->sizePolicy().hasHeightForWidth());
        label_10->setSizePolicy(sizePolicy1);
        QFont font;
        font.setFamilies({QString::fromUtf8("Bookman Old Style")});
        font.setPointSize(24);
        font.setBold(true);
        font.setItalic(false);
        label_10->setFont(font);
        label_10->setStyleSheet(QString::fromUtf8("color: #fff;\n"
"margin-bottom:0;"));
        label_10->setAlignment(Qt::AlignCenter);

        horizontalLayout->addWidget(label_10);

        label_11 = new QLabel(About);
        label_11->setObjectName("label_11");
        sizePolicy.setHeightForWidth(label_11->sizePolicy().hasHeightForWidth());
        label_11->setSizePolicy(sizePolicy);
        label_11->setMaximumSize(QSize(70, 70));
        label_11->setAutoFillBackground(false);
        label_11->setStyleSheet(QString::fromUtf8(""));
        label_11->setPixmap(QPixmap(QString::fromUtf8(":/icons/charge1.png")));
        label_11->setScaledContents(true);

        horizontalLayout->addWidget(label_11);


        verticalLayout->addLayout(horizontalLayout);

        label_8 = new QLabel(About);
        label_8->setObjectName("label_8");
        QSizePolicy sizePolicy2(QSizePolicy::Policy::Preferred, QSizePolicy::Policy::Minimum);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(label_8->sizePolicy().hasHeightForWidth());
        label_8->setSizePolicy(sizePolicy2);
        label_8->setMinimumSize(QSize(350, 0));
        QFont font1;
        font1.setFamilies({QString::fromUtf8("Bookman Old Style")});
        font1.setPointSize(13);
        font1.setBold(true);
        font1.setItalic(false);
        label_8->setFont(font1);
        label_8->setStyleSheet(QString::fromUtf8("color: #fff;\n"
"padding:0px;\n"
"margin: 0px;"));
        label_8->setAlignment(Qt::AlignCenter);

        verticalLayout->addWidget(label_8);

        label_14 = new QLabel(About);
        label_14->setObjectName("label_14");
        QFont font2;
        font2.setPointSize(9);
        label_14->setFont(font2);
        label_14->setStyleSheet(QString::fromUtf8("color: rgb(222, 226, 197); background-color: rgb(0, 90, 255);"));
        label_14->setFrameShape(QFrame::StyledPanel);
        label_14->setAlignment(Qt::AlignCenter);
        label_14->setIndent(5);

        verticalLayout->addWidget(label_14);

        label_Version = new QLabel(About);
        label_Version->setObjectName("label_Version");
        QFont font3;
        font3.setPointSize(10);
        font3.setBold(true);
        font3.setItalic(false);
        label_Version->setFont(font3);
        label_Version->setStyleSheet(QString::fromUtf8("color: rgb(240, 255, 200);"));
        label_Version->setAlignment(Qt::AlignCenter);

        verticalLayout->addWidget(label_Version);

        label_Date = new QLabel(About);
        label_Date->setObjectName("label_Date");
        label_Date->setFont(font3);
        label_Date->setStyleSheet(QString::fromUtf8("color: rgb(240, 255, 200);"));
        label_Date->setAlignment(Qt::AlignCenter);

        verticalLayout->addWidget(label_Date);

        label_mail = new ClickableLabel(About);
        label_mail->setObjectName("label_mail");
        label_mail->setCursor(QCursor(Qt::PointingHandCursor));
        label_mail->setStyleSheet(QString::fromUtf8("padding: 5px;\n"
"color: rgb(210, 210, 210);"));
        label_mail->setAlignment(Qt::AlignCenter);
        label_mail->setWordWrap(true);

        verticalLayout->addWidget(label_mail);

        frame = new QFrame(About);
        frame->setObjectName("frame");
        frame->setStyleSheet(QString::fromUtf8("background-color: rgb(0, 90, 255);"));
        frame->setFrameShape(QFrame::StyledPanel);
        gridLayout = new QGridLayout(frame);
        gridLayout->setObjectName("gridLayout");
        gridLayout->setHorizontalSpacing(9);
        gridLayout->setVerticalSpacing(12);
        gridLayout->setContentsMargins(8, 10, 8, 9);
        label_2 = new QLabel(frame);
        label_2->setObjectName("label_2");
        QFont font4;
        font4.setPointSize(9);
        font4.setBold(true);
        label_2->setFont(font4);
        label_2->setStyleSheet(QString::fromUtf8("color: rgb(170, 170, 255);"));

        gridLayout->addWidget(label_2, 0, 0, 1, 1);

        label_Charge = new ClickableLabel(frame);
        label_Charge->setObjectName("label_Charge");
        QFont font5;
        font5.setFamilies({QString::fromUtf8("Arial")});
        font5.setPointSize(9);
        label_Charge->setFont(font5);
        label_Charge->setCursor(QCursor(Qt::PointingHandCursor));
        label_Charge->setStyleSheet(QString::fromUtf8("color: rgb(222, 226, 197);"));
        label_Charge->setTextFormat(Qt::AutoText);
        label_Charge->setOpenExternalLinks(true);

        gridLayout->addWidget(label_Charge, 0, 1, 1, 2);

        label = new QLabel(frame);
        label->setObjectName("label");
        label->setFont(font4);
        label->setStyleSheet(QString::fromUtf8("color: rgb(170, 170, 255);"));

        gridLayout->addWidget(label, 1, 0, 1, 1);

        label_LISE = new ClickableLabel(frame);
        label_LISE->setObjectName("label_LISE");
        label_LISE->setFont(font5);
        label_LISE->setCursor(QCursor(Qt::PointingHandCursor));
        label_LISE->setStyleSheet(QString::fromUtf8("color: rgb(222, 226, 197);"));
        label_LISE->setTextFormat(Qt::AutoText);
        label_LISE->setOpenExternalLinks(true);

        gridLayout->addWidget(label_LISE, 1, 1, 1, 1);

        label_9 = new QLabel(frame);
        label_9->setObjectName("label_9");
        label_9->setMaximumSize(QSize(125, 45));
        label_9->setPixmap(QPixmap(QString::fromUtf8(":/icons/emblem_little_plus.png")));
        label_9->setScaledContents(false);
        label_9->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout->addWidget(label_9, 1, 2, 1, 1);


        verticalLayout->addWidget(frame);

        frame->raise();
        label_8->raise();
        label_14->raise();
        label_Version->raise();
        label_mail->raise();
        label_Date->raise();

        retranslateUi(About);

        QMetaObject::connectSlotsByName(About);
    } // setupUi

    void retranslateUi(QWidget *About)
    {
        About->setWindowTitle(QCoreApplication::translate("About", "About Charge", nullptr));
        label_13->setText(QString());
        label_10->setText(QCoreApplication::translate("About", "Charge", nullptr));
        label_11->setText(QString());
        label_8->setText(QCoreApplication::translate("About", "calculating charge state distributions", nullptr));
        label_14->setText(QCoreApplication::translate("About", "<br>Thomas St\303\266hlker<br>GSI &amp; University of Frankfurt<hr>C. Scheidenberger, Th. St\303\266hlker, W. E. Meyerhof,<br>H. Geissel, P. H. Mokler, B. Blank<br>Nucl. Instr. and Meth. B 142 (1998) 441<br>", nullptr));
        label_Version->setText(QCoreApplication::translate("About", "Version 1.5", nullptr));
        label_Date->setText(QCoreApplication::translate("About", "28-April-2015", nullptr));
#if QT_CONFIG(tooltip)
        label_mail->setToolTip(QCoreApplication::translate("About", "send mail to:", nullptr));
#endif // QT_CONFIG(tooltip)
        label_mail->setText(QCoreApplication::translate("About", "<p>Charge has been ported to MS Windows and C++<br> by O.B. Tarasov  within the framework of the program LISE<sup>++</sup>.</p><p>This program has been made into a cross-platform <br> application in the Qt framework by M.P. Kuchera.</p><p>The GUI-version is currently maintained by O.B.Tarasov</p>", nullptr));
        label_2->setText(QCoreApplication::translate("About", "Charge", nullptr));
#if QT_CONFIG(tooltip)
        label_Charge->setToolTip(QCoreApplication::translate("About", "<html><head/><body><p><span style=\" color:#ffffff;\">Link to Charge</span></p></body></html>", nullptr));
#endif // QT_CONFIG(tooltip)
        label_Charge->setText(QCoreApplication::translate("About", "http://web-docs.gsi.de/~weick/charge_states", nullptr));
        label->setText(QCoreApplication::translate("About", "LISE<sup>++</sup>", nullptr));
#if QT_CONFIG(tooltip)
        label_LISE->setToolTip(QCoreApplication::translate("About", "<html><head/><body><p><span style=\" color:#ffffff;\">link to LISE++</span></p></body></html>", nullptr));
#endif // QT_CONFIG(tooltip)
        label_LISE->setText(QCoreApplication::translate("About", "http://lise.nscl.msu.edu", nullptr));
        label_9->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class About: public Ui_About {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_C_ABOUT_H
