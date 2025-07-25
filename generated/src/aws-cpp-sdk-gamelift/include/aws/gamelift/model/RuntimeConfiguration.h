﻿/**
 * Copyright Amazon.com, Inc. or its affiliates. All Rights Reserved.
 * SPDX-License-Identifier: Apache-2.0.
 */

#pragma once
#include <aws/gamelift/GameLift_EXPORTS.h>
#include <aws/core/utils/memory/stl/AWSVector.h>
#include <aws/gamelift/model/ServerProcess.h>
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
namespace GameLift
{
namespace Model
{

  /**
   * <p>A set of instructions that define the set of server processes to run on
   * computes in a fleet. Server processes run either an executable in a custom game
   * build or a Amazon GameLift Servers Realtime script. Amazon GameLift Servers
   * launches the processes, manages their life cycle, and replaces them as needed.
   * Computes check regularly for an updated runtime configuration. </p> <p>An Amazon
   * GameLift Servers instance is limited to 50 processes running concurrently. To
   * calculate the total number of processes defined in a runtime configuration, add
   * the values of the <code>ConcurrentExecutions</code> parameter for each server
   * process. Learn more about <a
   * href="https://docs.aws.amazon.com/gamelift/latest/developerguide/fleets-multiprocess.html">
   * Running Multiple Processes on a Fleet</a>.</p><p><h3>See Also:</h3>   <a
   * href="http://docs.aws.amazon.com/goto/WebAPI/gamelift-2015-10-01/RuntimeConfiguration">AWS
   * API Reference</a></p>
   */
  class RuntimeConfiguration
  {
  public:
    AWS_GAMELIFT_API RuntimeConfiguration() = default;
    AWS_GAMELIFT_API RuntimeConfiguration(Aws::Utils::Json::JsonView jsonValue);
    AWS_GAMELIFT_API RuntimeConfiguration& operator=(Aws::Utils::Json::JsonView jsonValue);
    AWS_GAMELIFT_API Aws::Utils::Json::JsonValue Jsonize() const;


    ///@{
    /**
     * <p>A collection of server process configurations that identify what server
     * processes to run on fleet computes.</p>
     */
    inline const Aws::Vector<ServerProcess>& GetServerProcesses() const { return m_serverProcesses; }
    inline bool ServerProcessesHasBeenSet() const { return m_serverProcessesHasBeenSet; }
    template<typename ServerProcessesT = Aws::Vector<ServerProcess>>
    void SetServerProcesses(ServerProcessesT&& value) { m_serverProcessesHasBeenSet = true; m_serverProcesses = std::forward<ServerProcessesT>(value); }
    template<typename ServerProcessesT = Aws::Vector<ServerProcess>>
    RuntimeConfiguration& WithServerProcesses(ServerProcessesT&& value) { SetServerProcesses(std::forward<ServerProcessesT>(value)); return *this;}
    template<typename ServerProcessesT = ServerProcess>
    RuntimeConfiguration& AddServerProcesses(ServerProcessesT&& value) { m_serverProcessesHasBeenSet = true; m_serverProcesses.emplace_back(std::forward<ServerProcessesT>(value)); return *this; }
    ///@}

    ///@{
    /**
     * <p>The number of game sessions in status <code>ACTIVATING</code> to allow on an
     * instance or compute. This setting limits the instance resources that can be used
     * for new game activations at any one time.</p>
     */
    inline int GetMaxConcurrentGameSessionActivations() const { return m_maxConcurrentGameSessionActivations; }
    inline bool MaxConcurrentGameSessionActivationsHasBeenSet() const { return m_maxConcurrentGameSessionActivationsHasBeenSet; }
    inline void SetMaxConcurrentGameSessionActivations(int value) { m_maxConcurrentGameSessionActivationsHasBeenSet = true; m_maxConcurrentGameSessionActivations = value; }
    inline RuntimeConfiguration& WithMaxConcurrentGameSessionActivations(int value) { SetMaxConcurrentGameSessionActivations(value); return *this;}
    ///@}

    ///@{
    /**
     * <p>The maximum amount of time (in seconds) allowed to launch a new game session
     * and have it report ready to host players. During this time, the game session is
     * in status <code>ACTIVATING</code>. If the game session does not become active
     * before the timeout, it is ended and the game session status is changed to
     * <code>TERMINATED</code>.</p>
     */
    inline int GetGameSessionActivationTimeoutSeconds() const { return m_gameSessionActivationTimeoutSeconds; }
    inline bool GameSessionActivationTimeoutSecondsHasBeenSet() const { return m_gameSessionActivationTimeoutSecondsHasBeenSet; }
    inline void SetGameSessionActivationTimeoutSeconds(int value) { m_gameSessionActivationTimeoutSecondsHasBeenSet = true; m_gameSessionActivationTimeoutSeconds = value; }
    inline RuntimeConfiguration& WithGameSessionActivationTimeoutSeconds(int value) { SetGameSessionActivationTimeoutSeconds(value); return *this;}
    ///@}
  private:

    Aws::Vector<ServerProcess> m_serverProcesses;
    bool m_serverProcessesHasBeenSet = false;

    int m_maxConcurrentGameSessionActivations{0};
    bool m_maxConcurrentGameSessionActivationsHasBeenSet = false;

    int m_gameSessionActivationTimeoutSeconds{0};
    bool m_gameSessionActivationTimeoutSecondsHasBeenSet = false;
  };

} // namespace Model
} // namespace GameLift
} // namespace Aws
