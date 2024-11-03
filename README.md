### Futurerestore-iOS

: [pxx917144686](https://github.com/pxx917144686)

---

## 什么是 FutureRestore？

FutureRestore 是允许手动指定要恢复的 SEP 和基带。这使得可以将  未签名的iOS固件  恢复到设备上，前提有 APTicket（SHSH2 文件）的备份；


## FutureRestore 详细介绍

### 1. 核心功能

- **手动恢复**：允许用户手动指定 SEP（Secure Enclave Processor）和基带，从而实现未签名固件的恢复。
- **兼容性**：支持将设备恢复到特定的固件版本，前提是用户有相应的 APTicket（SHSH Blobs）备份。
- **自定义恢复选项**：用户可以根据需要调整恢复过程中的多个参数，以实现更灵活的操作。
- **基于 ECID 和 APNonce 的恢复**：能够通过重新创建 APTicket 的必要条件（如 ECID、APNonce 和 Board ID）来进行恢复。

### 2. 常见参数

| 参数 (短) | 参数 (长)                          | 描述                                                                                           |
|-----------|-----------------------------------|------------------------------------------------------------------------------------------------|
| `-t`      | `--apticket PATH`                 | 指定用于恢复的 APTicket（SHSH Blobs）文件路径。                                            |
| `-u`      | `--update`                        | 进行更新而非擦除安装（需要合适的 APTicket）。                                              |
| `-w`      | `--wait`                          | 持续重启直到 ApNonce 与 APTicket 匹配（可能存在不可靠性）。                                 |
| `-d`      | `--debug`                         | 显示所有代码，使用此选项可以保存调试日志。                                                  |
| `-e`      | `--exit-recovery`                | 退出恢复模式并退出。                                                                          |
| `-c`      | `--custom-latest VERSION`        | 指定自定义最新版本用于 SEP、基带和其他 FirmwareUpdater 组件。                                 |
| `-i`      | `--custom-latest-beta`           | 从 beta 固件列表中获取自定义 URL。                                                            |
| `-k`      | `--custom-latest-ota`            | 从 OTA 固件列表中获取自定义 URL。                                                             |
| `-3`      | `--use-pwndfu`                   | 使用 Odysseus 方法恢复设备，设备需处于 pwned DFU 模式。                                      |
| `-0`      | `--latest-sep`                   | 使用最新签名的 SEP，而不是手动指定。                                                         |
| `-1`      | `--latest-baseband`              | 使用最新签名的基带，而不是手动指定。                                                         |
| `-2`      | `--no-baseband`                  | 跳过检查并不刷新基带，仅适用于没有基带的设备（例如 iPod touch 或仅 Wi-Fi 的 iPad）。       |


## 群

[FutureRestore for Discord](https://discord.com/invite/96wCSnwYVX)

---

### 安装依赖

#### 第一步：安装 libcurl 依赖

1. **安装 Homebrew**：
   ```bash
   /bin/bash -c "$(curl -fsSL https://raw.githubusercontent.com/Homebrew/install/HEAD/install.sh)"

2. **使用 Homebrew 安装 curl 库**：
   ```bash
   brew install curl

---

### **更新 PATH**：

#### 具体如下：

1. **终端执行命令**：
   ```bash
   echo 'export PATH="/usr/local/opt/curl/bin:$PATH"' >> ~/.zshrc

2. **设置编译器标志（使编译器能够找到 curl）**：
   ```bash
   export LDFLAGS="-L/usr/local/opt/curl/lib"
   export CPPFLAGS="-I/usr/local/opt/curl/include"

3. **设置 pkg-config 路径**：
   ```bash
   export PKG_CONFIG_PATH="/usr/local/opt/curl/lib/pkgconfig"


4. **使修改生效**：
   ```bash
   source ~/.zshrc

---

#### 第二步：下载 futurerestore-iOS

1. **克隆仓库**：
   ```bash
   git clone https://github.com/pxx917144686/Futurerestore-iOS.git
   
2. **进入目录**：
   ```bash
   cd Futurerestore-iOS

**使用 make 命令**
**编译 futurerestore.c，生成名为 futurerestore 的可执行文件**：
   ```bash
make

