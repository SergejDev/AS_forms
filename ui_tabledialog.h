/********************************************************************************
** Form generated from reading UI file 'tabledialog.ui'
**
** Created: Thu 6. Dec 01:22:51 2012
**      by: Qt User Interface Compiler version 4.8.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TABLEDIALOG_H
#define UI_TABLEDIALOG_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDialog>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QTableWidget>

QT_BEGIN_NAMESPACE

class Ui_TableDialog
{
public:
    QHBoxLayout *horizontalLayout;
    QTableWidget *tableWidget;

    void setupUi(QDialog *TableDialog)
    {
        if (TableDialog->objectName().isEmpty())
            TableDialog->setObjectName(QString::fromUtf8("TableDialog"));
        TableDialog->resize(540, 314);
        horizontalLayout = new QHBoxLayout(TableDialog);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        tableWidget = new QTableWidget(TableDialog);
        if (tableWidget->columnCount() < 3)
            tableWidget->setColumnCount(3);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(2, __qtablewidgetitem2);
        tableWidget->setObjectName(QString::fromUtf8("tableWidget"));

        horizontalLayout->addWidget(tableWidget);


        retranslateUi(TableDialog);

        QMetaObject::connectSlotsByName(TableDialog);
    } // setupUi

    void retranslateUi(QDialog *TableDialog)
    {
        TableDialog->setWindowTitle(QApplication::translate("TableDialog", "Dialog", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem = tableWidget->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QApplication::translate("TableDialog", "Id", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem1 = tableWidget->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QApplication::translate("TableDialog", "Name", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem2 = tableWidget->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QApplication::translate("TableDialog", "Score", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class TableDialog: public Ui_TableDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TABLEDIALOG_H
