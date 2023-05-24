#pragma once

#include <QList>
#include <QSharedPointer>

#include "TreeItem.h"

#include "IncentiveData.h"

class IncentiveContainerData : public TreeItem
{
public:
    explicit IncentiveContainerData(const QString &itemName = "激励", DataType dataType = INCENTIVE_CONTAINER)
        : TreeItem(itemName, dataType)
    {
    }

    void addNode() override {
        removeChildAll();

        foreach(auto item, m_Incentive)
            appendChild(item);
    }

    void addItem(TreeItem::DataType ) override
    {
        QSharedPointer<IncentiveData> item(new IncentiveData());
        item->setItemName(QString("激励%1").arg(QString::number(++IncentiveNum)));
        m_Incentive.append(item);
        appendChild(item);
    }
    void removeItem(TreeItem::DataType) override
    {
        removeChildLast();
        if(m_Incentive.count() > 0)
            m_Incentive.removeLast();
        addNode();
    }
public:
    QList<QSharedPointer<IncentiveData>> incentive() const {
        return m_Incentive;
    }
    void setIncentive(const QList<QSharedPointer<IncentiveData>> &Incentive){
        m_Incentive = Incentive;
        //addNode();
    }

private:
    QList<QSharedPointer<IncentiveData>> m_Incentive;//激励
private:
    int IncentiveNum = 0;
};
