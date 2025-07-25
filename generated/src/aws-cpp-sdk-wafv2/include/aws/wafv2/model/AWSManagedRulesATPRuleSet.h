﻿/**
 * Copyright Amazon.com, Inc. or its affiliates. All Rights Reserved.
 * SPDX-License-Identifier: Apache-2.0.
 */

#pragma once
#include <aws/wafv2/WAFV2_EXPORTS.h>
#include <aws/core/utils/memory/stl/AWSString.h>
#include <aws/wafv2/model/RequestInspection.h>
#include <aws/wafv2/model/ResponseInspection.h>
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
namespace WAFV2
{
namespace Model
{

  /**
   * <p>Details for your use of the account takeover prevention managed rule group,
   * <code>AWSManagedRulesATPRuleSet</code>. This configuration is used in
   * <code>ManagedRuleGroupConfig</code>. </p> <p>For additional information about
   * this and the other intelligent threat mitigation rule groups, see <a
   * href="https://docs.aws.amazon.com/waf/latest/developerguide/waf-managed-protections">Intelligent
   * threat mitigation in WAF</a> and <a
   * href="https://docs.aws.amazon.com/waf/latest/developerguide/aws-managed-rule-groups-list">Amazon
   * Web Services Managed Rules rule groups list</a> in the <i>WAF Developer
   * Guide</i>. </p><p><h3>See Also:</h3>   <a
   * href="http://docs.aws.amazon.com/goto/WebAPI/wafv2-2019-07-29/AWSManagedRulesATPRuleSet">AWS
   * API Reference</a></p>
   */
  class AWSManagedRulesATPRuleSet
  {
  public:
    AWS_WAFV2_API AWSManagedRulesATPRuleSet() = default;
    AWS_WAFV2_API AWSManagedRulesATPRuleSet(Aws::Utils::Json::JsonView jsonValue);
    AWS_WAFV2_API AWSManagedRulesATPRuleSet& operator=(Aws::Utils::Json::JsonView jsonValue);
    AWS_WAFV2_API Aws::Utils::Json::JsonValue Jsonize() const;


    ///@{
    /**
     * <p>The path of the login endpoint for your application. For example, for the URL
     * <code>https://example.com/web/login</code>, you would provide the path
     * <code>/web/login</code>. Login paths that start with the path that you provide
     * are considered a match. For example <code>/web/login</code> matches the login
     * paths <code>/web/login</code>, <code>/web/login/</code>,
     * <code>/web/loginPage</code>, and <code>/web/login/thisPage</code>, but doesn't
     * match the login path <code>/home/web/login</code> or
     * <code>/website/login</code>.</p> <p>The rule group inspects only HTTP
     * <code>POST</code> requests to your specified login endpoint.</p>
     */
    inline const Aws::String& GetLoginPath() const { return m_loginPath; }
    inline bool LoginPathHasBeenSet() const { return m_loginPathHasBeenSet; }
    template<typename LoginPathT = Aws::String>
    void SetLoginPath(LoginPathT&& value) { m_loginPathHasBeenSet = true; m_loginPath = std::forward<LoginPathT>(value); }
    template<typename LoginPathT = Aws::String>
    AWSManagedRulesATPRuleSet& WithLoginPath(LoginPathT&& value) { SetLoginPath(std::forward<LoginPathT>(value)); return *this;}
    ///@}

    ///@{
    /**
     * <p>The criteria for inspecting login requests, used by the ATP rule group to
     * validate credentials usage. </p>
     */
    inline const RequestInspection& GetRequestInspection() const { return m_requestInspection; }
    inline bool RequestInspectionHasBeenSet() const { return m_requestInspectionHasBeenSet; }
    template<typename RequestInspectionT = RequestInspection>
    void SetRequestInspection(RequestInspectionT&& value) { m_requestInspectionHasBeenSet = true; m_requestInspection = std::forward<RequestInspectionT>(value); }
    template<typename RequestInspectionT = RequestInspection>
    AWSManagedRulesATPRuleSet& WithRequestInspection(RequestInspectionT&& value) { SetRequestInspection(std::forward<RequestInspectionT>(value)); return *this;}
    ///@}

    ///@{
    /**
     * <p>The criteria for inspecting responses to login requests, used by the ATP rule
     * group to track login failure rates. </p>  <p>Response inspection is
     * available only in web ACLs that protect Amazon CloudFront distributions.</p>
     *  <p>The ATP rule group evaluates the responses that your protected
     * resources send back to client login attempts, keeping count of successful and
     * failed attempts for each IP address and client session. Using this information,
     * the rule group labels and mitigates requests from client sessions and IP
     * addresses that have had too many failed login attempts in a short amount of
     * time. </p>
     */
    inline const ResponseInspection& GetResponseInspection() const { return m_responseInspection; }
    inline bool ResponseInspectionHasBeenSet() const { return m_responseInspectionHasBeenSet; }
    template<typename ResponseInspectionT = ResponseInspection>
    void SetResponseInspection(ResponseInspectionT&& value) { m_responseInspectionHasBeenSet = true; m_responseInspection = std::forward<ResponseInspectionT>(value); }
    template<typename ResponseInspectionT = ResponseInspection>
    AWSManagedRulesATPRuleSet& WithResponseInspection(ResponseInspectionT&& value) { SetResponseInspection(std::forward<ResponseInspectionT>(value)); return *this;}
    ///@}

    ///@{
    /**
     * <p>Allow the use of regular expressions in the login page path. </p>
     */
    inline bool GetEnableRegexInPath() const { return m_enableRegexInPath; }
    inline bool EnableRegexInPathHasBeenSet() const { return m_enableRegexInPathHasBeenSet; }
    inline void SetEnableRegexInPath(bool value) { m_enableRegexInPathHasBeenSet = true; m_enableRegexInPath = value; }
    inline AWSManagedRulesATPRuleSet& WithEnableRegexInPath(bool value) { SetEnableRegexInPath(value); return *this;}
    ///@}
  private:

    Aws::String m_loginPath;
    bool m_loginPathHasBeenSet = false;

    RequestInspection m_requestInspection;
    bool m_requestInspectionHasBeenSet = false;

    ResponseInspection m_responseInspection;
    bool m_responseInspectionHasBeenSet = false;

    bool m_enableRegexInPath{false};
    bool m_enableRegexInPathHasBeenSet = false;
  };

} // namespace Model
} // namespace WAFV2
} // namespace Aws
