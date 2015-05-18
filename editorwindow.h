#ifndef EDITORWINDOW_H
#define EDITORWINDOW_H

#include <QMainWindow>
<<<<<<< HEAD
#include <QVector>

#include <QFileDialog>
#include <QMessageBox>
#include <QTextStream>
#include <QTime>

#include "editorwidget.h"
=======
>>>>>>> origin/master

namespace Ui {
class EditorWindow;
}

class EditorWindow : public QMainWindow
{
    Q_OBJECT

public:
<<<<<<< HEAD

=======
>>>>>>> origin/master
    explicit EditorWindow(QWidget *parent = 0);
    ~EditorWindow();

private slots:

<<<<<<< HEAD
    // New tab creation
    void on_actionNew_triggered();

    /*
=======
>>>>>>> origin/master
    // Shortcuts functionality
    void on_actionList_triggered(bool condition);
    void on_actionNumberedList_triggered(bool condition);
    void on_actionLineTildas_triggered();
    void on_actionHeader_triggered();

    // Save/Load functionality
    void on_actionSave_triggered();
    void on_actionOpen_triggered();

    // Supplemental functionality
<<<<<<< HEAD

    void on_actionNew_triggered();
    void on_actionSaveAs_triggered();
    void on_actionLecture_triggered();
    void on_searchButton_clicked();
    void on_searchRequest_textChanged(const QString &arg1);
    void on_searchRequest_returnPressed();
    void on_findLectureButton_clicked();
    void on_actionDefinition_triggered();
    void on_tabWidget_currentChanged(int index);
    */

    // Tab widget operations
    void on_tabWidget_tabCloseRequested(int index);
    void on_tabWidget_currentChanged(int index);

    // Toolbar click operations
    void on_actionHelp_triggered();

    void on_actionSave_triggered();

protected:
    //void closeEvent(QCloseEvent *e);

private:
    Ui::EditorWindow *ui;
    EditorWidget *editor;

    //bool eventFilter(QObject *obj, QEvent *e);

    // State management
    void setStateToDefault();
    void setStateFromSettings(const EditorSettings *source);

    void StartSearch();
    void SetLetters(bool isCapital);

    void createTab(QString tabName = QString("Untitled"));
=======
    void on_txtEditorField_textChanged();

    void on_actionNew_triggered();

    void on_actionSaveAs_triggered();

    void on_actionHelp_triggered();

protected:
    void closeEvent(QCloseEvent *e);

private:
    Ui::EditorWindow *ui;

    bool documentWasSaved;
    bool markedListOn;
    bool numberedListOn;
    int numberedListCounter;

    bool textWasChanged;

    QString currentFileName;

    bool haveUnsavedChanges();
    bool eventFilter(QObject *obj, QEvent *e);

    void resetToBaseState();
>>>>>>> origin/master
};

#endif // EDITORWINDOW_H
