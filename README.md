# futurerestore-iOS  @ macOS @ pxx917144686

第一步：

安装 libcurl 依赖


安装 Homebrew ： 
/bin/bash -c "$(curl -fsSL https://raw.githubusercontent.com/Homebrew/install/HEAD/install.sh)"

安装 libcurl 依赖： 使用 Homebrew 安装 curl 库：

brew install curl



第二步

下载futurerestore-iOS  仓库文件

cd futurerestore-iOS文件夹
执行：make



## What is FutureRestore?
FutureRestore is a modified idevicerestore wrapper, which allows manually specifying SEP and Baseband for restoring. This allows unsigned firmwares to be restored onto devices, providing you have a backup of the APTicket (SHSH Blobs), and can recreate all the specific conditions of the APTicket e.g. ECID, APNonce, Board ID.

# Support
For support, join the [FutureRestore Support server](https://discord.com/invite/96wCSnwYVX) on Discord.

# Features  
* Supports the following downgrade methods:
  * Prometheus for 64-bit devices:
    - Prometheus via APNonce recreation with the APNonce generator
    - Prometheus via APNonce collision
  * Odysseus for 32-bit & 64-bit (A7-A11) devices
  * Re-restoring 32-bit devices to iOS 9.x with [alitek123](https://github.com/alitek12)'s no-ApNonce method (alternative — [idevicererestore](https://downgrade.party)).

# Compiling
See [COMPILING](COMPILING.md)


# Futurerestore Usage
Usage: `futurerestore [OPTIONS] iPSW`

| option (short) | option (long)                       | description                                                                                                                                             |
|----------------|-------------------------------------|---------------------------------------------------------------------------------------------------------------------------------------------------------|
| ` -t `         | ` --apticket PATH	 `                | Signing tickets used for restoring, commonly known as blobs                                                                                             |
| ` -u `         | ` --update `                        | Update instead of erase install (requires appropriate APTicket)                                                                                         |
|                |                                     | This parameter is recommended to not be used for downgrading. If you are jailbroken, make sure to have your orig-fs snapshot restored (Restore RootFS). |
| ` -w `         | ` --wait `                          | Keep rebooting until ApNonce matches APTicket (ApNonce collision, unreliable)                                                                           |
| ` -d `         | ` --debug `                         | Show all code, use to save a log for debug testing                                                                                                      |
| ` -e `         | ` --exit-recovery `                 | Exit recovery mode and quit                                                                                                                             |
| ` -c `         | ` --custom-latest VERSION `         | Specify custom latest version to use for SEP, Baseband and other FirmwareUpdater components                                                             |
| ` -g `         | ` --custom-latest-buildid BUILDID ` | Specify custom latest buildid to use for SEP, Baseband and other FirmwareUpdater components                                                             |
| ` -i `         | ` --custom-latest-beta `            | Get custom url from list of beta firmwares                                                                                                              |
| ` -k `         | ` --custom-latest-ota `             | Get custom url from list of OTA firmwares                                                                                                               |
| ` -3 `         | ` --use-pwndfu `                    | Restoring devices with Odysseus method. Device needs to be in pwned DFU mode already                                                                    |
| ` -4 `         | ` --no-ibss `                       | Restoring devices with Odysseus method. For checkm8/iPwnder32 specifically, bootrom needs to be patched already with unless iPwnder.                    |
| ` -5 `         | ` --rdsk PATH `                     | Set custom restore ramdisk for entering restoremode(requires use-pwndfu)                                                                                |
| ` -6 `         | ` --rkrn PATH `                     | Set custom restore kernelcache for entering restoremode(requires use-pwndfu)                                                                            |
| ` -7 `         | ` --set-nonce `                     | Set custom nonce from your blob then exit recovery(requires use-pwndfu)                                                                                 |
| ` -7 `         | ` --set-nonce=0xNONCE `             | Set custom nonce then exit recovery(requires use-pwndfu)                                                                                                |
| ` -8 `         | ` --serial `                        | Enable serial during boot(requires serial cable and use-pwndfu)                                                                                         |
| ` -9 `         | ` --boot-args "BOOTARGS" `          | Set custom restore boot-args(PROCEED WITH CAUTION)(requires use-pwndfu)                                                                                 |
| ` -a `         | ` --no-cache `                      | Disable cached patched iBSS/iBEC(requires use-pwndfu)                                                                                                   |
| ` -f `         | ` --skip-blob `                     | Skip SHSH blob validation(PROCEED WITH CAUTION)(requires use-pwndfu)                                                                                    |
| ` -0 `         | ` --latest-sep `                    | Use latest signed SEP instead of manually specifying one                                                                                                |
| ` -j `         | ` --no-rsep `                       | Choose not to send Restore Mode SEP firmware command                                                                                                    |
| ` -1 `         | ` --latest-baseband `               | Use latest signed baseband instead of manually specifying one                                                                                           |
| ` -2 `         | ` --no-baseband `                   | Skip checks and don't flash baseband                                                                                                                    |
|                |                                     | Only use this for device without a baseband (eg. iPod touch or Wi-Fi only iPads)                                                                        |
Deprecated/Legacy Options:

| option (short) | option (long)                       | description                                                                                                                                             |
|----------------|-------------------------------------|---------------------------------------------------------------------------------------------------------------------------------------------------------|
| ` -s `         | ` --sep PATH `                      | Manually specify SEP to be flashed                                                                                                                      |
| ` -m `         | ` --sep-manifest PATH `             | BuildManifest for requesting SEP ticket                                                                                                                 |
| ` -b `         | ` --baseband PATH	`                 | Manually specify baseband to be flashed                                                                                                                 |
| ` -p `         | ` --baseband-manifest PATH `        | BuildManifest for requesting baseband ticket                                                                                                            |
---

# 1) Prometheus (64-bit device) - APNonce recreation with generator method

### You can only downgrade if:
*  the destination firmware version is compatible with a currently signed SEP and baseband. Check whether your version is compatible [here.](#firmware-signing-info)
*  if you have a signing tickets files with a generator for **that specific firmware version.**


### Requirements
* A jailbreak or an exploit that allows nonce setting.
* Signing ticket files (`.shsh`, `.shsh2`, `.plist`) with a generator
  * A12+ users must also have a valid APNonce / generator pair due to nonce entanglement. Only having an APNonce without a generator is not sufficient.
* A computer with a minimum of 8 gigabytes of free space + IPSW of the target version downloaded. You can find the IPSW for your device at [IPSW.me](https://ipsw.me).
* On Windows machines, make sure to have [this version](https://www.apple.com/itunes/download/win64) of iTunes installed. Using the Microsoft Store version will cause issues.
### Method:
1. Jailbreak your device if it isn't jailbroken already.
2. Open your blob in any text editor and search for the word "generator". In most text editors you can use CTRL + F / CMD + F to look for it.

![GeneratorExample](https://user-images.githubusercontent.com/48022799/117004373-aa0b6700-acee-11eb-8a70-c488163e349b.jpeg) 
 - This should be a `0x` followed by 16 characters, which will be a combination of letters and numbers.
3. Note that value down. This is your generator.
   
   - **NOTE:** If there is no generator value, try to remember which jailbreak you were using at the time of saving blobs. If you were using unc0ver, your generator is most likely `0x1111111111111111`, and if you were using Chimera/Odyssey/Taurine, your generator is most likely `0xbd34a880be0b53f3`.

4. Set your device's APNonce generator. You can use your [jailbreak tool](#using-jailbreak-tools) to set your generator in its native settings. However, setting your generator with [dimentio](#Using-dimentio) is recommended.

5. Connect your device in normal mode to computer - make sure the trust dialog is accepted.
6. **Recommended:** Make a full backup of your device before running futurerestore.
7. On the computer run:
  
   ```futurerestore -t blob.shsh2 --latest-sep --latest-baseband -d target.ipsw```

   If you are upgrading and want to preserve user data you may run:
   
   ```futurerestore -u -t blob.shsh2 --latest-sep --latest-baseband -d target.ipsw```



