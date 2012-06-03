#include "vegetationanalyzer.h"
#include "ui_vegetationanalyzer.h"
#include <QWebView>
#include <QFileDialog>


VegetationAnalyzer::VegetationAnalyzer(QWidget *parent) : QMainWindow(parent),
    ui(new Ui::VegetationAnalyzer)
{
    ui->setupUi(this);

    imageApp = new Application();

    setupSignals();
}

VegetationAnalyzer::~VegetationAnalyzer()
{
    delete ui;
}

void VegetationAnalyzer::setupSignals()
{
    connect(ui->actionQuit, SIGNAL(triggered()), this, SLOT(close()) );

}

void VegetationAnalyzer::changeEvent(QEvent *e)
{
    QMainWindow::changeEvent(e);
    switch (e->type()) {
    case QEvent::LanguageChange:
        ui->retranslateUi(this);
        break;
    default:
        break;
    }
}

void VegetationAnalyzer::on_actionOpen_triggered()
{
    QStringList files = QFileDialog::getOpenFileNames(
                            this,
                            "Select at least 3 files to open",
                            QDir::currentPath(),
                            "Images (*.tif)");
    this->sourceFiles = files;
}


void VegetationAnalyzer::on_listWidget_doubleClicked(const QModelIndex &index)
{
    //assert(sourceFiles.count() > 2);
    //imageApp->readImages(sourceFiles);
    //imageApp->false_color();
    //ui->graphicsView->setBackgroundBrush(("/tmp/fake/falseColorImage.tif"));
    QGraphicsScene *scn = new QGraphicsScene( ui->graphicsView );
    scn->setSceneRect( ui->graphicsView->rect() );
    ui->graphicsView->setScene( scn );
    ui->graphicsView->setFixedSize( 400, 400 );
    QPixmap pix( "/tmp/fake/falseColorImage.tif" );
    scn->addPixmap( pix );
}

void VegetationAnalyzer::on_listWidget_clicked(const QModelIndex &index)
{
        ui->textBrowser->setText("foo");

        if (index.row() == 1) {
            ui->textBrowser->setText("The \"natural color\" band combination.\n\n Because the visible bands are used in this combination, ground features appear in colors  	similar to their appearance to the human visual system, healthy vegetation is green, recently  	cleared fields are very light, unhealthy vegetation is brown and yellow, roads are gray, 	and shorelines are white. This band combination provides the most water penetration  	and superior sediment and bathymetric information. It is also used for urban studies. Cleared  	and sparsely vegetated areas are not as easily detected here as in the 4 5 1 or 4 3 2 combination.  	Clouds and snow appear white and are difficult to distinguish. Also note that vegetation  	types are not as easily distinguished as the 4 5 1 combination. The 3 2 1 combination does  	not distinguish shallow water from soil as well as the 7 5 3 combination does.");
        }
        if (index.row() == 0) {
            ui->textBrowser->setText("\"Thermal image\" band combination\n\n Because the visible bands are used in this combination, ground features appear in colors");
        }
}
