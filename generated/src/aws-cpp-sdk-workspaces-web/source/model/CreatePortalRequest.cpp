﻿/**
 * Copyright Amazon.com, Inc. or its affiliates. All Rights Reserved.
 * SPDX-License-Identifier: Apache-2.0.
 */

#include <aws/workspaces-web/model/CreatePortalRequest.h>
#include <aws/core/utils/json/JsonSerializer.h>

#include <utility>

using namespace Aws::WorkSpacesWeb::Model;
using namespace Aws::Utils::Json;
using namespace Aws::Utils;

Aws::String CreatePortalRequest::SerializePayload() const
{
  JsonValue payload;

  if(m_displayNameHasBeenSet)
  {
   payload.WithString("displayName", m_displayName);

  }

  if(m_tagsHasBeenSet)
  {
   Aws::Utils::Array<JsonValue> tagsJsonList(m_tags.size());
   for(unsigned tagsIndex = 0; tagsIndex < tagsJsonList.GetLength(); ++tagsIndex)
   {
     tagsJsonList[tagsIndex].AsObject(m_tags[tagsIndex].Jsonize());
   }
   payload.WithArray("tags", std::move(tagsJsonList));

  }

  if(m_customerManagedKeyHasBeenSet)
  {
   payload.WithString("customerManagedKey", m_customerManagedKey);

  }

  if(m_additionalEncryptionContextHasBeenSet)
  {
   JsonValue additionalEncryptionContextJsonMap;
   for(auto& additionalEncryptionContextItem : m_additionalEncryptionContext)
   {
     additionalEncryptionContextJsonMap.WithString(additionalEncryptionContextItem.first, additionalEncryptionContextItem.second);
   }
   payload.WithObject("additionalEncryptionContext", std::move(additionalEncryptionContextJsonMap));

  }

  if(m_clientTokenHasBeenSet)
  {
   payload.WithString("clientToken", m_clientToken);

  }

  if(m_authenticationTypeHasBeenSet)
  {
   payload.WithString("authenticationType", AuthenticationTypeMapper::GetNameForAuthenticationType(m_authenticationType));
  }

  if(m_instanceTypeHasBeenSet)
  {
   payload.WithString("instanceType", InstanceTypeMapper::GetNameForInstanceType(m_instanceType));
  }

  if(m_maxConcurrentSessionsHasBeenSet)
  {
   payload.WithInteger("maxConcurrentSessions", m_maxConcurrentSessions);

  }

  return payload.View().WriteReadable();
}




