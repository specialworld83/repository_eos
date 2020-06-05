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

#include "KernelCommon.h"
#include "KernelListViewDelegate.h"
#include "KernelModule.h"
#include "MsmCommon.h"
#include "ui_PageKernel.h"

#include <KAboutData>
#include <KPluginFactory>

#include <QTranslator>

K_PLUGIN_FACTORY( MsmKernelFactory,
                  registerPlugin<PageKernel>( KernelCommon::getName() ); )
PageKernel::PageKernel( QWidget* parent, const QVariantList& args ) :
    KCModule( parent, args ),
    ui( new Ui::PageKernel ),
    m_kernelModel( new KernelModel )
{
    Q_INIT_RESOURCE( translations );
    QTranslator* appTranslator = new QTranslator;
    appTranslator->load( ":/translations/msm_" + QLocale::system().name() );
    qApp->installTranslator( appTranslator );

    KAboutData* aboutData = new KAboutData( KernelCommon::getName(),
                                            KernelCommon::getTitle(),
                                            PROJECT_VERSION,
                                            KernelCommon::getDescription(),
                                            KAboutLicense::LicenseKey::GPL_V3,
                                            "(c) 2014 - 2020 Manjaro Settings Manager developers" );
    aboutData->addAuthor( "Ramon Buldó",
                          QStringLiteral( "ramon@manjaro.org" ) );
    aboutData->setCustomAuthorText( QString(), MsmCommon::getBugReportLink() );
    setAboutData( aboutData );
    setButtons( KCModule::NoAdditionalButton );

    ui->setupUi( this );

    // Setup ListView
    KernelSortFilterProxyModel* proxyKernelModel = new KernelSortFilterProxyModel( this );
    proxyKernelModel->setSourceModel( m_kernelModel );
    proxyKernelModel->setSortRole( KernelModel::VersionRole );
    proxyKernelModel->sort( 0, Qt::DescendingOrder );
    ui->kernelListView->setModel( proxyKernelModel );

    KernelListViewDelegate* kernelListViewDelegate = new KernelListViewDelegate;
    ui->kernelListView->setItemDelegate( kernelListViewDelegate );

    // Connect kernel tab slots
    connect( kernelListViewDelegate, &KernelListViewDelegate::installButtonClicked,
             [=] ( const QModelIndex& index )
    {
        KernelCommon::kernelAction( index );
        load();
    } );
    connect( kernelListViewDelegate, &KernelListViewDelegate::infoButtonClicked,
             [=] ( const QModelIndex& index )
    {
        KernelCommon::showChangelog( index );
    } );
}


PageKernel::~PageKernel()
{
    delete ui;
    delete m_kernelModel;
}


void
PageKernel::load()
{
    KernelCommon::load( m_kernelModel );
}


void
PageKernel::save()
{
}


void
PageKernel::defaults()
{
}

#include "KernelModule.moc"
