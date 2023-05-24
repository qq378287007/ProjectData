#pragma once

#include <QList>
#include <QSharedPointer>
#include <QVariant>
#include <QDebug>

class TreeItem
{
public:
    enum DataType
    {
        EMPTY = 0,
        PROJECT_CONTAINER,
        PERMANENT_MAGNET_SYNC_MOTOR_PROJECT,

        STRUCT,
        STATOR_ROTOR,
        WINDING,

        MATERIAL,

        MOTION_AREA_CONTAINER,
        MOTION_AREA,
        BOUNDARY_CONTAINER,
        VECTOR_BOUNDARY,
        SYMMETRIC_BOUNDARY,
        INITIALIZATION,
        ANALYSIS_PLAN,
        SOLVE_SETTINGS,
        INCENTIVE_CONTAINER,
        INCENTIVE,

        ANALYSISRESULT,
        FIELD_DIAGRAM,
        GRAPH,

        PARAMETRIC,
        PARAMETRIC_SETTINGS,
        PARAMETERIZED_RESULTS
    };

    explicit TreeItem(const QString &itemName = "", DataType dataType = EMPTY)
        : m_ItemName(itemName)
        , m_DataType(dataType)
        , m_Parent(nullptr)
        , m_Row(-1)
    {
    }
    ~TreeItem()
    {
         m_Child.clear();
    }

public:
    void buildTree(){
        addNode();
        foreach(auto item, m_Child)
            item->addNode();
    }

    virtual void addNode()
    {
    }

    virtual void addItem(TreeItem::DataType dataType = EMPTY)
    {
    }

    virtual void removeItem(TreeItem::DataType dataType = EMPTY)
    {
    }

public:
    QString itemName() const { return m_ItemName; }
    void setItemName(const QString &nodeName) { m_ItemName = nodeName; }

    DataType dataType() const { return m_DataType; }
    void setDataType(DataType type) { m_DataType = type; }

    TreeItem *parent() const { return m_Parent; }
    void setParent(TreeItem *parent) { m_Parent = parent; }

    int childCount() const { return m_Child.count(); }
    QSharedPointer<TreeItem> childAt(int row) { return m_Child.value(row); }

    QSharedPointer<TreeItem> appendChild(QSharedPointer<TreeItem> item)
    {
        item->setParent(this);
        item->setRow(m_Child.size());
        m_Child.append(item);
        return item;
    }

    void removeChildAll(){
        m_Child.clear();
    }

    void removeChildAt(int i)
    {
        if (i >= 0 && i < childCount())
        {
            m_Child.removeAt(i);
            for (int j = 0; j < childCount(); j++)
                m_Child.at(j)->setRow(j);
        }
    }

    void removeChildLast()
    {
        if (childCount() > 0)
            m_Child.removeLast();
    }

    void removeChildLast(DataType dataType)
    {
        for (int i = childCount() - 1; i >= 0; i--)
        {
            if (m_Child.at(i)->dataType() == dataType)
            {
                removeChildAt(i);
                return;
            }
        }
    }

    int row() const { return m_Row; }
    void setRow(int row) { m_Row = row; }

    QVariant data(int role = Qt::DisplayRole) const
    {
        switch (role)
        {
        case Qt::DisplayRole:
            return m_ItemName;
        default:
            return QVariant();
        }
    }

private:
    QString m_ItemName;
    DataType m_DataType;

    TreeItem *m_Parent;
    QList<QSharedPointer<TreeItem>> m_Child;
    int m_Row;
};
