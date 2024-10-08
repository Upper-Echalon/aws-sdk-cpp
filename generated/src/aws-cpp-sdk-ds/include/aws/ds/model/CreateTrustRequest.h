﻿/**
 * Copyright Amazon.com, Inc. or its affiliates. All Rights Reserved.
 * SPDX-License-Identifier: Apache-2.0.
 */

#pragma once
#include <aws/ds/DirectoryService_EXPORTS.h>
#include <aws/ds/DirectoryServiceRequest.h>
#include <aws/core/utils/memory/stl/AWSString.h>
#include <aws/ds/model/TrustDirection.h>
#include <aws/ds/model/TrustType.h>
#include <aws/core/utils/memory/stl/AWSVector.h>
#include <aws/ds/model/SelectiveAuth.h>
#include <utility>

namespace Aws
{
namespace DirectoryService
{
namespace Model
{

  /**
   * <p>Directory Service for Microsoft Active Directory allows you to configure
   * trust relationships. For example, you can establish a trust between your Managed
   * Microsoft AD directory, and your existing self-managed Microsoft Active
   * Directory. This would allow you to provide users and groups access to resources
   * in either domain, with a single set of credentials.</p> <p>This action initiates
   * the creation of the Amazon Web Services side of a trust relationship between an
   * Managed Microsoft AD directory and an external domain.</p><p><h3>See Also:</h3> 
   * <a
   * href="http://docs.aws.amazon.com/goto/WebAPI/ds-2015-04-16/CreateTrustRequest">AWS
   * API Reference</a></p>
   */
  class CreateTrustRequest : public DirectoryServiceRequest
  {
  public:
    AWS_DIRECTORYSERVICE_API CreateTrustRequest();

    // Service request name is the Operation name which will send this request out,
    // each operation should has unique request name, so that we can get operation's name from this request.
    // Note: this is not true for response, multiple operations may have the same response name,
    // so we can not get operation's name from response.
    inline virtual const char* GetServiceRequestName() const override { return "CreateTrust"; }

    AWS_DIRECTORYSERVICE_API Aws::String SerializePayload() const override;

    AWS_DIRECTORYSERVICE_API Aws::Http::HeaderValueCollection GetRequestSpecificHeaders() const override;


    ///@{
    /**
     * <p>The Directory ID of the Managed Microsoft AD directory for which to establish
     * the trust relationship.</p>
     */
    inline const Aws::String& GetDirectoryId() const{ return m_directoryId; }
    inline bool DirectoryIdHasBeenSet() const { return m_directoryIdHasBeenSet; }
    inline void SetDirectoryId(const Aws::String& value) { m_directoryIdHasBeenSet = true; m_directoryId = value; }
    inline void SetDirectoryId(Aws::String&& value) { m_directoryIdHasBeenSet = true; m_directoryId = std::move(value); }
    inline void SetDirectoryId(const char* value) { m_directoryIdHasBeenSet = true; m_directoryId.assign(value); }
    inline CreateTrustRequest& WithDirectoryId(const Aws::String& value) { SetDirectoryId(value); return *this;}
    inline CreateTrustRequest& WithDirectoryId(Aws::String&& value) { SetDirectoryId(std::move(value)); return *this;}
    inline CreateTrustRequest& WithDirectoryId(const char* value) { SetDirectoryId(value); return *this;}
    ///@}

    ///@{
    /**
     * <p>The Fully Qualified Domain Name (FQDN) of the external domain for which to
     * create the trust relationship.</p>
     */
    inline const Aws::String& GetRemoteDomainName() const{ return m_remoteDomainName; }
    inline bool RemoteDomainNameHasBeenSet() const { return m_remoteDomainNameHasBeenSet; }
    inline void SetRemoteDomainName(const Aws::String& value) { m_remoteDomainNameHasBeenSet = true; m_remoteDomainName = value; }
    inline void SetRemoteDomainName(Aws::String&& value) { m_remoteDomainNameHasBeenSet = true; m_remoteDomainName = std::move(value); }
    inline void SetRemoteDomainName(const char* value) { m_remoteDomainNameHasBeenSet = true; m_remoteDomainName.assign(value); }
    inline CreateTrustRequest& WithRemoteDomainName(const Aws::String& value) { SetRemoteDomainName(value); return *this;}
    inline CreateTrustRequest& WithRemoteDomainName(Aws::String&& value) { SetRemoteDomainName(std::move(value)); return *this;}
    inline CreateTrustRequest& WithRemoteDomainName(const char* value) { SetRemoteDomainName(value); return *this;}
    ///@}

    ///@{
    /**
     * <p>The trust password. The trust password must be the same password that was
     * used when creating the trust relationship on the external domain.</p>
     */
    inline const Aws::String& GetTrustPassword() const{ return m_trustPassword; }
    inline bool TrustPasswordHasBeenSet() const { return m_trustPasswordHasBeenSet; }
    inline void SetTrustPassword(const Aws::String& value) { m_trustPasswordHasBeenSet = true; m_trustPassword = value; }
    inline void SetTrustPassword(Aws::String&& value) { m_trustPasswordHasBeenSet = true; m_trustPassword = std::move(value); }
    inline void SetTrustPassword(const char* value) { m_trustPasswordHasBeenSet = true; m_trustPassword.assign(value); }
    inline CreateTrustRequest& WithTrustPassword(const Aws::String& value) { SetTrustPassword(value); return *this;}
    inline CreateTrustRequest& WithTrustPassword(Aws::String&& value) { SetTrustPassword(std::move(value)); return *this;}
    inline CreateTrustRequest& WithTrustPassword(const char* value) { SetTrustPassword(value); return *this;}
    ///@}

    ///@{
    /**
     * <p>The direction of the trust relationship.</p>
     */
    inline const TrustDirection& GetTrustDirection() const{ return m_trustDirection; }
    inline bool TrustDirectionHasBeenSet() const { return m_trustDirectionHasBeenSet; }
    inline void SetTrustDirection(const TrustDirection& value) { m_trustDirectionHasBeenSet = true; m_trustDirection = value; }
    inline void SetTrustDirection(TrustDirection&& value) { m_trustDirectionHasBeenSet = true; m_trustDirection = std::move(value); }
    inline CreateTrustRequest& WithTrustDirection(const TrustDirection& value) { SetTrustDirection(value); return *this;}
    inline CreateTrustRequest& WithTrustDirection(TrustDirection&& value) { SetTrustDirection(std::move(value)); return *this;}
    ///@}

    ///@{
    /**
     * <p>The trust relationship type. <code>Forest</code> is the default.</p>
     */
    inline const TrustType& GetTrustType() const{ return m_trustType; }
    inline bool TrustTypeHasBeenSet() const { return m_trustTypeHasBeenSet; }
    inline void SetTrustType(const TrustType& value) { m_trustTypeHasBeenSet = true; m_trustType = value; }
    inline void SetTrustType(TrustType&& value) { m_trustTypeHasBeenSet = true; m_trustType = std::move(value); }
    inline CreateTrustRequest& WithTrustType(const TrustType& value) { SetTrustType(value); return *this;}
    inline CreateTrustRequest& WithTrustType(TrustType&& value) { SetTrustType(std::move(value)); return *this;}
    ///@}

    ///@{
    /**
     * <p>The IP addresses of the remote DNS server associated with
     * RemoteDomainName.</p>
     */
    inline const Aws::Vector<Aws::String>& GetConditionalForwarderIpAddrs() const{ return m_conditionalForwarderIpAddrs; }
    inline bool ConditionalForwarderIpAddrsHasBeenSet() const { return m_conditionalForwarderIpAddrsHasBeenSet; }
    inline void SetConditionalForwarderIpAddrs(const Aws::Vector<Aws::String>& value) { m_conditionalForwarderIpAddrsHasBeenSet = true; m_conditionalForwarderIpAddrs = value; }
    inline void SetConditionalForwarderIpAddrs(Aws::Vector<Aws::String>&& value) { m_conditionalForwarderIpAddrsHasBeenSet = true; m_conditionalForwarderIpAddrs = std::move(value); }
    inline CreateTrustRequest& WithConditionalForwarderIpAddrs(const Aws::Vector<Aws::String>& value) { SetConditionalForwarderIpAddrs(value); return *this;}
    inline CreateTrustRequest& WithConditionalForwarderIpAddrs(Aws::Vector<Aws::String>&& value) { SetConditionalForwarderIpAddrs(std::move(value)); return *this;}
    inline CreateTrustRequest& AddConditionalForwarderIpAddrs(const Aws::String& value) { m_conditionalForwarderIpAddrsHasBeenSet = true; m_conditionalForwarderIpAddrs.push_back(value); return *this; }
    inline CreateTrustRequest& AddConditionalForwarderIpAddrs(Aws::String&& value) { m_conditionalForwarderIpAddrsHasBeenSet = true; m_conditionalForwarderIpAddrs.push_back(std::move(value)); return *this; }
    inline CreateTrustRequest& AddConditionalForwarderIpAddrs(const char* value) { m_conditionalForwarderIpAddrsHasBeenSet = true; m_conditionalForwarderIpAddrs.push_back(value); return *this; }
    ///@}

    ///@{
    /**
     * <p>Optional parameter to enable selective authentication for the trust.</p>
     */
    inline const SelectiveAuth& GetSelectiveAuth() const{ return m_selectiveAuth; }
    inline bool SelectiveAuthHasBeenSet() const { return m_selectiveAuthHasBeenSet; }
    inline void SetSelectiveAuth(const SelectiveAuth& value) { m_selectiveAuthHasBeenSet = true; m_selectiveAuth = value; }
    inline void SetSelectiveAuth(SelectiveAuth&& value) { m_selectiveAuthHasBeenSet = true; m_selectiveAuth = std::move(value); }
    inline CreateTrustRequest& WithSelectiveAuth(const SelectiveAuth& value) { SetSelectiveAuth(value); return *this;}
    inline CreateTrustRequest& WithSelectiveAuth(SelectiveAuth&& value) { SetSelectiveAuth(std::move(value)); return *this;}
    ///@}
  private:

    Aws::String m_directoryId;
    bool m_directoryIdHasBeenSet = false;

    Aws::String m_remoteDomainName;
    bool m_remoteDomainNameHasBeenSet = false;

    Aws::String m_trustPassword;
    bool m_trustPasswordHasBeenSet = false;

    TrustDirection m_trustDirection;
    bool m_trustDirectionHasBeenSet = false;

    TrustType m_trustType;
    bool m_trustTypeHasBeenSet = false;

    Aws::Vector<Aws::String> m_conditionalForwarderIpAddrs;
    bool m_conditionalForwarderIpAddrsHasBeenSet = false;

    SelectiveAuth m_selectiveAuth;
    bool m_selectiveAuthHasBeenSet = false;
  };

} // namespace Model
} // namespace DirectoryService
} // namespace Aws
