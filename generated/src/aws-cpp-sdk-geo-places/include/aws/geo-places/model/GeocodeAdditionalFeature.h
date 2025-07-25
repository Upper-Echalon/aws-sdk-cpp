﻿/**
 * Copyright Amazon.com, Inc. or its affiliates. All Rights Reserved.
 * SPDX-License-Identifier: Apache-2.0.
 */

#pragma once
#include <aws/geo-places/GeoPlaces_EXPORTS.h>
#include <aws/core/utils/memory/stl/AWSString.h>

namespace Aws
{
namespace GeoPlaces
{
namespace Model
{
  enum class GeocodeAdditionalFeature
  {
    NOT_SET,
    TimeZone,
    Access,
    SecondaryAddresses,
    Intersections
  };

namespace GeocodeAdditionalFeatureMapper
{
AWS_GEOPLACES_API GeocodeAdditionalFeature GetGeocodeAdditionalFeatureForName(const Aws::String& name);

AWS_GEOPLACES_API Aws::String GetNameForGeocodeAdditionalFeature(GeocodeAdditionalFeature value);
} // namespace GeocodeAdditionalFeatureMapper
} // namespace Model
} // namespace GeoPlaces
} // namespace Aws
