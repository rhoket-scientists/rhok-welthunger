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
                            "Select one or more files to open",
                            QDir::currentPath(),
                            "Images (*.tif)");
    this->sourceFiles = files;
}


void VegetationAnalyzer::on_listWidget_doubleClicked(const QModelIndex &index)
{
    assert(sourceFiles.count() > 2);
    imageApp->readImages(sourceFiles);
    imageApp->false_color();
    // todo show image
}

void VegetationAnalyzer::on_listWidget_clicked(const QModelIndex &index)
{
        ui->textBrowser->setText("foo");

        if (index.row() == 0) {
            ui->textBrowser->setText("The \"natural color\" band combination.");
        }
        if (index.row() == 1) {
            ui->textBrowser->setText("\"Thermal image\" band combination");
        }
}
