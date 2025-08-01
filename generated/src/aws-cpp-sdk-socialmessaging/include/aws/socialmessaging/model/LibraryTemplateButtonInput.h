﻿/**
 * Copyright Amazon.com, Inc. or its affiliates. All Rights Reserved.
 * SPDX-License-Identifier: Apache-2.0.
 */

#pragma once
#include <aws/socialmessaging/SocialMessaging_EXPORTS.h>
#include <aws/core/utils/memory/stl/AWSString.h>
#include <aws/core/utils/memory/stl/AWSMap.h>
#include <aws/core/utils/memory/stl/AWSVector.h>
#include <utility>

namespace Aws
{
namespace Utils
{
namespace Json
{
  class JsonValue;
  class JsonView;
} // namespace Json
} // namespace Utils
namespace SocialMessaging
{
namespace Model
{

  /**
   * <p>Configuration options for customizing buttons in a template from Meta's
   * library.</p><p><h3>See Also:</h3>   <a
   * href="http://docs.aws.amazon.com/goto/WebAPI/socialmessaging-2024-01-01/LibraryTemplateButtonInput">AWS
   * API Reference</a></p>
   */
  class LibraryTemplateButtonInput
  {
  public:
    AWS_SOCIALMESSAGING_API LibraryTemplateButtonInput() = default;
    AWS_SOCIALMESSAGING_API LibraryTemplateButtonInput(Aws::Utils::Json::JsonView jsonValue);
    AWS_SOCIALMESSAGING_API LibraryTemplateButtonInput& operator=(Aws::Utils::Json::JsonView jsonValue);
    AWS_SOCIALMESSAGING_API Aws::Utils::Json::JsonValue Jsonize() const;


    ///@{
    /**
     * <p>The type of button (for example, QUICK_REPLY, CALL, or URL).</p>
     */
    inline const Aws::String& GetType() const { return m_type; }
    inline bool TypeHasBeenSet() const { return m_typeHasBeenSet; }
    template<typename TypeT = Aws::String>
    void SetType(TypeT&& value) { m_typeHasBeenSet = true; m_type = std::forward<TypeT>(value); }
    template<typename TypeT = Aws::String>
    LibraryTemplateButtonInput& WithType(TypeT&& value) { SetType(std::forward<TypeT>(value)); return *this;}
    ///@}

    ///@{
    /**
     * <p>The phone number in E.164 format for CALL-type buttons.</p>
     */
    inline const Aws::String& GetPhoneNumber() const { return m_phoneNumber; }
    inline bool PhoneNumberHasBeenSet() const { return m_phoneNumberHasBeenSet; }
    template<typename PhoneNumberT = Aws::String>
    void SetPhoneNumber(PhoneNumberT&& value) { m_phoneNumberHasBeenSet = true; m_phoneNumber = std::forward<PhoneNumberT>(value); }
    template<typename PhoneNumberT = Aws::String>
    LibraryTemplateButtonInput& WithPhoneNumber(PhoneNumberT&& value) { SetPhoneNumber(std::forward<PhoneNumberT>(value)); return *this;}
    ///@}

    ///@{
    /**
     * <p>The URL with dynamic parameters for URL-type buttons.</p>
     */
    inline const Aws::Map<Aws::String, Aws::String>& GetUrl() const { return m_url; }
    inline bool UrlHasBeenSet() const { return m_urlHasBeenSet; }
    template<typename UrlT = Aws::Map<Aws::String, Aws::String>>
    void SetUrl(UrlT&& value) { m_urlHasBeenSet = true; m_url = std::forward<UrlT>(value); }
    template<typename UrlT = Aws::Map<Aws::String, Aws::String>>
    LibraryTemplateButtonInput& WithUrl(UrlT&& value) { SetUrl(std::forward<UrlT>(value)); return *this;}
    template<typename UrlKeyT = Aws::String, typename UrlValueT = Aws::String>
    LibraryTemplateButtonInput& AddUrl(UrlKeyT&& key, UrlValueT&& value) {
      m_urlHasBeenSet = true; m_url.emplace(std::forward<UrlKeyT>(key), std::forward<UrlValueT>(value)); return *this;
    }
    ///@}

    ///@{
    /**
     * <p>The type of one-time password for OTP buttons.</p>
     */
    inline const Aws::String& GetOtpType() const { return m_otpType; }
    inline bool OtpTypeHasBeenSet() const { return m_otpTypeHasBeenSet; }
    template<typename OtpTypeT = Aws::String>
    void SetOtpType(OtpTypeT&& value) { m_otpTypeHasBeenSet = true; m_otpType = std::forward<OtpTypeT>(value); }
    template<typename OtpTypeT = Aws::String>
    LibraryTemplateButtonInput& WithOtpType(OtpTypeT&& value) { SetOtpType(std::forward<OtpTypeT>(value)); return *this;}
    ///@}

    ///@{
    /**
     * <p>When true, indicates acceptance of zero-tap terms for the button.</p>
     */
    inline bool GetZeroTapTermsAccepted() const { return m_zeroTapTermsAccepted; }
    inline bool ZeroTapTermsAcceptedHasBeenSet() const { return m_zeroTapTermsAcceptedHasBeenSet; }
    inline void SetZeroTapTermsAccepted(bool value) { m_zeroTapTermsAcceptedHasBeenSet = true; m_zeroTapTermsAccepted = value; }
    inline LibraryTemplateButtonInput& WithZeroTapTermsAccepted(bool value) { SetZeroTapTermsAccepted(value); return *this;}
    ///@}

    ///@{
    /**
     * <p>List of supported applications for this button type.</p>
     */
    inline const Aws::Vector<Aws::Map<Aws::String, Aws::String>>& GetSupportedApps() const { return m_supportedApps; }
    inline bool SupportedAppsHasBeenSet() const { return m_supportedAppsHasBeenSet; }
    template<typename SupportedAppsT = Aws::Vector<Aws::Map<Aws::String, Aws::String>>>
    void SetSupportedApps(SupportedAppsT&& value) { m_supportedAppsHasBeenSet = true; m_supportedApps = std::forward<SupportedAppsT>(value); }
    template<typename SupportedAppsT = Aws::Vector<Aws::Map<Aws::String, Aws::String>>>
    LibraryTemplateButtonInput& WithSupportedApps(SupportedAppsT&& value) { SetSupportedApps(std::forward<SupportedAppsT>(value)); return *this;}
    template<typename SupportedAppsT = Aws::Map<Aws::String, Aws::String>>
    LibraryTemplateButtonInput& AddSupportedApps(SupportedAppsT&& value) { m_supportedAppsHasBeenSet = true; m_supportedApps.emplace_back(std::forward<SupportedAppsT>(value)); return *this; }
    ///@}
  private:

    Aws::String m_type;
    bool m_typeHasBeenSet = false;

    Aws::String m_phoneNumber;
    bool m_phoneNumberHasBeenSet = false;

    Aws::Map<Aws::String, Aws::String> m_url;
    bool m_urlHasBeenSet = false;

    Aws::String m_otpType;
    bool m_otpTypeHasBeenSet = false;

    bool m_zeroTapTermsAccepted{false};
    bool m_zeroTapTermsAcceptedHasBeenSet = false;

    Aws::Vector<Aws::Map<Aws::String, Aws::String>> m_supportedApps;
    bool m_supportedAppsHasBeenSet = false;
  };

} // namespace Model
} // namespace SocialMessaging
} // namespace Aws
