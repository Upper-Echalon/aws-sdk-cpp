﻿/**
 * Copyright Amazon.com, Inc. or its affiliates. All Rights Reserved.
 * SPDX-License-Identifier: Apache-2.0.
 */

#pragma once
#include <aws/backup/Backup_EXPORTS.h>
#include <aws/backup/BackupRequest.h>
#include <aws/core/utils/memory/stl/AWSString.h>
#include <aws/backup/model/BackupPlanInput.h>
#include <utility>

namespace Aws
{
namespace Backup
{
namespace Model
{

  /**
   */
  class UpdateBackupPlanRequest : public BackupRequest
  {
  public:
    AWS_BACKUP_API UpdateBackupPlanRequest();

    // Service request name is the Operation name which will send this request out,
    // each operation should has unique request name, so that we can get operation's name from this request.
    // Note: this is not true for response, multiple operations may have the same response name,
    // so we can not get operation's name from response.
    inline virtual const char* GetServiceRequestName() const override { return "UpdateBackupPlan"; }

    AWS_BACKUP_API Aws::String SerializePayload() const override;


    ///@{
    /**
     * <p>The ID of the backup plan.</p>
     */
    inline const Aws::String& GetBackupPlanId() const{ return m_backupPlanId; }
    inline bool BackupPlanIdHasBeenSet() const { return m_backupPlanIdHasBeenSet; }
    inline void SetBackupPlanId(const Aws::String& value) { m_backupPlanIdHasBeenSet = true; m_backupPlanId = value; }
    inline void SetBackupPlanId(Aws::String&& value) { m_backupPlanIdHasBeenSet = true; m_backupPlanId = std::move(value); }
    inline void SetBackupPlanId(const char* value) { m_backupPlanIdHasBeenSet = true; m_backupPlanId.assign(value); }
    inline UpdateBackupPlanRequest& WithBackupPlanId(const Aws::String& value) { SetBackupPlanId(value); return *this;}
    inline UpdateBackupPlanRequest& WithBackupPlanId(Aws::String&& value) { SetBackupPlanId(std::move(value)); return *this;}
    inline UpdateBackupPlanRequest& WithBackupPlanId(const char* value) { SetBackupPlanId(value); return *this;}
    ///@}

    ///@{
    /**
     * <p>The body of a backup plan. Includes a <code>BackupPlanName</code> and one or
     * more sets of <code>Rules</code>.</p>
     */
    inline const BackupPlanInput& GetBackupPlan() const{ return m_backupPlan; }
    inline bool BackupPlanHasBeenSet() const { return m_backupPlanHasBeenSet; }
    inline void SetBackupPlan(const BackupPlanInput& value) { m_backupPlanHasBeenSet = true; m_backupPlan = value; }
    inline void SetBackupPlan(BackupPlanInput&& value) { m_backupPlanHasBeenSet = true; m_backupPlan = std::move(value); }
    inline UpdateBackupPlanRequest& WithBackupPlan(const BackupPlanInput& value) { SetBackupPlan(value); return *this;}
    inline UpdateBackupPlanRequest& WithBackupPlan(BackupPlanInput&& value) { SetBackupPlan(std::move(value)); return *this;}
    ///@}
  private:

    Aws::String m_backupPlanId;
    bool m_backupPlanIdHasBeenSet = false;

    BackupPlanInput m_backupPlan;
    bool m_backupPlanHasBeenSet = false;
  };

} // namespace Model
} // namespace Backup
} // namespace Aws
