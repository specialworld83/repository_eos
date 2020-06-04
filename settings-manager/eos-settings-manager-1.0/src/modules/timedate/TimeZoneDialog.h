/*
 *  This file is part of Manjaro Settings Manager.
 *
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

#ifndef TIMEZONEDIALOG_H
#define TIMEZONEDIALOG_H

#include <QDialog>
#include "TimeZoneWidget.h"

namespace Ui
{
class TimeZoneDialog;
}

class TimeZoneDialog : public QDialog
{
    Q_OBJECT

public:
    explicit TimeZoneDialog( QWidget* parent = 0 );
    ~TimeZoneDialog();
    void init( const QString& initialRegion, const QString& initialZone );
    QString currentLocation();

private:
    Ui::TimeZoneDialog* ui;
    TimeZoneWidget* m_timeZoneWidget;

    bool m_blockTimeZoneWidgetSet;
};

#endif // TIMEZONEDIALOG_H
