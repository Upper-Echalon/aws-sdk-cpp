﻿/**
 * Copyright Amazon.com, Inc. or its affiliates. All Rights Reserved.
 * SPDX-License-Identifier: Apache-2.0.
 */

#include <aws/inspector2/model/AutoEnable.h>
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

AutoEnable::AutoEnable(JsonView jsonValue)
{
  *this = jsonValue;
}

AutoEnable& AutoEnable::operator =(JsonView jsonValue)
{
  if(jsonValue.ValueExists("ec2"))
  {
    m_ec2 = jsonValue.GetBool("ec2");
    m_ec2HasBeenSet = true;
  }
  if(jsonValue.ValueExists("ecr"))
  {
    m_ecr = jsonValue.GetBool("ecr");
    m_ecrHasBeenSet = true;
  }
  if(jsonValue.ValueExists("lambda"))
  {
    m_lambda = jsonValue.GetBool("lambda");
    m_lambdaHasBeenSet = true;
  }
  if(jsonValue.ValueExists("lambdaCode"))
  {
    m_lambdaCode = jsonValue.GetBool("lambdaCode");
    m_lambdaCodeHasBeenSet = true;
  }
  if(jsonValue.ValueExists("codeRepository"))
  {
    m_codeRepository = jsonValue.GetBool("codeRepository");
    m_codeRepositoryHasBeenSet = true;
  }
  return *this;
}

JsonValue AutoEnable::Jsonize() const
{
  JsonValue payload;

  if(m_ec2HasBeenSet)
  {
   payload.WithBool("ec2", m_ec2);

  }

  if(m_ecrHasBeenSet)
  {
   payload.WithBool("ecr", m_ecr);

  }

  if(m_lambdaHasBeenSet)
  {
   payload.WithBool("lambda", m_lambda);

  }

  if(m_lambdaCodeHasBeenSet)
  {
   payload.WithBool("lambdaCode", m_lambdaCode);

  }

  if(m_codeRepositoryHasBeenSet)
  {
   payload.WithBool("codeRepository", m_codeRepository);

  }

  return payload;
}

} // namespace Model
} // namespace Inspector2
} // namespace Aws
