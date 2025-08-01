﻿/**
 * Copyright Amazon.com, Inc. or its affiliates. All Rights Reserved.
 * SPDX-License-Identifier: Apache-2.0.
 */

#include <aws/datazone/model/S3PropertiesInput.h>
#include <aws/core/utils/json/JsonSerializer.h>

#include <utility>

using namespace Aws::Utils::Json;
using namespace Aws::Utils;

namespace Aws
{
namespace DataZone
{
namespace Model
{

S3PropertiesInput::S3PropertiesInput(JsonView jsonValue)
{
  *this = jsonValue;
}

S3PropertiesInput& S3PropertiesInput::operator =(JsonView jsonValue)
{
  if(jsonValue.ValueExists("s3AccessGrantLocationId"))
  {
    m_s3AccessGrantLocationId = jsonValue.GetString("s3AccessGrantLocationId");
    m_s3AccessGrantLocationIdHasBeenSet = true;
  }
  if(jsonValue.ValueExists("s3Uri"))
  {
    m_s3Uri = jsonValue.GetString("s3Uri");
    m_s3UriHasBeenSet = true;
  }
  return *this;
}

JsonValue S3PropertiesInput::Jsonize() const
{
  JsonValue payload;

  if(m_s3AccessGrantLocationIdHasBeenSet)
  {
   payload.WithString("s3AccessGrantLocationId", m_s3AccessGrantLocationId);

  }

  if(m_s3UriHasBeenSet)
  {
   payload.WithString("s3Uri", m_s3Uri);

  }

  return payload;
}

} // namespace Model
} // namespace DataZone
} // namespace Aws
