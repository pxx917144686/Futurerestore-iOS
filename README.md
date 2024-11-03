futurerestore-iOS @ macOS @ pxx917144686

安装依赖
第一步：安装 libcurl 依赖
1.安装 Homebrew：/bin/bash -c "$(curl -fsSL https://raw.githubusercontent.com/Homebrew/install/HEAD/install.sh)"
2.使用 Homebrew 安装 curl 库：brew install curl


第二步：下载 futurerestore-iOS 仓库文件
1.克隆仓库并进入目录：
git clone https://github.com/thisiskeanyvy/futurerestore-downloader.git
cd futurerestore-iOS

执行 make 命令编译：
make






## 什么是 FutureRestore？
FutureRestore 是一个经过修改的 idevicerestore 包装器，允许手动指定要恢复的 SEP 和基带。这允许将未签名的固件恢复到设备上，前提是您有 APTicket（SHSH Blobs）的备份，并且可以重新创建 APTicket 的所有特定条件，例如 ECID、APNonce、Board ID。

# 支持
如需支持，请加入 Discord 上的 [FutureRestore 支持服务器](https://discord.com/invite/96wCSnwYVX)。

# 功能
* 支持以下降级方法：
* 适用于 64 位设备的 Prometheus：
- 通过使用 APNonce 生成器重新创建 APNonce 的 Prometheus
- 通过 APNonce 碰撞的 Prometheus
* 适用于 32 位和 64 位 (A7-A11) 设备的 Odysseus
* 使用 [alitek123](https://github.com/alitek12) 的 no-ApNonce 方法将 32 位设备重新恢复到 iOS 9.x（替代方案 — [idevicererestore](https://downgrade.party)）。

# 编译
请参阅 [COMPILING](COMPILING.md)
