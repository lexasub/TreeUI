#ifndef UTREE_H
#define UTREE_H

#include <QMainWindow>
#include <QFileSystemModel>
#include <QLineEdit>
#include <QTreeView>
QT_BEGIN_NAMESPACE
namespace Ui { class UTree; }
QT_END_NAMESPACE

class UTree : public QMainWindow
{
    Q_OBJECT

public:
    UTree(QWidget *parent = nullptr);
    ~UTree();

private:
    Ui::UTree *ui;
    QFileSystemModel *model;
    QTreeView *treeView;
    QLineEdit *filterLineEdit;
};
#endif // UTREE_H
