#pragma once

#include "TreeItem.h"

#include "ParametricSettingsData.h"
#include "ParameterizedResultsData.h"

class ParametricData : public TreeItem
{
public:
    explicit ParametricData(const QString &itemName = "参数化", DataType dataType = PARAMETRIC)
        : TreeItem(itemName, dataType)
        , m_ParametricSettings(new ParametricSettingsData())
        , m_ParameterizedResults(new ParameterizedResultsData())
    {
    }
public:
    void addNode() override {
        removeChildAll();

        appendChild(m_ParametricSettings);
        appendChild(m_ParameterizedResults);
    }
public:
    QSharedPointer<ParametricSettingsData> parametricSettings() const {
        return m_ParametricSettings;
    }
    QSharedPointer<ParameterizedResultsData> parameterizedResults() const {
        return m_ParameterizedResults;
    }
public:
    void setParametricSettings(const QSharedPointer<ParametricSettingsData> &ParametricSettings){
        m_ParametricSettings = ParametricSettings;
        //addNode();
    }
    void setParameterizedResult(const QSharedPointer<ParameterizedResultsData> &ParameterizedResults){
        m_ParameterizedResults = ParameterizedResults;
        //addNode();
    }
private:
    QSharedPointer<ParametricSettingsData> m_ParametricSettings;//参数化设置
    QSharedPointer<ParameterizedResultsData> m_ParameterizedResults;//参数化结果
};
