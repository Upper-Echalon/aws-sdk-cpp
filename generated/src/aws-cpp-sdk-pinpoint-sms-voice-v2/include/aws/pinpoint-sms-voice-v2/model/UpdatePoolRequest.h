﻿/**
 * Copyright Amazon.com, Inc. or its affiliates. All Rights Reserved.
 * SPDX-License-Identifier: Apache-2.0.
 */

#pragma once
#include <aws/pinpoint-sms-voice-v2/PinpointSMSVoiceV2_EXPORTS.h>
#include <aws/pinpoint-sms-voice-v2/PinpointSMSVoiceV2Request.h>
#include <aws/core/utils/memory/stl/AWSString.h>
#include <utility>

namespace Aws
{
namespace PinpointSMSVoiceV2
{
namespace Model
{

  /**
   */
  class UpdatePoolRequest : public PinpointSMSVoiceV2Request
  {
  public:
    AWS_PINPOINTSMSVOICEV2_API UpdatePoolRequest();

    // Service request name is the Operation name which will send this request out,
    // each operation should has unique request name, so that we can get operation's name from this request.
    // Note: this is not true for response, multiple operations may have the same response name,
    // so we can not get operation's name from response.
    inline virtual const char* GetServiceRequestName() const override { return "UpdatePool"; }

    AWS_PINPOINTSMSVOICEV2_API Aws::String SerializePayload() const override;

    AWS_PINPOINTSMSVOICEV2_API Aws::Http::HeaderValueCollection GetRequestSpecificHeaders() const override;


    ///@{
    /**
     * <p>The unique identifier of the pool to update. Valid values are either the
     * PoolId or PoolArn.</p>  <p>If you are using a shared AWS End User
     * Messaging SMS and Voice resource then you must use the full Amazon Resource
     * Name(ARN).</p> 
     */
    inline const Aws::String& GetPoolId() const{ return m_poolId; }
    inline bool PoolIdHasBeenSet() const { return m_poolIdHasBeenSet; }
    inline void SetPoolId(const Aws::String& value) { m_poolIdHasBeenSet = true; m_poolId = value; }
    inline void SetPoolId(Aws::String&& value) { m_poolIdHasBeenSet = true; m_poolId = std::move(value); }
    inline void SetPoolId(const char* value) { m_poolIdHasBeenSet = true; m_poolId.assign(value); }
    inline UpdatePoolRequest& WithPoolId(const Aws::String& value) { SetPoolId(value); return *this;}
    inline UpdatePoolRequest& WithPoolId(Aws::String&& value) { SetPoolId(std::move(value)); return *this;}
    inline UpdatePoolRequest& WithPoolId(const char* value) { SetPoolId(value); return *this;}
    ///@}

    ///@{
    /**
     * <p>By default this is set to false. When set to true you can receive incoming
     * text messages from your end recipients.</p>
     */
    inline bool GetTwoWayEnabled() const{ return m_twoWayEnabled; }
    inline bool TwoWayEnabledHasBeenSet() const { return m_twoWayEnabledHasBeenSet; }
    inline void SetTwoWayEnabled(bool value) { m_twoWayEnabledHasBeenSet = true; m_twoWayEnabled = value; }
    inline UpdatePoolRequest& WithTwoWayEnabled(bool value) { SetTwoWayEnabled(value); return *this;}
    ///@}

    ///@{
    /**
     * <p>The Amazon Resource Name (ARN) of the two way channel.</p>
     */
    inline const Aws::String& GetTwoWayChannelArn() const{ return m_twoWayChannelArn; }
    inline bool TwoWayChannelArnHasBeenSet() const { return m_twoWayChannelArnHasBeenSet; }
    inline void SetTwoWayChannelArn(const Aws::String& value) { m_twoWayChannelArnHasBeenSet = true; m_twoWayChannelArn = value; }
    inline void SetTwoWayChannelArn(Aws::String&& value) { m_twoWayChannelArnHasBeenSet = true; m_twoWayChannelArn = std::move(value); }
    inline void SetTwoWayChannelArn(const char* value) { m_twoWayChannelArnHasBeenSet = true; m_twoWayChannelArn.assign(value); }
    inline UpdatePoolRequest& WithTwoWayChannelArn(const Aws::String& value) { SetTwoWayChannelArn(value); return *this;}
    inline UpdatePoolRequest& WithTwoWayChannelArn(Aws::String&& value) { SetTwoWayChannelArn(std::move(value)); return *this;}
    inline UpdatePoolRequest& WithTwoWayChannelArn(const char* value) { SetTwoWayChannelArn(value); return *this;}
    ///@}

    ///@{
    /**
     * <p>An optional IAM Role Arn for a service to assume, to be able to post inbound
     * SMS messages.</p>
     */
    inline const Aws::String& GetTwoWayChannelRole() const{ return m_twoWayChannelRole; }
    inline bool TwoWayChannelRoleHasBeenSet() const { return m_twoWayChannelRoleHasBeenSet; }
    inline void SetTwoWayChannelRole(const Aws::String& value) { m_twoWayChannelRoleHasBeenSet = true; m_twoWayChannelRole = value; }
    inline void SetTwoWayChannelRole(Aws::String&& value) { m_twoWayChannelRoleHasBeenSet = true; m_twoWayChannelRole = std::move(value); }
    inline void SetTwoWayChannelRole(const char* value) { m_twoWayChannelRoleHasBeenSet = true; m_twoWayChannelRole.assign(value); }
    inline UpdatePoolRequest& WithTwoWayChannelRole(const Aws::String& value) { SetTwoWayChannelRole(value); return *this;}
    inline UpdatePoolRequest& WithTwoWayChannelRole(Aws::String&& value) { SetTwoWayChannelRole(std::move(value)); return *this;}
    inline UpdatePoolRequest& WithTwoWayChannelRole(const char* value) { SetTwoWayChannelRole(value); return *this;}
    ///@}

    ///@{
    /**
     * <p>By default this is set to false. When an end recipient sends a message that
     * begins with HELP or STOP to one of your dedicated numbers, AWS End User
     * Messaging SMS and Voice automatically replies with a customizable message and
     * adds the end recipient to the OptOutList. When set to true you're responsible
     * for responding to HELP and STOP requests. You're also responsible for tracking
     * and honoring opt-out requests.</p>
     */
    inline bool GetSelfManagedOptOutsEnabled() const{ return m_selfManagedOptOutsEnabled; }
    inline bool SelfManagedOptOutsEnabledHasBeenSet() const { return m_selfManagedOptOutsEnabledHasBeenSet; }
    inline void SetSelfManagedOptOutsEnabled(bool value) { m_selfManagedOptOutsEnabledHasBeenSet = true; m_selfManagedOptOutsEnabled = value; }
    inline UpdatePoolRequest& WithSelfManagedOptOutsEnabled(bool value) { SetSelfManagedOptOutsEnabled(value); return *this;}
    ///@}

    ///@{
    /**
     * <p>The OptOutList to associate with the pool. Valid values are either
     * OptOutListName or OptOutListArn.</p>  <p>If you are using a shared
     * AWS End User Messaging SMS and Voice resource then you must use the full Amazon
     * Resource Name(ARN).</p> 
     */
    inline const Aws::String& GetOptOutListName() const{ return m_optOutListName; }
    inline bool OptOutListNameHasBeenSet() const { return m_optOutListNameHasBeenSet; }
    inline void SetOptOutListName(const Aws::String& value) { m_optOutListNameHasBeenSet = true; m_optOutListName = value; }
    inline void SetOptOutListName(Aws::String&& value) { m_optOutListNameHasBeenSet = true; m_optOutListName = std::move(value); }
    inline void SetOptOutListName(const char* value) { m_optOutListNameHasBeenSet = true; m_optOutListName.assign(value); }
    inline UpdatePoolRequest& WithOptOutListName(const Aws::String& value) { SetOptOutListName(value); return *this;}
    inline UpdatePoolRequest& WithOptOutListName(Aws::String&& value) { SetOptOutListName(std::move(value)); return *this;}
    inline UpdatePoolRequest& WithOptOutListName(const char* value) { SetOptOutListName(value); return *this;}
    ///@}

    ///@{
    /**
     * <p>Indicates whether shared routes are enabled for the pool.</p>
     */
    inline bool GetSharedRoutesEnabled() const{ return m_sharedRoutesEnabled; }
    inline bool SharedRoutesEnabledHasBeenSet() const { return m_sharedRoutesEnabledHasBeenSet; }
    inline void SetSharedRoutesEnabled(bool value) { m_sharedRoutesEnabledHasBeenSet = true; m_sharedRoutesEnabled = value; }
    inline UpdatePoolRequest& WithSharedRoutesEnabled(bool value) { SetSharedRoutesEnabled(value); return *this;}
    ///@}

    ///@{
    /**
     * <p>When set to true the pool can't be deleted.</p>
     */
    inline bool GetDeletionProtectionEnabled() const{ return m_deletionProtectionEnabled; }
    inline bool DeletionProtectionEnabledHasBeenSet() const { return m_deletionProtectionEnabledHasBeenSet; }
    inline void SetDeletionProtectionEnabled(bool value) { m_deletionProtectionEnabledHasBeenSet = true; m_deletionProtectionEnabled = value; }
    inline UpdatePoolRequest& WithDeletionProtectionEnabled(bool value) { SetDeletionProtectionEnabled(value); return *this;}
    ///@}
  private:

    Aws::String m_poolId;
    bool m_poolIdHasBeenSet = false;

    bool m_twoWayEnabled;
    bool m_twoWayEnabledHasBeenSet = false;

    Aws::String m_twoWayChannelArn;
    bool m_twoWayChannelArnHasBeenSet = false;

    Aws::String m_twoWayChannelRole;
    bool m_twoWayChannelRoleHasBeenSet = false;

    bool m_selfManagedOptOutsEnabled;
    bool m_selfManagedOptOutsEnabledHasBeenSet = false;

    Aws::String m_optOutListName;
    bool m_optOutListNameHasBeenSet = false;

    bool m_sharedRoutesEnabled;
    bool m_sharedRoutesEnabledHasBeenSet = false;

    bool m_deletionProtectionEnabled;
    bool m_deletionProtectionEnabledHasBeenSet = false;
  };

} // namespace Model
} // namespace PinpointSMSVoiceV2
} // namespace Aws
