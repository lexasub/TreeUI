#include "utree.h"
#include "ui_utree.h"

#include <QToolBar>

UTree::UTree(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::UTree)
{
    ui->setupUi(this);
    model = new QFileSystemModel(this);
    QString homeDir = QDir::homePath();
    model->setRootPath(homeDir);

    treeView = new QTreeView(this);
    treeView->setModel(model);
    treeView->setRootIndex(model->index(homeDir));

    // Создаем панель инструментов
    QToolBar* toolBar = new QToolBar(this);
    addToolBar(toolBar);

    filterLineEdit = new QLineEdit(this);
    toolBar->addWidget(filterLineEdit);

    // Добавляем виджеты на главное окно
    setCentralWidget(treeView);

    // Подключаем сигнал изменения текста в QLineEdit к слоту фильтрации
    connect(filterLineEdit, &QLineEdit::textChanged, [this](const QString &text) {
        treeView->setRootIndex(model->index(QDir::homePath()));
        treeView->scrollTo(model->index(0, 0));
        treeView->collapseAll();
        treeView->expandToDepth(0);
        treeView->expandAll();

        QModelIndexList allIndexes = model->match(
            model->index(QDir::homePath()),
            Qt::DisplayRole,
            text,
            -1,
            Qt::MatchContains | Qt::MatchRecursive);

        foreach (const QModelIndex &index, allIndexes)
        {
            treeView->expand(index);
            treeView->setCurrentIndex(index);
        }
    });
}

UTree::~UTree()
{
    delete ui;
}

