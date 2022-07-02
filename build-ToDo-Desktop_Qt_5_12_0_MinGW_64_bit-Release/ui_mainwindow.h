/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.12.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QScrollArea>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QHBoxLayout *horizontalLayout;
    QGroupBox *groupBox;
    QVBoxLayout *verticalLayout;
    QListWidget *listWidget;
    QFrame *line_2;
    QPushButton *pushButton;
    QFrame *line;
    QGroupBox *groupBox_2;
    QVBoxLayout *verticalLayout_2;
    QGroupBox *groupBox_4;
    QHBoxLayout *horizontalLayout_2;
    QLineEdit *task_line;
    QPushButton *addTask;
    QScrollArea *scrollTasks;
    QWidget *layout;
    QVBoxLayout *verticalLayout_3;
    QTableWidget *tableWidget;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(870, 600);
        MainWindow->setMinimumSize(QSize(800, 600));
        MainWindow->setStyleSheet(QString::fromUtf8("background-color: #80bfff"));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        horizontalLayout = new QHBoxLayout(centralWidget);
        horizontalLayout->setSpacing(6);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        groupBox = new QGroupBox(centralWidget);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        groupBox->setMinimumSize(QSize(0, 0));
        groupBox->setMaximumSize(QSize(250, 16777215));
        verticalLayout = new QVBoxLayout(groupBox);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        listWidget = new QListWidget(groupBox);
        listWidget->setObjectName(QString::fromUtf8("listWidget"));
        listWidget->setMaximumSize(QSize(16777215, 16777215));
        listWidget->setAutoFillBackground(false);
        listWidget->setStyleSheet(QString::fromUtf8("background-color: white;"));
        listWidget->setLineWidth(1);
        listWidget->setAutoScrollMargin(16);
        listWidget->setIconSize(QSize(20, 20));
        listWidget->setFlow(QListView::TopToBottom);
        listWidget->setResizeMode(QListView::Fixed);
        listWidget->setSpacing(0);
        listWidget->setGridSize(QSize(0, 40));
        listWidget->setViewMode(QListView::ListMode);
        listWidget->setBatchSize(100);
        listWidget->setWordWrap(false);

        verticalLayout->addWidget(listWidget);

        line_2 = new QFrame(groupBox);
        line_2->setObjectName(QString::fromUtf8("line_2"));
        line_2->setFrameShape(QFrame::HLine);
        line_2->setFrameShadow(QFrame::Sunken);

        verticalLayout->addWidget(line_2);

        pushButton = new QPushButton(groupBox);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setMinimumSize(QSize(50, 25));
        pushButton->setMaximumSize(QSize(50, 50));
        pushButton->setStyleSheet(QString::fromUtf8("border-radius: 5px;\n"
"background-color: white;"));

        verticalLayout->addWidget(pushButton);


        horizontalLayout->addWidget(groupBox);

        line = new QFrame(centralWidget);
        line->setObjectName(QString::fromUtf8("line"));
        line->setFrameShape(QFrame::VLine);
        line->setFrameShadow(QFrame::Sunken);

        horizontalLayout->addWidget(line);

        groupBox_2 = new QGroupBox(centralWidget);
        groupBox_2->setObjectName(QString::fromUtf8("groupBox_2"));
        verticalLayout_2 = new QVBoxLayout(groupBox_2);
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setContentsMargins(11, 11, 11, 11);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        groupBox_4 = new QGroupBox(groupBox_2);
        groupBox_4->setObjectName(QString::fromUtf8("groupBox_4"));
        groupBox_4->setMaximumSize(QSize(16777215, 60));
        horizontalLayout_2 = new QHBoxLayout(groupBox_4);
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        task_line = new QLineEdit(groupBox_4);
        task_line->setObjectName(QString::fromUtf8("task_line"));
        task_line->setMinimumSize(QSize(0, 40));
        task_line->setStyleSheet(QString::fromUtf8("border-radius: 5px;\n"
"background-color: white;"));

        horizontalLayout_2->addWidget(task_line);

        addTask = new QPushButton(groupBox_4);
        addTask->setObjectName(QString::fromUtf8("addTask"));
        addTask->setMinimumSize(QSize(120, 40));
        addTask->setMaximumSize(QSize(120, 16777215));
        addTask->setStyleSheet(QString::fromUtf8("background-color: white;\n"
"border-radius: 5px;"));

        horizontalLayout_2->addWidget(addTask);


        verticalLayout_2->addWidget(groupBox_4);

        scrollTasks = new QScrollArea(groupBox_2);
        scrollTasks->setObjectName(QString::fromUtf8("scrollTasks"));
        scrollTasks->setAutoFillBackground(false);
        scrollTasks->setStyleSheet(QString::fromUtf8("border-color:red;"));
        scrollTasks->setFrameShape(QFrame::StyledPanel);
        scrollTasks->setFrameShadow(QFrame::Sunken);
        scrollTasks->setWidgetResizable(true);
        layout = new QWidget();
        layout->setObjectName(QString::fromUtf8("layout"));
        layout->setGeometry(QRect(0, 0, 554, 420));
        verticalLayout_3 = new QVBoxLayout(layout);
        verticalLayout_3->setSpacing(6);
        verticalLayout_3->setContentsMargins(11, 11, 11, 11);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        tableWidget = new QTableWidget(layout);
        tableWidget->setObjectName(QString::fromUtf8("tableWidget"));
        tableWidget->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOn);
        tableWidget->setSizeAdjustPolicy(QAbstractScrollArea::AdjustToContents);
        tableWidget->setRowCount(0);

        verticalLayout_3->addWidget(tableWidget);

        scrollTasks->setWidget(layout);

        verticalLayout_2->addWidget(scrollTasks);


        horizontalLayout->addWidget(groupBox_2);

        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 869, 26));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        mainToolBar->setStyleSheet(QString::fromUtf8(""));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        MainWindow->setStatusBar(statusBar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", nullptr));
        groupBox->setTitle(QString());
        pushButton->setText(QApplication::translate("MainWindow", "+", nullptr));
        groupBox_2->setTitle(QString());
        groupBox_4->setTitle(QString());
        task_line->setPlaceholderText(QApplication::translate("MainWindow", "\320\222\320\262\320\265\320\264\320\270\321\202\320\265 \320\264\320\276\320\261\320\260\320\262\320\273\321\217\320\265\320\274\321\203\321\216 \320\267\320\260\320\264\320\260\321\207\321\203", nullptr));
        addTask->setText(QApplication::translate("MainWindow", "\320\224\320\276\320\261\320\260\320\262\320\270\321\202\321\214 \320\267\320\260\320\264\320\260\321\207\321\203", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
