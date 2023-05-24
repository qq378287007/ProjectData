#pragma once

#include <QTreeView>
#include <QMouseEvent>
#include <QSharedPointer>

#include <QMenu>
#include <QAction>

#include "TreeModel.h"

class TreeView : public QTreeView
{
    Q_OBJECT
public:
    explicit TreeView(QWidget *parent = nullptr);
public:
    void addProject(TreeItem::DataType dataType){
        if(m_TreeModel.isNull())
            return;

        switch (dataType) {
        case TreeItem::PERMANENT_MAGNET_SYNC_MOTOR_PROJECT:
        {
            m_TreeModel->addProject(dataType);

            int projectId = m_TreeModel->projectId();
            QModelIndex m_ModelIndex = m_TreeModel->index(projectId, 0);
            setCurrentIndex(m_ModelIndex);
            expandRecursively(m_ModelIndex);
            doItemsLayout();
        }
            break;
        default:
            break;
        }
    }

    void removeProject(){
        if(m_TreeModel.isNull())
            return;

        int projectId = m_TreeModel->projectId();
        if(projectId < 0)
            return;

        m_TreeModel->removeProject();
        m_TreeModel->setProjectId(-1);

        setCurrentIndex(QModelIndex());

        doItemsLayout();
    }

public:
    QSharedPointer<TreeModel> treeModel() const {
        return m_TreeModel;
    }
    void setTreeModel(const QSharedPointer<TreeModel> &TreeMoel){
        m_TreeModel = TreeMoel;
        setModel(m_TreeModel.get());
    }
private:
    QSharedPointer<TreeModel> m_TreeModel;
private:
    QMenu *menu;
    QAction *addMotionAreaAction;
    QAction *addVectorBoundaryAction;
    QAction *addSymmetricBoundaryAction;
    QAction *addAnalysisPlanAction;
    QAction *addIncentiveAction;
    QAction *removeMotionAreaAction;
    QAction *removeVectorBoundaryAction;
    QAction *removeSymmetricBoundaryAction;
    QAction *removeAnalysisPlanAction;
    QAction *removeIncentiveAction;
    TreeItem *item;
};
