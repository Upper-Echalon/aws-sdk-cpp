﻿/**
 * Copyright Amazon.com, Inc. or its affiliates. All Rights Reserved.
 * SPDX-License-Identifier: Apache-2.0.
 */

#include <aws/deadline/model/UpdateQueueEnvironmentRequest.h>
#include <aws/core/utils/json/JsonSerializer.h>
#include <aws/core/utils/memory/stl/AWSStringStream.h>

#include <utility>

using namespace Aws::deadline::Model;
using namespace Aws::Utils::Json;
using namespace Aws::Utils;

UpdateQueueEnvironmentRequest::UpdateQueueEnvironmentRequest() : 
    m_clientToken(Aws::Utils::UUID::PseudoRandomUUID()),
    m_clientTokenHasBeenSet(true),
    m_farmIdHasBeenSet(false),
    m_queueIdHasBeenSet(false),
    m_queueEnvironmentIdHasBeenSet(false),
    m_priority(0),
    m_priorityHasBeenSet(false),
    m_templateType(EnvironmentTemplateType::NOT_SET),
    m_templateTypeHasBeenSet(false),
    m_templateHasBeenSet(false)
{
}

Aws::String UpdateQueueEnvironmentRequest::SerializePayload() const
{
  JsonValue payload;

  if(m_priorityHasBeenSet)
  {
   payload.WithInteger("priority", m_priority);

  }

  if(m_templateTypeHasBeenSet)
  {
   payload.WithString("templateType", EnvironmentTemplateTypeMapper::GetNameForEnvironmentTemplateType(m_templateType));
  }

  if(m_templateHasBeenSet)
  {
   payload.WithString("template", m_template);

  }

  return payload.View().WriteReadable();
}

Aws::Http::HeaderValueCollection UpdateQueueEnvironmentRequest::GetRequestSpecificHeaders() const
{
  Aws::Http::HeaderValueCollection headers;
  Aws::StringStream ss;
  if(m_clientTokenHasBeenSet)
  {
    ss << m_clientToken;
    headers.emplace("x-amz-client-token",  ss.str());
    ss.str("");
  }

  return headers;

}




