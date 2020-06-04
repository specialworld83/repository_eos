/*
 *  This file is part of Manjaro Settings Manager.
 *
 *  Roland Singer <roland@manjaro.org>
 *  Ramon Buldó <ramon@manjaro.org>
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

#ifndef PAGELANGUAGE_H
#define PAGELANGUAGE_H

#include "SelectLocalesDialog.h"
#include "LanguageListViewDelegate.h"
#include "EnabledLocalesModel.h"
#include "PageWidget.h"

namespace Ui
{
class LocaleModule;
}


class LocalePage : public PageWidget
{
    Q_OBJECT

public:
    explicit LocalePage( QWidget* parent = 0 );
    ~LocalePage();

    void load();
    void save();
    void defaults();

private:
    Ui::LocaleModule* ui;
    EnabledLocalesModel* m_enabledLocalesModel;
    LanguageListViewDelegate* m_languageListViewDelegate;
    bool m_isLocaleListModified;
    bool m_isSystemLocalesModified;

protected slots:
    void addLocale();
    void removeLocale();
    void disableRemoveButton( const QModelIndex& current, const QModelIndex& previous );

};

#endif // PAGELANGUAGE_H
