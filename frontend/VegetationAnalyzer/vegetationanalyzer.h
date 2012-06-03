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
<<<<<<< HEAD
    void on_listWidget_doubleClicked(const QModelIndex &);
    void on_listWidget_clicked(const QModelIndex &);
=======
    void on_listWidget_clicked(QModelIndex index);
    void on_listWidget_itemClicked(QListWidgetItem* item);
	//void on_listWidget_doubleClicked(const QModelIndex &index)
>>>>>>> 4092b4ae4824c858cf0ded97972d8790fac32be7
    void on_actionOpen_triggered();
};

#endif // VEGETATIONANALYZER_H
