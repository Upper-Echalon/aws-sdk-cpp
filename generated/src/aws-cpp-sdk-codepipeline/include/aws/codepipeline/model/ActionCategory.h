﻿/**
 * Copyright Amazon.com, Inc. or its affiliates. All Rights Reserved.
 * SPDX-License-Identifier: Apache-2.0.
 */

#pragma once
#include <aws/codepipeline/CodePipeline_EXPORTS.h>
#include <aws/core/utils/memory/stl/AWSString.h>

namespace Aws
{
namespace CodePipeline
{
namespace Model
{
  enum class ActionCategory
  {
    NOT_SET,
    Source,
    Build,
    Deploy,
    Test,
    Invoke,
    Approval,
    Compute
  };

namespace ActionCategoryMapper
{
AWS_CODEPIPELINE_API ActionCategory GetActionCategoryForName(const Aws::String& name);

AWS_CODEPIPELINE_API Aws::String GetNameForActionCategory(ActionCategory value);
} // namespace ActionCategoryMapper
} // namespace Model
} // namespace CodePipeline
} // namespace Aws
