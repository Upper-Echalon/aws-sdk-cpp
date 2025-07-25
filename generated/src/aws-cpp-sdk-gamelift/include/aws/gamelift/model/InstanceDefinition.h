﻿/**
 * Copyright Amazon.com, Inc. or its affiliates. All Rights Reserved.
 * SPDX-License-Identifier: Apache-2.0.
 */

#pragma once
#include <aws/gamelift/GameLift_EXPORTS.h>
#include <aws/gamelift/model/GameServerGroupInstanceType.h>
#include <aws/core/utils/memory/stl/AWSString.h>
#include <utility>

namespace Aws
{
namespace Utils
{
namespace Json
{
  class JsonValue;
  class JsonView;
} // namespace Json
} // namespace Utils
namespace GameLift
{
namespace Model
{

  /**
   * <p> <b>This data type is used with the Amazon GameLift Servers FleetIQ and game
   * server groups.</b> </p> <p>An allowed instance type for a game server group. All
   * game server groups must have at least two instance types defined for it. Amazon
   * GameLift Servers FleetIQ periodically evaluates each defined instance type for
   * viability. It then updates the Auto Scaling group with the list of viable
   * instance types.</p><p><h3>See Also:</h3>   <a
   * href="http://docs.aws.amazon.com/goto/WebAPI/gamelift-2015-10-01/InstanceDefinition">AWS
   * API Reference</a></p>
   */
  class InstanceDefinition
  {
  public:
    AWS_GAMELIFT_API InstanceDefinition() = default;
    AWS_GAMELIFT_API InstanceDefinition(Aws::Utils::Json::JsonView jsonValue);
    AWS_GAMELIFT_API InstanceDefinition& operator=(Aws::Utils::Json::JsonView jsonValue);
    AWS_GAMELIFT_API Aws::Utils::Json::JsonValue Jsonize() const;


    ///@{
    /**
     * <p>An Amazon EC2 instance type designation.</p>
     */
    inline GameServerGroupInstanceType GetInstanceType() const { return m_instanceType; }
    inline bool InstanceTypeHasBeenSet() const { return m_instanceTypeHasBeenSet; }
    inline void SetInstanceType(GameServerGroupInstanceType value) { m_instanceTypeHasBeenSet = true; m_instanceType = value; }
    inline InstanceDefinition& WithInstanceType(GameServerGroupInstanceType value) { SetInstanceType(value); return *this;}
    ///@}

    ///@{
    /**
     * <p>Instance weighting that indicates how much this instance type contributes to
     * the total capacity of a game server group. Instance weights are used by Amazon
     * GameLift Servers FleetIQ to calculate the instance type's cost per unit hour and
     * better identify the most cost-effective options. For detailed information on
     * weighting instance capacity, see <a
     * href="https://docs.aws.amazon.com/autoscaling/ec2/userguide/asg-instance-weighting.html">Instance
     * Weighting</a> in the <i>Amazon Elastic Compute Cloud Auto Scaling User
     * Guide</i>. Default value is "1".</p>
     */
    inline const Aws::String& GetWeightedCapacity() const { return m_weightedCapacity; }
    inline bool WeightedCapacityHasBeenSet() const { return m_weightedCapacityHasBeenSet; }
    template<typename WeightedCapacityT = Aws::String>
    void SetWeightedCapacity(WeightedCapacityT&& value) { m_weightedCapacityHasBeenSet = true; m_weightedCapacity = std::forward<WeightedCapacityT>(value); }
    template<typename WeightedCapacityT = Aws::String>
    InstanceDefinition& WithWeightedCapacity(WeightedCapacityT&& value) { SetWeightedCapacity(std::forward<WeightedCapacityT>(value)); return *this;}
    ///@}
  private:

    GameServerGroupInstanceType m_instanceType{GameServerGroupInstanceType::NOT_SET};
    bool m_instanceTypeHasBeenSet = false;

    Aws::String m_weightedCapacity;
    bool m_weightedCapacityHasBeenSet = false;
  };

} // namespace Model
} // namespace GameLift
} // namespace Aws
