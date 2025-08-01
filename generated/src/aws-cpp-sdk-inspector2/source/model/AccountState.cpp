﻿/**
 * Copyright Amazon.com, Inc. or its affiliates. All Rights Reserved.
 * SPDX-License-Identifier: Apache-2.0.
 */

#include <aws/inspector2/model/AccountState.h>
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

AccountState::AccountState(JsonView jsonValue)
{
  *this = jsonValue;
}

AccountState& AccountState::operator =(JsonView jsonValue)
{
  if(jsonValue.ValueExists("accountId"))
  {
    m_accountId = jsonValue.GetString("accountId");
    m_accountIdHasBeenSet = true;
  }
  if(jsonValue.ValueExists("state"))
  {
    m_state = jsonValue.GetObject("state");
    m_stateHasBeenSet = true;
  }
  if(jsonValue.ValueExists("resourceState"))
  {
    m_resourceState = jsonValue.GetObject("resourceState");
    m_resourceStateHasBeenSet = true;
  }
  return *this;
}

JsonValue AccountState::Jsonize() const
{
  JsonValue payload;

  if(m_accountIdHasBeenSet)
  {
   payload.WithString("accountId", m_accountId);

  }

  if(m_stateHasBeenSet)
  {
   payload.WithObject("state", m_state.Jsonize());

  }

  if(m_resourceStateHasBeenSet)
  {
   payload.WithObject("resourceState", m_resourceState.Jsonize());

  }

  return payload;
}

} // namespace Model
} // namespace Inspector2
} // namespace Aws
