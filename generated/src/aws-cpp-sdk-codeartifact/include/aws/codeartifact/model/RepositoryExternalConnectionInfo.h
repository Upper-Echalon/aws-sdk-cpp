﻿/**
 * Copyright Amazon.com, Inc. or its affiliates. All Rights Reserved.
 * SPDX-License-Identifier: Apache-2.0.
 */

#pragma once
#include <aws/codeartifact/CodeArtifact_EXPORTS.h>
#include <aws/core/utils/memory/stl/AWSString.h>
#include <aws/codeartifact/model/PackageFormat.h>
#include <aws/codeartifact/model/ExternalConnectionStatus.h>
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
namespace CodeArtifact
{
namespace Model
{

  /**
   * <p> Contains information about the external connection of a repository.
   * </p><p><h3>See Also:</h3>   <a
   * href="http://docs.aws.amazon.com/goto/WebAPI/codeartifact-2018-09-22/RepositoryExternalConnectionInfo">AWS
   * API Reference</a></p>
   */
  class RepositoryExternalConnectionInfo
  {
  public:
    AWS_CODEARTIFACT_API RepositoryExternalConnectionInfo();
    AWS_CODEARTIFACT_API RepositoryExternalConnectionInfo(Aws::Utils::Json::JsonView jsonValue);
    AWS_CODEARTIFACT_API RepositoryExternalConnectionInfo& operator=(Aws::Utils::Json::JsonView jsonValue);
    AWS_CODEARTIFACT_API Aws::Utils::Json::JsonValue Jsonize() const;


    ///@{
    /**
     * <p> The name of the external connection associated with a repository. </p>
     */
    inline const Aws::String& GetExternalConnectionName() const{ return m_externalConnectionName; }
    inline bool ExternalConnectionNameHasBeenSet() const { return m_externalConnectionNameHasBeenSet; }
    inline void SetExternalConnectionName(const Aws::String& value) { m_externalConnectionNameHasBeenSet = true; m_externalConnectionName = value; }
    inline void SetExternalConnectionName(Aws::String&& value) { m_externalConnectionNameHasBeenSet = true; m_externalConnectionName = std::move(value); }
    inline void SetExternalConnectionName(const char* value) { m_externalConnectionNameHasBeenSet = true; m_externalConnectionName.assign(value); }
    inline RepositoryExternalConnectionInfo& WithExternalConnectionName(const Aws::String& value) { SetExternalConnectionName(value); return *this;}
    inline RepositoryExternalConnectionInfo& WithExternalConnectionName(Aws::String&& value) { SetExternalConnectionName(std::move(value)); return *this;}
    inline RepositoryExternalConnectionInfo& WithExternalConnectionName(const char* value) { SetExternalConnectionName(value); return *this;}
    ///@}

    ///@{
    /**
     * <p> The package format associated with a repository's external connection. The
     * valid package formats are: </p> <ul> <li> <p> <code>npm</code>: A Node Package
     * Manager (npm) package. </p> </li> <li> <p> <code>pypi</code>: A Python Package
     * Index (PyPI) package. </p> </li> <li> <p> <code>maven</code>: A Maven package
     * that contains compiled code in a distributable format, such as a JAR file. </p>
     * </li> <li> <p> <code>nuget</code>: A NuGet package. </p> </li> <li> <p>
     * <code>generic</code>: A generic package. </p> </li> <li> <p> <code>ruby</code>:
     * A Ruby package. </p> </li> <li> <p> <code>swift</code>: A Swift package. </p>
     * </li> <li> <p> <code>cargo</code>: A Cargo package. </p> </li> </ul>
     */
    inline const PackageFormat& GetPackageFormat() const{ return m_packageFormat; }
    inline bool PackageFormatHasBeenSet() const { return m_packageFormatHasBeenSet; }
    inline void SetPackageFormat(const PackageFormat& value) { m_packageFormatHasBeenSet = true; m_packageFormat = value; }
    inline void SetPackageFormat(PackageFormat&& value) { m_packageFormatHasBeenSet = true; m_packageFormat = std::move(value); }
    inline RepositoryExternalConnectionInfo& WithPackageFormat(const PackageFormat& value) { SetPackageFormat(value); return *this;}
    inline RepositoryExternalConnectionInfo& WithPackageFormat(PackageFormat&& value) { SetPackageFormat(std::move(value)); return *this;}
    ///@}

    ///@{
    /**
     * <p> The status of the external connection of a repository. There is one valid
     * value, <code>Available</code>. </p>
     */
    inline const ExternalConnectionStatus& GetStatus() const{ return m_status; }
    inline bool StatusHasBeenSet() const { return m_statusHasBeenSet; }
    inline void SetStatus(const ExternalConnectionStatus& value) { m_statusHasBeenSet = true; m_status = value; }
    inline void SetStatus(ExternalConnectionStatus&& value) { m_statusHasBeenSet = true; m_status = std::move(value); }
    inline RepositoryExternalConnectionInfo& WithStatus(const ExternalConnectionStatus& value) { SetStatus(value); return *this;}
    inline RepositoryExternalConnectionInfo& WithStatus(ExternalConnectionStatus&& value) { SetStatus(std::move(value)); return *this;}
    ///@}
  private:

    Aws::String m_externalConnectionName;
    bool m_externalConnectionNameHasBeenSet = false;

    PackageFormat m_packageFormat;
    bool m_packageFormatHasBeenSet = false;

    ExternalConnectionStatus m_status;
    bool m_statusHasBeenSet = false;
  };

} // namespace Model
} // namespace CodeArtifact
} // namespace Aws
