﻿/**
 * Copyright Amazon.com, Inc. or its affiliates. All Rights Reserved.
 * SPDX-License-Identifier: Apache-2.0.
 */

#include <aws/marketplace-catalog/model/MachineLearningProductLastModifiedDateFilter.h>
#include <aws/core/utils/json/JsonSerializer.h>

#include <utility>

using namespace Aws::Utils::Json;
using namespace Aws::Utils;

namespace Aws
{
namespace MarketplaceCatalog
{
namespace Model
{

MachineLearningProductLastModifiedDateFilter::MachineLearningProductLastModifiedDateFilter(JsonView jsonValue)
{
  *this = jsonValue;
}

MachineLearningProductLastModifiedDateFilter& MachineLearningProductLastModifiedDateFilter::operator =(JsonView jsonValue)
{
  if(jsonValue.ValueExists("DateRange"))
  {
    m_dateRange = jsonValue.GetObject("DateRange");
    m_dateRangeHasBeenSet = true;
  }
  return *this;
}

JsonValue MachineLearningProductLastModifiedDateFilter::Jsonize() const
{
  JsonValue payload;

  if(m_dateRangeHasBeenSet)
  {
   payload.WithObject("DateRange", m_dateRange.Jsonize());

  }

  return payload;
}

} // namespace Model
} // namespace MarketplaceCatalog
} // namespace Aws
