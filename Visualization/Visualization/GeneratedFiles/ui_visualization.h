/********************************************************************************
** Form generated from reading UI file 'visualization.ui'
**
** Created by: Qt User Interface Compiler version 5.3.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_VISUALIZATION_H
#define UI_VISUALIZATION_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGraphicsView>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_VisualizationClass
{
public:
    QWidget *centralWidget;
    QLineEdit *lineEdit_status_r;
    QLabel *label_z;
    QGraphicsView *graphicsView_2;
    QGraphicsView *graphicsView;
    QLabel *label_x;
    QLineEdit *lineEdit_z_l;
    QLineEdit *lineEdit_y_r;
    QLineEdit *lineEdit_status_l;
    QLabel *label_y;
    QPushButton *pushbutton_stop;
    QPushButton *pushbutton_start;
    QLineEdit *lineEdit_x_r;
    QLineEdit *lineEdit_x_l;
    QLineEdit *lineEdit_y_l;
    QLineEdit *lineEdit_z_r;
    QLabel *label_left;
    QLabel *label_status;
    QLabel *label_right;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *VisualizationClass)
    {
        if (VisualizationClass->objectName().isEmpty())
            VisualizationClass->setObjectName(QStringLiteral("VisualizationClass"));
        VisualizationClass->resize(800, 600);
        VisualizationClass->setMinimumSize(QSize(800, 600));
        VisualizationClass->setMaximumSize(QSize(800, 600));
        centralWidget = new QWidget(VisualizationClass);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        lineEdit_status_r = new QLineEdit(centralWidget);
        lineEdit_status_r->setObjectName(QStringLiteral("lineEdit_status_r"));
        lineEdit_status_r->setGeometry(QRect(180, 30, 113, 20));
        label_z = new QLabel(centralWidget);
        label_z->setObjectName(QStringLiteral("label_z"));
        label_z->setGeometry(QRect(50, 120, 21, 16));
        graphicsView_2 = new QGraphicsView(centralWidget);
        graphicsView_2->setObjectName(QStringLiteral("graphicsView_2"));
        graphicsView_2->setGeometry(QRect(500, 10, 250, 130));
        graphicsView = new QGraphicsView(centralWidget);
        graphicsView->setObjectName(QStringLiteral("graphicsView"));
        graphicsView->setGeometry(QRect(10, 150, 780, 420));
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(graphicsView->sizePolicy().hasHeightForWidth());
        graphicsView->setSizePolicy(sizePolicy);
        graphicsView->setMinimumSize(QSize(780, 420));
        graphicsView->setMaximumSize(QSize(780, 420));
        label_x = new QLabel(centralWidget);
        label_x->setObjectName(QStringLiteral("label_x"));
        label_x->setGeometry(QRect(50, 60, 21, 16));
        lineEdit_z_l = new QLineEdit(centralWidget);
        lineEdit_z_l->setObjectName(QStringLiteral("lineEdit_z_l"));
        lineEdit_z_l->setGeometry(QRect(60, 120, 113, 20));
        lineEdit_y_r = new QLineEdit(centralWidget);
        lineEdit_y_r->setObjectName(QStringLiteral("lineEdit_y_r"));
        lineEdit_y_r->setGeometry(QRect(180, 90, 113, 20));
        lineEdit_status_l = new QLineEdit(centralWidget);
        lineEdit_status_l->setObjectName(QStringLiteral("lineEdit_status_l"));
        lineEdit_status_l->setGeometry(QRect(60, 30, 113, 20));
        label_y = new QLabel(centralWidget);
        label_y->setObjectName(QStringLiteral("label_y"));
        label_y->setGeometry(QRect(50, 90, 21, 16));
        pushbutton_stop = new QPushButton(centralWidget);
        pushbutton_stop->setObjectName(QStringLiteral("pushbutton_stop"));
        pushbutton_stop->setGeometry(QRect(350, 60, 100, 23));
        pushbutton_start = new QPushButton(centralWidget);
        pushbutton_start->setObjectName(QStringLiteral("pushbutton_start"));
        pushbutton_start->setGeometry(QRect(350, 30, 100, 23));
        lineEdit_x_r = new QLineEdit(centralWidget);
        lineEdit_x_r->setObjectName(QStringLiteral("lineEdit_x_r"));
        lineEdit_x_r->setGeometry(QRect(180, 60, 113, 20));
        lineEdit_x_l = new QLineEdit(centralWidget);
        lineEdit_x_l->setObjectName(QStringLiteral("lineEdit_x_l"));
        lineEdit_x_l->setGeometry(QRect(60, 60, 113, 20));
        lineEdit_y_l = new QLineEdit(centralWidget);
        lineEdit_y_l->setObjectName(QStringLiteral("lineEdit_y_l"));
        lineEdit_y_l->setGeometry(QRect(60, 90, 113, 20));
        lineEdit_z_r = new QLineEdit(centralWidget);
        lineEdit_z_r->setObjectName(QStringLiteral("lineEdit_z_r"));
        lineEdit_z_r->setGeometry(QRect(180, 120, 113, 20));
        label_left = new QLabel(centralWidget);
        label_left->setObjectName(QStringLiteral("label_left"));
        label_left->setGeometry(QRect(110, 10, 21, 16));
        label_status = new QLabel(centralWidget);
        label_status->setObjectName(QStringLiteral("label_status"));
        label_status->setGeometry(QRect(30, 30, 31, 16));
        label_right = new QLabel(centralWidget);
        label_right->setObjectName(QStringLiteral("label_right"));
        label_right->setGeometry(QRect(220, 10, 46, 13));
        VisualizationClass->setCentralWidget(centralWidget);
        statusBar = new QStatusBar(VisualizationClass);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        VisualizationClass->setStatusBar(statusBar);

        retranslateUi(VisualizationClass);

        QMetaObject::connectSlotsByName(VisualizationClass);
    } // setupUi

    void retranslateUi(QMainWindow *VisualizationClass)
    {
        VisualizationClass->setWindowTitle(QApplication::translate("VisualizationClass", "Visualization", 0));
        label_z->setText(QApplication::translate("VisualizationClass", "Z:", 0));
        label_x->setText(QApplication::translate("VisualizationClass", "X:", 0));
        label_y->setText(QApplication::translate("VisualizationClass", "Y:", 0));
        pushbutton_stop->setText(QApplication::translate("VisualizationClass", "Stop", 0));
        pushbutton_start->setText(QApplication::translate("VisualizationClass", "Start", 0));
        label_left->setText(QApplication::translate("VisualizationClass", "Left", 0));
        label_status->setText(QApplication::translate("VisualizationClass", "Status:", 0));
        label_right->setText(QApplication::translate("VisualizationClass", "Right", 0));
    } // retranslateUi

};

namespace Ui {
    class VisualizationClass: public Ui_VisualizationClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_VISUALIZATION_H
