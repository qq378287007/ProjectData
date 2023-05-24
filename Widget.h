#pragma once

#include <QWidget>
#include <QDebug>
#include <QPushButton>
#include <QHBoxLayout>
#include <QVBoxLayout>

#include "TreeView.h"

class Widget : public QWidget
{
    Q_OBJECT
public:
    explicit Widget(QWidget *parent = nullptr): QWidget(parent)
    {
        QPushButton *addProjectBtn = new QPushButton("增加工程", this);
        QPushButton *removeProjectBtn = new QPushButton("删除工程", this);
        QHBoxLayout *m_UpLayout = new QHBoxLayout();
        m_UpLayout->addWidget(addProjectBtn);
        m_UpLayout->addWidget(removeProjectBtn);
        m_UpLayout->addStretch();

        TreeView *m_TreeView = new TreeView(this);

        QVBoxLayout *m_MainLayout = new QVBoxLayout(this);
        m_MainLayout->addLayout(m_UpLayout);
        m_MainLayout->addWidget(m_TreeView, 1);

        QSharedPointer<TreeModel> m_TreeModel(new TreeModel());
        m_TreeView->setTreeModel(m_TreeModel);

        connect(addProjectBtn, &QPushButton::clicked, [=](){
            qDebug()<<"增加工程";
            m_TreeView->addProject(TreeItem::PERMANENT_MAGNET_SYNC_MOTOR_PROJECT);
        });

        connect(removeProjectBtn, &QPushButton::clicked, [=](){
            qDebug()<<"删除工程";
            m_TreeView->removeProject();
        });

        connect(m_TreeView->selectionModel(), &QItemSelectionModel::currentChanged, [=](const QModelIndex &index){
            if (index.isValid())
            {
                int m_ProjectId = m_TreeView->treeModel()->getProjectId(index);
                m_TreeView->treeModel()->setProjectId(m_ProjectId);
            }
        });
    }
};
