#pragma once

#include <QAbstractItemModel>
#include <QList>
#include <QSharedPointer>
#include <QDebug>

#include "TreeItem.h"
#include "ProjectContainerData.h"

class TreeModel : public QAbstractItemModel
{
    Q_OBJECT
public:
    explicit TreeModel(QObject *parent = nullptr)
        : QAbstractItemModel(parent)
        , m_Root(new ProjectContainerData())
    {
    }
public:
    void addProject(TreeItem::DataType dataType){
        m_Root->addProject(dataType);
    }
    void removeProject(){
        m_Root->removeProject();
    }

    int projectId() const {
        return m_Root->projectId();
    }
    void setProjectId(int projectId){
        m_Root->setProjectId(projectId);
    }

    int getProjectId(const QModelIndex &index){
        if(!index.isValid())
            return -1;

        QModelIndex m_ModelIndex = index;
        while(m_ModelIndex.parent().isValid())
           m_ModelIndex = m_ModelIndex.parent();

        TreeItem *item = itemFromIndex(m_ModelIndex);
        return item->row();
    }
public:
    QVariant data(const QModelIndex &index, int role) const override
    {
        if (index.isValid()){
            TreeItem *item = itemFromIndex(index);
            return item->data(role);
        }
        return QVariant();
    }
    QModelIndex index(int row, int column, const QModelIndex &parent = QModelIndex()) const override
    {
        if(hasIndex(row, column, parent))
        {
            TreeItem *parentItem = itemFromIndex(parent);
            QSharedPointer<TreeItem> item = parentItem->childAt(row);
            if (item)
                return createIndex(row, column, item.get());
        }
        return QModelIndex();
    }
    QModelIndex parent(const QModelIndex &index) const override
    {
        if (!index.isValid())
            return QModelIndex();

        TreeItem *item = itemFromIndex(index);
        if (item->dataType() == TreeItem::MOTION_AREA)
            qDebug() << __FUNCTION__;
        TreeItem *parentItem = item->parent();

        if (parentItem == m_Root)
            return QModelIndex();
        return createIndex(parentItem->row(), 0, parentItem);
    }
    int rowCount(const QModelIndex &parent) const override
    {
        if (parent.column() > 0)
            return 0;

        TreeItem* item = itemFromIndex(parent);
        return item->childCount();
    }

    int columnCount(const QModelIndex &) const override
    {
        return 1;
    }

private:
    TreeItem *itemFromIndex(const QModelIndex &index) const
    {
        if (index.isValid())
        {
            TreeItem *item = static_cast<TreeItem*>(index.internalPointer());
            return item;
        }
        return m_Root.get();
    }
public:
    QSharedPointer<ProjectContainerData> projectContainer(){
        return m_Root;
    }
private:
    QSharedPointer<ProjectContainerData> m_Root;
};
