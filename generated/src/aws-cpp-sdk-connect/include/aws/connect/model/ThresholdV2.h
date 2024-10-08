﻿/**
 * Copyright Amazon.com, Inc. or its affiliates. All Rights Reserved.
 * SPDX-License-Identifier: Apache-2.0.
 */

#pragma once
#include <aws/connect/Connect_EXPORTS.h>
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
namespace Connect
{
namespace Model
{

  /**
   * <p>Contains information about the threshold for service level
   * metrics.</p><p><h3>See Also:</h3>   <a
   * href="http://docs.aws.amazon.com/goto/WebAPI/connect-2017-08-08/ThresholdV2">AWS
   * API Reference</a></p>
   */
  class ThresholdV2
  {
  public:
    AWS_CONNECT_API ThresholdV2();
    AWS_CONNECT_API ThresholdV2(Aws::Utils::Json::JsonView jsonValue);
    AWS_CONNECT_API ThresholdV2& operator=(Aws::Utils::Json::JsonView jsonValue);
    AWS_CONNECT_API Aws::Utils::Json::JsonValue Jsonize() const;


    ///@{
    /**
     * <p>The type of comparison. Currently, "less than" (LT), "less than equal" (LTE),
     * and "greater than" (GT) comparisons are supported.</p>
     */
    inline const Aws::String& GetComparison() const{ return m_comparison; }
    inline bool ComparisonHasBeenSet() const { return m_comparisonHasBeenSet; }
    inline void SetComparison(const Aws::String& value) { m_comparisonHasBeenSet = true; m_comparison = value; }
    inline void SetComparison(Aws::String&& value) { m_comparisonHasBeenSet = true; m_comparison = std::move(value); }
    inline void SetComparison(const char* value) { m_comparisonHasBeenSet = true; m_comparison.assign(value); }
    inline ThresholdV2& WithComparison(const Aws::String& value) { SetComparison(value); return *this;}
    inline ThresholdV2& WithComparison(Aws::String&& value) { SetComparison(std::move(value)); return *this;}
    inline ThresholdV2& WithComparison(const char* value) { SetComparison(value); return *this;}
    ///@}

    ///@{
    /**
     * <p>The threshold value to compare.</p>
     */
    inline double GetThresholdValue() const{ return m_thresholdValue; }
    inline bool ThresholdValueHasBeenSet() const { return m_thresholdValueHasBeenSet; }
    inline void SetThresholdValue(double value) { m_thresholdValueHasBeenSet = true; m_thresholdValue = value; }
    inline ThresholdV2& WithThresholdValue(double value) { SetThresholdValue(value); return *this;}
    ///@}
  private:

    Aws::String m_comparison;
    bool m_comparisonHasBeenSet = false;

    double m_thresholdValue;
    bool m_thresholdValueHasBeenSet = false;
  };

} // namespace Model
} // namespace Connect
} // namespace Aws
