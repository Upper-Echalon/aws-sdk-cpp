﻿/**
 * Copyright Amazon.com, Inc. or its affiliates. All Rights Reserved.
 * SPDX-License-Identifier: Apache-2.0.
 */

#pragma once
#include <aws/sagemaker/SageMaker_EXPORTS.h>
#include <aws/core/utils/memory/stl/AWSVector.h>
#include <aws/core/utils/memory/stl/AWSString.h>
#include <aws/sagemaker/model/PipelineVersionSummary.h>
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
namespace SageMaker
{
namespace Model
{
  class ListPipelineVersionsResult
  {
  public:
    AWS_SAGEMAKER_API ListPipelineVersionsResult() = default;
    AWS_SAGEMAKER_API ListPipelineVersionsResult(const Aws::AmazonWebServiceResult<Aws::Utils::Json::JsonValue>& result);
    AWS_SAGEMAKER_API ListPipelineVersionsResult& operator=(const Aws::AmazonWebServiceResult<Aws::Utils::Json::JsonValue>& result);


    ///@{
    /**
     * <p>Contains a sorted list of pipeline version summary objects matching the
     * specified filters. Each version summary includes the pipeline version ID, the
     * creation date, and the last pipeline execution created from that version. This
     * list can be empty.</p>
     */
    inline const Aws::Vector<PipelineVersionSummary>& GetPipelineVersionSummaries() const { return m_pipelineVersionSummaries; }
    template<typename PipelineVersionSummariesT = Aws::Vector<PipelineVersionSummary>>
    void SetPipelineVersionSummaries(PipelineVersionSummariesT&& value) { m_pipelineVersionSummariesHasBeenSet = true; m_pipelineVersionSummaries = std::forward<PipelineVersionSummariesT>(value); }
    template<typename PipelineVersionSummariesT = Aws::Vector<PipelineVersionSummary>>
    ListPipelineVersionsResult& WithPipelineVersionSummaries(PipelineVersionSummariesT&& value) { SetPipelineVersionSummaries(std::forward<PipelineVersionSummariesT>(value)); return *this;}
    template<typename PipelineVersionSummariesT = PipelineVersionSummary>
    ListPipelineVersionsResult& AddPipelineVersionSummaries(PipelineVersionSummariesT&& value) { m_pipelineVersionSummariesHasBeenSet = true; m_pipelineVersionSummaries.emplace_back(std::forward<PipelineVersionSummariesT>(value)); return *this; }
    ///@}

    ///@{
    /**
     * <p>If the result of the previous <code>ListPipelineVersions</code> request was
     * truncated, the response includes a <code>NextToken</code>. To retrieve the next
     * set of pipeline versions, use this token in your next request.</p>
     */
    inline const Aws::String& GetNextToken() const { return m_nextToken; }
    template<typename NextTokenT = Aws::String>
    void SetNextToken(NextTokenT&& value) { m_nextTokenHasBeenSet = true; m_nextToken = std::forward<NextTokenT>(value); }
    template<typename NextTokenT = Aws::String>
    ListPipelineVersionsResult& WithNextToken(NextTokenT&& value) { SetNextToken(std::forward<NextTokenT>(value)); return *this;}
    ///@}

    ///@{
    
    inline const Aws::String& GetRequestId() const { return m_requestId; }
    template<typename RequestIdT = Aws::String>
    void SetRequestId(RequestIdT&& value) { m_requestIdHasBeenSet = true; m_requestId = std::forward<RequestIdT>(value); }
    template<typename RequestIdT = Aws::String>
    ListPipelineVersionsResult& WithRequestId(RequestIdT&& value) { SetRequestId(std::forward<RequestIdT>(value)); return *this;}
    ///@}
  private:

    Aws::Vector<PipelineVersionSummary> m_pipelineVersionSummaries;
    bool m_pipelineVersionSummariesHasBeenSet = false;

    Aws::String m_nextToken;
    bool m_nextTokenHasBeenSet = false;

    Aws::String m_requestId;
    bool m_requestIdHasBeenSet = false;
  };

} // namespace Model
} // namespace SageMaker
} // namespace Aws
