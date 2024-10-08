﻿/**
 * Copyright Amazon.com, Inc. or its affiliates. All Rights Reserved.
 * SPDX-License-Identifier: Apache-2.0.
 */

#pragma once
#include <aws/medialive/MediaLive_EXPORTS.h>
#include <aws/core/utils/memory/stl/AWSString.h>

namespace Aws
{
namespace MediaLive
{
namespace Model
{
  enum class ClusterState
  {
    NOT_SET,
    CREATING,
    CREATE_FAILED,
    ACTIVE,
    DELETING,
    DELETE_FAILED,
    DELETED
  };

namespace ClusterStateMapper
{
AWS_MEDIALIVE_API ClusterState GetClusterStateForName(const Aws::String& name);

AWS_MEDIALIVE_API Aws::String GetNameForClusterState(ClusterState value);
} // namespace ClusterStateMapper
} // namespace Model
} // namespace MediaLive
} // namespace Aws
