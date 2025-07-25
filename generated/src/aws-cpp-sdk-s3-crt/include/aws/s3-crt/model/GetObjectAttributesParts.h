﻿/**
 * Copyright Amazon.com, Inc. or its affiliates. All Rights Reserved.
 * SPDX-License-Identifier: Apache-2.0.
 */

#pragma once
#include <aws/s3-crt/S3Crt_EXPORTS.h>
#include <aws/core/utils/memory/stl/AWSVector.h>
#include <aws/s3-crt/model/ObjectPart.h>
#include <utility>

namespace Aws
{
namespace Utils
{
namespace Xml
{
  class XmlNode;
} // namespace Xml
} // namespace Utils
namespace S3Crt
{
namespace Model
{

  /**
   * <p>A collection of parts associated with a multipart upload.</p><p><h3>See
   * Also:</h3>   <a
   * href="http://docs.aws.amazon.com/goto/WebAPI/s3-2006-03-01/GetObjectAttributesParts">AWS
   * API Reference</a></p>
   */
  class GetObjectAttributesParts
  {
  public:
    AWS_S3CRT_API GetObjectAttributesParts() = default;
    AWS_S3CRT_API GetObjectAttributesParts(const Aws::Utils::Xml::XmlNode& xmlNode);
    AWS_S3CRT_API GetObjectAttributesParts& operator=(const Aws::Utils::Xml::XmlNode& xmlNode);

    AWS_S3CRT_API void AddToNode(Aws::Utils::Xml::XmlNode& parentNode) const;


    ///@{
    /**
     * <p>The total number of parts.</p>
     */
    inline int GetTotalPartsCount() const { return m_totalPartsCount; }
    inline bool TotalPartsCountHasBeenSet() const { return m_totalPartsCountHasBeenSet; }
    inline void SetTotalPartsCount(int value) { m_totalPartsCountHasBeenSet = true; m_totalPartsCount = value; }
    inline GetObjectAttributesParts& WithTotalPartsCount(int value) { SetTotalPartsCount(value); return *this;}
    ///@}

    ///@{
    /**
     * <p>The marker for the current part.</p>
     */
    inline int GetPartNumberMarker() const { return m_partNumberMarker; }
    inline bool PartNumberMarkerHasBeenSet() const { return m_partNumberMarkerHasBeenSet; }
    inline void SetPartNumberMarker(int value) { m_partNumberMarkerHasBeenSet = true; m_partNumberMarker = value; }
    inline GetObjectAttributesParts& WithPartNumberMarker(int value) { SetPartNumberMarker(value); return *this;}
    ///@}

    ///@{
    /**
     * <p>When a list is truncated, this element specifies the last part in the list,
     * as well as the value to use for the <code>PartNumberMarker</code> request
     * parameter in a subsequent request.</p>
     */
    inline int GetNextPartNumberMarker() const { return m_nextPartNumberMarker; }
    inline bool NextPartNumberMarkerHasBeenSet() const { return m_nextPartNumberMarkerHasBeenSet; }
    inline void SetNextPartNumberMarker(int value) { m_nextPartNumberMarkerHasBeenSet = true; m_nextPartNumberMarker = value; }
    inline GetObjectAttributesParts& WithNextPartNumberMarker(int value) { SetNextPartNumberMarker(value); return *this;}
    ///@}

    ///@{
    /**
     * <p>The maximum number of parts allowed in the response.</p>
     */
    inline int GetMaxParts() const { return m_maxParts; }
    inline bool MaxPartsHasBeenSet() const { return m_maxPartsHasBeenSet; }
    inline void SetMaxParts(int value) { m_maxPartsHasBeenSet = true; m_maxParts = value; }
    inline GetObjectAttributesParts& WithMaxParts(int value) { SetMaxParts(value); return *this;}
    ///@}

    ///@{
    /**
     * <p>Indicates whether the returned list of parts is truncated. A value of
     * <code>true</code> indicates that the list was truncated. A list can be truncated
     * if the number of parts exceeds the limit returned in the <code>MaxParts</code>
     * element.</p>
     */
    inline bool GetIsTruncated() const { return m_isTruncated; }
    inline bool IsTruncatedHasBeenSet() const { return m_isTruncatedHasBeenSet; }
    inline void SetIsTruncated(bool value) { m_isTruncatedHasBeenSet = true; m_isTruncated = value; }
    inline GetObjectAttributesParts& WithIsTruncated(bool value) { SetIsTruncated(value); return *this;}
    ///@}

    ///@{
    /**
     * <p>A container for elements related to a particular part. A response can contain
     * zero or more <code>Parts</code> elements.</p>  <ul> <li> <p> <b>General
     * purpose buckets</b> - For <code>GetObjectAttributes</code>, if an additional
     * checksum (including <code>x-amz-checksum-crc32</code>,
     * <code>x-amz-checksum-crc32c</code>, <code>x-amz-checksum-sha1</code>, or
     * <code>x-amz-checksum-sha256</code>) isn't applied to the object specified in the
     * request, the response doesn't return the <code>Part</code> element.</p> </li>
     * <li> <p> <b>Directory buckets</b> - For <code>GetObjectAttributes</code>,
     * regardless of whether an additional checksum is applied to the object specified
     * in the request, the response returns the <code>Part</code> element.</p> </li>
     * </ul> 
     */
    inline const Aws::Vector<ObjectPart>& GetParts() const { return m_parts; }
    inline bool PartsHasBeenSet() const { return m_partsHasBeenSet; }
    template<typename PartsT = Aws::Vector<ObjectPart>>
    void SetParts(PartsT&& value) { m_partsHasBeenSet = true; m_parts = std::forward<PartsT>(value); }
    template<typename PartsT = Aws::Vector<ObjectPart>>
    GetObjectAttributesParts& WithParts(PartsT&& value) { SetParts(std::forward<PartsT>(value)); return *this;}
    template<typename PartsT = ObjectPart>
    GetObjectAttributesParts& AddParts(PartsT&& value) { m_partsHasBeenSet = true; m_parts.emplace_back(std::forward<PartsT>(value)); return *this; }
    ///@}
  private:

    int m_totalPartsCount{0};
    bool m_totalPartsCountHasBeenSet = false;

    int m_partNumberMarker{0};
    bool m_partNumberMarkerHasBeenSet = false;

    int m_nextPartNumberMarker{0};
    bool m_nextPartNumberMarkerHasBeenSet = false;

    int m_maxParts{0};
    bool m_maxPartsHasBeenSet = false;

    bool m_isTruncated{false};
    bool m_isTruncatedHasBeenSet = false;

    Aws::Vector<ObjectPart> m_parts;
    bool m_partsHasBeenSet = false;
  };

} // namespace Model
} // namespace S3Crt
} // namespace Aws
