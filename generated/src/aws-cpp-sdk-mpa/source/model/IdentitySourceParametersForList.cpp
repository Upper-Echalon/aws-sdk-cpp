﻿/**
 * Copyright Amazon.com, Inc. or its affiliates. All Rights Reserved.
 * SPDX-License-Identifier: Apache-2.0.
 */

#include <aws/mpa/model/IdentitySourceParametersForList.h>
#include <aws/core/utils/json/JsonSerializer.h>

#include <utility>

using namespace Aws::Utils::Json;
using namespace Aws::Utils;

namespace Aws
{
namespace MPA
{
namespace Model
{

IdentitySourceParametersForList::IdentitySourceParametersForList(JsonView jsonValue)
{
  *this = jsonValue;
}

IdentitySourceParametersForList& IdentitySourceParametersForList::operator =(JsonView jsonValue)
{
  if(jsonValue.ValueExists("IamIdentityCenter"))
  {
    m_iamIdentityCenter = jsonValue.GetObject("IamIdentityCenter");
    m_iamIdentityCenterHasBeenSet = true;
  }
  return *this;
}

JsonValue IdentitySourceParametersForList::Jsonize() const
{
  JsonValue payload;

  if(m_iamIdentityCenterHasBeenSet)
  {
   payload.WithObject("IamIdentityCenter", m_iamIdentityCenter.Jsonize());

  }

  return payload;
}

} // namespace Model
} // namespace MPA
} // namespace Aws
