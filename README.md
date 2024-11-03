### Futurerestore-iOS   @ pxx917144686

---

## 什么是 FutureRestore？

FutureRestore 是一个经过修改的 idevicerestore 包装器，允许手动指定要恢复的 SEP 和基带。这使得可以将未签名的固件恢复到设备上，前提有 APTicket（SHSH2 文件）的备份；

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
   git clone https://github.com/thisiskeanyvy/futurerestore-downloader.git


2. **进入目录**：
   ```bash
   cd futurerestore



**使用 make 命令**
**编译 futurerestore.c，生成名为 futurerestore 的可执行文件**：
   ```bash
make

