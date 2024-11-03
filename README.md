futurerestore-iOS @ macOS @ pxx917144686
第一步：

安装 libcurl 依赖

安装 Homebrew ： /bin/bash -c "$(curl -fsSL https://raw.githubusercontent.com/Homebrew/install/HEAD/install.sh )"

安装 libcurl 依赖： 使用 Homebrew 安装curl 库：

brew安装curl

第二步

下载futurerestore-iOS仓​​库文件

cd futurerestore-iOS 文件夹执行：make

什么是 FutureRestore？
FutureRestore 是一个经过修改的 idevicerestore 包装器，允许手动指定要恢复的 SEP 和基带。这允许将未签名的固件恢复到设备上，前提是您有 APTicket（SHSH Blobs）的备份，并且可以重新创建 APTicket 的所有特定条件，例如 ECID、APNonce、Board ID。

支持
如需支持，请加入Discord 上的FutureRestore 支持服务器。

特征
支持以下降级方式：
适用于 64 位设备的 Prometheus：
Prometheus 通过使用 APNonce 生成器重建 APNonce
Prometheus 通过 APNonce 碰撞
适用于 32 位和 64 位 (A7-A11) 设备的 Odysseus
使用alitek123的 no-ApNonce 方法将 32 位设备重新恢复到 iOS 9.x （替代方案 - idevicererestore）。
编译
参见编译

Futurerestore 用法
用法：futurerestore [OPTIONS] iPSW

選擇 (簡單)	选项（长）	描述
-t	--apticket PATH		用于恢复的签名票，通常称为 blob
-u	--update	更新而不是删除安装（需要适当的 APTicket）
建议不要使用此参数进行降级。如果您已越狱，请确保恢复您的 orig-fs 快照（恢复 RootFS）。
-w	--wait	不断重启直到 ApNonce 与 APTicket 匹配（ApNonce 冲突，不可靠）
-d	--debug	显示所有代码，用于保存日志以供调试测试
-e	--exit-recovery	退出恢复模式并退出
-c	--custom-latest VERSION	指定用于 SEP、基带和其他 FirmwareUpdater 组件的自定义最新版本
-g	--custom-latest-buildid BUILDID	指定用于 SEP、基带和其他 FirmwareUpdater 组件的自定义最新 buildid
-i	--custom-latest-beta	从测试版固件列表中获取自定义 URL
-k	--custom-latest-ota	从 OTA 固件列表中获取自定义 URL
-3	--use-pwndfu	使用 Odysseus 方法恢复设备。设备需要已进入 DFU 模式
-4	--no-ibss	使用 Odysseus 方法恢复设备。具体来说，对于 checkm8/iPwnder32，bootrom 需要已使用 except iPwnder 进行修补。
-5	--rdsk PATH	设置自定义恢复 ramdisk 以进入恢复模式（需要使用-pwndfu）
-6	--rkrn PATH	设置自定义恢复内核缓存以进入恢复模式（需要使用-pwndfu）
-7	--set-nonce	从你的 blob 中设置自定义 nonce，然后退出恢复（需要使用 pwndfu）
-7	--set-nonce=0xNONCE	设置自定义随机数然后退出恢复（需要使用 pwndfu）
-8	--serial	在启动期间启用串行（需要串行电缆和使用 pwndfu）
-9	--boot-args "BOOTARGS"	设置自定义恢复启动参数（谨慎操作）（需要使用 pwndfu）
-a	--no-cache	禁用缓存的修补 iBSS/iBEC（需要使用 pwndfu）
-f	--skip-blob	跳过 SHSH blob 验证（谨慎继续）（需要使用 pwndfu）
-0	--latest-sep	使用最新签名的 SEP，而不是手动指定
-j	--no-rsep	选择不发送恢复模式 SEP 固件命令
-1	--latest-baseband	使用最新签名的基带，而不是手动指定一个
-2	--no-baseband	跳过检查并且不刷新基带
仅适用于没有基带的设备（例如 iPod touch 或仅支持 Wi-Fi 的 iPad）
已弃用/旧版选项：		
選擇 (簡單)	选项（长）	描述
-s	--sep PATH	手动指定要刷写的 SEP
-m	--sep-manifest PATH	用于申请 SEP 票证的 BuildManifest
-b	 --baseband PATH		手动指定要刷写的基带
-p	--baseband-manifest PATH	BuildManifest 用于请求基带票证
1）Prometheus（64 位设备）-使用生成器方法重新创建 APNonce
仅当满足以下条件时才可以降级：
目标固件版本与当前已签名的 SEP 和基带兼容。在此处检查您的版本是否兼容。
如果您有针对该特定固件版本的生成器的签名票证文件。
要求
允许设置随机数的越狱或漏洞利用。
使用生成器 签署票据文件（.shsh、.shsh2、 ）.plist
由于 nonce 纠缠，A12+ 用户还必须拥有有效的 APNonce/生成器对。仅有 APNonce 而没有生成器是不够的。
一台具有至少 8 GB 可用空间的计算机 + 下载的目标版本的 IPSW。您可以在IPSW.me上找到适合您设备的 IPSW 。
在 Windows 机器上，请确保安装了此版本的 iTunes。使用 Microsoft Store 版本会导致问题。
方法：
如果您的设备尚未越狱，请将其越狱。
在任何文本编辑器中打开您的 blob 并搜索单词“generator”。在大多数文本编辑器中，您可以使用 CTRL + F / CMD + F 来查找它。
生成器示例

它应该是0x后面跟着 16 个字符，是字母和数字的组合。
记下该值。这是您的生成器。

注意：如果没有生成器值，请尝试记住在保存 blob 时使用的是哪种越狱。如果您使用的是 unc0ver，则您的生成器最有可能是0x1111111111111111，如果您使用的是 Chimera/Odyssey/Taurine，则您的生成器最有可能是0xbd34a880be0b53f3。
设置设备的 APNonce 生成器。您可以使用越狱工具以原生设置设置生成器。不过，建议使用dimentio设置生成器。

以正常模式将您的设备连接到计算机 - 确保信任对话框被接受。

建议：在运行 Futurerestore 之前对您的设备进行完整备份。

在计算机上运行：

futurerestore -t blob.shsh2 --latest-sep --latest-baseband -d target.ipsw

如果您正在升级并且想要保留用户数据，您可以运行：

futurerestore -u -t blob.shsh2 --latest-sep --latest-baseband -d xxxxxxx.ipsw
