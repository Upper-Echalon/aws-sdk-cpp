﻿/**
 * Copyright Amazon.com, Inc. or its affiliates. All Rights Reserved.
 * SPDX-License-Identifier: Apache-2.0.
 */

#pragma once
#include <aws/docdb/DocDB_EXPORTS.h>
#include <aws/docdb/model/GlobalCluster.h>
#include <aws/docdb/model/ResponseMetadata.h>
#include <utility>

namespace Aws
{
template<typename RESULT_TYPE>
class AmazonWebServiceResult;

namespace Utils
{
namespace Xml
{
  class XmlDocument;
} // namespace Xml
} // namespace Utils
namespace DocDB
{
namespace Model
{
  class FailoverGlobalClusterResult
  {
  public:
    AWS_DOCDB_API FailoverGlobalClusterResult();
    AWS_DOCDB_API FailoverGlobalClusterResult(const Aws::AmazonWebServiceResult<Aws::Utils::Xml::XmlDocument>& result);
    AWS_DOCDB_API FailoverGlobalClusterResult& operator=(const Aws::AmazonWebServiceResult<Aws::Utils::Xml::XmlDocument>& result);


    ///@{
    
    inline const GlobalCluster& GetGlobalCluster() const{ return m_globalCluster; }
    inline void SetGlobalCluster(const GlobalCluster& value) { m_globalCluster = value; }
    inline void SetGlobalCluster(GlobalCluster&& value) { m_globalCluster = std::move(value); }
    inline FailoverGlobalClusterResult& WithGlobalCluster(const GlobalCluster& value) { SetGlobalCluster(value); return *this;}
    inline FailoverGlobalClusterResult& WithGlobalCluster(GlobalCluster&& value) { SetGlobalCluster(std::move(value)); return *this;}
    ///@}

    ///@{
    
    inline const ResponseMetadata& GetResponseMetadata() const{ return m_responseMetadata; }
    inline void SetResponseMetadata(const ResponseMetadata& value) { m_responseMetadata = value; }
    inline void SetResponseMetadata(ResponseMetadata&& value) { m_responseMetadata = std::move(value); }
    inline FailoverGlobalClusterResult& WithResponseMetadata(const ResponseMetadata& value) { SetResponseMetadata(value); return *this;}
    inline FailoverGlobalClusterResult& WithResponseMetadata(ResponseMetadata&& value) { SetResponseMetadata(std::move(value)); return *this;}
    ///@}
  private:

    GlobalCluster m_globalCluster;

    ResponseMetadata m_responseMetadata;
  };

} // namespace Model
} // namespace DocDB
} // namespace Aws
