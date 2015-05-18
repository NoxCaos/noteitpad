#include "aboutwindow.h"
#include "ui_aboutwindow.h"
#include <QDesktopServices>
#include <QUrl>

AboutWindow::AboutWindow(QWidget *parent) :
    QDialog(parent, Qt::WindowSystemMenuHint | Qt::WindowTitleHint | Qt::WindowCloseButtonHint),
    ui(new Ui::aboutWindow)
{
    ui->setupUi(this);
<<<<<<< HEAD
    setFixedSize(width(), height());
=======
    setFixedSize(290, 240);
>>>>>>> origin/master
}

AboutWindow::~AboutWindow()
{
    delete ui;
}

<<<<<<< HEAD
void AboutWindow::on_btnOpenBitbucket_clicked()
{
    QDesktopServices::openUrl(QUrl("https://bitbucket.org/mdmitriev/noteitpad"));
}

void AboutWindow::on_btnOpenGithub_clicked()
{
    QDesktopServices::openUrl(QUrl("https://github.com/Maxym-Dmytriiev/noteitpad"));
}
=======
void AboutWindow::on_btnOpenWebsite_clicked()
{
    QDesktopServices::openUrl(QUrl("https://bitbucket.org/mdmitriev/noteitpad"));
}
>>>>>>> origin/master
