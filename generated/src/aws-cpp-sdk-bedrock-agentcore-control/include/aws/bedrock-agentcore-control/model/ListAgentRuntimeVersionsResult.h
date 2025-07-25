﻿/**
 * Copyright Amazon.com, Inc. or its affiliates. All Rights Reserved.
 * SPDX-License-Identifier: Apache-2.0.
 */

#pragma once
#include <aws/bedrock-agentcore-control/BedrockAgentCoreControl_EXPORTS.h>
#include <aws/core/utils/memory/stl/AWSVector.h>
#include <aws/core/utils/memory/stl/AWSString.h>
#include <aws/bedrock-agentcore-control/model/Agent.h>
#include <utility>

namespace Aws
{
template<typename RESULT_TYPE>
class AmazonWebServiceResult;

namespace Utils
{
namespace Json
{
  class JsonValue;
} // namespace Json
} // namespace Utils
namespace BedrockAgentCoreControl
{
namespace Model
{
  class ListAgentRuntimeVersionsResult
  {
  public:
    AWS_BEDROCKAGENTCORECONTROL_API ListAgentRuntimeVersionsResult() = default;
    AWS_BEDROCKAGENTCORECONTROL_API ListAgentRuntimeVersionsResult(const Aws::AmazonWebServiceResult<Aws::Utils::Json::JsonValue>& result);
    AWS_BEDROCKAGENTCORECONTROL_API ListAgentRuntimeVersionsResult& operator=(const Aws::AmazonWebServiceResult<Aws::Utils::Json::JsonValue>& result);


    ///@{
    /**
     * <p>The list of agent runtime versions.</p>
     */
    inline const Aws::Vector<Agent>& GetAgentRuntimes() const { return m_agentRuntimes; }
    template<typename AgentRuntimesT = Aws::Vector<Agent>>
    void SetAgentRuntimes(AgentRuntimesT&& value) { m_agentRuntimesHasBeenSet = true; m_agentRuntimes = std::forward<AgentRuntimesT>(value); }
    template<typename AgentRuntimesT = Aws::Vector<Agent>>
    ListAgentRuntimeVersionsResult& WithAgentRuntimes(AgentRuntimesT&& value) { SetAgentRuntimes(std::forward<AgentRuntimesT>(value)); return *this;}
    template<typename AgentRuntimesT = Agent>
    ListAgentRuntimeVersionsResult& AddAgentRuntimes(AgentRuntimesT&& value) { m_agentRuntimesHasBeenSet = true; m_agentRuntimes.emplace_back(std::forward<AgentRuntimesT>(value)); return *this; }
    ///@}

    ///@{
    /**
     * <p>A token to retrieve the next page of results.</p>
     */
    inline const Aws::String& GetNextToken() const { return m_nextToken; }
    template<typename NextTokenT = Aws::String>
    void SetNextToken(NextTokenT&& value) { m_nextTokenHasBeenSet = true; m_nextToken = std::forward<NextTokenT>(value); }
    template<typename NextTokenT = Aws::String>
    ListAgentRuntimeVersionsResult& WithNextToken(NextTokenT&& value) { SetNextToken(std::forward<NextTokenT>(value)); return *this;}
    ///@}

    ///@{
    
    inline const Aws::String& GetRequestId() const { return m_requestId; }
    template<typename RequestIdT = Aws::String>
    void SetRequestId(RequestIdT&& value) { m_requestIdHasBeenSet = true; m_requestId = std::forward<RequestIdT>(value); }
    template<typename RequestIdT = Aws::String>
    ListAgentRuntimeVersionsResult& WithRequestId(RequestIdT&& value) { SetRequestId(std::forward<RequestIdT>(value)); return *this;}
    ///@}
  private:

    Aws::Vector<Agent> m_agentRuntimes;
    bool m_agentRuntimesHasBeenSet = false;

    Aws::String m_nextToken;
    bool m_nextTokenHasBeenSet = false;

    Aws::String m_requestId;
    bool m_requestIdHasBeenSet = false;
  };

} // namespace Model
} // namespace BedrockAgentCoreControl
} // namespace Aws
