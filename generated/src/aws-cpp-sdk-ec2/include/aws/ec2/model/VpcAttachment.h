﻿/**
 * Copyright Amazon.com, Inc. or its affiliates. All Rights Reserved.
 * SPDX-License-Identifier: Apache-2.0.
 */

#pragma once
#include <aws/ec2/EC2_EXPORTS.h>
#include <aws/core/utils/memory/stl/AWSStreamFwd.h>
#include <aws/core/utils/memory/stl/AWSString.h>
#include <aws/ec2/model/AttachmentStatus.h>
#include <utility>

namespace Aws
{
namespace Utils
{
namespace Xml
{
  class XmlNode;
} // namespace Xml
} // namespace Utils
namespace EC2
{
namespace Model
{

  /**
   * <p>Describes an attachment between a virtual private gateway and a
   * VPC.</p><p><h3>See Also:</h3>   <a
   * href="http://docs.aws.amazon.com/goto/WebAPI/ec2-2016-11-15/VpcAttachment">AWS
   * API Reference</a></p>
   */
  class VpcAttachment
  {
  public:
    AWS_EC2_API VpcAttachment();
    AWS_EC2_API VpcAttachment(const Aws::Utils::Xml::XmlNode& xmlNode);
    AWS_EC2_API VpcAttachment& operator=(const Aws::Utils::Xml::XmlNode& xmlNode);

    AWS_EC2_API void OutputToStream(Aws::OStream& ostream, const char* location, unsigned index, const char* locationValue) const;
    AWS_EC2_API void OutputToStream(Aws::OStream& oStream, const char* location) const;


    ///@{
    /**
     * <p>The ID of the VPC.</p>
     */
    inline const Aws::String& GetVpcId() const{ return m_vpcId; }
    inline bool VpcIdHasBeenSet() const { return m_vpcIdHasBeenSet; }
    inline void SetVpcId(const Aws::String& value) { m_vpcIdHasBeenSet = true; m_vpcId = value; }
    inline void SetVpcId(Aws::String&& value) { m_vpcIdHasBeenSet = true; m_vpcId = std::move(value); }
    inline void SetVpcId(const char* value) { m_vpcIdHasBeenSet = true; m_vpcId.assign(value); }
    inline VpcAttachment& WithVpcId(const Aws::String& value) { SetVpcId(value); return *this;}
    inline VpcAttachment& WithVpcId(Aws::String&& value) { SetVpcId(std::move(value)); return *this;}
    inline VpcAttachment& WithVpcId(const char* value) { SetVpcId(value); return *this;}
    ///@}

    ///@{
    /**
     * <p>The current state of the attachment.</p>
     */
    inline const AttachmentStatus& GetState() const{ return m_state; }
    inline bool StateHasBeenSet() const { return m_stateHasBeenSet; }
    inline void SetState(const AttachmentStatus& value) { m_stateHasBeenSet = true; m_state = value; }
    inline void SetState(AttachmentStatus&& value) { m_stateHasBeenSet = true; m_state = std::move(value); }
    inline VpcAttachment& WithState(const AttachmentStatus& value) { SetState(value); return *this;}
    inline VpcAttachment& WithState(AttachmentStatus&& value) { SetState(std::move(value)); return *this;}
    ///@}
  private:

    Aws::String m_vpcId;
    bool m_vpcIdHasBeenSet = false;

    AttachmentStatus m_state;
    bool m_stateHasBeenSet = false;
  };

} // namespace Model
} // namespace EC2
} // namespace Aws
