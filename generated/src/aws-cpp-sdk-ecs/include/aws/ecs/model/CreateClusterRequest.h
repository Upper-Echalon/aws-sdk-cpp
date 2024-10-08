﻿/**
 * Copyright Amazon.com, Inc. or its affiliates. All Rights Reserved.
 * SPDX-License-Identifier: Apache-2.0.
 */

#pragma once
#include <aws/ecs/ECS_EXPORTS.h>
#include <aws/ecs/ECSRequest.h>
#include <aws/core/utils/memory/stl/AWSString.h>
#include <aws/core/utils/memory/stl/AWSVector.h>
#include <aws/ecs/model/ClusterConfiguration.h>
#include <aws/ecs/model/ClusterServiceConnectDefaultsRequest.h>
#include <aws/ecs/model/Tag.h>
#include <aws/ecs/model/ClusterSetting.h>
#include <aws/ecs/model/CapacityProviderStrategyItem.h>
#include <utility>

namespace Aws
{
namespace ECS
{
namespace Model
{

  /**
   */
  class CreateClusterRequest : public ECSRequest
  {
  public:
    AWS_ECS_API CreateClusterRequest();

    // Service request name is the Operation name which will send this request out,
    // each operation should has unique request name, so that we can get operation's name from this request.
    // Note: this is not true for response, multiple operations may have the same response name,
    // so we can not get operation's name from response.
    inline virtual const char* GetServiceRequestName() const override { return "CreateCluster"; }

    AWS_ECS_API Aws::String SerializePayload() const override;

    AWS_ECS_API Aws::Http::HeaderValueCollection GetRequestSpecificHeaders() const override;


    ///@{
    /**
     * <p>The name of your cluster. If you don't specify a name for your cluster, you
     * create a cluster that's named <code>default</code>. Up to 255 letters (uppercase
     * and lowercase), numbers, underscores, and hyphens are allowed. </p>
     */
    inline const Aws::String& GetClusterName() const{ return m_clusterName; }
    inline bool ClusterNameHasBeenSet() const { return m_clusterNameHasBeenSet; }
    inline void SetClusterName(const Aws::String& value) { m_clusterNameHasBeenSet = true; m_clusterName = value; }
    inline void SetClusterName(Aws::String&& value) { m_clusterNameHasBeenSet = true; m_clusterName = std::move(value); }
    inline void SetClusterName(const char* value) { m_clusterNameHasBeenSet = true; m_clusterName.assign(value); }
    inline CreateClusterRequest& WithClusterName(const Aws::String& value) { SetClusterName(value); return *this;}
    inline CreateClusterRequest& WithClusterName(Aws::String&& value) { SetClusterName(std::move(value)); return *this;}
    inline CreateClusterRequest& WithClusterName(const char* value) { SetClusterName(value); return *this;}
    ///@}

    ///@{
    /**
     * <p>The metadata that you apply to the cluster to help you categorize and
     * organize them. Each tag consists of a key and an optional value. You define
     * both.</p> <p>The following basic restrictions apply to tags:</p> <ul> <li>
     * <p>Maximum number of tags per resource - 50</p> </li> <li> <p>For each resource,
     * each tag key must be unique, and each tag key can have only one value.</p> </li>
     * <li> <p>Maximum key length - 128 Unicode characters in UTF-8</p> </li> <li>
     * <p>Maximum value length - 256 Unicode characters in UTF-8</p> </li> <li> <p>If
     * your tagging schema is used across multiple services and resources, remember
     * that other services may have restrictions on allowed characters. Generally
     * allowed characters are: letters, numbers, and spaces representable in UTF-8, and
     * the following characters: + - = . _ : / @.</p> </li> <li> <p>Tag keys and values
     * are case-sensitive.</p> </li> <li> <p>Do not use <code>aws:</code>,
     * <code>AWS:</code>, or any upper or lowercase combination of such as a prefix for
     * either keys or values as it is reserved for Amazon Web Services use. You cannot
     * edit or delete tag keys or values with this prefix. Tags with this prefix do not
     * count against your tags per resource limit.</p> </li> </ul>
     */
    inline const Aws::Vector<Tag>& GetTags() const{ return m_tags; }
    inline bool TagsHasBeenSet() const { return m_tagsHasBeenSet; }
    inline void SetTags(const Aws::Vector<Tag>& value) { m_tagsHasBeenSet = true; m_tags = value; }
    inline void SetTags(Aws::Vector<Tag>&& value) { m_tagsHasBeenSet = true; m_tags = std::move(value); }
    inline CreateClusterRequest& WithTags(const Aws::Vector<Tag>& value) { SetTags(value); return *this;}
    inline CreateClusterRequest& WithTags(Aws::Vector<Tag>&& value) { SetTags(std::move(value)); return *this;}
    inline CreateClusterRequest& AddTags(const Tag& value) { m_tagsHasBeenSet = true; m_tags.push_back(value); return *this; }
    inline CreateClusterRequest& AddTags(Tag&& value) { m_tagsHasBeenSet = true; m_tags.push_back(std::move(value)); return *this; }
    ///@}

    ///@{
    /**
     * <p>The setting to use when creating a cluster. This parameter is used to turn on
     * CloudWatch Container Insights for a cluster. If this value is specified, it
     * overrides the <code>containerInsights</code> value set with <a
     * href="https://docs.aws.amazon.com/AmazonECS/latest/APIReference/API_PutAccountSetting.html">PutAccountSetting</a>
     * or <a
     * href="https://docs.aws.amazon.com/AmazonECS/latest/APIReference/API_PutAccountSettingDefault.html">PutAccountSettingDefault</a>.</p>
     */
    inline const Aws::Vector<ClusterSetting>& GetSettings() const{ return m_settings; }
    inline bool SettingsHasBeenSet() const { return m_settingsHasBeenSet; }
    inline void SetSettings(const Aws::Vector<ClusterSetting>& value) { m_settingsHasBeenSet = true; m_settings = value; }
    inline void SetSettings(Aws::Vector<ClusterSetting>&& value) { m_settingsHasBeenSet = true; m_settings = std::move(value); }
    inline CreateClusterRequest& WithSettings(const Aws::Vector<ClusterSetting>& value) { SetSettings(value); return *this;}
    inline CreateClusterRequest& WithSettings(Aws::Vector<ClusterSetting>&& value) { SetSettings(std::move(value)); return *this;}
    inline CreateClusterRequest& AddSettings(const ClusterSetting& value) { m_settingsHasBeenSet = true; m_settings.push_back(value); return *this; }
    inline CreateClusterRequest& AddSettings(ClusterSetting&& value) { m_settingsHasBeenSet = true; m_settings.push_back(std::move(value)); return *this; }
    ///@}

    ///@{
    /**
     * <p>The <code>execute</code> command configuration for the cluster.</p>
     */
    inline const ClusterConfiguration& GetConfiguration() const{ return m_configuration; }
    inline bool ConfigurationHasBeenSet() const { return m_configurationHasBeenSet; }
    inline void SetConfiguration(const ClusterConfiguration& value) { m_configurationHasBeenSet = true; m_configuration = value; }
    inline void SetConfiguration(ClusterConfiguration&& value) { m_configurationHasBeenSet = true; m_configuration = std::move(value); }
    inline CreateClusterRequest& WithConfiguration(const ClusterConfiguration& value) { SetConfiguration(value); return *this;}
    inline CreateClusterRequest& WithConfiguration(ClusterConfiguration&& value) { SetConfiguration(std::move(value)); return *this;}
    ///@}

    ///@{
    /**
     * <p>The short name of one or more capacity providers to associate with the
     * cluster. A capacity provider must be associated with a cluster before it can be
     * included as part of the default capacity provider strategy of the cluster or
     * used in a capacity provider strategy when calling the <a
     * href="https://docs.aws.amazon.com/AmazonECS/latest/APIReference/API_CreateService.html">CreateService</a>
     * or <a
     * href="https://docs.aws.amazon.com/AmazonECS/latest/APIReference/API_RunTask.html">RunTask</a>
     * actions.</p> <p>If specifying a capacity provider that uses an Auto Scaling
     * group, the capacity provider must be created but not associated with another
     * cluster. New Auto Scaling group capacity providers can be created with the <a
     * href="https://docs.aws.amazon.com/AmazonECS/latest/APIReference/API_CreateCapacityProvider.html">CreateCapacityProvider</a>
     * API operation.</p> <p>To use a Fargate capacity provider, specify either the
     * <code>FARGATE</code> or <code>FARGATE_SPOT</code> capacity providers. The
     * Fargate capacity providers are available to all accounts and only need to be
     * associated with a cluster to be used.</p> <p>The <a
     * href="https://docs.aws.amazon.com/AmazonECS/latest/APIReference/API_PutCapacityProvider.html">PutCapacityProvider</a>
     * API operation is used to update the list of available capacity providers for a
     * cluster after the cluster is created.</p>
     */
    inline const Aws::Vector<Aws::String>& GetCapacityProviders() const{ return m_capacityProviders; }
    inline bool CapacityProvidersHasBeenSet() const { return m_capacityProvidersHasBeenSet; }
    inline void SetCapacityProviders(const Aws::Vector<Aws::String>& value) { m_capacityProvidersHasBeenSet = true; m_capacityProviders = value; }
    inline void SetCapacityProviders(Aws::Vector<Aws::String>&& value) { m_capacityProvidersHasBeenSet = true; m_capacityProviders = std::move(value); }
    inline CreateClusterRequest& WithCapacityProviders(const Aws::Vector<Aws::String>& value) { SetCapacityProviders(value); return *this;}
    inline CreateClusterRequest& WithCapacityProviders(Aws::Vector<Aws::String>&& value) { SetCapacityProviders(std::move(value)); return *this;}
    inline CreateClusterRequest& AddCapacityProviders(const Aws::String& value) { m_capacityProvidersHasBeenSet = true; m_capacityProviders.push_back(value); return *this; }
    inline CreateClusterRequest& AddCapacityProviders(Aws::String&& value) { m_capacityProvidersHasBeenSet = true; m_capacityProviders.push_back(std::move(value)); return *this; }
    inline CreateClusterRequest& AddCapacityProviders(const char* value) { m_capacityProvidersHasBeenSet = true; m_capacityProviders.push_back(value); return *this; }
    ///@}

    ///@{
    /**
     * <p>The capacity provider strategy to set as the default for the cluster. After a
     * default capacity provider strategy is set for a cluster, when you call the <a
     * href="https://docs.aws.amazon.com/AmazonECS/latest/APIReference/API_CreateService.html">CreateService</a>
     * or <a
     * href="https://docs.aws.amazon.com/AmazonECS/latest/APIReference/API_RunTask.html">RunTask</a>
     * APIs with no capacity provider strategy or launch type specified, the default
     * capacity provider strategy for the cluster is used.</p> <p>If a default capacity
     * provider strategy isn't defined for a cluster when it was created, it can be
     * defined later with the <a
     * href="https://docs.aws.amazon.com/AmazonECS/latest/APIReference/API_PutClusterCapacityProviders.html">PutClusterCapacityProviders</a>
     * API operation.</p>
     */
    inline const Aws::Vector<CapacityProviderStrategyItem>& GetDefaultCapacityProviderStrategy() const{ return m_defaultCapacityProviderStrategy; }
    inline bool DefaultCapacityProviderStrategyHasBeenSet() const { return m_defaultCapacityProviderStrategyHasBeenSet; }
    inline void SetDefaultCapacityProviderStrategy(const Aws::Vector<CapacityProviderStrategyItem>& value) { m_defaultCapacityProviderStrategyHasBeenSet = true; m_defaultCapacityProviderStrategy = value; }
    inline void SetDefaultCapacityProviderStrategy(Aws::Vector<CapacityProviderStrategyItem>&& value) { m_defaultCapacityProviderStrategyHasBeenSet = true; m_defaultCapacityProviderStrategy = std::move(value); }
    inline CreateClusterRequest& WithDefaultCapacityProviderStrategy(const Aws::Vector<CapacityProviderStrategyItem>& value) { SetDefaultCapacityProviderStrategy(value); return *this;}
    inline CreateClusterRequest& WithDefaultCapacityProviderStrategy(Aws::Vector<CapacityProviderStrategyItem>&& value) { SetDefaultCapacityProviderStrategy(std::move(value)); return *this;}
    inline CreateClusterRequest& AddDefaultCapacityProviderStrategy(const CapacityProviderStrategyItem& value) { m_defaultCapacityProviderStrategyHasBeenSet = true; m_defaultCapacityProviderStrategy.push_back(value); return *this; }
    inline CreateClusterRequest& AddDefaultCapacityProviderStrategy(CapacityProviderStrategyItem&& value) { m_defaultCapacityProviderStrategyHasBeenSet = true; m_defaultCapacityProviderStrategy.push_back(std::move(value)); return *this; }
    ///@}

    ///@{
    /**
     * <p>Use this parameter to set a default Service Connect namespace. After you set
     * a default Service Connect namespace, any new services with Service Connect
     * turned on that are created in the cluster are added as client services in the
     * namespace. This setting only applies to new services that set the
     * <code>enabled</code> parameter to <code>true</code> in the
     * <code>ServiceConnectConfiguration</code>. You can set the namespace of each
     * service individually in the <code>ServiceConnectConfiguration</code> to override
     * this default parameter.</p> <p>Tasks that run in a namespace can use short names
     * to connect to services in the namespace. Tasks can connect to services across
     * all of the clusters in the namespace. Tasks connect through a managed proxy
     * container that collects logs and metrics for increased visibility. Only the
     * tasks that Amazon ECS services create are supported with Service Connect. For
     * more information, see <a
     * href="https://docs.aws.amazon.com/AmazonECS/latest/developerguide/service-connect.html">Service
     * Connect</a> in the <i>Amazon Elastic Container Service Developer Guide</i>.</p>
     */
    inline const ClusterServiceConnectDefaultsRequest& GetServiceConnectDefaults() const{ return m_serviceConnectDefaults; }
    inline bool ServiceConnectDefaultsHasBeenSet() const { return m_serviceConnectDefaultsHasBeenSet; }
    inline void SetServiceConnectDefaults(const ClusterServiceConnectDefaultsRequest& value) { m_serviceConnectDefaultsHasBeenSet = true; m_serviceConnectDefaults = value; }
    inline void SetServiceConnectDefaults(ClusterServiceConnectDefaultsRequest&& value) { m_serviceConnectDefaultsHasBeenSet = true; m_serviceConnectDefaults = std::move(value); }
    inline CreateClusterRequest& WithServiceConnectDefaults(const ClusterServiceConnectDefaultsRequest& value) { SetServiceConnectDefaults(value); return *this;}
    inline CreateClusterRequest& WithServiceConnectDefaults(ClusterServiceConnectDefaultsRequest&& value) { SetServiceConnectDefaults(std::move(value)); return *this;}
    ///@}
  private:

    Aws::String m_clusterName;
    bool m_clusterNameHasBeenSet = false;

    Aws::Vector<Tag> m_tags;
    bool m_tagsHasBeenSet = false;

    Aws::Vector<ClusterSetting> m_settings;
    bool m_settingsHasBeenSet = false;

    ClusterConfiguration m_configuration;
    bool m_configurationHasBeenSet = false;

    Aws::Vector<Aws::String> m_capacityProviders;
    bool m_capacityProvidersHasBeenSet = false;

    Aws::Vector<CapacityProviderStrategyItem> m_defaultCapacityProviderStrategy;
    bool m_defaultCapacityProviderStrategyHasBeenSet = false;

    ClusterServiceConnectDefaultsRequest m_serviceConnectDefaults;
    bool m_serviceConnectDefaultsHasBeenSet = false;
  };

} // namespace Model
} // namespace ECS
} // namespace Aws
