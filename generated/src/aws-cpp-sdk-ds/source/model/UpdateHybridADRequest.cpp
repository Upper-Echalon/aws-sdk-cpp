﻿/**
 * Copyright Amazon.com, Inc. or its affiliates. All Rights Reserved.
 * SPDX-License-Identifier: Apache-2.0.
 */

#include <aws/ds/model/UpdateHybridADRequest.h>
#include <aws/core/utils/json/JsonSerializer.h>

#include <utility>

using namespace Aws::DirectoryService::Model;
using namespace Aws::Utils::Json;
using namespace Aws::Utils;

Aws::String UpdateHybridADRequest::SerializePayload() const
{
  JsonValue payload;

  if(m_directoryIdHasBeenSet)
  {
   payload.WithString("DirectoryId", m_directoryId);

  }

  if(m_hybridAdministratorAccountUpdateHasBeenSet)
  {
   payload.WithObject("HybridAdministratorAccountUpdate", m_hybridAdministratorAccountUpdate.Jsonize());

  }

  if(m_selfManagedInstancesSettingsHasBeenSet)
  {
   payload.WithObject("SelfManagedInstancesSettings", m_selfManagedInstancesSettings.Jsonize());

  }

  return payload.View().WriteReadable();
}

Aws::Http::HeaderValueCollection UpdateHybridADRequest::GetRequestSpecificHeaders() const
{
  Aws::Http::HeaderValueCollection headers;
  headers.insert(Aws::Http::HeaderValuePair("X-Amz-Target", "DirectoryService_20150416.UpdateHybridAD"));
  return headers;

}




