﻿/**
 * Copyright Amazon.com, Inc. or its affiliates. All Rights Reserved.
 * SPDX-License-Identifier: Apache-2.0.
 */

#pragma once
#include <aws/s3/S3_EXPORTS.h>
#include <aws/core/utils/memory/stl/AWSString.h>
#include <aws/core/utils/DateTime.h>
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
namespace S3
{
namespace Model
{

  /**
   * <p> In terms of implementation, a Bucket is a resource. </p><p><h3>See
   * Also:</h3>   <a
   * href="http://docs.aws.amazon.com/goto/WebAPI/s3-2006-03-01/Bucket">AWS API
   * Reference</a></p>
   */
  class Bucket
  {
  public:
    AWS_S3_API Bucket() = default;
    AWS_S3_API Bucket(const Aws::Utils::Xml::XmlNode& xmlNode);
    AWS_S3_API Bucket& operator=(const Aws::Utils::Xml::XmlNode& xmlNode);

    AWS_S3_API void AddToNode(Aws::Utils::Xml::XmlNode& parentNode) const;


    ///@{
    /**
     * <p>The name of the bucket.</p>
     */
    inline const Aws::String& GetName() const { return m_name; }
    inline bool NameHasBeenSet() const { return m_nameHasBeenSet; }
    template<typename NameT = Aws::String>
    void SetName(NameT&& value) { m_nameHasBeenSet = true; m_name = std::forward<NameT>(value); }
    template<typename NameT = Aws::String>
    Bucket& WithName(NameT&& value) { SetName(std::forward<NameT>(value)); return *this;}
    ///@}

    ///@{
    /**
     * <p>Date the bucket was created. This date can change when making changes to your
     * bucket, such as editing its bucket policy.</p>
     */
    inline const Aws::Utils::DateTime& GetCreationDate() const { return m_creationDate; }
    inline bool CreationDateHasBeenSet() const { return m_creationDateHasBeenSet; }
    template<typename CreationDateT = Aws::Utils::DateTime>
    void SetCreationDate(CreationDateT&& value) { m_creationDateHasBeenSet = true; m_creationDate = std::forward<CreationDateT>(value); }
    template<typename CreationDateT = Aws::Utils::DateTime>
    Bucket& WithCreationDate(CreationDateT&& value) { SetCreationDate(std::forward<CreationDateT>(value)); return *this;}
    ///@}

    ///@{
    /**
     * <p> <code>BucketRegion</code> indicates the Amazon Web Services region where the
     * bucket is located. If the request contains at least one valid parameter, it is
     * included in the response.</p>
     */
    inline const Aws::String& GetBucketRegion() const { return m_bucketRegion; }
    inline bool BucketRegionHasBeenSet() const { return m_bucketRegionHasBeenSet; }
    template<typename BucketRegionT = Aws::String>
    void SetBucketRegion(BucketRegionT&& value) { m_bucketRegionHasBeenSet = true; m_bucketRegion = std::forward<BucketRegionT>(value); }
    template<typename BucketRegionT = Aws::String>
    Bucket& WithBucketRegion(BucketRegionT&& value) { SetBucketRegion(std::forward<BucketRegionT>(value)); return *this;}
    ///@}

    ///@{
    /**
     * <p>The Amazon Resource Name (ARN) of the S3 bucket. ARNs uniquely identify
     * Amazon Web Services resources across all of Amazon Web Services.</p> 
     * <p>This parameter is only supported for S3 directory buckets. For more
     * information, see <a
     * href="https://docs.aws.amazon.com/AmazonS3/latest/userguide/directory-buckets-tagging.html">Using
     * tags with directory buckets</a>.</p> 
     */
    inline const Aws::String& GetBucketArn() const { return m_bucketArn; }
    inline bool BucketArnHasBeenSet() const { return m_bucketArnHasBeenSet; }
    template<typename BucketArnT = Aws::String>
    void SetBucketArn(BucketArnT&& value) { m_bucketArnHasBeenSet = true; m_bucketArn = std::forward<BucketArnT>(value); }
    template<typename BucketArnT = Aws::String>
    Bucket& WithBucketArn(BucketArnT&& value) { SetBucketArn(std::forward<BucketArnT>(value)); return *this;}
    ///@}
  private:

    Aws::String m_name;
    bool m_nameHasBeenSet = false;

    Aws::Utils::DateTime m_creationDate{};
    bool m_creationDateHasBeenSet = false;

    Aws::String m_bucketRegion;
    bool m_bucketRegionHasBeenSet = false;

    Aws::String m_bucketArn;
    bool m_bucketArnHasBeenSet = false;
  };

} // namespace Model
} // namespace S3
} // namespace Aws
