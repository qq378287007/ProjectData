#pragma once

#include "TreeItem.h"

#include "VectorBoundaryData.h"
#include "SymmetricBoundaryData.h"

class BoundaryContainerData : public TreeItem
{
public:
    explicit BoundaryContainerData(const QString &itemName = "边界", DataType dataType = BOUNDARY_CONTAINER)
        : TreeItem(itemName, dataType)
    {
    }

    void addNode() override {
        removeChildAll();

        foreach(auto item, m_VectorBoundary)
            appendChild(item);
        foreach(auto item, m_SymmetricBoundary)
            appendChild(item);
    }

    void addItem(TreeItem::DataType dataType) override
    {
        switch (dataType)
        {
        case VECTOR_BOUNDARY:
        {
            QSharedPointer<VectorBoundaryData> item(new VectorBoundaryData());
            item->setItemName(QString("矢量边界%1").arg(QString::number(++VectorBoundaryNum)));
            m_VectorBoundary.append(item);
            appendChild(item);
        }
            break;
        case SYMMETRIC_BOUNDARY:
        {
            QSharedPointer<SymmetricBoundaryData> item(new SymmetricBoundaryData());
            item->setItemName(QString("对称边界%1").arg(QString::number(++SymmetricBoundaryNum)));
            m_SymmetricBoundary.append(item);
            appendChild(item);
        }
            break;
        default:
            break;
        }
    }

    void removeItem(TreeItem::DataType dataType) override
    {
        switch (dataType)
        {
        case VECTOR_BOUNDARY:
        {
            removeChildLast(dataType);
            if(m_VectorBoundary.count() > 0)
                m_VectorBoundary.removeLast();
            addNode();
        }
            break;
        case SYMMETRIC_BOUNDARY:
        {
            removeChildLast(dataType);
            if(m_SymmetricBoundary.count() > 0)
                m_SymmetricBoundary.removeLast();
            addNode();
        }
            break;
        default:
            break;
        }
    }
public:
    QList<QSharedPointer<VectorBoundaryData>> vectorBoundary() const {
        return m_VectorBoundary;
    }
    QList<QSharedPointer<SymmetricBoundaryData>> symmetricBoundary() const {
        return m_SymmetricBoundary;
    }
public:
    void setMotionArea(const QList<QSharedPointer<VectorBoundaryData>> &VectorBoundary){
        m_VectorBoundary = VectorBoundary;
        //addNode();
    }
    void setSymmetricBoundary(const QList<QSharedPointer<SymmetricBoundaryData>> &SymmetricBoundary){
        m_SymmetricBoundary = SymmetricBoundary;
        //addNode();
    }
private:
    QList<QSharedPointer<VectorBoundaryData>> m_VectorBoundary;//矢量边界
    QList<QSharedPointer<SymmetricBoundaryData>> m_SymmetricBoundary;//对称边界
private:
    int VectorBoundaryNum = 0;
    int SymmetricBoundaryNum = 0;
};
