﻿/**
 * Copyright Amazon.com, Inc. or its affiliates. All Rights Reserved.
 * SPDX-License-Identifier: Apache-2.0.
 */

#include <aws/bedrock-agentcore-control/model/DeleteGatewayTargetResult.h>
#include <aws/core/utils/json/JsonSerializer.h>
#include <aws/core/AmazonWebServiceResult.h>
#include <aws/core/utils/StringUtils.h>
#include <aws/core/utils/UnreferencedParam.h>
#include <aws/core/utils/memory/stl/AWSStringStream.h>

#include <utility>

using namespace Aws::BedrockAgentCoreControl::Model;
using namespace Aws::Utils::Json;
using namespace Aws::Utils;
using namespace Aws;

DeleteGatewayTargetResult::DeleteGatewayTargetResult(const Aws::AmazonWebServiceResult<JsonValue>& result)
{
  *this = result;
}

DeleteGatewayTargetResult& DeleteGatewayTargetResult::operator =(const Aws::AmazonWebServiceResult<JsonValue>& result)
{
  JsonView jsonValue = result.GetPayload().View();
  if(jsonValue.ValueExists("gatewayArn"))
  {
    m_gatewayArn = jsonValue.GetString("gatewayArn");
    m_gatewayArnHasBeenSet = true;
  }
  if(jsonValue.ValueExists("targetId"))
  {
    m_targetId = jsonValue.GetString("targetId");
    m_targetIdHasBeenSet = true;
  }
  if(jsonValue.ValueExists("status"))
  {
    m_status = TargetStatusMapper::GetTargetStatusForName(jsonValue.GetString("status"));
    m_statusHasBeenSet = true;
  }
  if(jsonValue.ValueExists("statusReasons"))
  {
    Aws::Utils::Array<JsonView> statusReasonsJsonList = jsonValue.GetArray("statusReasons");
    for(unsigned statusReasonsIndex = 0; statusReasonsIndex < statusReasonsJsonList.GetLength(); ++statusReasonsIndex)
    {
      m_statusReasons.push_back(statusReasonsJsonList[statusReasonsIndex].AsString());
    }
    m_statusReasonsHasBeenSet = true;
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
