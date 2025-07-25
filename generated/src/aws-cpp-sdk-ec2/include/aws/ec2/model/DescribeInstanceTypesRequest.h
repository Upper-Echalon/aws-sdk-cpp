﻿/**
 * Copyright Amazon.com, Inc. or its affiliates. All Rights Reserved.
 * SPDX-License-Identifier: Apache-2.0.
 */

#pragma once
#include <aws/ec2/EC2_EXPORTS.h>
#include <aws/ec2/EC2Request.h>
#include <aws/core/utils/memory/stl/AWSVector.h>
#include <aws/core/utils/memory/stl/AWSString.h>
#include <aws/ec2/model/InstanceType.h>
#include <aws/ec2/model/Filter.h>
#include <utility>

namespace Aws
{
namespace EC2
{
namespace Model
{

  /**
   */
  class DescribeInstanceTypesRequest : public EC2Request
  {
  public:
    AWS_EC2_API DescribeInstanceTypesRequest() = default;

    // Service request name is the Operation name which will send this request out,
    // each operation should has unique request name, so that we can get operation's name from this request.
    // Note: this is not true for response, multiple operations may have the same response name,
    // so we can not get operation's name from response.
    inline virtual const char* GetServiceRequestName() const override { return "DescribeInstanceTypes"; }

    AWS_EC2_API Aws::String SerializePayload() const override;

  protected:
    AWS_EC2_API void DumpBodyToUrl(Aws::Http::URI& uri ) const override;

  public:

    ///@{
    /**
     * <p>Checks whether you have the required permissions for the action, without
     * actually making the request, and provides an error response. If you have the
     * required permissions, the error response is <code>DryRunOperation</code>.
     * Otherwise, it is <code>UnauthorizedOperation</code>.</p>
     */
    inline bool GetDryRun() const { return m_dryRun; }
    inline bool DryRunHasBeenSet() const { return m_dryRunHasBeenSet; }
    inline void SetDryRun(bool value) { m_dryRunHasBeenSet = true; m_dryRun = value; }
    inline DescribeInstanceTypesRequest& WithDryRun(bool value) { SetDryRun(value); return *this;}
    ///@}

    ///@{
    /**
     * <p>The instance types.</p>
     */
    inline const Aws::Vector<InstanceType>& GetInstanceTypes() const { return m_instanceTypes; }
    inline bool InstanceTypesHasBeenSet() const { return m_instanceTypesHasBeenSet; }
    template<typename InstanceTypesT = Aws::Vector<InstanceType>>
    void SetInstanceTypes(InstanceTypesT&& value) { m_instanceTypesHasBeenSet = true; m_instanceTypes = std::forward<InstanceTypesT>(value); }
    template<typename InstanceTypesT = Aws::Vector<InstanceType>>
    DescribeInstanceTypesRequest& WithInstanceTypes(InstanceTypesT&& value) { SetInstanceTypes(std::forward<InstanceTypesT>(value)); return *this;}
    inline DescribeInstanceTypesRequest& AddInstanceTypes(InstanceType value) { m_instanceTypesHasBeenSet = true; m_instanceTypes.push_back(value); return *this; }
    ///@}

    ///@{
    /**
     * <p>One or more filters. Filter names and values are case-sensitive.</p> <ul>
     * <li> <p> <code>auto-recovery-supported</code> - Indicates whether Amazon
     * CloudWatch action based recovery is supported (<code>true</code> |
     * <code>false</code>).</p> </li> <li> <p> <code>bare-metal</code> - Indicates
     * whether it is a bare metal instance type (<code>true</code> |
     * <code>false</code>).</p> </li> <li> <p>
     * <code>burstable-performance-supported</code> - Indicates whether the instance
     * type is a burstable performance T instance type (<code>true</code> |
     * <code>false</code>).</p> </li> <li> <p> <code>current-generation</code> -
     * Indicates whether this instance type is the latest generation instance type of
     * an instance family (<code>true</code> | <code>false</code>).</p> </li> <li> <p>
     * <code>dedicated-hosts-supported</code> - Indicates whether the instance type
     * supports Dedicated Hosts. (<code>true</code> | <code>false</code>)</p> </li>
     * <li> <p> <code>ebs-info.ebs-optimized-info.baseline-bandwidth-in-mbps</code> -
     * The baseline bandwidth performance for an EBS-optimized instance type, in
     * Mbps.</p> </li> <li> <p> <code>ebs-info.ebs-optimized-info.baseline-iops</code>
     * - The baseline input/output storage operations per second for an EBS-optimized
     * instance type.</p> </li> <li> <p>
     * <code>ebs-info.ebs-optimized-info.baseline-throughput-in-mbps</code> - The
     * baseline throughput performance for an EBS-optimized instance type, in MB/s.</p>
     * </li> <li> <p>
     * <code>ebs-info.ebs-optimized-info.maximum-bandwidth-in-mbps</code> - The maximum
     * bandwidth performance for an EBS-optimized instance type, in Mbps.</p> </li>
     * <li> <p> <code>ebs-info.ebs-optimized-info.maximum-iops</code> - The maximum
     * input/output storage operations per second for an EBS-optimized instance
     * type.</p> </li> <li> <p>
     * <code>ebs-info.ebs-optimized-info.maximum-throughput-in-mbps</code> - The
     * maximum throughput performance for an EBS-optimized instance type, in MB/s.</p>
     * </li> <li> <p> <code>ebs-info.ebs-optimized-support</code> - Indicates whether
     * the instance type is EBS-optimized (<code>supported</code> |
     * <code>unsupported</code> | <code>default</code>).</p> </li> <li> <p>
     * <code>ebs-info.encryption-support</code> - Indicates whether EBS encryption is
     * supported (<code>supported</code> | <code>unsupported</code>).</p> </li> <li>
     * <p> <code>ebs-info.nvme-support</code> - Indicates whether non-volatile memory
     * express (NVMe) is supported for EBS volumes (<code>required</code> |
     * <code>supported</code> | <code>unsupported</code>).</p> </li> <li> <p>
     * <code>free-tier-eligible</code> - A Boolean that indicates whether this instance
     * type can be used under the Amazon Web Services Free Tier (<code>true</code> |
     * <code>false</code>).</p> </li> <li> <p> <code>hibernation-supported</code> -
     * Indicates whether On-Demand hibernation is supported (<code>true</code> |
     * <code>false</code>).</p> </li> <li> <p> <code>hypervisor</code> - The hypervisor
     * (<code>nitro</code> | <code>xen</code>).</p> </li> <li> <p>
     * <code>instance-storage-info.disk.count</code> - The number of local disks.</p>
     * </li> <li> <p> <code>instance-storage-info.disk.size-in-gb</code> - The storage
     * size of each instance storage disk, in GB.</p> </li> <li> <p>
     * <code>instance-storage-info.disk.type</code> - The storage technology for the
     * local instance storage disks (<code>hdd</code> | <code>ssd</code>).</p> </li>
     * <li> <p> <code>instance-storage-info.encryption-support</code> - Indicates
     * whether data is encrypted at rest (<code>required</code> |
     * <code>supported</code> | <code>unsupported</code>).</p> </li> <li> <p>
     * <code>instance-storage-info.nvme-support</code> - Indicates whether non-volatile
     * memory express (NVMe) is supported for instance store (<code>required</code> |
     * <code>supported</code> | <code>unsupported</code>).</p> </li> <li> <p>
     * <code>instance-storage-info.total-size-in-gb</code> - The total amount of
     * storage available from all local instance storage, in GB.</p> </li> <li> <p>
     * <code>instance-storage-supported</code> - Indicates whether the instance type
     * has local instance storage (<code>true</code> | <code>false</code>).</p> </li>
     * <li> <p> <code>instance-type</code> - The instance type (for example
     * <code>c5.2xlarge</code> or c5*).</p> </li> <li> <p>
     * <code>memory-info.size-in-mib</code> - The memory size.</p> </li> <li> <p>
     * <code>network-info.bandwidth-weightings</code> - For instances that support
     * bandwidth weighting to boost performance (<code>default</code>,
     * <code>vpc-1</code>, <code>ebs-1</code>).</p> </li> <li> <p>
     * <code>network-info.efa-info.maximum-efa-interfaces</code> - The maximum number
     * of Elastic Fabric Adapters (EFAs) per instance.</p> </li> <li> <p>
     * <code>network-info.efa-supported</code> - Indicates whether the instance type
     * supports Elastic Fabric Adapter (EFA) (<code>true</code> |
     * <code>false</code>).</p> </li> <li> <p> <code>network-info.ena-support</code> -
     * Indicates whether Elastic Network Adapter (ENA) is supported or required
     * (<code>required</code> | <code>supported</code> | <code>unsupported</code>).</p>
     * </li> <li> <p> <code>network-info.flexible-ena-queues-support</code> - Indicates
     * whether an instance supports flexible ENA queues (<code>supported</code> |
     * <code>unsupported</code>).</p> </li> <li> <p>
     * <code>network-info.encryption-in-transit-supported</code> - Indicates whether
     * the instance type automatically encrypts in-transit traffic between instances
     * (<code>true</code> | <code>false</code>).</p> </li> <li> <p>
     * <code>network-info.ipv4-addresses-per-interface</code> - The maximum number of
     * private IPv4 addresses per network interface.</p> </li> <li> <p>
     * <code>network-info.ipv6-addresses-per-interface</code> - The maximum number of
     * private IPv6 addresses per network interface.</p> </li> <li> <p>
     * <code>network-info.ipv6-supported</code> - Indicates whether the instance type
     * supports IPv6 (<code>true</code> | <code>false</code>).</p> </li> <li> <p>
     * <code>network-info.maximum-network-cards</code> - The maximum number of network
     * cards per instance.</p> </li> <li> <p>
     * <code>network-info.maximum-network-interfaces</code> - The maximum number of
     * network interfaces per instance.</p> </li> <li> <p>
     * <code>network-info.network-performance</code> - The network performance (for
     * example, "25 Gigabit").</p> </li> <li> <p> <code>nitro-enclaves-support</code> -
     * Indicates whether Nitro Enclaves is supported (<code>supported</code> |
     * <code>unsupported</code>).</p> </li> <li> <p> <code>nitro-tpm-support</code> -
     * Indicates whether NitroTPM is supported (<code>supported</code> |
     * <code>unsupported</code>).</p> </li> <li> <p>
     * <code>nitro-tpm-info.supported-versions</code> - The supported NitroTPM version
     * (<code>2.0</code>).</p> </li> <li> <p>
     * <code>processor-info.supported-architecture</code> - The CPU architecture
     * (<code>arm64</code> | <code>i386</code> | <code>x86_64</code>).</p> </li> <li>
     * <p> <code>processor-info.sustained-clock-speed-in-ghz</code> - The CPU clock
     * speed, in GHz.</p> </li> <li> <p> <code>processor-info.supported-features</code>
     * - The supported CPU features (<code>amd-sev-snp</code>).</p> </li> <li> <p>
     * <code>reboot-migration-support</code> - Indicates whether enabling reboot
     * migration is supported (<code>supported</code> | <code>unsupported</code>).</p>
     * </li> <li> <p> <code>supported-boot-mode</code> - The boot mode
     * (<code>legacy-bios</code> | <code>uefi</code>).</p> </li> <li> <p>
     * <code>supported-root-device-type</code> - The root device type (<code>ebs</code>
     * | <code>instance-store</code>).</p> </li> <li> <p>
     * <code>supported-usage-class</code> - The usage class (<code>on-demand</code> |
     * <code>spot</code> | <code>capacity-block</code>).</p> </li> <li> <p>
     * <code>supported-virtualization-type</code> - The virtualization type
     * (<code>hvm</code> | <code>paravirtual</code>).</p> </li> <li> <p>
     * <code>vcpu-info.default-cores</code> - The default number of cores for the
     * instance type.</p> </li> <li> <p>
     * <code>vcpu-info.default-threads-per-core</code> - The default number of threads
     * per core for the instance type.</p> </li> <li> <p>
     * <code>vcpu-info.default-vcpus</code> - The default number of vCPUs for the
     * instance type.</p> </li> <li> <p> <code>vcpu-info.valid-cores</code> - The
     * number of cores that can be configured for the instance type.</p> </li> <li> <p>
     * <code>vcpu-info.valid-threads-per-core</code> - The number of threads per core
     * that can be configured for the instance type. For example, "1" or "1,2".</p>
     * </li> </ul>
     */
    inline const Aws::Vector<Filter>& GetFilters() const { return m_filters; }
    inline bool FiltersHasBeenSet() const { return m_filtersHasBeenSet; }
    template<typename FiltersT = Aws::Vector<Filter>>
    void SetFilters(FiltersT&& value) { m_filtersHasBeenSet = true; m_filters = std::forward<FiltersT>(value); }
    template<typename FiltersT = Aws::Vector<Filter>>
    DescribeInstanceTypesRequest& WithFilters(FiltersT&& value) { SetFilters(std::forward<FiltersT>(value)); return *this;}
    template<typename FiltersT = Filter>
    DescribeInstanceTypesRequest& AddFilters(FiltersT&& value) { m_filtersHasBeenSet = true; m_filters.emplace_back(std::forward<FiltersT>(value)); return *this; }
    ///@}

    ///@{
    /**
     * <p>The maximum number of items to return for this request. To get the next page
     * of items, make another request with the token returned in the output. For more
     * information, see <a
     * href="https://docs.aws.amazon.com/AWSEC2/latest/APIReference/Query-Requests.html#api-pagination">Pagination</a>.</p>
     */
    inline int GetMaxResults() const { return m_maxResults; }
    inline bool MaxResultsHasBeenSet() const { return m_maxResultsHasBeenSet; }
    inline void SetMaxResults(int value) { m_maxResultsHasBeenSet = true; m_maxResults = value; }
    inline DescribeInstanceTypesRequest& WithMaxResults(int value) { SetMaxResults(value); return *this;}
    ///@}

    ///@{
    /**
     * <p>The token returned from a previous paginated request. Pagination continues
     * from the end of the items returned by the previous request.</p>
     */
    inline const Aws::String& GetNextToken() const { return m_nextToken; }
    inline bool NextTokenHasBeenSet() const { return m_nextTokenHasBeenSet; }
    template<typename NextTokenT = Aws::String>
    void SetNextToken(NextTokenT&& value) { m_nextTokenHasBeenSet = true; m_nextToken = std::forward<NextTokenT>(value); }
    template<typename NextTokenT = Aws::String>
    DescribeInstanceTypesRequest& WithNextToken(NextTokenT&& value) { SetNextToken(std::forward<NextTokenT>(value)); return *this;}
    ///@}
  private:

    bool m_dryRun{false};
    bool m_dryRunHasBeenSet = false;

    Aws::Vector<InstanceType> m_instanceTypes;
    bool m_instanceTypesHasBeenSet = false;

    Aws::Vector<Filter> m_filters;
    bool m_filtersHasBeenSet = false;

    int m_maxResults{0};
    bool m_maxResultsHasBeenSet = false;

    Aws::String m_nextToken;
    bool m_nextTokenHasBeenSet = false;
  };

} // namespace Model
} // namespace EC2
} // namespace Aws
