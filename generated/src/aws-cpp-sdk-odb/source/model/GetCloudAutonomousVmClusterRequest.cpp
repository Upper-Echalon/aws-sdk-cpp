﻿/**
 * Copyright Amazon.com, Inc. or its affiliates. All Rights Reserved.
 * SPDX-License-Identifier: Apache-2.0.
 */

#include <aws/odb/model/GetCloudAutonomousVmClusterRequest.h>
#include <aws/core/utils/json/JsonSerializer.h>

#include <utility>

using namespace Aws::odb::Model;
using namespace Aws::Utils::Json;
using namespace Aws::Utils;

Aws::String GetCloudAutonomousVmClusterRequest::SerializePayload() const
{
  JsonValue payload;

  if(m_cloudAutonomousVmClusterIdHasBeenSet)
  {
   payload.WithString("cloudAutonomousVmClusterId", m_cloudAutonomousVmClusterId);

  }

  return payload.View().WriteReadable();
}

Aws::Http::HeaderValueCollection GetCloudAutonomousVmClusterRequest::GetRequestSpecificHeaders() const
{
  Aws::Http::HeaderValueCollection headers;
  headers.insert(Aws::Http::HeaderValuePair("X-Amz-Target", "Odb.GetCloudAutonomousVmCluster"));
  return headers;

}




