/**
 * Copyright Amazon.com, Inc. or its affiliates. All Rights Reserved.
 * SPDX-License-Identifier: Apache-2.0.
 */

#include <gtest/gtest.h>
#include <aws/testing/AwsTestHelpers.h>

#include <aws/opensearch/OpenSearchServiceClient.h>
#include <aws/opensearch/OpenSearchServiceEndpointProvider.h>
#include <aws/opensearch/OpenSearchServiceEndpointRules.h>
#include <aws/opensearch/OpenSearchServiceErrorMarshaller.h>
#include <aws/opensearch/OpenSearchServiceErrors.h>
#include <aws/opensearch/OpenSearchServiceRequest.h>
#include <aws/opensearch/OpenSearchServiceServiceClientModel.h>
#include <aws/opensearch/OpenSearchService_EXPORTS.h>
#include <aws/opensearch/model/AIMLOptionsInput.h>
#include <aws/opensearch/model/AIMLOptionsOutput.h>
#include <aws/opensearch/model/AIMLOptionsStatus.h>
#include <aws/opensearch/model/AWSDomainInformation.h>
#include <aws/opensearch/model/AWSServicePrincipal.h>
#include <aws/opensearch/model/AcceptInboundConnectionRequest.h>
#include <aws/opensearch/model/AcceptInboundConnectionResult.h>
#include <aws/opensearch/model/AccessPoliciesStatus.h>
#include <aws/opensearch/model/ActionSeverity.h>
#include <aws/opensearch/model/ActionStatus.h>
#include <aws/opensearch/model/ActionType.h>
#include <aws/opensearch/model/AddDataSourceRequest.h>
#include <aws/opensearch/model/AddDataSourceResult.h>
#include <aws/opensearch/model/AddDirectQueryDataSourceRequest.h>
#include <aws/opensearch/model/AddDirectQueryDataSourceResult.h>
#include <aws/opensearch/model/AddTagsRequest.h>
#include <aws/opensearch/model/AdditionalLimit.h>
#include <aws/opensearch/model/AdvancedOptionsStatus.h>
#include <aws/opensearch/model/AdvancedSecurityOptions.h>
#include <aws/opensearch/model/AdvancedSecurityOptionsInput.h>
#include <aws/opensearch/model/AdvancedSecurityOptionsStatus.h>
#include <aws/opensearch/model/AppConfig.h>
#include <aws/opensearch/model/AppConfigType.h>
#include <aws/opensearch/model/ApplicationStatus.h>
#include <aws/opensearch/model/ApplicationSummary.h>
#include <aws/opensearch/model/AssociatePackageRequest.h>
#include <aws/opensearch/model/AssociatePackageResult.h>
#include <aws/opensearch/model/AssociatePackagesRequest.h>
#include <aws/opensearch/model/AssociatePackagesResult.h>
#include <aws/opensearch/model/AuthorizeVpcEndpointAccessRequest.h>
#include <aws/opensearch/model/AuthorizeVpcEndpointAccessResult.h>
#include <aws/opensearch/model/AuthorizedPrincipal.h>
#include <aws/opensearch/model/AutoTune.h>
#include <aws/opensearch/model/AutoTuneDesiredState.h>
#include <aws/opensearch/model/AutoTuneDetails.h>
#include <aws/opensearch/model/AutoTuneMaintenanceSchedule.h>
#include <aws/opensearch/model/AutoTuneOptions.h>
#include <aws/opensearch/model/AutoTuneOptionsInput.h>
#include <aws/opensearch/model/AutoTuneOptionsOutput.h>
#include <aws/opensearch/model/AutoTuneOptionsStatus.h>
#include <aws/opensearch/model/AutoTuneState.h>
#include <aws/opensearch/model/AutoTuneStatus.h>
#include <aws/opensearch/model/AutoTuneType.h>
#include <aws/opensearch/model/AvailabilityZoneInfo.h>
#include <aws/opensearch/model/CancelDomainConfigChangeRequest.h>
#include <aws/opensearch/model/CancelDomainConfigChangeResult.h>
#include <aws/opensearch/model/CancelServiceSoftwareUpdateRequest.h>
#include <aws/opensearch/model/CancelServiceSoftwareUpdateResult.h>
#include <aws/opensearch/model/CancelledChangeProperty.h>
#include <aws/opensearch/model/ChangeProgressDetails.h>
#include <aws/opensearch/model/ChangeProgressStage.h>
#include <aws/opensearch/model/ChangeProgressStatusDetails.h>
#include <aws/opensearch/model/CloudWatchDirectQueryDataSource.h>
#include <aws/opensearch/model/ClusterConfig.h>
#include <aws/opensearch/model/ClusterConfigStatus.h>
#include <aws/opensearch/model/CognitoOptions.h>
#include <aws/opensearch/model/CognitoOptionsStatus.h>
#include <aws/opensearch/model/ColdStorageOptions.h>
#include <aws/opensearch/model/CompatibleVersionsMap.h>
#include <aws/opensearch/model/ConfigChangeStatus.h>
#include <aws/opensearch/model/ConnectionMode.h>
#include <aws/opensearch/model/ConnectionProperties.h>
#include <aws/opensearch/model/CreateApplicationRequest.h>
#include <aws/opensearch/model/CreateApplicationResult.h>
#include <aws/opensearch/model/CreateDomainRequest.h>
#include <aws/opensearch/model/CreateDomainResult.h>
#include <aws/opensearch/model/CreateOutboundConnectionRequest.h>
#include <aws/opensearch/model/CreateOutboundConnectionResult.h>
#include <aws/opensearch/model/CreatePackageRequest.h>
#include <aws/opensearch/model/CreatePackageResult.h>
#include <aws/opensearch/model/CreateVpcEndpointRequest.h>
#include <aws/opensearch/model/CreateVpcEndpointResult.h>
#include <aws/opensearch/model/CrossClusterSearchConnectionProperties.h>
#include <aws/opensearch/model/DataSource.h>
#include <aws/opensearch/model/DataSourceDetails.h>
#include <aws/opensearch/model/DataSourceStatus.h>
#include <aws/opensearch/model/DataSourceType.h>
#include <aws/opensearch/model/DeleteApplicationRequest.h>
#include <aws/opensearch/model/DeleteApplicationResult.h>
#include <aws/opensearch/model/DeleteDataSourceRequest.h>
#include <aws/opensearch/model/DeleteDataSourceResult.h>
#include <aws/opensearch/model/DeleteDirectQueryDataSourceRequest.h>
#include <aws/opensearch/model/DeleteDomainRequest.h>
#include <aws/opensearch/model/DeleteDomainResult.h>
#include <aws/opensearch/model/DeleteInboundConnectionRequest.h>
#include <aws/opensearch/model/DeleteInboundConnectionResult.h>
#include <aws/opensearch/model/DeleteOutboundConnectionRequest.h>
#include <aws/opensearch/model/DeleteOutboundConnectionResult.h>
#include <aws/opensearch/model/DeletePackageRequest.h>
#include <aws/opensearch/model/DeletePackageResult.h>
#include <aws/opensearch/model/DeleteVpcEndpointRequest.h>
#include <aws/opensearch/model/DeleteVpcEndpointResult.h>
#include <aws/opensearch/model/DeploymentStatus.h>
#include <aws/opensearch/model/DescribeDomainAutoTunesRequest.h>
#include <aws/opensearch/model/DescribeDomainAutoTunesResult.h>
#include <aws/opensearch/model/DescribeDomainChangeProgressRequest.h>
#include <aws/opensearch/model/DescribeDomainChangeProgressResult.h>
#include <aws/opensearch/model/DescribeDomainConfigRequest.h>
#include <aws/opensearch/model/DescribeDomainConfigResult.h>
#include <aws/opensearch/model/DescribeDomainHealthRequest.h>
#include <aws/opensearch/model/DescribeDomainHealthResult.h>
#include <aws/opensearch/model/DescribeDomainNodesRequest.h>
#include <aws/opensearch/model/DescribeDomainNodesResult.h>
#include <aws/opensearch/model/DescribeDomainRequest.h>
#include <aws/opensearch/model/DescribeDomainResult.h>
#include <aws/opensearch/model/DescribeDomainsRequest.h>
#include <aws/opensearch/model/DescribeDomainsResult.h>
#include <aws/opensearch/model/DescribeDryRunProgressRequest.h>
#include <aws/opensearch/model/DescribeDryRunProgressResult.h>
#include <aws/opensearch/model/DescribeInboundConnectionsRequest.h>
#include <aws/opensearch/model/DescribeInboundConnectionsResult.h>
#include <aws/opensearch/model/DescribeInstanceTypeLimitsRequest.h>
#include <aws/opensearch/model/DescribeInstanceTypeLimitsResult.h>
#include <aws/opensearch/model/DescribeOutboundConnectionsRequest.h>
#include <aws/opensearch/model/DescribeOutboundConnectionsResult.h>
#include <aws/opensearch/model/DescribePackagesFilter.h>
#include <aws/opensearch/model/DescribePackagesFilterName.h>
#include <aws/opensearch/model/DescribePackagesRequest.h>
#include <aws/opensearch/model/DescribePackagesResult.h>
#include <aws/opensearch/model/DescribeReservedInstanceOfferingsRequest.h>
#include <aws/opensearch/model/DescribeReservedInstanceOfferingsResult.h>
#include <aws/opensearch/model/DescribeReservedInstancesRequest.h>
#include <aws/opensearch/model/DescribeReservedInstancesResult.h>
#include <aws/opensearch/model/DescribeVpcEndpointsRequest.h>
#include <aws/opensearch/model/DescribeVpcEndpointsResult.h>
#include <aws/opensearch/model/DirectQueryDataSource.h>
#include <aws/opensearch/model/DirectQueryDataSourceType.h>
#include <aws/opensearch/model/DissociatePackageRequest.h>
#include <aws/opensearch/model/DissociatePackageResult.h>
#include <aws/opensearch/model/DissociatePackagesRequest.h>
#include <aws/opensearch/model/DissociatePackagesResult.h>
#include <aws/opensearch/model/DomainConfig.h>
#include <aws/opensearch/model/DomainEndpointOptions.h>
#include <aws/opensearch/model/DomainEndpointOptionsStatus.h>
#include <aws/opensearch/model/DomainHealth.h>
#include <aws/opensearch/model/DomainInfo.h>
#include <aws/opensearch/model/DomainInformationContainer.h>
#include <aws/opensearch/model/DomainMaintenanceDetails.h>
#include <aws/opensearch/model/DomainNodesStatus.h>
#include <aws/opensearch/model/DomainPackageDetails.h>
#include <aws/opensearch/model/DomainPackageStatus.h>
#include <aws/opensearch/model/DomainProcessingStatusType.h>
#include <aws/opensearch/model/DomainState.h>
#include <aws/opensearch/model/DomainStatus.h>
#include <aws/opensearch/model/DryRunMode.h>
#include <aws/opensearch/model/DryRunProgressStatus.h>
#include <aws/opensearch/model/DryRunResults.h>
#include <aws/opensearch/model/Duration.h>
#include <aws/opensearch/model/EBSOptions.h>
#include <aws/opensearch/model/EBSOptionsStatus.h>
#include <aws/opensearch/model/EncryptionAtRestOptions.h>
#include <aws/opensearch/model/EncryptionAtRestOptionsStatus.h>
#include <aws/opensearch/model/EngineType.h>
#include <aws/opensearch/model/EnvironmentInfo.h>
#include <aws/opensearch/model/ErrorDetails.h>
#include <aws/opensearch/model/Filter.h>
#include <aws/opensearch/model/GetApplicationRequest.h>
#include <aws/opensearch/model/GetApplicationResult.h>
#include <aws/opensearch/model/GetCompatibleVersionsRequest.h>
#include <aws/opensearch/model/GetCompatibleVersionsResult.h>
#include <aws/opensearch/model/GetDataSourceRequest.h>
#include <aws/opensearch/model/GetDataSourceResult.h>
#include <aws/opensearch/model/GetDirectQueryDataSourceRequest.h>
#include <aws/opensearch/model/GetDirectQueryDataSourceResult.h>
#include <aws/opensearch/model/GetDomainMaintenanceStatusRequest.h>
#include <aws/opensearch/model/GetDomainMaintenanceStatusResult.h>
#include <aws/opensearch/model/GetPackageVersionHistoryRequest.h>
#include <aws/opensearch/model/GetPackageVersionHistoryResult.h>
#include <aws/opensearch/model/GetUpgradeHistoryRequest.h>
#include <aws/opensearch/model/GetUpgradeHistoryResult.h>
#include <aws/opensearch/model/GetUpgradeStatusRequest.h>
#include <aws/opensearch/model/GetUpgradeStatusResult.h>
#include <aws/opensearch/model/IAMFederationOptionsInput.h>
#include <aws/opensearch/model/IAMFederationOptionsOutput.h>
#include <aws/opensearch/model/IPAddressType.h>
#include <aws/opensearch/model/IPAddressTypeStatus.h>
#include <aws/opensearch/model/IamIdentityCenterOptions.h>
#include <aws/opensearch/model/IamIdentityCenterOptionsInput.h>
#include <aws/opensearch/model/IdentityCenterOptions.h>
#include <aws/opensearch/model/IdentityCenterOptionsInput.h>
#include <aws/opensearch/model/IdentityCenterOptionsStatus.h>
#include <aws/opensearch/model/InboundConnection.h>
#include <aws/opensearch/model/InboundConnectionStatus.h>
#include <aws/opensearch/model/InboundConnectionStatusCode.h>
#include <aws/opensearch/model/InitiatedBy.h>
#include <aws/opensearch/model/InstanceCountLimits.h>
#include <aws/opensearch/model/InstanceLimits.h>
#include <aws/opensearch/model/InstanceTypeDetails.h>
#include <aws/opensearch/model/JWTOptionsInput.h>
#include <aws/opensearch/model/JWTOptionsOutput.h>
#include <aws/opensearch/model/KeyStoreAccessOption.h>
#include <aws/opensearch/model/Limits.h>
#include <aws/opensearch/model/ListApplicationsRequest.h>
#include <aws/opensearch/model/ListApplicationsResult.h>
#include <aws/opensearch/model/ListDataSourcesRequest.h>
#include <aws/opensearch/model/ListDataSourcesResult.h>
#include <aws/opensearch/model/ListDirectQueryDataSourcesRequest.h>
#include <aws/opensearch/model/ListDirectQueryDataSourcesResult.h>
#include <aws/opensearch/model/ListDomainMaintenancesRequest.h>
#include <aws/opensearch/model/ListDomainMaintenancesResult.h>
#include <aws/opensearch/model/ListDomainNamesRequest.h>
#include <aws/opensearch/model/ListDomainNamesResult.h>
#include <aws/opensearch/model/ListDomainsForPackageRequest.h>
#include <aws/opensearch/model/ListDomainsForPackageResult.h>
#include <aws/opensearch/model/ListInstanceTypeDetailsRequest.h>
#include <aws/opensearch/model/ListInstanceTypeDetailsResult.h>
#include <aws/opensearch/model/ListPackagesForDomainRequest.h>
#include <aws/opensearch/model/ListPackagesForDomainResult.h>
#include <aws/opensearch/model/ListScheduledActionsRequest.h>
#include <aws/opensearch/model/ListScheduledActionsResult.h>
#include <aws/opensearch/model/ListTagsRequest.h>
#include <aws/opensearch/model/ListTagsResult.h>
#include <aws/opensearch/model/ListVersionsRequest.h>
#include <aws/opensearch/model/ListVersionsResult.h>
#include <aws/opensearch/model/ListVpcEndpointAccessRequest.h>
#include <aws/opensearch/model/ListVpcEndpointAccessResult.h>
#include <aws/opensearch/model/ListVpcEndpointsForDomainRequest.h>
#include <aws/opensearch/model/ListVpcEndpointsForDomainResult.h>
#include <aws/opensearch/model/ListVpcEndpointsRequest.h>
#include <aws/opensearch/model/ListVpcEndpointsResult.h>
#include <aws/opensearch/model/LogPublishingOption.h>
#include <aws/opensearch/model/LogPublishingOptionsStatus.h>
#include <aws/opensearch/model/LogType.h>
#include <aws/opensearch/model/MaintenanceStatus.h>
#include <aws/opensearch/model/MaintenanceType.h>
#include <aws/opensearch/model/MasterNodeStatus.h>
#include <aws/opensearch/model/MasterUserOptions.h>
#include <aws/opensearch/model/ModifyingProperties.h>
#include <aws/opensearch/model/NaturalLanguageQueryGenerationCurrentState.h>
#include <aws/opensearch/model/NaturalLanguageQueryGenerationDesiredState.h>
#include <aws/opensearch/model/NaturalLanguageQueryGenerationOptionsInput.h>
#include <aws/opensearch/model/NaturalLanguageQueryGenerationOptionsOutput.h>
#include <aws/opensearch/model/NodeConfig.h>
#include <aws/opensearch/model/NodeOption.h>
#include <aws/opensearch/model/NodeOptionsNodeType.h>
#include <aws/opensearch/model/NodeStatus.h>
#include <aws/opensearch/model/NodeToNodeEncryptionOptions.h>
#include <aws/opensearch/model/NodeToNodeEncryptionOptionsStatus.h>
#include <aws/opensearch/model/NodeType.h>
#include <aws/opensearch/model/OffPeakWindow.h>
#include <aws/opensearch/model/OffPeakWindowOptions.h>
#include <aws/opensearch/model/OffPeakWindowOptionsStatus.h>
#include <aws/opensearch/model/OpenSearchPartitionInstanceType.h>
#include <aws/opensearch/model/OpenSearchWarmPartitionInstanceType.h>
#include <aws/opensearch/model/OptionState.h>
#include <aws/opensearch/model/OptionStatus.h>
#include <aws/opensearch/model/OutboundConnection.h>
#include <aws/opensearch/model/OutboundConnectionStatus.h>
#include <aws/opensearch/model/OutboundConnectionStatusCode.h>
#include <aws/opensearch/model/OverallChangeStatus.h>
#include <aws/opensearch/model/PackageAssociationConfiguration.h>
#include <aws/opensearch/model/PackageConfiguration.h>
#include <aws/opensearch/model/PackageDetails.h>
#include <aws/opensearch/model/PackageDetailsForAssociation.h>
#include <aws/opensearch/model/PackageEncryptionOptions.h>
#include <aws/opensearch/model/PackageScopeOperationEnum.h>
#include <aws/opensearch/model/PackageSource.h>
#include <aws/opensearch/model/PackageStatus.h>
#include <aws/opensearch/model/PackageType.h>
#include <aws/opensearch/model/PackageVendingOptions.h>
#include <aws/opensearch/model/PackageVersionHistory.h>
#include <aws/opensearch/model/PluginProperties.h>
#include <aws/opensearch/model/PrincipalType.h>
#include <aws/opensearch/model/PropertyValueType.h>
#include <aws/opensearch/model/PurchaseReservedInstanceOfferingRequest.h>
#include <aws/opensearch/model/PurchaseReservedInstanceOfferingResult.h>
#include <aws/opensearch/model/RecurringCharge.h>
#include <aws/opensearch/model/RejectInboundConnectionRequest.h>
#include <aws/opensearch/model/RejectInboundConnectionResult.h>
#include <aws/opensearch/model/RemoveTagsRequest.h>
#include <aws/opensearch/model/RequirementLevel.h>
#include <aws/opensearch/model/ReservedInstance.h>
#include <aws/opensearch/model/ReservedInstanceOffering.h>
#include <aws/opensearch/model/ReservedInstancePaymentOption.h>
#include <aws/opensearch/model/RevokeVpcEndpointAccessRequest.h>
#include <aws/opensearch/model/RevokeVpcEndpointAccessResult.h>
#include <aws/opensearch/model/RolesKeyIdCOption.h>
#include <aws/opensearch/model/RollbackOnDisable.h>
#include <aws/opensearch/model/S3GlueDataCatalog.h>
#include <aws/opensearch/model/S3VectorsEngine.h>
#include <aws/opensearch/model/SAMLIdp.h>
#include <aws/opensearch/model/SAMLOptionsInput.h>
#include <aws/opensearch/model/SAMLOptionsOutput.h>
#include <aws/opensearch/model/ScheduleAt.h>
#include <aws/opensearch/model/ScheduledAction.h>
#include <aws/opensearch/model/ScheduledAutoTuneActionType.h>
#include <aws/opensearch/model/ScheduledAutoTuneDetails.h>
#include <aws/opensearch/model/ScheduledAutoTuneSeverityType.h>
#include <aws/opensearch/model/ScheduledBy.h>
#include <aws/opensearch/model/SecurityLakeDirectQueryDataSource.h>
#include <aws/opensearch/model/ServiceSoftwareOptions.h>
#include <aws/opensearch/model/SkipUnavailableStatus.h>
#include <aws/opensearch/model/SlotNotAvailableException.h>
#include <aws/opensearch/model/SnapshotOptions.h>
#include <aws/opensearch/model/SnapshotOptionsStatus.h>
#include <aws/opensearch/model/SoftwareUpdateOptions.h>
#include <aws/opensearch/model/SoftwareUpdateOptionsStatus.h>
#include <aws/opensearch/model/StartDomainMaintenanceRequest.h>
#include <aws/opensearch/model/StartDomainMaintenanceResult.h>
#include <aws/opensearch/model/StartServiceSoftwareUpdateRequest.h>
#include <aws/opensearch/model/StartServiceSoftwareUpdateResult.h>
#include <aws/opensearch/model/StorageType.h>
#include <aws/opensearch/model/StorageTypeLimit.h>
#include <aws/opensearch/model/SubjectKeyIdCOption.h>
#include <aws/opensearch/model/TLSSecurityPolicy.h>
#include <aws/opensearch/model/Tag.h>
#include <aws/opensearch/model/TimeUnit.h>
#include <aws/opensearch/model/UpdateApplicationRequest.h>
#include <aws/opensearch/model/UpdateApplicationResult.h>
#include <aws/opensearch/model/UpdateDataSourceRequest.h>
#include <aws/opensearch/model/UpdateDataSourceResult.h>
#include <aws/opensearch/model/UpdateDirectQueryDataSourceRequest.h>
#include <aws/opensearch/model/UpdateDirectQueryDataSourceResult.h>
#include <aws/opensearch/model/UpdateDomainConfigRequest.h>
#include <aws/opensearch/model/UpdateDomainConfigResult.h>
#include <aws/opensearch/model/UpdatePackageRequest.h>
#include <aws/opensearch/model/UpdatePackageResult.h>
#include <aws/opensearch/model/UpdatePackageScopeRequest.h>
#include <aws/opensearch/model/UpdatePackageScopeResult.h>
#include <aws/opensearch/model/UpdateScheduledActionRequest.h>
#include <aws/opensearch/model/UpdateScheduledActionResult.h>
#include <aws/opensearch/model/UpdateVpcEndpointRequest.h>
#include <aws/opensearch/model/UpdateVpcEndpointResult.h>
#include <aws/opensearch/model/UpgradeDomainRequest.h>
#include <aws/opensearch/model/UpgradeDomainResult.h>
#include <aws/opensearch/model/UpgradeHistory.h>
#include <aws/opensearch/model/UpgradeStatus.h>
#include <aws/opensearch/model/UpgradeStep.h>
#include <aws/opensearch/model/UpgradeStepItem.h>
#include <aws/opensearch/model/VPCDerivedInfo.h>
#include <aws/opensearch/model/VPCDerivedInfoStatus.h>
#include <aws/opensearch/model/VPCOptions.h>
#include <aws/opensearch/model/ValidationFailure.h>
#include <aws/opensearch/model/VersionStatus.h>
#include <aws/opensearch/model/VolumeType.h>
#include <aws/opensearch/model/VpcEndpoint.h>
#include <aws/opensearch/model/VpcEndpointError.h>
#include <aws/opensearch/model/VpcEndpointErrorCode.h>
#include <aws/opensearch/model/VpcEndpointStatus.h>
#include <aws/opensearch/model/VpcEndpointSummary.h>
#include <aws/opensearch/model/WindowStartTime.h>
#include <aws/opensearch/model/ZoneAwarenessConfig.h>
#include <aws/opensearch/model/ZoneStatus.h>

using OpenSearchServiceIncludeTest = ::testing::Test;

TEST_F(OpenSearchServiceIncludeTest, TestClientCompiles)
{
  Aws::Client::ClientConfigurationInitValues cfgInit;
  cfgInit.shouldDisableIMDS = true;
  Aws::Client::ClientConfiguration config(cfgInit);
  AWS_UNREFERENCED_PARAM(config);
  // auto pClient = Aws::MakeUnique<Aws::OpenSearchService::OpenSearchServiceClient>("OpenSearchServiceIncludeTest", config);
  // ASSERT_TRUE(pClient.get());
}
