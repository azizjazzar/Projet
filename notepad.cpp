#include "notepad.h"
#include "ui_notepad.h"

notePad::notePad(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::notePad)
{
    ui->setupUi(this);
    this->setCentralWidget(ui->textEdit);

}

notePad::~notePad()
{
    delete ui;
}

void notePad::on_actionnouveau_triggered()
{
    currentFile.clear();

        // Clear the textEdit widget buffer
        ui->textEdit->setText(QString());
}

void notePad::on_actionOuvrir_triggered()
{
    // Opens a dialog that allows you to select a file to open
        QString fileName = QFileDialog::getOpenFileName(this, "Open the file");

        // An object for reading and writing files
        QFile file(fileName);

        // Store the currentFile name
        currentFile = fileName;

        // Try to open the file as a read only file if possible or display a
        // warning dialog box
        if (!file.open(QIODevice::ReadOnly | QFile::Text)) {
            QMessageBox::warning(this, "Warning", "Cannot open file: " + file.errorString());
            return;}

        // Set the title for the window to the file name
        setWindowTitle(fileName);

        // Interface for reading text
        QTextStream in(&file);

        // Copy text in the string
        QString text = in.readAll();

        // Put the text in the textEdit widget
        ui->textEdit->setText(text);

        // Close the file
        file.close();
}

void notePad::on_actionEnregistrer_triggered()
{

    QString fileName = QFileDialog::getSaveFileName(this, "Save as");

        // An object for reading and writing files
        QFile file(fileName);

        // Try to open a file with write only options
        if (!file.open(QFile::WriteOnly | QFile::Text)) {
            QMessageBox::warning(this, "Warning", "Cannot save file: " + file.errorString());
            return;
        }

        // Store the currentFile name
        currentFile = fileName;

        // Set the title for the window to the file name
        setWindowTitle(fileName);

        // Interface for writing text
        QTextStream out(&file);

        // Copy text in the textEdit widget and convert to plain text
        QString text = ui->textEdit->toPlainText();

        // Output to file
        out << text;

        // Close the file
        file.close();
    }


void notePad::on_actionPrint_triggered()
{
    // Allows for interacting with printer
        QPrinter printer;

        // You'll put your printer name here
        printer.setPrinterName("Printer Name");

        // Create the print dialog and pass the name and parent
        QPrintDialog pDialog(&printer, this);

        if(pDialog.exec() == QDialog::Rejected){
            QMessageBox::warning(this, "Warning", "Cannot Access Printer");
            return;
        }

        // Send the text to the printer
        ui->textEdit->print(&printer);
}

void notePad::on_actionQuitter_triggered()
{
    QApplication::quit();
}

void notePad::on_actionCopier_triggered()
{
      ui->textEdit->copy();
}

void notePad::on_actionColler_triggered()
{
     ui->textEdit->paste();
}

void notePad::on_actionCouper_triggered()
{
     ui->textEdit->cut();
}

void notePad::on_actionretour_triggered()
{
    ui->textEdit->redo();
}

void notePad::on_actionAnnuler_triggered()
{
    ui->textEdit->undo();
}
