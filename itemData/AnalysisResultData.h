#pragma once

#include "TreeItem.h"

#include "FieldDiagramData.h"
#include "GraphData.h"

class AnalysisResultData : public TreeItem
{
public:
    explicit AnalysisResultData(const QString &itemName = "分析结果", DataType dataType = WINDING)
        : TreeItem(itemName, dataType)
        , m_FieldDiagram(new FieldDiagramData())
        , m_Graph(new GraphData())
    {
    }

public:
    void addNode() override {
        removeChildAll();

        appendChild(m_FieldDiagram);
        appendChild(m_Graph);
    }
public:
    QSharedPointer<FieldDiagramData> fieldDiagram() const
    {
        return m_FieldDiagram;
    }
    QSharedPointer<GraphData> graph() const
    {
        return m_Graph;
    }
public:
    void setFieldDiagram(const QSharedPointer<FieldDiagramData> &FieldDiagram){
        m_FieldDiagram = FieldDiagram;
        //addNode()
    }
    void setGraph(const QSharedPointer<GraphData> &Graph){
        m_Graph = Graph;
        //addNode()
    }

private:
    QSharedPointer<FieldDiagramData> m_FieldDiagram; // 场图
    QSharedPointer<GraphData> m_Graph;               // 曲线图
};
