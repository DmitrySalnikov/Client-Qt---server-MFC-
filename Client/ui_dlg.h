/********************************************************************************
** Form generated from reading UI file 'dlg.ui'
**
** Created: Wed 9. Dec 03:02:25 2015
**      by: Qt User Interface Compiler version 4.8.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DLG_H
#define UI_DLG_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QPushButton>
#include <QtGui/QSpinBox>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_dlg
{
public:
    QPushButton *ModelPushButton;
    QLabel *label;
    QLabel *label_2;
    QSpinBox *NumberSpinBox;
    QSpinBox *Come1SpinBox;
    QSpinBox *Come2SpinBox;
    QLabel *label_4;
    QLabel *label_5;
    QLabel *label_6;
    QLabel *label_7;
    QSpinBox *Service1SpinBox;
    QSpinBox *Service2SpinBox;
    QLabel *label_8;
    QSpinBox *DaysSpinBox;
    QLabel *label_3;
    QWidget *widget;

    void setupUi(QWidget *dlg)
    {
        if (dlg->objectName().isEmpty())
            dlg->setObjectName(QString::fromUtf8("dlg"));
        dlg->resize(512, 270);
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(dlg->sizePolicy().hasHeightForWidth());
        dlg->setSizePolicy(sizePolicy);
        dlg->setMinimumSize(QSize(512, 270));
        dlg->setMaximumSize(QSize(512, 270));
        ModelPushButton = new QPushButton(dlg);
        ModelPushButton->setObjectName(QString::fromUtf8("ModelPushButton"));
        ModelPushButton->setGeometry(QRect(20, 220, 191, 23));
        ModelPushButton->setCheckable(false);
        label = new QLabel(dlg);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(20, 30, 121, 22));
        label->setAcceptDrops(false);
        label->setScaledContents(true);
        label->setWordWrap(true);
        label_2 = new QLabel(dlg);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(50, 60, 151, 21));
        label_2->setWordWrap(true);
        NumberSpinBox = new QSpinBox(dlg);
        NumberSpinBox->setObjectName(QString::fromUtf8("NumberSpinBox"));
        NumberSpinBox->setGeometry(QRect(150, 30, 61, 22));
        NumberSpinBox->setValue(10);
        Come1SpinBox = new QSpinBox(dlg);
        Come1SpinBox->setObjectName(QString::fromUtf8("Come1SpinBox"));
        Come1SpinBox->setGeometry(QRect(40, 80, 62, 22));
        Come2SpinBox = new QSpinBox(dlg);
        Come2SpinBox->setObjectName(QString::fromUtf8("Come2SpinBox"));
        Come2SpinBox->setGeometry(QRect(150, 80, 62, 22));
        Come2SpinBox->setValue(2);
        label_4 = new QLabel(dlg);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(20, 80, 21, 21));
        label_4->setWordWrap(true);
        label_5 = new QLabel(dlg);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setGeometry(QRect(130, 80, 21, 21));
        label_5->setWordWrap(true);
        label_6 = new QLabel(dlg);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setGeometry(QRect(20, 140, 21, 21));
        label_6->setWordWrap(true);
        label_7 = new QLabel(dlg);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        label_7->setGeometry(QRect(40, 120, 171, 21));
        label_7->setWordWrap(true);
        Service1SpinBox = new QSpinBox(dlg);
        Service1SpinBox->setObjectName(QString::fromUtf8("Service1SpinBox"));
        Service1SpinBox->setGeometry(QRect(40, 140, 62, 22));
        Service1SpinBox->setValue(4);
        Service2SpinBox = new QSpinBox(dlg);
        Service2SpinBox->setObjectName(QString::fromUtf8("Service2SpinBox"));
        Service2SpinBox->setGeometry(QRect(150, 140, 62, 22));
        Service2SpinBox->setValue(6);
        label_8 = new QLabel(dlg);
        label_8->setObjectName(QString::fromUtf8("label_8"));
        label_8->setGeometry(QRect(130, 140, 21, 21));
        label_8->setWordWrap(true);
        DaysSpinBox = new QSpinBox(dlg);
        DaysSpinBox->setObjectName(QString::fromUtf8("DaysSpinBox"));
        DaysSpinBox->setGeometry(QRect(150, 180, 61, 22));
        DaysSpinBox->setValue(30);
        label_3 = new QLabel(dlg);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(20, 180, 121, 22));
        label_3->setAcceptDrops(false);
        label_3->setScaledContents(true);
        label_3->setWordWrap(true);
        widget = new QWidget(dlg);
        widget->setObjectName(QString::fromUtf8("widget"));
        widget->setGeometry(QRect(240, 10, 261, 251));

        retranslateUi(dlg);

        QMetaObject::connectSlotsByName(dlg);
    } // setupUi

    void retranslateUi(QWidget *dlg)
    {
        dlg->setWindowTitle(QApplication::translate("dlg", "Form", 0, QApplication::UnicodeUTF8));
        ModelPushButton->setText(QApplication::translate("dlg", "\320\234\320\276\320\264\320\265\320\273\320\270\321\200\320\276\320\262\320\260\321\202\321\214", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("dlg", "\320\232\320\276\320\273\320\270\321\207\320\265\321\201\321\202\320\262\320\276 \321\202\321\200\320\260\321\203\320\273\320\265\321\200\320\276\320\262", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("dlg", "\320\237\321\200\320\270\320\261\321\213\321\202\320\270\320\265 \321\202\321\200\320\260\321\203\320\273\320\265\321\200\320\276\320\262, \321\201\321\203\321\202\320\276\320\272", 0, QApplication::UnicodeUTF8));
        label_4->setText(QApplication::translate("dlg", "\320\276\321\202", 0, QApplication::UnicodeUTF8));
        label_5->setText(QApplication::translate("dlg", "\320\264\320\276", 0, QApplication::UnicodeUTF8));
        label_6->setText(QApplication::translate("dlg", "\320\276\321\202", 0, QApplication::UnicodeUTF8));
        label_7->setText(QApplication::translate("dlg", "\320\236\320\261\321\201\320\273\321\203\320\266\320\270\320\262\320\260\320\275\320\270\320\265 \321\202\321\200\320\260\321\203\320\273\320\265\321\200\320\276\320\262, \321\207\320\260\321\201\320\276\320\262", 0, QApplication::UnicodeUTF8));
        label_8->setText(QApplication::translate("dlg", "\320\264\320\276", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("dlg", "\320\232\320\276\320\273\320\270\321\207\320\265\321\201\321\202\320\262\320\276 \321\201\321\203\321\202\320\276\320\272", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class dlg: public Ui_dlg {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DLG_H
