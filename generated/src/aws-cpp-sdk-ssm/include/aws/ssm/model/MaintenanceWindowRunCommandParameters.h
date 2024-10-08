﻿/**
 * Copyright Amazon.com, Inc. or its affiliates. All Rights Reserved.
 * SPDX-License-Identifier: Apache-2.0.
 */

#pragma once
#include <aws/ssm/SSM_EXPORTS.h>
#include <aws/core/utils/memory/stl/AWSString.h>
#include <aws/ssm/model/CloudWatchOutputConfig.h>
#include <aws/ssm/model/DocumentHashType.h>
#include <aws/ssm/model/NotificationConfig.h>
#include <aws/core/utils/memory/stl/AWSMap.h>
#include <aws/core/utils/memory/stl/AWSVector.h>
#include <utility>

namespace Aws
{
namespace Utils
{
namespace Json
{
  class JsonValue;
  class JsonView;
} // namespace Json
} // namespace Utils
namespace SSM
{
namespace Model
{

  /**
   * <p>The parameters for a <code>RUN_COMMAND</code> task type.</p> <p>For
   * information about specifying and updating task parameters, see
   * <a>RegisterTaskWithMaintenanceWindow</a> and
   * <a>UpdateMaintenanceWindowTask</a>.</p>  <p> <code>LoggingInfo</code> has
   * been deprecated. To specify an Amazon Simple Storage Service (Amazon S3) bucket
   * to contain logs, instead use the <code>OutputS3BucketName</code> and
   * <code>OutputS3KeyPrefix</code> options in the
   * <code>TaskInvocationParameters</code> structure. For information about how
   * Amazon Web Services Systems Manager handles these options for the supported
   * maintenance window task types, see
   * <a>MaintenanceWindowTaskInvocationParameters</a>.</p> <p>
   * <code>TaskParameters</code> has been deprecated. To specify parameters to pass
   * to a task when it runs, instead use the <code>Parameters</code> option in the
   * <code>TaskInvocationParameters</code> structure. For information about how
   * Systems Manager handles these options for the supported maintenance window task
   * types, see <a>MaintenanceWindowTaskInvocationParameters</a>.</p> <p>For
   * <code>RUN_COMMAND</code> tasks, Systems Manager uses specified values for
   * <code>TaskParameters</code> and <code>LoggingInfo</code> only if no values are
   * specified for <code>TaskInvocationParameters</code>. </p> <p><h3>See
   * Also:</h3>   <a
   * href="http://docs.aws.amazon.com/goto/WebAPI/ssm-2014-11-06/MaintenanceWindowRunCommandParameters">AWS
   * API Reference</a></p>
   */
  class MaintenanceWindowRunCommandParameters
  {
  public:
    AWS_SSM_API MaintenanceWindowRunCommandParameters();
    AWS_SSM_API MaintenanceWindowRunCommandParameters(Aws::Utils::Json::JsonView jsonValue);
    AWS_SSM_API MaintenanceWindowRunCommandParameters& operator=(Aws::Utils::Json::JsonView jsonValue);
    AWS_SSM_API Aws::Utils::Json::JsonValue Jsonize() const;


    ///@{
    /**
     * <p>Information about the commands to run.</p>
     */
    inline const Aws::String& GetComment() const{ return m_comment; }
    inline bool CommentHasBeenSet() const { return m_commentHasBeenSet; }
    inline void SetComment(const Aws::String& value) { m_commentHasBeenSet = true; m_comment = value; }
    inline void SetComment(Aws::String&& value) { m_commentHasBeenSet = true; m_comment = std::move(value); }
    inline void SetComment(const char* value) { m_commentHasBeenSet = true; m_comment.assign(value); }
    inline MaintenanceWindowRunCommandParameters& WithComment(const Aws::String& value) { SetComment(value); return *this;}
    inline MaintenanceWindowRunCommandParameters& WithComment(Aws::String&& value) { SetComment(std::move(value)); return *this;}
    inline MaintenanceWindowRunCommandParameters& WithComment(const char* value) { SetComment(value); return *this;}
    ///@}

    ///@{
    
    inline const CloudWatchOutputConfig& GetCloudWatchOutputConfig() const{ return m_cloudWatchOutputConfig; }
    inline bool CloudWatchOutputConfigHasBeenSet() const { return m_cloudWatchOutputConfigHasBeenSet; }
    inline void SetCloudWatchOutputConfig(const CloudWatchOutputConfig& value) { m_cloudWatchOutputConfigHasBeenSet = true; m_cloudWatchOutputConfig = value; }
    inline void SetCloudWatchOutputConfig(CloudWatchOutputConfig&& value) { m_cloudWatchOutputConfigHasBeenSet = true; m_cloudWatchOutputConfig = std::move(value); }
    inline MaintenanceWindowRunCommandParameters& WithCloudWatchOutputConfig(const CloudWatchOutputConfig& value) { SetCloudWatchOutputConfig(value); return *this;}
    inline MaintenanceWindowRunCommandParameters& WithCloudWatchOutputConfig(CloudWatchOutputConfig&& value) { SetCloudWatchOutputConfig(std::move(value)); return *this;}
    ///@}

    ///@{
    /**
     * <p>The SHA-256 or SHA-1 hash created by the system when the document was
     * created. SHA-1 hashes have been deprecated.</p>
     */
    inline const Aws::String& GetDocumentHash() const{ return m_documentHash; }
    inline bool DocumentHashHasBeenSet() const { return m_documentHashHasBeenSet; }
    inline void SetDocumentHash(const Aws::String& value) { m_documentHashHasBeenSet = true; m_documentHash = value; }
    inline void SetDocumentHash(Aws::String&& value) { m_documentHashHasBeenSet = true; m_documentHash = std::move(value); }
    inline void SetDocumentHash(const char* value) { m_documentHashHasBeenSet = true; m_documentHash.assign(value); }
    inline MaintenanceWindowRunCommandParameters& WithDocumentHash(const Aws::String& value) { SetDocumentHash(value); return *this;}
    inline MaintenanceWindowRunCommandParameters& WithDocumentHash(Aws::String&& value) { SetDocumentHash(std::move(value)); return *this;}
    inline MaintenanceWindowRunCommandParameters& WithDocumentHash(const char* value) { SetDocumentHash(value); return *this;}
    ///@}

    ///@{
    /**
     * <p>SHA-256 or SHA-1. SHA-1 hashes have been deprecated.</p>
     */
    inline const DocumentHashType& GetDocumentHashType() const{ return m_documentHashType; }
    inline bool DocumentHashTypeHasBeenSet() const { return m_documentHashTypeHasBeenSet; }
    inline void SetDocumentHashType(const DocumentHashType& value) { m_documentHashTypeHasBeenSet = true; m_documentHashType = value; }
    inline void SetDocumentHashType(DocumentHashType&& value) { m_documentHashTypeHasBeenSet = true; m_documentHashType = std::move(value); }
    inline MaintenanceWindowRunCommandParameters& WithDocumentHashType(const DocumentHashType& value) { SetDocumentHashType(value); return *this;}
    inline MaintenanceWindowRunCommandParameters& WithDocumentHashType(DocumentHashType&& value) { SetDocumentHashType(std::move(value)); return *this;}
    ///@}

    ///@{
    /**
     * <p>The Amazon Web Services Systems Manager document (SSM document) version to
     * use in the request. You can specify <code>$DEFAULT</code>, <code>$LATEST</code>,
     * or a specific version number. If you run commands by using the Amazon Web
     * Services CLI, then you must escape the first two options by using a backslash.
     * If you specify a version number, then you don't need to use the backslash. For
     * example:</p> <p> <code>--document-version "\$DEFAULT"</code> </p> <p>
     * <code>--document-version "\$LATEST"</code> </p> <p> <code>--document-version
     * "3"</code> </p>
     */
    inline const Aws::String& GetDocumentVersion() const{ return m_documentVersion; }
    inline bool DocumentVersionHasBeenSet() const { return m_documentVersionHasBeenSet; }
    inline void SetDocumentVersion(const Aws::String& value) { m_documentVersionHasBeenSet = true; m_documentVersion = value; }
    inline void SetDocumentVersion(Aws::String&& value) { m_documentVersionHasBeenSet = true; m_documentVersion = std::move(value); }
    inline void SetDocumentVersion(const char* value) { m_documentVersionHasBeenSet = true; m_documentVersion.assign(value); }
    inline MaintenanceWindowRunCommandParameters& WithDocumentVersion(const Aws::String& value) { SetDocumentVersion(value); return *this;}
    inline MaintenanceWindowRunCommandParameters& WithDocumentVersion(Aws::String&& value) { SetDocumentVersion(std::move(value)); return *this;}
    inline MaintenanceWindowRunCommandParameters& WithDocumentVersion(const char* value) { SetDocumentVersion(value); return *this;}
    ///@}

    ///@{
    /**
     * <p>Configurations for sending notifications about command status changes on a
     * per-managed node basis.</p>
     */
    inline const NotificationConfig& GetNotificationConfig() const{ return m_notificationConfig; }
    inline bool NotificationConfigHasBeenSet() const { return m_notificationConfigHasBeenSet; }
    inline void SetNotificationConfig(const NotificationConfig& value) { m_notificationConfigHasBeenSet = true; m_notificationConfig = value; }
    inline void SetNotificationConfig(NotificationConfig&& value) { m_notificationConfigHasBeenSet = true; m_notificationConfig = std::move(value); }
    inline MaintenanceWindowRunCommandParameters& WithNotificationConfig(const NotificationConfig& value) { SetNotificationConfig(value); return *this;}
    inline MaintenanceWindowRunCommandParameters& WithNotificationConfig(NotificationConfig&& value) { SetNotificationConfig(std::move(value)); return *this;}
    ///@}

    ///@{
    /**
     * <p>The name of the Amazon Simple Storage Service (Amazon S3) bucket.</p>
     */
    inline const Aws::String& GetOutputS3BucketName() const{ return m_outputS3BucketName; }
    inline bool OutputS3BucketNameHasBeenSet() const { return m_outputS3BucketNameHasBeenSet; }
    inline void SetOutputS3BucketName(const Aws::String& value) { m_outputS3BucketNameHasBeenSet = true; m_outputS3BucketName = value; }
    inline void SetOutputS3BucketName(Aws::String&& value) { m_outputS3BucketNameHasBeenSet = true; m_outputS3BucketName = std::move(value); }
    inline void SetOutputS3BucketName(const char* value) { m_outputS3BucketNameHasBeenSet = true; m_outputS3BucketName.assign(value); }
    inline MaintenanceWindowRunCommandParameters& WithOutputS3BucketName(const Aws::String& value) { SetOutputS3BucketName(value); return *this;}
    inline MaintenanceWindowRunCommandParameters& WithOutputS3BucketName(Aws::String&& value) { SetOutputS3BucketName(std::move(value)); return *this;}
    inline MaintenanceWindowRunCommandParameters& WithOutputS3BucketName(const char* value) { SetOutputS3BucketName(value); return *this;}
    ///@}

    ///@{
    /**
     * <p>The S3 bucket subfolder.</p>
     */
    inline const Aws::String& GetOutputS3KeyPrefix() const{ return m_outputS3KeyPrefix; }
    inline bool OutputS3KeyPrefixHasBeenSet() const { return m_outputS3KeyPrefixHasBeenSet; }
    inline void SetOutputS3KeyPrefix(const Aws::String& value) { m_outputS3KeyPrefixHasBeenSet = true; m_outputS3KeyPrefix = value; }
    inline void SetOutputS3KeyPrefix(Aws::String&& value) { m_outputS3KeyPrefixHasBeenSet = true; m_outputS3KeyPrefix = std::move(value); }
    inline void SetOutputS3KeyPrefix(const char* value) { m_outputS3KeyPrefixHasBeenSet = true; m_outputS3KeyPrefix.assign(value); }
    inline MaintenanceWindowRunCommandParameters& WithOutputS3KeyPrefix(const Aws::String& value) { SetOutputS3KeyPrefix(value); return *this;}
    inline MaintenanceWindowRunCommandParameters& WithOutputS3KeyPrefix(Aws::String&& value) { SetOutputS3KeyPrefix(std::move(value)); return *this;}
    inline MaintenanceWindowRunCommandParameters& WithOutputS3KeyPrefix(const char* value) { SetOutputS3KeyPrefix(value); return *this;}
    ///@}

    ///@{
    /**
     * <p>The parameters for the <code>RUN_COMMAND</code> task execution.</p>
     */
    inline const Aws::Map<Aws::String, Aws::Vector<Aws::String>>& GetParameters() const{ return m_parameters; }
    inline bool ParametersHasBeenSet() const { return m_parametersHasBeenSet; }
    inline void SetParameters(const Aws::Map<Aws::String, Aws::Vector<Aws::String>>& value) { m_parametersHasBeenSet = true; m_parameters = value; }
    inline void SetParameters(Aws::Map<Aws::String, Aws::Vector<Aws::String>>&& value) { m_parametersHasBeenSet = true; m_parameters = std::move(value); }
    inline MaintenanceWindowRunCommandParameters& WithParameters(const Aws::Map<Aws::String, Aws::Vector<Aws::String>>& value) { SetParameters(value); return *this;}
    inline MaintenanceWindowRunCommandParameters& WithParameters(Aws::Map<Aws::String, Aws::Vector<Aws::String>>&& value) { SetParameters(std::move(value)); return *this;}
    inline MaintenanceWindowRunCommandParameters& AddParameters(const Aws::String& key, const Aws::Vector<Aws::String>& value) { m_parametersHasBeenSet = true; m_parameters.emplace(key, value); return *this; }
    inline MaintenanceWindowRunCommandParameters& AddParameters(Aws::String&& key, const Aws::Vector<Aws::String>& value) { m_parametersHasBeenSet = true; m_parameters.emplace(std::move(key), value); return *this; }
    inline MaintenanceWindowRunCommandParameters& AddParameters(const Aws::String& key, Aws::Vector<Aws::String>&& value) { m_parametersHasBeenSet = true; m_parameters.emplace(key, std::move(value)); return *this; }
    inline MaintenanceWindowRunCommandParameters& AddParameters(Aws::String&& key, Aws::Vector<Aws::String>&& value) { m_parametersHasBeenSet = true; m_parameters.emplace(std::move(key), std::move(value)); return *this; }
    inline MaintenanceWindowRunCommandParameters& AddParameters(const char* key, Aws::Vector<Aws::String>&& value) { m_parametersHasBeenSet = true; m_parameters.emplace(key, std::move(value)); return *this; }
    inline MaintenanceWindowRunCommandParameters& AddParameters(const char* key, const Aws::Vector<Aws::String>& value) { m_parametersHasBeenSet = true; m_parameters.emplace(key, value); return *this; }
    ///@}

    ///@{
    /**
     * <p>The Amazon Resource Name (ARN) of the IAM service role for Amazon Web
     * Services Systems Manager to assume when running a maintenance window task. If
     * you do not specify a service role ARN, Systems Manager uses a service-linked
     * role in your account. If no appropriate service-linked role for Systems Manager
     * exists in your account, it is created when you run
     * <code>RegisterTaskWithMaintenanceWindow</code>.</p> <p>However, for an improved
     * security posture, we strongly recommend creating a custom policy and custom
     * service role for running your maintenance window tasks. The policy can be
     * crafted to provide only the permissions needed for your particular maintenance
     * window tasks. For more information, see <a
     * href="https://docs.aws.amazon.com/systems-manager/latest/userguide/sysman-maintenance-permissions.html">Setting
     * up Maintenance Windows</a> in the in the <i>Amazon Web Services Systems Manager
     * User Guide</i>.</p>
     */
    inline const Aws::String& GetServiceRoleArn() const{ return m_serviceRoleArn; }
    inline bool ServiceRoleArnHasBeenSet() const { return m_serviceRoleArnHasBeenSet; }
    inline void SetServiceRoleArn(const Aws::String& value) { m_serviceRoleArnHasBeenSet = true; m_serviceRoleArn = value; }
    inline void SetServiceRoleArn(Aws::String&& value) { m_serviceRoleArnHasBeenSet = true; m_serviceRoleArn = std::move(value); }
    inline void SetServiceRoleArn(const char* value) { m_serviceRoleArnHasBeenSet = true; m_serviceRoleArn.assign(value); }
    inline MaintenanceWindowRunCommandParameters& WithServiceRoleArn(const Aws::String& value) { SetServiceRoleArn(value); return *this;}
    inline MaintenanceWindowRunCommandParameters& WithServiceRoleArn(Aws::String&& value) { SetServiceRoleArn(std::move(value)); return *this;}
    inline MaintenanceWindowRunCommandParameters& WithServiceRoleArn(const char* value) { SetServiceRoleArn(value); return *this;}
    ///@}

    ///@{
    /**
     * <p>If this time is reached and the command hasn't already started running, it
     * doesn't run.</p>
     */
    inline int GetTimeoutSeconds() const{ return m_timeoutSeconds; }
    inline bool TimeoutSecondsHasBeenSet() const { return m_timeoutSecondsHasBeenSet; }
    inline void SetTimeoutSeconds(int value) { m_timeoutSecondsHasBeenSet = true; m_timeoutSeconds = value; }
    inline MaintenanceWindowRunCommandParameters& WithTimeoutSeconds(int value) { SetTimeoutSeconds(value); return *this;}
    ///@}
  private:

    Aws::String m_comment;
    bool m_commentHasBeenSet = false;

    CloudWatchOutputConfig m_cloudWatchOutputConfig;
    bool m_cloudWatchOutputConfigHasBeenSet = false;

    Aws::String m_documentHash;
    bool m_documentHashHasBeenSet = false;

    DocumentHashType m_documentHashType;
    bool m_documentHashTypeHasBeenSet = false;

    Aws::String m_documentVersion;
    bool m_documentVersionHasBeenSet = false;

    NotificationConfig m_notificationConfig;
    bool m_notificationConfigHasBeenSet = false;

    Aws::String m_outputS3BucketName;
    bool m_outputS3BucketNameHasBeenSet = false;

    Aws::String m_outputS3KeyPrefix;
    bool m_outputS3KeyPrefixHasBeenSet = false;

    Aws::Map<Aws::String, Aws::Vector<Aws::String>> m_parameters;
    bool m_parametersHasBeenSet = false;

    Aws::String m_serviceRoleArn;
    bool m_serviceRoleArnHasBeenSet = false;

    int m_timeoutSeconds;
    bool m_timeoutSecondsHasBeenSet = false;
  };

} // namespace Model
} // namespace SSM
} // namespace Aws
