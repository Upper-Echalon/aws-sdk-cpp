﻿/**
 * Copyright Amazon.com, Inc. or its affiliates. All Rights Reserved.
 * SPDX-License-Identifier: Apache-2.0.
 */

#pragma once

/* Generic header includes */
#include <aws/iotsitewise/IoTSiteWiseErrors.h>
#include <aws/core/client/GenericClientConfiguration.h>
#include <aws/core/client/AWSError.h>
#include <aws/core/utils/memory/stl/AWSString.h>
#include <aws/core/client/AsyncCallerContext.h>
#include <aws/core/http/HttpTypes.h>
#include <aws/iotsitewise/IoTSiteWiseEndpointProvider.h>
#include <future>
#include <functional>
/* End of generic header includes */

/* Service model headers required in IoTSiteWiseClient header */
#include <aws/iotsitewise/model/BatchAssociateProjectAssetsResult.h>
#include <aws/iotsitewise/model/BatchDisassociateProjectAssetsResult.h>
#include <aws/iotsitewise/model/BatchGetAssetPropertyAggregatesResult.h>
#include <aws/iotsitewise/model/BatchGetAssetPropertyValueResult.h>
#include <aws/iotsitewise/model/BatchGetAssetPropertyValueHistoryResult.h>
#include <aws/iotsitewise/model/BatchPutAssetPropertyValueResult.h>
#include <aws/iotsitewise/model/CreateAccessPolicyResult.h>
#include <aws/iotsitewise/model/CreateAssetResult.h>
#include <aws/iotsitewise/model/CreateAssetModelResult.h>
#include <aws/iotsitewise/model/CreateAssetModelCompositeModelResult.h>
#include <aws/iotsitewise/model/CreateBulkImportJobResult.h>
#include <aws/iotsitewise/model/CreateComputationModelResult.h>
#include <aws/iotsitewise/model/CreateDashboardResult.h>
#include <aws/iotsitewise/model/CreateDatasetResult.h>
#include <aws/iotsitewise/model/CreateGatewayResult.h>
#include <aws/iotsitewise/model/CreatePortalResult.h>
#include <aws/iotsitewise/model/CreateProjectResult.h>
#include <aws/iotsitewise/model/DeleteAccessPolicyResult.h>
#include <aws/iotsitewise/model/DeleteAssetResult.h>
#include <aws/iotsitewise/model/DeleteAssetModelResult.h>
#include <aws/iotsitewise/model/DeleteAssetModelCompositeModelResult.h>
#include <aws/iotsitewise/model/DeleteComputationModelResult.h>
#include <aws/iotsitewise/model/DeleteDashboardResult.h>
#include <aws/iotsitewise/model/DeleteDatasetResult.h>
#include <aws/iotsitewise/model/DeletePortalResult.h>
#include <aws/iotsitewise/model/DeleteProjectResult.h>
#include <aws/iotsitewise/model/DescribeAccessPolicyResult.h>
#include <aws/iotsitewise/model/DescribeActionResult.h>
#include <aws/iotsitewise/model/DescribeAssetResult.h>
#include <aws/iotsitewise/model/DescribeAssetCompositeModelResult.h>
#include <aws/iotsitewise/model/DescribeAssetModelResult.h>
#include <aws/iotsitewise/model/DescribeAssetModelCompositeModelResult.h>
#include <aws/iotsitewise/model/DescribeAssetPropertyResult.h>
#include <aws/iotsitewise/model/DescribeBulkImportJobResult.h>
#include <aws/iotsitewise/model/DescribeComputationModelResult.h>
#include <aws/iotsitewise/model/DescribeComputationModelExecutionSummaryResult.h>
#include <aws/iotsitewise/model/DescribeDashboardResult.h>
#include <aws/iotsitewise/model/DescribeDatasetResult.h>
#include <aws/iotsitewise/model/DescribeDefaultEncryptionConfigurationResult.h>
#include <aws/iotsitewise/model/DescribeExecutionResult.h>
#include <aws/iotsitewise/model/DescribeGatewayResult.h>
#include <aws/iotsitewise/model/DescribeGatewayCapabilityConfigurationResult.h>
#include <aws/iotsitewise/model/DescribeLoggingOptionsResult.h>
#include <aws/iotsitewise/model/DescribePortalResult.h>
#include <aws/iotsitewise/model/DescribeProjectResult.h>
#include <aws/iotsitewise/model/DescribeStorageConfigurationResult.h>
#include <aws/iotsitewise/model/DescribeTimeSeriesResult.h>
#include <aws/iotsitewise/model/ExecuteActionResult.h>
#include <aws/iotsitewise/model/ExecuteQueryResult.h>
#include <aws/iotsitewise/model/GetAssetPropertyAggregatesResult.h>
#include <aws/iotsitewise/model/GetAssetPropertyValueResult.h>
#include <aws/iotsitewise/model/GetAssetPropertyValueHistoryResult.h>
#include <aws/iotsitewise/model/GetInterpolatedAssetPropertyValuesResult.h>
#include <aws/iotsitewise/model/ListAccessPoliciesResult.h>
#include <aws/iotsitewise/model/ListActionsResult.h>
#include <aws/iotsitewise/model/ListAssetModelCompositeModelsResult.h>
#include <aws/iotsitewise/model/ListAssetModelPropertiesResult.h>
#include <aws/iotsitewise/model/ListAssetModelsResult.h>
#include <aws/iotsitewise/model/ListAssetPropertiesResult.h>
#include <aws/iotsitewise/model/ListAssetRelationshipsResult.h>
#include <aws/iotsitewise/model/ListAssetsResult.h>
#include <aws/iotsitewise/model/ListAssociatedAssetsResult.h>
#include <aws/iotsitewise/model/ListBulkImportJobsResult.h>
#include <aws/iotsitewise/model/ListCompositionRelationshipsResult.h>
#include <aws/iotsitewise/model/ListComputationModelDataBindingUsagesResult.h>
#include <aws/iotsitewise/model/ListComputationModelResolveToResourcesResult.h>
#include <aws/iotsitewise/model/ListComputationModelsResult.h>
#include <aws/iotsitewise/model/ListDashboardsResult.h>
#include <aws/iotsitewise/model/ListDatasetsResult.h>
#include <aws/iotsitewise/model/ListExecutionsResult.h>
#include <aws/iotsitewise/model/ListGatewaysResult.h>
#include <aws/iotsitewise/model/ListPortalsResult.h>
#include <aws/iotsitewise/model/ListProjectAssetsResult.h>
#include <aws/iotsitewise/model/ListProjectsResult.h>
#include <aws/iotsitewise/model/ListTagsForResourceResult.h>
#include <aws/iotsitewise/model/ListTimeSeriesResult.h>
#include <aws/iotsitewise/model/PutDefaultEncryptionConfigurationResult.h>
#include <aws/iotsitewise/model/PutLoggingOptionsResult.h>
#include <aws/iotsitewise/model/PutStorageConfigurationResult.h>
#include <aws/iotsitewise/model/TagResourceResult.h>
#include <aws/iotsitewise/model/UntagResourceResult.h>
#include <aws/iotsitewise/model/UpdateAccessPolicyResult.h>
#include <aws/iotsitewise/model/UpdateAssetResult.h>
#include <aws/iotsitewise/model/UpdateAssetModelResult.h>
#include <aws/iotsitewise/model/UpdateAssetModelCompositeModelResult.h>
#include <aws/iotsitewise/model/UpdateComputationModelResult.h>
#include <aws/iotsitewise/model/UpdateDashboardResult.h>
#include <aws/iotsitewise/model/UpdateDatasetResult.h>
#include <aws/iotsitewise/model/UpdateGatewayCapabilityConfigurationResult.h>
#include <aws/iotsitewise/model/UpdatePortalResult.h>
#include <aws/iotsitewise/model/UpdateProjectResult.h>
#include <aws/iotsitewise/model/ListAssetModelsRequest.h>
#include <aws/iotsitewise/model/DescribeTimeSeriesRequest.h>
#include <aws/iotsitewise/model/ListTimeSeriesRequest.h>
#include <aws/iotsitewise/model/ListPortalsRequest.h>
#include <aws/iotsitewise/model/GetAssetPropertyValueHistoryRequest.h>
#include <aws/iotsitewise/model/ListBulkImportJobsRequest.h>
#include <aws/iotsitewise/model/ListComputationModelsRequest.h>
#include <aws/iotsitewise/model/DescribeDefaultEncryptionConfigurationRequest.h>
#include <aws/iotsitewise/model/DescribeLoggingOptionsRequest.h>
#include <aws/iotsitewise/model/ListAssetsRequest.h>
#include <aws/iotsitewise/model/DescribeStorageConfigurationRequest.h>
#include <aws/iotsitewise/model/ListAccessPoliciesRequest.h>
#include <aws/iotsitewise/model/DeleteTimeSeriesRequest.h>
#include <aws/iotsitewise/model/GetAssetPropertyValueRequest.h>
#include <aws/iotsitewise/model/ListGatewaysRequest.h>
#include <aws/core/NoResult.h>
/* End of service model headers required in IoTSiteWiseClient header */

namespace Aws
{
  namespace Http
  {
    class HttpClient;
    class HttpClientFactory;
  } // namespace Http

  namespace Utils
  {
    template< typename R, typename E> class Outcome;

    namespace Threading
    {
      class Executor;
    } // namespace Threading
  } // namespace Utils

  namespace Auth
  {
    class AWSCredentials;
    class AWSCredentialsProvider;
  } // namespace Auth

  namespace Client
  {
    class RetryStrategy;
  } // namespace Client

  namespace IoTSiteWise
  {
    using IoTSiteWiseClientConfiguration = Aws::Client::GenericClientConfiguration;
    using IoTSiteWiseEndpointProviderBase = Aws::IoTSiteWise::Endpoint::IoTSiteWiseEndpointProviderBase;
    using IoTSiteWiseEndpointProvider = Aws::IoTSiteWise::Endpoint::IoTSiteWiseEndpointProvider;

    namespace Model
    {
      /* Service model forward declarations required in IoTSiteWiseClient header */
      class AssociateAssetsRequest;
      class AssociateTimeSeriesToAssetPropertyRequest;
      class BatchAssociateProjectAssetsRequest;
      class BatchDisassociateProjectAssetsRequest;
      class BatchGetAssetPropertyAggregatesRequest;
      class BatchGetAssetPropertyValueRequest;
      class BatchGetAssetPropertyValueHistoryRequest;
      class BatchPutAssetPropertyValueRequest;
      class CreateAccessPolicyRequest;
      class CreateAssetRequest;
      class CreateAssetModelRequest;
      class CreateAssetModelCompositeModelRequest;
      class CreateBulkImportJobRequest;
      class CreateComputationModelRequest;
      class CreateDashboardRequest;
      class CreateDatasetRequest;
      class CreateGatewayRequest;
      class CreatePortalRequest;
      class CreateProjectRequest;
      class DeleteAccessPolicyRequest;
      class DeleteAssetRequest;
      class DeleteAssetModelRequest;
      class DeleteAssetModelCompositeModelRequest;
      class DeleteComputationModelRequest;
      class DeleteDashboardRequest;
      class DeleteDatasetRequest;
      class DeleteGatewayRequest;
      class DeletePortalRequest;
      class DeleteProjectRequest;
      class DeleteTimeSeriesRequest;
      class DescribeAccessPolicyRequest;
      class DescribeActionRequest;
      class DescribeAssetRequest;
      class DescribeAssetCompositeModelRequest;
      class DescribeAssetModelRequest;
      class DescribeAssetModelCompositeModelRequest;
      class DescribeAssetPropertyRequest;
      class DescribeBulkImportJobRequest;
      class DescribeComputationModelRequest;
      class DescribeComputationModelExecutionSummaryRequest;
      class DescribeDashboardRequest;
      class DescribeDatasetRequest;
      class DescribeDefaultEncryptionConfigurationRequest;
      class DescribeExecutionRequest;
      class DescribeGatewayRequest;
      class DescribeGatewayCapabilityConfigurationRequest;
      class DescribeLoggingOptionsRequest;
      class DescribePortalRequest;
      class DescribeProjectRequest;
      class DescribeStorageConfigurationRequest;
      class DescribeTimeSeriesRequest;
      class DisassociateAssetsRequest;
      class DisassociateTimeSeriesFromAssetPropertyRequest;
      class ExecuteActionRequest;
      class ExecuteQueryRequest;
      class GetAssetPropertyAggregatesRequest;
      class GetAssetPropertyValueRequest;
      class GetAssetPropertyValueHistoryRequest;
      class GetInterpolatedAssetPropertyValuesRequest;
      class InvokeAssistantRequest;
      class ListAccessPoliciesRequest;
      class ListActionsRequest;
      class ListAssetModelCompositeModelsRequest;
      class ListAssetModelPropertiesRequest;
      class ListAssetModelsRequest;
      class ListAssetPropertiesRequest;
      class ListAssetRelationshipsRequest;
      class ListAssetsRequest;
      class ListAssociatedAssetsRequest;
      class ListBulkImportJobsRequest;
      class ListCompositionRelationshipsRequest;
      class ListComputationModelDataBindingUsagesRequest;
      class ListComputationModelResolveToResourcesRequest;
      class ListComputationModelsRequest;
      class ListDashboardsRequest;
      class ListDatasetsRequest;
      class ListExecutionsRequest;
      class ListGatewaysRequest;
      class ListPortalsRequest;
      class ListProjectAssetsRequest;
      class ListProjectsRequest;
      class ListTagsForResourceRequest;
      class ListTimeSeriesRequest;
      class PutDefaultEncryptionConfigurationRequest;
      class PutLoggingOptionsRequest;
      class PutStorageConfigurationRequest;
      class TagResourceRequest;
      class UntagResourceRequest;
      class UpdateAccessPolicyRequest;
      class UpdateAssetRequest;
      class UpdateAssetModelRequest;
      class UpdateAssetModelCompositeModelRequest;
      class UpdateAssetPropertyRequest;
      class UpdateComputationModelRequest;
      class UpdateDashboardRequest;
      class UpdateDatasetRequest;
      class UpdateGatewayRequest;
      class UpdateGatewayCapabilityConfigurationRequest;
      class UpdatePortalRequest;
      class UpdateProjectRequest;
      /* End of service model forward declarations required in IoTSiteWiseClient header */

      /* Service model Outcome class definitions */
      typedef Aws::Utils::Outcome<Aws::NoResult, IoTSiteWiseError> AssociateAssetsOutcome;
      typedef Aws::Utils::Outcome<Aws::NoResult, IoTSiteWiseError> AssociateTimeSeriesToAssetPropertyOutcome;
      typedef Aws::Utils::Outcome<BatchAssociateProjectAssetsResult, IoTSiteWiseError> BatchAssociateProjectAssetsOutcome;
      typedef Aws::Utils::Outcome<BatchDisassociateProjectAssetsResult, IoTSiteWiseError> BatchDisassociateProjectAssetsOutcome;
      typedef Aws::Utils::Outcome<BatchGetAssetPropertyAggregatesResult, IoTSiteWiseError> BatchGetAssetPropertyAggregatesOutcome;
      typedef Aws::Utils::Outcome<BatchGetAssetPropertyValueResult, IoTSiteWiseError> BatchGetAssetPropertyValueOutcome;
      typedef Aws::Utils::Outcome<BatchGetAssetPropertyValueHistoryResult, IoTSiteWiseError> BatchGetAssetPropertyValueHistoryOutcome;
      typedef Aws::Utils::Outcome<BatchPutAssetPropertyValueResult, IoTSiteWiseError> BatchPutAssetPropertyValueOutcome;
      typedef Aws::Utils::Outcome<CreateAccessPolicyResult, IoTSiteWiseError> CreateAccessPolicyOutcome;
      typedef Aws::Utils::Outcome<CreateAssetResult, IoTSiteWiseError> CreateAssetOutcome;
      typedef Aws::Utils::Outcome<CreateAssetModelResult, IoTSiteWiseError> CreateAssetModelOutcome;
      typedef Aws::Utils::Outcome<CreateAssetModelCompositeModelResult, IoTSiteWiseError> CreateAssetModelCompositeModelOutcome;
      typedef Aws::Utils::Outcome<CreateBulkImportJobResult, IoTSiteWiseError> CreateBulkImportJobOutcome;
      typedef Aws::Utils::Outcome<CreateComputationModelResult, IoTSiteWiseError> CreateComputationModelOutcome;
      typedef Aws::Utils::Outcome<CreateDashboardResult, IoTSiteWiseError> CreateDashboardOutcome;
      typedef Aws::Utils::Outcome<CreateDatasetResult, IoTSiteWiseError> CreateDatasetOutcome;
      typedef Aws::Utils::Outcome<CreateGatewayResult, IoTSiteWiseError> CreateGatewayOutcome;
      typedef Aws::Utils::Outcome<CreatePortalResult, IoTSiteWiseError> CreatePortalOutcome;
      typedef Aws::Utils::Outcome<CreateProjectResult, IoTSiteWiseError> CreateProjectOutcome;
      typedef Aws::Utils::Outcome<DeleteAccessPolicyResult, IoTSiteWiseError> DeleteAccessPolicyOutcome;
      typedef Aws::Utils::Outcome<DeleteAssetResult, IoTSiteWiseError> DeleteAssetOutcome;
      typedef Aws::Utils::Outcome<DeleteAssetModelResult, IoTSiteWiseError> DeleteAssetModelOutcome;
      typedef Aws::Utils::Outcome<DeleteAssetModelCompositeModelResult, IoTSiteWiseError> DeleteAssetModelCompositeModelOutcome;
      typedef Aws::Utils::Outcome<DeleteComputationModelResult, IoTSiteWiseError> DeleteComputationModelOutcome;
      typedef Aws::Utils::Outcome<DeleteDashboardResult, IoTSiteWiseError> DeleteDashboardOutcome;
      typedef Aws::Utils::Outcome<DeleteDatasetResult, IoTSiteWiseError> DeleteDatasetOutcome;
      typedef Aws::Utils::Outcome<Aws::NoResult, IoTSiteWiseError> DeleteGatewayOutcome;
      typedef Aws::Utils::Outcome<DeletePortalResult, IoTSiteWiseError> DeletePortalOutcome;
      typedef Aws::Utils::Outcome<DeleteProjectResult, IoTSiteWiseError> DeleteProjectOutcome;
      typedef Aws::Utils::Outcome<Aws::NoResult, IoTSiteWiseError> DeleteTimeSeriesOutcome;
      typedef Aws::Utils::Outcome<DescribeAccessPolicyResult, IoTSiteWiseError> DescribeAccessPolicyOutcome;
      typedef Aws::Utils::Outcome<DescribeActionResult, IoTSiteWiseError> DescribeActionOutcome;
      typedef Aws::Utils::Outcome<DescribeAssetResult, IoTSiteWiseError> DescribeAssetOutcome;
      typedef Aws::Utils::Outcome<DescribeAssetCompositeModelResult, IoTSiteWiseError> DescribeAssetCompositeModelOutcome;
      typedef Aws::Utils::Outcome<DescribeAssetModelResult, IoTSiteWiseError> DescribeAssetModelOutcome;
      typedef Aws::Utils::Outcome<DescribeAssetModelCompositeModelResult, IoTSiteWiseError> DescribeAssetModelCompositeModelOutcome;
      typedef Aws::Utils::Outcome<DescribeAssetPropertyResult, IoTSiteWiseError> DescribeAssetPropertyOutcome;
      typedef Aws::Utils::Outcome<DescribeBulkImportJobResult, IoTSiteWiseError> DescribeBulkImportJobOutcome;
      typedef Aws::Utils::Outcome<DescribeComputationModelResult, IoTSiteWiseError> DescribeComputationModelOutcome;
      typedef Aws::Utils::Outcome<DescribeComputationModelExecutionSummaryResult, IoTSiteWiseError> DescribeComputationModelExecutionSummaryOutcome;
      typedef Aws::Utils::Outcome<DescribeDashboardResult, IoTSiteWiseError> DescribeDashboardOutcome;
      typedef Aws::Utils::Outcome<DescribeDatasetResult, IoTSiteWiseError> DescribeDatasetOutcome;
      typedef Aws::Utils::Outcome<DescribeDefaultEncryptionConfigurationResult, IoTSiteWiseError> DescribeDefaultEncryptionConfigurationOutcome;
      typedef Aws::Utils::Outcome<DescribeExecutionResult, IoTSiteWiseError> DescribeExecutionOutcome;
      typedef Aws::Utils::Outcome<DescribeGatewayResult, IoTSiteWiseError> DescribeGatewayOutcome;
      typedef Aws::Utils::Outcome<DescribeGatewayCapabilityConfigurationResult, IoTSiteWiseError> DescribeGatewayCapabilityConfigurationOutcome;
      typedef Aws::Utils::Outcome<DescribeLoggingOptionsResult, IoTSiteWiseError> DescribeLoggingOptionsOutcome;
      typedef Aws::Utils::Outcome<DescribePortalResult, IoTSiteWiseError> DescribePortalOutcome;
      typedef Aws::Utils::Outcome<DescribeProjectResult, IoTSiteWiseError> DescribeProjectOutcome;
      typedef Aws::Utils::Outcome<DescribeStorageConfigurationResult, IoTSiteWiseError> DescribeStorageConfigurationOutcome;
      typedef Aws::Utils::Outcome<DescribeTimeSeriesResult, IoTSiteWiseError> DescribeTimeSeriesOutcome;
      typedef Aws::Utils::Outcome<Aws::NoResult, IoTSiteWiseError> DisassociateAssetsOutcome;
      typedef Aws::Utils::Outcome<Aws::NoResult, IoTSiteWiseError> DisassociateTimeSeriesFromAssetPropertyOutcome;
      typedef Aws::Utils::Outcome<ExecuteActionResult, IoTSiteWiseError> ExecuteActionOutcome;
      typedef Aws::Utils::Outcome<ExecuteQueryResult, IoTSiteWiseError> ExecuteQueryOutcome;
      typedef Aws::Utils::Outcome<GetAssetPropertyAggregatesResult, IoTSiteWiseError> GetAssetPropertyAggregatesOutcome;
      typedef Aws::Utils::Outcome<GetAssetPropertyValueResult, IoTSiteWiseError> GetAssetPropertyValueOutcome;
      typedef Aws::Utils::Outcome<GetAssetPropertyValueHistoryResult, IoTSiteWiseError> GetAssetPropertyValueHistoryOutcome;
      typedef Aws::Utils::Outcome<GetInterpolatedAssetPropertyValuesResult, IoTSiteWiseError> GetInterpolatedAssetPropertyValuesOutcome;
      typedef Aws::Utils::Outcome<Aws::NoResult, IoTSiteWiseError> InvokeAssistantOutcome;
      typedef Aws::Utils::Outcome<ListAccessPoliciesResult, IoTSiteWiseError> ListAccessPoliciesOutcome;
      typedef Aws::Utils::Outcome<ListActionsResult, IoTSiteWiseError> ListActionsOutcome;
      typedef Aws::Utils::Outcome<ListAssetModelCompositeModelsResult, IoTSiteWiseError> ListAssetModelCompositeModelsOutcome;
      typedef Aws::Utils::Outcome<ListAssetModelPropertiesResult, IoTSiteWiseError> ListAssetModelPropertiesOutcome;
      typedef Aws::Utils::Outcome<ListAssetModelsResult, IoTSiteWiseError> ListAssetModelsOutcome;
      typedef Aws::Utils::Outcome<ListAssetPropertiesResult, IoTSiteWiseError> ListAssetPropertiesOutcome;
      typedef Aws::Utils::Outcome<ListAssetRelationshipsResult, IoTSiteWiseError> ListAssetRelationshipsOutcome;
      typedef Aws::Utils::Outcome<ListAssetsResult, IoTSiteWiseError> ListAssetsOutcome;
      typedef Aws::Utils::Outcome<ListAssociatedAssetsResult, IoTSiteWiseError> ListAssociatedAssetsOutcome;
      typedef Aws::Utils::Outcome<ListBulkImportJobsResult, IoTSiteWiseError> ListBulkImportJobsOutcome;
      typedef Aws::Utils::Outcome<ListCompositionRelationshipsResult, IoTSiteWiseError> ListCompositionRelationshipsOutcome;
      typedef Aws::Utils::Outcome<ListComputationModelDataBindingUsagesResult, IoTSiteWiseError> ListComputationModelDataBindingUsagesOutcome;
      typedef Aws::Utils::Outcome<ListComputationModelResolveToResourcesResult, IoTSiteWiseError> ListComputationModelResolveToResourcesOutcome;
      typedef Aws::Utils::Outcome<ListComputationModelsResult, IoTSiteWiseError> ListComputationModelsOutcome;
      typedef Aws::Utils::Outcome<ListDashboardsResult, IoTSiteWiseError> ListDashboardsOutcome;
      typedef Aws::Utils::Outcome<ListDatasetsResult, IoTSiteWiseError> ListDatasetsOutcome;
      typedef Aws::Utils::Outcome<ListExecutionsResult, IoTSiteWiseError> ListExecutionsOutcome;
      typedef Aws::Utils::Outcome<ListGatewaysResult, IoTSiteWiseError> ListGatewaysOutcome;
      typedef Aws::Utils::Outcome<ListPortalsResult, IoTSiteWiseError> ListPortalsOutcome;
      typedef Aws::Utils::Outcome<ListProjectAssetsResult, IoTSiteWiseError> ListProjectAssetsOutcome;
      typedef Aws::Utils::Outcome<ListProjectsResult, IoTSiteWiseError> ListProjectsOutcome;
      typedef Aws::Utils::Outcome<ListTagsForResourceResult, IoTSiteWiseError> ListTagsForResourceOutcome;
      typedef Aws::Utils::Outcome<ListTimeSeriesResult, IoTSiteWiseError> ListTimeSeriesOutcome;
      typedef Aws::Utils::Outcome<PutDefaultEncryptionConfigurationResult, IoTSiteWiseError> PutDefaultEncryptionConfigurationOutcome;
      typedef Aws::Utils::Outcome<PutLoggingOptionsResult, IoTSiteWiseError> PutLoggingOptionsOutcome;
      typedef Aws::Utils::Outcome<PutStorageConfigurationResult, IoTSiteWiseError> PutStorageConfigurationOutcome;
      typedef Aws::Utils::Outcome<TagResourceResult, IoTSiteWiseError> TagResourceOutcome;
      typedef Aws::Utils::Outcome<UntagResourceResult, IoTSiteWiseError> UntagResourceOutcome;
      typedef Aws::Utils::Outcome<UpdateAccessPolicyResult, IoTSiteWiseError> UpdateAccessPolicyOutcome;
      typedef Aws::Utils::Outcome<UpdateAssetResult, IoTSiteWiseError> UpdateAssetOutcome;
      typedef Aws::Utils::Outcome<UpdateAssetModelResult, IoTSiteWiseError> UpdateAssetModelOutcome;
      typedef Aws::Utils::Outcome<UpdateAssetModelCompositeModelResult, IoTSiteWiseError> UpdateAssetModelCompositeModelOutcome;
      typedef Aws::Utils::Outcome<Aws::NoResult, IoTSiteWiseError> UpdateAssetPropertyOutcome;
      typedef Aws::Utils::Outcome<UpdateComputationModelResult, IoTSiteWiseError> UpdateComputationModelOutcome;
      typedef Aws::Utils::Outcome<UpdateDashboardResult, IoTSiteWiseError> UpdateDashboardOutcome;
      typedef Aws::Utils::Outcome<UpdateDatasetResult, IoTSiteWiseError> UpdateDatasetOutcome;
      typedef Aws::Utils::Outcome<Aws::NoResult, IoTSiteWiseError> UpdateGatewayOutcome;
      typedef Aws::Utils::Outcome<UpdateGatewayCapabilityConfigurationResult, IoTSiteWiseError> UpdateGatewayCapabilityConfigurationOutcome;
      typedef Aws::Utils::Outcome<UpdatePortalResult, IoTSiteWiseError> UpdatePortalOutcome;
      typedef Aws::Utils::Outcome<UpdateProjectResult, IoTSiteWiseError> UpdateProjectOutcome;
      /* End of service model Outcome class definitions */

      /* Service model Outcome callable definitions */
      typedef std::future<AssociateAssetsOutcome> AssociateAssetsOutcomeCallable;
      typedef std::future<AssociateTimeSeriesToAssetPropertyOutcome> AssociateTimeSeriesToAssetPropertyOutcomeCallable;
      typedef std::future<BatchAssociateProjectAssetsOutcome> BatchAssociateProjectAssetsOutcomeCallable;
      typedef std::future<BatchDisassociateProjectAssetsOutcome> BatchDisassociateProjectAssetsOutcomeCallable;
      typedef std::future<BatchGetAssetPropertyAggregatesOutcome> BatchGetAssetPropertyAggregatesOutcomeCallable;
      typedef std::future<BatchGetAssetPropertyValueOutcome> BatchGetAssetPropertyValueOutcomeCallable;
      typedef std::future<BatchGetAssetPropertyValueHistoryOutcome> BatchGetAssetPropertyValueHistoryOutcomeCallable;
      typedef std::future<BatchPutAssetPropertyValueOutcome> BatchPutAssetPropertyValueOutcomeCallable;
      typedef std::future<CreateAccessPolicyOutcome> CreateAccessPolicyOutcomeCallable;
      typedef std::future<CreateAssetOutcome> CreateAssetOutcomeCallable;
      typedef std::future<CreateAssetModelOutcome> CreateAssetModelOutcomeCallable;
      typedef std::future<CreateAssetModelCompositeModelOutcome> CreateAssetModelCompositeModelOutcomeCallable;
      typedef std::future<CreateBulkImportJobOutcome> CreateBulkImportJobOutcomeCallable;
      typedef std::future<CreateComputationModelOutcome> CreateComputationModelOutcomeCallable;
      typedef std::future<CreateDashboardOutcome> CreateDashboardOutcomeCallable;
      typedef std::future<CreateDatasetOutcome> CreateDatasetOutcomeCallable;
      typedef std::future<CreateGatewayOutcome> CreateGatewayOutcomeCallable;
      typedef std::future<CreatePortalOutcome> CreatePortalOutcomeCallable;
      typedef std::future<CreateProjectOutcome> CreateProjectOutcomeCallable;
      typedef std::future<DeleteAccessPolicyOutcome> DeleteAccessPolicyOutcomeCallable;
      typedef std::future<DeleteAssetOutcome> DeleteAssetOutcomeCallable;
      typedef std::future<DeleteAssetModelOutcome> DeleteAssetModelOutcomeCallable;
      typedef std::future<DeleteAssetModelCompositeModelOutcome> DeleteAssetModelCompositeModelOutcomeCallable;
      typedef std::future<DeleteComputationModelOutcome> DeleteComputationModelOutcomeCallable;
      typedef std::future<DeleteDashboardOutcome> DeleteDashboardOutcomeCallable;
      typedef std::future<DeleteDatasetOutcome> DeleteDatasetOutcomeCallable;
      typedef std::future<DeleteGatewayOutcome> DeleteGatewayOutcomeCallable;
      typedef std::future<DeletePortalOutcome> DeletePortalOutcomeCallable;
      typedef std::future<DeleteProjectOutcome> DeleteProjectOutcomeCallable;
      typedef std::future<DeleteTimeSeriesOutcome> DeleteTimeSeriesOutcomeCallable;
      typedef std::future<DescribeAccessPolicyOutcome> DescribeAccessPolicyOutcomeCallable;
      typedef std::future<DescribeActionOutcome> DescribeActionOutcomeCallable;
      typedef std::future<DescribeAssetOutcome> DescribeAssetOutcomeCallable;
      typedef std::future<DescribeAssetCompositeModelOutcome> DescribeAssetCompositeModelOutcomeCallable;
      typedef std::future<DescribeAssetModelOutcome> DescribeAssetModelOutcomeCallable;
      typedef std::future<DescribeAssetModelCompositeModelOutcome> DescribeAssetModelCompositeModelOutcomeCallable;
      typedef std::future<DescribeAssetPropertyOutcome> DescribeAssetPropertyOutcomeCallable;
      typedef std::future<DescribeBulkImportJobOutcome> DescribeBulkImportJobOutcomeCallable;
      typedef std::future<DescribeComputationModelOutcome> DescribeComputationModelOutcomeCallable;
      typedef std::future<DescribeComputationModelExecutionSummaryOutcome> DescribeComputationModelExecutionSummaryOutcomeCallable;
      typedef std::future<DescribeDashboardOutcome> DescribeDashboardOutcomeCallable;
      typedef std::future<DescribeDatasetOutcome> DescribeDatasetOutcomeCallable;
      typedef std::future<DescribeDefaultEncryptionConfigurationOutcome> DescribeDefaultEncryptionConfigurationOutcomeCallable;
      typedef std::future<DescribeExecutionOutcome> DescribeExecutionOutcomeCallable;
      typedef std::future<DescribeGatewayOutcome> DescribeGatewayOutcomeCallable;
      typedef std::future<DescribeGatewayCapabilityConfigurationOutcome> DescribeGatewayCapabilityConfigurationOutcomeCallable;
      typedef std::future<DescribeLoggingOptionsOutcome> DescribeLoggingOptionsOutcomeCallable;
      typedef std::future<DescribePortalOutcome> DescribePortalOutcomeCallable;
      typedef std::future<DescribeProjectOutcome> DescribeProjectOutcomeCallable;
      typedef std::future<DescribeStorageConfigurationOutcome> DescribeStorageConfigurationOutcomeCallable;
      typedef std::future<DescribeTimeSeriesOutcome> DescribeTimeSeriesOutcomeCallable;
      typedef std::future<DisassociateAssetsOutcome> DisassociateAssetsOutcomeCallable;
      typedef std::future<DisassociateTimeSeriesFromAssetPropertyOutcome> DisassociateTimeSeriesFromAssetPropertyOutcomeCallable;
      typedef std::future<ExecuteActionOutcome> ExecuteActionOutcomeCallable;
      typedef std::future<ExecuteQueryOutcome> ExecuteQueryOutcomeCallable;
      typedef std::future<GetAssetPropertyAggregatesOutcome> GetAssetPropertyAggregatesOutcomeCallable;
      typedef std::future<GetAssetPropertyValueOutcome> GetAssetPropertyValueOutcomeCallable;
      typedef std::future<GetAssetPropertyValueHistoryOutcome> GetAssetPropertyValueHistoryOutcomeCallable;
      typedef std::future<GetInterpolatedAssetPropertyValuesOutcome> GetInterpolatedAssetPropertyValuesOutcomeCallable;
      typedef std::future<InvokeAssistantOutcome> InvokeAssistantOutcomeCallable;
      typedef std::future<ListAccessPoliciesOutcome> ListAccessPoliciesOutcomeCallable;
      typedef std::future<ListActionsOutcome> ListActionsOutcomeCallable;
      typedef std::future<ListAssetModelCompositeModelsOutcome> ListAssetModelCompositeModelsOutcomeCallable;
      typedef std::future<ListAssetModelPropertiesOutcome> ListAssetModelPropertiesOutcomeCallable;
      typedef std::future<ListAssetModelsOutcome> ListAssetModelsOutcomeCallable;
      typedef std::future<ListAssetPropertiesOutcome> ListAssetPropertiesOutcomeCallable;
      typedef std::future<ListAssetRelationshipsOutcome> ListAssetRelationshipsOutcomeCallable;
      typedef std::future<ListAssetsOutcome> ListAssetsOutcomeCallable;
      typedef std::future<ListAssociatedAssetsOutcome> ListAssociatedAssetsOutcomeCallable;
      typedef std::future<ListBulkImportJobsOutcome> ListBulkImportJobsOutcomeCallable;
      typedef std::future<ListCompositionRelationshipsOutcome> ListCompositionRelationshipsOutcomeCallable;
      typedef std::future<ListComputationModelDataBindingUsagesOutcome> ListComputationModelDataBindingUsagesOutcomeCallable;
      typedef std::future<ListComputationModelResolveToResourcesOutcome> ListComputationModelResolveToResourcesOutcomeCallable;
      typedef std::future<ListComputationModelsOutcome> ListComputationModelsOutcomeCallable;
      typedef std::future<ListDashboardsOutcome> ListDashboardsOutcomeCallable;
      typedef std::future<ListDatasetsOutcome> ListDatasetsOutcomeCallable;
      typedef std::future<ListExecutionsOutcome> ListExecutionsOutcomeCallable;
      typedef std::future<ListGatewaysOutcome> ListGatewaysOutcomeCallable;
      typedef std::future<ListPortalsOutcome> ListPortalsOutcomeCallable;
      typedef std::future<ListProjectAssetsOutcome> ListProjectAssetsOutcomeCallable;
      typedef std::future<ListProjectsOutcome> ListProjectsOutcomeCallable;
      typedef std::future<ListTagsForResourceOutcome> ListTagsForResourceOutcomeCallable;
      typedef std::future<ListTimeSeriesOutcome> ListTimeSeriesOutcomeCallable;
      typedef std::future<PutDefaultEncryptionConfigurationOutcome> PutDefaultEncryptionConfigurationOutcomeCallable;
      typedef std::future<PutLoggingOptionsOutcome> PutLoggingOptionsOutcomeCallable;
      typedef std::future<PutStorageConfigurationOutcome> PutStorageConfigurationOutcomeCallable;
      typedef std::future<TagResourceOutcome> TagResourceOutcomeCallable;
      typedef std::future<UntagResourceOutcome> UntagResourceOutcomeCallable;
      typedef std::future<UpdateAccessPolicyOutcome> UpdateAccessPolicyOutcomeCallable;
      typedef std::future<UpdateAssetOutcome> UpdateAssetOutcomeCallable;
      typedef std::future<UpdateAssetModelOutcome> UpdateAssetModelOutcomeCallable;
      typedef std::future<UpdateAssetModelCompositeModelOutcome> UpdateAssetModelCompositeModelOutcomeCallable;
      typedef std::future<UpdateAssetPropertyOutcome> UpdateAssetPropertyOutcomeCallable;
      typedef std::future<UpdateComputationModelOutcome> UpdateComputationModelOutcomeCallable;
      typedef std::future<UpdateDashboardOutcome> UpdateDashboardOutcomeCallable;
      typedef std::future<UpdateDatasetOutcome> UpdateDatasetOutcomeCallable;
      typedef std::future<UpdateGatewayOutcome> UpdateGatewayOutcomeCallable;
      typedef std::future<UpdateGatewayCapabilityConfigurationOutcome> UpdateGatewayCapabilityConfigurationOutcomeCallable;
      typedef std::future<UpdatePortalOutcome> UpdatePortalOutcomeCallable;
      typedef std::future<UpdateProjectOutcome> UpdateProjectOutcomeCallable;
      /* End of service model Outcome callable definitions */
    } // namespace Model

    class IoTSiteWiseClient;

    /* Service model async handlers definitions */
    typedef std::function<void(const IoTSiteWiseClient*, const Model::AssociateAssetsRequest&, const Model::AssociateAssetsOutcome&, const std::shared_ptr<const Aws::Client::AsyncCallerContext>&) > AssociateAssetsResponseReceivedHandler;
    typedef std::function<void(const IoTSiteWiseClient*, const Model::AssociateTimeSeriesToAssetPropertyRequest&, const Model::AssociateTimeSeriesToAssetPropertyOutcome&, const std::shared_ptr<const Aws::Client::AsyncCallerContext>&) > AssociateTimeSeriesToAssetPropertyResponseReceivedHandler;
    typedef std::function<void(const IoTSiteWiseClient*, const Model::BatchAssociateProjectAssetsRequest&, const Model::BatchAssociateProjectAssetsOutcome&, const std::shared_ptr<const Aws::Client::AsyncCallerContext>&) > BatchAssociateProjectAssetsResponseReceivedHandler;
    typedef std::function<void(const IoTSiteWiseClient*, const Model::BatchDisassociateProjectAssetsRequest&, const Model::BatchDisassociateProjectAssetsOutcome&, const std::shared_ptr<const Aws::Client::AsyncCallerContext>&) > BatchDisassociateProjectAssetsResponseReceivedHandler;
    typedef std::function<void(const IoTSiteWiseClient*, const Model::BatchGetAssetPropertyAggregatesRequest&, const Model::BatchGetAssetPropertyAggregatesOutcome&, const std::shared_ptr<const Aws::Client::AsyncCallerContext>&) > BatchGetAssetPropertyAggregatesResponseReceivedHandler;
    typedef std::function<void(const IoTSiteWiseClient*, const Model::BatchGetAssetPropertyValueRequest&, const Model::BatchGetAssetPropertyValueOutcome&, const std::shared_ptr<const Aws::Client::AsyncCallerContext>&) > BatchGetAssetPropertyValueResponseReceivedHandler;
    typedef std::function<void(const IoTSiteWiseClient*, const Model::BatchGetAssetPropertyValueHistoryRequest&, const Model::BatchGetAssetPropertyValueHistoryOutcome&, const std::shared_ptr<const Aws::Client::AsyncCallerContext>&) > BatchGetAssetPropertyValueHistoryResponseReceivedHandler;
    typedef std::function<void(const IoTSiteWiseClient*, const Model::BatchPutAssetPropertyValueRequest&, const Model::BatchPutAssetPropertyValueOutcome&, const std::shared_ptr<const Aws::Client::AsyncCallerContext>&) > BatchPutAssetPropertyValueResponseReceivedHandler;
    typedef std::function<void(const IoTSiteWiseClient*, const Model::CreateAccessPolicyRequest&, const Model::CreateAccessPolicyOutcome&, const std::shared_ptr<const Aws::Client::AsyncCallerContext>&) > CreateAccessPolicyResponseReceivedHandler;
    typedef std::function<void(const IoTSiteWiseClient*, const Model::CreateAssetRequest&, const Model::CreateAssetOutcome&, const std::shared_ptr<const Aws::Client::AsyncCallerContext>&) > CreateAssetResponseReceivedHandler;
    typedef std::function<void(const IoTSiteWiseClient*, const Model::CreateAssetModelRequest&, const Model::CreateAssetModelOutcome&, const std::shared_ptr<const Aws::Client::AsyncCallerContext>&) > CreateAssetModelResponseReceivedHandler;
    typedef std::function<void(const IoTSiteWiseClient*, const Model::CreateAssetModelCompositeModelRequest&, const Model::CreateAssetModelCompositeModelOutcome&, const std::shared_ptr<const Aws::Client::AsyncCallerContext>&) > CreateAssetModelCompositeModelResponseReceivedHandler;
    typedef std::function<void(const IoTSiteWiseClient*, const Model::CreateBulkImportJobRequest&, const Model::CreateBulkImportJobOutcome&, const std::shared_ptr<const Aws::Client::AsyncCallerContext>&) > CreateBulkImportJobResponseReceivedHandler;
    typedef std::function<void(const IoTSiteWiseClient*, const Model::CreateComputationModelRequest&, const Model::CreateComputationModelOutcome&, const std::shared_ptr<const Aws::Client::AsyncCallerContext>&) > CreateComputationModelResponseReceivedHandler;
    typedef std::function<void(const IoTSiteWiseClient*, const Model::CreateDashboardRequest&, const Model::CreateDashboardOutcome&, const std::shared_ptr<const Aws::Client::AsyncCallerContext>&) > CreateDashboardResponseReceivedHandler;
    typedef std::function<void(const IoTSiteWiseClient*, const Model::CreateDatasetRequest&, const Model::CreateDatasetOutcome&, const std::shared_ptr<const Aws::Client::AsyncCallerContext>&) > CreateDatasetResponseReceivedHandler;
    typedef std::function<void(const IoTSiteWiseClient*, const Model::CreateGatewayRequest&, const Model::CreateGatewayOutcome&, const std::shared_ptr<const Aws::Client::AsyncCallerContext>&) > CreateGatewayResponseReceivedHandler;
    typedef std::function<void(const IoTSiteWiseClient*, const Model::CreatePortalRequest&, const Model::CreatePortalOutcome&, const std::shared_ptr<const Aws::Client::AsyncCallerContext>&) > CreatePortalResponseReceivedHandler;
    typedef std::function<void(const IoTSiteWiseClient*, const Model::CreateProjectRequest&, const Model::CreateProjectOutcome&, const std::shared_ptr<const Aws::Client::AsyncCallerContext>&) > CreateProjectResponseReceivedHandler;
    typedef std::function<void(const IoTSiteWiseClient*, const Model::DeleteAccessPolicyRequest&, const Model::DeleteAccessPolicyOutcome&, const std::shared_ptr<const Aws::Client::AsyncCallerContext>&) > DeleteAccessPolicyResponseReceivedHandler;
    typedef std::function<void(const IoTSiteWiseClient*, const Model::DeleteAssetRequest&, const Model::DeleteAssetOutcome&, const std::shared_ptr<const Aws::Client::AsyncCallerContext>&) > DeleteAssetResponseReceivedHandler;
    typedef std::function<void(const IoTSiteWiseClient*, const Model::DeleteAssetModelRequest&, const Model::DeleteAssetModelOutcome&, const std::shared_ptr<const Aws::Client::AsyncCallerContext>&) > DeleteAssetModelResponseReceivedHandler;
    typedef std::function<void(const IoTSiteWiseClient*, const Model::DeleteAssetModelCompositeModelRequest&, const Model::DeleteAssetModelCompositeModelOutcome&, const std::shared_ptr<const Aws::Client::AsyncCallerContext>&) > DeleteAssetModelCompositeModelResponseReceivedHandler;
    typedef std::function<void(const IoTSiteWiseClient*, const Model::DeleteComputationModelRequest&, const Model::DeleteComputationModelOutcome&, const std::shared_ptr<const Aws::Client::AsyncCallerContext>&) > DeleteComputationModelResponseReceivedHandler;
    typedef std::function<void(const IoTSiteWiseClient*, const Model::DeleteDashboardRequest&, const Model::DeleteDashboardOutcome&, const std::shared_ptr<const Aws::Client::AsyncCallerContext>&) > DeleteDashboardResponseReceivedHandler;
    typedef std::function<void(const IoTSiteWiseClient*, const Model::DeleteDatasetRequest&, const Model::DeleteDatasetOutcome&, const std::shared_ptr<const Aws::Client::AsyncCallerContext>&) > DeleteDatasetResponseReceivedHandler;
    typedef std::function<void(const IoTSiteWiseClient*, const Model::DeleteGatewayRequest&, const Model::DeleteGatewayOutcome&, const std::shared_ptr<const Aws::Client::AsyncCallerContext>&) > DeleteGatewayResponseReceivedHandler;
    typedef std::function<void(const IoTSiteWiseClient*, const Model::DeletePortalRequest&, const Model::DeletePortalOutcome&, const std::shared_ptr<const Aws::Client::AsyncCallerContext>&) > DeletePortalResponseReceivedHandler;
    typedef std::function<void(const IoTSiteWiseClient*, const Model::DeleteProjectRequest&, const Model::DeleteProjectOutcome&, const std::shared_ptr<const Aws::Client::AsyncCallerContext>&) > DeleteProjectResponseReceivedHandler;
    typedef std::function<void(const IoTSiteWiseClient*, const Model::DeleteTimeSeriesRequest&, const Model::DeleteTimeSeriesOutcome&, const std::shared_ptr<const Aws::Client::AsyncCallerContext>&) > DeleteTimeSeriesResponseReceivedHandler;
    typedef std::function<void(const IoTSiteWiseClient*, const Model::DescribeAccessPolicyRequest&, const Model::DescribeAccessPolicyOutcome&, const std::shared_ptr<const Aws::Client::AsyncCallerContext>&) > DescribeAccessPolicyResponseReceivedHandler;
    typedef std::function<void(const IoTSiteWiseClient*, const Model::DescribeActionRequest&, const Model::DescribeActionOutcome&, const std::shared_ptr<const Aws::Client::AsyncCallerContext>&) > DescribeActionResponseReceivedHandler;
    typedef std::function<void(const IoTSiteWiseClient*, const Model::DescribeAssetRequest&, const Model::DescribeAssetOutcome&, const std::shared_ptr<const Aws::Client::AsyncCallerContext>&) > DescribeAssetResponseReceivedHandler;
    typedef std::function<void(const IoTSiteWiseClient*, const Model::DescribeAssetCompositeModelRequest&, const Model::DescribeAssetCompositeModelOutcome&, const std::shared_ptr<const Aws::Client::AsyncCallerContext>&) > DescribeAssetCompositeModelResponseReceivedHandler;
    typedef std::function<void(const IoTSiteWiseClient*, const Model::DescribeAssetModelRequest&, const Model::DescribeAssetModelOutcome&, const std::shared_ptr<const Aws::Client::AsyncCallerContext>&) > DescribeAssetModelResponseReceivedHandler;
    typedef std::function<void(const IoTSiteWiseClient*, const Model::DescribeAssetModelCompositeModelRequest&, const Model::DescribeAssetModelCompositeModelOutcome&, const std::shared_ptr<const Aws::Client::AsyncCallerContext>&) > DescribeAssetModelCompositeModelResponseReceivedHandler;
    typedef std::function<void(const IoTSiteWiseClient*, const Model::DescribeAssetPropertyRequest&, const Model::DescribeAssetPropertyOutcome&, const std::shared_ptr<const Aws::Client::AsyncCallerContext>&) > DescribeAssetPropertyResponseReceivedHandler;
    typedef std::function<void(const IoTSiteWiseClient*, const Model::DescribeBulkImportJobRequest&, const Model::DescribeBulkImportJobOutcome&, const std::shared_ptr<const Aws::Client::AsyncCallerContext>&) > DescribeBulkImportJobResponseReceivedHandler;
    typedef std::function<void(const IoTSiteWiseClient*, const Model::DescribeComputationModelRequest&, const Model::DescribeComputationModelOutcome&, const std::shared_ptr<const Aws::Client::AsyncCallerContext>&) > DescribeComputationModelResponseReceivedHandler;
    typedef std::function<void(const IoTSiteWiseClient*, const Model::DescribeComputationModelExecutionSummaryRequest&, const Model::DescribeComputationModelExecutionSummaryOutcome&, const std::shared_ptr<const Aws::Client::AsyncCallerContext>&) > DescribeComputationModelExecutionSummaryResponseReceivedHandler;
    typedef std::function<void(const IoTSiteWiseClient*, const Model::DescribeDashboardRequest&, const Model::DescribeDashboardOutcome&, const std::shared_ptr<const Aws::Client::AsyncCallerContext>&) > DescribeDashboardResponseReceivedHandler;
    typedef std::function<void(const IoTSiteWiseClient*, const Model::DescribeDatasetRequest&, const Model::DescribeDatasetOutcome&, const std::shared_ptr<const Aws::Client::AsyncCallerContext>&) > DescribeDatasetResponseReceivedHandler;
    typedef std::function<void(const IoTSiteWiseClient*, const Model::DescribeDefaultEncryptionConfigurationRequest&, const Model::DescribeDefaultEncryptionConfigurationOutcome&, const std::shared_ptr<const Aws::Client::AsyncCallerContext>&) > DescribeDefaultEncryptionConfigurationResponseReceivedHandler;
    typedef std::function<void(const IoTSiteWiseClient*, const Model::DescribeExecutionRequest&, const Model::DescribeExecutionOutcome&, const std::shared_ptr<const Aws::Client::AsyncCallerContext>&) > DescribeExecutionResponseReceivedHandler;
    typedef std::function<void(const IoTSiteWiseClient*, const Model::DescribeGatewayRequest&, const Model::DescribeGatewayOutcome&, const std::shared_ptr<const Aws::Client::AsyncCallerContext>&) > DescribeGatewayResponseReceivedHandler;
    typedef std::function<void(const IoTSiteWiseClient*, const Model::DescribeGatewayCapabilityConfigurationRequest&, const Model::DescribeGatewayCapabilityConfigurationOutcome&, const std::shared_ptr<const Aws::Client::AsyncCallerContext>&) > DescribeGatewayCapabilityConfigurationResponseReceivedHandler;
    typedef std::function<void(const IoTSiteWiseClient*, const Model::DescribeLoggingOptionsRequest&, const Model::DescribeLoggingOptionsOutcome&, const std::shared_ptr<const Aws::Client::AsyncCallerContext>&) > DescribeLoggingOptionsResponseReceivedHandler;
    typedef std::function<void(const IoTSiteWiseClient*, const Model::DescribePortalRequest&, const Model::DescribePortalOutcome&, const std::shared_ptr<const Aws::Client::AsyncCallerContext>&) > DescribePortalResponseReceivedHandler;
    typedef std::function<void(const IoTSiteWiseClient*, const Model::DescribeProjectRequest&, const Model::DescribeProjectOutcome&, const std::shared_ptr<const Aws::Client::AsyncCallerContext>&) > DescribeProjectResponseReceivedHandler;
    typedef std::function<void(const IoTSiteWiseClient*, const Model::DescribeStorageConfigurationRequest&, const Model::DescribeStorageConfigurationOutcome&, const std::shared_ptr<const Aws::Client::AsyncCallerContext>&) > DescribeStorageConfigurationResponseReceivedHandler;
    typedef std::function<void(const IoTSiteWiseClient*, const Model::DescribeTimeSeriesRequest&, const Model::DescribeTimeSeriesOutcome&, const std::shared_ptr<const Aws::Client::AsyncCallerContext>&) > DescribeTimeSeriesResponseReceivedHandler;
    typedef std::function<void(const IoTSiteWiseClient*, const Model::DisassociateAssetsRequest&, const Model::DisassociateAssetsOutcome&, const std::shared_ptr<const Aws::Client::AsyncCallerContext>&) > DisassociateAssetsResponseReceivedHandler;
    typedef std::function<void(const IoTSiteWiseClient*, const Model::DisassociateTimeSeriesFromAssetPropertyRequest&, const Model::DisassociateTimeSeriesFromAssetPropertyOutcome&, const std::shared_ptr<const Aws::Client::AsyncCallerContext>&) > DisassociateTimeSeriesFromAssetPropertyResponseReceivedHandler;
    typedef std::function<void(const IoTSiteWiseClient*, const Model::ExecuteActionRequest&, const Model::ExecuteActionOutcome&, const std::shared_ptr<const Aws::Client::AsyncCallerContext>&) > ExecuteActionResponseReceivedHandler;
    typedef std::function<void(const IoTSiteWiseClient*, const Model::ExecuteQueryRequest&, const Model::ExecuteQueryOutcome&, const std::shared_ptr<const Aws::Client::AsyncCallerContext>&) > ExecuteQueryResponseReceivedHandler;
    typedef std::function<void(const IoTSiteWiseClient*, const Model::GetAssetPropertyAggregatesRequest&, const Model::GetAssetPropertyAggregatesOutcome&, const std::shared_ptr<const Aws::Client::AsyncCallerContext>&) > GetAssetPropertyAggregatesResponseReceivedHandler;
    typedef std::function<void(const IoTSiteWiseClient*, const Model::GetAssetPropertyValueRequest&, const Model::GetAssetPropertyValueOutcome&, const std::shared_ptr<const Aws::Client::AsyncCallerContext>&) > GetAssetPropertyValueResponseReceivedHandler;
    typedef std::function<void(const IoTSiteWiseClient*, const Model::GetAssetPropertyValueHistoryRequest&, const Model::GetAssetPropertyValueHistoryOutcome&, const std::shared_ptr<const Aws::Client::AsyncCallerContext>&) > GetAssetPropertyValueHistoryResponseReceivedHandler;
    typedef std::function<void(const IoTSiteWiseClient*, const Model::GetInterpolatedAssetPropertyValuesRequest&, const Model::GetInterpolatedAssetPropertyValuesOutcome&, const std::shared_ptr<const Aws::Client::AsyncCallerContext>&) > GetInterpolatedAssetPropertyValuesResponseReceivedHandler;
    typedef std::function<void(const IoTSiteWiseClient*, const Model::InvokeAssistantRequest&, const Model::InvokeAssistantOutcome&, const std::shared_ptr<const Aws::Client::AsyncCallerContext>&) > InvokeAssistantResponseReceivedHandler;
    typedef std::function<void(const IoTSiteWiseClient*, const Model::ListAccessPoliciesRequest&, const Model::ListAccessPoliciesOutcome&, const std::shared_ptr<const Aws::Client::AsyncCallerContext>&) > ListAccessPoliciesResponseReceivedHandler;
    typedef std::function<void(const IoTSiteWiseClient*, const Model::ListActionsRequest&, const Model::ListActionsOutcome&, const std::shared_ptr<const Aws::Client::AsyncCallerContext>&) > ListActionsResponseReceivedHandler;
    typedef std::function<void(const IoTSiteWiseClient*, const Model::ListAssetModelCompositeModelsRequest&, const Model::ListAssetModelCompositeModelsOutcome&, const std::shared_ptr<const Aws::Client::AsyncCallerContext>&) > ListAssetModelCompositeModelsResponseReceivedHandler;
    typedef std::function<void(const IoTSiteWiseClient*, const Model::ListAssetModelPropertiesRequest&, const Model::ListAssetModelPropertiesOutcome&, const std::shared_ptr<const Aws::Client::AsyncCallerContext>&) > ListAssetModelPropertiesResponseReceivedHandler;
    typedef std::function<void(const IoTSiteWiseClient*, const Model::ListAssetModelsRequest&, const Model::ListAssetModelsOutcome&, const std::shared_ptr<const Aws::Client::AsyncCallerContext>&) > ListAssetModelsResponseReceivedHandler;
    typedef std::function<void(const IoTSiteWiseClient*, const Model::ListAssetPropertiesRequest&, const Model::ListAssetPropertiesOutcome&, const std::shared_ptr<const Aws::Client::AsyncCallerContext>&) > ListAssetPropertiesResponseReceivedHandler;
    typedef std::function<void(const IoTSiteWiseClient*, const Model::ListAssetRelationshipsRequest&, const Model::ListAssetRelationshipsOutcome&, const std::shared_ptr<const Aws::Client::AsyncCallerContext>&) > ListAssetRelationshipsResponseReceivedHandler;
    typedef std::function<void(const IoTSiteWiseClient*, const Model::ListAssetsRequest&, const Model::ListAssetsOutcome&, const std::shared_ptr<const Aws::Client::AsyncCallerContext>&) > ListAssetsResponseReceivedHandler;
    typedef std::function<void(const IoTSiteWiseClient*, const Model::ListAssociatedAssetsRequest&, const Model::ListAssociatedAssetsOutcome&, const std::shared_ptr<const Aws::Client::AsyncCallerContext>&) > ListAssociatedAssetsResponseReceivedHandler;
    typedef std::function<void(const IoTSiteWiseClient*, const Model::ListBulkImportJobsRequest&, const Model::ListBulkImportJobsOutcome&, const std::shared_ptr<const Aws::Client::AsyncCallerContext>&) > ListBulkImportJobsResponseReceivedHandler;
    typedef std::function<void(const IoTSiteWiseClient*, const Model::ListCompositionRelationshipsRequest&, const Model::ListCompositionRelationshipsOutcome&, const std::shared_ptr<const Aws::Client::AsyncCallerContext>&) > ListCompositionRelationshipsResponseReceivedHandler;
    typedef std::function<void(const IoTSiteWiseClient*, const Model::ListComputationModelDataBindingUsagesRequest&, const Model::ListComputationModelDataBindingUsagesOutcome&, const std::shared_ptr<const Aws::Client::AsyncCallerContext>&) > ListComputationModelDataBindingUsagesResponseReceivedHandler;
    typedef std::function<void(const IoTSiteWiseClient*, const Model::ListComputationModelResolveToResourcesRequest&, const Model::ListComputationModelResolveToResourcesOutcome&, const std::shared_ptr<const Aws::Client::AsyncCallerContext>&) > ListComputationModelResolveToResourcesResponseReceivedHandler;
    typedef std::function<void(const IoTSiteWiseClient*, const Model::ListComputationModelsRequest&, const Model::ListComputationModelsOutcome&, const std::shared_ptr<const Aws::Client::AsyncCallerContext>&) > ListComputationModelsResponseReceivedHandler;
    typedef std::function<void(const IoTSiteWiseClient*, const Model::ListDashboardsRequest&, const Model::ListDashboardsOutcome&, const std::shared_ptr<const Aws::Client::AsyncCallerContext>&) > ListDashboardsResponseReceivedHandler;
    typedef std::function<void(const IoTSiteWiseClient*, const Model::ListDatasetsRequest&, const Model::ListDatasetsOutcome&, const std::shared_ptr<const Aws::Client::AsyncCallerContext>&) > ListDatasetsResponseReceivedHandler;
    typedef std::function<void(const IoTSiteWiseClient*, const Model::ListExecutionsRequest&, const Model::ListExecutionsOutcome&, const std::shared_ptr<const Aws::Client::AsyncCallerContext>&) > ListExecutionsResponseReceivedHandler;
    typedef std::function<void(const IoTSiteWiseClient*, const Model::ListGatewaysRequest&, const Model::ListGatewaysOutcome&, const std::shared_ptr<const Aws::Client::AsyncCallerContext>&) > ListGatewaysResponseReceivedHandler;
    typedef std::function<void(const IoTSiteWiseClient*, const Model::ListPortalsRequest&, const Model::ListPortalsOutcome&, const std::shared_ptr<const Aws::Client::AsyncCallerContext>&) > ListPortalsResponseReceivedHandler;
    typedef std::function<void(const IoTSiteWiseClient*, const Model::ListProjectAssetsRequest&, const Model::ListProjectAssetsOutcome&, const std::shared_ptr<const Aws::Client::AsyncCallerContext>&) > ListProjectAssetsResponseReceivedHandler;
    typedef std::function<void(const IoTSiteWiseClient*, const Model::ListProjectsRequest&, const Model::ListProjectsOutcome&, const std::shared_ptr<const Aws::Client::AsyncCallerContext>&) > ListProjectsResponseReceivedHandler;
    typedef std::function<void(const IoTSiteWiseClient*, const Model::ListTagsForResourceRequest&, const Model::ListTagsForResourceOutcome&, const std::shared_ptr<const Aws::Client::AsyncCallerContext>&) > ListTagsForResourceResponseReceivedHandler;
    typedef std::function<void(const IoTSiteWiseClient*, const Model::ListTimeSeriesRequest&, const Model::ListTimeSeriesOutcome&, const std::shared_ptr<const Aws::Client::AsyncCallerContext>&) > ListTimeSeriesResponseReceivedHandler;
    typedef std::function<void(const IoTSiteWiseClient*, const Model::PutDefaultEncryptionConfigurationRequest&, const Model::PutDefaultEncryptionConfigurationOutcome&, const std::shared_ptr<const Aws::Client::AsyncCallerContext>&) > PutDefaultEncryptionConfigurationResponseReceivedHandler;
    typedef std::function<void(const IoTSiteWiseClient*, const Model::PutLoggingOptionsRequest&, const Model::PutLoggingOptionsOutcome&, const std::shared_ptr<const Aws::Client::AsyncCallerContext>&) > PutLoggingOptionsResponseReceivedHandler;
    typedef std::function<void(const IoTSiteWiseClient*, const Model::PutStorageConfigurationRequest&, const Model::PutStorageConfigurationOutcome&, const std::shared_ptr<const Aws::Client::AsyncCallerContext>&) > PutStorageConfigurationResponseReceivedHandler;
    typedef std::function<void(const IoTSiteWiseClient*, const Model::TagResourceRequest&, const Model::TagResourceOutcome&, const std::shared_ptr<const Aws::Client::AsyncCallerContext>&) > TagResourceResponseReceivedHandler;
    typedef std::function<void(const IoTSiteWiseClient*, const Model::UntagResourceRequest&, const Model::UntagResourceOutcome&, const std::shared_ptr<const Aws::Client::AsyncCallerContext>&) > UntagResourceResponseReceivedHandler;
    typedef std::function<void(const IoTSiteWiseClient*, const Model::UpdateAccessPolicyRequest&, const Model::UpdateAccessPolicyOutcome&, const std::shared_ptr<const Aws::Client::AsyncCallerContext>&) > UpdateAccessPolicyResponseReceivedHandler;
    typedef std::function<void(const IoTSiteWiseClient*, const Model::UpdateAssetRequest&, const Model::UpdateAssetOutcome&, const std::shared_ptr<const Aws::Client::AsyncCallerContext>&) > UpdateAssetResponseReceivedHandler;
    typedef std::function<void(const IoTSiteWiseClient*, const Model::UpdateAssetModelRequest&, const Model::UpdateAssetModelOutcome&, const std::shared_ptr<const Aws::Client::AsyncCallerContext>&) > UpdateAssetModelResponseReceivedHandler;
    typedef std::function<void(const IoTSiteWiseClient*, const Model::UpdateAssetModelCompositeModelRequest&, const Model::UpdateAssetModelCompositeModelOutcome&, const std::shared_ptr<const Aws::Client::AsyncCallerContext>&) > UpdateAssetModelCompositeModelResponseReceivedHandler;
    typedef std::function<void(const IoTSiteWiseClient*, const Model::UpdateAssetPropertyRequest&, const Model::UpdateAssetPropertyOutcome&, const std::shared_ptr<const Aws::Client::AsyncCallerContext>&) > UpdateAssetPropertyResponseReceivedHandler;
    typedef std::function<void(const IoTSiteWiseClient*, const Model::UpdateComputationModelRequest&, const Model::UpdateComputationModelOutcome&, const std::shared_ptr<const Aws::Client::AsyncCallerContext>&) > UpdateComputationModelResponseReceivedHandler;
    typedef std::function<void(const IoTSiteWiseClient*, const Model::UpdateDashboardRequest&, const Model::UpdateDashboardOutcome&, const std::shared_ptr<const Aws::Client::AsyncCallerContext>&) > UpdateDashboardResponseReceivedHandler;
    typedef std::function<void(const IoTSiteWiseClient*, const Model::UpdateDatasetRequest&, const Model::UpdateDatasetOutcome&, const std::shared_ptr<const Aws::Client::AsyncCallerContext>&) > UpdateDatasetResponseReceivedHandler;
    typedef std::function<void(const IoTSiteWiseClient*, const Model::UpdateGatewayRequest&, const Model::UpdateGatewayOutcome&, const std::shared_ptr<const Aws::Client::AsyncCallerContext>&) > UpdateGatewayResponseReceivedHandler;
    typedef std::function<void(const IoTSiteWiseClient*, const Model::UpdateGatewayCapabilityConfigurationRequest&, const Model::UpdateGatewayCapabilityConfigurationOutcome&, const std::shared_ptr<const Aws::Client::AsyncCallerContext>&) > UpdateGatewayCapabilityConfigurationResponseReceivedHandler;
    typedef std::function<void(const IoTSiteWiseClient*, const Model::UpdatePortalRequest&, const Model::UpdatePortalOutcome&, const std::shared_ptr<const Aws::Client::AsyncCallerContext>&) > UpdatePortalResponseReceivedHandler;
    typedef std::function<void(const IoTSiteWiseClient*, const Model::UpdateProjectRequest&, const Model::UpdateProjectOutcome&, const std::shared_ptr<const Aws::Client::AsyncCallerContext>&) > UpdateProjectResponseReceivedHandler;
    /* End of service model async handlers definitions */
  } // namespace IoTSiteWise
} // namespace Aws
