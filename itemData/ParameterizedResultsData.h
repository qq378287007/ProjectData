#pragma once

#include "TreeItem.h"

class ParameterizedResultsData : public TreeItem
{
public:
    explicit ParameterizedResultsData(const QString &itemName = "参数化结果", DataType dataType = PARAMETERIZED_RESULTS)
        : TreeItem(itemName, dataType)
    {
    }
};
