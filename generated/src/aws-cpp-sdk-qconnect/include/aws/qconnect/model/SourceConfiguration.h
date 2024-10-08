﻿/**
 * Copyright Amazon.com, Inc. or its affiliates. All Rights Reserved.
 * SPDX-License-Identifier: Apache-2.0.
 */

#pragma once
#include <aws/qconnect/QConnect_EXPORTS.h>
#include <aws/qconnect/model/AppIntegrationsConfiguration.h>
#include <aws/qconnect/model/ManagedSourceConfiguration.h>
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
namespace QConnect
{
namespace Model
{

  /**
   * <p>Configuration information about the external data source.</p><p><h3>See
   * Also:</h3>   <a
   * href="http://docs.aws.amazon.com/goto/WebAPI/qconnect-2020-10-19/SourceConfiguration">AWS
   * API Reference</a></p>
   */
  class SourceConfiguration
  {
  public:
    AWS_QCONNECT_API SourceConfiguration();
    AWS_QCONNECT_API SourceConfiguration(Aws::Utils::Json::JsonView jsonValue);
    AWS_QCONNECT_API SourceConfiguration& operator=(Aws::Utils::Json::JsonView jsonValue);
    AWS_QCONNECT_API Aws::Utils::Json::JsonValue Jsonize() const;


    ///@{
    /**
     * <p>Configuration information for Amazon AppIntegrations to automatically ingest
     * content.</p>
     */
    inline const AppIntegrationsConfiguration& GetAppIntegrations() const{ return m_appIntegrations; }
    inline bool AppIntegrationsHasBeenSet() const { return m_appIntegrationsHasBeenSet; }
    inline void SetAppIntegrations(const AppIntegrationsConfiguration& value) { m_appIntegrationsHasBeenSet = true; m_appIntegrations = value; }
    inline void SetAppIntegrations(AppIntegrationsConfiguration&& value) { m_appIntegrationsHasBeenSet = true; m_appIntegrations = std::move(value); }
    inline SourceConfiguration& WithAppIntegrations(const AppIntegrationsConfiguration& value) { SetAppIntegrations(value); return *this;}
    inline SourceConfiguration& WithAppIntegrations(AppIntegrationsConfiguration&& value) { SetAppIntegrations(std::move(value)); return *this;}
    ///@}

    ///@{
    /**
     * <p>Source configuration for managed resources.</p>
     */
    inline const ManagedSourceConfiguration& GetManagedSourceConfiguration() const{ return m_managedSourceConfiguration; }
    inline bool ManagedSourceConfigurationHasBeenSet() const { return m_managedSourceConfigurationHasBeenSet; }
    inline void SetManagedSourceConfiguration(const ManagedSourceConfiguration& value) { m_managedSourceConfigurationHasBeenSet = true; m_managedSourceConfiguration = value; }
    inline void SetManagedSourceConfiguration(ManagedSourceConfiguration&& value) { m_managedSourceConfigurationHasBeenSet = true; m_managedSourceConfiguration = std::move(value); }
    inline SourceConfiguration& WithManagedSourceConfiguration(const ManagedSourceConfiguration& value) { SetManagedSourceConfiguration(value); return *this;}
    inline SourceConfiguration& WithManagedSourceConfiguration(ManagedSourceConfiguration&& value) { SetManagedSourceConfiguration(std::move(value)); return *this;}
    ///@}
  private:

    AppIntegrationsConfiguration m_appIntegrations;
    bool m_appIntegrationsHasBeenSet = false;

    ManagedSourceConfiguration m_managedSourceConfiguration;
    bool m_managedSourceConfigurationHasBeenSet = false;
  };

} // namespace Model
} // namespace QConnect
} // namespace Aws
