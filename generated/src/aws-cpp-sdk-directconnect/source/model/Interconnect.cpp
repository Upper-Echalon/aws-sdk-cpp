﻿/**
 * Copyright Amazon.com, Inc. or its affiliates. All Rights Reserved.
 * SPDX-License-Identifier: Apache-2.0.
 */

#include <aws/directconnect/model/Interconnect.h>
#include <aws/core/utils/json/JsonSerializer.h>
#include <aws/core/utils/memory/stl/AWSStringStream.h>

#include <utility>

using namespace Aws::Utils::Json;
using namespace Aws::Utils;

namespace Aws
{
namespace DirectConnect
{
namespace Model
{

Interconnect::Interconnect(JsonView jsonValue)
{
  *this = jsonValue;
}

Interconnect& Interconnect::operator =(JsonView jsonValue)
{
  if(jsonValue.ValueExists("interconnectId"))
  {
    m_interconnectId = jsonValue.GetString("interconnectId");
    m_interconnectIdHasBeenSet = true;
  }
  if(jsonValue.ValueExists("interconnectName"))
  {
    m_interconnectName = jsonValue.GetString("interconnectName");
    m_interconnectNameHasBeenSet = true;
  }
  if(jsonValue.ValueExists("interconnectState"))
  {
    m_interconnectState = InterconnectStateMapper::GetInterconnectStateForName(jsonValue.GetString("interconnectState"));
    m_interconnectStateHasBeenSet = true;
  }
  if(jsonValue.ValueExists("region"))
  {
    m_region = jsonValue.GetString("region");
    m_regionHasBeenSet = true;
  }
  if(jsonValue.ValueExists("location"))
  {
    m_location = jsonValue.GetString("location");
    m_locationHasBeenSet = true;
  }
  if(jsonValue.ValueExists("bandwidth"))
  {
    m_bandwidth = jsonValue.GetString("bandwidth");
    m_bandwidthHasBeenSet = true;
  }
  if(jsonValue.ValueExists("loaIssueTime"))
  {
    m_loaIssueTime = jsonValue.GetDouble("loaIssueTime");
    m_loaIssueTimeHasBeenSet = true;
  }
  if(jsonValue.ValueExists("lagId"))
  {
    m_lagId = jsonValue.GetString("lagId");
    m_lagIdHasBeenSet = true;
  }
  if(jsonValue.ValueExists("awsDevice"))
  {
    m_awsDevice = jsonValue.GetString("awsDevice");
    m_awsDeviceHasBeenSet = true;
  }
  if(jsonValue.ValueExists("jumboFrameCapable"))
  {
    m_jumboFrameCapable = jsonValue.GetBool("jumboFrameCapable");
    m_jumboFrameCapableHasBeenSet = true;
  }
  if(jsonValue.ValueExists("awsDeviceV2"))
  {
    m_awsDeviceV2 = jsonValue.GetString("awsDeviceV2");
    m_awsDeviceV2HasBeenSet = true;
  }
  if(jsonValue.ValueExists("awsLogicalDeviceId"))
  {
    m_awsLogicalDeviceId = jsonValue.GetString("awsLogicalDeviceId");
    m_awsLogicalDeviceIdHasBeenSet = true;
  }
  if(jsonValue.ValueExists("hasLogicalRedundancy"))
  {
    m_hasLogicalRedundancy = HasLogicalRedundancyMapper::GetHasLogicalRedundancyForName(jsonValue.GetString("hasLogicalRedundancy"));
    m_hasLogicalRedundancyHasBeenSet = true;
  }
  if(jsonValue.ValueExists("tags"))
  {
    Aws::Utils::Array<JsonView> tagsJsonList = jsonValue.GetArray("tags");
    for(unsigned tagsIndex = 0; tagsIndex < tagsJsonList.GetLength(); ++tagsIndex)
    {
      m_tags.push_back(tagsJsonList[tagsIndex].AsObject());
    }
    m_tagsHasBeenSet = true;
  }
  if(jsonValue.ValueExists("providerName"))
  {
    m_providerName = jsonValue.GetString("providerName");
    m_providerNameHasBeenSet = true;
  }
  if(jsonValue.ValueExists("macSecCapable"))
  {
    m_macSecCapable = jsonValue.GetBool("macSecCapable");
    m_macSecCapableHasBeenSet = true;
  }
  if(jsonValue.ValueExists("portEncryptionStatus"))
  {
    m_portEncryptionStatus = jsonValue.GetString("portEncryptionStatus");
    m_portEncryptionStatusHasBeenSet = true;
  }
  if(jsonValue.ValueExists("encryptionMode"))
  {
    m_encryptionMode = jsonValue.GetString("encryptionMode");
    m_encryptionModeHasBeenSet = true;
  }
  if(jsonValue.ValueExists("macSecKeys"))
  {
    Aws::Utils::Array<JsonView> macSecKeysJsonList = jsonValue.GetArray("macSecKeys");
    for(unsigned macSecKeysIndex = 0; macSecKeysIndex < macSecKeysJsonList.GetLength(); ++macSecKeysIndex)
    {
      m_macSecKeys.push_back(macSecKeysJsonList[macSecKeysIndex].AsObject());
    }
    m_macSecKeysHasBeenSet = true;
  }
  return *this;
}

JsonValue Interconnect::Jsonize() const
{
  JsonValue payload;

  if(m_interconnectIdHasBeenSet)
  {
   payload.WithString("interconnectId", m_interconnectId);

  }

  if(m_interconnectNameHasBeenSet)
  {
   payload.WithString("interconnectName", m_interconnectName);

  }

  if(m_interconnectStateHasBeenSet)
  {
   payload.WithString("interconnectState", InterconnectStateMapper::GetNameForInterconnectState(m_interconnectState));
  }

  if(m_regionHasBeenSet)
  {
   payload.WithString("region", m_region);

  }

  if(m_locationHasBeenSet)
  {
   payload.WithString("location", m_location);

  }

  if(m_bandwidthHasBeenSet)
  {
   payload.WithString("bandwidth", m_bandwidth);

  }

  if(m_loaIssueTimeHasBeenSet)
  {
   payload.WithDouble("loaIssueTime", m_loaIssueTime.SecondsWithMSPrecision());
  }

  if(m_lagIdHasBeenSet)
  {
   payload.WithString("lagId", m_lagId);

  }

  if(m_awsDeviceHasBeenSet)
  {
   payload.WithString("awsDevice", m_awsDevice);

  }

  if(m_jumboFrameCapableHasBeenSet)
  {
   payload.WithBool("jumboFrameCapable", m_jumboFrameCapable);

  }

  if(m_awsDeviceV2HasBeenSet)
  {
   payload.WithString("awsDeviceV2", m_awsDeviceV2);

  }

  if(m_awsLogicalDeviceIdHasBeenSet)
  {
   payload.WithString("awsLogicalDeviceId", m_awsLogicalDeviceId);

  }

  if(m_hasLogicalRedundancyHasBeenSet)
  {
   payload.WithString("hasLogicalRedundancy", HasLogicalRedundancyMapper::GetNameForHasLogicalRedundancy(m_hasLogicalRedundancy));
  }

  if(m_tagsHasBeenSet)
  {
   Aws::Utils::Array<JsonValue> tagsJsonList(m_tags.size());
   for(unsigned tagsIndex = 0; tagsIndex < tagsJsonList.GetLength(); ++tagsIndex)
   {
     tagsJsonList[tagsIndex].AsObject(m_tags[tagsIndex].Jsonize());
   }
   payload.WithArray("tags", std::move(tagsJsonList));

  }

  if(m_providerNameHasBeenSet)
  {
   payload.WithString("providerName", m_providerName);

  }

  if(m_macSecCapableHasBeenSet)
  {
   payload.WithBool("macSecCapable", m_macSecCapable);

  }

  if(m_portEncryptionStatusHasBeenSet)
  {
   payload.WithString("portEncryptionStatus", m_portEncryptionStatus);

  }

  if(m_encryptionModeHasBeenSet)
  {
   payload.WithString("encryptionMode", m_encryptionMode);

  }

  if(m_macSecKeysHasBeenSet)
  {
   Aws::Utils::Array<JsonValue> macSecKeysJsonList(m_macSecKeys.size());
   for(unsigned macSecKeysIndex = 0; macSecKeysIndex < macSecKeysJsonList.GetLength(); ++macSecKeysIndex)
   {
     macSecKeysJsonList[macSecKeysIndex].AsObject(m_macSecKeys[macSecKeysIndex].Jsonize());
   }
   payload.WithArray("macSecKeys", std::move(macSecKeysJsonList));

  }

  return payload;
}

} // namespace Model
} // namespace DirectConnect
} // namespace Aws
