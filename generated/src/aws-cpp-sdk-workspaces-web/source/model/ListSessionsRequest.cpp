﻿/**
 * Copyright Amazon.com, Inc. or its affiliates. All Rights Reserved.
 * SPDX-License-Identifier: Apache-2.0.
 */

#include <aws/workspaces-web/model/ListSessionsRequest.h>
#include <aws/core/utils/json/JsonSerializer.h>
#include <aws/core/http/URI.h>
#include <aws/core/utils/memory/stl/AWSStringStream.h>

#include <utility>

using namespace Aws::WorkSpacesWeb::Model;
using namespace Aws::Utils::Json;
using namespace Aws::Utils;
using namespace Aws::Http;

Aws::String ListSessionsRequest::SerializePayload() const
{
  return {};
}

void ListSessionsRequest::AddQueryStringParameters(URI& uri) const
{
    Aws::StringStream ss;
    if(m_usernameHasBeenSet)
    {
      ss << m_username;
      uri.AddQueryStringParameter("username", ss.str());
      ss.str("");
    }

    if(m_sessionIdHasBeenSet)
    {
      ss << m_sessionId;
      uri.AddQueryStringParameter("sessionId", ss.str());
      ss.str("");
    }

    if(m_sortByHasBeenSet)
    {
      ss << SessionSortByMapper::GetNameForSessionSortBy(m_sortBy);
      uri.AddQueryStringParameter("sortBy", ss.str());
      ss.str("");
    }

    if(m_statusHasBeenSet)
    {
      ss << SessionStatusMapper::GetNameForSessionStatus(m_status);
      uri.AddQueryStringParameter("status", ss.str());
      ss.str("");
    }

    if(m_maxResultsHasBeenSet)
    {
      ss << m_maxResults;
      uri.AddQueryStringParameter("maxResults", ss.str());
      ss.str("");
    }

    if(m_nextTokenHasBeenSet)
    {
      ss << m_nextToken;
      uri.AddQueryStringParameter("nextToken", ss.str());
      ss.str("");
    }

}



