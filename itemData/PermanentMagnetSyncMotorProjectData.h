#pragma once

#include <QSharedPointer>
#include <QList>

#include "TreeItem.h"

#include "StructureData.h"
#include "MaterialData.h"
#include "InitializationData.h"
#include "AnalysisPlanData.h"

class PermanentMagnetSyncMotorProjectData : public TreeItem
{
public:
    explicit PermanentMagnetSyncMotorProjectData(const QString &itemName = "", DataType dataType = PERMANENT_MAGNET_SYNC_MOTOR_PROJECT)
        : TreeItem(itemName, dataType)
        , m_Structure(new StructureData())
        , m_Material(new MaterialData())
        , m_Initialization(new InitializationData())
    {
    }
public:
    void addNode() override {
        removeChildAll();

        appendChild(m_Structure);
        appendChild(m_Material);
        appendChild(m_Initialization);

        foreach(auto item, m_AnalysisPlan){
            appendChild(item);
        }
    }

    void addItem(TreeItem::DataType) override
    {
        QSharedPointer<AnalysisPlanData> item(new AnalysisPlanData());
        item->setItemName(QString("分析方案%1").arg(QString::number(++AnalysisPlanNum)));
        item->buildTree();
        m_AnalysisPlan.append(item);
        appendChild(item);
    }

    void removeItem(TreeItem::DataType dataType = TreeItem::ANALYSIS_PLAN) override
    {
        removeChildLast(dataType);
        if(m_AnalysisPlan.count() > 0)
            m_AnalysisPlan.removeLast();
//        addNode();
    }

public:
    QSharedPointer<StructureData> structure() const {
        return m_Structure;
    }
    QSharedPointer<MaterialData> material() const {
        return m_Material;
    }
    QSharedPointer<InitializationData> initialization() const {
        return m_Initialization;
    }
    QList<QSharedPointer<AnalysisPlanData>> analysisPlan() const {
        return m_AnalysisPlan;
    }

public:
    void setStructure(const QSharedPointer<StructureData> &Structure){
        m_Structure = Structure;
        //addNode();
    }
    void setMaterial(const QSharedPointer<MaterialData> &Material){
        m_Material = Material;
        //addNode();
    }
    void setMaterial(const QSharedPointer<InitializationData> &Initialization) {
        m_Initialization = Initialization;
        //addNode();
    }

    void setAnalysisPlan(const QList<QSharedPointer<AnalysisPlanData>> &AnalysisPlan) {
        m_AnalysisPlan = AnalysisPlan;
        //addNode();
    }

private:
    QSharedPointer<StructureData> m_Structure;//结构建模
    QSharedPointer<MaterialData> m_Material;//材料
    QSharedPointer<InitializationData> m_Initialization;//初始化
    QList<QSharedPointer<AnalysisPlanData>> m_AnalysisPlan;//分析方案

private:
    int AnalysisPlanNum = 0;
};
