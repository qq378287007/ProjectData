#pragma once

#include <QList>
#include <QSharedPointer>

#include "TreeItem.h"
#include "PermanentMagnetSyncMotorProjectData.h"

class ProjectContainerData : public TreeItem
{
public:
    explicit ProjectContainerData(const QString &itemName = "", DataType dataType = PROJECT_CONTAINER)
        : TreeItem(itemName, dataType)
    {
    }

    void addProject(TreeItem::DataType dataType)
    {
        switch (dataType)
        {
        case TreeItem::PERMANENT_MAGNET_SYNC_MOTOR_PROJECT:
        {
            m_ProjectId = childCount();

            QSharedPointer<TreeItem> item(new PermanentMagnetSyncMotorProjectData());
            item->setItemName(QString("新建工程%1").arg(QString::number(++ProjectNum)));
            item->buildTree();
            appendChild(item);
        }
            break;
        default:
            break;
        }
    }
    void removeProject()
    {
        if (m_ProjectId >= 0)
            removeChildAt(m_ProjectId);
        m_ProjectId = -1;
    }

public:
    int projectId() const
    {
        return m_ProjectId;
    }
    void setProjectId(int projectId)
    {
        m_ProjectId = projectId;
    }

private:
    int m_ProjectId = -1;
private:
    int ProjectNum = 0;
};
