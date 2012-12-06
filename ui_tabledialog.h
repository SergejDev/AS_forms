/********************************************************************************
** Form generated from reading UI file 'tabledialog.ui'
**
** Created: Thu 6. Dec 16:12:33 2012
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
#include <QtGui/QTableView>

QT_BEGIN_NAMESPACE

class Ui_TableDialog
{
public:
    QHBoxLayout *horizontalLayout;
    QTableView *tableView;

    void setupUi(QDialog *TableDialog)
    {
        if (TableDialog->objectName().isEmpty())
            TableDialog->setObjectName(QString::fromUtf8("TableDialog"));
        TableDialog->resize(540, 314);
        horizontalLayout = new QHBoxLayout(TableDialog);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        tableView = new QTableView(TableDialog);
        tableView->setObjectName(QString::fromUtf8("tableView"));

        horizontalLayout->addWidget(tableView);


        retranslateUi(TableDialog);

        QMetaObject::connectSlotsByName(TableDialog);
    } // setupUi

    void retranslateUi(QDialog *TableDialog)
    {
        TableDialog->setWindowTitle(QApplication::translate("TableDialog", "Dialog", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class TableDialog: public Ui_TableDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TABLEDIALOG_H
