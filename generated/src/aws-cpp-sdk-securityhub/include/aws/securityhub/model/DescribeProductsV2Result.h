﻿/**
 * Copyright Amazon.com, Inc. or its affiliates. All Rights Reserved.
 * SPDX-License-Identifier: Apache-2.0.
 */

#pragma once
#include <aws/securityhub/SecurityHub_EXPORTS.h>
#include <aws/core/utils/memory/stl/AWSVector.h>
#include <aws/core/utils/memory/stl/AWSString.h>
#include <aws/securityhub/model/ProductV2.h>
#include <utility>

namespace Aws
{
template<typename RESULT_TYPE>
class AmazonWebServiceResult;

namespace Utils
{
namespace Json
{
  class JsonValue;
} // namespace Json
} // namespace Utils
namespace SecurityHub
{
namespace Model
{
  class DescribeProductsV2Result
  {
  public:
    AWS_SECURITYHUB_API DescribeProductsV2Result() = default;
    AWS_SECURITYHUB_API DescribeProductsV2Result(const Aws::AmazonWebServiceResult<Aws::Utils::Json::JsonValue>& result);
    AWS_SECURITYHUB_API DescribeProductsV2Result& operator=(const Aws::AmazonWebServiceResult<Aws::Utils::Json::JsonValue>& result);


    ///@{
    /**
     * <p>Gets information about the product integration.</p>
     */
    inline const Aws::Vector<ProductV2>& GetProductsV2() const { return m_productsV2; }
    template<typename ProductsV2T = Aws::Vector<ProductV2>>
    void SetProductsV2(ProductsV2T&& value) { m_productsV2HasBeenSet = true; m_productsV2 = std::forward<ProductsV2T>(value); }
    template<typename ProductsV2T = Aws::Vector<ProductV2>>
    DescribeProductsV2Result& WithProductsV2(ProductsV2T&& value) { SetProductsV2(std::forward<ProductsV2T>(value)); return *this;}
    template<typename ProductsV2T = ProductV2>
    DescribeProductsV2Result& AddProductsV2(ProductsV2T&& value) { m_productsV2HasBeenSet = true; m_productsV2.emplace_back(std::forward<ProductsV2T>(value)); return *this; }
    ///@}

    ///@{
    /**
     * <p>The pagination token to use to request the next page of results. Otherwise,
     * this parameter is null.</p>
     */
    inline const Aws::String& GetNextToken() const { return m_nextToken; }
    template<typename NextTokenT = Aws::String>
    void SetNextToken(NextTokenT&& value) { m_nextTokenHasBeenSet = true; m_nextToken = std::forward<NextTokenT>(value); }
    template<typename NextTokenT = Aws::String>
    DescribeProductsV2Result& WithNextToken(NextTokenT&& value) { SetNextToken(std::forward<NextTokenT>(value)); return *this;}
    ///@}

    ///@{
    
    inline const Aws::String& GetRequestId() const { return m_requestId; }
    template<typename RequestIdT = Aws::String>
    void SetRequestId(RequestIdT&& value) { m_requestIdHasBeenSet = true; m_requestId = std::forward<RequestIdT>(value); }
    template<typename RequestIdT = Aws::String>
    DescribeProductsV2Result& WithRequestId(RequestIdT&& value) { SetRequestId(std::forward<RequestIdT>(value)); return *this;}
    ///@}
  private:

    Aws::Vector<ProductV2> m_productsV2;
    bool m_productsV2HasBeenSet = false;

    Aws::String m_nextToken;
    bool m_nextTokenHasBeenSet = false;

    Aws::String m_requestId;
    bool m_requestIdHasBeenSet = false;
  };

} // namespace Model
} // namespace SecurityHub
} // namespace Aws
