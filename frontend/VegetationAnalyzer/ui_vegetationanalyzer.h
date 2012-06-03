/********************************************************************************
** Form generated from reading UI file 'vegetationanalyzer.ui'
**
** Created: Sun Jun 3 13:21:13 2012
**      by: Qt User Interface Compiler version 4.8.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_VEGETATIONANALYZER_H
#define UI_VEGETATIONANALYZER_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QGraphicsView>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QListWidget>
#include <QtGui/QMainWindow>
#include <QtGui/QMenu>
#include <QtGui/QMenuBar>
#include <QtGui/QTextBrowser>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_VegetationAnalyzer
{
public:
    QAction *actionQuit;
    QAction *actionOpen;
    QWidget *centralWidget;
    QHBoxLayout *horizontalLayout;
    QVBoxLayout *verticalLayout;
    QListWidget *listWidget;
    QTextBrowser *textBrowser;
    QGraphicsView *graphicsView;
    QMenuBar *menuBar;
    QMenu *menuAnalyzer;
    QMenu *menuAbout;

    void setupUi(QMainWindow *VegetationAnalyzer)
    {
        if (VegetationAnalyzer->objectName().isEmpty())
            VegetationAnalyzer->setObjectName(QString::fromUtf8("VegetationAnalyzer"));
        VegetationAnalyzer->resize(600, 400);
        actionQuit = new QAction(VegetationAnalyzer);
        actionQuit->setObjectName(QString::fromUtf8("actionQuit"));
        actionOpen = new QAction(VegetationAnalyzer);
        actionOpen->setObjectName(QString::fromUtf8("actionOpen"));
        centralWidget = new QWidget(VegetationAnalyzer);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        horizontalLayout = new QHBoxLayout(centralWidget);
        horizontalLayout->setSpacing(6);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(6);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        listWidget = new QListWidget(centralWidget);
        new QListWidgetItem(listWidget);
        new QListWidgetItem(listWidget);
        listWidget->setObjectName(QString::fromUtf8("listWidget"));

        verticalLayout->addWidget(listWidget);

        textBrowser = new QTextBrowser(centralWidget);
        textBrowser->setObjectName(QString::fromUtf8("textBrowser"));

        verticalLayout->addWidget(textBrowser);


        horizontalLayout->addLayout(verticalLayout);

        graphicsView = new QGraphicsView(centralWidget);
        graphicsView->setObjectName(QString::fromUtf8("graphicsView"));

        horizontalLayout->addWidget(graphicsView);

        VegetationAnalyzer->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(VegetationAnalyzer);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 600, 23));
        menuAnalyzer = new QMenu(menuBar);
        menuAnalyzer->setObjectName(QString::fromUtf8("menuAnalyzer"));
        menuAbout = new QMenu(menuBar);
        menuAbout->setObjectName(QString::fromUtf8("menuAbout"));
        VegetationAnalyzer->setMenuBar(menuBar);

        menuBar->addAction(menuAnalyzer->menuAction());
        menuBar->addAction(menuAbout->menuAction());
        menuAnalyzer->addAction(actionOpen);
        menuAnalyzer->addSeparator();
        menuAnalyzer->addAction(actionQuit);

        retranslateUi(VegetationAnalyzer);

        QMetaObject::connectSlotsByName(VegetationAnalyzer);
    } // setupUi

    void retranslateUi(QMainWindow *VegetationAnalyzer)
    {
        VegetationAnalyzer->setWindowTitle(QApplication::translate("VegetationAnalyzer", "VegetationAnalyzer", 0, QApplication::UnicodeUTF8));
        actionQuit->setText(QApplication::translate("VegetationAnalyzer", "Quit", 0, QApplication::UnicodeUTF8));
        actionOpen->setText(QApplication::translate("VegetationAnalyzer", "Open", 0, QApplication::UnicodeUTF8));
        actionOpen->setShortcut(QApplication::translate("VegetationAnalyzer", "Ctrl+O", 0, QApplication::UnicodeUTF8));

        const bool __sortingEnabled = listWidget->isSortingEnabled();
        listWidget->setSortingEnabled(false);
        QListWidgetItem *___qlistwidgetitem = listWidget->item(0);
        ___qlistwidgetitem->setText(QApplication::translate("VegetationAnalyzer", "false color", 0, QApplication::UnicodeUTF8));
        QListWidgetItem *___qlistwidgetitem1 = listWidget->item(1);
        ___qlistwidgetitem1->setText(QApplication::translate("VegetationAnalyzer", "natural color", 0, QApplication::UnicodeUTF8));
        listWidget->setSortingEnabled(__sortingEnabled);

        menuAnalyzer->setTitle(QApplication::translate("VegetationAnalyzer", "File", 0, QApplication::UnicodeUTF8));
        menuAbout->setTitle(QApplication::translate("VegetationAnalyzer", "About", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class VegetationAnalyzer: public Ui_VegetationAnalyzer {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_VEGETATIONANALYZER_H
