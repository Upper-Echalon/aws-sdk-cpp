﻿/**
 * Copyright Amazon.com, Inc. or its affiliates. All Rights Reserved.
 * SPDX-License-Identifier: Apache-2.0.
 */

#include <aws/marketplace-catalog/model/MachineLearningProductTitleFilter.h>
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

MachineLearningProductTitleFilter::MachineLearningProductTitleFilter(JsonView jsonValue)
{
  *this = jsonValue;
}

MachineLearningProductTitleFilter& MachineLearningProductTitleFilter::operator =(JsonView jsonValue)
{
  if(jsonValue.ValueExists("ValueList"))
  {
    Aws::Utils::Array<JsonView> valueListJsonList = jsonValue.GetArray("ValueList");
    for(unsigned valueListIndex = 0; valueListIndex < valueListJsonList.GetLength(); ++valueListIndex)
    {
      m_valueList.push_back(valueListJsonList[valueListIndex].AsString());
    }
    m_valueListHasBeenSet = true;
  }
  if(jsonValue.ValueExists("WildCardValue"))
  {
    m_wildCardValue = jsonValue.GetString("WildCardValue");
    m_wildCardValueHasBeenSet = true;
  }
  return *this;
}

JsonValue MachineLearningProductTitleFilter::Jsonize() const
{
  JsonValue payload;

  if(m_valueListHasBeenSet)
  {
   Aws::Utils::Array<JsonValue> valueListJsonList(m_valueList.size());
   for(unsigned valueListIndex = 0; valueListIndex < valueListJsonList.GetLength(); ++valueListIndex)
   {
     valueListJsonList[valueListIndex].AsString(m_valueList[valueListIndex]);
   }
   payload.WithArray("ValueList", std::move(valueListJsonList));

  }

  if(m_wildCardValueHasBeenSet)
  {
   payload.WithString("WildCardValue", m_wildCardValue);

  }

  return payload;
}

} // namespace Model
} // namespace MarketplaceCatalog
} // namespace Aws
