﻿/**
 * Copyright Amazon.com, Inc. or its affiliates. All Rights Reserved.
 * SPDX-License-Identifier: Apache-2.0.
 */

#pragma once
#include <aws/quicksight/QuickSight_EXPORTS.h>
#include <aws/core/utils/memory/stl/AWSString.h>
#include <aws/core/utils/memory/stl/AWSVector.h>
#include <aws/quicksight/model/AssetBundleExportJobFolderPropertyToOverride.h>
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
namespace QuickSight
{
namespace Model
{

  /**
   * <p>Controls how a specific <code>Folder</code> resource is parameterized in the
   * returned CloudFormation template.</p><p><h3>See Also:</h3>   <a
   * href="http://docs.aws.amazon.com/goto/WebAPI/quicksight-2018-04-01/AssetBundleExportJobFolderOverrideProperties">AWS
   * API Reference</a></p>
   */
  class AssetBundleExportJobFolderOverrideProperties
  {
  public:
    AWS_QUICKSIGHT_API AssetBundleExportJobFolderOverrideProperties();
    AWS_QUICKSIGHT_API AssetBundleExportJobFolderOverrideProperties(Aws::Utils::Json::JsonView jsonValue);
    AWS_QUICKSIGHT_API AssetBundleExportJobFolderOverrideProperties& operator=(Aws::Utils::Json::JsonView jsonValue);
    AWS_QUICKSIGHT_API Aws::Utils::Json::JsonValue Jsonize() const;


    ///@{
    /**
     * <p>The ARN of the specific <code>Folder</code> resource whose override
     * properties are configured in this structure.</p>
     */
    inline const Aws::String& GetArn() const{ return m_arn; }
    inline bool ArnHasBeenSet() const { return m_arnHasBeenSet; }
    inline void SetArn(const Aws::String& value) { m_arnHasBeenSet = true; m_arn = value; }
    inline void SetArn(Aws::String&& value) { m_arnHasBeenSet = true; m_arn = std::move(value); }
    inline void SetArn(const char* value) { m_arnHasBeenSet = true; m_arn.assign(value); }
    inline AssetBundleExportJobFolderOverrideProperties& WithArn(const Aws::String& value) { SetArn(value); return *this;}
    inline AssetBundleExportJobFolderOverrideProperties& WithArn(Aws::String&& value) { SetArn(std::move(value)); return *this;}
    inline AssetBundleExportJobFolderOverrideProperties& WithArn(const char* value) { SetArn(value); return *this;}
    ///@}

    ///@{
    /**
     * <p>A list of <code>Folder</code> resource properties to generate variables for
     * in the returned CloudFormation template.</p>
     */
    inline const Aws::Vector<AssetBundleExportJobFolderPropertyToOverride>& GetProperties() const{ return m_properties; }
    inline bool PropertiesHasBeenSet() const { return m_propertiesHasBeenSet; }
    inline void SetProperties(const Aws::Vector<AssetBundleExportJobFolderPropertyToOverride>& value) { m_propertiesHasBeenSet = true; m_properties = value; }
    inline void SetProperties(Aws::Vector<AssetBundleExportJobFolderPropertyToOverride>&& value) { m_propertiesHasBeenSet = true; m_properties = std::move(value); }
    inline AssetBundleExportJobFolderOverrideProperties& WithProperties(const Aws::Vector<AssetBundleExportJobFolderPropertyToOverride>& value) { SetProperties(value); return *this;}
    inline AssetBundleExportJobFolderOverrideProperties& WithProperties(Aws::Vector<AssetBundleExportJobFolderPropertyToOverride>&& value) { SetProperties(std::move(value)); return *this;}
    inline AssetBundleExportJobFolderOverrideProperties& AddProperties(const AssetBundleExportJobFolderPropertyToOverride& value) { m_propertiesHasBeenSet = true; m_properties.push_back(value); return *this; }
    inline AssetBundleExportJobFolderOverrideProperties& AddProperties(AssetBundleExportJobFolderPropertyToOverride&& value) { m_propertiesHasBeenSet = true; m_properties.push_back(std::move(value)); return *this; }
    ///@}
  private:

    Aws::String m_arn;
    bool m_arnHasBeenSet = false;

    Aws::Vector<AssetBundleExportJobFolderPropertyToOverride> m_properties;
    bool m_propertiesHasBeenSet = false;
  };

} // namespace Model
} // namespace QuickSight
} // namespace Aws
