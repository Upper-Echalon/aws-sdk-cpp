﻿/**
 * Copyright Amazon.com, Inc. or its affiliates. All Rights Reserved.
 * SPDX-License-Identifier: Apache-2.0.
 */

#pragma once
#include <aws/bedrock/Bedrock_EXPORTS.h>
#include <aws/core/utils/memory/stl/AWSString.h>

namespace Aws
{
namespace Bedrock
{
namespace Model
{
  enum class ModelStatus
  {
    NOT_SET,
    Active,
    Creating,
    Failed
  };

namespace ModelStatusMapper
{
AWS_BEDROCK_API ModelStatus GetModelStatusForName(const Aws::String& name);

AWS_BEDROCK_API Aws::String GetNameForModelStatus(ModelStatus value);
} // namespace ModelStatusMapper
} // namespace Model
} // namespace Bedrock
} // namespace Aws
