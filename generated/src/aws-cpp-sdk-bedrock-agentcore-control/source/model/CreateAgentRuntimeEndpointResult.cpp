﻿/**
 * Copyright Amazon.com, Inc. or its affiliates. All Rights Reserved.
 * SPDX-License-Identifier: Apache-2.0.
 */

#include <aws/bedrock-agentcore-control/model/CreateAgentRuntimeEndpointResult.h>
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

CreateAgentRuntimeEndpointResult::CreateAgentRuntimeEndpointResult(const Aws::AmazonWebServiceResult<JsonValue>& result)
{
  *this = result;
}

CreateAgentRuntimeEndpointResult& CreateAgentRuntimeEndpointResult::operator =(const Aws::AmazonWebServiceResult<JsonValue>& result)
{
  JsonView jsonValue = result.GetPayload().View();
  if(jsonValue.ValueExists("targetVersion"))
  {
    m_targetVersion = jsonValue.GetString("targetVersion");
    m_targetVersionHasBeenSet = true;
  }
  if(jsonValue.ValueExists("agentRuntimeEndpointArn"))
  {
    m_agentRuntimeEndpointArn = jsonValue.GetString("agentRuntimeEndpointArn");
    m_agentRuntimeEndpointArnHasBeenSet = true;
  }
  if(jsonValue.ValueExists("agentRuntimeArn"))
  {
    m_agentRuntimeArn = jsonValue.GetString("agentRuntimeArn");
    m_agentRuntimeArnHasBeenSet = true;
  }
  if(jsonValue.ValueExists("status"))
  {
    m_status = AgentEndpointStatusMapper::GetAgentEndpointStatusForName(jsonValue.GetString("status"));
    m_statusHasBeenSet = true;
  }
  if(jsonValue.ValueExists("createdAt"))
  {
    m_createdAt = jsonValue.GetString("createdAt");
    m_createdAtHasBeenSet = true;
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
