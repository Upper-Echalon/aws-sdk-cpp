﻿/**
 * Copyright Amazon.com, Inc. or its affiliates. All Rights Reserved.
 * SPDX-License-Identifier: Apache-2.0.
 */

#include <aws/inspector2/model/FreeTrialInfo.h>
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

FreeTrialInfo::FreeTrialInfo(JsonView jsonValue)
{
  *this = jsonValue;
}

FreeTrialInfo& FreeTrialInfo::operator =(JsonView jsonValue)
{
  if(jsonValue.ValueExists("type"))
  {
    m_type = FreeTrialTypeMapper::GetFreeTrialTypeForName(jsonValue.GetString("type"));
    m_typeHasBeenSet = true;
  }
  if(jsonValue.ValueExists("start"))
  {
    m_start = jsonValue.GetDouble("start");
    m_startHasBeenSet = true;
  }
  if(jsonValue.ValueExists("end"))
  {
    m_end = jsonValue.GetDouble("end");
    m_endHasBeenSet = true;
  }
  if(jsonValue.ValueExists("status"))
  {
    m_status = FreeTrialStatusMapper::GetFreeTrialStatusForName(jsonValue.GetString("status"));
    m_statusHasBeenSet = true;
  }
  return *this;
}

JsonValue FreeTrialInfo::Jsonize() const
{
  JsonValue payload;

  if(m_typeHasBeenSet)
  {
   payload.WithString("type", FreeTrialTypeMapper::GetNameForFreeTrialType(m_type));
  }

  if(m_startHasBeenSet)
  {
   payload.WithDouble("start", m_start.SecondsWithMSPrecision());
  }

  if(m_endHasBeenSet)
  {
   payload.WithDouble("end", m_end.SecondsWithMSPrecision());
  }

  if(m_statusHasBeenSet)
  {
   payload.WithString("status", FreeTrialStatusMapper::GetNameForFreeTrialStatus(m_status));
  }

  return payload;
}

} // namespace Model
} // namespace Inspector2
} // namespace Aws
