﻿/**
 * Copyright Amazon.com, Inc. or its affiliates. All Rights Reserved.
 * SPDX-License-Identifier: Apache-2.0.
 */

#pragma once
#include <aws/elasticloadbalancingv2/ElasticLoadBalancingv2_EXPORTS.h>
#include <aws/core/utils/memory/stl/AWSVector.h>
#include <aws/elasticloadbalancingv2/model/ResponseMetadata.h>
#include <aws/elasticloadbalancingv2/model/TargetGroupAttribute.h>
#include <utility>

namespace Aws
{
template<typename RESULT_TYPE>
class AmazonWebServiceResult;

namespace Utils
{
namespace Xml
{
  class XmlDocument;
} // namespace Xml
} // namespace Utils
namespace ElasticLoadBalancingv2
{
namespace Model
{
  class ModifyTargetGroupAttributesResult
  {
  public:
    AWS_ELASTICLOADBALANCINGV2_API ModifyTargetGroupAttributesResult();
    AWS_ELASTICLOADBALANCINGV2_API ModifyTargetGroupAttributesResult(const Aws::AmazonWebServiceResult<Aws::Utils::Xml::XmlDocument>& result);
    AWS_ELASTICLOADBALANCINGV2_API ModifyTargetGroupAttributesResult& operator=(const Aws::AmazonWebServiceResult<Aws::Utils::Xml::XmlDocument>& result);


    ///@{
    /**
     * <p>Information about the target group attributes.</p>
     */
    inline const Aws::Vector<TargetGroupAttribute>& GetAttributes() const{ return m_attributes; }
    inline void SetAttributes(const Aws::Vector<TargetGroupAttribute>& value) { m_attributes = value; }
    inline void SetAttributes(Aws::Vector<TargetGroupAttribute>&& value) { m_attributes = std::move(value); }
    inline ModifyTargetGroupAttributesResult& WithAttributes(const Aws::Vector<TargetGroupAttribute>& value) { SetAttributes(value); return *this;}
    inline ModifyTargetGroupAttributesResult& WithAttributes(Aws::Vector<TargetGroupAttribute>&& value) { SetAttributes(std::move(value)); return *this;}
    inline ModifyTargetGroupAttributesResult& AddAttributes(const TargetGroupAttribute& value) { m_attributes.push_back(value); return *this; }
    inline ModifyTargetGroupAttributesResult& AddAttributes(TargetGroupAttribute&& value) { m_attributes.push_back(std::move(value)); return *this; }
    ///@}

    ///@{
    
    inline const ResponseMetadata& GetResponseMetadata() const{ return m_responseMetadata; }
    inline void SetResponseMetadata(const ResponseMetadata& value) { m_responseMetadata = value; }
    inline void SetResponseMetadata(ResponseMetadata&& value) { m_responseMetadata = std::move(value); }
    inline ModifyTargetGroupAttributesResult& WithResponseMetadata(const ResponseMetadata& value) { SetResponseMetadata(value); return *this;}
    inline ModifyTargetGroupAttributesResult& WithResponseMetadata(ResponseMetadata&& value) { SetResponseMetadata(std::move(value)); return *this;}
    ///@}
  private:

    Aws::Vector<TargetGroupAttribute> m_attributes;

    ResponseMetadata m_responseMetadata;
  };

} // namespace Model
} // namespace ElasticLoadBalancingv2
} // namespace Aws
