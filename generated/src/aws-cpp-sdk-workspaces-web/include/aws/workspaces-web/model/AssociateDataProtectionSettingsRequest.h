﻿/**
 * Copyright Amazon.com, Inc. or its affiliates. All Rights Reserved.
 * SPDX-License-Identifier: Apache-2.0.
 */

#pragma once
#include <aws/workspaces-web/WorkSpacesWeb_EXPORTS.h>
#include <aws/workspaces-web/WorkSpacesWebRequest.h>
#include <aws/core/utils/memory/stl/AWSString.h>
#include <utility>

namespace Aws
{
namespace Http
{
    class URI;
} //namespace Http
namespace WorkSpacesWeb
{
namespace Model
{

  /**
   */
  class AssociateDataProtectionSettingsRequest : public WorkSpacesWebRequest
  {
  public:
    AWS_WORKSPACESWEB_API AssociateDataProtectionSettingsRequest() = default;

    // Service request name is the Operation name which will send this request out,
    // each operation should has unique request name, so that we can get operation's name from this request.
    // Note: this is not true for response, multiple operations may have the same response name,
    // so we can not get operation's name from response.
    inline virtual const char* GetServiceRequestName() const override { return "AssociateDataProtectionSettings"; }

    AWS_WORKSPACESWEB_API Aws::String SerializePayload() const override;

    AWS_WORKSPACESWEB_API void AddQueryStringParameters(Aws::Http::URI& uri) const override;


    ///@{
    /**
     * <p>The ARN of the web portal.</p>
     */
    inline const Aws::String& GetPortalArn() const { return m_portalArn; }
    inline bool PortalArnHasBeenSet() const { return m_portalArnHasBeenSet; }
    template<typename PortalArnT = Aws::String>
    void SetPortalArn(PortalArnT&& value) { m_portalArnHasBeenSet = true; m_portalArn = std::forward<PortalArnT>(value); }
    template<typename PortalArnT = Aws::String>
    AssociateDataProtectionSettingsRequest& WithPortalArn(PortalArnT&& value) { SetPortalArn(std::forward<PortalArnT>(value)); return *this;}
    ///@}

    ///@{
    /**
     * <p>The ARN of the data protection settings.</p>
     */
    inline const Aws::String& GetDataProtectionSettingsArn() const { return m_dataProtectionSettingsArn; }
    inline bool DataProtectionSettingsArnHasBeenSet() const { return m_dataProtectionSettingsArnHasBeenSet; }
    template<typename DataProtectionSettingsArnT = Aws::String>
    void SetDataProtectionSettingsArn(DataProtectionSettingsArnT&& value) { m_dataProtectionSettingsArnHasBeenSet = true; m_dataProtectionSettingsArn = std::forward<DataProtectionSettingsArnT>(value); }
    template<typename DataProtectionSettingsArnT = Aws::String>
    AssociateDataProtectionSettingsRequest& WithDataProtectionSettingsArn(DataProtectionSettingsArnT&& value) { SetDataProtectionSettingsArn(std::forward<DataProtectionSettingsArnT>(value)); return *this;}
    ///@}
  private:

    Aws::String m_portalArn;
    bool m_portalArnHasBeenSet = false;

    Aws::String m_dataProtectionSettingsArn;
    bool m_dataProtectionSettingsArnHasBeenSet = false;
  };

} // namespace Model
} // namespace WorkSpacesWeb
} // namespace Aws
