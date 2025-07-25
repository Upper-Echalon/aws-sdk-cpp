﻿/**
 * Copyright Amazon.com, Inc. or its affiliates. All Rights Reserved.
 * SPDX-License-Identifier: Apache-2.0.
 */

#include <aws/arc-zonal-shift/model/StartZonalShiftRequest.h>
#include <aws/core/utils/json/JsonSerializer.h>

#include <utility>

using namespace Aws::ARCZonalShift::Model;
using namespace Aws::Utils::Json;
using namespace Aws::Utils;

Aws::String StartZonalShiftRequest::SerializePayload() const
{
  JsonValue payload;

  if(m_resourceIdentifierHasBeenSet)
  {
   payload.WithString("resourceIdentifier", m_resourceIdentifier);

  }

  if(m_awayFromHasBeenSet)
  {
   payload.WithString("awayFrom", m_awayFrom);

  }

  if(m_expiresInHasBeenSet)
  {
   payload.WithString("expiresIn", m_expiresIn);

  }

  if(m_commentHasBeenSet)
  {
   payload.WithString("comment", m_comment);

  }

  return payload.View().WriteReadable();
}




