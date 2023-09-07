# spdlog日志库

## 1.介绍

Spdlog是一个快速、异步、跨平台、易于使用的C++日志库，旨在提供高性能、易用性和灵活性。它支持多线程环境和异步记录，支持多种日志级别和多个后端（如控制台、文件、网络等），并提供灵活的日志格式化选项。

以下是Spdlog的一些主要特点：

1. 快速和异步记录：Spdlog使用内存映射文件和异步日志记录等技术，以提高日志记录的效率和性能。这意味着日志记录不会阻塞主线程，从而提高应用程序的吞吐量和响应速度。

2. 多线程支持：Spdlog支持多线程环境，并提供了线程安全的日志记录。它通过使用互斥锁来保护共享资源，从而避免了多线程并发访问的问题。

3. 多种日志级别：Spdlog支持多种日志级别，如trace、debug、info、warning、error和critical等。这些级别可以方便地控制日志记录的详细程度。

+ `trace`: 最低级别的日志，用于追踪程序的详细执行信息，通常用于调试目的。例如，函数的输入参数和返回值、代码执行路径等。

+ `debug`: 用于输出调试信息，辅助开发人员进行代码调试。比 `trace` 级别更详细，可以包含更多关于程序状态和变量的信息。

+ `info`: 用于输出一般性的信息，记录程序运行的关键事件和状态。例如，程序启动、连接数据库、加载配置等。

+ `warn`: 用于输出警告信息，表示潜在的问题或错误，但程序仍能正常运行。这些警告可能会影响程序的性能或结果。

+ `error`: 用于输出错误信息，表示程序发生了可恢复的错误。这些错误会导致程序运行异常，但通常可以通过处理来恢复正常。

+ `critical`: 最高级别的日志，用于输出严重的错误信息，表示程序遇到了无法继续运行的严重问题。这些问题可能导致程序崩溃或数据丢失。

4. 多个后端支持：Spdlog支持多个后端，包括控制台、文件、网络等。这些后端可以方便地进行配置和切换。

5. 灵活的格式化选项：Spdlog提供了灵活的日志格式化选项，可以定制化地满足不同需求。它支持使用格式化字符串和用户自定义格式化器等方式来格式化日志记录。

6. 跨平台支持：Spdlog可以在Windows、Linux、macOS等多个平台上运行，并提供了一致的API。这意味着可以轻松地将Spdlog集成到您的跨平台应用程序中。

## 2.如何使用

### 下载

+ 通过GitHub获取源代码：<https://github.com/gabime/spdlog/releases>

   在该页面上，可以找到Spdlog库的各个版本的源代码包，包括压缩文件和tarball。选择下载相应的版本，并将其解压到项目文件夹中。

+ 使用包管理器下载

   在Ubuntu系统中，可以使用以下命令安装Spdlog库：

   ```
   sudo apt-get install libspdlog-dev
   ```

### 安装

+ 首先将下载好的spdlog源代码解压缩到需要使用的目录下
+ 进入下载的spdlog目录

```
cd spdlog
```

+ 使用CMake进行构建和安装。创建一个构建目录，然后执行CMake命令：

```
mkdir build
cd build
cmake ..
make
sudo make install
```

+ 安装完成后，spdlog库将被安装到系统的默认位置。

## 3.常用函数

在spdlog库中，有一些常用的函数可用于进行日志记录和配置。以下是一些常见的spdlog函数：

1. **spdlog::info()/spdlog::debug()/spdlog::warn()/spdlog::error()**：这些函数用于记录不同级别的日志消息。例如，`spdlog::info("This is an info message")`会记录一条信息级别的日志消息。

2. **spdlog::set_level()**：该函数用于设置全局日志级别。可以通过传递 `spdlog::level::level_enum` 枚举值来设置不同的日志级别，如 `spdlog::set_level(spdlog::level::debug)` 将日志级别设置为调试。

3. **spdlog::set_pattern()**：该函数用于设置日志消息的格式模式。可以使用占位符来定义日志消息的输出格式，如 `%^[%Y-%m-%d %H:%M:%S.%e] [%n] [%l]%$ %v`。
  
   %^ 和 %$ 是用于设置终端颜色的特殊标记。[%Y-%m-%d %H:%M:%S.%e] 表示日期和时间信息，[%n] 表示日志记录器名称，[%l] 表示日志级别，%v 表示日志消息的内容。

4. **spdlog::set_default_logger()**：该函数用于设置默认的日志记录器。一旦设置了默认记录器，就可以使用全局的spdlog函数来记录日志，而无需传递记录器实例。例如，`spdlog::info("This is a message using the default logger")`。

5. **spdlog::stdout_color_mt()**：该函数创建一个输出到标准输出的多线程日志记录器。例如，`auto logger = spdlog::stdout_color_mt("console_logger")` 创建一个名为 "console_logger" 的记录器。

6. **spdlog::rotating_logger_mt()**：该函数创建一个多线程的日志记录器，可以将日志消息写入轮转的文件中。例如，`auto logger = spdlog::rotating_logger_mt("file_logger", "logs.log", 1024 * 1024 * 5, 3)` 创建一个名为 "file_logger" 的记录器，将日志消息写入名为 "logs.log" 的文件中，最大文件大小为 5MB，最多保留 3 个文件。

7. **spdlog::basic_logger_mt()**:该函数创建一个写入到文件的基本日志记录器。例如，`auto logger1 = spdlog::basic_logger_mt("basic_logger", "logs/basic-log.txt")`创建一个名为"basic_logger"的记录器，将日志消息写入名为"logs/basic-log.txt"的文件中。

```cpp
#include <spdlog/spdlog.h>
#include <spdlog/sinks/basic_file_sink.h>

int main() {
    // 设置日志级别为调试
    spdlog::set_level(spdlog::level::debug);

    // 设置日志消息的格式模式
    spdlog::set_pattern("%^[%Y-%m-%d %H:%M:%S.%e] [%n] [%l]%$ %v");

    // 创建一个输出到标准输出的多线程日志记录器
    auto console_logger = spdlog::stdout_color_mt("console_logger");

    // 创建一个写入到文件的日志记录器，最大文件大小为5MB，最多保留3个文件
    auto file_logger = spdlog::rotating_logger_mt("file_logger", "logs.log", 1024 * 1024 * 5, 3);

    // 设置默认的日志记录器
    spdlog::set_default_logger(console_logger);

    // 使用默认的日志记录器记录不同级别的日志消息
    spdlog::info("This is an info message");
    spdlog::debug("This is a debug message");
    spdlog::warn("This is a warning message");
    spdlog::error("This is an error message");

    // 使用特定的日志记录器记录日志消息
    console_logger->info("This is a message using the console_logger");
    file_logger->info("This is a message using the file_logger");

    return 0;
}
```

### 4.多线程安全

1. 互斥锁（Mutex）：spdlog 使用互斥锁来保护共享资源的访问。在进行日志记录操作时，每个线程会尝试获取互斥锁，并在操作完成后释放锁，从而确保同一时间只有一个线程可以访问共享资源，避免了数据竞争的问题。

2. 条件变量（Condition Variable）：spdlog 使用条件变量来实现异步日志记录的机制。当日志消息被写入队列后，后台线程会等待条件变量的通知，以确定何时处理队列中的消息。条件变量允许线程在等待时释放互斥锁，从而避免了不必要的锁竞争，提高了多线程并发处理日志的效率。

3. 原子操作（Atomic Operations）：spdlog 使用原子操作来确保对共享数据的原子性访问。原子操作是一种线程安全的操作，它可以保证在多线程环境下对共享数据的读取和写入操作不会导致数据不一致或竞争条件的发生。

## 5.spdlog是如何避免死锁的

1. 异步日志记录：
   `spdlog` 使用异步日志记录，这意味着在提交日志消息后，它会立即返回，而不会等待日志写入操作完成。这样可以避免可能导致死锁的潜在情况。在异步模式下，日志消息会被添加到一个内部的无锁队列中，而不会立即写入目标输出。

2. 无锁队列：
   `spdlog` 使用无锁队列来存储待写入的日志消息。无锁队列是一种线程安全的数据结构，允许多个线程并发地对其进行读取和写入，而无需显式的互斥锁。这减少了线程之间的锁竞争，提高了性能，并减少了潜在的死锁风险。

   在 `spdlog` 中，日志消息被添加到无锁队列中，这个过程不需要加锁。多个线程可以同时将消息添加到队列中，而不会发生死锁情况。后台线程会负责从队列中取出消息，并将其写入目标输出（如终端或文件）。

3. 后台线程：
   `spdlog` 在后台运行一个独立的线程，负责处理日志消息的写入。这个线程从无锁队列中获取待写入的日志消息，并将其写入目标输出。通过使用独立的线程来处理日志输出，可以减少与主要应用程序逻辑的竞争条件，从而进一步降低死锁的风险。

   后台线程在后台运行，不会阻塞主线程或其他线程的执行。这样，即使在高负载情况下，日志记录仍然可以以异步、高效的方式进行，而不会导致死锁或性能下降。
