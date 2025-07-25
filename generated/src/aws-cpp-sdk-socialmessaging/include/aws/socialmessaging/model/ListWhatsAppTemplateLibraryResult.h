﻿/**
 * Copyright Amazon.com, Inc. or its affiliates. All Rights Reserved.
 * SPDX-License-Identifier: Apache-2.0.
 */

#pragma once
#include <aws/socialmessaging/SocialMessaging_EXPORTS.h>
#include <aws/core/utils/memory/stl/AWSVector.h>
#include <aws/core/utils/memory/stl/AWSString.h>
#include <aws/socialmessaging/model/MetaLibraryTemplateDefinition.h>
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
namespace SocialMessaging
{
namespace Model
{
  class ListWhatsAppTemplateLibraryResult
  {
  public:
    AWS_SOCIALMESSAGING_API ListWhatsAppTemplateLibraryResult() = default;
    AWS_SOCIALMESSAGING_API ListWhatsAppTemplateLibraryResult(const Aws::AmazonWebServiceResult<Aws::Utils::Json::JsonValue>& result);
    AWS_SOCIALMESSAGING_API ListWhatsAppTemplateLibraryResult& operator=(const Aws::AmazonWebServiceResult<Aws::Utils::Json::JsonValue>& result);


    ///@{
    /**
     * <p>A list of templates from Meta's library.</p>
     */
    inline const Aws::Vector<MetaLibraryTemplateDefinition>& GetMetaLibraryTemplates() const { return m_metaLibraryTemplates; }
    template<typename MetaLibraryTemplatesT = Aws::Vector<MetaLibraryTemplateDefinition>>
    void SetMetaLibraryTemplates(MetaLibraryTemplatesT&& value) { m_metaLibraryTemplatesHasBeenSet = true; m_metaLibraryTemplates = std::forward<MetaLibraryTemplatesT>(value); }
    template<typename MetaLibraryTemplatesT = Aws::Vector<MetaLibraryTemplateDefinition>>
    ListWhatsAppTemplateLibraryResult& WithMetaLibraryTemplates(MetaLibraryTemplatesT&& value) { SetMetaLibraryTemplates(std::forward<MetaLibraryTemplatesT>(value)); return *this;}
    template<typename MetaLibraryTemplatesT = MetaLibraryTemplateDefinition>
    ListWhatsAppTemplateLibraryResult& AddMetaLibraryTemplates(MetaLibraryTemplatesT&& value) { m_metaLibraryTemplatesHasBeenSet = true; m_metaLibraryTemplates.emplace_back(std::forward<MetaLibraryTemplatesT>(value)); return *this; }
    ///@}

    ///@{
    /**
     * <p>The token to retrieve the next page of results, if any.</p>
     */
    inline const Aws::String& GetNextToken() const { return m_nextToken; }
    template<typename NextTokenT = Aws::String>
    void SetNextToken(NextTokenT&& value) { m_nextTokenHasBeenSet = true; m_nextToken = std::forward<NextTokenT>(value); }
    template<typename NextTokenT = Aws::String>
    ListWhatsAppTemplateLibraryResult& WithNextToken(NextTokenT&& value) { SetNextToken(std::forward<NextTokenT>(value)); return *this;}
    ///@}

    ///@{
    
    inline const Aws::String& GetRequestId() const { return m_requestId; }
    template<typename RequestIdT = Aws::String>
    void SetRequestId(RequestIdT&& value) { m_requestIdHasBeenSet = true; m_requestId = std::forward<RequestIdT>(value); }
    template<typename RequestIdT = Aws::String>
    ListWhatsAppTemplateLibraryResult& WithRequestId(RequestIdT&& value) { SetRequestId(std::forward<RequestIdT>(value)); return *this;}
    ///@}
  private:

    Aws::Vector<MetaLibraryTemplateDefinition> m_metaLibraryTemplates;
    bool m_metaLibraryTemplatesHasBeenSet = false;

    Aws::String m_nextToken;
    bool m_nextTokenHasBeenSet = false;

    Aws::String m_requestId;
    bool m_requestIdHasBeenSet = false;
  };

} // namespace Model
} // namespace SocialMessaging
} // namespace Aws
