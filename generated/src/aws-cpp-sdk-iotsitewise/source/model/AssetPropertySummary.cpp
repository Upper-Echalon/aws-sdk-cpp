﻿/**
 * Copyright Amazon.com, Inc. or its affiliates. All Rights Reserved.
 * SPDX-License-Identifier: Apache-2.0.
 */

#include <aws/iotsitewise/model/AssetPropertySummary.h>
#include <aws/core/utils/json/JsonSerializer.h>

#include <utility>

using namespace Aws::Utils::Json;
using namespace Aws::Utils;

namespace Aws
{
namespace IoTSiteWise
{
namespace Model
{

AssetPropertySummary::AssetPropertySummary(JsonView jsonValue)
{
  *this = jsonValue;
}

AssetPropertySummary& AssetPropertySummary::operator =(JsonView jsonValue)
{
  if(jsonValue.ValueExists("id"))
  {
    m_id = jsonValue.GetString("id");
    m_idHasBeenSet = true;
  }
  if(jsonValue.ValueExists("externalId"))
  {
    m_externalId = jsonValue.GetString("externalId");
    m_externalIdHasBeenSet = true;
  }
  if(jsonValue.ValueExists("alias"))
  {
    m_alias = jsonValue.GetString("alias");
    m_aliasHasBeenSet = true;
  }
  if(jsonValue.ValueExists("unit"))
  {
    m_unit = jsonValue.GetString("unit");
    m_unitHasBeenSet = true;
  }
  if(jsonValue.ValueExists("notification"))
  {
    m_notification = jsonValue.GetObject("notification");
    m_notificationHasBeenSet = true;
  }
  if(jsonValue.ValueExists("assetCompositeModelId"))
  {
    m_assetCompositeModelId = jsonValue.GetString("assetCompositeModelId");
    m_assetCompositeModelIdHasBeenSet = true;
  }
  if(jsonValue.ValueExists("path"))
  {
    Aws::Utils::Array<JsonView> pathJsonList = jsonValue.GetArray("path");
    for(unsigned pathIndex = 0; pathIndex < pathJsonList.GetLength(); ++pathIndex)
    {
      m_path.push_back(pathJsonList[pathIndex].AsObject());
    }
    m_pathHasBeenSet = true;
  }
  return *this;
}

JsonValue AssetPropertySummary::Jsonize() const
{
  JsonValue payload;

  if(m_idHasBeenSet)
  {
   payload.WithString("id", m_id);

  }

  if(m_externalIdHasBeenSet)
  {
   payload.WithString("externalId", m_externalId);

  }

  if(m_aliasHasBeenSet)
  {
   payload.WithString("alias", m_alias);

  }

  if(m_unitHasBeenSet)
  {
   payload.WithString("unit", m_unit);

  }

  if(m_notificationHasBeenSet)
  {
   payload.WithObject("notification", m_notification.Jsonize());

  }

  if(m_assetCompositeModelIdHasBeenSet)
  {
   payload.WithString("assetCompositeModelId", m_assetCompositeModelId);

  }

  if(m_pathHasBeenSet)
  {
   Aws::Utils::Array<JsonValue> pathJsonList(m_path.size());
   for(unsigned pathIndex = 0; pathIndex < pathJsonList.GetLength(); ++pathIndex)
   {
     pathJsonList[pathIndex].AsObject(m_path[pathIndex].Jsonize());
   }
   payload.WithArray("path", std::move(pathJsonList));

  }

  return payload;
}

} // namespace Model
} // namespace IoTSiteWise
} // namespace Aws
