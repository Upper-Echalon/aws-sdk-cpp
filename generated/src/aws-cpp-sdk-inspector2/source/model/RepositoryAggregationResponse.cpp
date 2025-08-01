﻿/**
 * Copyright Amazon.com, Inc. or its affiliates. All Rights Reserved.
 * SPDX-License-Identifier: Apache-2.0.
 */

#include <aws/inspector2/model/RepositoryAggregationResponse.h>
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

RepositoryAggregationResponse::RepositoryAggregationResponse(JsonView jsonValue)
{
  *this = jsonValue;
}

RepositoryAggregationResponse& RepositoryAggregationResponse::operator =(JsonView jsonValue)
{
  if(jsonValue.ValueExists("repository"))
  {
    m_repository = jsonValue.GetString("repository");
    m_repositoryHasBeenSet = true;
  }
  if(jsonValue.ValueExists("accountId"))
  {
    m_accountId = jsonValue.GetString("accountId");
    m_accountIdHasBeenSet = true;
  }
  if(jsonValue.ValueExists("severityCounts"))
  {
    m_severityCounts = jsonValue.GetObject("severityCounts");
    m_severityCountsHasBeenSet = true;
  }
  if(jsonValue.ValueExists("affectedImages"))
  {
    m_affectedImages = jsonValue.GetInt64("affectedImages");
    m_affectedImagesHasBeenSet = true;
  }
  return *this;
}

JsonValue RepositoryAggregationResponse::Jsonize() const
{
  JsonValue payload;

  if(m_repositoryHasBeenSet)
  {
   payload.WithString("repository", m_repository);

  }

  if(m_accountIdHasBeenSet)
  {
   payload.WithString("accountId", m_accountId);

  }

  if(m_severityCountsHasBeenSet)
  {
   payload.WithObject("severityCounts", m_severityCounts.Jsonize());

  }

  if(m_affectedImagesHasBeenSet)
  {
   payload.WithInt64("affectedImages", m_affectedImages);

  }

  return payload;
}

} // namespace Model
} // namespace Inspector2
} // namespace Aws
