﻿/**
 * Copyright Amazon.com, Inc. or its affiliates. All Rights Reserved.
 * SPDX-License-Identifier: Apache-2.0.
 */

#pragma once
#include <aws/s3-crt/S3Crt_EXPORTS.h>
#include <aws/s3-crt/S3CrtRequest.h>
#include <aws/s3-crt/model/ObjectCannedACL.h>
#include <aws/core/utils/memory/stl/AWSString.h>
#include <aws/s3-crt/model/ChecksumAlgorithm.h>
#include <aws/core/utils/DateTime.h>
#include <aws/core/utils/memory/stl/AWSMap.h>
#include <aws/s3-crt/model/MetadataDirective.h>
#include <aws/s3-crt/model/TaggingDirective.h>
#include <aws/s3-crt/model/ServerSideEncryption.h>
#include <aws/s3-crt/model/StorageClass.h>
#include <aws/s3-crt/model/RequestPayer.h>
#include <aws/s3-crt/model/ObjectLockMode.h>
#include <aws/s3-crt/model/ObjectLockLegalHoldStatus.h>
#include <utility>

namespace Aws
{
namespace Http
{
    class URI;
} //namespace Http
namespace S3Crt
{
namespace Model
{

  /**
   */
  class CopyObjectRequest : public S3CrtRequest
  {
  public:
    AWS_S3CRT_API CopyObjectRequest() = default;

    // Service request name is the Operation name which will send this request out,
    // each operation should has unique request name, so that we can get operation's name from this request.
    // Note: this is not true for response, multiple operations may have the same response name,
    // so we can not get operation's name from response.
    inline virtual const char* GetServiceRequestName() const override { return "CopyObject"; }

    AWS_S3CRT_API Aws::String SerializePayload() const override;

    AWS_S3CRT_API void AddQueryStringParameters(Aws::Http::URI& uri) const override;

    AWS_S3CRT_API Aws::Http::HeaderValueCollection GetRequestSpecificHeaders() const override;

    AWS_S3CRT_API bool HasEmbeddedError(IOStream &body, const Http::HeaderValueCollection &header) const override;
    /**
     * Helper function to collect parameters (configurable and static hardcoded) required for endpoint computation.
     */
    AWS_S3CRT_API EndpointParameters GetEndpointContextParams() const override;

    ///@{
    /**
     * <p>The canned access control list (ACL) to apply to the object.</p> <p>When you
     * copy an object, the ACL metadata is not preserved and is set to
     * <code>private</code> by default. Only the owner has full access control. To
     * override the default ACL setting, specify a new ACL when you generate a copy
     * request. For more information, see <a
     * href="https://docs.aws.amazon.com/AmazonS3/latest/dev/S3_ACLs_UsingACLs.html">Using
     * ACLs</a>. </p> <p>If the destination bucket that you're copying objects to uses
     * the bucket owner enforced setting for S3 Object Ownership, ACLs are disabled and
     * no longer affect permissions. Buckets that use this setting only accept
     * <code>PUT</code> requests that don't specify an ACL or <code>PUT</code> requests
     * that specify bucket owner full control ACLs, such as the
     * <code>bucket-owner-full-control</code> canned ACL or an equivalent form of this
     * ACL expressed in the XML format. For more information, see <a
     * href="https://docs.aws.amazon.com/AmazonS3/latest/userguide/about-object-ownership.html">Controlling
     * ownership of objects and disabling ACLs</a> in the <i>Amazon S3 User
     * Guide</i>.</p>  <ul> <li> <p>If your destination bucket uses the bucket
     * owner enforced setting for Object Ownership, all objects written to the bucket
     * by any account will be owned by the bucket owner.</p> </li> <li> <p>This
     * functionality is not supported for directory buckets.</p> </li> <li> <p>This
     * functionality is not supported for Amazon S3 on Outposts.</p> </li> </ul>
     * 
     */
    inline ObjectCannedACL GetACL() const { return m_aCL; }
    inline bool ACLHasBeenSet() const { return m_aCLHasBeenSet; }
    inline void SetACL(ObjectCannedACL value) { m_aCLHasBeenSet = true; m_aCL = value; }
    inline CopyObjectRequest& WithACL(ObjectCannedACL value) { SetACL(value); return *this;}
    ///@}

    ///@{
    /**
     * <p>The name of the destination bucket.</p> <p> <b>Directory buckets</b> - When
     * you use this operation with a directory bucket, you must use
     * virtual-hosted-style requests in the format <code>
     * <i>Bucket-name</i>.s3express-<i>zone-id</i>.<i>region-code</i>.amazonaws.com</code>.
     * Path-style requests are not supported. Directory bucket names must be unique in
     * the chosen Zone (Availability Zone or Local Zone). Bucket names must follow the
     * format <code> <i>bucket-base-name</i>--<i>zone-id</i>--x-s3</code> (for example,
     * <code> <i>amzn-s3-demo-bucket</i>--<i>usw2-az1</i>--x-s3</code>). For
     * information about bucket naming restrictions, see <a
     * href="https://docs.aws.amazon.com/AmazonS3/latest/userguide/directory-bucket-naming-rules.html">Directory
     * bucket naming rules</a> in the <i>Amazon S3 User Guide</i>.</p> 
     * <p>Copying objects across different Amazon Web Services Regions isn't supported
     * when the source or destination bucket is in Amazon Web Services Local Zones. The
     * source and destination buckets must have the same parent Amazon Web Services
     * Region. Otherwise, you get an HTTP <code>400 Bad Request</code> error with the
     * error code <code>InvalidRequest</code>.</p>  <p> <b>Access points</b> -
     * When you use this action with an access point for general purpose buckets, you
     * must provide the alias of the access point in place of the bucket name or
     * specify the access point ARN. When you use this action with an access point for
     * directory buckets, you must provide the access point name in place of the bucket
     * name. When using the access point ARN, you must direct requests to the access
     * point hostname. The access point hostname takes the form
     * <i>AccessPointName</i>-<i>AccountId</i>.s3-accesspoint.<i>Region</i>.amazonaws.com.
     * When using this action with an access point through the Amazon Web Services
     * SDKs, you provide the access point ARN in place of the bucket name. For more
     * information about access point ARNs, see <a
     * href="https://docs.aws.amazon.com/AmazonS3/latest/userguide/using-access-points.html">Using
     * access points</a> in the <i>Amazon S3 User Guide</i>.</p>  <p>Object
     * Lambda access points are not supported by directory buckets.</p>  <p>
     * <b>S3 on Outposts</b> - When you use this action with S3 on Outposts, you must
     * use the Outpost bucket access point ARN or the access point alias for the
     * destination bucket. You can only copy objects within the same Outpost bucket.
     * It's not supported to copy objects across different Amazon Web Services
     * Outposts, between buckets on the same Outposts, or between Outposts buckets and
     * any other bucket types. For more information about S3 on Outposts, see <a
     * href="https://docs.aws.amazon.com/AmazonS3/latest/userguide/S3onOutposts.html">What
     * is S3 on Outposts?</a> in the <i>S3 on Outposts guide</i>. When you use this
     * action with S3 on Outposts through the REST API, you must direct requests to the
     * S3 on Outposts hostname, in the format <code>
     * <i>AccessPointName</i>-<i>AccountId</i>.<i>outpostID</i>.s3-outposts.<i>Region</i>.amazonaws.com</code>.
     * The hostname isn't required when you use the Amazon Web Services CLI or SDKs.
     * </p>
     */
    inline const Aws::String& GetBucket() const { return m_bucket; }
    inline bool BucketHasBeenSet() const { return m_bucketHasBeenSet; }
    template<typename BucketT = Aws::String>
    void SetBucket(BucketT&& value) { m_bucketHasBeenSet = true; m_bucket = std::forward<BucketT>(value); }
    template<typename BucketT = Aws::String>
    CopyObjectRequest& WithBucket(BucketT&& value) { SetBucket(std::forward<BucketT>(value)); return *this;}
    ///@}

    ///@{
    /**
     * <p>Specifies the caching behavior along the request/reply chain.</p>
     */
    inline const Aws::String& GetCacheControl() const { return m_cacheControl; }
    inline bool CacheControlHasBeenSet() const { return m_cacheControlHasBeenSet; }
    template<typename CacheControlT = Aws::String>
    void SetCacheControl(CacheControlT&& value) { m_cacheControlHasBeenSet = true; m_cacheControl = std::forward<CacheControlT>(value); }
    template<typename CacheControlT = Aws::String>
    CopyObjectRequest& WithCacheControl(CacheControlT&& value) { SetCacheControl(std::forward<CacheControlT>(value)); return *this;}
    ///@}

    ///@{
    /**
     * <p>Indicates the algorithm that you want Amazon S3 to use to create the checksum
     * for the object. For more information, see <a
     * href="https://docs.aws.amazon.com/AmazonS3/latest/userguide/checking-object-integrity.html">Checking
     * object integrity</a> in the <i>Amazon S3 User Guide</i>.</p> <p>When you copy an
     * object, if the source object has a checksum, that checksum value will be copied
     * to the new object by default. If the <code>CopyObject</code> request does not
     * include this <code>x-amz-checksum-algorithm</code> header, the checksum
     * algorithm will be copied from the source object to the destination object (if
     * it's present on the source object). You can optionally specify a different
     * checksum algorithm to use with the <code>x-amz-checksum-algorithm</code> header.
     * Unrecognized or unsupported values will respond with the HTTP status code
     * <code>400 Bad Request</code>.</p>  <p>For directory buckets, when you use
     * Amazon Web Services SDKs, <code>CRC32</code> is the default checksum algorithm
     * that's used for performance.</p> 
     */
    inline ChecksumAlgorithm GetChecksumAlgorithm() const { return m_checksumAlgorithm; }
    inline bool ChecksumAlgorithmHasBeenSet() const { return m_checksumAlgorithmHasBeenSet; }
    inline void SetChecksumAlgorithm(ChecksumAlgorithm value) { m_checksumAlgorithmHasBeenSet = true; m_checksumAlgorithm = value; }
    inline CopyObjectRequest& WithChecksumAlgorithm(ChecksumAlgorithm value) { SetChecksumAlgorithm(value); return *this;}
    ///@}

    ///@{
    /**
     * <p>Specifies presentational information for the object. Indicates whether an
     * object should be displayed in a web browser or downloaded as a file. It allows
     * specifying the desired filename for the downloaded file.</p>
     */
    inline const Aws::String& GetContentDisposition() const { return m_contentDisposition; }
    inline bool ContentDispositionHasBeenSet() const { return m_contentDispositionHasBeenSet; }
    template<typename ContentDispositionT = Aws::String>
    void SetContentDisposition(ContentDispositionT&& value) { m_contentDispositionHasBeenSet = true; m_contentDisposition = std::forward<ContentDispositionT>(value); }
    template<typename ContentDispositionT = Aws::String>
    CopyObjectRequest& WithContentDisposition(ContentDispositionT&& value) { SetContentDisposition(std::forward<ContentDispositionT>(value)); return *this;}
    ///@}

    ///@{
    /**
     * <p>Specifies what content encodings have been applied to the object and thus
     * what decoding mechanisms must be applied to obtain the media-type referenced by
     * the Content-Type header field.</p>  <p>For directory buckets, only the
     * <code>aws-chunked</code> value is supported in this header field.</p> 
     */
    inline const Aws::String& GetContentEncoding() const { return m_contentEncoding; }
    inline bool ContentEncodingHasBeenSet() const { return m_contentEncodingHasBeenSet; }
    template<typename ContentEncodingT = Aws::String>
    void SetContentEncoding(ContentEncodingT&& value) { m_contentEncodingHasBeenSet = true; m_contentEncoding = std::forward<ContentEncodingT>(value); }
    template<typename ContentEncodingT = Aws::String>
    CopyObjectRequest& WithContentEncoding(ContentEncodingT&& value) { SetContentEncoding(std::forward<ContentEncodingT>(value)); return *this;}
    ///@}

    ///@{
    /**
     * <p>The language the content is in.</p>
     */
    inline const Aws::String& GetContentLanguage() const { return m_contentLanguage; }
    inline bool ContentLanguageHasBeenSet() const { return m_contentLanguageHasBeenSet; }
    template<typename ContentLanguageT = Aws::String>
    void SetContentLanguage(ContentLanguageT&& value) { m_contentLanguageHasBeenSet = true; m_contentLanguage = std::forward<ContentLanguageT>(value); }
    template<typename ContentLanguageT = Aws::String>
    CopyObjectRequest& WithContentLanguage(ContentLanguageT&& value) { SetContentLanguage(std::forward<ContentLanguageT>(value)); return *this;}
    ///@}

    ///@{
    /**
     * <p>A standard MIME type that describes the format of the object data.</p>
     */
    inline const Aws::String& GetContentType() const { return m_contentType; }
    inline bool ContentTypeHasBeenSet() const { return m_contentTypeHasBeenSet; }
    template<typename ContentTypeT = Aws::String>
    void SetContentType(ContentTypeT&& value) { m_contentTypeHasBeenSet = true; m_contentType = std::forward<ContentTypeT>(value); }
    template<typename ContentTypeT = Aws::String>
    CopyObjectRequest& WithContentType(ContentTypeT&& value) { SetContentType(std::forward<ContentTypeT>(value)); return *this;}
    ///@}

    ///@{
    /**
     * <p>Specifies the source object for the copy operation. The source object can be
     * up to 5 GB. If the source object is an object that was uploaded by using a
     * multipart upload, the object copy will be a single part object after the source
     * object is copied to the destination bucket.</p> <p>You specify the value of the
     * copy source in one of two formats, depending on whether you want to access the
     * source object through an <a
     * href="https://docs.aws.amazon.com/AmazonS3/latest/userguide/access-points.html">access
     * point</a>:</p> <ul> <li> <p>For objects not accessed through an access point,
     * specify the name of the source bucket and the key of the source object,
     * separated by a slash (/). For example, to copy the object
     * <code>reports/january.pdf</code> from the general purpose bucket
     * <code>awsexamplebucket</code>, use
     * <code>awsexamplebucket/reports/january.pdf</code>. The value must be
     * URL-encoded. To copy the object <code>reports/january.pdf</code> from the
     * directory bucket <code>awsexamplebucket--use1-az5--x-s3</code>, use
     * <code>awsexamplebucket--use1-az5--x-s3/reports/january.pdf</code>. The value
     * must be URL-encoded.</p> </li> <li> <p>For objects accessed through access
     * points, specify the Amazon Resource Name (ARN) of the object as accessed through
     * the access point, in the format
     * <code>arn:aws:s3:&lt;Region&gt;:&lt;account-id&gt;:accesspoint/&lt;access-point-name&gt;/object/&lt;key&gt;</code>.
     * For example, to copy the object <code>reports/january.pdf</code> through access
     * point <code>my-access-point</code> owned by account <code>123456789012</code> in
     * Region <code>us-west-2</code>, use the URL encoding of
     * <code>arn:aws:s3:us-west-2:123456789012:accesspoint/my-access-point/object/reports/january.pdf</code>.
     * The value must be URL encoded.</p>  <ul> <li> <p>Amazon S3 supports copy
     * operations using Access points only when the source and destination buckets are
     * in the same Amazon Web Services Region.</p> </li> <li> <p>Access points are not
     * supported by directory buckets.</p> </li> </ul>  <p>Alternatively, for
     * objects accessed through Amazon S3 on Outposts, specify the ARN of the object as
     * accessed in the format
     * <code>arn:aws:s3-outposts:&lt;Region&gt;:&lt;account-id&gt;:outpost/&lt;outpost-id&gt;/object/&lt;key&gt;</code>.
     * For example, to copy the object <code>reports/january.pdf</code> through outpost
     * <code>my-outpost</code> owned by account <code>123456789012</code> in Region
     * <code>us-west-2</code>, use the URL encoding of
     * <code>arn:aws:s3-outposts:us-west-2:123456789012:outpost/my-outpost/object/reports/january.pdf</code>.
     * The value must be URL-encoded. </p> </li> </ul> <p>If your source bucket
     * versioning is enabled, the <code>x-amz-copy-source</code> header by default
     * identifies the current version of an object to copy. If the current version is a
     * delete marker, Amazon S3 behaves as if the object was deleted. To copy a
     * different version, use the <code>versionId</code> query parameter. Specifically,
     * append <code>?versionId=&lt;version-id&gt;</code> to the value (for example,
     * <code>awsexamplebucket/reports/january.pdf?versionId=QUpfdndhfd8438MNFDN93jdnJFkdmqnh893</code>).
     * If you don't specify a version ID, Amazon S3 copies the latest version of the
     * source object.</p> <p>If you enable versioning on the destination bucket, Amazon
     * S3 generates a unique version ID for the copied object. This version ID is
     * different from the version ID of the source object. Amazon S3 returns the
     * version ID of the copied object in the <code>x-amz-version-id</code> response
     * header in the response.</p> <p>If you do not enable versioning or suspend it on
     * the destination bucket, the version ID that Amazon S3 generates in the
     * <code>x-amz-version-id</code> response header is always null.</p>  <p>
     * <b>Directory buckets</b> - S3 Versioning isn't enabled and supported for
     * directory buckets.</p> 
     */
    inline const Aws::String& GetCopySource() const { return m_copySource; }
    inline bool CopySourceHasBeenSet() const { return m_copySourceHasBeenSet; }
    template<typename CopySourceT = Aws::String>
    void SetCopySource(CopySourceT&& value) { m_copySourceHasBeenSet = true; m_copySource = std::forward<CopySourceT>(value); }
    template<typename CopySourceT = Aws::String>
    CopyObjectRequest& WithCopySource(CopySourceT&& value) { SetCopySource(std::forward<CopySourceT>(value)); return *this;}
    ///@}

    ///@{
    /**
     * <p>Copies the object if its entity tag (ETag) matches the specified tag.</p> <p>
     * If both the <code>x-amz-copy-source-if-match</code> and
     * <code>x-amz-copy-source-if-unmodified-since</code> headers are present in the
     * request and evaluate as follows, Amazon S3 returns <code>200 OK</code> and
     * copies the data:</p> <ul> <li> <p> <code>x-amz-copy-source-if-match</code>
     * condition evaluates to true</p> </li> <li> <p>
     * <code>x-amz-copy-source-if-unmodified-since</code> condition evaluates to
     * false</p> </li> </ul>
     */
    inline const Aws::String& GetCopySourceIfMatch() const { return m_copySourceIfMatch; }
    inline bool CopySourceIfMatchHasBeenSet() const { return m_copySourceIfMatchHasBeenSet; }
    template<typename CopySourceIfMatchT = Aws::String>
    void SetCopySourceIfMatch(CopySourceIfMatchT&& value) { m_copySourceIfMatchHasBeenSet = true; m_copySourceIfMatch = std::forward<CopySourceIfMatchT>(value); }
    template<typename CopySourceIfMatchT = Aws::String>
    CopyObjectRequest& WithCopySourceIfMatch(CopySourceIfMatchT&& value) { SetCopySourceIfMatch(std::forward<CopySourceIfMatchT>(value)); return *this;}
    ///@}

    ///@{
    /**
     * <p>Copies the object if it has been modified since the specified time.</p> <p>If
     * both the <code>x-amz-copy-source-if-none-match</code> and
     * <code>x-amz-copy-source-if-modified-since</code> headers are present in the
     * request and evaluate as follows, Amazon S3 returns the <code>412 Precondition
     * Failed</code> response code:</p> <ul> <li> <p>
     * <code>x-amz-copy-source-if-none-match</code> condition evaluates to false</p>
     * </li> <li> <p> <code>x-amz-copy-source-if-modified-since</code> condition
     * evaluates to true</p> </li> </ul>
     */
    inline const Aws::Utils::DateTime& GetCopySourceIfModifiedSince() const { return m_copySourceIfModifiedSince; }
    inline bool CopySourceIfModifiedSinceHasBeenSet() const { return m_copySourceIfModifiedSinceHasBeenSet; }
    template<typename CopySourceIfModifiedSinceT = Aws::Utils::DateTime>
    void SetCopySourceIfModifiedSince(CopySourceIfModifiedSinceT&& value) { m_copySourceIfModifiedSinceHasBeenSet = true; m_copySourceIfModifiedSince = std::forward<CopySourceIfModifiedSinceT>(value); }
    template<typename CopySourceIfModifiedSinceT = Aws::Utils::DateTime>
    CopyObjectRequest& WithCopySourceIfModifiedSince(CopySourceIfModifiedSinceT&& value) { SetCopySourceIfModifiedSince(std::forward<CopySourceIfModifiedSinceT>(value)); return *this;}
    ///@}

    ///@{
    /**
     * <p>Copies the object if its entity tag (ETag) is different than the specified
     * ETag.</p> <p>If both the <code>x-amz-copy-source-if-none-match</code> and
     * <code>x-amz-copy-source-if-modified-since</code> headers are present in the
     * request and evaluate as follows, Amazon S3 returns the <code>412 Precondition
     * Failed</code> response code:</p> <ul> <li> <p>
     * <code>x-amz-copy-source-if-none-match</code> condition evaluates to false</p>
     * </li> <li> <p> <code>x-amz-copy-source-if-modified-since</code> condition
     * evaluates to true</p> </li> </ul>
     */
    inline const Aws::String& GetCopySourceIfNoneMatch() const { return m_copySourceIfNoneMatch; }
    inline bool CopySourceIfNoneMatchHasBeenSet() const { return m_copySourceIfNoneMatchHasBeenSet; }
    template<typename CopySourceIfNoneMatchT = Aws::String>
    void SetCopySourceIfNoneMatch(CopySourceIfNoneMatchT&& value) { m_copySourceIfNoneMatchHasBeenSet = true; m_copySourceIfNoneMatch = std::forward<CopySourceIfNoneMatchT>(value); }
    template<typename CopySourceIfNoneMatchT = Aws::String>
    CopyObjectRequest& WithCopySourceIfNoneMatch(CopySourceIfNoneMatchT&& value) { SetCopySourceIfNoneMatch(std::forward<CopySourceIfNoneMatchT>(value)); return *this;}
    ///@}

    ///@{
    /**
     * <p>Copies the object if it hasn't been modified since the specified time.</p>
     * <p> If both the <code>x-amz-copy-source-if-match</code> and
     * <code>x-amz-copy-source-if-unmodified-since</code> headers are present in the
     * request and evaluate as follows, Amazon S3 returns <code>200 OK</code> and
     * copies the data:</p> <ul> <li> <p> <code>x-amz-copy-source-if-match</code>
     * condition evaluates to true</p> </li> <li> <p>
     * <code>x-amz-copy-source-if-unmodified-since</code> condition evaluates to
     * false</p> </li> </ul>
     */
    inline const Aws::Utils::DateTime& GetCopySourceIfUnmodifiedSince() const { return m_copySourceIfUnmodifiedSince; }
    inline bool CopySourceIfUnmodifiedSinceHasBeenSet() const { return m_copySourceIfUnmodifiedSinceHasBeenSet; }
    template<typename CopySourceIfUnmodifiedSinceT = Aws::Utils::DateTime>
    void SetCopySourceIfUnmodifiedSince(CopySourceIfUnmodifiedSinceT&& value) { m_copySourceIfUnmodifiedSinceHasBeenSet = true; m_copySourceIfUnmodifiedSince = std::forward<CopySourceIfUnmodifiedSinceT>(value); }
    template<typename CopySourceIfUnmodifiedSinceT = Aws::Utils::DateTime>
    CopyObjectRequest& WithCopySourceIfUnmodifiedSince(CopySourceIfUnmodifiedSinceT&& value) { SetCopySourceIfUnmodifiedSince(std::forward<CopySourceIfUnmodifiedSinceT>(value)); return *this;}
    ///@}

    ///@{
    /**
     * <p>The date and time at which the object is no longer cacheable.</p>
     */
    inline const Aws::Utils::DateTime& GetExpires() const { return m_expires; }
    inline bool ExpiresHasBeenSet() const { return m_expiresHasBeenSet; }
    template<typename ExpiresT = Aws::Utils::DateTime>
    void SetExpires(ExpiresT&& value) { m_expiresHasBeenSet = true; m_expires = std::forward<ExpiresT>(value); }
    template<typename ExpiresT = Aws::Utils::DateTime>
    CopyObjectRequest& WithExpires(ExpiresT&& value) { SetExpires(std::forward<ExpiresT>(value)); return *this;}
    ///@}

    ///@{
    /**
     * <p>Gives the grantee READ, READ_ACP, and WRITE_ACP permissions on the
     * object.</p>  <ul> <li> <p>This functionality is not supported for
     * directory buckets.</p> </li> <li> <p>This functionality is not supported for
     * Amazon S3 on Outposts.</p> </li> </ul> 
     */
    inline const Aws::String& GetGrantFullControl() const { return m_grantFullControl; }
    inline bool GrantFullControlHasBeenSet() const { return m_grantFullControlHasBeenSet; }
    template<typename GrantFullControlT = Aws::String>
    void SetGrantFullControl(GrantFullControlT&& value) { m_grantFullControlHasBeenSet = true; m_grantFullControl = std::forward<GrantFullControlT>(value); }
    template<typename GrantFullControlT = Aws::String>
    CopyObjectRequest& WithGrantFullControl(GrantFullControlT&& value) { SetGrantFullControl(std::forward<GrantFullControlT>(value)); return *this;}
    ///@}

    ///@{
    /**
     * <p>Allows grantee to read the object data and its metadata.</p>  <ul> <li>
     * <p>This functionality is not supported for directory buckets.</p> </li> <li>
     * <p>This functionality is not supported for Amazon S3 on Outposts.</p> </li>
     * </ul> 
     */
    inline const Aws::String& GetGrantRead() const { return m_grantRead; }
    inline bool GrantReadHasBeenSet() const { return m_grantReadHasBeenSet; }
    template<typename GrantReadT = Aws::String>
    void SetGrantRead(GrantReadT&& value) { m_grantReadHasBeenSet = true; m_grantRead = std::forward<GrantReadT>(value); }
    template<typename GrantReadT = Aws::String>
    CopyObjectRequest& WithGrantRead(GrantReadT&& value) { SetGrantRead(std::forward<GrantReadT>(value)); return *this;}
    ///@}

    ///@{
    /**
     * <p>Allows grantee to read the object ACL.</p>  <ul> <li> <p>This
     * functionality is not supported for directory buckets.</p> </li> <li> <p>This
     * functionality is not supported for Amazon S3 on Outposts.</p> </li> </ul>
     * 
     */
    inline const Aws::String& GetGrantReadACP() const { return m_grantReadACP; }
    inline bool GrantReadACPHasBeenSet() const { return m_grantReadACPHasBeenSet; }
    template<typename GrantReadACPT = Aws::String>
    void SetGrantReadACP(GrantReadACPT&& value) { m_grantReadACPHasBeenSet = true; m_grantReadACP = std::forward<GrantReadACPT>(value); }
    template<typename GrantReadACPT = Aws::String>
    CopyObjectRequest& WithGrantReadACP(GrantReadACPT&& value) { SetGrantReadACP(std::forward<GrantReadACPT>(value)); return *this;}
    ///@}

    ///@{
    /**
     * <p>Allows grantee to write the ACL for the applicable object.</p>  <ul>
     * <li> <p>This functionality is not supported for directory buckets.</p> </li>
     * <li> <p>This functionality is not supported for Amazon S3 on Outposts.</p> </li>
     * </ul> 
     */
    inline const Aws::String& GetGrantWriteACP() const { return m_grantWriteACP; }
    inline bool GrantWriteACPHasBeenSet() const { return m_grantWriteACPHasBeenSet; }
    template<typename GrantWriteACPT = Aws::String>
    void SetGrantWriteACP(GrantWriteACPT&& value) { m_grantWriteACPHasBeenSet = true; m_grantWriteACP = std::forward<GrantWriteACPT>(value); }
    template<typename GrantWriteACPT = Aws::String>
    CopyObjectRequest& WithGrantWriteACP(GrantWriteACPT&& value) { SetGrantWriteACP(std::forward<GrantWriteACPT>(value)); return *this;}
    ///@}

    ///@{
    /**
     * <p>The key of the destination object.</p>
     */
    inline const Aws::String& GetKey() const { return m_key; }
    inline bool KeyHasBeenSet() const { return m_keyHasBeenSet; }
    template<typename KeyT = Aws::String>
    void SetKey(KeyT&& value) { m_keyHasBeenSet = true; m_key = std::forward<KeyT>(value); }
    template<typename KeyT = Aws::String>
    CopyObjectRequest& WithKey(KeyT&& value) { SetKey(std::forward<KeyT>(value)); return *this;}
    ///@}

    ///@{
    /**
     * <p>A map of metadata to store with the object in S3.</p>
     */
    inline const Aws::Map<Aws::String, Aws::String>& GetMetadata() const { return m_metadata; }
    inline bool MetadataHasBeenSet() const { return m_metadataHasBeenSet; }
    template<typename MetadataT = Aws::Map<Aws::String, Aws::String>>
    void SetMetadata(MetadataT&& value) { m_metadataHasBeenSet = true; m_metadata = std::forward<MetadataT>(value); }
    template<typename MetadataT = Aws::Map<Aws::String, Aws::String>>
    CopyObjectRequest& WithMetadata(MetadataT&& value) { SetMetadata(std::forward<MetadataT>(value)); return *this;}
    template<typename MetadataKeyT = Aws::String, typename MetadataValueT = Aws::String>
    CopyObjectRequest& AddMetadata(MetadataKeyT&& key, MetadataValueT&& value) {
      m_metadataHasBeenSet = true; m_metadata.emplace(std::forward<MetadataKeyT>(key), std::forward<MetadataValueT>(value)); return *this;
    }
    ///@}

    ///@{
    /**
     * <p>Specifies whether the metadata is copied from the source object or replaced
     * with metadata that's provided in the request. When copying an object, you can
     * preserve all metadata (the default) or specify new metadata. If this header
     * isn’t specified, <code>COPY</code> is the default behavior. </p> <p> <b>General
     * purpose bucket</b> - For general purpose buckets, when you grant permissions,
     * you can use the <code>s3:x-amz-metadata-directive</code> condition key to
     * enforce certain metadata behavior when objects are uploaded. For more
     * information, see <a
     * href="https://docs.aws.amazon.com/AmazonS3/latest/dev/amazon-s3-policy-keys.html">Amazon
     * S3 condition key examples</a> in the <i>Amazon S3 User Guide</i>.</p>  <p>
     * <code>x-amz-website-redirect-location</code> is unique to each object and is not
     * copied when using the <code>x-amz-metadata-directive</code> header. To copy the
     * value, you must specify <code>x-amz-website-redirect-location</code> in the
     * request header.</p> 
     */
    inline MetadataDirective GetMetadataDirective() const { return m_metadataDirective; }
    inline bool MetadataDirectiveHasBeenSet() const { return m_metadataDirectiveHasBeenSet; }
    inline void SetMetadataDirective(MetadataDirective value) { m_metadataDirectiveHasBeenSet = true; m_metadataDirective = value; }
    inline CopyObjectRequest& WithMetadataDirective(MetadataDirective value) { SetMetadataDirective(value); return *this;}
    ///@}

    ///@{
    /**
     * <p>Specifies whether the object tag-set is copied from the source object or
     * replaced with the tag-set that's provided in the request.</p> <p>The default
     * value is <code>COPY</code>.</p>  <p> <b>Directory buckets</b> - For
     * directory buckets in a <code>CopyObject</code> operation, only the empty tag-set
     * is supported. Any requests that attempt to write non-empty tags into directory
     * buckets will receive a <code>501 Not Implemented</code> status code. When the
     * destination bucket is a directory bucket, you will receive a <code>501 Not
     * Implemented</code> response in any of the following situations:</p> <ul> <li>
     * <p>When you attempt to <code>COPY</code> the tag-set from an S3 source object
     * that has non-empty tags.</p> </li> <li> <p>When you attempt to
     * <code>REPLACE</code> the tag-set of a source object and set a non-empty value to
     * <code>x-amz-tagging</code>.</p> </li> <li> <p>When you don't set the
     * <code>x-amz-tagging-directive</code> header and the source object has non-empty
     * tags. This is because the default value of <code>x-amz-tagging-directive</code>
     * is <code>COPY</code>.</p> </li> </ul> <p>Because only the empty tag-set is
     * supported for directory buckets in a <code>CopyObject</code> operation, the
     * following situations are allowed:</p> <ul> <li> <p>When you attempt to
     * <code>COPY</code> the tag-set from a directory bucket source object that has no
     * tags to a general purpose bucket. It copies an empty tag-set to the destination
     * object.</p> </li> <li> <p>When you attempt to <code>REPLACE</code> the tag-set
     * of a directory bucket source object and set the <code>x-amz-tagging</code> value
     * of the directory bucket destination object to empty.</p> </li> <li> <p>When you
     * attempt to <code>REPLACE</code> the tag-set of a general purpose bucket source
     * object that has non-empty tags and set the <code>x-amz-tagging</code> value of
     * the directory bucket destination object to empty.</p> </li> <li> <p>When you
     * attempt to <code>REPLACE</code> the tag-set of a directory bucket source object
     * and don't set the <code>x-amz-tagging</code> value of the directory bucket
     * destination object. This is because the default value of
     * <code>x-amz-tagging</code> is the empty value.</p> </li> </ul> 
     */
    inline TaggingDirective GetTaggingDirective() const { return m_taggingDirective; }
    inline bool TaggingDirectiveHasBeenSet() const { return m_taggingDirectiveHasBeenSet; }
    inline void SetTaggingDirective(TaggingDirective value) { m_taggingDirectiveHasBeenSet = true; m_taggingDirective = value; }
    inline CopyObjectRequest& WithTaggingDirective(TaggingDirective value) { SetTaggingDirective(value); return *this;}
    ///@}

    ///@{
    /**
     * <p>The server-side encryption algorithm used when storing this object in Amazon
     * S3. Unrecognized or unsupported values won’t write a destination object and will
     * receive a <code>400 Bad Request</code> response. </p> <p>Amazon S3 automatically
     * encrypts all new objects that are copied to an S3 bucket. When copying an
     * object, if you don't specify encryption information in your copy request, the
     * encryption setting of the target object is set to the default encryption
     * configuration of the destination bucket. By default, all buckets have a base
     * level of encryption configuration that uses server-side encryption with Amazon
     * S3 managed keys (SSE-S3). If the destination bucket has a different default
     * encryption configuration, Amazon S3 uses the corresponding encryption key to
     * encrypt the target object copy.</p> <p>With server-side encryption, Amazon S3
     * encrypts your data as it writes your data to disks in its data centers and
     * decrypts the data when you access it. For more information about server-side
     * encryption, see <a
     * href="https://docs.aws.amazon.com/AmazonS3/latest/dev/serv-side-encryption.html">Using
     * Server-Side Encryption</a> in the <i>Amazon S3 User Guide</i>.</p> <p>
     * <b>General purpose buckets </b> </p> <ul> <li> <p>For general purpose buckets,
     * there are the following supported options for server-side encryption:
     * server-side encryption with Key Management Service (KMS) keys (SSE-KMS),
     * dual-layer server-side encryption with Amazon Web Services KMS keys (DSSE-KMS),
     * and server-side encryption with customer-provided encryption keys (SSE-C).
     * Amazon S3 uses the corresponding KMS key, or a customer-provided key to encrypt
     * the target object copy.</p> </li> <li> <p>When you perform a
     * <code>CopyObject</code> operation, if you want to use a different type of
     * encryption setting for the target object, you can specify appropriate
     * encryption-related headers to encrypt the target object with an Amazon S3
     * managed key, a KMS key, or a customer-provided key. If the encryption setting in
     * your request is different from the default encryption configuration of the
     * destination bucket, the encryption setting in your request takes precedence.
     * </p> </li> </ul> <p> <b>Directory buckets </b> </p> <ul> <li> <p>For directory
     * buckets, there are only two supported options for server-side encryption:
     * server-side encryption with Amazon S3 managed keys (SSE-S3)
     * (<code>AES256</code>) and server-side encryption with KMS keys (SSE-KMS)
     * (<code>aws:kms</code>). We recommend that the bucket's default encryption uses
     * the desired encryption configuration and you don't override the bucket default
     * encryption in your <code>CreateSession</code> requests or <code>PUT</code>
     * object requests. Then, new objects are automatically encrypted with the desired
     * encryption settings. For more information, see <a
     * href="https://docs.aws.amazon.com/AmazonS3/latest/userguide/s3-express-serv-side-encryption.html">Protecting
     * data with server-side encryption</a> in the <i>Amazon S3 User Guide</i>. For
     * more information about the encryption overriding behaviors in directory buckets,
     * see <a
     * href="https://docs.aws.amazon.com/AmazonS3/latest/userguide/s3-express-specifying-kms-encryption.html">Specifying
     * server-side encryption with KMS for new object uploads</a>.</p> </li> <li> <p>To
     * encrypt new object copies to a directory bucket with SSE-KMS, we recommend you
     * specify SSE-KMS as the directory bucket's default encryption configuration with
     * a KMS key (specifically, a <a
     * href="https://docs.aws.amazon.com/kms/latest/developerguide/concepts.html#customer-cmk">customer
     * managed key</a>). The <a
     * href="https://docs.aws.amazon.com/kms/latest/developerguide/concepts.html#aws-managed-cmk">Amazon
     * Web Services managed key</a> (<code>aws/s3</code>) isn't supported. Your SSE-KMS
     * configuration can only support 1 <a
     * href="https://docs.aws.amazon.com/kms/latest/developerguide/concepts.html#customer-cmk">customer
     * managed key</a> per directory bucket for the lifetime of the bucket. After you
     * specify a customer managed key for SSE-KMS, you can't override the customer
     * managed key for the bucket's SSE-KMS configuration. Then, when you perform a
     * <code>CopyObject</code> operation and want to specify server-side encryption
     * settings for new object copies with SSE-KMS in the encryption-related request
     * headers, you must ensure the encryption key is the same customer managed key
     * that you specified for the directory bucket's default encryption configuration.
     * </p> </li> <li> <p> <b>S3 access points for Amazon FSx </b> - When accessing
     * data stored in Amazon FSx file systems using S3 access points, the only valid
     * server side encryption option is <code>aws:fsx</code>. All Amazon FSx file
     * systems have encryption configured by default and are encrypted at rest. Data is
     * automatically encrypted before being written to the file system, and
     * automatically decrypted as it is read. These processes are handled transparently
     * by Amazon FSx.</p> </li> </ul>
     */
    inline ServerSideEncryption GetServerSideEncryption() const { return m_serverSideEncryption; }
    inline bool ServerSideEncryptionHasBeenSet() const { return m_serverSideEncryptionHasBeenSet; }
    inline void SetServerSideEncryption(ServerSideEncryption value) { m_serverSideEncryptionHasBeenSet = true; m_serverSideEncryption = value; }
    inline CopyObjectRequest& WithServerSideEncryption(ServerSideEncryption value) { SetServerSideEncryption(value); return *this;}
    ///@}

    ///@{
    /**
     * <p>If the <code>x-amz-storage-class</code> header is not used, the copied object
     * will be stored in the <code>STANDARD</code> Storage Class by default. The
     * <code>STANDARD</code> storage class provides high durability and high
     * availability. Depending on performance needs, you can specify a different
     * Storage Class. </p>  <ul> <li> <p> <b>Directory buckets </b> - Directory
     * buckets only support <code>EXPRESS_ONEZONE</code> (the S3 Express One Zone
     * storage class) in Availability Zones and <code>ONEZONE_IA</code> (the S3 One
     * Zone-Infrequent Access storage class) in Dedicated Local Zones. Unsupported
     * storage class values won't write a destination object and will respond with the
     * HTTP status code <code>400 Bad Request</code>.</p> </li> <li> <p> <b>Amazon S3
     * on Outposts </b> - S3 on Outposts only uses the <code>OUTPOSTS</code> Storage
     * Class.</p> </li> </ul>  <p>You can use the <code>CopyObject</code> action
     * to change the storage class of an object that is already stored in Amazon S3 by
     * using the <code>x-amz-storage-class</code> header. For more information, see <a
     * href="https://docs.aws.amazon.com/AmazonS3/latest/dev/storage-class-intro.html">Storage
     * Classes</a> in the <i>Amazon S3 User Guide</i>.</p> <p>Before using an object as
     * a source object for the copy operation, you must restore a copy of it if it
     * meets any of the following conditions:</p> <ul> <li> <p>The storage class of the
     * source object is <code>GLACIER</code> or <code>DEEP_ARCHIVE</code>.</p> </li>
     * <li> <p>The storage class of the source object is
     * <code>INTELLIGENT_TIERING</code> and it's <a
     * href="https://docs.aws.amazon.com/AmazonS3/latest/userguide/intelligent-tiering-overview.html#intel-tiering-tier-definition">S3
     * Intelligent-Tiering access tier</a> is <code>Archive Access</code> or <code>Deep
     * Archive Access</code>.</p> </li> </ul> <p>For more information, see <a
     * href="https://docs.aws.amazon.com/AmazonS3/latest/API/API_RestoreObject.html">RestoreObject</a>
     * and <a
     * href="https://docs.aws.amazon.com/AmazonS3/latest/dev/CopyingObjectsExamples.html">Copying
     * Objects</a> in the <i>Amazon S3 User Guide</i>.</p>
     */
    inline StorageClass GetStorageClass() const { return m_storageClass; }
    inline bool StorageClassHasBeenSet() const { return m_storageClassHasBeenSet; }
    inline void SetStorageClass(StorageClass value) { m_storageClassHasBeenSet = true; m_storageClass = value; }
    inline CopyObjectRequest& WithStorageClass(StorageClass value) { SetStorageClass(value); return *this;}
    ///@}

    ///@{
    /**
     * <p>If the destination bucket is configured as a website, redirects requests for
     * this object copy to another object in the same bucket or to an external URL.
     * Amazon S3 stores the value of this header in the object metadata. This value is
     * unique to each object and is not copied when using the
     * <code>x-amz-metadata-directive</code> header. Instead, you may opt to provide
     * this header in combination with the <code>x-amz-metadata-directive</code>
     * header.</p>  <p>This functionality is not supported for directory
     * buckets.</p> 
     */
    inline const Aws::String& GetWebsiteRedirectLocation() const { return m_websiteRedirectLocation; }
    inline bool WebsiteRedirectLocationHasBeenSet() const { return m_websiteRedirectLocationHasBeenSet; }
    template<typename WebsiteRedirectLocationT = Aws::String>
    void SetWebsiteRedirectLocation(WebsiteRedirectLocationT&& value) { m_websiteRedirectLocationHasBeenSet = true; m_websiteRedirectLocation = std::forward<WebsiteRedirectLocationT>(value); }
    template<typename WebsiteRedirectLocationT = Aws::String>
    CopyObjectRequest& WithWebsiteRedirectLocation(WebsiteRedirectLocationT&& value) { SetWebsiteRedirectLocation(std::forward<WebsiteRedirectLocationT>(value)); return *this;}
    ///@}

    ///@{
    /**
     * <p>Specifies the algorithm to use when encrypting the object (for example,
     * <code>AES256</code>).</p> <p>When you perform a <code>CopyObject</code>
     * operation, if you want to use a different type of encryption setting for the
     * target object, you can specify appropriate encryption-related headers to encrypt
     * the target object with an Amazon S3 managed key, a KMS key, or a
     * customer-provided key. If the encryption setting in your request is different
     * from the default encryption configuration of the destination bucket, the
     * encryption setting in your request takes precedence. </p>  <p>This
     * functionality is not supported when the destination bucket is a directory
     * bucket.</p> 
     */
    inline const Aws::String& GetSSECustomerAlgorithm() const { return m_sSECustomerAlgorithm; }
    inline bool SSECustomerAlgorithmHasBeenSet() const { return m_sSECustomerAlgorithmHasBeenSet; }
    template<typename SSECustomerAlgorithmT = Aws::String>
    void SetSSECustomerAlgorithm(SSECustomerAlgorithmT&& value) { m_sSECustomerAlgorithmHasBeenSet = true; m_sSECustomerAlgorithm = std::forward<SSECustomerAlgorithmT>(value); }
    template<typename SSECustomerAlgorithmT = Aws::String>
    CopyObjectRequest& WithSSECustomerAlgorithm(SSECustomerAlgorithmT&& value) { SetSSECustomerAlgorithm(std::forward<SSECustomerAlgorithmT>(value)); return *this;}
    ///@}

    ///@{
    /**
     * <p>Specifies the customer-provided encryption key for Amazon S3 to use in
     * encrypting data. This value is used to store the object and then it is
     * discarded. Amazon S3 does not store the encryption key. The key must be
     * appropriate for use with the algorithm specified in the
     * <code>x-amz-server-side-encryption-customer-algorithm</code> header.</p> 
     * <p>This functionality is not supported when the destination bucket is a
     * directory bucket.</p> 
     */
    inline const Aws::String& GetSSECustomerKey() const { return m_sSECustomerKey; }
    inline bool SSECustomerKeyHasBeenSet() const { return m_sSECustomerKeyHasBeenSet; }
    template<typename SSECustomerKeyT = Aws::String>
    void SetSSECustomerKey(SSECustomerKeyT&& value) { m_sSECustomerKeyHasBeenSet = true; m_sSECustomerKey = std::forward<SSECustomerKeyT>(value); }
    template<typename SSECustomerKeyT = Aws::String>
    CopyObjectRequest& WithSSECustomerKey(SSECustomerKeyT&& value) { SetSSECustomerKey(std::forward<SSECustomerKeyT>(value)); return *this;}
    ///@}

    ///@{
    /**
     * <p>Specifies the 128-bit MD5 digest of the encryption key according to RFC 1321.
     * Amazon S3 uses this header for a message integrity check to ensure that the
     * encryption key was transmitted without error.</p>  <p>This functionality
     * is not supported when the destination bucket is a directory bucket.</p> 
     */
    inline const Aws::String& GetSSECustomerKeyMD5() const { return m_sSECustomerKeyMD5; }
    inline bool SSECustomerKeyMD5HasBeenSet() const { return m_sSECustomerKeyMD5HasBeenSet; }
    template<typename SSECustomerKeyMD5T = Aws::String>
    void SetSSECustomerKeyMD5(SSECustomerKeyMD5T&& value) { m_sSECustomerKeyMD5HasBeenSet = true; m_sSECustomerKeyMD5 = std::forward<SSECustomerKeyMD5T>(value); }
    template<typename SSECustomerKeyMD5T = Aws::String>
    CopyObjectRequest& WithSSECustomerKeyMD5(SSECustomerKeyMD5T&& value) { SetSSECustomerKeyMD5(std::forward<SSECustomerKeyMD5T>(value)); return *this;}
    ///@}

    ///@{
    /**
     * <p>Specifies the KMS key ID (Key ID, Key ARN, or Key Alias) to use for object
     * encryption. All GET and PUT requests for an object protected by KMS will fail if
     * they're not made via SSL or using SigV4. For information about configuring any
     * of the officially supported Amazon Web Services SDKs and Amazon Web Services
     * CLI, see <a
     * href="https://docs.aws.amazon.com/AmazonS3/latest/dev/UsingAWSSDK.html#specify-signature-version">Specifying
     * the Signature Version in Request Authentication</a> in the <i>Amazon S3 User
     * Guide</i>.</p> <p> <b>Directory buckets</b> - To encrypt data using SSE-KMS,
     * it's recommended to specify the <code>x-amz-server-side-encryption</code> header
     * to <code>aws:kms</code>. Then, the
     * <code>x-amz-server-side-encryption-aws-kms-key-id</code> header implicitly uses
     * the bucket's default KMS customer managed key ID. If you want to explicitly set
     * the <code> x-amz-server-side-encryption-aws-kms-key-id</code> header, it must
     * match the bucket's default customer managed key (using key ID or ARN, not
     * alias). Your SSE-KMS configuration can only support 1 <a
     * href="https://docs.aws.amazon.com/kms/latest/developerguide/concepts.html#customer-cmk">customer
     * managed key</a> per directory bucket's lifetime. The <a
     * href="https://docs.aws.amazon.com/kms/latest/developerguide/concepts.html#aws-managed-cmk">Amazon
     * Web Services managed key</a> (<code>aws/s3</code>) isn't supported. Incorrect
     * key specification results in an HTTP <code>400 Bad Request</code> error. </p>
     */
    inline const Aws::String& GetSSEKMSKeyId() const { return m_sSEKMSKeyId; }
    inline bool SSEKMSKeyIdHasBeenSet() const { return m_sSEKMSKeyIdHasBeenSet; }
    template<typename SSEKMSKeyIdT = Aws::String>
    void SetSSEKMSKeyId(SSEKMSKeyIdT&& value) { m_sSEKMSKeyIdHasBeenSet = true; m_sSEKMSKeyId = std::forward<SSEKMSKeyIdT>(value); }
    template<typename SSEKMSKeyIdT = Aws::String>
    CopyObjectRequest& WithSSEKMSKeyId(SSEKMSKeyIdT&& value) { SetSSEKMSKeyId(std::forward<SSEKMSKeyIdT>(value)); return *this;}
    ///@}

    ///@{
    /**
     * <p>Specifies the Amazon Web Services KMS Encryption Context as an additional
     * encryption context to use for the destination object encryption. The value of
     * this header is a base64-encoded UTF-8 string holding JSON with the encryption
     * context key-value pairs.</p> <p> <b>General purpose buckets</b> - This value
     * must be explicitly added to specify encryption context for
     * <code>CopyObject</code> requests if you want an additional encryption context
     * for your destination object. The additional encryption context of the source
     * object won't be copied to the destination object. For more information, see <a
     * href="https://docs.aws.amazon.com/AmazonS3/latest/userguide/UsingKMSEncryption.html#encryption-context">Encryption
     * context</a> in the <i>Amazon S3 User Guide</i>.</p> <p> <b>Directory buckets</b>
     * - You can optionally provide an explicit encryption context value. The value
     * must match the default encryption context - the bucket Amazon Resource Name
     * (ARN). An additional encryption context value is not supported. </p>
     */
    inline const Aws::String& GetSSEKMSEncryptionContext() const { return m_sSEKMSEncryptionContext; }
    inline bool SSEKMSEncryptionContextHasBeenSet() const { return m_sSEKMSEncryptionContextHasBeenSet; }
    template<typename SSEKMSEncryptionContextT = Aws::String>
    void SetSSEKMSEncryptionContext(SSEKMSEncryptionContextT&& value) { m_sSEKMSEncryptionContextHasBeenSet = true; m_sSEKMSEncryptionContext = std::forward<SSEKMSEncryptionContextT>(value); }
    template<typename SSEKMSEncryptionContextT = Aws::String>
    CopyObjectRequest& WithSSEKMSEncryptionContext(SSEKMSEncryptionContextT&& value) { SetSSEKMSEncryptionContext(std::forward<SSEKMSEncryptionContextT>(value)); return *this;}
    ///@}

    ///@{
    /**
     * <p>Specifies whether Amazon S3 should use an S3 Bucket Key for object encryption
     * with server-side encryption using Key Management Service (KMS) keys (SSE-KMS).
     * If a target object uses SSE-KMS, you can enable an S3 Bucket Key for the
     * object.</p> <p>Setting this header to <code>true</code> causes Amazon S3 to use
     * an S3 Bucket Key for object encryption with SSE-KMS. Specifying this header with
     * a COPY action doesn’t affect bucket-level settings for S3 Bucket Key.</p> <p>For
     * more information, see <a
     * href="https://docs.aws.amazon.com/AmazonS3/latest/dev/bucket-key.html">Amazon S3
     * Bucket Keys</a> in the <i>Amazon S3 User Guide</i>.</p>  <p> <b>Directory
     * buckets</b> - S3 Bucket Keys aren't supported, when you copy SSE-KMS encrypted
     * objects from general purpose buckets to directory buckets, from directory
     * buckets to general purpose buckets, or between directory buckets, through <a
     * href="https://docs.aws.amazon.com/AmazonS3/latest/API/API_CopyObject.html">CopyObject</a>.
     * In this case, Amazon S3 makes a call to KMS every time a copy request is made
     * for a KMS-encrypted object.</p> 
     */
    inline bool GetBucketKeyEnabled() const { return m_bucketKeyEnabled; }
    inline bool BucketKeyEnabledHasBeenSet() const { return m_bucketKeyEnabledHasBeenSet; }
    inline void SetBucketKeyEnabled(bool value) { m_bucketKeyEnabledHasBeenSet = true; m_bucketKeyEnabled = value; }
    inline CopyObjectRequest& WithBucketKeyEnabled(bool value) { SetBucketKeyEnabled(value); return *this;}
    ///@}

    ///@{
    /**
     * <p>Specifies the algorithm to use when decrypting the source object (for
     * example, <code>AES256</code>).</p> <p>If the source object for the copy is
     * stored in Amazon S3 using SSE-C, you must provide the necessary encryption
     * information in your request so that Amazon S3 can decrypt the object for
     * copying.</p>  <p>This functionality is not supported when the source
     * object is in a directory bucket.</p> 
     */
    inline const Aws::String& GetCopySourceSSECustomerAlgorithm() const { return m_copySourceSSECustomerAlgorithm; }
    inline bool CopySourceSSECustomerAlgorithmHasBeenSet() const { return m_copySourceSSECustomerAlgorithmHasBeenSet; }
    template<typename CopySourceSSECustomerAlgorithmT = Aws::String>
    void SetCopySourceSSECustomerAlgorithm(CopySourceSSECustomerAlgorithmT&& value) { m_copySourceSSECustomerAlgorithmHasBeenSet = true; m_copySourceSSECustomerAlgorithm = std::forward<CopySourceSSECustomerAlgorithmT>(value); }
    template<typename CopySourceSSECustomerAlgorithmT = Aws::String>
    CopyObjectRequest& WithCopySourceSSECustomerAlgorithm(CopySourceSSECustomerAlgorithmT&& value) { SetCopySourceSSECustomerAlgorithm(std::forward<CopySourceSSECustomerAlgorithmT>(value)); return *this;}
    ///@}

    ///@{
    /**
     * <p>Specifies the customer-provided encryption key for Amazon S3 to use to
     * decrypt the source object. The encryption key provided in this header must be
     * the same one that was used when the source object was created.</p> <p>If the
     * source object for the copy is stored in Amazon S3 using SSE-C, you must provide
     * the necessary encryption information in your request so that Amazon S3 can
     * decrypt the object for copying.</p>  <p>This functionality is not
     * supported when the source object is in a directory bucket.</p> 
     */
    inline const Aws::String& GetCopySourceSSECustomerKey() const { return m_copySourceSSECustomerKey; }
    inline bool CopySourceSSECustomerKeyHasBeenSet() const { return m_copySourceSSECustomerKeyHasBeenSet; }
    template<typename CopySourceSSECustomerKeyT = Aws::String>
    void SetCopySourceSSECustomerKey(CopySourceSSECustomerKeyT&& value) { m_copySourceSSECustomerKeyHasBeenSet = true; m_copySourceSSECustomerKey = std::forward<CopySourceSSECustomerKeyT>(value); }
    template<typename CopySourceSSECustomerKeyT = Aws::String>
    CopyObjectRequest& WithCopySourceSSECustomerKey(CopySourceSSECustomerKeyT&& value) { SetCopySourceSSECustomerKey(std::forward<CopySourceSSECustomerKeyT>(value)); return *this;}
    ///@}

    ///@{
    /**
     * <p>Specifies the 128-bit MD5 digest of the encryption key according to RFC 1321.
     * Amazon S3 uses this header for a message integrity check to ensure that the
     * encryption key was transmitted without error.</p> <p>If the source object for
     * the copy is stored in Amazon S3 using SSE-C, you must provide the necessary
     * encryption information in your request so that Amazon S3 can decrypt the object
     * for copying.</p>  <p>This functionality is not supported when the source
     * object is in a directory bucket.</p> 
     */
    inline const Aws::String& GetCopySourceSSECustomerKeyMD5() const { return m_copySourceSSECustomerKeyMD5; }
    inline bool CopySourceSSECustomerKeyMD5HasBeenSet() const { return m_copySourceSSECustomerKeyMD5HasBeenSet; }
    template<typename CopySourceSSECustomerKeyMD5T = Aws::String>
    void SetCopySourceSSECustomerKeyMD5(CopySourceSSECustomerKeyMD5T&& value) { m_copySourceSSECustomerKeyMD5HasBeenSet = true; m_copySourceSSECustomerKeyMD5 = std::forward<CopySourceSSECustomerKeyMD5T>(value); }
    template<typename CopySourceSSECustomerKeyMD5T = Aws::String>
    CopyObjectRequest& WithCopySourceSSECustomerKeyMD5(CopySourceSSECustomerKeyMD5T&& value) { SetCopySourceSSECustomerKeyMD5(std::forward<CopySourceSSECustomerKeyMD5T>(value)); return *this;}
    ///@}

    ///@{
    
    inline RequestPayer GetRequestPayer() const { return m_requestPayer; }
    inline bool RequestPayerHasBeenSet() const { return m_requestPayerHasBeenSet; }
    inline void SetRequestPayer(RequestPayer value) { m_requestPayerHasBeenSet = true; m_requestPayer = value; }
    inline CopyObjectRequest& WithRequestPayer(RequestPayer value) { SetRequestPayer(value); return *this;}
    ///@}

    ///@{
    /**
     * <p>The tag-set for the object copy in the destination bucket. This value must be
     * used in conjunction with the <code>x-amz-tagging-directive</code> if you choose
     * <code>REPLACE</code> for the <code>x-amz-tagging-directive</code>. If you choose
     * <code>COPY</code> for the <code>x-amz-tagging-directive</code>, you don't need
     * to set the <code>x-amz-tagging</code> header, because the tag-set will be copied
     * from the source object directly. The tag-set must be encoded as URL Query
     * parameters.</p> <p>The default value is the empty value.</p>  <p>
     * <b>Directory buckets</b> - For directory buckets in a <code>CopyObject</code>
     * operation, only the empty tag-set is supported. Any requests that attempt to
     * write non-empty tags into directory buckets will receive a <code>501 Not
     * Implemented</code> status code. When the destination bucket is a directory
     * bucket, you will receive a <code>501 Not Implemented</code> response in any of
     * the following situations:</p> <ul> <li> <p>When you attempt to <code>COPY</code>
     * the tag-set from an S3 source object that has non-empty tags.</p> </li> <li>
     * <p>When you attempt to <code>REPLACE</code> the tag-set of a source object and
     * set a non-empty value to <code>x-amz-tagging</code>.</p> </li> <li> <p>When you
     * don't set the <code>x-amz-tagging-directive</code> header and the source object
     * has non-empty tags. This is because the default value of
     * <code>x-amz-tagging-directive</code> is <code>COPY</code>.</p> </li> </ul>
     * <p>Because only the empty tag-set is supported for directory buckets in a
     * <code>CopyObject</code> operation, the following situations are allowed:</p>
     * <ul> <li> <p>When you attempt to <code>COPY</code> the tag-set from a directory
     * bucket source object that has no tags to a general purpose bucket. It copies an
     * empty tag-set to the destination object.</p> </li> <li> <p>When you attempt to
     * <code>REPLACE</code> the tag-set of a directory bucket source object and set the
     * <code>x-amz-tagging</code> value of the directory bucket destination object to
     * empty.</p> </li> <li> <p>When you attempt to <code>REPLACE</code> the tag-set of
     * a general purpose bucket source object that has non-empty tags and set the
     * <code>x-amz-tagging</code> value of the directory bucket destination object to
     * empty.</p> </li> <li> <p>When you attempt to <code>REPLACE</code> the tag-set of
     * a directory bucket source object and don't set the <code>x-amz-tagging</code>
     * value of the directory bucket destination object. This is because the default
     * value of <code>x-amz-tagging</code> is the empty value.</p> </li> </ul> 
     */
    inline const Aws::String& GetTagging() const { return m_tagging; }
    inline bool TaggingHasBeenSet() const { return m_taggingHasBeenSet; }
    template<typename TaggingT = Aws::String>
    void SetTagging(TaggingT&& value) { m_taggingHasBeenSet = true; m_tagging = std::forward<TaggingT>(value); }
    template<typename TaggingT = Aws::String>
    CopyObjectRequest& WithTagging(TaggingT&& value) { SetTagging(std::forward<TaggingT>(value)); return *this;}
    ///@}

    ///@{
    /**
     * <p>The Object Lock mode that you want to apply to the object copy.</p> 
     * <p>This functionality is not supported for directory buckets.</p> 
     */
    inline ObjectLockMode GetObjectLockMode() const { return m_objectLockMode; }
    inline bool ObjectLockModeHasBeenSet() const { return m_objectLockModeHasBeenSet; }
    inline void SetObjectLockMode(ObjectLockMode value) { m_objectLockModeHasBeenSet = true; m_objectLockMode = value; }
    inline CopyObjectRequest& WithObjectLockMode(ObjectLockMode value) { SetObjectLockMode(value); return *this;}
    ///@}

    ///@{
    /**
     * <p>The date and time when you want the Object Lock of the object copy to
     * expire.</p>  <p>This functionality is not supported for directory
     * buckets.</p> 
     */
    inline const Aws::Utils::DateTime& GetObjectLockRetainUntilDate() const { return m_objectLockRetainUntilDate; }
    inline bool ObjectLockRetainUntilDateHasBeenSet() const { return m_objectLockRetainUntilDateHasBeenSet; }
    template<typename ObjectLockRetainUntilDateT = Aws::Utils::DateTime>
    void SetObjectLockRetainUntilDate(ObjectLockRetainUntilDateT&& value) { m_objectLockRetainUntilDateHasBeenSet = true; m_objectLockRetainUntilDate = std::forward<ObjectLockRetainUntilDateT>(value); }
    template<typename ObjectLockRetainUntilDateT = Aws::Utils::DateTime>
    CopyObjectRequest& WithObjectLockRetainUntilDate(ObjectLockRetainUntilDateT&& value) { SetObjectLockRetainUntilDate(std::forward<ObjectLockRetainUntilDateT>(value)); return *this;}
    ///@}

    ///@{
    /**
     * <p>Specifies whether you want to apply a legal hold to the object copy.</p>
     *  <p>This functionality is not supported for directory buckets.</p> 
     */
    inline ObjectLockLegalHoldStatus GetObjectLockLegalHoldStatus() const { return m_objectLockLegalHoldStatus; }
    inline bool ObjectLockLegalHoldStatusHasBeenSet() const { return m_objectLockLegalHoldStatusHasBeenSet; }
    inline void SetObjectLockLegalHoldStatus(ObjectLockLegalHoldStatus value) { m_objectLockLegalHoldStatusHasBeenSet = true; m_objectLockLegalHoldStatus = value; }
    inline CopyObjectRequest& WithObjectLockLegalHoldStatus(ObjectLockLegalHoldStatus value) { SetObjectLockLegalHoldStatus(value); return *this;}
    ///@}

    ///@{
    /**
     * <p>The account ID of the expected destination bucket owner. If the account ID
     * that you provide does not match the actual owner of the destination bucket, the
     * request fails with the HTTP status code <code>403 Forbidden</code> (access
     * denied).</p>
     */
    inline const Aws::String& GetExpectedBucketOwner() const { return m_expectedBucketOwner; }
    inline bool ExpectedBucketOwnerHasBeenSet() const { return m_expectedBucketOwnerHasBeenSet; }
    template<typename ExpectedBucketOwnerT = Aws::String>
    void SetExpectedBucketOwner(ExpectedBucketOwnerT&& value) { m_expectedBucketOwnerHasBeenSet = true; m_expectedBucketOwner = std::forward<ExpectedBucketOwnerT>(value); }
    template<typename ExpectedBucketOwnerT = Aws::String>
    CopyObjectRequest& WithExpectedBucketOwner(ExpectedBucketOwnerT&& value) { SetExpectedBucketOwner(std::forward<ExpectedBucketOwnerT>(value)); return *this;}
    ///@}

    ///@{
    /**
     * <p>The account ID of the expected source bucket owner. If the account ID that
     * you provide does not match the actual owner of the source bucket, the request
     * fails with the HTTP status code <code>403 Forbidden</code> (access denied).</p>
     */
    inline const Aws::String& GetExpectedSourceBucketOwner() const { return m_expectedSourceBucketOwner; }
    inline bool ExpectedSourceBucketOwnerHasBeenSet() const { return m_expectedSourceBucketOwnerHasBeenSet; }
    template<typename ExpectedSourceBucketOwnerT = Aws::String>
    void SetExpectedSourceBucketOwner(ExpectedSourceBucketOwnerT&& value) { m_expectedSourceBucketOwnerHasBeenSet = true; m_expectedSourceBucketOwner = std::forward<ExpectedSourceBucketOwnerT>(value); }
    template<typename ExpectedSourceBucketOwnerT = Aws::String>
    CopyObjectRequest& WithExpectedSourceBucketOwner(ExpectedSourceBucketOwnerT&& value) { SetExpectedSourceBucketOwner(std::forward<ExpectedSourceBucketOwnerT>(value)); return *this;}
    ///@}

    ///@{
    
    inline const Aws::Map<Aws::String, Aws::String>& GetCustomizedAccessLogTag() const { return m_customizedAccessLogTag; }
    inline bool CustomizedAccessLogTagHasBeenSet() const { return m_customizedAccessLogTagHasBeenSet; }
    template<typename CustomizedAccessLogTagT = Aws::Map<Aws::String, Aws::String>>
    void SetCustomizedAccessLogTag(CustomizedAccessLogTagT&& value) { m_customizedAccessLogTagHasBeenSet = true; m_customizedAccessLogTag = std::forward<CustomizedAccessLogTagT>(value); }
    template<typename CustomizedAccessLogTagT = Aws::Map<Aws::String, Aws::String>>
    CopyObjectRequest& WithCustomizedAccessLogTag(CustomizedAccessLogTagT&& value) { SetCustomizedAccessLogTag(std::forward<CustomizedAccessLogTagT>(value)); return *this;}
    template<typename CustomizedAccessLogTagKeyT = Aws::String, typename CustomizedAccessLogTagValueT = Aws::String>
    CopyObjectRequest& AddCustomizedAccessLogTag(CustomizedAccessLogTagKeyT&& key, CustomizedAccessLogTagValueT&& value) {
      m_customizedAccessLogTagHasBeenSet = true; m_customizedAccessLogTag.emplace(std::forward<CustomizedAccessLogTagKeyT>(key), std::forward<CustomizedAccessLogTagValueT>(value)); return *this;
    }
    ///@}
  private:

    ObjectCannedACL m_aCL{ObjectCannedACL::NOT_SET};
    bool m_aCLHasBeenSet = false;

    Aws::String m_bucket;
    bool m_bucketHasBeenSet = false;

    Aws::String m_cacheControl;
    bool m_cacheControlHasBeenSet = false;

    ChecksumAlgorithm m_checksumAlgorithm{ChecksumAlgorithm::NOT_SET};
    bool m_checksumAlgorithmHasBeenSet = false;

    Aws::String m_contentDisposition;
    bool m_contentDispositionHasBeenSet = false;

    Aws::String m_contentEncoding;
    bool m_contentEncodingHasBeenSet = false;

    Aws::String m_contentLanguage;
    bool m_contentLanguageHasBeenSet = false;

    Aws::String m_contentType;
    bool m_contentTypeHasBeenSet = false;

    Aws::String m_copySource;
    bool m_copySourceHasBeenSet = false;

    Aws::String m_copySourceIfMatch;
    bool m_copySourceIfMatchHasBeenSet = false;

    Aws::Utils::DateTime m_copySourceIfModifiedSince{};
    bool m_copySourceIfModifiedSinceHasBeenSet = false;

    Aws::String m_copySourceIfNoneMatch;
    bool m_copySourceIfNoneMatchHasBeenSet = false;

    Aws::Utils::DateTime m_copySourceIfUnmodifiedSince{};
    bool m_copySourceIfUnmodifiedSinceHasBeenSet = false;

    Aws::Utils::DateTime m_expires{};
    bool m_expiresHasBeenSet = false;

    Aws::String m_grantFullControl;
    bool m_grantFullControlHasBeenSet = false;

    Aws::String m_grantRead;
    bool m_grantReadHasBeenSet = false;

    Aws::String m_grantReadACP;
    bool m_grantReadACPHasBeenSet = false;

    Aws::String m_grantWriteACP;
    bool m_grantWriteACPHasBeenSet = false;

    Aws::String m_key;
    bool m_keyHasBeenSet = false;

    Aws::Map<Aws::String, Aws::String> m_metadata;
    bool m_metadataHasBeenSet = false;

    MetadataDirective m_metadataDirective{MetadataDirective::NOT_SET};
    bool m_metadataDirectiveHasBeenSet = false;

    TaggingDirective m_taggingDirective{TaggingDirective::NOT_SET};
    bool m_taggingDirectiveHasBeenSet = false;

    ServerSideEncryption m_serverSideEncryption{ServerSideEncryption::NOT_SET};
    bool m_serverSideEncryptionHasBeenSet = false;

    StorageClass m_storageClass{StorageClass::NOT_SET};
    bool m_storageClassHasBeenSet = false;

    Aws::String m_websiteRedirectLocation;
    bool m_websiteRedirectLocationHasBeenSet = false;

    Aws::String m_sSECustomerAlgorithm;
    bool m_sSECustomerAlgorithmHasBeenSet = false;

    Aws::String m_sSECustomerKey;
    bool m_sSECustomerKeyHasBeenSet = false;

    Aws::String m_sSECustomerKeyMD5;
    bool m_sSECustomerKeyMD5HasBeenSet = false;

    Aws::String m_sSEKMSKeyId;
    bool m_sSEKMSKeyIdHasBeenSet = false;

    Aws::String m_sSEKMSEncryptionContext;
    bool m_sSEKMSEncryptionContextHasBeenSet = false;

    bool m_bucketKeyEnabled{false};
    bool m_bucketKeyEnabledHasBeenSet = false;

    Aws::String m_copySourceSSECustomerAlgorithm;
    bool m_copySourceSSECustomerAlgorithmHasBeenSet = false;

    Aws::String m_copySourceSSECustomerKey;
    bool m_copySourceSSECustomerKeyHasBeenSet = false;

    Aws::String m_copySourceSSECustomerKeyMD5;
    bool m_copySourceSSECustomerKeyMD5HasBeenSet = false;

    RequestPayer m_requestPayer{RequestPayer::NOT_SET};
    bool m_requestPayerHasBeenSet = false;

    Aws::String m_tagging;
    bool m_taggingHasBeenSet = false;

    ObjectLockMode m_objectLockMode{ObjectLockMode::NOT_SET};
    bool m_objectLockModeHasBeenSet = false;

    Aws::Utils::DateTime m_objectLockRetainUntilDate{};
    bool m_objectLockRetainUntilDateHasBeenSet = false;

    ObjectLockLegalHoldStatus m_objectLockLegalHoldStatus{ObjectLockLegalHoldStatus::NOT_SET};
    bool m_objectLockLegalHoldStatusHasBeenSet = false;

    Aws::String m_expectedBucketOwner;
    bool m_expectedBucketOwnerHasBeenSet = false;

    Aws::String m_expectedSourceBucketOwner;
    bool m_expectedSourceBucketOwnerHasBeenSet = false;

    Aws::Map<Aws::String, Aws::String> m_customizedAccessLogTag;
    bool m_customizedAccessLogTagHasBeenSet = false;
  };

} // namespace Model
} // namespace S3Crt
} // namespace Aws
