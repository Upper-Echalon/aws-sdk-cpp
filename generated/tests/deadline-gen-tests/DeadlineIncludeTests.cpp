/**
 * Copyright Amazon.com, Inc. or its affiliates. All Rights Reserved.
 * SPDX-License-Identifier: Apache-2.0.
 */

#include <gtest/gtest.h>
#include <aws/testing/AwsTestHelpers.h>

#include <aws/deadline/DeadlineClient.h>
#include <aws/deadline/DeadlineEndpointProvider.h>
#include <aws/deadline/DeadlineEndpointRules.h>
#include <aws/deadline/DeadlineErrorMarshaller.h>
#include <aws/deadline/DeadlineErrors.h>
#include <aws/deadline/DeadlineRequest.h>
#include <aws/deadline/DeadlineServiceClientModel.h>
#include <aws/deadline/Deadline_EXPORTS.h>
#include <aws/deadline/model/AcceleratorCapabilities.h>
#include <aws/deadline/model/AcceleratorCountRange.h>
#include <aws/deadline/model/AcceleratorName.h>
#include <aws/deadline/model/AcceleratorSelection.h>
#include <aws/deadline/model/AcceleratorTotalMemoryMiBRange.h>
#include <aws/deadline/model/AcceleratorType.h>
#include <aws/deadline/model/AccessDeniedException.h>
#include <aws/deadline/model/AcquiredLimit.h>
#include <aws/deadline/model/AssignedEnvironmentEnterSessionActionDefinition.h>
#include <aws/deadline/model/AssignedEnvironmentExitSessionActionDefinition.h>
#include <aws/deadline/model/AssignedSession.h>
#include <aws/deadline/model/AssignedSessionAction.h>
#include <aws/deadline/model/AssignedSessionActionDefinition.h>
#include <aws/deadline/model/AssignedSyncInputJobAttachmentsSessionActionDefinition.h>
#include <aws/deadline/model/AssignedTaskRunSessionActionDefinition.h>
#include <aws/deadline/model/AssociateMemberToFarmRequest.h>
#include <aws/deadline/model/AssociateMemberToFarmResult.h>
#include <aws/deadline/model/AssociateMemberToFleetRequest.h>
#include <aws/deadline/model/AssociateMemberToFleetResult.h>
#include <aws/deadline/model/AssociateMemberToJobRequest.h>
#include <aws/deadline/model/AssociateMemberToJobResult.h>
#include <aws/deadline/model/AssociateMemberToQueueRequest.h>
#include <aws/deadline/model/AssociateMemberToQueueResult.h>
#include <aws/deadline/model/AssumeFleetRoleForReadRequest.h>
#include <aws/deadline/model/AssumeFleetRoleForReadResult.h>
#include <aws/deadline/model/AssumeFleetRoleForWorkerRequest.h>
#include <aws/deadline/model/AssumeFleetRoleForWorkerResult.h>
#include <aws/deadline/model/AssumeQueueRoleForReadRequest.h>
#include <aws/deadline/model/AssumeQueueRoleForReadResult.h>
#include <aws/deadline/model/AssumeQueueRoleForUserRequest.h>
#include <aws/deadline/model/AssumeQueueRoleForUserResult.h>
#include <aws/deadline/model/AssumeQueueRoleForWorkerRequest.h>
#include <aws/deadline/model/AssumeQueueRoleForWorkerResult.h>
#include <aws/deadline/model/Attachments.h>
#include <aws/deadline/model/AutoScalingMode.h>
#include <aws/deadline/model/AutoScalingStatus.h>
#include <aws/deadline/model/AwsCredentials.h>
#include <aws/deadline/model/BatchGetJobEntityRequest.h>
#include <aws/deadline/model/BatchGetJobEntityResult.h>
#include <aws/deadline/model/BudgetActionToAdd.h>
#include <aws/deadline/model/BudgetActionToRemove.h>
#include <aws/deadline/model/BudgetActionType.h>
#include <aws/deadline/model/BudgetSchedule.h>
#include <aws/deadline/model/BudgetStatus.h>
#include <aws/deadline/model/BudgetSummary.h>
#include <aws/deadline/model/ComparisonOperator.h>
#include <aws/deadline/model/CompletedStatus.h>
#include <aws/deadline/model/ConflictException.h>
#include <aws/deadline/model/ConflictExceptionReason.h>
#include <aws/deadline/model/ConsumedUsages.h>
#include <aws/deadline/model/CopyJobTemplateRequest.h>
#include <aws/deadline/model/CopyJobTemplateResult.h>
#include <aws/deadline/model/CpuArchitectureType.h>
#include <aws/deadline/model/CreateBudgetRequest.h>
#include <aws/deadline/model/CreateBudgetResult.h>
#include <aws/deadline/model/CreateFarmRequest.h>
#include <aws/deadline/model/CreateFarmResult.h>
#include <aws/deadline/model/CreateFleetRequest.h>
#include <aws/deadline/model/CreateFleetResult.h>
#include <aws/deadline/model/CreateJobRequest.h>
#include <aws/deadline/model/CreateJobResult.h>
#include <aws/deadline/model/CreateJobTargetTaskRunStatus.h>
#include <aws/deadline/model/CreateLicenseEndpointRequest.h>
#include <aws/deadline/model/CreateLicenseEndpointResult.h>
#include <aws/deadline/model/CreateLimitRequest.h>
#include <aws/deadline/model/CreateLimitResult.h>
#include <aws/deadline/model/CreateMonitorRequest.h>
#include <aws/deadline/model/CreateMonitorResult.h>
#include <aws/deadline/model/CreateQueueEnvironmentRequest.h>
#include <aws/deadline/model/CreateQueueEnvironmentResult.h>
#include <aws/deadline/model/CreateQueueFleetAssociationRequest.h>
#include <aws/deadline/model/CreateQueueFleetAssociationResult.h>
#include <aws/deadline/model/CreateQueueLimitAssociationRequest.h>
#include <aws/deadline/model/CreateQueueLimitAssociationResult.h>
#include <aws/deadline/model/CreateQueueRequest.h>
#include <aws/deadline/model/CreateQueueResult.h>
#include <aws/deadline/model/CreateStorageProfileRequest.h>
#include <aws/deadline/model/CreateStorageProfileResult.h>
#include <aws/deadline/model/CreateWorkerRequest.h>
#include <aws/deadline/model/CreateWorkerResult.h>
#include <aws/deadline/model/CustomerManagedFleetConfiguration.h>
#include <aws/deadline/model/CustomerManagedFleetOperatingSystemFamily.h>
#include <aws/deadline/model/CustomerManagedWorkerCapabilities.h>
#include <aws/deadline/model/DateTimeFilterExpression.h>
#include <aws/deadline/model/DefaultQueueBudgetAction.h>
#include <aws/deadline/model/DeleteBudgetRequest.h>
#include <aws/deadline/model/DeleteBudgetResult.h>
#include <aws/deadline/model/DeleteFarmRequest.h>
#include <aws/deadline/model/DeleteFarmResult.h>
#include <aws/deadline/model/DeleteFleetRequest.h>
#include <aws/deadline/model/DeleteFleetResult.h>
#include <aws/deadline/model/DeleteLicenseEndpointRequest.h>
#include <aws/deadline/model/DeleteLicenseEndpointResult.h>
#include <aws/deadline/model/DeleteLimitRequest.h>
#include <aws/deadline/model/DeleteLimitResult.h>
#include <aws/deadline/model/DeleteMeteredProductRequest.h>
#include <aws/deadline/model/DeleteMeteredProductResult.h>
#include <aws/deadline/model/DeleteMonitorRequest.h>
#include <aws/deadline/model/DeleteMonitorResult.h>
#include <aws/deadline/model/DeleteQueueEnvironmentRequest.h>
#include <aws/deadline/model/DeleteQueueEnvironmentResult.h>
#include <aws/deadline/model/DeleteQueueFleetAssociationRequest.h>
#include <aws/deadline/model/DeleteQueueFleetAssociationResult.h>
#include <aws/deadline/model/DeleteQueueLimitAssociationRequest.h>
#include <aws/deadline/model/DeleteQueueLimitAssociationResult.h>
#include <aws/deadline/model/DeleteQueueRequest.h>
#include <aws/deadline/model/DeleteQueueResult.h>
#include <aws/deadline/model/DeleteStorageProfileRequest.h>
#include <aws/deadline/model/DeleteStorageProfileResult.h>
#include <aws/deadline/model/DeleteWorkerRequest.h>
#include <aws/deadline/model/DeleteWorkerResult.h>
#include <aws/deadline/model/DependencyConsumerResolutionStatus.h>
#include <aws/deadline/model/DependencyCounts.h>
#include <aws/deadline/model/DesiredWorkerStatus.h>
#include <aws/deadline/model/DisassociateMemberFromFarmRequest.h>
#include <aws/deadline/model/DisassociateMemberFromFarmResult.h>
#include <aws/deadline/model/DisassociateMemberFromFleetRequest.h>
#include <aws/deadline/model/DisassociateMemberFromFleetResult.h>
#include <aws/deadline/model/DisassociateMemberFromJobRequest.h>
#include <aws/deadline/model/DisassociateMemberFromJobResult.h>
#include <aws/deadline/model/DisassociateMemberFromQueueRequest.h>
#include <aws/deadline/model/DisassociateMemberFromQueueResult.h>
#include <aws/deadline/model/Ec2EbsVolume.h>
#include <aws/deadline/model/Ec2MarketType.h>
#include <aws/deadline/model/EnvironmentDetailsEntity.h>
#include <aws/deadline/model/EnvironmentDetailsError.h>
#include <aws/deadline/model/EnvironmentDetailsIdentifiers.h>
#include <aws/deadline/model/EnvironmentEnterSessionActionDefinition.h>
#include <aws/deadline/model/EnvironmentEnterSessionActionDefinitionSummary.h>
#include <aws/deadline/model/EnvironmentExitSessionActionDefinition.h>
#include <aws/deadline/model/EnvironmentExitSessionActionDefinitionSummary.h>
#include <aws/deadline/model/EnvironmentTemplateType.h>
#include <aws/deadline/model/FarmMember.h>
#include <aws/deadline/model/FarmSummary.h>
#include <aws/deadline/model/FieldSortExpression.h>
#include <aws/deadline/model/FileSystemLocation.h>
#include <aws/deadline/model/FileSystemLocationType.h>
#include <aws/deadline/model/FixedBudgetSchedule.h>
#include <aws/deadline/model/FleetAmountCapability.h>
#include <aws/deadline/model/FleetAttributeCapability.h>
#include <aws/deadline/model/FleetCapabilities.h>
#include <aws/deadline/model/FleetConfiguration.h>
#include <aws/deadline/model/FleetMember.h>
#include <aws/deadline/model/FleetStatus.h>
#include <aws/deadline/model/FleetSummary.h>
#include <aws/deadline/model/GetBudgetRequest.h>
#include <aws/deadline/model/GetBudgetResult.h>
#include <aws/deadline/model/GetFarmRequest.h>
#include <aws/deadline/model/GetFarmResult.h>
#include <aws/deadline/model/GetFleetRequest.h>
#include <aws/deadline/model/GetFleetResult.h>
#include <aws/deadline/model/GetJobEntityError.h>
#include <aws/deadline/model/GetJobRequest.h>
#include <aws/deadline/model/GetJobResult.h>
#include <aws/deadline/model/GetLicenseEndpointRequest.h>
#include <aws/deadline/model/GetLicenseEndpointResult.h>
#include <aws/deadline/model/GetLimitRequest.h>
#include <aws/deadline/model/GetLimitResult.h>
#include <aws/deadline/model/GetMonitorRequest.h>
#include <aws/deadline/model/GetMonitorResult.h>
#include <aws/deadline/model/GetQueueEnvironmentRequest.h>
#include <aws/deadline/model/GetQueueEnvironmentResult.h>
#include <aws/deadline/model/GetQueueFleetAssociationRequest.h>
#include <aws/deadline/model/GetQueueFleetAssociationResult.h>
#include <aws/deadline/model/GetQueueLimitAssociationRequest.h>
#include <aws/deadline/model/GetQueueLimitAssociationResult.h>
#include <aws/deadline/model/GetQueueRequest.h>
#include <aws/deadline/model/GetQueueResult.h>
#include <aws/deadline/model/GetSessionActionRequest.h>
#include <aws/deadline/model/GetSessionActionResult.h>
#include <aws/deadline/model/GetSessionRequest.h>
#include <aws/deadline/model/GetSessionResult.h>
#include <aws/deadline/model/GetSessionsStatisticsAggregationRequest.h>
#include <aws/deadline/model/GetSessionsStatisticsAggregationResult.h>
#include <aws/deadline/model/GetStepRequest.h>
#include <aws/deadline/model/GetStepResult.h>
#include <aws/deadline/model/GetStorageProfileForQueueRequest.h>
#include <aws/deadline/model/GetStorageProfileForQueueResult.h>
#include <aws/deadline/model/GetStorageProfileRequest.h>
#include <aws/deadline/model/GetStorageProfileResult.h>
#include <aws/deadline/model/GetTaskRequest.h>
#include <aws/deadline/model/GetTaskResult.h>
#include <aws/deadline/model/GetWorkerRequest.h>
#include <aws/deadline/model/GetWorkerResult.h>
#include <aws/deadline/model/HostConfiguration.h>
#include <aws/deadline/model/HostPropertiesRequest.h>
#include <aws/deadline/model/HostPropertiesResponse.h>
#include <aws/deadline/model/InternalServerErrorException.h>
#include <aws/deadline/model/IpAddresses.h>
#include <aws/deadline/model/JobAttachmentDetailsEntity.h>
#include <aws/deadline/model/JobAttachmentDetailsError.h>
#include <aws/deadline/model/JobAttachmentDetailsIdentifiers.h>
#include <aws/deadline/model/JobAttachmentSettings.h>
#include <aws/deadline/model/JobAttachmentsFileSystem.h>
#include <aws/deadline/model/JobDetailsEntity.h>
#include <aws/deadline/model/JobDetailsError.h>
#include <aws/deadline/model/JobDetailsIdentifiers.h>
#include <aws/deadline/model/JobEntity.h>
#include <aws/deadline/model/JobEntityErrorCode.h>
#include <aws/deadline/model/JobEntityIdentifiersUnion.h>
#include <aws/deadline/model/JobLifecycleStatus.h>
#include <aws/deadline/model/JobMember.h>
#include <aws/deadline/model/JobParameter.h>
#include <aws/deadline/model/JobRunAsUser.h>
#include <aws/deadline/model/JobSearchSummary.h>
#include <aws/deadline/model/JobSummary.h>
#include <aws/deadline/model/JobTargetTaskRunStatus.h>
#include <aws/deadline/model/JobTemplateType.h>
#include <aws/deadline/model/LicenseEndpointStatus.h>
#include <aws/deadline/model/LicenseEndpointSummary.h>
#include <aws/deadline/model/LimitSummary.h>
#include <aws/deadline/model/ListAvailableMeteredProductsRequest.h>
#include <aws/deadline/model/ListAvailableMeteredProductsResult.h>
#include <aws/deadline/model/ListBudgetsRequest.h>
#include <aws/deadline/model/ListBudgetsResult.h>
#include <aws/deadline/model/ListFarmMembersRequest.h>
#include <aws/deadline/model/ListFarmMembersResult.h>
#include <aws/deadline/model/ListFarmsRequest.h>
#include <aws/deadline/model/ListFarmsResult.h>
#include <aws/deadline/model/ListFleetMembersRequest.h>
#include <aws/deadline/model/ListFleetMembersResult.h>
#include <aws/deadline/model/ListFleetsRequest.h>
#include <aws/deadline/model/ListFleetsResult.h>
#include <aws/deadline/model/ListJobMembersRequest.h>
#include <aws/deadline/model/ListJobMembersResult.h>
#include <aws/deadline/model/ListJobParameterDefinitionsRequest.h>
#include <aws/deadline/model/ListJobParameterDefinitionsResult.h>
#include <aws/deadline/model/ListJobsRequest.h>
#include <aws/deadline/model/ListJobsResult.h>
#include <aws/deadline/model/ListLicenseEndpointsRequest.h>
#include <aws/deadline/model/ListLicenseEndpointsResult.h>
#include <aws/deadline/model/ListLimitsRequest.h>
#include <aws/deadline/model/ListLimitsResult.h>
#include <aws/deadline/model/ListMeteredProductsRequest.h>
#include <aws/deadline/model/ListMeteredProductsResult.h>
#include <aws/deadline/model/ListMonitorsRequest.h>
#include <aws/deadline/model/ListMonitorsResult.h>
#include <aws/deadline/model/ListQueueEnvironmentsRequest.h>
#include <aws/deadline/model/ListQueueEnvironmentsResult.h>
#include <aws/deadline/model/ListQueueFleetAssociationsRequest.h>
#include <aws/deadline/model/ListQueueFleetAssociationsResult.h>
#include <aws/deadline/model/ListQueueLimitAssociationsRequest.h>
#include <aws/deadline/model/ListQueueLimitAssociationsResult.h>
#include <aws/deadline/model/ListQueueMembersRequest.h>
#include <aws/deadline/model/ListQueueMembersResult.h>
#include <aws/deadline/model/ListQueuesRequest.h>
#include <aws/deadline/model/ListQueuesResult.h>
#include <aws/deadline/model/ListSessionActionsRequest.h>
#include <aws/deadline/model/ListSessionActionsResult.h>
#include <aws/deadline/model/ListSessionsForWorkerRequest.h>
#include <aws/deadline/model/ListSessionsForWorkerResult.h>
#include <aws/deadline/model/ListSessionsRequest.h>
#include <aws/deadline/model/ListSessionsResult.h>
#include <aws/deadline/model/ListStepConsumersRequest.h>
#include <aws/deadline/model/ListStepConsumersResult.h>
#include <aws/deadline/model/ListStepDependenciesRequest.h>
#include <aws/deadline/model/ListStepDependenciesResult.h>
#include <aws/deadline/model/ListStepsRequest.h>
#include <aws/deadline/model/ListStepsResult.h>
#include <aws/deadline/model/ListStorageProfilesForQueueRequest.h>
#include <aws/deadline/model/ListStorageProfilesForQueueResult.h>
#include <aws/deadline/model/ListStorageProfilesRequest.h>
#include <aws/deadline/model/ListStorageProfilesResult.h>
#include <aws/deadline/model/ListTagsForResourceRequest.h>
#include <aws/deadline/model/ListTagsForResourceResult.h>
#include <aws/deadline/model/ListTasksRequest.h>
#include <aws/deadline/model/ListTasksResult.h>
#include <aws/deadline/model/ListWorkersRequest.h>
#include <aws/deadline/model/ListWorkersResult.h>
#include <aws/deadline/model/LogConfiguration.h>
#include <aws/deadline/model/LogicalOperator.h>
#include <aws/deadline/model/ManifestProperties.h>
#include <aws/deadline/model/MembershipLevel.h>
#include <aws/deadline/model/MemoryMiBRange.h>
#include <aws/deadline/model/MeteredProductSummary.h>
#include <aws/deadline/model/MonitorSummary.h>
#include <aws/deadline/model/ParameterFilterExpression.h>
#include <aws/deadline/model/ParameterSortExpression.h>
#include <aws/deadline/model/ParameterSpace.h>
#include <aws/deadline/model/PathFormat.h>
#include <aws/deadline/model/PathMappingRule.h>
#include <aws/deadline/model/Period.h>
#include <aws/deadline/model/PosixUser.h>
#include <aws/deadline/model/PrincipalType.h>
#include <aws/deadline/model/PutMeteredProductRequest.h>
#include <aws/deadline/model/PutMeteredProductResult.h>
#include <aws/deadline/model/QueueBlockedReason.h>
#include <aws/deadline/model/QueueEnvironmentSummary.h>
#include <aws/deadline/model/QueueFleetAssociationStatus.h>
#include <aws/deadline/model/QueueFleetAssociationSummary.h>
#include <aws/deadline/model/QueueLimitAssociationStatus.h>
#include <aws/deadline/model/QueueLimitAssociationSummary.h>
#include <aws/deadline/model/QueueMember.h>
#include <aws/deadline/model/QueueStatus.h>
#include <aws/deadline/model/QueueSummary.h>
#include <aws/deadline/model/ResourceNotFoundException.h>
#include <aws/deadline/model/ResponseBudgetAction.h>
#include <aws/deadline/model/RunAs.h>
#include <aws/deadline/model/S3Location.h>
#include <aws/deadline/model/SearchFilterExpression.h>
#include <aws/deadline/model/SearchGroupedFilterExpressions.h>
#include <aws/deadline/model/SearchJobsRequest.h>
#include <aws/deadline/model/SearchJobsResult.h>
#include <aws/deadline/model/SearchSortExpression.h>
#include <aws/deadline/model/SearchStepsRequest.h>
#include <aws/deadline/model/SearchStepsResult.h>
#include <aws/deadline/model/SearchTasksRequest.h>
#include <aws/deadline/model/SearchTasksResult.h>
#include <aws/deadline/model/SearchTermFilterExpression.h>
#include <aws/deadline/model/SearchTermMatchingType.h>
#include <aws/deadline/model/SearchWorkersRequest.h>
#include <aws/deadline/model/SearchWorkersResult.h>
#include <aws/deadline/model/ServiceManagedEc2FleetConfiguration.h>
#include <aws/deadline/model/ServiceManagedEc2InstanceCapabilities.h>
#include <aws/deadline/model/ServiceManagedEc2InstanceMarketOptions.h>
#include <aws/deadline/model/ServiceManagedFleetOperatingSystemFamily.h>
#include <aws/deadline/model/ServiceQuotaExceededException.h>
#include <aws/deadline/model/ServiceQuotaExceededExceptionReason.h>
#include <aws/deadline/model/SessionActionDefinition.h>
#include <aws/deadline/model/SessionActionDefinitionSummary.h>
#include <aws/deadline/model/SessionActionStatus.h>
#include <aws/deadline/model/SessionActionSummary.h>
#include <aws/deadline/model/SessionLifecycleStatus.h>
#include <aws/deadline/model/SessionLifecycleTargetStatus.h>
#include <aws/deadline/model/SessionSummary.h>
#include <aws/deadline/model/SessionsStatisticsAggregationStatus.h>
#include <aws/deadline/model/SessionsStatisticsResources.h>
#include <aws/deadline/model/SortOrder.h>
#include <aws/deadline/model/StartSessionsStatisticsAggregationRequest.h>
#include <aws/deadline/model/StartSessionsStatisticsAggregationResult.h>
#include <aws/deadline/model/Statistics.h>
#include <aws/deadline/model/Stats.h>
#include <aws/deadline/model/StepAmountCapability.h>
#include <aws/deadline/model/StepAttributeCapability.h>
#include <aws/deadline/model/StepConsumer.h>
#include <aws/deadline/model/StepDependency.h>
#include <aws/deadline/model/StepDetailsEntity.h>
#include <aws/deadline/model/StepDetailsError.h>
#include <aws/deadline/model/StepDetailsIdentifiers.h>
#include <aws/deadline/model/StepLifecycleStatus.h>
#include <aws/deadline/model/StepParameter.h>
#include <aws/deadline/model/StepParameterType.h>
#include <aws/deadline/model/StepRequiredCapabilities.h>
#include <aws/deadline/model/StepSearchSummary.h>
#include <aws/deadline/model/StepSummary.h>
#include <aws/deadline/model/StepTargetTaskRunStatus.h>
#include <aws/deadline/model/StorageProfileOperatingSystemFamily.h>
#include <aws/deadline/model/StorageProfileSummary.h>
#include <aws/deadline/model/StringFilterExpression.h>
#include <aws/deadline/model/SyncInputJobAttachmentsSessionActionDefinition.h>
#include <aws/deadline/model/SyncInputJobAttachmentsSessionActionDefinitionSummary.h>
#include <aws/deadline/model/TagPropagationMode.h>
#include <aws/deadline/model/TagResourceRequest.h>
#include <aws/deadline/model/TagResourceResult.h>
#include <aws/deadline/model/TaskParameterValue.h>
#include <aws/deadline/model/TaskRunManifestPropertiesRequest.h>
#include <aws/deadline/model/TaskRunManifestPropertiesResponse.h>
#include <aws/deadline/model/TaskRunSessionActionDefinition.h>
#include <aws/deadline/model/TaskRunSessionActionDefinitionSummary.h>
#include <aws/deadline/model/TaskRunStatus.h>
#include <aws/deadline/model/TaskSearchSummary.h>
#include <aws/deadline/model/TaskSummary.h>
#include <aws/deadline/model/TaskTargetRunStatus.h>
#include <aws/deadline/model/ThrottlingException.h>
#include <aws/deadline/model/UntagResourceRequest.h>
#include <aws/deadline/model/UntagResourceResult.h>
#include <aws/deadline/model/UpdateBudgetRequest.h>
#include <aws/deadline/model/UpdateBudgetResult.h>
#include <aws/deadline/model/UpdateFarmRequest.h>
#include <aws/deadline/model/UpdateFarmResult.h>
#include <aws/deadline/model/UpdateFleetRequest.h>
#include <aws/deadline/model/UpdateFleetResult.h>
#include <aws/deadline/model/UpdateJobLifecycleStatus.h>
#include <aws/deadline/model/UpdateJobRequest.h>
#include <aws/deadline/model/UpdateJobResult.h>
#include <aws/deadline/model/UpdateLimitRequest.h>
#include <aws/deadline/model/UpdateLimitResult.h>
#include <aws/deadline/model/UpdateMonitorRequest.h>
#include <aws/deadline/model/UpdateMonitorResult.h>
#include <aws/deadline/model/UpdateQueueEnvironmentRequest.h>
#include <aws/deadline/model/UpdateQueueEnvironmentResult.h>
#include <aws/deadline/model/UpdateQueueFleetAssociationRequest.h>
#include <aws/deadline/model/UpdateQueueFleetAssociationResult.h>
#include <aws/deadline/model/UpdateQueueFleetAssociationStatus.h>
#include <aws/deadline/model/UpdateQueueLimitAssociationRequest.h>
#include <aws/deadline/model/UpdateQueueLimitAssociationResult.h>
#include <aws/deadline/model/UpdateQueueLimitAssociationStatus.h>
#include <aws/deadline/model/UpdateQueueRequest.h>
#include <aws/deadline/model/UpdateQueueResult.h>
#include <aws/deadline/model/UpdateSessionRequest.h>
#include <aws/deadline/model/UpdateSessionResult.h>
#include <aws/deadline/model/UpdateStepRequest.h>
#include <aws/deadline/model/UpdateStepResult.h>
#include <aws/deadline/model/UpdateStorageProfileRequest.h>
#include <aws/deadline/model/UpdateStorageProfileResult.h>
#include <aws/deadline/model/UpdateTaskRequest.h>
#include <aws/deadline/model/UpdateTaskResult.h>
#include <aws/deadline/model/UpdateWorkerRequest.h>
#include <aws/deadline/model/UpdateWorkerResult.h>
#include <aws/deadline/model/UpdateWorkerScheduleRequest.h>
#include <aws/deadline/model/UpdateWorkerScheduleResult.h>
#include <aws/deadline/model/UpdatedSessionActionInfo.h>
#include <aws/deadline/model/UpdatedWorkerStatus.h>
#include <aws/deadline/model/UsageGroupByField.h>
#include <aws/deadline/model/UsageStatistic.h>
#include <aws/deadline/model/UsageTrackingResource.h>
#include <aws/deadline/model/UsageType.h>
#include <aws/deadline/model/UserJobsFirst.h>
#include <aws/deadline/model/VCpuCountRange.h>
#include <aws/deadline/model/ValidationException.h>
#include <aws/deadline/model/ValidationExceptionField.h>
#include <aws/deadline/model/ValidationExceptionReason.h>
#include <aws/deadline/model/VpcConfiguration.h>
#include <aws/deadline/model/WindowsUser.h>
#include <aws/deadline/model/WorkerAmountCapability.h>
#include <aws/deadline/model/WorkerAttributeCapability.h>
#include <aws/deadline/model/WorkerCapabilities.h>
#include <aws/deadline/model/WorkerSearchSummary.h>
#include <aws/deadline/model/WorkerSessionSummary.h>
#include <aws/deadline/model/WorkerStatus.h>
#include <aws/deadline/model/WorkerSummary.h>

using DeadlineIncludeTest = ::testing::Test;

TEST_F(DeadlineIncludeTest, TestClientCompiles)
{
  Aws::Client::ClientConfigurationInitValues cfgInit;
  cfgInit.shouldDisableIMDS = true;
  Aws::Client::ClientConfiguration config(cfgInit);
  AWS_UNREFERENCED_PARAM(config);
  // auto pClient = Aws::MakeUnique<Aws::deadline::DeadlineClient>("DeadlineIncludeTest", config);
  // ASSERT_TRUE(pClient.get());
}
