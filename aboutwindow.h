#ifndef ABOUTWINDOW_H
#define ABOUTWINDOW_H

#include <QDialog>

namespace Ui {
class aboutWindow;
}

class AboutWindow : public QDialog
{
    Q_OBJECT

public:
    explicit AboutWindow(QWidget *parent = 0);
    ~AboutWindow();

private slots:
<<<<<<< HEAD
    void on_btnOpenBitbucket_clicked();
    void on_btnOpenGithub_clicked();
=======
    void on_btnOpenWebsite_clicked();
>>>>>>> origin/master

private:
    Ui::aboutWindow *ui;
};

#endif // ABOUTWINDOW_H
