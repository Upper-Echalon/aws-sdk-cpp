﻿/**
 * Copyright Amazon.com, Inc. or its affiliates. All Rights Reserved.
 * SPDX-License-Identifier: Apache-2.0.
 */

#include <aws/freetier/model/GetAccountPlanStateResult.h>
#include <aws/core/utils/json/JsonSerializer.h>
#include <aws/core/AmazonWebServiceResult.h>
#include <aws/core/utils/StringUtils.h>
#include <aws/core/utils/UnreferencedParam.h>
#include <aws/core/utils/memory/stl/AWSStringStream.h>

#include <utility>

using namespace Aws::FreeTier::Model;
using namespace Aws::Utils::Json;
using namespace Aws::Utils;
using namespace Aws;

GetAccountPlanStateResult::GetAccountPlanStateResult(const Aws::AmazonWebServiceResult<JsonValue>& result)
{
  *this = result;
}

GetAccountPlanStateResult& GetAccountPlanStateResult::operator =(const Aws::AmazonWebServiceResult<JsonValue>& result)
{
  JsonView jsonValue = result.GetPayload().View();
  if(jsonValue.ValueExists("accountId"))
  {
    m_accountId = jsonValue.GetString("accountId");
    m_accountIdHasBeenSet = true;
  }
  if(jsonValue.ValueExists("accountPlanType"))
  {
    m_accountPlanType = AccountPlanTypeMapper::GetAccountPlanTypeForName(jsonValue.GetString("accountPlanType"));
    m_accountPlanTypeHasBeenSet = true;
  }
  if(jsonValue.ValueExists("accountPlanStatus"))
  {
    m_accountPlanStatus = AccountPlanStatusMapper::GetAccountPlanStatusForName(jsonValue.GetString("accountPlanStatus"));
    m_accountPlanStatusHasBeenSet = true;
  }
  if(jsonValue.ValueExists("accountPlanRemainingCredits"))
  {
    m_accountPlanRemainingCredits = jsonValue.GetObject("accountPlanRemainingCredits");
    m_accountPlanRemainingCreditsHasBeenSet = true;
  }
  if(jsonValue.ValueExists("accountPlanExpirationDate"))
  {
    m_accountPlanExpirationDate = jsonValue.GetString("accountPlanExpirationDate");
    m_accountPlanExpirationDateHasBeenSet = true;
  }

  const auto& headers = result.GetHeaderValueCollection();
  const auto& requestIdIter = headers.find("x-amzn-requestid");
  if(requestIdIter != headers.end())
  {
    m_requestId = requestIdIter->second;
    m_requestIdHasBeenSet = true;
  }


  return *this;
}
