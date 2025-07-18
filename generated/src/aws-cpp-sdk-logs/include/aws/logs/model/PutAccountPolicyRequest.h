﻿/**
 * Copyright Amazon.com, Inc. or its affiliates. All Rights Reserved.
 * SPDX-License-Identifier: Apache-2.0.
 */

#pragma once
#include <aws/logs/CloudWatchLogs_EXPORTS.h>
#include <aws/logs/CloudWatchLogsRequest.h>
#include <aws/core/utils/memory/stl/AWSString.h>
#include <aws/logs/model/PolicyType.h>
#include <aws/logs/model/Scope.h>
#include <utility>

namespace Aws
{
namespace CloudWatchLogs
{
namespace Model
{

  /**
   */
  class PutAccountPolicyRequest : public CloudWatchLogsRequest
  {
  public:
    AWS_CLOUDWATCHLOGS_API PutAccountPolicyRequest() = default;

    // Service request name is the Operation name which will send this request out,
    // each operation should has unique request name, so that we can get operation's name from this request.
    // Note: this is not true for response, multiple operations may have the same response name,
    // so we can not get operation's name from response.
    inline virtual const char* GetServiceRequestName() const override { return "PutAccountPolicy"; }

    AWS_CLOUDWATCHLOGS_API Aws::String SerializePayload() const override;

    AWS_CLOUDWATCHLOGS_API Aws::Http::HeaderValueCollection GetRequestSpecificHeaders() const override;


    ///@{
    /**
     * <p>A name for the policy. This must be unique within the account.</p>
     */
    inline const Aws::String& GetPolicyName() const { return m_policyName; }
    inline bool PolicyNameHasBeenSet() const { return m_policyNameHasBeenSet; }
    template<typename PolicyNameT = Aws::String>
    void SetPolicyName(PolicyNameT&& value) { m_policyNameHasBeenSet = true; m_policyName = std::forward<PolicyNameT>(value); }
    template<typename PolicyNameT = Aws::String>
    PutAccountPolicyRequest& WithPolicyName(PolicyNameT&& value) { SetPolicyName(std::forward<PolicyNameT>(value)); return *this;}
    ///@}

    ///@{
    /**
     * <p>Specify the policy, in JSON.</p> <p> <b>Data protection policy</b> </p> <p>A
     * data protection policy must include two JSON blocks:</p> <ul> <li> <p>The first
     * block must include both a <code>DataIdentifer</code> array and an
     * <code>Operation</code> property with an <code>Audit</code> action. The
     * <code>DataIdentifer</code> array lists the types of sensitive data that you want
     * to mask. For more information about the available options, see <a
     * href="https://docs.aws.amazon.com/AmazonCloudWatch/latest/logs/mask-sensitive-log-data-types.html">Types
     * of data that you can mask</a>.</p> <p>The <code>Operation</code> property with
     * an <code>Audit</code> action is required to find the sensitive data terms. This
     * <code>Audit</code> action must contain a <code>FindingsDestination</code>
     * object. You can optionally use that <code>FindingsDestination</code> object to
     * list one or more destinations to send audit findings to. If you specify
     * destinations such as log groups, Firehose streams, and S3 buckets, they must
     * already exist.</p> </li> <li> <p>The second block must include both a
     * <code>DataIdentifer</code> array and an <code>Operation</code> property with an
     * <code>Deidentify</code> action. The <code>DataIdentifer</code> array must
     * exactly match the <code>DataIdentifer</code> array in the first block of the
     * policy.</p> <p>The <code>Operation</code> property with the
     * <code>Deidentify</code> action is what actually masks the data, and it must
     * contain the <code> "MaskConfig": {}</code> object. The <code> "MaskConfig":
     * {}</code> object must be empty.</p> </li> </ul> <p>For an example data
     * protection policy, see the <b>Examples</b> section on this page.</p> 
     * <p>The contents of the two <code>DataIdentifer</code> arrays must match
     * exactly.</p>  <p>In addition to the two JSON blocks, the
     * <code>policyDocument</code> can also include <code>Name</code>,
     * <code>Description</code>, and <code>Version</code> fields. The <code>Name</code>
     * is different than the operation's <code>policyName</code> parameter, and is used
     * as a dimension when CloudWatch Logs reports audit findings metrics to
     * CloudWatch.</p> <p>The JSON specified in <code>policyDocument</code> can be up
     * to 30,720 characters long.</p> <p> <b>Subscription filter policy</b> </p> <p>A
     * subscription filter policy can include the following attributes in a JSON
     * block:</p> <ul> <li> <p> <b>DestinationArn</b> The ARN of the destination to
     * deliver log events to. Supported destinations are:</p> <ul> <li> <p>An Kinesis
     * Data Streams data stream in the same account as the subscription policy, for
     * same-account delivery.</p> </li> <li> <p>An Firehose data stream in the same
     * account as the subscription policy, for same-account delivery.</p> </li> <li>
     * <p>A Lambda function in the same account as the subscription policy, for
     * same-account delivery.</p> </li> <li> <p>A logical destination in a different
     * account created with <a
     * href="https://docs.aws.amazon.com/AmazonCloudWatchLogs/latest/APIReference/API_PutDestination.html">PutDestination</a>,
     * for cross-account delivery. Kinesis Data Streams and Firehose are supported as
     * logical destinations.</p> </li> </ul> </li> <li> <p> <b>RoleArn</b> The ARN of
     * an IAM role that grants CloudWatch Logs permissions to deliver ingested log
     * events to the destination stream. You don't need to provide the ARN when you are
     * working with a logical destination for cross-account delivery.</p> </li> <li>
     * <p> <b>FilterPattern</b> A filter pattern for subscribing to a filtered stream
     * of log events.</p> </li> <li> <p> <b>Distribution</b> The method used to
     * distribute log data to the destination. By default, log data is grouped by log
     * stream, but the grouping can be set to <code>Random</code> for a more even
     * distribution. This property is only applicable when the destination is an
     * Kinesis Data Streams data stream.</p> </li> </ul> <p> <b>Transformer policy</b>
     * </p> <p>A transformer policy must include one JSON block with the array of
     * processors and their configurations. For more information about available
     * processors, see <a
     * href="https://docs.aws.amazon.com/AmazonCloudWatch/latest/logs/CloudWatch-Logs-Transformation.html#CloudWatch-Logs-Transformation-Processors">
     * Processors that you can use</a>. </p> <p> <b>Field index policy</b> </p> <p>A
     * field index filter policy can include the following attribute in a JSON
     * block:</p> <ul> <li> <p> <b>Fields</b> The array of field indexes to create.</p>
     * </li> </ul> <p>It must contain at least one field index.</p> <p>The following is
     * an example of an index policy document that creates two indexes,
     * <code>RequestId</code> and <code>TransactionId</code>.</p> <p>
     * <code>"policyDocument": "{ \"Fields\": [ \"RequestId\", \"TransactionId\" ]
     * }"</code> </p>
     */
    inline const Aws::String& GetPolicyDocument() const { return m_policyDocument; }
    inline bool PolicyDocumentHasBeenSet() const { return m_policyDocumentHasBeenSet; }
    template<typename PolicyDocumentT = Aws::String>
    void SetPolicyDocument(PolicyDocumentT&& value) { m_policyDocumentHasBeenSet = true; m_policyDocument = std::forward<PolicyDocumentT>(value); }
    template<typename PolicyDocumentT = Aws::String>
    PutAccountPolicyRequest& WithPolicyDocument(PolicyDocumentT&& value) { SetPolicyDocument(std::forward<PolicyDocumentT>(value)); return *this;}
    ///@}

    ///@{
    /**
     * <p>The type of policy that you're creating or updating.</p>
     */
    inline PolicyType GetPolicyType() const { return m_policyType; }
    inline bool PolicyTypeHasBeenSet() const { return m_policyTypeHasBeenSet; }
    inline void SetPolicyType(PolicyType value) { m_policyTypeHasBeenSet = true; m_policyType = value; }
    inline PutAccountPolicyRequest& WithPolicyType(PolicyType value) { SetPolicyType(value); return *this;}
    ///@}

    ///@{
    /**
     * <p>Currently the only valid value for this parameter is <code>ALL</code>, which
     * specifies that the data protection policy applies to all log groups in the
     * account. If you omit this parameter, the default of <code>ALL</code> is
     * used.</p>
     */
    inline Scope GetScope() const { return m_scope; }
    inline bool ScopeHasBeenSet() const { return m_scopeHasBeenSet; }
    inline void SetScope(Scope value) { m_scopeHasBeenSet = true; m_scope = value; }
    inline PutAccountPolicyRequest& WithScope(Scope value) { SetScope(value); return *this;}
    ///@}

    ///@{
    /**
     * <p>Use this parameter to apply the new policy to a subset of log groups in the
     * account.</p> <p>Specifying <code>selectionCriteria</code> is valid only when you
     * specify <code>SUBSCRIPTION_FILTER_POLICY</code>, <code>FIELD_INDEX_POLICY</code>
     * or <code>TRANSFORMER_POLICY</code>for <code>policyType</code>.</p> <p>If
     * <code>policyType</code> is <code>SUBSCRIPTION_FILTER_POLICY</code>, the only
     * supported <code>selectionCriteria</code> filter is <code>LogGroupName NOT IN
     * []</code> </p> <p>If <code>policyType</code> is <code>FIELD_INDEX_POLICY</code>
     * or <code>TRANSFORMER_POLICY</code>, the only supported
     * <code>selectionCriteria</code> filter is <code>LogGroupNamePrefix</code> </p>
     * <p>The <code>selectionCriteria</code> string can be up to 25KB in length. The
     * length is determined by using its UTF-8 bytes.</p> <p>Using the
     * <code>selectionCriteria</code> parameter with
     * <code>SUBSCRIPTION_FILTER_POLICY</code> is useful to help prevent infinite
     * loops. For more information, see <a
     * href="https://docs.aws.amazon.com/AmazonCloudWatch/latest/logs/Subscriptions-recursion-prevention.html">Log
     * recursion prevention</a>.</p>
     */
    inline const Aws::String& GetSelectionCriteria() const { return m_selectionCriteria; }
    inline bool SelectionCriteriaHasBeenSet() const { return m_selectionCriteriaHasBeenSet; }
    template<typename SelectionCriteriaT = Aws::String>
    void SetSelectionCriteria(SelectionCriteriaT&& value) { m_selectionCriteriaHasBeenSet = true; m_selectionCriteria = std::forward<SelectionCriteriaT>(value); }
    template<typename SelectionCriteriaT = Aws::String>
    PutAccountPolicyRequest& WithSelectionCriteria(SelectionCriteriaT&& value) { SetSelectionCriteria(std::forward<SelectionCriteriaT>(value)); return *this;}
    ///@}
  private:

    Aws::String m_policyName;
    bool m_policyNameHasBeenSet = false;

    Aws::String m_policyDocument;
    bool m_policyDocumentHasBeenSet = false;

    PolicyType m_policyType{PolicyType::NOT_SET};
    bool m_policyTypeHasBeenSet = false;

    Scope m_scope{Scope::NOT_SET};
    bool m_scopeHasBeenSet = false;

    Aws::String m_selectionCriteria;
    bool m_selectionCriteriaHasBeenSet = false;
  };

} // namespace Model
} // namespace CloudWatchLogs
} // namespace Aws
