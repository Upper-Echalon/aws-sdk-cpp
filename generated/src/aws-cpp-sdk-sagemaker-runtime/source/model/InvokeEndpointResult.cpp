﻿/**
 * Copyright Amazon.com, Inc. or its affiliates. All Rights Reserved.
 * SPDX-License-Identifier: Apache-2.0.
 */

#include <aws/sagemaker-runtime/model/InvokeEndpointResult.h>
#include <aws/core/AmazonWebServiceResult.h>
#include <aws/core/utils/StringUtils.h>
#include <aws/core/utils/HashingUtils.h>
#include <aws/core/utils/memory/stl/AWSStringStream.h>

#include <utility>

using namespace Aws::SageMakerRuntime::Model;
using namespace Aws::Utils::Stream;
using namespace Aws::Utils;
using namespace Aws;

InvokeEndpointResult::InvokeEndpointResult()
{
}

InvokeEndpointResult::InvokeEndpointResult(InvokeEndpointResult&& toMove) : 
    m_body(std::move(toMove.m_body)),
    m_contentType(std::move(toMove.m_contentType)),
    m_invokedProductionVariant(std::move(toMove.m_invokedProductionVariant)),
    m_customAttributes(std::move(toMove.m_customAttributes)),
    m_newSessionId(std::move(toMove.m_newSessionId)),
    m_closedSessionId(std::move(toMove.m_closedSessionId)),
    m_requestId(std::move(toMove.m_requestId))
{
}

InvokeEndpointResult& InvokeEndpointResult::operator=(InvokeEndpointResult&& toMove)
{
   if(this == &toMove)
   {
      return *this;
   }

   m_body = std::move(toMove.m_body);
   m_contentType = std::move(toMove.m_contentType);
   m_invokedProductionVariant = std::move(toMove.m_invokedProductionVariant);
   m_customAttributes = std::move(toMove.m_customAttributes);
   m_newSessionId = std::move(toMove.m_newSessionId);
   m_closedSessionId = std::move(toMove.m_closedSessionId);
   m_requestId = std::move(toMove.m_requestId);

   return *this;
}

InvokeEndpointResult::InvokeEndpointResult(Aws::AmazonWebServiceResult<ResponseStream>&& result)
{
  *this = std::move(result);
}

InvokeEndpointResult& InvokeEndpointResult::operator =(Aws::AmazonWebServiceResult<ResponseStream>&& result)
{
  m_body = result.TakeOwnershipOfPayload();

  const auto& headers = result.GetHeaderValueCollection();
  const auto& contentTypeIter = headers.find("content-type");
  if(contentTypeIter != headers.end())
  {
    m_contentType = contentTypeIter->second;
  }

  const auto& invokedProductionVariantIter = headers.find("x-amzn-invoked-production-variant");
  if(invokedProductionVariantIter != headers.end())
  {
    m_invokedProductionVariant = invokedProductionVariantIter->second;
  }

  const auto& customAttributesIter = headers.find("x-amzn-sagemaker-custom-attributes");
  if(customAttributesIter != headers.end())
  {
    m_customAttributes = customAttributesIter->second;
  }

  const auto& newSessionIdIter = headers.find("x-amzn-sagemaker-new-session-id");
  if(newSessionIdIter != headers.end())
  {
    m_newSessionId = newSessionIdIter->second;
  }

  const auto& closedSessionIdIter = headers.find("x-amzn-sagemaker-closed-session-id");
  if(closedSessionIdIter != headers.end())
  {
    m_closedSessionId = closedSessionIdIter->second;
  }

  const auto& requestIdIter = headers.find("x-amzn-requestid");
  if(requestIdIter != headers.end())
  {
    m_requestId = requestIdIter->second;
  }

   return *this;
}
