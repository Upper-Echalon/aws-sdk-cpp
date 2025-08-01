﻿/**
 * Copyright Amazon.com, Inc. or its affiliates. All Rights Reserved.
 * SPDX-License-Identifier: Apache-2.0.
 */

#pragma once
#include <aws/iotsitewise/IoTSiteWise_EXPORTS.h>
#include <aws/core/utils/memory/stl/AWSVector.h>
#include <aws/core/utils/memory/stl/AWSString.h>
#include <aws/iotsitewise/model/ExecutionSummary.h>
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
namespace IoTSiteWise
{
namespace Model
{
  class ListExecutionsResult
  {
  public:
    AWS_IOTSITEWISE_API ListExecutionsResult() = default;
    AWS_IOTSITEWISE_API ListExecutionsResult(const Aws::AmazonWebServiceResult<Aws::Utils::Json::JsonValue>& result);
    AWS_IOTSITEWISE_API ListExecutionsResult& operator=(const Aws::AmazonWebServiceResult<Aws::Utils::Json::JsonValue>& result);


    ///@{
    /**
     * <p>Contains the list of execution summaries of the computation models.</p>
     */
    inline const Aws::Vector<ExecutionSummary>& GetExecutionSummaries() const { return m_executionSummaries; }
    template<typename ExecutionSummariesT = Aws::Vector<ExecutionSummary>>
    void SetExecutionSummaries(ExecutionSummariesT&& value) { m_executionSummariesHasBeenSet = true; m_executionSummaries = std::forward<ExecutionSummariesT>(value); }
    template<typename ExecutionSummariesT = Aws::Vector<ExecutionSummary>>
    ListExecutionsResult& WithExecutionSummaries(ExecutionSummariesT&& value) { SetExecutionSummaries(std::forward<ExecutionSummariesT>(value)); return *this;}
    template<typename ExecutionSummariesT = ExecutionSummary>
    ListExecutionsResult& AddExecutionSummaries(ExecutionSummariesT&& value) { m_executionSummariesHasBeenSet = true; m_executionSummaries.emplace_back(std::forward<ExecutionSummariesT>(value)); return *this; }
    ///@}

    ///@{
    /**
     * <p>The token for the next set of results, or null if there are no additional
     * results.</p>
     */
    inline const Aws::String& GetNextToken() const { return m_nextToken; }
    template<typename NextTokenT = Aws::String>
    void SetNextToken(NextTokenT&& value) { m_nextTokenHasBeenSet = true; m_nextToken = std::forward<NextTokenT>(value); }
    template<typename NextTokenT = Aws::String>
    ListExecutionsResult& WithNextToken(NextTokenT&& value) { SetNextToken(std::forward<NextTokenT>(value)); return *this;}
    ///@}

    ///@{
    
    inline const Aws::String& GetRequestId() const { return m_requestId; }
    template<typename RequestIdT = Aws::String>
    void SetRequestId(RequestIdT&& value) { m_requestIdHasBeenSet = true; m_requestId = std::forward<RequestIdT>(value); }
    template<typename RequestIdT = Aws::String>
    ListExecutionsResult& WithRequestId(RequestIdT&& value) { SetRequestId(std::forward<RequestIdT>(value)); return *this;}
    ///@}
  private:

    Aws::Vector<ExecutionSummary> m_executionSummaries;
    bool m_executionSummariesHasBeenSet = false;

    Aws::String m_nextToken;
    bool m_nextTokenHasBeenSet = false;

    Aws::String m_requestId;
    bool m_requestIdHasBeenSet = false;
  };

} // namespace Model
} // namespace IoTSiteWise
} // namespace Aws
