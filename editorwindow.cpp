#include "editorwindow.h"
#include "ui_editorwindow.h"

#include "aboutwindow.h"

<<<<<<< HEAD
#include <QDebug>
=======

#include <QFileDialog>
#include <QMessageBox>
#include <QTextStream>
#include <QTime>
>>>>>>> origin/master


EditorWindow::EditorWindow(QWidget *parent) :
    QMainWindow(parent),
<<<<<<< HEAD
    ui(new Ui::EditorWindow), editor(new EditorWidget())
{
    ui->setupUi(this);
    this->setFixedSize(width(), height());

    ui->tabWidget->addTab(editor, "Untitled");
    editor->setFocus();

    //addAction(ui->actionSaveAs);
=======
    ui(new Ui::EditorWindow)
{
    ui->setupUi(this);
    ui->txtEditorField->installEventFilter(this);

    this->setFixedSize(width(), height());
    addAction(ui->actionSaveAs);

    resetToBaseState();
>>>>>>> origin/master

}

EditorWindow::~EditorWindow()
{
    delete ui;
}

<<<<<<< HEAD
// Resets menu buttons to their default state
void EditorWindow::setStateToDefault()
{
    ui->actionMarkedList->setEnabled(true);
    ui->actionMarkedList->setChecked(false);

    ui->actionNumberedList->setEnabled(true);
    ui->actionNumberedList->setChecked(false);

}

// Sets state of menu buttons according to EditorSettings object data
void EditorWindow::setStateFromSettings(const EditorSettings *source)
{
    if (source->getMarkedListOn()) {
        ui->actionMarkedList->setChecked(true);
        ui->actionNumberedList->setEnabled(false);
    }
    else if (source->getNumberedListOn()) {
        ui->actionNumberedList->setChecked(true);
        ui->actionMarkedList->setEnabled(false);
    }
}

// Creates new tab with stated name
void EditorWindow::createTab(QString tabName)
{
    EditorWidget * newEditor = new EditorWidget();
    ui->tabWidget->addTab(newEditor, tabName);
    ui->tabWidget->setCurrentIndex(ui->tabWidget->count() - 1);

    int lastWidgetIndex = ui->tabWidget->count() - 1;
    ui->tabWidget->widget(lastWidgetIndex)->setFocus();

    connect(newEditor, SIGNAL(needToSave()), this, SLOT(on_actionSave_triggered()));

}

/*


void EditorWindow::SetLetters(bool isCapital){
    //We set letters to capital

    QTextCharFormat capital;
    if(isCapital){
        capital.setFontCapitalization(QFont::Capitalize);
    }
    else{
        capital.setFontCapitalization(QFont::MixedCase);
    }
    txtEditor->setCurrentCharFormat(capital);
=======
// Shortcuts implementation
void EditorWindow::on_actionList_triggered(bool condition)
{
    // Switch button states
    ui->actionNumberedList->setEnabled(!condition);

    // Setup list states
    markedListOn = condition;

    if (condition) {
        ui->txtEditorField->appendPlainText(QString::fromUtf8("+ "));
    }
}

void EditorWindow::on_actionNumberedList_triggered(bool condition)
{
    // Switch button states
    ui->actionList->setEnabled(!condition);

    // Setup list states
    numberedListOn = condition;

    if (!numberedListOn) {
        numberedListCounter = 1;
    }

    if (condition) {
        ui->txtEditorField->appendPlainText(QString::fromUtf8("1. "));
    }
>>>>>>> origin/master
}

bool EditorWindow::eventFilter(QObject *obj, QEvent *e)
{
<<<<<<< HEAD
    if (obj == txtEditor && e->type() == QEvent::KeyRelease) {
=======
    if (obj == ui->txtEditorField && e->type() == QEvent::KeyRelease) {
>>>>>>> origin/master
        QKeyEvent *keyEvent = static_cast<QKeyEvent*>(e);
        if (keyEvent->key() == Qt::Key_Return ||
            keyEvent->key() == Qt::Key_Enter)
        {
            if (markedListOn) {
<<<<<<< HEAD
                txtEditor->appendPlainText(QString::fromUtf8("+ "));
            }
            else if (numberedListOn) {
                txtEditor->insertPlainText(QString::number(++numberedListCounter) +
                                                    QString::fromUtf8(". "));
            }
            else if(lectureNameEdit){
                txtEditor->textCursor().deletePreviousChar();
                txtEditor->insertPlainText(" " + QDate::currentDate().toString() + "\n\n");
                this->lectureNameEdit = false;
            }


             // A little fix that prevents date appearing again
             // if enter was pressed after list (or smth else)

            if(lectureNameEdit) this->lectureNameEdit = false;

            SetLetters(true);
            return true;
        }
        else if(keyEvent->key() == Qt::Key_Space){
            //Let's make letters capital after a dot!

            QTextCursor cursor = txtEditor->textCursor();
            cursor.movePosition(QTextCursor::PreviousCharacter);
            cursor.select(QTextCursor::WordUnderCursor);
            QString c = cursor.selectedText().right(1);
            if(c == "."){
                SetLetters(true);
            }
        }
        else {
            SetLetters(false);
=======
                ui->txtEditorField->appendPlainText(QString::fromUtf8("+ "));
            }
            else if (numberedListOn) {
                ui->txtEditorField->insertPlainText(QString::number(++numberedListCounter) +
                                                    QString::fromUtf8(". "));
            }

            return true;
        }
        else {
>>>>>>> origin/master
            return QMainWindow::eventFilter(obj, e);
        }
    }
    else {
        return QMainWindow::eventFilter(obj, e);
    }
<<<<<<< HEAD

=======
>>>>>>> origin/master
}

void EditorWindow::resetToBaseState()
{
    ui->actionList->setEnabled(true);
    ui->actionList->setChecked(false);
    markedListOn = false;

    ui->actionNumberedList->setEnabled(true);
    ui->actionNumberedList->setChecked(false);
    numberedListOn = false;
    numberedListCounter = 1;

<<<<<<< HEAD
    this->lectureNameEdit = false;

=======
>>>>>>> origin/master
    textWasChanged = false;
    documentWasSaved = false;

    currentFileName = "Untitled";
    this->setWindowTitle("NoteIt Pad - " + currentFileName);
    ui->statusBar->showMessage(QTime::currentTime().toString() + " - Created new empty document");
}


void EditorWindow::on_actionLineTildas_triggered()
{
<<<<<<< HEAD
    txtEditor->appendPlainText("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
=======
    ui->txtEditorField->appendPlainText("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
>>>>>>> origin/master
}

void EditorWindow::on_actionHeader_triggered()
{
<<<<<<< HEAD
    txtEditor->insertPlainText("------------");
    SetLetters(true);
}

void EditorWindow::on_actionDefinition_triggered()
{
    txtEditor->insertPlainText("\n-> ");
    SetLetters(true);
}

void EditorWindow::on_actionLecture_triggered()
{
    txtEditor->appendPlainText("\n===Lecture #");
    this->lectureNameEdit = true;
}
=======
    ui->txtEditorField->insertPlainText("------------");
}

>>>>>>> origin/master


// Save/Load functionality implementation
void EditorWindow::on_actionSave_triggered()
{
    QString saveFileName = currentFileName;

    // If this document was not already saved, open
    // a SaveFile dialog
    if (!documentWasSaved) {
        // Open dialog with user
        saveFileName = QFileDialog::getSaveFileName
                (this,
                 tr("Save notes..."),
                 "",
                 tr("Plain text file (*.txt);;All Files (*)"));

    }

    // If user deceided not to save file
    if (saveFileName.isEmpty()) {
            return;
    }
    else {
        QFile file(saveFileName);

        // Try to open file in Write-only mode
        if (!file.open(QIODevice::WriteOnly)) {
            QMessageBox::information(this,
                                     tr("Unable to open file"),
                                     file.errorString());
            return;
        }

        // Write contents to txt file:
        QTextStream out(&file);
        out.setCodec("UTF-8");
<<<<<<< HEAD
        out << txtEditor->toPlainText();
=======
        out << ui->txtEditorField->toPlainText();
>>>>>>> origin/master

        // Change system variables
        currentFileName = saveFileName;
        documentWasSaved = true;
        textWasChanged = false;

        // Refresh supplemental text...
        QString shortName = QFileInfo(file).baseName();
        setWindowTitle("NoteIt Pad - " + shortName);
        ui->statusBar->showMessage(QTime::currentTime().toString() + " - Saved file \"" + shortName + "\"");
    }
}

void EditorWindow::on_actionSaveAs_triggered()
{
    documentWasSaved = false;
    on_actionSave_triggered();
}

void EditorWindow::on_actionOpen_triggered()
{
    bool decision = haveUnsavedChanges();

    // User deceided to wait
    if (decision == true) {
        return;
    }

    QString loadFileName = QFileDialog::getOpenFileName(this,
             tr("Open notes file..."), "",
             tr("Plain text files (*.txt);;All Files (*)"));

    if (loadFileName.isEmpty()) {
             return;
    }
    else {
        // Crate instance of file
        QFile file(loadFileName);

        // Try to open file for reading
        if (!file.open(QIODevice::ReadOnly)) {
            QMessageBox::information(this,
                                     tr("Unable to open file"),
                                     file.errorString());
            return;
        }

        // Read text file contents
        QTextStream in(&file);
        in.setCodec("UTF-8");
        QString contents = in.readAll();

        // Reset window
        resetToBaseState();

<<<<<<< HEAD
        // txtEditor = CreateTab(QFileInfo(file).baseName());

        // Insert data into editor
        txtEditor->setPlainText(contents);
=======
        // Insert data into editor
        ui->txtEditorField->setPlainText(contents);
>>>>>>> origin/master
        currentFileName = loadFileName;

        documentWasSaved = true;
        textWasChanged = false;

        // Refresh supplemental text
        QString shortName = QFileInfo(file).baseName();
        setWindowTitle("NoteIt Pad - " + shortName);
        ui->statusBar->showMessage(QTime::currentTime().toString() + " - Loaded file \"" + shortName + "\"");
    }
}

void EditorWindow::closeEvent(QCloseEvent *e)
{
    bool decision = haveUnsavedChanges();

    // User deceided to wait
    if (decision == true) {
        e->ignore();
        return;
    }

    e->accept();
}

void EditorWindow::on_actionNew_triggered()
{
    bool decision = haveUnsavedChanges();

    if (decision) {
        return;
    }
    // Reset window
<<<<<<< HEAD
    txtEditor->clear();
    resetToBaseState();
    //CreateTab();
}

// Supplemental functionality

=======
    ui->txtEditorField->clear();
    resetToBaseState();
}

// Supplemental functionality
void EditorWindow::on_txtEditorField_textChanged()
{
    textWasChanged = true;
}
>>>>>>> origin/master

bool EditorWindow::haveUnsavedChanges()
{
    // Detect if user has unsaved changes
    if (textWasChanged) {

        QMessageBox::StandardButton reply;
        // Ask user for actions
        reply = QMessageBox::question(this,
                                      "Unsaved changes",
                                      "You have unsaved changes.\nSave them?",
                                      QMessageBox::Yes|QMessageBox::No|QMessageBox::Cancel);

        // Discard changes
        if (reply == QMessageBox::No) {
            return false;
        }

        // Save changes
        if (reply == QMessageBox::Yes) {
            on_actionSave_triggered();
            return false;
        }

        return true;
    }

    return false;
}

<<<<<<< HEAD


void EditorWindow::on_searchButton_clicked()
{
    StartSearch();
}

void EditorWindow::on_searchRequest_textChanged(const QString &arg1)
{
    txtEditor->moveCursor(QTextCursor::Start);
    //Some improvements fore live search
    QString s = ui->searchRequest->text();
    if(!ui->searchRequest->text().isEmpty() && !txtEditor->find(s)){
        ui->searchRequest->setStyleSheet("QLineEdit{background: #FF3848;}");
    }
    else ui->searchRequest->setStyleSheet("QLineEdit{background: white;}");
}

void EditorWindow::on_searchRequest_returnPressed()
{
    StartSearch();
}

void EditorWindow::StartSearch(){
    QString s = ui->searchRequest->text();
    txtEditor->setFocus();
    if(!txtEditor->find(s)){
        QMessageBox::information(this,
                                              "Nothing found",
                                              "Find reached the starting point of the search",
                                              QMessageBox::Ok);
        txtEditor->setFocus();
        txtEditor->moveCursor(QTextCursor::Start);
        txtEditor->find(s);
    }
}

void EditorWindow::on_findLectureButton_clicked()
{
    txtEditor->setFocus();
    txtEditor->moveCursor(QTextCursor::Start);
    QString s = "===Lecture #" + ui->lectureNumberField->text();
    txtEditor->find(s);
}

void EditorWindow::on_tabWidget_currentChanged(int index)
{
}
*/

void EditorWindow::on_tabWidget_tabCloseRequested(int index)
{
    if (editor->haveUnsavedChanges()) {
        return;
    }

    if (ui->tabWidget->count() == 1) {
        createTab();
    }

    ui->tabWidget->removeTab(index);

}

void EditorWindow::on_tabWidget_currentChanged(int index)
{
    this->editor = dynamic_cast<EditorWidget*>(ui->tabWidget->widget(index));

    setStateToDefault();
    setStateFromSettings(editor->getSettings());

    qDebug() << editor << endl;
}

=======
void EditorWindow::on_actionHelp_triggered()
{
    AboutWindow *about = new AboutWindow(this);
    about->show();
}
>>>>>>> origin/master
