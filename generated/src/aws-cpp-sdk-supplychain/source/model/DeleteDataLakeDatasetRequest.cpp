﻿/**
 * Copyright Amazon.com, Inc. or its affiliates. All Rights Reserved.
 * SPDX-License-Identifier: Apache-2.0.
 */

#include <aws/supplychain/model/DeleteDataLakeDatasetRequest.h>
#include <aws/core/utils/json/JsonSerializer.h>

#include <utility>

using namespace Aws::SupplyChain::Model;
using namespace Aws::Utils::Json;
using namespace Aws::Utils;

DeleteDataLakeDatasetRequest::DeleteDataLakeDatasetRequest() : 
    m_instanceIdHasBeenSet(false),
    m_namespaceHasBeenSet(false),
    m_nameHasBeenSet(false)
{
}

Aws::String DeleteDataLakeDatasetRequest::SerializePayload() const
{
  return {};
}




