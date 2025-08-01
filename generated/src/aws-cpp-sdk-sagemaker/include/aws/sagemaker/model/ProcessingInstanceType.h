﻿/**
 * Copyright Amazon.com, Inc. or its affiliates. All Rights Reserved.
 * SPDX-License-Identifier: Apache-2.0.
 */

#pragma once
#include <aws/sagemaker/SageMaker_EXPORTS.h>
#include <aws/core/utils/memory/stl/AWSString.h>

namespace Aws
{
namespace SageMaker
{
namespace Model
{
  enum class ProcessingInstanceType
  {
    NOT_SET,
    ml_t3_medium,
    ml_t3_large,
    ml_t3_xlarge,
    ml_t3_2xlarge,
    ml_m4_xlarge,
    ml_m4_2xlarge,
    ml_m4_4xlarge,
    ml_m4_10xlarge,
    ml_m4_16xlarge,
    ml_c4_xlarge,
    ml_c4_2xlarge,
    ml_c4_4xlarge,
    ml_c4_8xlarge,
    ml_p2_xlarge,
    ml_p2_8xlarge,
    ml_p2_16xlarge,
    ml_p3_2xlarge,
    ml_p3_8xlarge,
    ml_p3_16xlarge,
    ml_c5_xlarge,
    ml_c5_2xlarge,
    ml_c5_4xlarge,
    ml_c5_9xlarge,
    ml_c5_18xlarge,
    ml_m5_large,
    ml_m5_xlarge,
    ml_m5_2xlarge,
    ml_m5_4xlarge,
    ml_m5_12xlarge,
    ml_m5_24xlarge,
    ml_r5_large,
    ml_r5_xlarge,
    ml_r5_2xlarge,
    ml_r5_4xlarge,
    ml_r5_8xlarge,
    ml_r5_12xlarge,
    ml_r5_16xlarge,
    ml_r5_24xlarge,
    ml_g4dn_xlarge,
    ml_g4dn_2xlarge,
    ml_g4dn_4xlarge,
    ml_g4dn_8xlarge,
    ml_g4dn_12xlarge,
    ml_g4dn_16xlarge,
    ml_g5_xlarge,
    ml_g5_2xlarge,
    ml_g5_4xlarge,
    ml_g5_8xlarge,
    ml_g5_16xlarge,
    ml_g5_12xlarge,
    ml_g5_24xlarge,
    ml_g5_48xlarge,
    ml_r5d_large,
    ml_r5d_xlarge,
    ml_r5d_2xlarge,
    ml_r5d_4xlarge,
    ml_r5d_8xlarge,
    ml_r5d_12xlarge,
    ml_r5d_16xlarge,
    ml_r5d_24xlarge,
    ml_g6_xlarge,
    ml_g6_2xlarge,
    ml_g6_4xlarge,
    ml_g6_8xlarge,
    ml_g6_12xlarge,
    ml_g6_16xlarge,
    ml_g6_24xlarge,
    ml_g6_48xlarge,
    ml_g6e_xlarge,
    ml_g6e_2xlarge,
    ml_g6e_4xlarge,
    ml_g6e_8xlarge,
    ml_g6e_12xlarge,
    ml_g6e_16xlarge,
    ml_g6e_24xlarge,
    ml_g6e_48xlarge,
    ml_m6i_large,
    ml_m6i_xlarge,
    ml_m6i_2xlarge,
    ml_m6i_4xlarge,
    ml_m6i_8xlarge,
    ml_m6i_12xlarge,
    ml_m6i_16xlarge,
    ml_m6i_24xlarge,
    ml_m6i_32xlarge,
    ml_c6i_xlarge,
    ml_c6i_2xlarge,
    ml_c6i_4xlarge,
    ml_c6i_8xlarge,
    ml_c6i_12xlarge,
    ml_c6i_16xlarge,
    ml_c6i_24xlarge,
    ml_c6i_32xlarge,
    ml_m7i_large,
    ml_m7i_xlarge,
    ml_m7i_2xlarge,
    ml_m7i_4xlarge,
    ml_m7i_8xlarge,
    ml_m7i_12xlarge,
    ml_m7i_16xlarge,
    ml_m7i_24xlarge,
    ml_m7i_48xlarge,
    ml_c7i_large,
    ml_c7i_xlarge,
    ml_c7i_2xlarge,
    ml_c7i_4xlarge,
    ml_c7i_8xlarge,
    ml_c7i_12xlarge,
    ml_c7i_16xlarge,
    ml_c7i_24xlarge,
    ml_c7i_48xlarge,
    ml_r7i_large,
    ml_r7i_xlarge,
    ml_r7i_2xlarge,
    ml_r7i_4xlarge,
    ml_r7i_8xlarge,
    ml_r7i_12xlarge,
    ml_r7i_16xlarge,
    ml_r7i_24xlarge,
    ml_r7i_48xlarge
  };

namespace ProcessingInstanceTypeMapper
{
AWS_SAGEMAKER_API ProcessingInstanceType GetProcessingInstanceTypeForName(const Aws::String& name);

AWS_SAGEMAKER_API Aws::String GetNameForProcessingInstanceType(ProcessingInstanceType value);
} // namespace ProcessingInstanceTypeMapper
} // namespace Model
} // namespace SageMaker
} // namespace Aws
