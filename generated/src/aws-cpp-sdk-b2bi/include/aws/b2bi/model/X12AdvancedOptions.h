﻿/**
 * Copyright Amazon.com, Inc. or its affiliates. All Rights Reserved.
 * SPDX-License-Identifier: Apache-2.0.
 */

#pragma once
#include <aws/b2bi/B2BI_EXPORTS.h>
#include <aws/b2bi/model/X12SplitOptions.h>
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
namespace B2BI
{
namespace Model
{

  /**
   * <p>Contains advanced options specific to X12 EDI processing, such as splitting
   * large X12 files into smaller units.</p><p><h3>See Also:</h3>   <a
   * href="http://docs.aws.amazon.com/goto/WebAPI/b2bi-2022-06-23/X12AdvancedOptions">AWS
   * API Reference</a></p>
   */
  class X12AdvancedOptions
  {
  public:
    AWS_B2BI_API X12AdvancedOptions() = default;
    AWS_B2BI_API X12AdvancedOptions(Aws::Utils::Json::JsonView jsonValue);
    AWS_B2BI_API X12AdvancedOptions& operator=(Aws::Utils::Json::JsonView jsonValue);
    AWS_B2BI_API Aws::Utils::Json::JsonValue Jsonize() const;


    ///@{
    /**
     * <p>Specifies options for splitting X12 EDI files. These options control how
     * large X12 files are divided into smaller, more manageable units.</p>
     */
    inline const X12SplitOptions& GetSplitOptions() const { return m_splitOptions; }
    inline bool SplitOptionsHasBeenSet() const { return m_splitOptionsHasBeenSet; }
    template<typename SplitOptionsT = X12SplitOptions>
    void SetSplitOptions(SplitOptionsT&& value) { m_splitOptionsHasBeenSet = true; m_splitOptions = std::forward<SplitOptionsT>(value); }
    template<typename SplitOptionsT = X12SplitOptions>
    X12AdvancedOptions& WithSplitOptions(SplitOptionsT&& value) { SetSplitOptions(std::forward<SplitOptionsT>(value)); return *this;}
    ///@}
  private:

    X12SplitOptions m_splitOptions;
    bool m_splitOptionsHasBeenSet = false;
  };

} // namespace Model
} // namespace B2BI
} // namespace Aws
