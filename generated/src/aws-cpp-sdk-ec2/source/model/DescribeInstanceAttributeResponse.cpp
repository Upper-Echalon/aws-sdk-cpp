﻿/**
 * Copyright Amazon.com, Inc. or its affiliates. All Rights Reserved.
 * SPDX-License-Identifier: Apache-2.0.
 */

#include <aws/ec2/model/DescribeInstanceAttributeResponse.h>
#include <aws/core/utils/xml/XmlSerializer.h>
#include <aws/core/AmazonWebServiceResult.h>
#include <aws/core/utils/StringUtils.h>
#include <aws/core/utils/logging/LogMacros.h>

#include <utility>

using namespace Aws::EC2::Model;
using namespace Aws::Utils::Xml;
using namespace Aws::Utils::Logging;
using namespace Aws::Utils;
using namespace Aws;

DescribeInstanceAttributeResponse::DescribeInstanceAttributeResponse()
{
}

DescribeInstanceAttributeResponse::DescribeInstanceAttributeResponse(const Aws::AmazonWebServiceResult<XmlDocument>& result)
{
  *this = result;
}

DescribeInstanceAttributeResponse& DescribeInstanceAttributeResponse::operator =(const Aws::AmazonWebServiceResult<XmlDocument>& result)
{
  const XmlDocument& xmlDocument = result.GetPayload();
  XmlNode rootNode = xmlDocument.GetRootElement();
  XmlNode resultNode = rootNode;
  if (!rootNode.IsNull() && (rootNode.GetName() != "DescribeInstanceAttributeResponse"))
  {
    resultNode = rootNode.FirstChild("DescribeInstanceAttributeResponse");
  }

  if(!resultNode.IsNull())
  {
    XmlNode blockDeviceMappingsNode = resultNode.FirstChild("blockDeviceMapping");
    if(!blockDeviceMappingsNode.IsNull())
    {
      XmlNode blockDeviceMappingsMember = blockDeviceMappingsNode.FirstChild("item");
      while(!blockDeviceMappingsMember.IsNull())
      {
        m_blockDeviceMappings.push_back(blockDeviceMappingsMember);
        blockDeviceMappingsMember = blockDeviceMappingsMember.NextNode("item");
      }

    }
    XmlNode disableApiTerminationNode = resultNode.FirstChild("disableApiTermination");
    if(!disableApiTerminationNode.IsNull())
    {
      m_disableApiTermination = disableApiTerminationNode;
    }
    XmlNode enaSupportNode = resultNode.FirstChild("enaSupport");
    if(!enaSupportNode.IsNull())
    {
      m_enaSupport = enaSupportNode;
    }
    XmlNode enclaveOptionsNode = resultNode.FirstChild("enclaveOptions");
    if(!enclaveOptionsNode.IsNull())
    {
      m_enclaveOptions = enclaveOptionsNode;
    }
    XmlNode ebsOptimizedNode = resultNode.FirstChild("ebsOptimized");
    if(!ebsOptimizedNode.IsNull())
    {
      m_ebsOptimized = ebsOptimizedNode;
    }
    XmlNode instanceIdNode = resultNode.FirstChild("instanceId");
    if(!instanceIdNode.IsNull())
    {
      m_instanceId = Aws::Utils::Xml::DecodeEscapedXmlText(instanceIdNode.GetText());
    }
    XmlNode instanceInitiatedShutdownBehaviorNode = resultNode.FirstChild("instanceInitiatedShutdownBehavior");
    if(!instanceInitiatedShutdownBehaviorNode.IsNull())
    {
      m_instanceInitiatedShutdownBehavior = instanceInitiatedShutdownBehaviorNode;
    }
    XmlNode instanceTypeNode = resultNode.FirstChild("instanceType");
    if(!instanceTypeNode.IsNull())
    {
      m_instanceType = instanceTypeNode;
    }
    XmlNode kernelIdNode = resultNode.FirstChild("kernel");
    if(!kernelIdNode.IsNull())
    {
      m_kernelId = kernelIdNode;
    }
    XmlNode productCodesNode = resultNode.FirstChild("productCodes");
    if(!productCodesNode.IsNull())
    {
      XmlNode productCodesMember = productCodesNode.FirstChild("item");
      while(!productCodesMember.IsNull())
      {
        m_productCodes.push_back(productCodesMember);
        productCodesMember = productCodesMember.NextNode("item");
      }

    }
    XmlNode ramdiskIdNode = resultNode.FirstChild("ramdisk");
    if(!ramdiskIdNode.IsNull())
    {
      m_ramdiskId = ramdiskIdNode;
    }
    XmlNode rootDeviceNameNode = resultNode.FirstChild("rootDeviceName");
    if(!rootDeviceNameNode.IsNull())
    {
      m_rootDeviceName = rootDeviceNameNode;
    }
    XmlNode sourceDestCheckNode = resultNode.FirstChild("sourceDestCheck");
    if(!sourceDestCheckNode.IsNull())
    {
      m_sourceDestCheck = sourceDestCheckNode;
    }
    XmlNode sriovNetSupportNode = resultNode.FirstChild("sriovNetSupport");
    if(!sriovNetSupportNode.IsNull())
    {
      m_sriovNetSupport = sriovNetSupportNode;
    }
    XmlNode userDataNode = resultNode.FirstChild("userData");
    if(!userDataNode.IsNull())
    {
      m_userData = userDataNode;
    }
    XmlNode disableApiStopNode = resultNode.FirstChild("disableApiStop");
    if(!disableApiStopNode.IsNull())
    {
      m_disableApiStop = disableApiStopNode;
    }
    XmlNode groupsNode = resultNode.FirstChild("groupSet");
    if(!groupsNode.IsNull())
    {
      XmlNode groupsMember = groupsNode.FirstChild("item");
      while(!groupsMember.IsNull())
      {
        m_groups.push_back(groupsMember);
        groupsMember = groupsMember.NextNode("item");
      }

    }
  }

  if (!rootNode.IsNull()) {
    XmlNode requestIdNode = rootNode.FirstChild("requestId");
    if (!requestIdNode.IsNull())
    {
      m_responseMetadata.SetRequestId(StringUtils::Trim(requestIdNode.GetText().c_str()));
    }
    AWS_LOGSTREAM_DEBUG("Aws::EC2::Model::DescribeInstanceAttributeResponse", "x-amzn-request-id: " << m_responseMetadata.GetRequestId() );
  }
  return *this;
}
