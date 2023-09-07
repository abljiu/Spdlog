#include <iostream>
#include <vector>
#include <thread>
#include <numeric>
#include "spdlog/spdlog.h"
#include "spdlog/sinks/basic_file_sink.h"
#include "spdlog/sinks/stdout_color_sinks.h"
#include "spdlog/fmt/bundled/ostream.h"

// 创建全局的日志器
auto consoleLogger = spdlog::stdout_color_mt("console");
auto fileLogger = spdlog::basic_logger_mt("file_logger", "logfile.txt");

// 线程函数，计算部分数组的平方和
void computeSum(const std::vector<int> &data, std::size_t start, std::size_t end, int &result)
{
    result = std::accumulate(data.begin() + start, data.begin() + end, 0,
                             [](int sum, int element)
                             { return sum + element * element; });

    // 使用日志器打印计算结果
    consoleLogger->info("Thread {}: Sum of squares in range [{}, {}]: {}", std::this_thread::get_id(), start, end, result);
}

int main()
{
    // 设置日志级别
    spdlog::set_level(spdlog::level::info);

    // 准备数据
    std::vector<int> data = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    std::size_t dataSize = data.size();

    // 定义线程数和任务大小
    const int numThreads = 4;
    std::size_t chunkSize = dataSize / numThreads;

    // 存储每个线程的计算结果
    std::vector<int> threadResults(numThreads);

    // 创建线程对象并计算部分和
    std::vector<std::thread> threads;
    for (int i = 0; i < numThreads; ++i)
    {
        std::size_t start = i * chunkSize;
        std::size_t end = (i == numThreads - 1) ? dataSize : start + chunkSize;

        threads.emplace_back(computeSum, std::ref(data), start, end, std::ref(threadResults[i]));
    }

    // 等待所有线程完成
    for (auto &thread : threads)
    {
        thread.join();
    }

    // 合并结果
    int totalSum = std::accumulate(threadResults.begin(), threadResults.end(), 0);

    consoleLogger->info("Total sum of squares: {}", totalSum);
    fileLogger->info("Total sum of squares: {}", totalSum);

    return 0;
}
