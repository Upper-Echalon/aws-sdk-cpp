﻿/**
 * Copyright Amazon.com, Inc. or its affiliates. All Rights Reserved.
 * SPDX-License-Identifier: Apache-2.0.
 */

#pragma once
#include <aws/iot/IoT_EXPORTS.h>
#include <aws/core/utils/memory/stl/AWSString.h>

namespace Aws
{
namespace IoT
{
namespace Model
{
  enum class ConfigurationStatus
  {
    NOT_SET,
    HEALTHY,
    UNHEALTHY
  };

namespace ConfigurationStatusMapper
{
AWS_IOT_API ConfigurationStatus GetConfigurationStatusForName(const Aws::String& name);

AWS_IOT_API Aws::String GetNameForConfigurationStatus(ConfigurationStatus value);
} // namespace ConfigurationStatusMapper
} // namespace Model
} // namespace IoT
} // namespace Aws
