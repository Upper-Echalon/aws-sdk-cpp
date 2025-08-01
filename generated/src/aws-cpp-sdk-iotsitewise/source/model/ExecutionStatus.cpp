﻿/**
 * Copyright Amazon.com, Inc. or its affiliates. All Rights Reserved.
 * SPDX-License-Identifier: Apache-2.0.
 */

#include <aws/iotsitewise/model/ExecutionStatus.h>
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

ExecutionStatus::ExecutionStatus(JsonView jsonValue)
{
  *this = jsonValue;
}

ExecutionStatus& ExecutionStatus::operator =(JsonView jsonValue)
{
  if(jsonValue.ValueExists("state"))
  {
    m_state = ExecutionStateMapper::GetExecutionStateForName(jsonValue.GetString("state"));
    m_stateHasBeenSet = true;
  }
  return *this;
}

JsonValue ExecutionStatus::Jsonize() const
{
  JsonValue payload;

  if(m_stateHasBeenSet)
  {
   payload.WithString("state", ExecutionStateMapper::GetNameForExecutionState(m_state));
  }

  return payload;
}

} // namespace Model
} // namespace IoTSiteWise
} // namespace Aws
