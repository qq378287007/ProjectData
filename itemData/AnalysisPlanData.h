#pragma once

#include <QList>
#include <QSharedPointer>

#include "TreeItem.h"

#include "SolveSettingsData.h"
#include "IncentiveContainerData.h"
#include "AnalysisResultData.h"
#include "ParametricData.h"

class AnalysisPlanData: public TreeItem
{
public:
    explicit AnalysisPlanData(const QString &itemName = "", DataType dataType = ANALYSIS_PLAN)
        : TreeItem(itemName, dataType)
        , m_SolveSettings(new SolveSettingsData())
        , m_IncentiveContainer(new IncentiveContainerData())
        , m_AnalysisResult(new AnalysisResultData())
        , m_Parametric(new ParametricData())
    {
    }

public:
    void addNode() override {
        removeChildAll();

        appendChild(m_SolveSettings);
        appendChild(m_IncentiveContainer);
        appendChild(m_AnalysisResult);
        appendChild(m_Parametric);
    }
private:
    QSharedPointer<SolveSettingsData> m_SolveSettings;//求解设置
    QSharedPointer<IncentiveContainerData> m_IncentiveContainer;//激励父节点
    QSharedPointer<AnalysisResultData> m_AnalysisResult;//分析结果
    QSharedPointer<ParametricData> m_Parametric;//参数化
};
