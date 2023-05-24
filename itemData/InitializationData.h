#pragma once

#include "TreeItem.h"

#include "MotionAreaContainerData.h"
#include "BoundaryContainerData.h"

class InitializationData : public TreeItem
{
public:
    explicit InitializationData(const QString &itemName = "初始化", DataType dataType = INITIALIZATION)
        : TreeItem(itemName, dataType)
        , m_MotionAreaContainer(new MotionAreaContainerData())
        , m_BoundaryContainer(new BoundaryContainerData())
    {
    }
public:
    void addNode() override {
        removeChildAll();

        appendChild(m_MotionAreaContainer);
        appendChild(m_BoundaryContainer);
    }
public:
    QSharedPointer<MotionAreaContainerData> motionAreaContainer() const{
        return m_MotionAreaContainer;
    }
    QSharedPointer<BoundaryContainerData> boundaryContainer() const{
        return m_BoundaryContainer;
    }

    void setMotionAreaContainer(const QSharedPointer<MotionAreaContainerData> &MotionAreaContainer){
        m_MotionAreaContainer = MotionAreaContainer;
        //addNode();
    }
    void setBoundaryContainer(const QSharedPointer<BoundaryContainerData> &BoundaryContainer){
        m_BoundaryContainer = BoundaryContainer;
        //addNode();
    }
private:
    QSharedPointer<MotionAreaContainerData> m_MotionAreaContainer;//运动区域父节点
    QSharedPointer<BoundaryContainerData> m_BoundaryContainer;//边界父节点
};
