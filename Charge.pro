TARGET = Charge
TEMPLATE = app
CONFIG += c++17
#QT += core gui
QT += widgets core gui printsupport network
#qtHaveModule(printsupport): QT += printsupport

UI_DIR = ui
MOC_DIR = moc
RCC_DIR = rcc
OBJECTS_DIR = obj


#win32-g++ {
#DESTDIR = c:/LISEcute/_install
#}
#win32-msvc {
#DESTDIR = c:/LISEcute/_install_MSVC
#}

win32:VERSION = 2.1.12.1 # major.minor.patch.build
else:VERSION = 2.1.12    # major.minor.patch

win32 {
       QMAKE_TARGET_COPYRIGHT = "LISE group at FRIB/MSU"
	QMAKE_TARGET_COMPANY   = "LISE group at FRIB/MSU"
	}

#==================================================
# The following define makes your compiler warn you if you use any
# feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.

DEFINES += QT_DEPRECATED_WARNINGS QT_DEBUG_PLUGIN
DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

# Input


SOURCES += \
    g_Charge/source/ch_csd.cpp \
    g_Charge/source/ch_rec.cpp \
    g_Charge/source/ch_ion.cpp \
    g_Charge/source/ch_nrc.cpp \
    g_Charge/win/c_about.cpp \
    g_Charge/win/c_fileReadWrite.cpp \
    g_Charge/win/c_main.cpp \
    g_Charge/win/c_mainwindow.cpp \
    g_Charge/win/c_util.cpp \
    w_Stuff/w_Label_clickable.cpp

HEADERS  += \
    g_Charge/source/c_constant.h \
    g_Charge/win/c_about.h \
    g_Charge/win/c_element.h \
    g_Charge/win/c_ftype.h \
    g_Charge/win/c_mainwindow.h \
    w_Stuff/w_Label_clickable.h

FORMS += \
       g_Charge/win/c_about.ui \
       g_Charge/win/c_mainwindow.ui

RESOURCES += \
       g_Charge/c_resources.qrc \
       lise.qrc

RC_ICONS = g_Charge/icons/charge1.ico

# Check if the platform is macOS
macx {
	DEFINES += __APPLE_
	ICON = ./Icons_macos/charge.icns
	QMAKE_INFO_PLIST = ./Info.plist
}