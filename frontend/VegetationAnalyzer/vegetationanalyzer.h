#ifndef VEGETATIONANALYZER_H
#define VEGETATIONANALYZER_H

#include <QMainWindow>
#include <QFile>
#include "Application.h"
#include <QListWidgetItem>
#include <list>


namespace Ui {
    class VegetationAnalyzer;
}

class VegetationAnalyzer : public QMainWindow {
    Q_OBJECT
public:
    VegetationAnalyzer(QWidget *parent = 0);
    ~VegetationAnalyzer();

protected:
    void changeEvent(QEvent *e);

private:
    Application* imageApp;
    Ui::VegetationAnalyzer *ui;
    void setupSignals();
    QList<QString> sourceFiles;

private slots:
    void on_listWidget_itemClicked(QListWidgetItem* item);
    void on_actionOpen_triggered();
};

#endif // VEGETATIONANALYZER_H
