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
  enum class GuardrailContentFiltersTierName
  {
    NOT_SET,
    CLASSIC,
    STANDARD
  };

namespace GuardrailContentFiltersTierNameMapper
{
AWS_BEDROCK_API GuardrailContentFiltersTierName GetGuardrailContentFiltersTierNameForName(const Aws::String& name);

AWS_BEDROCK_API Aws::String GetNameForGuardrailContentFiltersTierName(GuardrailContentFiltersTierName value);
} // namespace GuardrailContentFiltersTierNameMapper
} // namespace Model
} // namespace Bedrock
} // namespace Aws
