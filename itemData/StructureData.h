#pragma once

#include "TreeItem.h"

#include "StatorRotorData.h"
#include "WindingData.h"

class StructureData : public TreeItem
{
public:
    explicit StructureData(const QString &itemName = "结构建模", DataType dataType = STRUCT)
        : TreeItem(itemName, dataType)
        , m_StatorRotor(new StatorRotorData())
        , m_Winding(new WindingData())
    {
    }
public:
    void addNode() override {
        removeChildAll();

        appendChild(m_StatorRotor);
        appendChild(m_Winding);
    }
public:
    QSharedPointer<StatorRotorData> & statorRotor()  {
        return m_StatorRotor;
    }
    QSharedPointer<WindingData> & winding()  {
        return m_Winding;
    }
    void setStatorRotor(const QSharedPointer<StatorRotorData> &StatorRotor){
        m_StatorRotor = StatorRotor;
        //addNode();
    }
    void setWinding(const QSharedPointer<WindingData> &Winding){
        m_Winding = Winding;
        //addNode();
    }
private:
    QSharedPointer<StatorRotorData> m_StatorRotor;//定子和转子
    QSharedPointer<WindingData> m_Winding;//绕组
};
