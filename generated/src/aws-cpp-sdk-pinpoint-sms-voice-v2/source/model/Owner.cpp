﻿/**
 * Copyright Amazon.com, Inc. or its affiliates. All Rights Reserved.
 * SPDX-License-Identifier: Apache-2.0.
 */

#include <aws/pinpoint-sms-voice-v2/model/Owner.h>
#include <aws/core/utils/HashingUtils.h>
#include <aws/core/Globals.h>
#include <aws/core/utils/EnumParseOverflowContainer.h>

using namespace Aws::Utils;


namespace Aws
{
  namespace PinpointSMSVoiceV2
  {
    namespace Model
    {
      namespace OwnerMapper
      {

        static const int SELF_HASH = HashingUtils::HashString("SELF");
        static const int SHARED_HASH = HashingUtils::HashString("SHARED");


        Owner GetOwnerForName(const Aws::String& name)
        {
          int hashCode = HashingUtils::HashString(name.c_str());
          if (hashCode == SELF_HASH)
          {
            return Owner::SELF;
          }
          else if (hashCode == SHARED_HASH)
          {
            return Owner::SHARED;
          }
          EnumParseOverflowContainer* overflowContainer = Aws::GetEnumOverflowContainer();
          if(overflowContainer)
          {
            overflowContainer->StoreOverflow(hashCode, name);
            return static_cast<Owner>(hashCode);
          }

          return Owner::NOT_SET;
        }

        Aws::String GetNameForOwner(Owner enumValue)
        {
          switch(enumValue)
          {
          case Owner::NOT_SET:
            return {};
          case Owner::SELF:
            return "SELF";
          case Owner::SHARED:
            return "SHARED";
          default:
            EnumParseOverflowContainer* overflowContainer = Aws::GetEnumOverflowContainer();
            if(overflowContainer)
            {
              return overflowContainer->RetrieveOverflow(static_cast<int>(enumValue));
            }

            return {};
          }
        }

      } // namespace OwnerMapper
    } // namespace Model
  } // namespace PinpointSMSVoiceV2
} // namespace Aws
