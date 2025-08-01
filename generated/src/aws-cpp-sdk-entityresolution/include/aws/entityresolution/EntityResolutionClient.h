﻿/**
 * Copyright Amazon.com, Inc. or its affiliates. All Rights Reserved.
 * SPDX-License-Identifier: Apache-2.0.
 */

#pragma once
#include <aws/entityresolution/EntityResolution_EXPORTS.h>
#include <aws/core/client/ClientConfiguration.h>
#include <aws/core/client/AWSClient.h>
#include <aws/core/client/AWSClientAsyncCRTP.h>
#include <aws/core/utils/json/JsonSerializer.h>
#include <aws/entityresolution/EntityResolutionServiceClientModel.h>

namespace Aws
{
namespace EntityResolution
{
  /**
   * <p>Welcome to the <i>Entity Resolution API Reference</i>.</p> <p>Entity
   * Resolution is an Amazon Web Services service that provides pre-configured entity
   * resolution capabilities that enable developers and analysts at advertising and
   * marketing companies to build an accurate and complete view of their
   * consumers.</p> <p> With Entity Resolution, you can match source records
   * containing consumer identifiers, such as name, email address, and phone number.
   * This is true even when these records have incomplete or conflicting identifiers.
   * For example, Entity Resolution can effectively match a source record from a
   * customer relationship management (CRM) system with a source record from a
   * marketing system containing campaign information.</p> <p>To learn more about
   * Entity Resolution concepts, procedures, and best practices, see the <a
   * href="https://docs.aws.amazon.com/entityresolution/latest/userguide/what-is-service.html">Entity
   * Resolution User Guide</a>.</p>
   */
  class AWS_ENTITYRESOLUTION_API EntityResolutionClient : public Aws::Client::AWSJsonClient, public Aws::Client::ClientWithAsyncTemplateMethods<EntityResolutionClient>
  {
    public:
      typedef Aws::Client::AWSJsonClient BASECLASS;
      static const char* GetServiceName();
      static const char* GetAllocationTag();

      typedef EntityResolutionClientConfiguration ClientConfigurationType;
      typedef EntityResolutionEndpointProvider EndpointProviderType;

       /**
        * Initializes client to use DefaultCredentialProviderChain, with default http client factory, and optional client config. If client config
        * is not specified, it will be initialized to default values.
        */
        EntityResolutionClient(const Aws::EntityResolution::EntityResolutionClientConfiguration& clientConfiguration = Aws::EntityResolution::EntityResolutionClientConfiguration(),
                               std::shared_ptr<EntityResolutionEndpointProviderBase> endpointProvider = nullptr);

       /**
        * Initializes client to use SimpleAWSCredentialsProvider, with default http client factory, and optional client config. If client config
        * is not specified, it will be initialized to default values.
        */
        EntityResolutionClient(const Aws::Auth::AWSCredentials& credentials,
                               std::shared_ptr<EntityResolutionEndpointProviderBase> endpointProvider = nullptr,
                               const Aws::EntityResolution::EntityResolutionClientConfiguration& clientConfiguration = Aws::EntityResolution::EntityResolutionClientConfiguration());

       /**
        * Initializes client to use specified credentials provider with specified client config. If http client factory is not supplied,
        * the default http client factory will be used
        */
        EntityResolutionClient(const std::shared_ptr<Aws::Auth::AWSCredentialsProvider>& credentialsProvider,
                               std::shared_ptr<EntityResolutionEndpointProviderBase> endpointProvider = nullptr,
                               const Aws::EntityResolution::EntityResolutionClientConfiguration& clientConfiguration = Aws::EntityResolution::EntityResolutionClientConfiguration());


        /* Legacy constructors due deprecation */
       /**
        * Initializes client to use DefaultCredentialProviderChain, with default http client factory, and optional client config. If client config
        * is not specified, it will be initialized to default values.
        */
        EntityResolutionClient(const Aws::Client::ClientConfiguration& clientConfiguration);

       /**
        * Initializes client to use SimpleAWSCredentialsProvider, with default http client factory, and optional client config. If client config
        * is not specified, it will be initialized to default values.
        */
        EntityResolutionClient(const Aws::Auth::AWSCredentials& credentials,
                               const Aws::Client::ClientConfiguration& clientConfiguration);

       /**
        * Initializes client to use specified credentials provider with specified client config. If http client factory is not supplied,
        * the default http client factory will be used
        */
        EntityResolutionClient(const std::shared_ptr<Aws::Auth::AWSCredentialsProvider>& credentialsProvider,
                               const Aws::Client::ClientConfiguration& clientConfiguration);

        /* End of legacy constructors due deprecation */
        virtual ~EntityResolutionClient();

        /**
         * <p>Adds a policy statement object. To retrieve a list of existing policy
         * statements, use the <code>GetPolicy</code> API.</p><p><h3>See Also:</h3>   <a
         * href="http://docs.aws.amazon.com/goto/WebAPI/entityresolution-2018-05-10/AddPolicyStatement">AWS
         * API Reference</a></p>
         */
        virtual Model::AddPolicyStatementOutcome AddPolicyStatement(const Model::AddPolicyStatementRequest& request) const;

        /**
         * A Callable wrapper for AddPolicyStatement that returns a future to the operation so that it can be executed in parallel to other requests.
         */
        template<typename AddPolicyStatementRequestT = Model::AddPolicyStatementRequest>
        Model::AddPolicyStatementOutcomeCallable AddPolicyStatementCallable(const AddPolicyStatementRequestT& request) const
        {
            return SubmitCallable(&EntityResolutionClient::AddPolicyStatement, request);
        }

        /**
         * An Async wrapper for AddPolicyStatement that queues the request into a thread executor and triggers associated callback when operation has finished.
         */
        template<typename AddPolicyStatementRequestT = Model::AddPolicyStatementRequest>
        void AddPolicyStatementAsync(const AddPolicyStatementRequestT& request, const AddPolicyStatementResponseReceivedHandler& handler, const std::shared_ptr<const Aws::Client::AsyncCallerContext>& context = nullptr) const
        {
            return SubmitAsync(&EntityResolutionClient::AddPolicyStatement, request, handler, context);
        }

        /**
         * <p>Deletes multiple unique IDs in a matching workflow.</p><p><h3>See Also:</h3> 
         * <a
         * href="http://docs.aws.amazon.com/goto/WebAPI/entityresolution-2018-05-10/BatchDeleteUniqueId">AWS
         * API Reference</a></p>
         */
        virtual Model::BatchDeleteUniqueIdOutcome BatchDeleteUniqueId(const Model::BatchDeleteUniqueIdRequest& request) const;

        /**
         * A Callable wrapper for BatchDeleteUniqueId that returns a future to the operation so that it can be executed in parallel to other requests.
         */
        template<typename BatchDeleteUniqueIdRequestT = Model::BatchDeleteUniqueIdRequest>
        Model::BatchDeleteUniqueIdOutcomeCallable BatchDeleteUniqueIdCallable(const BatchDeleteUniqueIdRequestT& request) const
        {
            return SubmitCallable(&EntityResolutionClient::BatchDeleteUniqueId, request);
        }

        /**
         * An Async wrapper for BatchDeleteUniqueId that queues the request into a thread executor and triggers associated callback when operation has finished.
         */
        template<typename BatchDeleteUniqueIdRequestT = Model::BatchDeleteUniqueIdRequest>
        void BatchDeleteUniqueIdAsync(const BatchDeleteUniqueIdRequestT& request, const BatchDeleteUniqueIdResponseReceivedHandler& handler, const std::shared_ptr<const Aws::Client::AsyncCallerContext>& context = nullptr) const
        {
            return SubmitAsync(&EntityResolutionClient::BatchDeleteUniqueId, request, handler, context);
        }

        /**
         * <p>Creates an <code>IdMappingWorkflow</code> object which stores the
         * configuration of the data processing job to be run. Each
         * <code>IdMappingWorkflow</code> must have a unique workflow name. To modify an
         * existing workflow, use the UpdateIdMappingWorkflow API.</p><p><h3>See Also:</h3>
         * <a
         * href="http://docs.aws.amazon.com/goto/WebAPI/entityresolution-2018-05-10/CreateIdMappingWorkflow">AWS
         * API Reference</a></p>
         */
        virtual Model::CreateIdMappingWorkflowOutcome CreateIdMappingWorkflow(const Model::CreateIdMappingWorkflowRequest& request) const;

        /**
         * A Callable wrapper for CreateIdMappingWorkflow that returns a future to the operation so that it can be executed in parallel to other requests.
         */
        template<typename CreateIdMappingWorkflowRequestT = Model::CreateIdMappingWorkflowRequest>
        Model::CreateIdMappingWorkflowOutcomeCallable CreateIdMappingWorkflowCallable(const CreateIdMappingWorkflowRequestT& request) const
        {
            return SubmitCallable(&EntityResolutionClient::CreateIdMappingWorkflow, request);
        }

        /**
         * An Async wrapper for CreateIdMappingWorkflow that queues the request into a thread executor and triggers associated callback when operation has finished.
         */
        template<typename CreateIdMappingWorkflowRequestT = Model::CreateIdMappingWorkflowRequest>
        void CreateIdMappingWorkflowAsync(const CreateIdMappingWorkflowRequestT& request, const CreateIdMappingWorkflowResponseReceivedHandler& handler, const std::shared_ptr<const Aws::Client::AsyncCallerContext>& context = nullptr) const
        {
            return SubmitAsync(&EntityResolutionClient::CreateIdMappingWorkflow, request, handler, context);
        }

        /**
         * <p>Creates an ID namespace object which will help customers provide metadata
         * explaining their dataset and how to use it. Each ID namespace must have a unique
         * name. To modify an existing ID namespace, use the UpdateIdNamespace
         * API.</p><p><h3>See Also:</h3>   <a
         * href="http://docs.aws.amazon.com/goto/WebAPI/entityresolution-2018-05-10/CreateIdNamespace">AWS
         * API Reference</a></p>
         */
        virtual Model::CreateIdNamespaceOutcome CreateIdNamespace(const Model::CreateIdNamespaceRequest& request) const;

        /**
         * A Callable wrapper for CreateIdNamespace that returns a future to the operation so that it can be executed in parallel to other requests.
         */
        template<typename CreateIdNamespaceRequestT = Model::CreateIdNamespaceRequest>
        Model::CreateIdNamespaceOutcomeCallable CreateIdNamespaceCallable(const CreateIdNamespaceRequestT& request) const
        {
            return SubmitCallable(&EntityResolutionClient::CreateIdNamespace, request);
        }

        /**
         * An Async wrapper for CreateIdNamespace that queues the request into a thread executor and triggers associated callback when operation has finished.
         */
        template<typename CreateIdNamespaceRequestT = Model::CreateIdNamespaceRequest>
        void CreateIdNamespaceAsync(const CreateIdNamespaceRequestT& request, const CreateIdNamespaceResponseReceivedHandler& handler, const std::shared_ptr<const Aws::Client::AsyncCallerContext>& context = nullptr) const
        {
            return SubmitAsync(&EntityResolutionClient::CreateIdNamespace, request, handler, context);
        }

        /**
         * <p>Creates a matching workflow that defines the configuration for a data
         * processing job. The workflow name must be unique. To modify an existing
         * workflow, use <code>UpdateMatchingWorkflow</code>. </p>  <p>For
         * workflows where <code>resolutionType</code> is ML_MATCHING, incremental
         * processing is not supported. </p> <p><h3>See Also:</h3>   <a
         * href="http://docs.aws.amazon.com/goto/WebAPI/entityresolution-2018-05-10/CreateMatchingWorkflow">AWS
         * API Reference</a></p>
         */
        virtual Model::CreateMatchingWorkflowOutcome CreateMatchingWorkflow(const Model::CreateMatchingWorkflowRequest& request) const;

        /**
         * A Callable wrapper for CreateMatchingWorkflow that returns a future to the operation so that it can be executed in parallel to other requests.
         */
        template<typename CreateMatchingWorkflowRequestT = Model::CreateMatchingWorkflowRequest>
        Model::CreateMatchingWorkflowOutcomeCallable CreateMatchingWorkflowCallable(const CreateMatchingWorkflowRequestT& request) const
        {
            return SubmitCallable(&EntityResolutionClient::CreateMatchingWorkflow, request);
        }

        /**
         * An Async wrapper for CreateMatchingWorkflow that queues the request into a thread executor and triggers associated callback when operation has finished.
         */
        template<typename CreateMatchingWorkflowRequestT = Model::CreateMatchingWorkflowRequest>
        void CreateMatchingWorkflowAsync(const CreateMatchingWorkflowRequestT& request, const CreateMatchingWorkflowResponseReceivedHandler& handler, const std::shared_ptr<const Aws::Client::AsyncCallerContext>& context = nullptr) const
        {
            return SubmitAsync(&EntityResolutionClient::CreateMatchingWorkflow, request, handler, context);
        }

        /**
         * <p>Creates a schema mapping, which defines the schema of the input customer
         * records table. The <code>SchemaMapping</code> also provides Entity Resolution
         * with some metadata about the table, such as the attribute types of the columns
         * and which columns to match on.</p><p><h3>See Also:</h3>   <a
         * href="http://docs.aws.amazon.com/goto/WebAPI/entityresolution-2018-05-10/CreateSchemaMapping">AWS
         * API Reference</a></p>
         */
        virtual Model::CreateSchemaMappingOutcome CreateSchemaMapping(const Model::CreateSchemaMappingRequest& request) const;

        /**
         * A Callable wrapper for CreateSchemaMapping that returns a future to the operation so that it can be executed in parallel to other requests.
         */
        template<typename CreateSchemaMappingRequestT = Model::CreateSchemaMappingRequest>
        Model::CreateSchemaMappingOutcomeCallable CreateSchemaMappingCallable(const CreateSchemaMappingRequestT& request) const
        {
            return SubmitCallable(&EntityResolutionClient::CreateSchemaMapping, request);
        }

        /**
         * An Async wrapper for CreateSchemaMapping that queues the request into a thread executor and triggers associated callback when operation has finished.
         */
        template<typename CreateSchemaMappingRequestT = Model::CreateSchemaMappingRequest>
        void CreateSchemaMappingAsync(const CreateSchemaMappingRequestT& request, const CreateSchemaMappingResponseReceivedHandler& handler, const std::shared_ptr<const Aws::Client::AsyncCallerContext>& context = nullptr) const
        {
            return SubmitAsync(&EntityResolutionClient::CreateSchemaMapping, request, handler, context);
        }

        /**
         * <p>Deletes the <code>IdMappingWorkflow</code> with a given name. This operation
         * will succeed even if a workflow with the given name does not
         * exist.</p><p><h3>See Also:</h3>   <a
         * href="http://docs.aws.amazon.com/goto/WebAPI/entityresolution-2018-05-10/DeleteIdMappingWorkflow">AWS
         * API Reference</a></p>
         */
        virtual Model::DeleteIdMappingWorkflowOutcome DeleteIdMappingWorkflow(const Model::DeleteIdMappingWorkflowRequest& request) const;

        /**
         * A Callable wrapper for DeleteIdMappingWorkflow that returns a future to the operation so that it can be executed in parallel to other requests.
         */
        template<typename DeleteIdMappingWorkflowRequestT = Model::DeleteIdMappingWorkflowRequest>
        Model::DeleteIdMappingWorkflowOutcomeCallable DeleteIdMappingWorkflowCallable(const DeleteIdMappingWorkflowRequestT& request) const
        {
            return SubmitCallable(&EntityResolutionClient::DeleteIdMappingWorkflow, request);
        }

        /**
         * An Async wrapper for DeleteIdMappingWorkflow that queues the request into a thread executor and triggers associated callback when operation has finished.
         */
        template<typename DeleteIdMappingWorkflowRequestT = Model::DeleteIdMappingWorkflowRequest>
        void DeleteIdMappingWorkflowAsync(const DeleteIdMappingWorkflowRequestT& request, const DeleteIdMappingWorkflowResponseReceivedHandler& handler, const std::shared_ptr<const Aws::Client::AsyncCallerContext>& context = nullptr) const
        {
            return SubmitAsync(&EntityResolutionClient::DeleteIdMappingWorkflow, request, handler, context);
        }

        /**
         * <p>Deletes the <code>IdNamespace</code> with a given name.</p><p><h3>See
         * Also:</h3>   <a
         * href="http://docs.aws.amazon.com/goto/WebAPI/entityresolution-2018-05-10/DeleteIdNamespace">AWS
         * API Reference</a></p>
         */
        virtual Model::DeleteIdNamespaceOutcome DeleteIdNamespace(const Model::DeleteIdNamespaceRequest& request) const;

        /**
         * A Callable wrapper for DeleteIdNamespace that returns a future to the operation so that it can be executed in parallel to other requests.
         */
        template<typename DeleteIdNamespaceRequestT = Model::DeleteIdNamespaceRequest>
        Model::DeleteIdNamespaceOutcomeCallable DeleteIdNamespaceCallable(const DeleteIdNamespaceRequestT& request) const
        {
            return SubmitCallable(&EntityResolutionClient::DeleteIdNamespace, request);
        }

        /**
         * An Async wrapper for DeleteIdNamespace that queues the request into a thread executor and triggers associated callback when operation has finished.
         */
        template<typename DeleteIdNamespaceRequestT = Model::DeleteIdNamespaceRequest>
        void DeleteIdNamespaceAsync(const DeleteIdNamespaceRequestT& request, const DeleteIdNamespaceResponseReceivedHandler& handler, const std::shared_ptr<const Aws::Client::AsyncCallerContext>& context = nullptr) const
        {
            return SubmitAsync(&EntityResolutionClient::DeleteIdNamespace, request, handler, context);
        }

        /**
         * <p>Deletes the <code>MatchingWorkflow</code> with a given name. This operation
         * will succeed even if a workflow with the given name does not
         * exist.</p><p><h3>See Also:</h3>   <a
         * href="http://docs.aws.amazon.com/goto/WebAPI/entityresolution-2018-05-10/DeleteMatchingWorkflow">AWS
         * API Reference</a></p>
         */
        virtual Model::DeleteMatchingWorkflowOutcome DeleteMatchingWorkflow(const Model::DeleteMatchingWorkflowRequest& request) const;

        /**
         * A Callable wrapper for DeleteMatchingWorkflow that returns a future to the operation so that it can be executed in parallel to other requests.
         */
        template<typename DeleteMatchingWorkflowRequestT = Model::DeleteMatchingWorkflowRequest>
        Model::DeleteMatchingWorkflowOutcomeCallable DeleteMatchingWorkflowCallable(const DeleteMatchingWorkflowRequestT& request) const
        {
            return SubmitCallable(&EntityResolutionClient::DeleteMatchingWorkflow, request);
        }

        /**
         * An Async wrapper for DeleteMatchingWorkflow that queues the request into a thread executor and triggers associated callback when operation has finished.
         */
        template<typename DeleteMatchingWorkflowRequestT = Model::DeleteMatchingWorkflowRequest>
        void DeleteMatchingWorkflowAsync(const DeleteMatchingWorkflowRequestT& request, const DeleteMatchingWorkflowResponseReceivedHandler& handler, const std::shared_ptr<const Aws::Client::AsyncCallerContext>& context = nullptr) const
        {
            return SubmitAsync(&EntityResolutionClient::DeleteMatchingWorkflow, request, handler, context);
        }

        /**
         * <p>Deletes the policy statement.</p><p><h3>See Also:</h3>   <a
         * href="http://docs.aws.amazon.com/goto/WebAPI/entityresolution-2018-05-10/DeletePolicyStatement">AWS
         * API Reference</a></p>
         */
        virtual Model::DeletePolicyStatementOutcome DeletePolicyStatement(const Model::DeletePolicyStatementRequest& request) const;

        /**
         * A Callable wrapper for DeletePolicyStatement that returns a future to the operation so that it can be executed in parallel to other requests.
         */
        template<typename DeletePolicyStatementRequestT = Model::DeletePolicyStatementRequest>
        Model::DeletePolicyStatementOutcomeCallable DeletePolicyStatementCallable(const DeletePolicyStatementRequestT& request) const
        {
            return SubmitCallable(&EntityResolutionClient::DeletePolicyStatement, request);
        }

        /**
         * An Async wrapper for DeletePolicyStatement that queues the request into a thread executor and triggers associated callback when operation has finished.
         */
        template<typename DeletePolicyStatementRequestT = Model::DeletePolicyStatementRequest>
        void DeletePolicyStatementAsync(const DeletePolicyStatementRequestT& request, const DeletePolicyStatementResponseReceivedHandler& handler, const std::shared_ptr<const Aws::Client::AsyncCallerContext>& context = nullptr) const
        {
            return SubmitAsync(&EntityResolutionClient::DeletePolicyStatement, request, handler, context);
        }

        /**
         * <p>Deletes the <code>SchemaMapping</code> with a given name. This operation will
         * succeed even if a schema with the given name does not exist. This operation will
         * fail if there is a <code>MatchingWorkflow</code> object that references the
         * <code>SchemaMapping</code> in the workflow's
         * <code>InputSourceConfig</code>.</p><p><h3>See Also:</h3>   <a
         * href="http://docs.aws.amazon.com/goto/WebAPI/entityresolution-2018-05-10/DeleteSchemaMapping">AWS
         * API Reference</a></p>
         */
        virtual Model::DeleteSchemaMappingOutcome DeleteSchemaMapping(const Model::DeleteSchemaMappingRequest& request) const;

        /**
         * A Callable wrapper for DeleteSchemaMapping that returns a future to the operation so that it can be executed in parallel to other requests.
         */
        template<typename DeleteSchemaMappingRequestT = Model::DeleteSchemaMappingRequest>
        Model::DeleteSchemaMappingOutcomeCallable DeleteSchemaMappingCallable(const DeleteSchemaMappingRequestT& request) const
        {
            return SubmitCallable(&EntityResolutionClient::DeleteSchemaMapping, request);
        }

        /**
         * An Async wrapper for DeleteSchemaMapping that queues the request into a thread executor and triggers associated callback when operation has finished.
         */
        template<typename DeleteSchemaMappingRequestT = Model::DeleteSchemaMappingRequest>
        void DeleteSchemaMappingAsync(const DeleteSchemaMappingRequestT& request, const DeleteSchemaMappingResponseReceivedHandler& handler, const std::shared_ptr<const Aws::Client::AsyncCallerContext>& context = nullptr) const
        {
            return SubmitAsync(&EntityResolutionClient::DeleteSchemaMapping, request, handler, context);
        }

        /**
         * <p>Generates or retrieves Match IDs for records using a rule-based matching
         * workflow. When you call this operation, it processes your records against the
         * workflow's matching rules to identify potential matches. For existing records,
         * it retrieves their Match IDs and associated rules. For records without matches,
         * it generates new Match IDs. The operation saves results to Amazon S3. </p>
         * <p>The processing type (<code>processingType</code>) you choose affects both the
         * accuracy and response time of the operation. Additional charges apply for each
         * API call, whether made through the Entity Resolution console or directly via the
         * API. The rule-based matching workflow must exist and be active before calling
         * this operation.</p><p><h3>See Also:</h3>   <a
         * href="http://docs.aws.amazon.com/goto/WebAPI/entityresolution-2018-05-10/GenerateMatchId">AWS
         * API Reference</a></p>
         */
        virtual Model::GenerateMatchIdOutcome GenerateMatchId(const Model::GenerateMatchIdRequest& request) const;

        /**
         * A Callable wrapper for GenerateMatchId that returns a future to the operation so that it can be executed in parallel to other requests.
         */
        template<typename GenerateMatchIdRequestT = Model::GenerateMatchIdRequest>
        Model::GenerateMatchIdOutcomeCallable GenerateMatchIdCallable(const GenerateMatchIdRequestT& request) const
        {
            return SubmitCallable(&EntityResolutionClient::GenerateMatchId, request);
        }

        /**
         * An Async wrapper for GenerateMatchId that queues the request into a thread executor and triggers associated callback when operation has finished.
         */
        template<typename GenerateMatchIdRequestT = Model::GenerateMatchIdRequest>
        void GenerateMatchIdAsync(const GenerateMatchIdRequestT& request, const GenerateMatchIdResponseReceivedHandler& handler, const std::shared_ptr<const Aws::Client::AsyncCallerContext>& context = nullptr) const
        {
            return SubmitAsync(&EntityResolutionClient::GenerateMatchId, request, handler, context);
        }

        /**
         * <p>Returns the status, metrics, and errors (if there are any) that are
         * associated with a job.</p><p><h3>See Also:</h3>   <a
         * href="http://docs.aws.amazon.com/goto/WebAPI/entityresolution-2018-05-10/GetIdMappingJob">AWS
         * API Reference</a></p>
         */
        virtual Model::GetIdMappingJobOutcome GetIdMappingJob(const Model::GetIdMappingJobRequest& request) const;

        /**
         * A Callable wrapper for GetIdMappingJob that returns a future to the operation so that it can be executed in parallel to other requests.
         */
        template<typename GetIdMappingJobRequestT = Model::GetIdMappingJobRequest>
        Model::GetIdMappingJobOutcomeCallable GetIdMappingJobCallable(const GetIdMappingJobRequestT& request) const
        {
            return SubmitCallable(&EntityResolutionClient::GetIdMappingJob, request);
        }

        /**
         * An Async wrapper for GetIdMappingJob that queues the request into a thread executor and triggers associated callback when operation has finished.
         */
        template<typename GetIdMappingJobRequestT = Model::GetIdMappingJobRequest>
        void GetIdMappingJobAsync(const GetIdMappingJobRequestT& request, const GetIdMappingJobResponseReceivedHandler& handler, const std::shared_ptr<const Aws::Client::AsyncCallerContext>& context = nullptr) const
        {
            return SubmitAsync(&EntityResolutionClient::GetIdMappingJob, request, handler, context);
        }

        /**
         * <p>Returns the <code>IdMappingWorkflow</code> with a given name, if it
         * exists.</p><p><h3>See Also:</h3>   <a
         * href="http://docs.aws.amazon.com/goto/WebAPI/entityresolution-2018-05-10/GetIdMappingWorkflow">AWS
         * API Reference</a></p>
         */
        virtual Model::GetIdMappingWorkflowOutcome GetIdMappingWorkflow(const Model::GetIdMappingWorkflowRequest& request) const;

        /**
         * A Callable wrapper for GetIdMappingWorkflow that returns a future to the operation so that it can be executed in parallel to other requests.
         */
        template<typename GetIdMappingWorkflowRequestT = Model::GetIdMappingWorkflowRequest>
        Model::GetIdMappingWorkflowOutcomeCallable GetIdMappingWorkflowCallable(const GetIdMappingWorkflowRequestT& request) const
        {
            return SubmitCallable(&EntityResolutionClient::GetIdMappingWorkflow, request);
        }

        /**
         * An Async wrapper for GetIdMappingWorkflow that queues the request into a thread executor and triggers associated callback when operation has finished.
         */
        template<typename GetIdMappingWorkflowRequestT = Model::GetIdMappingWorkflowRequest>
        void GetIdMappingWorkflowAsync(const GetIdMappingWorkflowRequestT& request, const GetIdMappingWorkflowResponseReceivedHandler& handler, const std::shared_ptr<const Aws::Client::AsyncCallerContext>& context = nullptr) const
        {
            return SubmitAsync(&EntityResolutionClient::GetIdMappingWorkflow, request, handler, context);
        }

        /**
         * <p>Returns the <code>IdNamespace</code> with a given name, if it
         * exists.</p><p><h3>See Also:</h3>   <a
         * href="http://docs.aws.amazon.com/goto/WebAPI/entityresolution-2018-05-10/GetIdNamespace">AWS
         * API Reference</a></p>
         */
        virtual Model::GetIdNamespaceOutcome GetIdNamespace(const Model::GetIdNamespaceRequest& request) const;

        /**
         * A Callable wrapper for GetIdNamespace that returns a future to the operation so that it can be executed in parallel to other requests.
         */
        template<typename GetIdNamespaceRequestT = Model::GetIdNamespaceRequest>
        Model::GetIdNamespaceOutcomeCallable GetIdNamespaceCallable(const GetIdNamespaceRequestT& request) const
        {
            return SubmitCallable(&EntityResolutionClient::GetIdNamespace, request);
        }

        /**
         * An Async wrapper for GetIdNamespace that queues the request into a thread executor and triggers associated callback when operation has finished.
         */
        template<typename GetIdNamespaceRequestT = Model::GetIdNamespaceRequest>
        void GetIdNamespaceAsync(const GetIdNamespaceRequestT& request, const GetIdNamespaceResponseReceivedHandler& handler, const std::shared_ptr<const Aws::Client::AsyncCallerContext>& context = nullptr) const
        {
            return SubmitAsync(&EntityResolutionClient::GetIdNamespace, request, handler, context);
        }

        /**
         * <p>Returns the corresponding Match ID of a customer record if the record has
         * been processed in a rule-based matching workflow or ML matching workflow.</p>
         * <p>You can call this API as a dry run of an incremental load on the rule-based
         * matching workflow.</p><p><h3>See Also:</h3>   <a
         * href="http://docs.aws.amazon.com/goto/WebAPI/entityresolution-2018-05-10/GetMatchId">AWS
         * API Reference</a></p>
         */
        virtual Model::GetMatchIdOutcome GetMatchId(const Model::GetMatchIdRequest& request) const;

        /**
         * A Callable wrapper for GetMatchId that returns a future to the operation so that it can be executed in parallel to other requests.
         */
        template<typename GetMatchIdRequestT = Model::GetMatchIdRequest>
        Model::GetMatchIdOutcomeCallable GetMatchIdCallable(const GetMatchIdRequestT& request) const
        {
            return SubmitCallable(&EntityResolutionClient::GetMatchId, request);
        }

        /**
         * An Async wrapper for GetMatchId that queues the request into a thread executor and triggers associated callback when operation has finished.
         */
        template<typename GetMatchIdRequestT = Model::GetMatchIdRequest>
        void GetMatchIdAsync(const GetMatchIdRequestT& request, const GetMatchIdResponseReceivedHandler& handler, const std::shared_ptr<const Aws::Client::AsyncCallerContext>& context = nullptr) const
        {
            return SubmitAsync(&EntityResolutionClient::GetMatchId, request, handler, context);
        }

        /**
         * <p>Returns the status, metrics, and errors (if there are any) that are
         * associated with a job.</p><p><h3>See Also:</h3>   <a
         * href="http://docs.aws.amazon.com/goto/WebAPI/entityresolution-2018-05-10/GetMatchingJob">AWS
         * API Reference</a></p>
         */
        virtual Model::GetMatchingJobOutcome GetMatchingJob(const Model::GetMatchingJobRequest& request) const;

        /**
         * A Callable wrapper for GetMatchingJob that returns a future to the operation so that it can be executed in parallel to other requests.
         */
        template<typename GetMatchingJobRequestT = Model::GetMatchingJobRequest>
        Model::GetMatchingJobOutcomeCallable GetMatchingJobCallable(const GetMatchingJobRequestT& request) const
        {
            return SubmitCallable(&EntityResolutionClient::GetMatchingJob, request);
        }

        /**
         * An Async wrapper for GetMatchingJob that queues the request into a thread executor and triggers associated callback when operation has finished.
         */
        template<typename GetMatchingJobRequestT = Model::GetMatchingJobRequest>
        void GetMatchingJobAsync(const GetMatchingJobRequestT& request, const GetMatchingJobResponseReceivedHandler& handler, const std::shared_ptr<const Aws::Client::AsyncCallerContext>& context = nullptr) const
        {
            return SubmitAsync(&EntityResolutionClient::GetMatchingJob, request, handler, context);
        }

        /**
         * <p>Returns the <code>MatchingWorkflow</code> with a given name, if it
         * exists.</p><p><h3>See Also:</h3>   <a
         * href="http://docs.aws.amazon.com/goto/WebAPI/entityresolution-2018-05-10/GetMatchingWorkflow">AWS
         * API Reference</a></p>
         */
        virtual Model::GetMatchingWorkflowOutcome GetMatchingWorkflow(const Model::GetMatchingWorkflowRequest& request) const;

        /**
         * A Callable wrapper for GetMatchingWorkflow that returns a future to the operation so that it can be executed in parallel to other requests.
         */
        template<typename GetMatchingWorkflowRequestT = Model::GetMatchingWorkflowRequest>
        Model::GetMatchingWorkflowOutcomeCallable GetMatchingWorkflowCallable(const GetMatchingWorkflowRequestT& request) const
        {
            return SubmitCallable(&EntityResolutionClient::GetMatchingWorkflow, request);
        }

        /**
         * An Async wrapper for GetMatchingWorkflow that queues the request into a thread executor and triggers associated callback when operation has finished.
         */
        template<typename GetMatchingWorkflowRequestT = Model::GetMatchingWorkflowRequest>
        void GetMatchingWorkflowAsync(const GetMatchingWorkflowRequestT& request, const GetMatchingWorkflowResponseReceivedHandler& handler, const std::shared_ptr<const Aws::Client::AsyncCallerContext>& context = nullptr) const
        {
            return SubmitAsync(&EntityResolutionClient::GetMatchingWorkflow, request, handler, context);
        }

        /**
         * <p>Returns the resource-based policy.</p><p><h3>See Also:</h3>   <a
         * href="http://docs.aws.amazon.com/goto/WebAPI/entityresolution-2018-05-10/GetPolicy">AWS
         * API Reference</a></p>
         */
        virtual Model::GetPolicyOutcome GetPolicy(const Model::GetPolicyRequest& request) const;

        /**
         * A Callable wrapper for GetPolicy that returns a future to the operation so that it can be executed in parallel to other requests.
         */
        template<typename GetPolicyRequestT = Model::GetPolicyRequest>
        Model::GetPolicyOutcomeCallable GetPolicyCallable(const GetPolicyRequestT& request) const
        {
            return SubmitCallable(&EntityResolutionClient::GetPolicy, request);
        }

        /**
         * An Async wrapper for GetPolicy that queues the request into a thread executor and triggers associated callback when operation has finished.
         */
        template<typename GetPolicyRequestT = Model::GetPolicyRequest>
        void GetPolicyAsync(const GetPolicyRequestT& request, const GetPolicyResponseReceivedHandler& handler, const std::shared_ptr<const Aws::Client::AsyncCallerContext>& context = nullptr) const
        {
            return SubmitAsync(&EntityResolutionClient::GetPolicy, request, handler, context);
        }

        /**
         * <p>Returns the <code>ProviderService</code> of a given name.</p><p><h3>See
         * Also:</h3>   <a
         * href="http://docs.aws.amazon.com/goto/WebAPI/entityresolution-2018-05-10/GetProviderService">AWS
         * API Reference</a></p>
         */
        virtual Model::GetProviderServiceOutcome GetProviderService(const Model::GetProviderServiceRequest& request) const;

        /**
         * A Callable wrapper for GetProviderService that returns a future to the operation so that it can be executed in parallel to other requests.
         */
        template<typename GetProviderServiceRequestT = Model::GetProviderServiceRequest>
        Model::GetProviderServiceOutcomeCallable GetProviderServiceCallable(const GetProviderServiceRequestT& request) const
        {
            return SubmitCallable(&EntityResolutionClient::GetProviderService, request);
        }

        /**
         * An Async wrapper for GetProviderService that queues the request into a thread executor and triggers associated callback when operation has finished.
         */
        template<typename GetProviderServiceRequestT = Model::GetProviderServiceRequest>
        void GetProviderServiceAsync(const GetProviderServiceRequestT& request, const GetProviderServiceResponseReceivedHandler& handler, const std::shared_ptr<const Aws::Client::AsyncCallerContext>& context = nullptr) const
        {
            return SubmitAsync(&EntityResolutionClient::GetProviderService, request, handler, context);
        }

        /**
         * <p>Returns the SchemaMapping of a given name.</p><p><h3>See Also:</h3>   <a
         * href="http://docs.aws.amazon.com/goto/WebAPI/entityresolution-2018-05-10/GetSchemaMapping">AWS
         * API Reference</a></p>
         */
        virtual Model::GetSchemaMappingOutcome GetSchemaMapping(const Model::GetSchemaMappingRequest& request) const;

        /**
         * A Callable wrapper for GetSchemaMapping that returns a future to the operation so that it can be executed in parallel to other requests.
         */
        template<typename GetSchemaMappingRequestT = Model::GetSchemaMappingRequest>
        Model::GetSchemaMappingOutcomeCallable GetSchemaMappingCallable(const GetSchemaMappingRequestT& request) const
        {
            return SubmitCallable(&EntityResolutionClient::GetSchemaMapping, request);
        }

        /**
         * An Async wrapper for GetSchemaMapping that queues the request into a thread executor and triggers associated callback when operation has finished.
         */
        template<typename GetSchemaMappingRequestT = Model::GetSchemaMappingRequest>
        void GetSchemaMappingAsync(const GetSchemaMappingRequestT& request, const GetSchemaMappingResponseReceivedHandler& handler, const std::shared_ptr<const Aws::Client::AsyncCallerContext>& context = nullptr) const
        {
            return SubmitAsync(&EntityResolutionClient::GetSchemaMapping, request, handler, context);
        }

        /**
         * <p>Lists all ID mapping jobs for a given workflow.</p><p><h3>See Also:</h3>   <a
         * href="http://docs.aws.amazon.com/goto/WebAPI/entityresolution-2018-05-10/ListIdMappingJobs">AWS
         * API Reference</a></p>
         */
        virtual Model::ListIdMappingJobsOutcome ListIdMappingJobs(const Model::ListIdMappingJobsRequest& request) const;

        /**
         * A Callable wrapper for ListIdMappingJobs that returns a future to the operation so that it can be executed in parallel to other requests.
         */
        template<typename ListIdMappingJobsRequestT = Model::ListIdMappingJobsRequest>
        Model::ListIdMappingJobsOutcomeCallable ListIdMappingJobsCallable(const ListIdMappingJobsRequestT& request) const
        {
            return SubmitCallable(&EntityResolutionClient::ListIdMappingJobs, request);
        }

        /**
         * An Async wrapper for ListIdMappingJobs that queues the request into a thread executor and triggers associated callback when operation has finished.
         */
        template<typename ListIdMappingJobsRequestT = Model::ListIdMappingJobsRequest>
        void ListIdMappingJobsAsync(const ListIdMappingJobsRequestT& request, const ListIdMappingJobsResponseReceivedHandler& handler, const std::shared_ptr<const Aws::Client::AsyncCallerContext>& context = nullptr) const
        {
            return SubmitAsync(&EntityResolutionClient::ListIdMappingJobs, request, handler, context);
        }

        /**
         * <p>Returns a list of all the <code>IdMappingWorkflows</code> that have been
         * created for an Amazon Web Services account.</p><p><h3>See Also:</h3>   <a
         * href="http://docs.aws.amazon.com/goto/WebAPI/entityresolution-2018-05-10/ListIdMappingWorkflows">AWS
         * API Reference</a></p>
         */
        virtual Model::ListIdMappingWorkflowsOutcome ListIdMappingWorkflows(const Model::ListIdMappingWorkflowsRequest& request = {}) const;

        /**
         * A Callable wrapper for ListIdMappingWorkflows that returns a future to the operation so that it can be executed in parallel to other requests.
         */
        template<typename ListIdMappingWorkflowsRequestT = Model::ListIdMappingWorkflowsRequest>
        Model::ListIdMappingWorkflowsOutcomeCallable ListIdMappingWorkflowsCallable(const ListIdMappingWorkflowsRequestT& request = {}) const
        {
            return SubmitCallable(&EntityResolutionClient::ListIdMappingWorkflows, request);
        }

        /**
         * An Async wrapper for ListIdMappingWorkflows that queues the request into a thread executor and triggers associated callback when operation has finished.
         */
        template<typename ListIdMappingWorkflowsRequestT = Model::ListIdMappingWorkflowsRequest>
        void ListIdMappingWorkflowsAsync(const ListIdMappingWorkflowsResponseReceivedHandler& handler, const std::shared_ptr<const Aws::Client::AsyncCallerContext>& context = nullptr, const ListIdMappingWorkflowsRequestT& request = {}) const
        {
            return SubmitAsync(&EntityResolutionClient::ListIdMappingWorkflows, request, handler, context);
        }

        /**
         * <p>Returns a list of all ID namespaces.</p><p><h3>See Also:</h3>   <a
         * href="http://docs.aws.amazon.com/goto/WebAPI/entityresolution-2018-05-10/ListIdNamespaces">AWS
         * API Reference</a></p>
         */
        virtual Model::ListIdNamespacesOutcome ListIdNamespaces(const Model::ListIdNamespacesRequest& request = {}) const;

        /**
         * A Callable wrapper for ListIdNamespaces that returns a future to the operation so that it can be executed in parallel to other requests.
         */
        template<typename ListIdNamespacesRequestT = Model::ListIdNamespacesRequest>
        Model::ListIdNamespacesOutcomeCallable ListIdNamespacesCallable(const ListIdNamespacesRequestT& request = {}) const
        {
            return SubmitCallable(&EntityResolutionClient::ListIdNamespaces, request);
        }

        /**
         * An Async wrapper for ListIdNamespaces that queues the request into a thread executor and triggers associated callback when operation has finished.
         */
        template<typename ListIdNamespacesRequestT = Model::ListIdNamespacesRequest>
        void ListIdNamespacesAsync(const ListIdNamespacesResponseReceivedHandler& handler, const std::shared_ptr<const Aws::Client::AsyncCallerContext>& context = nullptr, const ListIdNamespacesRequestT& request = {}) const
        {
            return SubmitAsync(&EntityResolutionClient::ListIdNamespaces, request, handler, context);
        }

        /**
         * <p>Lists all jobs for a given workflow.</p><p><h3>See Also:</h3>   <a
         * href="http://docs.aws.amazon.com/goto/WebAPI/entityresolution-2018-05-10/ListMatchingJobs">AWS
         * API Reference</a></p>
         */
        virtual Model::ListMatchingJobsOutcome ListMatchingJobs(const Model::ListMatchingJobsRequest& request) const;

        /**
         * A Callable wrapper for ListMatchingJobs that returns a future to the operation so that it can be executed in parallel to other requests.
         */
        template<typename ListMatchingJobsRequestT = Model::ListMatchingJobsRequest>
        Model::ListMatchingJobsOutcomeCallable ListMatchingJobsCallable(const ListMatchingJobsRequestT& request) const
        {
            return SubmitCallable(&EntityResolutionClient::ListMatchingJobs, request);
        }

        /**
         * An Async wrapper for ListMatchingJobs that queues the request into a thread executor and triggers associated callback when operation has finished.
         */
        template<typename ListMatchingJobsRequestT = Model::ListMatchingJobsRequest>
        void ListMatchingJobsAsync(const ListMatchingJobsRequestT& request, const ListMatchingJobsResponseReceivedHandler& handler, const std::shared_ptr<const Aws::Client::AsyncCallerContext>& context = nullptr) const
        {
            return SubmitAsync(&EntityResolutionClient::ListMatchingJobs, request, handler, context);
        }

        /**
         * <p>Returns a list of all the <code>MatchingWorkflows</code> that have been
         * created for an Amazon Web Services account.</p><p><h3>See Also:</h3>   <a
         * href="http://docs.aws.amazon.com/goto/WebAPI/entityresolution-2018-05-10/ListMatchingWorkflows">AWS
         * API Reference</a></p>
         */
        virtual Model::ListMatchingWorkflowsOutcome ListMatchingWorkflows(const Model::ListMatchingWorkflowsRequest& request = {}) const;

        /**
         * A Callable wrapper for ListMatchingWorkflows that returns a future to the operation so that it can be executed in parallel to other requests.
         */
        template<typename ListMatchingWorkflowsRequestT = Model::ListMatchingWorkflowsRequest>
        Model::ListMatchingWorkflowsOutcomeCallable ListMatchingWorkflowsCallable(const ListMatchingWorkflowsRequestT& request = {}) const
        {
            return SubmitCallable(&EntityResolutionClient::ListMatchingWorkflows, request);
        }

        /**
         * An Async wrapper for ListMatchingWorkflows that queues the request into a thread executor and triggers associated callback when operation has finished.
         */
        template<typename ListMatchingWorkflowsRequestT = Model::ListMatchingWorkflowsRequest>
        void ListMatchingWorkflowsAsync(const ListMatchingWorkflowsResponseReceivedHandler& handler, const std::shared_ptr<const Aws::Client::AsyncCallerContext>& context = nullptr, const ListMatchingWorkflowsRequestT& request = {}) const
        {
            return SubmitAsync(&EntityResolutionClient::ListMatchingWorkflows, request, handler, context);
        }

        /**
         * <p>Returns a list of all the <code>ProviderServices</code> that are available in
         * this Amazon Web Services Region.</p><p><h3>See Also:</h3>   <a
         * href="http://docs.aws.amazon.com/goto/WebAPI/entityresolution-2018-05-10/ListProviderServices">AWS
         * API Reference</a></p>
         */
        virtual Model::ListProviderServicesOutcome ListProviderServices(const Model::ListProviderServicesRequest& request = {}) const;

        /**
         * A Callable wrapper for ListProviderServices that returns a future to the operation so that it can be executed in parallel to other requests.
         */
        template<typename ListProviderServicesRequestT = Model::ListProviderServicesRequest>
        Model::ListProviderServicesOutcomeCallable ListProviderServicesCallable(const ListProviderServicesRequestT& request = {}) const
        {
            return SubmitCallable(&EntityResolutionClient::ListProviderServices, request);
        }

        /**
         * An Async wrapper for ListProviderServices that queues the request into a thread executor and triggers associated callback when operation has finished.
         */
        template<typename ListProviderServicesRequestT = Model::ListProviderServicesRequest>
        void ListProviderServicesAsync(const ListProviderServicesResponseReceivedHandler& handler, const std::shared_ptr<const Aws::Client::AsyncCallerContext>& context = nullptr, const ListProviderServicesRequestT& request = {}) const
        {
            return SubmitAsync(&EntityResolutionClient::ListProviderServices, request, handler, context);
        }

        /**
         * <p>Returns a list of all the <code>SchemaMappings</code> that have been created
         * for an Amazon Web Services account.</p><p><h3>See Also:</h3>   <a
         * href="http://docs.aws.amazon.com/goto/WebAPI/entityresolution-2018-05-10/ListSchemaMappings">AWS
         * API Reference</a></p>
         */
        virtual Model::ListSchemaMappingsOutcome ListSchemaMappings(const Model::ListSchemaMappingsRequest& request = {}) const;

        /**
         * A Callable wrapper for ListSchemaMappings that returns a future to the operation so that it can be executed in parallel to other requests.
         */
        template<typename ListSchemaMappingsRequestT = Model::ListSchemaMappingsRequest>
        Model::ListSchemaMappingsOutcomeCallable ListSchemaMappingsCallable(const ListSchemaMappingsRequestT& request = {}) const
        {
            return SubmitCallable(&EntityResolutionClient::ListSchemaMappings, request);
        }

        /**
         * An Async wrapper for ListSchemaMappings that queues the request into a thread executor and triggers associated callback when operation has finished.
         */
        template<typename ListSchemaMappingsRequestT = Model::ListSchemaMappingsRequest>
        void ListSchemaMappingsAsync(const ListSchemaMappingsResponseReceivedHandler& handler, const std::shared_ptr<const Aws::Client::AsyncCallerContext>& context = nullptr, const ListSchemaMappingsRequestT& request = {}) const
        {
            return SubmitAsync(&EntityResolutionClient::ListSchemaMappings, request, handler, context);
        }

        /**
         * <p>Displays the tags associated with an Entity Resolution resource. In Entity
         * Resolution, <code>SchemaMapping</code>, and <code>MatchingWorkflow</code> can be
         * tagged.</p><p><h3>See Also:</h3>   <a
         * href="http://docs.aws.amazon.com/goto/WebAPI/entityresolution-2018-05-10/ListTagsForResource">AWS
         * API Reference</a></p>
         */
        virtual Model::ListTagsForResourceOutcome ListTagsForResource(const Model::ListTagsForResourceRequest& request) const;

        /**
         * A Callable wrapper for ListTagsForResource that returns a future to the operation so that it can be executed in parallel to other requests.
         */
        template<typename ListTagsForResourceRequestT = Model::ListTagsForResourceRequest>
        Model::ListTagsForResourceOutcomeCallable ListTagsForResourceCallable(const ListTagsForResourceRequestT& request) const
        {
            return SubmitCallable(&EntityResolutionClient::ListTagsForResource, request);
        }

        /**
         * An Async wrapper for ListTagsForResource that queues the request into a thread executor and triggers associated callback when operation has finished.
         */
        template<typename ListTagsForResourceRequestT = Model::ListTagsForResourceRequest>
        void ListTagsForResourceAsync(const ListTagsForResourceRequestT& request, const ListTagsForResourceResponseReceivedHandler& handler, const std::shared_ptr<const Aws::Client::AsyncCallerContext>& context = nullptr) const
        {
            return SubmitAsync(&EntityResolutionClient::ListTagsForResource, request, handler, context);
        }

        /**
         * <p>Updates the resource-based policy.</p><p><h3>See Also:</h3>   <a
         * href="http://docs.aws.amazon.com/goto/WebAPI/entityresolution-2018-05-10/PutPolicy">AWS
         * API Reference</a></p>
         */
        virtual Model::PutPolicyOutcome PutPolicy(const Model::PutPolicyRequest& request) const;

        /**
         * A Callable wrapper for PutPolicy that returns a future to the operation so that it can be executed in parallel to other requests.
         */
        template<typename PutPolicyRequestT = Model::PutPolicyRequest>
        Model::PutPolicyOutcomeCallable PutPolicyCallable(const PutPolicyRequestT& request) const
        {
            return SubmitCallable(&EntityResolutionClient::PutPolicy, request);
        }

        /**
         * An Async wrapper for PutPolicy that queues the request into a thread executor and triggers associated callback when operation has finished.
         */
        template<typename PutPolicyRequestT = Model::PutPolicyRequest>
        void PutPolicyAsync(const PutPolicyRequestT& request, const PutPolicyResponseReceivedHandler& handler, const std::shared_ptr<const Aws::Client::AsyncCallerContext>& context = nullptr) const
        {
            return SubmitAsync(&EntityResolutionClient::PutPolicy, request, handler, context);
        }

        /**
         * <p>Starts the <code>IdMappingJob</code> of a workflow. The workflow must have
         * previously been created using the <code>CreateIdMappingWorkflow</code>
         * endpoint.</p><p><h3>See Also:</h3>   <a
         * href="http://docs.aws.amazon.com/goto/WebAPI/entityresolution-2018-05-10/StartIdMappingJob">AWS
         * API Reference</a></p>
         */
        virtual Model::StartIdMappingJobOutcome StartIdMappingJob(const Model::StartIdMappingJobRequest& request) const;

        /**
         * A Callable wrapper for StartIdMappingJob that returns a future to the operation so that it can be executed in parallel to other requests.
         */
        template<typename StartIdMappingJobRequestT = Model::StartIdMappingJobRequest>
        Model::StartIdMappingJobOutcomeCallable StartIdMappingJobCallable(const StartIdMappingJobRequestT& request) const
        {
            return SubmitCallable(&EntityResolutionClient::StartIdMappingJob, request);
        }

        /**
         * An Async wrapper for StartIdMappingJob that queues the request into a thread executor and triggers associated callback when operation has finished.
         */
        template<typename StartIdMappingJobRequestT = Model::StartIdMappingJobRequest>
        void StartIdMappingJobAsync(const StartIdMappingJobRequestT& request, const StartIdMappingJobResponseReceivedHandler& handler, const std::shared_ptr<const Aws::Client::AsyncCallerContext>& context = nullptr) const
        {
            return SubmitAsync(&EntityResolutionClient::StartIdMappingJob, request, handler, context);
        }

        /**
         * <p>Starts the <code>MatchingJob</code> of a workflow. The workflow must have
         * previously been created using the <code>CreateMatchingWorkflow</code>
         * endpoint.</p><p><h3>See Also:</h3>   <a
         * href="http://docs.aws.amazon.com/goto/WebAPI/entityresolution-2018-05-10/StartMatchingJob">AWS
         * API Reference</a></p>
         */
        virtual Model::StartMatchingJobOutcome StartMatchingJob(const Model::StartMatchingJobRequest& request) const;

        /**
         * A Callable wrapper for StartMatchingJob that returns a future to the operation so that it can be executed in parallel to other requests.
         */
        template<typename StartMatchingJobRequestT = Model::StartMatchingJobRequest>
        Model::StartMatchingJobOutcomeCallable StartMatchingJobCallable(const StartMatchingJobRequestT& request) const
        {
            return SubmitCallable(&EntityResolutionClient::StartMatchingJob, request);
        }

        /**
         * An Async wrapper for StartMatchingJob that queues the request into a thread executor and triggers associated callback when operation has finished.
         */
        template<typename StartMatchingJobRequestT = Model::StartMatchingJobRequest>
        void StartMatchingJobAsync(const StartMatchingJobRequestT& request, const StartMatchingJobResponseReceivedHandler& handler, const std::shared_ptr<const Aws::Client::AsyncCallerContext>& context = nullptr) const
        {
            return SubmitAsync(&EntityResolutionClient::StartMatchingJob, request, handler, context);
        }

        /**
         * <p>Assigns one or more tags (key-value pairs) to the specified Entity Resolution
         * resource. Tags can help you organize and categorize your resources. You can also
         * use them to scope user permissions by granting a user permission to access or
         * change only resources with certain tag values. In Entity Resolution,
         * <code>SchemaMapping</code> and <code>MatchingWorkflow</code> can be tagged. Tags
         * don't have any semantic meaning to Amazon Web Services and are interpreted
         * strictly as strings of characters. You can use the <code>TagResource</code>
         * action with a resource that already has tags. If you specify a new tag key, this
         * tag is appended to the list of tags associated with the resource. If you specify
         * a tag key that is already associated with the resource, the new tag value that
         * you specify replaces the previous value for that tag.</p><p><h3>See Also:</h3>  
         * <a
         * href="http://docs.aws.amazon.com/goto/WebAPI/entityresolution-2018-05-10/TagResource">AWS
         * API Reference</a></p>
         */
        virtual Model::TagResourceOutcome TagResource(const Model::TagResourceRequest& request) const;

        /**
         * A Callable wrapper for TagResource that returns a future to the operation so that it can be executed in parallel to other requests.
         */
        template<typename TagResourceRequestT = Model::TagResourceRequest>
        Model::TagResourceOutcomeCallable TagResourceCallable(const TagResourceRequestT& request) const
        {
            return SubmitCallable(&EntityResolutionClient::TagResource, request);
        }

        /**
         * An Async wrapper for TagResource that queues the request into a thread executor and triggers associated callback when operation has finished.
         */
        template<typename TagResourceRequestT = Model::TagResourceRequest>
        void TagResourceAsync(const TagResourceRequestT& request, const TagResourceResponseReceivedHandler& handler, const std::shared_ptr<const Aws::Client::AsyncCallerContext>& context = nullptr) const
        {
            return SubmitAsync(&EntityResolutionClient::TagResource, request, handler, context);
        }

        /**
         * <p>Removes one or more tags from the specified Entity Resolution resource. In
         * Entity Resolution, <code>SchemaMapping</code>, and <code>MatchingWorkflow</code>
         * can be tagged.</p><p><h3>See Also:</h3>   <a
         * href="http://docs.aws.amazon.com/goto/WebAPI/entityresolution-2018-05-10/UntagResource">AWS
         * API Reference</a></p>
         */
        virtual Model::UntagResourceOutcome UntagResource(const Model::UntagResourceRequest& request) const;

        /**
         * A Callable wrapper for UntagResource that returns a future to the operation so that it can be executed in parallel to other requests.
         */
        template<typename UntagResourceRequestT = Model::UntagResourceRequest>
        Model::UntagResourceOutcomeCallable UntagResourceCallable(const UntagResourceRequestT& request) const
        {
            return SubmitCallable(&EntityResolutionClient::UntagResource, request);
        }

        /**
         * An Async wrapper for UntagResource that queues the request into a thread executor and triggers associated callback when operation has finished.
         */
        template<typename UntagResourceRequestT = Model::UntagResourceRequest>
        void UntagResourceAsync(const UntagResourceRequestT& request, const UntagResourceResponseReceivedHandler& handler, const std::shared_ptr<const Aws::Client::AsyncCallerContext>& context = nullptr) const
        {
            return SubmitAsync(&EntityResolutionClient::UntagResource, request, handler, context);
        }

        /**
         * <p>Updates an existing <code>IdMappingWorkflow</code>. This method is identical
         * to CreateIdMappingWorkflow, except it uses an HTTP <code>PUT</code> request
         * instead of a <code>POST</code> request, and the <code>IdMappingWorkflow</code>
         * must already exist for the method to succeed.</p><p><h3>See Also:</h3>   <a
         * href="http://docs.aws.amazon.com/goto/WebAPI/entityresolution-2018-05-10/UpdateIdMappingWorkflow">AWS
         * API Reference</a></p>
         */
        virtual Model::UpdateIdMappingWorkflowOutcome UpdateIdMappingWorkflow(const Model::UpdateIdMappingWorkflowRequest& request) const;

        /**
         * A Callable wrapper for UpdateIdMappingWorkflow that returns a future to the operation so that it can be executed in parallel to other requests.
         */
        template<typename UpdateIdMappingWorkflowRequestT = Model::UpdateIdMappingWorkflowRequest>
        Model::UpdateIdMappingWorkflowOutcomeCallable UpdateIdMappingWorkflowCallable(const UpdateIdMappingWorkflowRequestT& request) const
        {
            return SubmitCallable(&EntityResolutionClient::UpdateIdMappingWorkflow, request);
        }

        /**
         * An Async wrapper for UpdateIdMappingWorkflow that queues the request into a thread executor and triggers associated callback when operation has finished.
         */
        template<typename UpdateIdMappingWorkflowRequestT = Model::UpdateIdMappingWorkflowRequest>
        void UpdateIdMappingWorkflowAsync(const UpdateIdMappingWorkflowRequestT& request, const UpdateIdMappingWorkflowResponseReceivedHandler& handler, const std::shared_ptr<const Aws::Client::AsyncCallerContext>& context = nullptr) const
        {
            return SubmitAsync(&EntityResolutionClient::UpdateIdMappingWorkflow, request, handler, context);
        }

        /**
         * <p>Updates an existing ID namespace.</p><p><h3>See Also:</h3>   <a
         * href="http://docs.aws.amazon.com/goto/WebAPI/entityresolution-2018-05-10/UpdateIdNamespace">AWS
         * API Reference</a></p>
         */
        virtual Model::UpdateIdNamespaceOutcome UpdateIdNamespace(const Model::UpdateIdNamespaceRequest& request) const;

        /**
         * A Callable wrapper for UpdateIdNamespace that returns a future to the operation so that it can be executed in parallel to other requests.
         */
        template<typename UpdateIdNamespaceRequestT = Model::UpdateIdNamespaceRequest>
        Model::UpdateIdNamespaceOutcomeCallable UpdateIdNamespaceCallable(const UpdateIdNamespaceRequestT& request) const
        {
            return SubmitCallable(&EntityResolutionClient::UpdateIdNamespace, request);
        }

        /**
         * An Async wrapper for UpdateIdNamespace that queues the request into a thread executor and triggers associated callback when operation has finished.
         */
        template<typename UpdateIdNamespaceRequestT = Model::UpdateIdNamespaceRequest>
        void UpdateIdNamespaceAsync(const UpdateIdNamespaceRequestT& request, const UpdateIdNamespaceResponseReceivedHandler& handler, const std::shared_ptr<const Aws::Client::AsyncCallerContext>& context = nullptr) const
        {
            return SubmitAsync(&EntityResolutionClient::UpdateIdNamespace, request, handler, context);
        }

        /**
         * <p>Updates an existing matching workflow. The workflow must already exist for
         * this operation to succeed.</p>  <p>For workflows where
         * <code>resolutionType</code> is ML_MATCHING, incremental processing is not
         * supported. </p> <p><h3>See Also:</h3>   <a
         * href="http://docs.aws.amazon.com/goto/WebAPI/entityresolution-2018-05-10/UpdateMatchingWorkflow">AWS
         * API Reference</a></p>
         */
        virtual Model::UpdateMatchingWorkflowOutcome UpdateMatchingWorkflow(const Model::UpdateMatchingWorkflowRequest& request) const;

        /**
         * A Callable wrapper for UpdateMatchingWorkflow that returns a future to the operation so that it can be executed in parallel to other requests.
         */
        template<typename UpdateMatchingWorkflowRequestT = Model::UpdateMatchingWorkflowRequest>
        Model::UpdateMatchingWorkflowOutcomeCallable UpdateMatchingWorkflowCallable(const UpdateMatchingWorkflowRequestT& request) const
        {
            return SubmitCallable(&EntityResolutionClient::UpdateMatchingWorkflow, request);
        }

        /**
         * An Async wrapper for UpdateMatchingWorkflow that queues the request into a thread executor and triggers associated callback when operation has finished.
         */
        template<typename UpdateMatchingWorkflowRequestT = Model::UpdateMatchingWorkflowRequest>
        void UpdateMatchingWorkflowAsync(const UpdateMatchingWorkflowRequestT& request, const UpdateMatchingWorkflowResponseReceivedHandler& handler, const std::shared_ptr<const Aws::Client::AsyncCallerContext>& context = nullptr) const
        {
            return SubmitAsync(&EntityResolutionClient::UpdateMatchingWorkflow, request, handler, context);
        }

        /**
         * <p>Updates a schema mapping.</p>  <p>A schema is immutable if it is being
         * used by a workflow. Therefore, you can't update a schema mapping if it's
         * associated with a workflow. </p> <p><h3>See Also:</h3>   <a
         * href="http://docs.aws.amazon.com/goto/WebAPI/entityresolution-2018-05-10/UpdateSchemaMapping">AWS
         * API Reference</a></p>
         */
        virtual Model::UpdateSchemaMappingOutcome UpdateSchemaMapping(const Model::UpdateSchemaMappingRequest& request) const;

        /**
         * A Callable wrapper for UpdateSchemaMapping that returns a future to the operation so that it can be executed in parallel to other requests.
         */
        template<typename UpdateSchemaMappingRequestT = Model::UpdateSchemaMappingRequest>
        Model::UpdateSchemaMappingOutcomeCallable UpdateSchemaMappingCallable(const UpdateSchemaMappingRequestT& request) const
        {
            return SubmitCallable(&EntityResolutionClient::UpdateSchemaMapping, request);
        }

        /**
         * An Async wrapper for UpdateSchemaMapping that queues the request into a thread executor and triggers associated callback when operation has finished.
         */
        template<typename UpdateSchemaMappingRequestT = Model::UpdateSchemaMappingRequest>
        void UpdateSchemaMappingAsync(const UpdateSchemaMappingRequestT& request, const UpdateSchemaMappingResponseReceivedHandler& handler, const std::shared_ptr<const Aws::Client::AsyncCallerContext>& context = nullptr) const
        {
            return SubmitAsync(&EntityResolutionClient::UpdateSchemaMapping, request, handler, context);
        }


      void OverrideEndpoint(const Aws::String& endpoint);
      std::shared_ptr<EntityResolutionEndpointProviderBase>& accessEndpointProvider();
    private:
      friend class Aws::Client::ClientWithAsyncTemplateMethods<EntityResolutionClient>;
      void init(const EntityResolutionClientConfiguration& clientConfiguration);

      EntityResolutionClientConfiguration m_clientConfiguration;
      std::shared_ptr<EntityResolutionEndpointProviderBase> m_endpointProvider;
  };

} // namespace EntityResolution
} // namespace Aws
