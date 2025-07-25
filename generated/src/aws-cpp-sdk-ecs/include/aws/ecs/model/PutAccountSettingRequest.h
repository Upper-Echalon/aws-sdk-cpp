﻿/**
 * Copyright Amazon.com, Inc. or its affiliates. All Rights Reserved.
 * SPDX-License-Identifier: Apache-2.0.
 */

#pragma once
#include <aws/ecs/ECS_EXPORTS.h>
#include <aws/ecs/ECSRequest.h>
#include <aws/ecs/model/SettingName.h>
#include <aws/core/utils/memory/stl/AWSString.h>
#include <utility>

namespace Aws
{
namespace ECS
{
namespace Model
{

  /**
   */
  class PutAccountSettingRequest : public ECSRequest
  {
  public:
    AWS_ECS_API PutAccountSettingRequest() = default;

    // Service request name is the Operation name which will send this request out,
    // each operation should has unique request name, so that we can get operation's name from this request.
    // Note: this is not true for response, multiple operations may have the same response name,
    // so we can not get operation's name from response.
    inline virtual const char* GetServiceRequestName() const override { return "PutAccountSetting"; }

    AWS_ECS_API Aws::String SerializePayload() const override;

    AWS_ECS_API Aws::Http::HeaderValueCollection GetRequestSpecificHeaders() const override;


    ///@{
    /**
     * <p>The Amazon ECS account setting name to modify.</p> <p>The following are the
     * valid values for the account setting name.</p> <ul> <li> <p>
     * <code>serviceLongArnFormat</code> - When modified, the Amazon Resource Name
     * (ARN) and resource ID format of the resource type for a specified user, role, or
     * the root user for an account is affected. The opt-in and opt-out account setting
     * must be set for each Amazon ECS resource separately. The ARN and resource ID
     * format of a resource is defined by the opt-in status of the user or role that
     * created the resource. You must turn on this setting to use Amazon ECS features
     * such as resource tagging.</p> </li> <li> <p> <code>taskLongArnFormat</code> -
     * When modified, the Amazon Resource Name (ARN) and resource ID format of the
     * resource type for a specified user, role, or the root user for an account is
     * affected. The opt-in and opt-out account setting must be set for each Amazon ECS
     * resource separately. The ARN and resource ID format of a resource is defined by
     * the opt-in status of the user or role that created the resource. You must turn
     * on this setting to use Amazon ECS features such as resource tagging.</p> </li>
     * <li> <p> <code>containerInstanceLongArnFormat</code> - When modified, the Amazon
     * Resource Name (ARN) and resource ID format of the resource type for a specified
     * user, role, or the root user for an account is affected. The opt-in and opt-out
     * account setting must be set for each Amazon ECS resource separately. The ARN and
     * resource ID format of a resource is defined by the opt-in status of the user or
     * role that created the resource. You must turn on this setting to use Amazon ECS
     * features such as resource tagging.</p> </li> <li> <p>
     * <code>awsvpcTrunking</code> - When modified, the elastic network interface (ENI)
     * limit for any new container instances that support the feature is changed. If
     * <code>awsvpcTrunking</code> is turned on, any new container instances that
     * support the feature are launched have the increased ENI limits available to
     * them. For more information, see <a
     * href="https://docs.aws.amazon.com/AmazonECS/latest/developerguide/container-instance-eni.html">Elastic
     * Network Interface Trunking</a> in the <i>Amazon Elastic Container Service
     * Developer Guide</i>.</p> </li> <li> <p> <code>containerInsights</code> -
     * Container Insights with enhanced observability provides all the Container
     * Insights metrics, plus additional task and container metrics. This version
     * supports enhanced observability for Amazon ECS clusters using the Amazon EC2 and
     * Fargate launch types. After you configure Container Insights with enhanced
     * observability on Amazon ECS, Container Insights auto-collects detailed
     * infrastructure telemetry from the cluster level down to the container level in
     * your environment and displays these critical performance data in curated
     * dashboards removing the heavy lifting in observability set-up. </p> <p>To use
     * Container Insights with enhanced observability, set the
     * <code>containerInsights</code> account setting to <code>enhanced</code>.</p>
     * <p>To use Container Insights, set the <code>containerInsights</code> account
     * setting to <code>enabled</code>.</p> <p>For more information, see <a
     * href="https://docs.aws.amazon.com/AmazonECS/latest/developerguide/cloudwatch-container-insights.html">Monitor
     * Amazon ECS containers using Container Insights with enhanced observability</a>
     * in the <i>Amazon Elastic Container Service Developer Guide</i>.</p> </li> <li>
     * <p> <code>dualStackIPv6</code> - When turned on, when using a VPC in dual stack
     * mode, your tasks using the <code>awsvpc</code> network mode can have an IPv6
     * address assigned. For more information on using IPv6 with tasks launched on
     * Amazon EC2 instances, see <a
     * href="https://docs.aws.amazon.com/AmazonECS/latest/developerguide/task-networking-awsvpc.html#task-networking-vpc-dual-stack">Using
     * a VPC in dual-stack mode</a>. For more information on using IPv6 with tasks
     * launched on Fargate, see <a
     * href="https://docs.aws.amazon.com/AmazonECS/latest/developerguide/fargate-task-networking.html#fargate-task-networking-vpc-dual-stack">Using
     * a VPC in dual-stack mode</a>.</p> </li> <li> <p>
     * <code>fargateTaskRetirementWaitPeriod</code> - When Amazon Web Services
     * determines that a security or infrastructure update is needed for an Amazon ECS
     * task hosted on Fargate, the tasks need to be stopped and new tasks launched to
     * replace them. Use <code>fargateTaskRetirementWaitPeriod</code> to configure the
     * wait time to retire a Fargate task. For information about the Fargate tasks
     * maintenance, see <a
     * href="https://docs.aws.amazon.com/AmazonECS/latest/developerguide/task-maintenance.html">Amazon
     * Web Services Fargate task maintenance</a> in the <i>Amazon ECS Developer
     * Guide</i>.</p> </li> <li> <p> <code>tagResourceAuthorization</code> - Amazon ECS
     * is introducing tagging authorization for resource creation. Users must have
     * permissions for actions that create the resource, such as
     * <code>ecsCreateCluster</code>. If tags are specified when you create a resource,
     * Amazon Web Services performs additional authorization to verify if users or
     * roles have permissions to create tags. Therefore, you must grant explicit
     * permissions to use the <code>ecs:TagResource</code> action. For more
     * information, see <a
     * href="https://docs.aws.amazon.com/AmazonECS/latest/developerguide/supported-iam-actions-tagging.html">Grant
     * permission to tag resources on creation</a> in the <i>Amazon ECS Developer
     * Guide</i>.</p> </li> <li> <p> <code>defaultLogDriverMode</code> - Amazon ECS
     * supports setting a default delivery mode of log messages from a container to the
     * <code>logDriver</code> that you specify in the container's
     * <code>logConfiguration</code>. The delivery mode affects application stability
     * when the flow of logs from the container to the log driver is interrupted. The
     * <code>defaultLogDriverMode</code> setting supports two values:
     * <code>blocking</code> and <code>non-blocking</code>. If you don't specify a
     * delivery mode in your container definition's <code>logConfiguration</code>, the
     * mode you specify using this account setting will be used as the default. For
     * more information about log delivery modes, see <a
     * href="https://docs.aws.amazon.com/AmazonECS/latest/APIReference/API_LogConfiguration.html">LogConfiguration</a>.
     * </p>  <p>On June 25, 2025, Amazon ECS changed the default log driver mode
     * from <code>blocking</code> to <code>non-blocking</code> to prioritize task
     * availability over logging. To continue using the <code>blocking</code> mode
     * after this change, do one of the following:</p> <ul> <li> <p>Set the
     * <code>mode</code> option in your container definition's
     * <code>logConfiguration</code> as <code>blocking</code>.</p> </li> <li> <p>Set
     * the <code>defaultLogDriverMode</code> account setting to
     * <code>blocking</code>.</p> </li> </ul>  </li> <li> <p>
     * <code>guardDutyActivate</code> - The <code>guardDutyActivate</code> parameter is
     * read-only in Amazon ECS and indicates whether Amazon ECS Runtime Monitoring is
     * enabled or disabled by your security administrator in your Amazon ECS account.
     * Amazon GuardDuty controls this account setting on your behalf. For more
     * information, see <a
     * href="https://docs.aws.amazon.com/AmazonECS/latest/developerguide/ecs-guard-duty-integration.html">Protecting
     * Amazon ECS workloads with Amazon ECS Runtime Monitoring</a>.</p> </li> </ul>
     */
    inline SettingName GetName() const { return m_name; }
    inline bool NameHasBeenSet() const { return m_nameHasBeenSet; }
    inline void SetName(SettingName value) { m_nameHasBeenSet = true; m_name = value; }
    inline PutAccountSettingRequest& WithName(SettingName value) { SetName(value); return *this;}
    ///@}

    ///@{
    /**
     * <p>The account setting value for the specified principal ARN. Accepted values
     * are <code>enabled</code>, <code>disabled</code>, <code>enhanced</code>,
     * <code>on</code>, and <code>off</code>.</p> <p>When you specify
     * <code>fargateTaskRetirementWaitPeriod</code> for the <code>name</code>, the
     * following are the valid values:</p> <ul> <li> <p> <code>0</code> - Amazon Web
     * Services sends the notification, and immediately retires the affected tasks.</p>
     * </li> <li> <p> <code>7</code> - Amazon Web Services sends the notification, and
     * waits 7 calendar days to retire the tasks.</p> </li> <li> <p> <code>14</code> -
     * Amazon Web Services sends the notification, and waits 14 calendar days to retire
     * the tasks.</p> </li> </ul>
     */
    inline const Aws::String& GetValue() const { return m_value; }
    inline bool ValueHasBeenSet() const { return m_valueHasBeenSet; }
    template<typename ValueT = Aws::String>
    void SetValue(ValueT&& value) { m_valueHasBeenSet = true; m_value = std::forward<ValueT>(value); }
    template<typename ValueT = Aws::String>
    PutAccountSettingRequest& WithValue(ValueT&& value) { SetValue(std::forward<ValueT>(value)); return *this;}
    ///@}

    ///@{
    /**
     * <p>The ARN of the principal, which can be a user, role, or the root user. If you
     * specify the root user, it modifies the account setting for all users, roles, and
     * the root user of the account unless a user or role explicitly overrides these
     * settings. If this field is omitted, the setting is changed only for the
     * authenticated user.</p> <p>In order to use this parameter, you must be the root
     * user, or the principal.</p>  <p>You must use the root user when you set
     * the Fargate wait time (<code>fargateTaskRetirementWaitPeriod</code>). </p>
     * <p>Federated users assume the account setting of the root user and can't have
     * explicit account settings set for them.</p> 
     */
    inline const Aws::String& GetPrincipalArn() const { return m_principalArn; }
    inline bool PrincipalArnHasBeenSet() const { return m_principalArnHasBeenSet; }
    template<typename PrincipalArnT = Aws::String>
    void SetPrincipalArn(PrincipalArnT&& value) { m_principalArnHasBeenSet = true; m_principalArn = std::forward<PrincipalArnT>(value); }
    template<typename PrincipalArnT = Aws::String>
    PutAccountSettingRequest& WithPrincipalArn(PrincipalArnT&& value) { SetPrincipalArn(std::forward<PrincipalArnT>(value)); return *this;}
    ///@}
  private:

    SettingName m_name{SettingName::NOT_SET};
    bool m_nameHasBeenSet = false;

    Aws::String m_value;
    bool m_valueHasBeenSet = false;

    Aws::String m_principalArn;
    bool m_principalArnHasBeenSet = false;
  };

} // namespace Model
} // namespace ECS
} // namespace Aws
