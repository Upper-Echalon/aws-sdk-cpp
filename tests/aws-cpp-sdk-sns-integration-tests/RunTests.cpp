//
// Created by Pulim, Snigdha on 7/31/25.
//
#include <gtest/gtest.h>
#include <aws/core/Aws.h>
#include <aws/testing/platform/PlatformTesting.h>
#include <aws/testing/TestingEnvironment.h>
#include <aws/testing/MemoryTesting.h>

int main(int argc, char** argv)
{
    Aws::Testing::SetDefaultSigPipeHandler();
    Aws::SDKOptions options;
    options.loggingOptions.logLevel = Aws::Utils::Logging::LogLevel::Trace;
    AWS_BEGIN_MEMORY_TEST_EX(options, 1024, 128);

    Aws::Testing::InitPlatformTest(options);
    Aws::Testing::ParseArgs(argc, argv);

    Aws::InitAPI(options);
    ::testing::InitGoogleTest(&argc, argv);
    int exitCode = RUN_ALL_TESTS();

    Aws::ShutdownAPI(options);
    AWS_END_MEMORY_TEST_EX;
    Aws::Testing::ShutdownPlatformTest(options);
    return exitCode;
}
