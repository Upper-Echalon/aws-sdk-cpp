﻿/**
 * Copyright Amazon.com, Inc. or its affiliates. All Rights Reserved.
 * SPDX-License-Identifier: Apache-2.0.
 */

#include <aws/inspector2/model/FindingTypeAggregation.h>
#include <aws/core/utils/json/JsonSerializer.h>

#include <utility>

using namespace Aws::Utils::Json;
using namespace Aws::Utils;

namespace Aws
{
namespace Inspector2
{
namespace Model
{

FindingTypeAggregation::FindingTypeAggregation(JsonView jsonValue)
{
  *this = jsonValue;
}

FindingTypeAggregation& FindingTypeAggregation::operator =(JsonView jsonValue)
{
  if(jsonValue.ValueExists("findingType"))
  {
    m_findingType = AggregationFindingTypeMapper::GetAggregationFindingTypeForName(jsonValue.GetString("findingType"));
    m_findingTypeHasBeenSet = true;
  }
  if(jsonValue.ValueExists("resourceType"))
  {
    m_resourceType = AggregationResourceTypeMapper::GetAggregationResourceTypeForName(jsonValue.GetString("resourceType"));
    m_resourceTypeHasBeenSet = true;
  }
  if(jsonValue.ValueExists("sortOrder"))
  {
    m_sortOrder = SortOrderMapper::GetSortOrderForName(jsonValue.GetString("sortOrder"));
    m_sortOrderHasBeenSet = true;
  }
  if(jsonValue.ValueExists("sortBy"))
  {
    m_sortBy = FindingTypeSortByMapper::GetFindingTypeSortByForName(jsonValue.GetString("sortBy"));
    m_sortByHasBeenSet = true;
  }
  return *this;
}

JsonValue FindingTypeAggregation::Jsonize() const
{
  JsonValue payload;

  if(m_findingTypeHasBeenSet)
  {
   payload.WithString("findingType", AggregationFindingTypeMapper::GetNameForAggregationFindingType(m_findingType));
  }

  if(m_resourceTypeHasBeenSet)
  {
   payload.WithString("resourceType", AggregationResourceTypeMapper::GetNameForAggregationResourceType(m_resourceType));
  }

  if(m_sortOrderHasBeenSet)
  {
   payload.WithString("sortOrder", SortOrderMapper::GetNameForSortOrder(m_sortOrder));
  }

  if(m_sortByHasBeenSet)
  {
   payload.WithString("sortBy", FindingTypeSortByMapper::GetNameForFindingTypeSortBy(m_sortBy));
  }

  return payload;
}

} // namespace Model
} // namespace Inspector2
} // namespace Aws
