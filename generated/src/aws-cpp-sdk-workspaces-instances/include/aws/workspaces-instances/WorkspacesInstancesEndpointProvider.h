﻿/**
 * Copyright Amazon.com, Inc. or its affiliates. All Rights Reserved.
 * SPDX-License-Identifier: Apache-2.0.
 */

#pragma once
#include <aws/workspaces-instances/WorkspacesInstances_EXPORTS.h>
#include <aws/core/client/GenericClientConfiguration.h>
#include <aws/core/endpoint/DefaultEndpointProvider.h>
#include <aws/core/endpoint/EndpointParameter.h>
#include <aws/core/utils/memory/stl/AWSString.h>
#include <aws/core/utils/memory/stl/AWSVector.h>

#include <aws/workspaces-instances/WorkspacesInstancesEndpointRules.h>


namespace Aws
{
namespace WorkspacesInstances
{
namespace Endpoint
{
using EndpointParameters = Aws::Endpoint::EndpointParameters;
using Aws::Endpoint::EndpointProviderBase;
using Aws::Endpoint::DefaultEndpointProvider;

using WorkspacesInstancesClientContextParameters = Aws::Endpoint::ClientContextParameters;

using WorkspacesInstancesClientConfiguration = Aws::Client::GenericClientConfiguration;
using WorkspacesInstancesBuiltInParameters = Aws::Endpoint::BuiltInParameters;

/**
 * The type for the WorkspacesInstances Client Endpoint Provider.
 * Inherit from this Base class / "Interface" should you want to provide a custom endpoint provider.
 * The SDK must use service-specific type for each service per specification.
 */
using WorkspacesInstancesEndpointProviderBase =
    EndpointProviderBase<WorkspacesInstancesClientConfiguration, WorkspacesInstancesBuiltInParameters, WorkspacesInstancesClientContextParameters>;

using WorkspacesInstancesDefaultEpProviderBase =
    DefaultEndpointProvider<WorkspacesInstancesClientConfiguration, WorkspacesInstancesBuiltInParameters, WorkspacesInstancesClientContextParameters>;

/**
 * Default endpoint provider used for this service
 */
class AWS_WORKSPACESINSTANCES_API WorkspacesInstancesEndpointProvider : public WorkspacesInstancesDefaultEpProviderBase
{
public:
    using WorkspacesInstancesResolveEndpointOutcome = Aws::Endpoint::ResolveEndpointOutcome;

    WorkspacesInstancesEndpointProvider()
      : WorkspacesInstancesDefaultEpProviderBase(Aws::WorkspacesInstances::WorkspacesInstancesEndpointRules::GetRulesBlob(), Aws::WorkspacesInstances::WorkspacesInstancesEndpointRules::RulesBlobSize)
    {}

    ~WorkspacesInstancesEndpointProvider()
    {
    }
};
} // namespace Endpoint
} // namespace WorkspacesInstances
} // namespace Aws
