﻿/**
 * Copyright Amazon.com, Inc. or its affiliates. All Rights Reserved.
 * SPDX-License-Identifier: Apache-2.0.
 */

#include <aws/quicksight/model/RestoreAnalysisResult.h>
#include <aws/core/utils/json/JsonSerializer.h>
#include <aws/core/AmazonWebServiceResult.h>
#include <aws/core/utils/StringUtils.h>
#include <aws/core/utils/UnreferencedParam.h>
#include <aws/core/utils/memory/stl/AWSStringStream.h>

#include <utility>

using namespace Aws::QuickSight::Model;
using namespace Aws::Utils::Json;
using namespace Aws::Utils;
using namespace Aws;

RestoreAnalysisResult::RestoreAnalysisResult() : 
    m_status(0)
{
}

RestoreAnalysisResult::RestoreAnalysisResult(const Aws::AmazonWebServiceResult<JsonValue>& result)
  : RestoreAnalysisResult()
{
  *this = result;
}

RestoreAnalysisResult& RestoreAnalysisResult::operator =(const Aws::AmazonWebServiceResult<JsonValue>& result)
{
  JsonView jsonValue = result.GetPayload().View();
  if(jsonValue.ValueExists("Arn"))
  {
    m_arn = jsonValue.GetString("Arn");

  }

  if(jsonValue.ValueExists("AnalysisId"))
  {
    m_analysisId = jsonValue.GetString("AnalysisId");

  }

  if(jsonValue.ValueExists("RestorationFailedFolderArns"))
  {
    Aws::Utils::Array<JsonView> restorationFailedFolderArnsJsonList = jsonValue.GetArray("RestorationFailedFolderArns");
    for(unsigned restorationFailedFolderArnsIndex = 0; restorationFailedFolderArnsIndex < restorationFailedFolderArnsJsonList.GetLength(); ++restorationFailedFolderArnsIndex)
    {
      m_restorationFailedFolderArns.push_back(restorationFailedFolderArnsJsonList[restorationFailedFolderArnsIndex].AsString());
    }
  }


  const auto& headers = result.GetHeaderValueCollection();
  const auto& requestIdIter = headers.find("x-amzn-requestid");
  if(requestIdIter != headers.end())
  {
    m_requestId = requestIdIter->second;
  }


  m_status = static_cast<int>(result.GetResponseCode());

  return *this;
}
