﻿/**
 * Copyright Amazon.com, Inc. or its affiliates. All Rights Reserved.
 * SPDX-License-Identifier: Apache-2.0.
 */

#include <aws/batch/model/DeleteServiceEnvironmentRequest.h>
#include <aws/core/utils/json/JsonSerializer.h>

#include <utility>

using namespace Aws::Batch::Model;
using namespace Aws::Utils::Json;
using namespace Aws::Utils;

Aws::String DeleteServiceEnvironmentRequest::SerializePayload() const
{
  JsonValue payload;

  if(m_serviceEnvironmentHasBeenSet)
  {
   payload.WithString("serviceEnvironment", m_serviceEnvironment);

  }

  return payload.View().WriteReadable();
}




