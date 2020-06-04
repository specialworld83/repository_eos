/*
 *  This file is part of Manjaro Settings Manager.
 *
 *  Roland Singer <roland@manjaro.org>
 *
 *  Manjaro Settings Manager is free software: you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation, either version 3 of the License, or
 *  (at your option) any later version.
 *
 *  Manjaro Settings Manager is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with Manjaro Settings Manager.  If not, see <http://www.gnu.org/licenses/>.
 */

#ifndef ADDUSERDIALOG_H
#define ADDUSERDIALOG_H

#include "UsersCommon.h"

#include <QDialog>
#include <QMessageBox>
#include <QStringList>
#include <QRegExp>
#include <QRegExpValidator>



namespace Ui
{
class AddUserDialog;
}


class AddUserDialog : public QDialog
{
    Q_OBJECT

public:
    explicit AddUserDialog( QWidget* parent = 0 );
    ~AddUserDialog();

    bool userDataChanged()
    {
        return dataChanged;
    }
    using QDialog::exec;

public slots:
    virtual int exec();

private:
    Ui::AddUserDialog* ui;
    bool dataChanged;

private slots:
    void buttonCreate_clicked();
    void textbox_textChanged();
};

#endif // ADDUSERDIALOG_H
