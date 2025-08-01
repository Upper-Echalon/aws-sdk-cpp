﻿/**
 * Copyright Amazon.com, Inc. or its affiliates. All Rights Reserved.
 * SPDX-License-Identifier: Apache-2.0.
 */

#include <aws/ds/model/StartADAssessmentRequest.h>
#include <aws/core/utils/json/JsonSerializer.h>

#include <utility>

using namespace Aws::DirectoryService::Model;
using namespace Aws::Utils::Json;
using namespace Aws::Utils;

Aws::String StartADAssessmentRequest::SerializePayload() const
{
  JsonValue payload;

  if(m_assessmentConfigurationHasBeenSet)
  {
   payload.WithObject("AssessmentConfiguration", m_assessmentConfiguration.Jsonize());

  }

  if(m_directoryIdHasBeenSet)
  {
   payload.WithString("DirectoryId", m_directoryId);

  }

  return payload.View().WriteReadable();
}

Aws::Http::HeaderValueCollection StartADAssessmentRequest::GetRequestSpecificHeaders() const
{
  Aws::Http::HeaderValueCollection headers;
  headers.insert(Aws::Http::HeaderValuePair("X-Amz-Target", "DirectoryService_20150416.StartADAssessment"));
  return headers;

}




