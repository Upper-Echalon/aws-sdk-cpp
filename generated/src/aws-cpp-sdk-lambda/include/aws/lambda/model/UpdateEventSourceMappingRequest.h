﻿/**
 * Copyright Amazon.com, Inc. or its affiliates. All Rights Reserved.
 * SPDX-License-Identifier: Apache-2.0.
 */

#pragma once
#include <aws/lambda/Lambda_EXPORTS.h>
#include <aws/lambda/LambdaRequest.h>
#include <aws/core/utils/memory/stl/AWSString.h>
#include <aws/lambda/model/FilterCriteria.h>
#include <aws/lambda/model/DestinationConfig.h>
#include <aws/core/utils/memory/stl/AWSVector.h>
#include <aws/lambda/model/ScalingConfig.h>
#include <aws/lambda/model/AmazonManagedKafkaEventSourceConfig.h>
#include <aws/lambda/model/SelfManagedKafkaEventSourceConfig.h>
#include <aws/lambda/model/DocumentDBEventSourceConfig.h>
#include <aws/lambda/model/EventSourceMappingMetricsConfig.h>
#include <aws/lambda/model/ProvisionedPollerConfig.h>
#include <aws/lambda/model/SourceAccessConfiguration.h>
#include <aws/lambda/model/FunctionResponseType.h>
#include <utility>

namespace Aws
{
namespace Lambda
{
namespace Model
{

  /**
   */
  class UpdateEventSourceMappingRequest : public LambdaRequest
  {
  public:
    AWS_LAMBDA_API UpdateEventSourceMappingRequest() = default;

    // Service request name is the Operation name which will send this request out,
    // each operation should has unique request name, so that we can get operation's name from this request.
    // Note: this is not true for response, multiple operations may have the same response name,
    // so we can not get operation's name from response.
    inline virtual const char* GetServiceRequestName() const override { return "UpdateEventSourceMapping"; }

    AWS_LAMBDA_API Aws::String SerializePayload() const override;


    ///@{
    /**
     * <p>The identifier of the event source mapping.</p>
     */
    inline const Aws::String& GetUUID() const { return m_uUID; }
    inline bool UUIDHasBeenSet() const { return m_uUIDHasBeenSet; }
    template<typename UUIDT = Aws::String>
    void SetUUID(UUIDT&& value) { m_uUIDHasBeenSet = true; m_uUID = std::forward<UUIDT>(value); }
    template<typename UUIDT = Aws::String>
    UpdateEventSourceMappingRequest& WithUUID(UUIDT&& value) { SetUUID(std::forward<UUIDT>(value)); return *this;}
    ///@}

    ///@{
    /**
     * <p>The name or ARN of the Lambda function.</p> <p class="title"> <b>Name
     * formats</b> </p> <ul> <li> <p> <b>Function name</b> –
     * <code>MyFunction</code>.</p> </li> <li> <p> <b>Function ARN</b> –
     * <code>arn:aws:lambda:us-west-2:123456789012:function:MyFunction</code>.</p>
     * </li> <li> <p> <b>Version or Alias ARN</b> –
     * <code>arn:aws:lambda:us-west-2:123456789012:function:MyFunction:PROD</code>.</p>
     * </li> <li> <p> <b>Partial ARN</b> –
     * <code>123456789012:function:MyFunction</code>.</p> </li> </ul> <p>The length
     * constraint applies only to the full ARN. If you specify only the function name,
     * it's limited to 64 characters in length.</p>
     */
    inline const Aws::String& GetFunctionName() const { return m_functionName; }
    inline bool FunctionNameHasBeenSet() const { return m_functionNameHasBeenSet; }
    template<typename FunctionNameT = Aws::String>
    void SetFunctionName(FunctionNameT&& value) { m_functionNameHasBeenSet = true; m_functionName = std::forward<FunctionNameT>(value); }
    template<typename FunctionNameT = Aws::String>
    UpdateEventSourceMappingRequest& WithFunctionName(FunctionNameT&& value) { SetFunctionName(std::forward<FunctionNameT>(value)); return *this;}
    ///@}

    ///@{
    /**
     * <p>When true, the event source mapping is active. When false, Lambda pauses
     * polling and invocation.</p> <p>Default: True</p>
     */
    inline bool GetEnabled() const { return m_enabled; }
    inline bool EnabledHasBeenSet() const { return m_enabledHasBeenSet; }
    inline void SetEnabled(bool value) { m_enabledHasBeenSet = true; m_enabled = value; }
    inline UpdateEventSourceMappingRequest& WithEnabled(bool value) { SetEnabled(value); return *this;}
    ///@}

    ///@{
    /**
     * <p>The maximum number of records in each batch that Lambda pulls from your
     * stream or queue and sends to your function. Lambda passes all of the records in
     * the batch to the function in a single call, up to the payload limit for
     * synchronous invocation (6 MB).</p> <ul> <li> <p> <b>Amazon Kinesis</b> – Default
     * 100. Max 10,000.</p> </li> <li> <p> <b>Amazon DynamoDB Streams</b> – Default
     * 100. Max 10,000.</p> </li> <li> <p> <b>Amazon Simple Queue Service</b> – Default
     * 10. For standard queues the max is 10,000. For FIFO queues the max is 10.</p>
     * </li> <li> <p> <b>Amazon Managed Streaming for Apache Kafka</b> – Default 100.
     * Max 10,000.</p> </li> <li> <p> <b>Self-managed Apache Kafka</b> – Default 100.
     * Max 10,000.</p> </li> <li> <p> <b>Amazon MQ (ActiveMQ and RabbitMQ)</b> –
     * Default 100. Max 10,000.</p> </li> <li> <p> <b>DocumentDB</b> – Default 100. Max
     * 10,000.</p> </li> </ul>
     */
    inline int GetBatchSize() const { return m_batchSize; }
    inline bool BatchSizeHasBeenSet() const { return m_batchSizeHasBeenSet; }
    inline void SetBatchSize(int value) { m_batchSizeHasBeenSet = true; m_batchSize = value; }
    inline UpdateEventSourceMappingRequest& WithBatchSize(int value) { SetBatchSize(value); return *this;}
    ///@}

    ///@{
    /**
     * <p>An object that defines the filter criteria that determine whether Lambda
     * should process an event. For more information, see <a
     * href="https://docs.aws.amazon.com/lambda/latest/dg/invocation-eventfiltering.html">Lambda
     * event filtering</a>.</p>
     */
    inline const FilterCriteria& GetFilterCriteria() const { return m_filterCriteria; }
    inline bool FilterCriteriaHasBeenSet() const { return m_filterCriteriaHasBeenSet; }
    template<typename FilterCriteriaT = FilterCriteria>
    void SetFilterCriteria(FilterCriteriaT&& value) { m_filterCriteriaHasBeenSet = true; m_filterCriteria = std::forward<FilterCriteriaT>(value); }
    template<typename FilterCriteriaT = FilterCriteria>
    UpdateEventSourceMappingRequest& WithFilterCriteria(FilterCriteriaT&& value) { SetFilterCriteria(std::forward<FilterCriteriaT>(value)); return *this;}
    ///@}

    ///@{
    /**
     * <p>The maximum amount of time, in seconds, that Lambda spends gathering records
     * before invoking the function. You can configure
     * <code>MaximumBatchingWindowInSeconds</code> to any value from 0 seconds to 300
     * seconds in increments of seconds.</p> <p>For Kinesis, DynamoDB, and Amazon SQS
     * event sources, the default batching window is 0 seconds. For Amazon MSK,
     * Self-managed Apache Kafka, Amazon MQ, and DocumentDB event sources, the default
     * batching window is 500 ms. Note that because you can only change
     * <code>MaximumBatchingWindowInSeconds</code> in increments of seconds, you cannot
     * revert back to the 500 ms default batching window after you have changed it. To
     * restore the default batching window, you must create a new event source
     * mapping.</p> <p>Related setting: For Kinesis, DynamoDB, and Amazon SQS event
     * sources, when you set <code>BatchSize</code> to a value greater than 10, you
     * must set <code>MaximumBatchingWindowInSeconds</code> to at least 1.</p>
     */
    inline int GetMaximumBatchingWindowInSeconds() const { return m_maximumBatchingWindowInSeconds; }
    inline bool MaximumBatchingWindowInSecondsHasBeenSet() const { return m_maximumBatchingWindowInSecondsHasBeenSet; }
    inline void SetMaximumBatchingWindowInSeconds(int value) { m_maximumBatchingWindowInSecondsHasBeenSet = true; m_maximumBatchingWindowInSeconds = value; }
    inline UpdateEventSourceMappingRequest& WithMaximumBatchingWindowInSeconds(int value) { SetMaximumBatchingWindowInSeconds(value); return *this;}
    ///@}

    ///@{
    /**
     * <p>(Kinesis, DynamoDB Streams, Amazon MSK, and self-managed Kafka only) A
     * configuration object that specifies the destination of an event after Lambda
     * processes it.</p>
     */
    inline const DestinationConfig& GetDestinationConfig() const { return m_destinationConfig; }
    inline bool DestinationConfigHasBeenSet() const { return m_destinationConfigHasBeenSet; }
    template<typename DestinationConfigT = DestinationConfig>
    void SetDestinationConfig(DestinationConfigT&& value) { m_destinationConfigHasBeenSet = true; m_destinationConfig = std::forward<DestinationConfigT>(value); }
    template<typename DestinationConfigT = DestinationConfig>
    UpdateEventSourceMappingRequest& WithDestinationConfig(DestinationConfigT&& value) { SetDestinationConfig(std::forward<DestinationConfigT>(value)); return *this;}
    ///@}

    ///@{
    /**
     * <p>(Kinesis and DynamoDB Streams only) Discard records older than the specified
     * age. The default value is infinite (-1).</p>
     */
    inline int GetMaximumRecordAgeInSeconds() const { return m_maximumRecordAgeInSeconds; }
    inline bool MaximumRecordAgeInSecondsHasBeenSet() const { return m_maximumRecordAgeInSecondsHasBeenSet; }
    inline void SetMaximumRecordAgeInSeconds(int value) { m_maximumRecordAgeInSecondsHasBeenSet = true; m_maximumRecordAgeInSeconds = value; }
    inline UpdateEventSourceMappingRequest& WithMaximumRecordAgeInSeconds(int value) { SetMaximumRecordAgeInSeconds(value); return *this;}
    ///@}

    ///@{
    /**
     * <p>(Kinesis and DynamoDB Streams only) If the function returns an error, split
     * the batch in two and retry.</p>
     */
    inline bool GetBisectBatchOnFunctionError() const { return m_bisectBatchOnFunctionError; }
    inline bool BisectBatchOnFunctionErrorHasBeenSet() const { return m_bisectBatchOnFunctionErrorHasBeenSet; }
    inline void SetBisectBatchOnFunctionError(bool value) { m_bisectBatchOnFunctionErrorHasBeenSet = true; m_bisectBatchOnFunctionError = value; }
    inline UpdateEventSourceMappingRequest& WithBisectBatchOnFunctionError(bool value) { SetBisectBatchOnFunctionError(value); return *this;}
    ///@}

    ///@{
    /**
     * <p>(Kinesis and DynamoDB Streams only) Discard records after the specified
     * number of retries. The default value is infinite (-1). When set to infinite
     * (-1), failed records are retried until the record expires.</p>
     */
    inline int GetMaximumRetryAttempts() const { return m_maximumRetryAttempts; }
    inline bool MaximumRetryAttemptsHasBeenSet() const { return m_maximumRetryAttemptsHasBeenSet; }
    inline void SetMaximumRetryAttempts(int value) { m_maximumRetryAttemptsHasBeenSet = true; m_maximumRetryAttempts = value; }
    inline UpdateEventSourceMappingRequest& WithMaximumRetryAttempts(int value) { SetMaximumRetryAttempts(value); return *this;}
    ///@}

    ///@{
    /**
     * <p>(Kinesis and DynamoDB Streams only) The number of batches to process from
     * each shard concurrently.</p>
     */
    inline int GetParallelizationFactor() const { return m_parallelizationFactor; }
    inline bool ParallelizationFactorHasBeenSet() const { return m_parallelizationFactorHasBeenSet; }
    inline void SetParallelizationFactor(int value) { m_parallelizationFactorHasBeenSet = true; m_parallelizationFactor = value; }
    inline UpdateEventSourceMappingRequest& WithParallelizationFactor(int value) { SetParallelizationFactor(value); return *this;}
    ///@}

    ///@{
    /**
     * <p>An array of authentication protocols or VPC components required to secure
     * your event source.</p>
     */
    inline const Aws::Vector<SourceAccessConfiguration>& GetSourceAccessConfigurations() const { return m_sourceAccessConfigurations; }
    inline bool SourceAccessConfigurationsHasBeenSet() const { return m_sourceAccessConfigurationsHasBeenSet; }
    template<typename SourceAccessConfigurationsT = Aws::Vector<SourceAccessConfiguration>>
    void SetSourceAccessConfigurations(SourceAccessConfigurationsT&& value) { m_sourceAccessConfigurationsHasBeenSet = true; m_sourceAccessConfigurations = std::forward<SourceAccessConfigurationsT>(value); }
    template<typename SourceAccessConfigurationsT = Aws::Vector<SourceAccessConfiguration>>
    UpdateEventSourceMappingRequest& WithSourceAccessConfigurations(SourceAccessConfigurationsT&& value) { SetSourceAccessConfigurations(std::forward<SourceAccessConfigurationsT>(value)); return *this;}
    template<typename SourceAccessConfigurationsT = SourceAccessConfiguration>
    UpdateEventSourceMappingRequest& AddSourceAccessConfigurations(SourceAccessConfigurationsT&& value) { m_sourceAccessConfigurationsHasBeenSet = true; m_sourceAccessConfigurations.emplace_back(std::forward<SourceAccessConfigurationsT>(value)); return *this; }
    ///@}

    ///@{
    /**
     * <p>(Kinesis and DynamoDB Streams only) The duration in seconds of a processing
     * window for DynamoDB and Kinesis Streams event sources. A value of 0 seconds
     * indicates no tumbling window.</p>
     */
    inline int GetTumblingWindowInSeconds() const { return m_tumblingWindowInSeconds; }
    inline bool TumblingWindowInSecondsHasBeenSet() const { return m_tumblingWindowInSecondsHasBeenSet; }
    inline void SetTumblingWindowInSeconds(int value) { m_tumblingWindowInSecondsHasBeenSet = true; m_tumblingWindowInSeconds = value; }
    inline UpdateEventSourceMappingRequest& WithTumblingWindowInSeconds(int value) { SetTumblingWindowInSeconds(value); return *this;}
    ///@}

    ///@{
    /**
     * <p>(Kinesis, DynamoDB Streams, and Amazon SQS) A list of current response type
     * enums applied to the event source mapping.</p>
     */
    inline const Aws::Vector<FunctionResponseType>& GetFunctionResponseTypes() const { return m_functionResponseTypes; }
    inline bool FunctionResponseTypesHasBeenSet() const { return m_functionResponseTypesHasBeenSet; }
    template<typename FunctionResponseTypesT = Aws::Vector<FunctionResponseType>>
    void SetFunctionResponseTypes(FunctionResponseTypesT&& value) { m_functionResponseTypesHasBeenSet = true; m_functionResponseTypes = std::forward<FunctionResponseTypesT>(value); }
    template<typename FunctionResponseTypesT = Aws::Vector<FunctionResponseType>>
    UpdateEventSourceMappingRequest& WithFunctionResponseTypes(FunctionResponseTypesT&& value) { SetFunctionResponseTypes(std::forward<FunctionResponseTypesT>(value)); return *this;}
    inline UpdateEventSourceMappingRequest& AddFunctionResponseTypes(FunctionResponseType value) { m_functionResponseTypesHasBeenSet = true; m_functionResponseTypes.push_back(value); return *this; }
    ///@}

    ///@{
    /**
     * <p>(Amazon SQS only) The scaling configuration for the event source. For more
     * information, see <a
     * href="https://docs.aws.amazon.com/lambda/latest/dg/with-sqs.html#events-sqs-max-concurrency">Configuring
     * maximum concurrency for Amazon SQS event sources</a>.</p>
     */
    inline const ScalingConfig& GetScalingConfig() const { return m_scalingConfig; }
    inline bool ScalingConfigHasBeenSet() const { return m_scalingConfigHasBeenSet; }
    template<typename ScalingConfigT = ScalingConfig>
    void SetScalingConfig(ScalingConfigT&& value) { m_scalingConfigHasBeenSet = true; m_scalingConfig = std::forward<ScalingConfigT>(value); }
    template<typename ScalingConfigT = ScalingConfig>
    UpdateEventSourceMappingRequest& WithScalingConfig(ScalingConfigT&& value) { SetScalingConfig(std::forward<ScalingConfigT>(value)); return *this;}
    ///@}

    ///@{
    
    inline const AmazonManagedKafkaEventSourceConfig& GetAmazonManagedKafkaEventSourceConfig() const { return m_amazonManagedKafkaEventSourceConfig; }
    inline bool AmazonManagedKafkaEventSourceConfigHasBeenSet() const { return m_amazonManagedKafkaEventSourceConfigHasBeenSet; }
    template<typename AmazonManagedKafkaEventSourceConfigT = AmazonManagedKafkaEventSourceConfig>
    void SetAmazonManagedKafkaEventSourceConfig(AmazonManagedKafkaEventSourceConfigT&& value) { m_amazonManagedKafkaEventSourceConfigHasBeenSet = true; m_amazonManagedKafkaEventSourceConfig = std::forward<AmazonManagedKafkaEventSourceConfigT>(value); }
    template<typename AmazonManagedKafkaEventSourceConfigT = AmazonManagedKafkaEventSourceConfig>
    UpdateEventSourceMappingRequest& WithAmazonManagedKafkaEventSourceConfig(AmazonManagedKafkaEventSourceConfigT&& value) { SetAmazonManagedKafkaEventSourceConfig(std::forward<AmazonManagedKafkaEventSourceConfigT>(value)); return *this;}
    ///@}

    ///@{
    
    inline const SelfManagedKafkaEventSourceConfig& GetSelfManagedKafkaEventSourceConfig() const { return m_selfManagedKafkaEventSourceConfig; }
    inline bool SelfManagedKafkaEventSourceConfigHasBeenSet() const { return m_selfManagedKafkaEventSourceConfigHasBeenSet; }
    template<typename SelfManagedKafkaEventSourceConfigT = SelfManagedKafkaEventSourceConfig>
    void SetSelfManagedKafkaEventSourceConfig(SelfManagedKafkaEventSourceConfigT&& value) { m_selfManagedKafkaEventSourceConfigHasBeenSet = true; m_selfManagedKafkaEventSourceConfig = std::forward<SelfManagedKafkaEventSourceConfigT>(value); }
    template<typename SelfManagedKafkaEventSourceConfigT = SelfManagedKafkaEventSourceConfig>
    UpdateEventSourceMappingRequest& WithSelfManagedKafkaEventSourceConfig(SelfManagedKafkaEventSourceConfigT&& value) { SetSelfManagedKafkaEventSourceConfig(std::forward<SelfManagedKafkaEventSourceConfigT>(value)); return *this;}
    ///@}

    ///@{
    /**
     * <p>Specific configuration settings for a DocumentDB event source.</p>
     */
    inline const DocumentDBEventSourceConfig& GetDocumentDBEventSourceConfig() const { return m_documentDBEventSourceConfig; }
    inline bool DocumentDBEventSourceConfigHasBeenSet() const { return m_documentDBEventSourceConfigHasBeenSet; }
    template<typename DocumentDBEventSourceConfigT = DocumentDBEventSourceConfig>
    void SetDocumentDBEventSourceConfig(DocumentDBEventSourceConfigT&& value) { m_documentDBEventSourceConfigHasBeenSet = true; m_documentDBEventSourceConfig = std::forward<DocumentDBEventSourceConfigT>(value); }
    template<typename DocumentDBEventSourceConfigT = DocumentDBEventSourceConfig>
    UpdateEventSourceMappingRequest& WithDocumentDBEventSourceConfig(DocumentDBEventSourceConfigT&& value) { SetDocumentDBEventSourceConfig(std::forward<DocumentDBEventSourceConfigT>(value)); return *this;}
    ///@}

    ///@{
    /**
     * <p> The ARN of the Key Management Service (KMS) customer managed key that Lambda
     * uses to encrypt your function's <a
     * href="https://docs.aws.amazon.com/lambda/latest/dg/invocation-eventfiltering.html#filtering-basics">filter
     * criteria</a>. By default, Lambda does not encrypt your filter criteria object.
     * Specify this property to encrypt data using your own customer managed key. </p>
     */
    inline const Aws::String& GetKMSKeyArn() const { return m_kMSKeyArn; }
    inline bool KMSKeyArnHasBeenSet() const { return m_kMSKeyArnHasBeenSet; }
    template<typename KMSKeyArnT = Aws::String>
    void SetKMSKeyArn(KMSKeyArnT&& value) { m_kMSKeyArnHasBeenSet = true; m_kMSKeyArn = std::forward<KMSKeyArnT>(value); }
    template<typename KMSKeyArnT = Aws::String>
    UpdateEventSourceMappingRequest& WithKMSKeyArn(KMSKeyArnT&& value) { SetKMSKeyArn(std::forward<KMSKeyArnT>(value)); return *this;}
    ///@}

    ///@{
    /**
     * <p>The metrics configuration for your event source. For more information, see <a
     * href="https://docs.aws.amazon.com/lambda/latest/dg/monitoring-metrics-types.html#event-source-mapping-metrics">Event
     * source mapping metrics</a>.</p>
     */
    inline const EventSourceMappingMetricsConfig& GetMetricsConfig() const { return m_metricsConfig; }
    inline bool MetricsConfigHasBeenSet() const { return m_metricsConfigHasBeenSet; }
    template<typename MetricsConfigT = EventSourceMappingMetricsConfig>
    void SetMetricsConfig(MetricsConfigT&& value) { m_metricsConfigHasBeenSet = true; m_metricsConfig = std::forward<MetricsConfigT>(value); }
    template<typename MetricsConfigT = EventSourceMappingMetricsConfig>
    UpdateEventSourceMappingRequest& WithMetricsConfig(MetricsConfigT&& value) { SetMetricsConfig(std::forward<MetricsConfigT>(value)); return *this;}
    ///@}

    ///@{
    /**
     * <p>(Amazon MSK and self-managed Apache Kafka only) The provisioned mode
     * configuration for the event source. For more information, see <a
     * href="https://docs.aws.amazon.com/lambda/latest/dg/invocation-eventsourcemapping.html#invocation-eventsourcemapping-provisioned-mode">provisioned
     * mode</a>.</p>
     */
    inline const ProvisionedPollerConfig& GetProvisionedPollerConfig() const { return m_provisionedPollerConfig; }
    inline bool ProvisionedPollerConfigHasBeenSet() const { return m_provisionedPollerConfigHasBeenSet; }
    template<typename ProvisionedPollerConfigT = ProvisionedPollerConfig>
    void SetProvisionedPollerConfig(ProvisionedPollerConfigT&& value) { m_provisionedPollerConfigHasBeenSet = true; m_provisionedPollerConfig = std::forward<ProvisionedPollerConfigT>(value); }
    template<typename ProvisionedPollerConfigT = ProvisionedPollerConfig>
    UpdateEventSourceMappingRequest& WithProvisionedPollerConfig(ProvisionedPollerConfigT&& value) { SetProvisionedPollerConfig(std::forward<ProvisionedPollerConfigT>(value)); return *this;}
    ///@}
  private:

    Aws::String m_uUID;
    bool m_uUIDHasBeenSet = false;

    Aws::String m_functionName;
    bool m_functionNameHasBeenSet = false;

    bool m_enabled{false};
    bool m_enabledHasBeenSet = false;

    int m_batchSize{0};
    bool m_batchSizeHasBeenSet = false;

    FilterCriteria m_filterCriteria;
    bool m_filterCriteriaHasBeenSet = false;

    int m_maximumBatchingWindowInSeconds{0};
    bool m_maximumBatchingWindowInSecondsHasBeenSet = false;

    DestinationConfig m_destinationConfig;
    bool m_destinationConfigHasBeenSet = false;

    int m_maximumRecordAgeInSeconds{0};
    bool m_maximumRecordAgeInSecondsHasBeenSet = false;

    bool m_bisectBatchOnFunctionError{false};
    bool m_bisectBatchOnFunctionErrorHasBeenSet = false;

    int m_maximumRetryAttempts{0};
    bool m_maximumRetryAttemptsHasBeenSet = false;

    int m_parallelizationFactor{0};
    bool m_parallelizationFactorHasBeenSet = false;

    Aws::Vector<SourceAccessConfiguration> m_sourceAccessConfigurations;
    bool m_sourceAccessConfigurationsHasBeenSet = false;

    int m_tumblingWindowInSeconds{0};
    bool m_tumblingWindowInSecondsHasBeenSet = false;

    Aws::Vector<FunctionResponseType> m_functionResponseTypes;
    bool m_functionResponseTypesHasBeenSet = false;

    ScalingConfig m_scalingConfig;
    bool m_scalingConfigHasBeenSet = false;

    AmazonManagedKafkaEventSourceConfig m_amazonManagedKafkaEventSourceConfig;
    bool m_amazonManagedKafkaEventSourceConfigHasBeenSet = false;

    SelfManagedKafkaEventSourceConfig m_selfManagedKafkaEventSourceConfig;
    bool m_selfManagedKafkaEventSourceConfigHasBeenSet = false;

    DocumentDBEventSourceConfig m_documentDBEventSourceConfig;
    bool m_documentDBEventSourceConfigHasBeenSet = false;

    Aws::String m_kMSKeyArn;
    bool m_kMSKeyArnHasBeenSet = false;

    EventSourceMappingMetricsConfig m_metricsConfig;
    bool m_metricsConfigHasBeenSet = false;

    ProvisionedPollerConfig m_provisionedPollerConfig;
    bool m_provisionedPollerConfigHasBeenSet = false;
  };

} // namespace Model
} // namespace Lambda
} // namespace Aws
