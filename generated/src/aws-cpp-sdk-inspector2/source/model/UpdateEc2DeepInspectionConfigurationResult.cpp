﻿/**
 * Copyright Amazon.com, Inc. or its affiliates. All Rights Reserved.
 * SPDX-License-Identifier: Apache-2.0.
 */

#include <aws/inspector2/model/UpdateEc2DeepInspectionConfigurationResult.h>
#include <aws/core/utils/json/JsonSerializer.h>
#include <aws/core/AmazonWebServiceResult.h>
#include <aws/core/utils/StringUtils.h>
#include <aws/core/utils/UnreferencedParam.h>
#include <aws/core/utils/memory/stl/AWSStringStream.h>

#include <utility>

using namespace Aws::Inspector2::Model;
using namespace Aws::Utils::Json;
using namespace Aws::Utils;
using namespace Aws;

UpdateEc2DeepInspectionConfigurationResult::UpdateEc2DeepInspectionConfigurationResult(const Aws::AmazonWebServiceResult<JsonValue>& result)
{
  *this = result;
}

UpdateEc2DeepInspectionConfigurationResult& UpdateEc2DeepInspectionConfigurationResult::operator =(const Aws::AmazonWebServiceResult<JsonValue>& result)
{
  JsonView jsonValue = result.GetPayload().View();
  if(jsonValue.ValueExists("packagePaths"))
  {
    Aws::Utils::Array<JsonView> packagePathsJsonList = jsonValue.GetArray("packagePaths");
    for(unsigned packagePathsIndex = 0; packagePathsIndex < packagePathsJsonList.GetLength(); ++packagePathsIndex)
    {
      m_packagePaths.push_back(packagePathsJsonList[packagePathsIndex].AsString());
    }
    m_packagePathsHasBeenSet = true;
  }
  if(jsonValue.ValueExists("orgPackagePaths"))
  {
    Aws::Utils::Array<JsonView> orgPackagePathsJsonList = jsonValue.GetArray("orgPackagePaths");
    for(unsigned orgPackagePathsIndex = 0; orgPackagePathsIndex < orgPackagePathsJsonList.GetLength(); ++orgPackagePathsIndex)
    {
      m_orgPackagePaths.push_back(orgPackagePathsJsonList[orgPackagePathsIndex].AsString());
    }
    m_orgPackagePathsHasBeenSet = true;
  }
  if(jsonValue.ValueExists("status"))
  {
    m_status = Ec2DeepInspectionStatusMapper::GetEc2DeepInspectionStatusForName(jsonValue.GetString("status"));
    m_statusHasBeenSet = true;
  }
  if(jsonValue.ValueExists("errorMessage"))
  {
    m_errorMessage = jsonValue.GetString("errorMessage");
    m_errorMessageHasBeenSet = true;
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
